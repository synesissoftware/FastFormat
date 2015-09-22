/* /////////////////////////////////////////////////////////////////////////
 * File:        src/fmt_spec_defect_handlers.cpp
 *
 * Purpose:     Implementation file for FastFormat core API: defect
 *              handlers.
 *
 * Created:     26th November 2007
 * Updated:     3rd February 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2012, Matthew Wilson and Synesis Software
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



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "ximpl_core.hpp"
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif
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
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Types & Non-local variables
 */

namespace
{

    struct ff_illformed_handler_info_t_
        : public ff_illformed_handler_info_t
    {
    public:
        ff_illformed_handler_info_t_()
        {
            handler =   NULL;
            param   =   NULL;
        }
        ff_illformed_handler_info_t_(fastformat_illformedHandler_t h, void* p)
        {
            handler =   h;
            param   =   p;
        }

    public:
        void swap(ff_illformed_handler_info_t_& rhs)
        {
            std::swap(handler, rhs.handler);
            std::swap(param, rhs.param);
        }
    };

    struct ff_mismatched_handler_info_t_
        : public ff_mismatched_handler_info_t
    {
        ff_mismatched_handler_info_t_()
        {
            handler =   NULL;
            param   =   NULL;
        }
        ff_mismatched_handler_info_t_(fastformat_mismatchedHandler_t h, void* p)
        {
            handler =   h;
            param   =   p;
        }

    public:
        void swap(ff_mismatched_handler_info_t_& rhs)
        {
            std::swap(handler, rhs.handler);
            std::swap(param, rhs.param);
        }
    };



    class defectHandlers_context_t
    {
    private: /// Member Types
#ifdef FASTFORMAT_MT
        struct slot_type_
        {
            ff_illformed_handler_info_t_    illformedHandler;
            ff_mismatched_handler_info_t_   mismatchedHandler;
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
        ff_illformed_handler_info_t_    getIllformedProcessHandler() const;
        ff_illformed_handler_info_t_    setIllformedProcessHandler(fastformat_illformedHandler_t handler, void* param);

        ff_illformed_handler_info_t_    getIllformedThreadHandler() const;
        ff_illformed_handler_info_t_    setIllformedThreadHandler(fastformat_illformedHandler_t handler, void* param);


        ff_mismatched_handler_info_t_   getMismatchedProcessHandler() const;
        ff_mismatched_handler_info_t_   setMismatchedProcessHandler(fastformat_mismatchedHandler_t handler, void* param);

        ff_mismatched_handler_info_t_   getMismatchedThreadHandler() const;
        ff_mismatched_handler_info_t_   setMismatchedThreadHandler(fastformat_mismatchedHandler_t handler, void* param);

    private: /// Implementation
        static int FASTFORMAT_CALLCONV  default_illformedHandler(   void*               param
                                                                ,   ff_parse_code_t     code
                                                                ,   ff_char_t const*    format
                                                                ,   size_t              formatLen
                                                                ,   size_t              replacementIndex
                                                                ,   ff_char_t const*    defect
                                                                ,   size_t              defectLen
                                                                ,   int                 parameterIndex
                                                                ,   void*               reserved0
                                                                ,   size_t              reserved1
                                                                ,   void*               reserved2);

    private: /// Member Variables
        mx_type_                            m_mx;
#ifdef FASTFORMAT_MT
        platformstl::tss_index              m_key;
#endif /* FASTFORMAT_MT */
        ff_illformed_handler_info_t_        m_illformedProcessHandler;
        ff_mismatched_handler_info_t_       m_unmatchedProcessHandler;
#ifdef FASTFORMAT_MT
        ff_illformed_handler_info_t_        m_illformedThreadHandler;
        ff_mismatched_handler_info_t_       m_unmatchedThreadHandler;
#endif /* FASTFORMAT_MT */
    };

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Implementation Functions
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

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    delete ctxt;
}

ff_illformed_handler_info_t ximpl_core::fastformat_impl_handlers_getIllformedProcessHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getIllformedProcessHandler();
}

ff_illformed_handler_info_t ximpl_core::fastformat_impl_handlers_setIllformedProcessHandler(void* token, fastformat_illformedHandler_t handler, void* param)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setIllformedProcessHandler(handler, param);
}

ff_illformed_handler_info_t ximpl_core::fastformat_impl_handlers_getIllformedThreadHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getIllformedThreadHandler();
}

ff_illformed_handler_info_t ximpl_core::fastformat_impl_handlers_setIllformedThreadHandler(void* token, fastformat_illformedHandler_t handler, void* param)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setIllformedThreadHandler(handler, param);
}

ff_mismatched_handler_info_t ximpl_core::fastformat_impl_handlers_getMismatchedProcessHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getMismatchedProcessHandler();
}

ff_mismatched_handler_info_t ximpl_core::fastformat_impl_handlers_setMismatchedProcessHandler(void* token, fastformat_mismatchedHandler_t handler, void* param)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setMismatchedProcessHandler(handler, param);
}

ff_mismatched_handler_info_t ximpl_core::fastformat_impl_handlers_getMismatchedThreadHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t const* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->getMismatchedThreadHandler();
}

ff_mismatched_handler_info_t ximpl_core::fastformat_impl_handlers_setMismatchedThreadHandler(void* token, fastformat_mismatchedHandler_t handler, void* param)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");

    defectHandlers_context_t* ctxt = static_cast<defectHandlers_context_t*>(token);

    return ctxt->setMismatchedThreadHandler(handler, param);
}

