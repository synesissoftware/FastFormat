/* /////////////////////////////////////////////////////////////////////////
 * File:    fastformat/shims/conversion/filter_type/reals.hpp
 *
 * Purpose: FastFormat argument conversion shim for floating-point types.
 *
 * Created: 1st June 2008
 * Updated: 16th October 2026
 *
 * Home:    http://www.fastformat.org/
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file fastformat/shims/conversion/filter_type/reals.hpp
 *
 * [C++ only] FastFormat argument conversion shim for floating-point types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS
#define FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_MINOR     2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_EDIT      9
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
#include <fastformat/internal/stlsoft.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>

#include <stlsoft/string/shim_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace filters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * Overloadable conversion shim functions:
 *
 * float
 * double
 */

/** Filtering conversion shim function for implicitly adapting
 *  <code>double</code> floating points as format arguments.
 */
inline stlsoft::basic_shim_string<ff_char_t, 32> filter_type(double value, double const*, ff_char_t const volatile*)
{
    static const ff_char_t  fmt[] = { '%', 'G', '\0' };

    stlsoft::basic_shim_string<ff_char_t, 32>   r(32);

    // Use FastFormat's snprintf insulator (same pattern as void_pointers.hpp)
    // rather than bare sprintf/snprintf — Apple Clang deprecates sprintf
    // under -Werror, and compiler snprintf signatures vary.
    int n = fastformat_util_snprintf(r.data(), r.size(), fmt, value);

    if(n < 0)
    {
        n = 0;
    }

    r.truncate(static_cast<size_t>(n));

    return r;
}

/** Filtering conversion shim function for implicitly adapting
 *  <code>float</code> floating points as format arguments.
 */
inline stlsoft::basic_shim_string<ff_char_t, 32> filter_type(float value, float const*, ff_char_t const volatile*)
{
    double value2 = value;

    return filter_type(value2, &value2, static_cast<ff_char_t const volatile*>(0));
}


/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace filters */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS */

/* ///////////////////////////// end of file //////////////////////////// */
