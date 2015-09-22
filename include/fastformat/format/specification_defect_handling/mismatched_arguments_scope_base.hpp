/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/format/specification_defect_handling/mismatched_arguments_scope_base.hpp
 *
 * Purpose:     Base class for scoping classes that customise the behaviour
 *              in response to mismatched arguments.
 *
 * Created:     1st December 2008
 * Updated:     13th September 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2010, Matthew Wilson and Synesis Software
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
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_MINOR       0
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_REVISION    1
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE_EDIT        6
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
 * Classes
 */

/** Base class for scoping classes that customise the behaviour in response
 * to mismatched arguments.
 *
 * \ingroup group__format_specification_defect_handling
 */
class mismatched_arguments_scope_base
{
public: // Member Types
    /// This type
    typedef mismatched_arguments_scope_base     class_type;

protected: // Construction
    /** Causes the thread/process mismatched handler to be set to a function
     * that ignores the
     * <code>FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT</code> code and
     * passes all others to the previously-registered handler
     */
    explicit mismatched_arguments_scope_base(fastformat_mismatchedHandler_t handler, void* param)
        : m_previous(fastformat_setThreadMismatchedHandler(handler, param))
    {}
public:
    /** Restores the thread/process mismatched handler to the function
     * registered prior to the construction of this instance
     *
     * \warning The system behaviour is undefined if the thread/process 
     *   mismatch handler is modified during the lifetime of this instance
     */
    virtual ~mismatched_arguments_scope_base() throw()
    {
        fastformat_setThreadMismatchedHandler(m_previous.handler, m_previous.param);
    }

protected: // Operations
    /** Invokes 
     */
    int handle_default(
        void*                   /* param */
    ,   ff_replacement_code_t   code
    ,   size_t                  numParameters
    ,   int                     parameterIndex
    ,   ff_string_slice_t*      slice
    ,   void*                   reserved0
    ,   size_t                  reserved1
    ,   void*                   reserved2
    )
    {
        if(NULL == m_previous.handler)
        {
            return +1; // Ignore unreferenced argument
        }
        else
        {
            return (m_previous.handler)(m_previous.param, code, numParameters, parameterIndex, slice, reserved0, reserved1, reserved2);
        }
    }

private:
    mismatched_arguments_scope_base(class_type const&);
    class_type& operator =(class_type const&);

protected:  // A (very) rare use case for protected member data, when using (private) implementation inheritance
    mismatched_handler_info_t   m_previous; //!< Previous handler, for chaining
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
