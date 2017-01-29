/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/util/filesystem/FILE_functions.hpp
 *
 * Purpose:     Utility functions for using <code>FILE*</code>.
 *
 * Created:     3rd January 2008
 * Updated:     22nd January 2017
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


/** \file fastformat/util/filesystem/FILE_functions.hpp
 *
 * [C++ only] Utility functions for using <code>FILE*</code>.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS
#define FASTFORMAT_INCL_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS_EDIT      3
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
# include <fastformat/fastformat.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT
# include <fastformat/internal/stlsoft.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT */

#include <platformstl/system/system_traits.hpp>
#if _STLSOFT_VER < 0x010a0181

# include <platformstl/error/exceptions.hpp>
#else

# include <platformstl/exception/filesystem_exception.hpp>
# include <stlsoft/util/exception_string_creator.hpp>
#endif

#include <stlsoft/internal/safestr.h>

#include <errno.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace util
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

inline
FILE*
fopen_or_throw(
    char const* fileName
,   char const* mode
)
{
#if defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) &&\
    defined(STLSOFT_COMPILER_IS_MSVC)
    FILE* f;
    int   e = ::fopen_s(&f, fileName, mode);

    if(0 != e)
    {
#else // }
    FILE* f = ::fopen(fileName, mode);

    if(NULL == f)
    {
#endif

#if _STLSOFT_VER < 0x010a0181

        throw platformstl::platform_exception((std::string("Could not open file '") + fileName + "'").c_str(), platformstl::system_traits<char>::get_last_error());
#else
        stlsoft::exception_string_creator   xsc(100);

        xsc.append("Count not open file '");
        xsc.append(fileName);
        xsc.append('\'');

        throw platformstl::filesystem_exception(xsc.c_str(), platformstl::system_traits<char>::get_last_error());
#endif
    }

    return f;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace util */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_UTIL_FILESYSTEM_HPP_FILE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
