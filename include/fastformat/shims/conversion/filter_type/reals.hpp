/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/shims/conversion/filter_type/reals.hpp
 *
 * Purpose:     FastFormat argument conversion shim for floating-point
 *              types.
 *
 * Created:     1st June 2008
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


/** \file fastformat/shims/conversion/filter_type/reals.hpp
 *
 * [C++ only] FastFormat argument conversion shim for floating-point types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS
#define FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_MINOR     2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_REVISION  2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS_EDIT      11
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
#include <fastformat/internal/stlsoft.h>
#include <fastformat/quality/contract.h>

#include <stlsoft/string/shim_string.hpp>

#include <stdio.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
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

    ff_char_t num[100];

    // TODO: Sort this properly, using detection of the "Safe" string library, a la Pantheios

    // TODO: Sort this properly, using traits instead of all the preprocessor clutter

#if defined(__STDC_SECURE_LIB__) && \
    defined(__STDC_WANT_SECURE_LIB__) && \
    __STDC_WANT_SECURE_LIB__ == 1
# ifdef FASTFORMAT_USE_WIDE_STRINGS
    int     n = ::swprintf_s(&num[0], STLSOFT_NUM_ELEMENTS(num), fmt, value);
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    int     n = ::sprintf_s(&num[0], STLSOFT_NUM_ELEMENTS(num), fmt, value);
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
#else /* ? "secure" */
# ifdef FASTFORMAT_USE_WIDE_STRINGS
    int     n = ::swprintf(&num[0], fmt, value);
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    int     n = ::sprintf(&num[0], fmt, value);
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
#endif /* "secure" */

    if(n < 0)
    {
        n = 0;
    }

    return stlsoft::basic_shim_string<ff_char_t, 32>(num, static_cast<size_t>(n));
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
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace filters */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_REALS */

/* ///////////////////////////// end of file //////////////////////////// */