namespace
{
    /* static */ int defectHandlers_context_t::default_illformedHandler(
        void*               /* param */
    ,   ff_parse_code_t     code
    ,   ff_char_t const*    format
    ,   size_t              formatLen
    ,   size_t              /* replacementIndex */
    ,   ff_char_t const*    /* ptr */
    ,   size_t              /* len */
    ,   int                 /* index */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        // Simplistic factory for exceptions

        switch(code)
        {
            default:
                FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unknown parse code");
                break;
            case    FF_PARSECODE_SUCCESS:
                FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("handler invoked with success parse code");
                break;
            case    FF_PARSECODE_INCOMPLETEREPLACEMENT:
                throw illformed_format_exception("ill-formed format: incomplete replacement", code, format, formatLen);
            case    FF_PARSECODE_INVALIDINDEX:
                throw illformed_format_exception("ill-formed format: invalid index", code, format, formatLen);
        }

        return 0;
    }


    defectHandlers_context_t::defectHandlers_context_t()
        : m_mx()
#ifdef FASTFORMAT_MT
        , m_key()
#endif /* FASTFORMAT_MT */
        , m_illformedProcessHandler(defectHandlers_context_t::default_illformedHandler, NULL)
        , m_unmatchedProcessHandler()
#ifdef FASTFORMAT_MT
        , m_illformedThreadHandler()
        , m_unmatchedThreadHandler()
#endif /* FASTFORMAT_MT */
    {}


    ff_illformed_handler_info_t_ defectHandlers_context_t::getIllformedProcessHandler() const
    {
        return m_illformedProcessHandler;
    }

    ff_illformed_handler_info_t_ defectHandlers_context_t::setIllformedProcessHandler(fastformat_illformedHandler_t handler, void* param)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        ff_illformed_handler_info_t_    oldHandler(handler, param);

        {
            stlsoft::lock_scope<mx_type_> lock(m_mx);

            FASTFORMAT_COVER_MARK_ENTRY();

            m_illformedProcessHandler.swap(oldHandler);
        }

        return oldHandler;
    }

    ff_illformed_handler_info_t_ defectHandlers_context_t::getIllformedThreadHandler() const
    {
#ifdef FASTFORMAT_MT
        slot_type_* slot = static_cast<slot_type_*>(m_key.get_value());

        return (NULL == slot) ? ff_illformed_handler_info_t_() : slot->illformedHandler;
#else /* ? FASTFORMAT_MT */
        // Not multithreading, so use process handler

        return getIllformedProcessHandler();
#endif /* FASTFORMAT_MT */
    }

    ff_illformed_handler_info_t_ defectHandlers_context_t::setIllformedThreadHandler(fastformat_illformedHandler_t handler, void* param)
    {
#ifdef FASTFORMAT_MT
        slot_type_*                     slot = static_cast<slot_type_*>(m_key.get_value());
        ff_illformed_handler_info_t_    oldHandler(handler, param);

        if(NULL == slot)
        {
            slot = static_cast<slot_type_*>(fastformat_malloc(sizeof(slot_type_)));

            if(NULL == slot)
            {
                throw std::bad_alloc();
            }
            else
            {
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.handler);
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.param);
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.handler);
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.param);
            }

            m_key.set_value(slot);
        }

        slot->illformedHandler.swap(oldHandler);

        return oldHandler;
#else /* ? FASTFORMAT_MT */
        // Not multithreading, so use process handler

        return setIllformedProcessHandler(handler, param);
#endif /* FASTFORMAT_MT */
    }


    ff_mismatched_handler_info_t_ defectHandlers_context_t::getMismatchedProcessHandler() const
    {
        return m_unmatchedProcessHandler;
    }

    ff_mismatched_handler_info_t_ defectHandlers_context_t::setMismatchedProcessHandler(fastformat_mismatchedHandler_t handler, void* param)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        ff_mismatched_handler_info_t_ oldHandler(handler, param);

        {
            stlsoft::lock_scope<mx_type_> lock(m_mx);

            FASTFORMAT_COVER_MARK_ENTRY();

            m_unmatchedProcessHandler.swap(oldHandler);
        }

        return oldHandler;
    }

    ff_mismatched_handler_info_t_ defectHandlers_context_t::getMismatchedThreadHandler() const
    {
#ifdef FASTFORMAT_MT
        slot_type_* slot = static_cast<slot_type_*>(m_key.get_value());

        return (NULL == slot) ? ff_mismatched_handler_info_t_() : slot->mismatchedHandler;
#else /* ? FASTFORMAT_MT */
        // Not multithreading, so use process handler

        return getMismatchedProcessHandler();
#endif /* FASTFORMAT_MT */
    }

    ff_mismatched_handler_info_t_ defectHandlers_context_t::setMismatchedThreadHandler(fastformat_mismatchedHandler_t handler, void* param)
    {
#ifdef FASTFORMAT_MT
        slot_type_*                     slot = static_cast<slot_type_*>(m_key.get_value());
        ff_mismatched_handler_info_t_   oldHandler(handler, param);

        if(NULL == slot)
        {
            slot = static_cast<slot_type_*>(fastformat_malloc(sizeof(slot_type_)));

            if(NULL == slot)
            {
                throw std::bad_alloc();
            }
            else
            {
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.handler);
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->illformedHandler.param);
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.handler);
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL == slot->mismatchedHandler.param);
            }

            m_key.set_value(slot);
        }

        slot->mismatchedHandler.swap(oldHandler);

        return oldHandler;
#else /* ? FASTFORMAT_MT */
        // Not multithreading, so use process handler

        return setMismatchedProcessHandler(handler, param);
#endif /* FASTFORMAT_MT */
    }

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
