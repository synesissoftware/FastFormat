/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/format/specification_defect_handling/mismatched_arguments_scope_base.hpp
 *
 * Purpose:     Base class for scoping classes that customise the behaviour
 *              in response to mismatched arguments.
 *
 * Created:     1st December 2008
 * Updated:     15th August 2016
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2016, Matthew Wilson and Synesis Software
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


/** \file fastformat/format/specification_defect_handling/mismatched_arguments_scope_base.hpp
 *
 * [C++ only] Base class for scoping classes that customise the behaviour
 *  in response to mismatched arguments.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE
#define FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_MINOR       2
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_REVISION    1
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_EDIT        11
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helpers
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_mismatched_arguments_scope_base
{

/* Separated out in order to ensure field construction order */
class mismatched_handler_scope_specifier_base
{
private:
    typedef mismatched_handler_scope_specifier_base class_type;
public:
    typedef fastformat::ff_mismatchedHandler_info_t handler_info_type;
protected:
    typedef handler_info_type
                              (FASTFORMAT_CALLCONV *handler_specifier_function_type)(handler_info_type);

protected:
    explicit mismatched_handler_scope_specifier_base(ff_handler_domain_t domain)
        : m_specifier(select_specifier_(domain))
    {}
private:
    class_type& operator =(class_type const&);

private:
    static handler_specifier_function_type select_specifier_(ff_handler_domain_t domain)
    {
        using namespace fastformat;

        return (FF_HANDLERDOMAIN_PROCESS == domain) ? fastformat_setProcessMismatchedHandler : fastformat_setThreadMismatchedHandler;
    }

protected:
    handler_specifier_function_type const   m_specifier;
};

}/* namespace ximpl_mismatched_arguments_scope_base */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** Base class for scoping classes that customise the behaviour in response
 * to mismatched arguments.
 *
 * \ingroup group__format_specification_defect_handling
 */
class mismatched_arguments_scope_base
    : protected ximpl_mismatched_arguments_scope_base::mismatched_handler_scope_specifier_base
{
public: // Member Types
protected:
    typedef ximpl_mismatched_arguments_scope_base::mismatched_handler_scope_specifier_base
                                                        parent_class_type;
public:
    /// This type
    typedef mismatched_arguments_scope_base             class_type;
protected:
    typedef fastformat::ff_handler_response_t           handler_response_type;

protected: // Construction
    /** Causes the thread/process mismatched handler to be set to a function
     * that ignores the
     * <code>FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT</code> code and
     * passes all others to the previously-registered handler
     */
    explicit mismatched_arguments_scope_base(ff_handler_domain_t domain)
        : parent_class_type(domain)
        , m_previous((*m_specifier)(ff_mismatchedHandler_info_t::make(&class_type::handler, get_this_())))
    {}
public:
    /** Restores the thread/process mismatched handler to the function
     * registered prior to the construction of this instance
     *
     * \warning The system behaviour is undefined if the thread/process 
     *   mismatch handler is modified during the lifetime of this instance
     */
    virtual ~mismatched_arguments_scope_base() ss_noexcept_k
    {
        (*m_specifier)(m_previous);
    }

private:
    mismatched_arguments_scope_base(class_type const&);
    class_type& operator =(class_type const&);

protected: // Overrides

    /** Override, to be implemented by derived class, that will be invoked
     * when mismatched are encountered when processing a formatting
     * statement.
     *
     * \param code The type of mismatch
     * \param numArguments The number of arguments provided to the format
     *   statement
     * \param mismatchedParameterIndex The index of the parameter that is associated
     *   with the mismatch
     * \param slice A slice that may be modified in handling the mismatch.
     */
    virtual ff_handler_response_t handle(
        ff_replacement_code_t       code
    ,   size_t                      numArguments
    ,   int                         mismatchedParameterIndex
    ,   ff_replacement_action_t*    action
    ,   ff_string_slice_t*          slice
    ) = 0;

private: // Implementation
    void* get_this_() ss_noexcept_k
    {
        return this;
    }

    static
    ff_handler_response_t
    FASTFORMAT_CALLCONV handler(
        void*                       param
    ,   ff_replacement_code_t       code
    ,   size_t                      numArguments
    ,   int                         mismatchedParameterIndex
    ,   ff_replacement_action_t*    action
    ,   ff_string_slice_t*          slice
    ,   void*                       reserved0
    ,   size_t                      reserved1
    ,   void*                       reserved2
    ,   int                         reserved3
    )
    {
        class_type* pThis = static_cast<class_type*>(param);

        handler_response_type hr = pThis->handle(code, numArguments, mismatchedParameterIndex, action, slice);

        if(fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING == hr)
        {
            return hr;
        }

        if(NULL != pThis->m_previous.handler)
        {
            return (*pThis->m_previous.handler)(pThis->m_previous.param, code, numArguments, mismatchedParameterIndex, action, slice, reserved0, reserved1, reserved2, reserved3);
        }

        return fastformat::FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

protected: // Fields
    // A (very) rare use case for protected member data, when using (private) implementation inheritance
    ff_mismatchedHandler_info_t const   m_previous; //!< Previous handler, for chaining
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE */

/* ///////////////////////////// end of file //////////////////////////// */
