/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/CString.hpp
 *
 * Purpose:     A FastFormat sink adaptor for MFC's CString.
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


/** \file fastformat/sinks/CString.hpp
 *
 * [C++ only] A FastFormat sink adaptor for MFC's CString.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CSTRING_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CSTRING_MINOR      2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CSTRING_REVISION   4
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CSTRING_EDIT       15
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

#include <afx.h> // MFC requires that it is the first includer of Windows.h

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/util/sinks/helpers.hpp>

#include <mfcstl/string/grab_cstring_buffer.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace sinks
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/** Writes an array of string slices into a <code>CString</code> sink.
 *
 * \ingroup group__sinks
 *
 */
inline CString& fmt_slices(CString& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
    try
    {
#if !defined(FASTFORMAT_NO_NAMESPACE)
        using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

        const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

        if(flags::ff_newLine & flags)
        {
            cchTotal += crlf.len;
        }

        mfcstl::grab_cstring_buffer buff(sink, static_cast<int>(cchTotal) + sink.GetLength());
        ff_char_t*                  base    =   buff;
        size_t                      n       =   concat_slices(cchTotal, base + buff.original_length(), numResults, results);

        n += buff.original_length();

        if(flags::ff_newLine & flags)
        {
            ::memcpy(base + n, crlf.ptr, crlf.len * sizeof(ff_char_t));
            n += crlf.len;
        }
        base[n] = '\0';
    }
    catch(CMemoryException* px)
    {
        px->Delete();

        throw std::bad_alloc();
    }

    return sink;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */

/* ///////////////////////////// end of file //////////////////////////// */
