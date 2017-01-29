/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp
 *
 * Purpose:     A scoping class that suppresses the reporting of
 *              unreferenced arguments.
 *
 * Created:     1st December 2008
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp
 *
 * [C++ only] A scoping class that suppresses the reporting of unreferenced
 *  arguments.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE
#define FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE_MINOR       2
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE_REVISION    3
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE_EDIT        10
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/exceptions.hpp>
#ifndef FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE
# include <fastformat/format/specification_defect_handling/mismatched_arguments_scope_base.hpp>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_MISMATCHED_ARGUMENTS_SCOPE_BASE */
#include <fastformat/quality/contract.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Scoping class that suppresses the reporting of unreferenced arguments
 * during its lifetime.
 *
 * \ingroup group__format_specification_defect_handling
 */
class ignore_unreferenced_arguments_scope
    : protected mismatched_arguments_scope_base // ISA is not important
{
public: // Member Types
    /// The parent type
    typedef mismatched_arguments_scope_base         parent_class_type;
    /// This type
    typedef ignore_unreferenced_arguments_scope     class_type;

public: // Construction
    /** Causes the thread/process mismatched handler to be set to a function
     * that ignores the
     * <code>FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT</code> code 
     * for all parameter indexes and
     * passes all others to the previously-registered handler
     */
    explicit ignore_unreferenced_arguments_scope(ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
        : parent_class_type(domain)
        , m_lowestIndexToIgnore(0)
    {}
    /** Causes the thread/process mismatched handler to be set to a function
     * that ignores the
     * <code>FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT</code> code 
     * for all parameter indexes equal or subsequent to the given index and
     * passes all others to the previously-registered handler.
     *
     * \param lowestIndexToIgnore The index at/above which all unreferenced
     *   argument indexes are ignored.
     */
    explicit ignore_unreferenced_arguments_scope(unsigned lowestIndexToIgnore, ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
        : parent_class_type(domain)
        , m_lowestIndexToIgnore(lowestIndexToIgnore)
    {}
    /** Restores the thread/process mismatched handler to the function
     * registered prior to the construction of this instance
     *
     * \warning The system behaviour is undefined if the thread/process 
     *   mismatch handler is modified during the lifetime of this instance
     */
    ~ignore_unreferenced_arguments_scope() ss_noexcept_k
    {}
private:
    ignore_unreferenced_arguments_scope(class_type const&);
    class_type& operator =(class_type const&);

private: // Overrides
    virtual ff_handler_response_t handle(
        ff_replacement_code_t       code
    ,   size_t                      numArguments
    ,   int                         mismatchedParameterIndex
    ,   ff_replacement_action_t*    /* action */
    ,   ff_string_slice_t*          /* slice */
    )
    {
        if(FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT == code)
        {
            if(int(m_lowestIndexToIgnore) <= mismatchedParameterIndex)
            {
                // Ignore unreferenced argument
                return FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
            }

            throw unreferenced_argument_exception("an argument was unreferenced in the format", code, int(numArguments), mismatchedParameterIndex);
        }

        return FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

private: // Fields
    unsigned const  m_lowestIndexToIgnore;
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_FORMAT_SPECIFICATION_DEFECT_HANDLING_HPP_IGNORE_UNREFERENCED_ARGUMENTS_SCOPE */

/* ///////////////////////////// end of file //////////////////////////// */
