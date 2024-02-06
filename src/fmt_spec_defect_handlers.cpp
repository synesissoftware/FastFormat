/* /////////////////////////////////////////////////////////////////////////
 * File:        src/fmt_spec_defect_handlers.cpp
 *
 * Purpose:     Implementation file for FastFormat core API: defect
 *              handlers.
 *
 * Created:     26th November 2007
 * Updated:     6th February 2024
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */



// #define FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS // This is not defined by default, but unreferenced arguments are not always a defect

/* /////////////////////////////////////////////////////////////////////////
 * includes - 0
 */

#include <stlsoft/stlsoft.h>

#include "ximpl_core.hpp"

#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if 0
#elif defined(STLSOFT_COMPILER_IS_MSVC)
# if _MSC_VER == 1500
#  pragma warning(disable : 4551)
# endif
#else
#endif

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <fastformat/internal/threading.h>
#include <fastformat/exceptions.hpp>
#include <fastformat/init_codes.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#ifdef FASTFORMAT_MT
# include <platformstl/synch/thread_mutex.hpp>
# include <platformstl/synch/tss_index.hpp>
#else /* ? FASTFORMAT_MT */
# include <stlsoft/synch/null_mutex.hpp>
#endif /* FASTFORMAT_MT */

#include <stlsoft/synch/lock_scope.hpp>
#include <stlsoft/util/std_swap.hpp>

#include <new>
#include <stdexcept>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * types & non-local variables
 */

namespace
{

    /* /////////////////////////////////////////////////////////////////////
     * constants
     */

    ff_illformedHandler_info_t const s_emptyIllformedHandler    =   { NULL, NULL };
    ff_mismatchedHandler_info_t const s_emptyMismatchedHandler  =   { NULL, NULL };


    /* /////////////////////////////////////////////////////////////////////
     * helper functions
     */

    void
    swap_handler(
        ff_illformedHandler_info_t&     lhs
    ,   ff_illformedHandler_info_t&     rhs
    )
    {
        std::swap(lhs.handler, rhs.handler);
        std::swap(lhs.param, rhs.param);
    }

    void
    swap_handler(
        ff_mismatchedHandler_info_t&    lhs
    ,   ff_mismatchedHandler_info_t&    rhs
    )
    {
        std::swap(lhs.handler, rhs.handler);
        std::swap(lhs.param, rhs.param);
    }


    /* /////////////////////////////////////////////////////////////////////
     * Classes
     */

    class defectHandlers_context_t
    {
    private: /// Member Types
#ifdef FASTFORMAT_MT
        struct slot_type_
        {
            ff_illformedHandler_info_t      illformedHandler;
            ff_mismatchedHandler_info_t     mismatchedHandler;
        };
        typedef platformstl::thread_mutex   mx_type_;
#else /* ? FASTFORMAT_MT */
        typedef stlsoft::null_mutex         mx_type_;
#endif /* FASTFORMAT_MT */

    public: /// Construction
        defectHandlers_context_t();
    private:
        defectHandlers_context_t(defectHandlers_context_t const&);
        defectHandlers_context_t& operator =(defectHandlers_context_t const&);

    public: /// Operations
        ff_illformedHandler_info_t  getIllformedProcessHandler() const;
        ff_illformedHandler_info_t  setIllformedProcessHandler(ff_illformedHandler_info_t handler_info);

        ff_illformedHandler_info_t  getIllformedThreadHandler() const;
        ff_illformedHandler_info_t  setIllformedThreadHandler(ff_illformedHandler_info_t handler_info);


        ff_mismatchedHandler_info_t getMismatchedProcessHandler() const;
        ff_mismatchedHandler_info_t setMismatchedProcessHandler(ff_mismatchedHandler_info_t handler_info);

        ff_mismatchedHandler_info_t getMismatchedThreadHandler() const;
        ff_mismatchedHandler_info_t setMismatchedThreadHandler(ff_mismatchedHandler_info_t handler_info);

    private: /// Implementation
#ifdef FASTFORMAT_MT
        slot_type_*         get_slot_();
        slot_type_ const*   get_slot_() const;
#endif /* FASTFORMAT_MT */

    private: /// Member Variables
        mx_type_                            m_mx;
#ifdef FASTFORMAT_MT
        platformstl::tss_index              m_key;
#endif /* FASTFORMAT_MT */
        ff_illformedHandler_info_t          m_illformedProcessHandler;
        ff_mismatchedHandler_info_t         m_unmatchedProcessHandler;
#ifndef FASTFORMAT_MT
        ff_illformedHandler_info_t          m_illformedThreadHandler;
        ff_mismatchedHandler_info_t         m_unmatchedThreadHandler;
#endif /* !FASTFORMAT_MT */
    };

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * implementation functions
 */

int ximpl_core::fastformat_impl_handlers_init(void** ptoken)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != ptoken, "token pointer must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    try
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        defectHandlers_context_t* ctxt = new defectHandlers_context_t();

        if(NULL == ctxt)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            return -2;
        }

        *ptoken = ctxt;

        return 0;
    }
    catch(std::bad_alloc&)
    {
        return FASTFORMAT_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
    catch(...)
    {
        return FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR;
    }
}

void ximpl_core::fastformat_impl_handlers_uninit(void* token)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != token, "FastFormat error handlers have not been initialised");

    defectHandlers_context_t* const ctxt = static_cast<defectHandlers_context_t*>(token);

    delete ctxt;
}

ff_illformedHandler_info_t ximpl_core::fastformat_impl_handlers_getIllformedProcessHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getIllformedProcessHandler();
}

ff_illformedHandler_info_t ximpl_core::fastformat_impl_handlers_setIllformedProcessHandler(void* token, ff_illformedHandler_info_t handler_info)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setIllformedProcessHandler(handler_info);
}

ff_illformedHandler_info_t ximpl_core::fastformat_impl_handlers_getIllformedThreadHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getIllformedThreadHandler();
}

ff_illformedHandler_info_t ximpl_core::fastformat_impl_handlers_setIllformedThreadHandler(void* token, ff_illformedHandler_info_t handler_info)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setIllformedThreadHandler(handler_info);
}


ff_mismatchedHandler_info_t ximpl_core::fastformat_impl_handlers_getMismatchedProcessHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getMismatchedProcessHandler();
}

ff_mismatchedHandler_info_t ximpl_core::fastformat_impl_handlers_setMismatchedProcessHandler(void* token, ff_mismatchedHandler_info_t handler_info)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setMismatchedProcessHandler(handler_info);
}

ff_mismatchedHandler_info_t ximpl_core::fastformat_impl_handlers_getMismatchedThreadHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getMismatchedThreadHandler();
}

ff_mismatchedHandler_info_t ximpl_core::fastformat_impl_handlers_setMismatchedThreadHandler(void* token, ff_mismatchedHandler_info_t handler_info)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setMismatchedThreadHandler(handler_info);
}


namespace
{

    defectHandlers_context_t::defectHandlers_context_t()
        : m_mx()
#ifdef FASTFORMAT_MT
        , m_key()
#endif /* FASTFORMAT_MT */
        , m_illformedProcessHandler(s_emptyIllformedHandler)
        , m_unmatchedProcessHandler(s_emptyMismatchedHandler)
#ifndef FASTFORMAT_MT
        , m_illformedThreadHandler(s_emptyIllformedHandler)
        , m_unmatchedThreadHandler(s_emptyMismatchedHandler)
#endif /* !FASTFORMAT_MT */
    {
        FASTFORMAT_COVER_MARK_ENTRY();
    }

#ifdef FASTFORMAT_MT
    inline
    defectHandlers_context_t::slot_type_* defectHandlers_context_t::get_slot_()
    {
        return static_cast<slot_type_*>(m_key.get_value());
    }
    inline
    defectHandlers_context_t::slot_type_ const* defectHandlers_context_t::get_slot_() const
    {
        return static_cast<slot_type_*>(m_key.get_value());
    }
#endif /* FASTFORMAT_MT */

