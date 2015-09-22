/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/ACE_CString.hpp
 *
 * Purpose:     A FastFormat sink adaptor for ACE's ACE_CString.
 *
 * Created:     2nd January 2009
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


/** \file fastformat/sinks/ACE_CString.hpp
 *
 * [C++ only] A FastFormat sink adaptor for ACE's ACE_CString.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_ACE_CSTRING
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_ACE_CSTRING

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_ACE_CSTRING_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_ACE_CSTRING_MINOR       1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_ACE_CSTRING_REVISION    1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_ACE_CSTRING_EDIT        5
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
#include <fastformat/quality/contract.h>
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/util/sinks/helpers.hpp>

#include <atlbase.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace sinks
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Action Shims
 */

/** Writes an array of string slices into a <code>ACE_CString</code> sink.
 *
 * \ingroup group__sinks
 *
 */
inline ACE_CString& fmt_slices(ACE_CString& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
#if !defined(FASTFORMAT_NO_NAMESPACE)
    using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

    if( 0 != cchTotal ||
        0 != flags)
    {
        const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

        if(flags::ff_newLine & flags)
        {
            cchTotal += crlf.len;
        }

#if ACE_MAJOR_VERSION < 5 || \
    (   ACE_MAJOR_VERSION == 5 && \
        ACE_MINOR_VERSION < 6)

#else /* ? ACE <5.6 */

        // TODO: Optimise later, by doing a reserve() like operation, and
        // then writing directly into string

        const size_t    initialSize     =   sink.length();
        const size_t    requiredSize    =   initialSize + cchTotal;

#endif /* ACE <5.6 */

        stlsoft::auto_buffer<ff_char_t> buff(1 + cchTotal);

        concat_slices(buff, numResults, results);
        if(flags::ff_newLine & flags)
        {
            ::memcpy(&buff[0] + (cchTotal - crlf.len), crlf.ptr, crlf.len * sizeof(ff_char_t));
        }
        buff[cchTotal] = '\0';

        sink += ACE_CString(buff.data(), cchTotal);
    }

    return sink;
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_ACE_CSTRING */

/* ///////////////////////////// end of file //////////////////////////// */
