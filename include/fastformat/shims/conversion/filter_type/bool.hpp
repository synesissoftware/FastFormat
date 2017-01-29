/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/shims/conversion/filter_type/bool.hpp
 *
 * Purpose:     FastFormat argument conversion shim for bool type.
 *
 * Created:     2nd June 2008
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


/** \file fastformat/shims/conversion/filter_type/bool.hpp
 *
 * [C++ only] FastFormat argument conversion shim for bool type.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL
#define FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL_MINOR      0
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL_REVISION   3
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL_EDIT       8
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
 * helpers
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace ximpl_bool
{

} /* namespace ximpl_bool */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Overloadable conversion shim functions:
 *
 * bool
 */

/** Filtering conversion shim function for implicitly adapting 
 *  <code>bool</code> format arguments.
 */
#if 0
    inline std::basic_string<ff_char_t> filter_type(bool value, bool const*, ff_char_t const volatile*)
    {
        return value ? FASTFORMAT_LITERAL_STRING("True") : FASTFORMAT_LITERAL_STRING("False");
    }
#else /* ? 0 */
    inline ff_string_slice_t filter_type(bool value, bool const*, ff_char_t const volatile*)
    {
        ff_string_slice_t   result;

        // The following implementation is valid only because the string
        // literals go into the program data section, and are available
        // throughout the lifetime of the process.
        if(value)
        {
            result.len  =   4;
            result.ptr  =   FASTFORMAT_LITERAL_STRING("True");
        }
        else
        {
            result.len  =   5;
            result.ptr  =   FASTFORMAT_LITERAL_STRING("False");
        }

        return result;
    }
#endif /* 0 */

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

#endif /* FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_BOOL */

/* ///////////////////////////// end of file //////////////////////////// */