    ff_illformedHandler_info_t defectHandlers_context_t::getIllformedProcessHandler() const
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return m_illformedProcessHandler;
    }

    ff_illformedHandler_info_t defectHandlers_context_t::setIllformedProcessHandler(ff_illformedHandler_info_t handler_info)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        ff_illformedHandler_info_t oldHandler = handler_info;

        {
            stlsoft::lock_scope<mx_type_> lock(m_mx);

            FASTFORMAT_COVER_MARK_ENTRY();

            swap_handler(m_illformedProcessHandler, oldHandler);
        }

        return oldHandler;
    }

    ff_illformedHandler_info_t defectHandlers_context_t::getIllformedThreadHandler() const
    {
        FASTFORMAT_COVER_MARK_ENTRY();

#ifdef FASTFORMAT_MT
        slot_type_ const* const slot = get_slot_();

        if(NULL != slot)
        {
            return slot->illformedHandler;
        }

        return s_emptyIllformedHandler;
#else /* ? FASTFORMAT_MT */
        // Not multithreading

        return m_illformedThreadHandler;
#endif /* FASTFORMAT_MT */
    }

    ff_illformedHandler_info_t defectHandlers_context_t::setIllformedThreadHandler(ff_illformedHandler_info_t handler_info)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        ff_illformedHandler_info_t      oldHandler = handler_info;
#ifdef FASTFORMAT_MT
        slot_type_*                     slot = get_slot_();

        if(NULL == slot)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            slot = static_cast<slot_type_*>(fastformat_malloc(sizeof(slot_type_)));

            if(NULL == slot)
            {
                FASTFORMAT_COVER_MARK_ENTRY();

                throw std::bad_alloc();
            }

            FASTFORMAT_COVER_MARK_ENTRY();

            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.handler);
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.param);
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.handler);
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.param);

            m_key.set_value(slot);
        }

        swap_handler(slot->illformedHandler, oldHandler);
#else /* ? FASTFORMAT_MT */
        // Not multithreading

        {
            stlsoft::lock_scope<mx_type_> lock(m_mx);

            FASTFORMAT_COVER_MARK_ENTRY();

            swap_handler(m_illformedThreadHandler, oldHandler);
        }
#endif /* FASTFORMAT_MT */

        return oldHandler;
    }


    ff_mismatchedHandler_info_t defectHandlers_context_t::getMismatchedProcessHandler() const
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return m_unmatchedProcessHandler;
    }

    ff_mismatchedHandler_info_t defectHandlers_context_t::setMismatchedProcessHandler(ff_mismatchedHandler_info_t handler_info)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        ff_mismatchedHandler_info_t oldHandler = handler_info;

        {
            stlsoft::lock_scope<mx_type_> lock(m_mx);

            FASTFORMAT_COVER_MARK_ENTRY();

            swap_handler(m_unmatchedProcessHandler, oldHandler);
        }

        return oldHandler;
    }

    ff_mismatchedHandler_info_t defectHandlers_context_t::getMismatchedThreadHandler() const
    {
        FASTFORMAT_COVER_MARK_ENTRY();

#ifdef FASTFORMAT_MT
        slot_type_ const* const slot = get_slot_();

        if(NULL != slot)
        {
            return slot->mismatchedHandler;
        }

        return s_emptyMismatchedHandler;
#else /* ? FASTFORMAT_MT */
        // Not multithreading

        return m_unmatchedThreadHandler;
#endif /* FASTFORMAT_MT */
    }

    ff_mismatchedHandler_info_t defectHandlers_context_t::setMismatchedThreadHandler(ff_mismatchedHandler_info_t handler_info)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        ff_mismatchedHandler_info_t     oldHandler = handler_info;
#ifdef FASTFORMAT_MT
        slot_type_*                     slot = get_slot_();

        if(NULL == slot)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            slot = static_cast<slot_type_*>(fastformat_malloc(sizeof(slot_type_)));

            if(NULL == slot)
            {
                FASTFORMAT_COVER_MARK_ENTRY();

                throw std::bad_alloc();
            }

            FASTFORMAT_COVER_MARK_ENTRY();

            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.handler);
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.param);
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.handler);
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.param);

            m_key.set_value(slot);
        }

        swap_handler(slot->mismatchedHandler, oldHandler);
#else /* ? FASTFORMAT_MT */
        // Not multithreading

        {
            stlsoft::lock_scope<mx_type_> lock(m_mx);

            FASTFORMAT_COVER_MARK_ENTRY();

            swap_handler(m_unmatchedThreadHandler, oldHandler);
        }
#endif /* FASTFORMAT_MT */

        return oldHandler;
    }

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
