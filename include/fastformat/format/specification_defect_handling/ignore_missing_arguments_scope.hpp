/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/format/specification_defect_handling/ignore_missing_arguments_scope.hpp
 *
 * Purpose:     A scoping class that suppresses the reporting of
 *              unreferenced arguments.
 *
 * Created:     25th April 2009
 * Updated:     15th August 2016
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2016, Matthew Wilson and Synesis Software
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


/** \file fastformat/format/specification_defect_handling/ignore_missing_arguments_scope.hpp
 *
 * [C++ only] A scoping class that suppresses the reporting of unreferenced
 *  arguments.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE
#define FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE_MINOR    2
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE_REVISION 3
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE_EDIT     10
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
#include <fastformat/exceptions.hpp>
#ifndef FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE
# include <fastformat/format/specification_defect_handling/mismatched_arguments_scope_base.hpp>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE */
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

/** Scoping class that suppresses the reporting of unreferenced arguments
 * during its lifetime.
 *
 * \ingroup group__format_specification_defect_handling
 */
class ignore_missing_arguments_scope
    : protected mismatched_arguments_scope_base // ISA is not important
{
public: // Member Types
    /// The parent type
    typedef mismatched_arguments_scope_base     parent_class_type;
    /// This type
    typedef ignore_missing_arguments_scope      class_type;

public: // Construction
    /** Causes the thread/process mismatched handler to be set to a function
     * that ignores the
     * <code>FF_REPLACEMENTCODE_MISSING_ARGUMENT</code> code and
     * passes all others to the previously-registered handler
     */
    explicit ignore_missing_arguments_scope(ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
        : parent_class_type(domain)
    {}
    /** Restores the thread/process mismatched handler to the function
     * registered prior to the construction of this instance
     *
     * \warning The system behaviour is undefined if the thread/process 
     *   mismatch handler is modified during the lifetime of this instance
     */
    ~ignore_missing_arguments_scope() ss_noexcept_k
    {}
private:
    ignore_missing_arguments_scope(class_type const&);
    class_type& operator =(class_type const&);

private: // Overrides
    virtual ff_handler_response_t handle(
        ff_replacement_code_t       code
    ,   size_t                      /* numArguments */
    ,   int                         /* mismatchedParameterIndex */
    ,   ff_replacement_action_t*    /* action */
    ,   ff_string_slice_t*          /* slice */
    )
    {
        if(FF_REPLACEMENTCODE_MISSING_ARGUMENT == code)
        {
            // Ignore missing argument
            return FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
        }

        return FF_HANDLERRESPONSE_NEXT_HANDLER;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_MISSING_ARGUMENTS_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */
