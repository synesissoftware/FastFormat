/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/inserters/int_typedefs.hpp
 *
 * Purpose:     Common typedefs for integral inserters
 *
 * Created:     26th May 2009
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2017, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/** \file fastformat/internal/inserters/int_typedefs.hpp
 *
 * [C++ only] Common typedefs for integral inserters.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_INSERTERS_HPP_INT_TYPEDEFS
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_INSERTERS_HPP_INT_TYPEDEFS

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>

#include <stlsoft/string/shim_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1300
 /* can't use shim string with some old compilers - not clear why - so 
  * must use a string type. stlsoft::simple_string is used because it
  * guarantees contiguous storage, so can sprintf() into its buffer
  */
# define FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_
# include <stlsoft/string/simple_string.hpp>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace inserters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_integer
{

# ifdef FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_
typedef stlsoft::basic_simple_string<ff_char_t>         ff_to_i_r_t_;
# else /* ? FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_ */
typedef stlsoft::basic_shim_string<ff_char_t, 20>       ff_to_i_r_t_;
# endif /* FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_ */

} /* namespace ximpl_integer */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INTERNAL_INSERTERS_HPP_INT_TYPEDEFS */

/* ///////////////////////////// end of file //////////////////////////// */
