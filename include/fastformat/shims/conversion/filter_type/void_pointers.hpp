/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/shims/conversion/filter_type/void_pointers.hpp
 *
 * Purpose:     FastFormat argument conversion shim for floating-point
 *              types.
 *
 * Created:     30th November 2008
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


/** \file fastformat/shims/conversion/filter_type/void_pointers.hpp
 *
 * [C++ only] FastFormat argument conversion shim for floating-point types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS
#define FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS_MINOR     1
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS_REVISION  2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS_EDIT      9
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
#include <fastformat/util/string/snprintf.h>

#include <stlsoft/string/shim_string.hpp>

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
 *  <code>void const volatile*</code> pointers as format arguments.
 */
inline stlsoft::basic_shim_string<ff_char_t, 32> filter_type(void const volatile* value, void const volatile* const*, ff_char_t const volatile*)
{
    static const ff_char_t  fmt[] = { '%', 'p', '\0' };

    stlsoft::basic_shim_string<ff_char_t, 32>   r(32);

    int n = fastformat_util_snprintf(r.data(), r.size(), fmt, value);

    if(n < 0)
    {
        n = 0;
    }

    r.truncate(static_cast<size_t>(n));

    return r;
}

/** Filtering conversion shim function for implicitly adapting
 *  <code>void const*</code> pointers as format arguments.
 */
inline stlsoft::basic_shim_string<ff_char_t, 32> filter_type(void const* value, void const* const*, ff_char_t const volatile*)
{
    void const volatile* value2 = value;

    return filter_type(value2, &value2, static_cast<ff_char_t const volatile*>(0));
}

/** Filtering conversion shim function for implicitly adapting
 *  <code>void volatile*</code> pointers as format arguments.
 */
inline stlsoft::basic_shim_string<ff_char_t, 32> filter_type(void volatile* value, void volatile* const*, ff_char_t const volatile*)
{
    void const volatile* value2 = value;

    return filter_type(value2, &value2, static_cast<ff_char_t const volatile*>(0));
}

/** Filtering conversion shim function for implicitly adapting
 *  <code>void*</code> pointers as format arguments.
 */
inline stlsoft::basic_shim_string<ff_char_t, 32> filter_type(void* value, void* const*, ff_char_t const volatile*)
{
    void const volatile* value2 = value;

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

#endif /* FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_VOID_POINTERS */

/* ///////////////////////////// end of file //////////////////////////// */
