/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/util/string/snprintf.h (was fastformat/util/string/string.h)
 *
 * Purpose:     snprintf() utility functions.
 *
 * Created:     1st June 2008
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/util/string/string.h
 *
 * [C, C++] snprintf() utility functions.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_UTIL_STRING_H_SNPRINTF
#define FASTFORMAT_INCL_FASTFORMAT_UTIL_STRING_H_SNPRINTF

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_UTIL_STRING_H_SNPRINTF_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_UTIL_STRING_H_SNPRINTF_MINOR     3
# define FASTFORMAT_VER_FASTFORMAT_UTIL_STRING_H_SNPRINTF_REVISION  4
# define FASTFORMAT_VER_FASTFORMAT_UTIL_STRING_H_SNPRINTF_EDIT      13
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
# include <fastformat/fastformat.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

#ifndef FASTFORMAT_INCL_H_STDARG
# define FASTFORMAT_INCL_H_STDARG
# include <stdarg.h>
#endif /* !FASTFORMAT_INCL_H_STDARG */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace util
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

/** An <code>snprintf()</code>-equivalent that insulates FastFormat
 *   implementation code from the peculiarities of different compilers
 *   and/or libraries.
 *
 * \param dest The buffer into which the result will be written
 * \param cchDest The number of character spaces that are available to be
 *   written
 * \param fmt The format string
 *
 * \return The usual return values defined for <code>snprintf()</code>
 */
FASTFORMAT_CALL(int) fastformat_util_snprintf(
    ff_char_t*          dest
,   size_t              cchDest
,   const ff_char_t*    fmt
,   ...
)
/* TODO: Change this to properly discriminated feature */
#if defined(STLSOFT_COMPILER_IS_GCC)
__attribute__((format(printf,3,4)))
#endif /* compiler */
;

/** A <code>vsnprintf()</code>-equivalent that insulates FastFormat
 *   implementation code from the peculiarities of different compilers
 *   and/or libraries.
 *
 * \param dest The buffer into which the result will be written
 * \param cchDest The number of character spaces that are available to be
 *   written
 * \param fmt The format string
 * \param args The argument list
 *
 * \return The usual return values defined for <code>vsnprintf()</code>
 */
FASTFORMAT_CALL(int) fastformat_util_vsnprintf(
    ff_char_t*          dest
,   size_t              cchDest
,   ff_char_t const*    fmt
,   va_list             args
);

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
FASTFORMAT_CALL(int) fastformat_util_snprintf_a(
    char*           dest
,   size_t          cchDest
,   const char*     fmt
,   ...
)
/* TODO: Change this to properly discriminated feature */
#if defined(STLSOFT_COMPILER_IS_GCC)
__attribute__((format(printf,3,4)))
#endif /* compiler */
;
FASTFORMAT_CALL(int) fastformat_util_vsnprintf_a(
    char*           dest
,   size_t          cchDest
,   char const*     fmt
,   va_list         args
);
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ Functions
 */

#ifdef __cplusplus
# ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
#  ifndef FASTFORMAT_NO_NAMESPACE

inline
int
vsnprintf(
    ff_char_t*          dest
,   size_t              cchDest
,   ff_char_t const*    fmt
,   va_list             args
)
{
    return fastformat_util_vsnprintf(dest, cchDest, fmt, args);
}

inline
int
snprintf(
    ff_char_t*          dest
,   size_t              cchDest
,   const ff_char_t*    fmt
,   ...
)
{
    va_list args;
    int     r;

    va_start(args, fmt);

    r = fastformat_util_vsnprintf(dest, cchDest, fmt, args);

    va_end(args);

    return r;
}

#  endif /* !FASTFORMAT_NO_NAMESPACE */
# endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace util */
using ::fastformat::util::fastformat_util_snprintf;
using ::fastformat::util::fastformat_util_vsnprintf;

using ::fastformat::util::fastformat_util_snprintf_a;
using ::fastformat::util::fastformat_util_vsnprintf_a;
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_UTIL_STRING_H_SNPRINTF */

/* ///////////////////////////// end of file //////////////////////////// */
