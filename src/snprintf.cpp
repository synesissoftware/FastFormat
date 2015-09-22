/* /////////////////////////////////////////////////////////////////////////
 * File:        src/snprintf.cpp
 *
 * Purpose:     Implementation file for snprintf() utility functions.
 *
 * Created:     1st June 2008
 * Updated:     3rd February 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2012, Matthew Wilson and Synesis Software
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



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "ximpl_core.hpp"
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif
#include <fastformat/internal/threading.h>
#include <fastformat/util/string/snprintf.h>
#include <fastformat/init_codes.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#include <stlsoft/internal/safestr.h>

#include <stdio.h>

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
 * Compiler / feature discrimination
 *
 * fastformat_util_vsnprintf_a_(d, n, f, a)
 * fastformat_util_vsnprintf_w_(d, n, f, a)
 *
 * fastformat_util_vsnprintf_(d, n, f, a)
 */

#if defined(STLSOFT_COMPILER_IS_DMC) || \
    (   (   defined(WIN32) || \
            defined(WIN64)) && \
        (   defined(STLSOFT_COMPILER_IS_INTEL) || \
            (   defined(STLSOFT_COMPILER_IS_COMO) && \
                defined(_MSC_VER)))) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
#  define fastformat_util_vsnprintf_a_(d, n, f, a)      _vsnprintf_s((d), (n), _TRUNCATE, (f), (a))
#  define fastformat_util_vsnprintf_w_(d, n, f, a)      _vsnwprintf_s((d), (n), _TRUNCATE, (f), (a))
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
#  define fastformat_util_vsnprintf_a_(d, n, f, a)      _vsnprintf((d), (n), (f), (a))
#  define fastformat_util_vsnprintf_w_(d, n, f, a)      _vsnwprintf((d), (n), (f), (a))
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
#else /* ? compiler */
#  define fastformat_util_vsnprintf_a_(d, n, f, a)      ::vsnprintf((d), (n), (f), (a))
#  define fastformat_util_vsnprintf_w_(d, n, f, a)      ::vsnwprintf((d), (n), (f), (a))
#endif /* compiler */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define fastformat_util_vsnprintf_(d, n, f, a)         fastformat_util_vsnprintf_w_(d, n, f, a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define fastformat_util_vsnprintf_(d, n, f, a)         fastformat_util_vsnprintf_a_(d, n, f, a)
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * Private API
 */

FASTFORMAT_CALL(int) fastformat_util_vsnprintf_a(
    char*       dest
,   size_t      cchDest
,   char const* fmt
,   va_list     args
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_util_vsnprintf_a_(dest, cchDest, fmt, args);
}

FASTFORMAT_CALL(int) fastformat_util_snprintf_a(
    char*       dest
,   size_t      cchDest
,   const char* fmt
,   ...
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    va_list args;
    int     ret;

    va_start(args, fmt);

    ret = fastformat_util_vsnprintf_a(dest, cchDest, fmt, args);

    va_end(args);

    FASTFORMAT_COVER_MARK_ENTRY();

    return ret;
}

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

FASTFORMAT_CALL(int) fastformat_util_vsnprintf(
    ff_char_t*          dest
,   size_t              cchDest
,   ff_char_t const*    fmt
,   va_list             args
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_util_vsnprintf_(dest, cchDest, fmt, args);
}

FASTFORMAT_CALL(int) fastformat_util_snprintf(
    ff_char_t*          dest
,   size_t              cchDest
,   const ff_char_t*    fmt
,   ...
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    va_list args;
    int     ret;

    va_start(args, fmt);

    ret = fastformat_util_vsnprintf(dest, cchDest, fmt, args);

    va_end(args);

    FASTFORMAT_COVER_MARK_ENTRY();

    return ret;
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace util */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
