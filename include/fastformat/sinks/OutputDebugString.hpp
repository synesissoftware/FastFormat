/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/OutputDebugString.hpp
 *
 * Purpose:     A FastFormat sink for Windows' OutputDebugString().
 *
 * Created:     24th February 2009
 * Updated:     13th September 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/FILE.hpp
 *
 * [C++ only] A FastFormat sink for Windows' <code>OutputDebugString()</code>.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING_EDIT      6
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
#include <fastformat/util/sinks/helpers.hpp>
#include <fastformat/format/standard_flags.hpp>

#include <stlsoft/memory/auto_buffer.hpp>

#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace sinks
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

struct OutputDebugString_helper
{
    static void fn(char const* s)
    {
        ::OutputDebugStringA(s);
    }
    static void fn(wchar_t const* s)
    {
        ::OutputDebugStringW(s);
    }
};
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** Sink for sending a statement to Windows' <code>OutputDebugString()</code>.
 *
 * \ingroup group__sinks
 */
class OutputDebugString_sink
{
public:
    /// This type
    typedef OutputDebugString_sink     class_type;

public:
    /// Constructs the instance
    OutputDebugString_sink()
    {}

public:
    /// Outputs the results, according to the given flags
    class_type& write(int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
    {
        const ff_string_slice_t         newLine = fastformat_getNewlineForPlatform();
        stlsoft::auto_buffer<ff_char_t> buff(1 + cchTotal + ((flags::ff_newLine & flags) ? newLine.len : 0));

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
        if(!buff.empty())
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
        {
#if !defined(FASTFORMAT_NO_NAMESPACE)
            using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

            concat_slices(buff, numResults, results);

            if(flags::ff_newLine & flags)
            {
                ::memcpy(&buff[cchTotal], newLine.ptr, sizeof(ff_char_t) * newLine.len);

                cchTotal += newLine.len;
            }
            buff[cchTotal] = '\0';

            OutputDebugString_helper::fn(buff.data());
        }

        return *this;
    }
};

/* /////////////////////////////////////////////////////////////////////////
 * Action Shims
 */

/** Writes an array of string slices to Windows'
 * <code>OutputDebugString()</code>.
 *
 * \ingroup group__sinks
 */
inline OutputDebugString_sink& fmt_slices(OutputDebugString_sink& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
    return sink.write(flags, cchTotal, numResults, results);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OUTPUTDEBUGSTRING */

/* ///////////////////////////// end of file //////////////////////////// */
