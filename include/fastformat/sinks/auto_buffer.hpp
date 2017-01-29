/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/auto_buffer.hpp
 *
 * Purpose:     A FastFormat sink for STLSoft's auto_buffer class template.
 *
 * Created:     21st April 2008
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


/** \file fastformat/sinks/auto_buffer.hpp
 *
 * [C++ only] A FastFormat sink for STLSoft's auto_buffer class template.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_AUTO_BUFFER
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_AUTO_BUFFER

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_AUTO_BUFFER_SINK_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_AUTO_BUFFER_SINK_MINOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_AUTO_BUFFER_SINK_REVISION   2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_AUTO_BUFFER_SINK_EDIT       18
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
#include <fastformat/quality/contract.h>
#include <fastformat/util/sinks/helpers.hpp>
#include <fastformat/format/standard_flags.hpp>

#include <fastformat/util/memory/auto_buffer_selector.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310
# ifndef FASTFORMAT_NO_IMPLICIT_ACTION_SHIMS
#  define FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT
# endif /* !FASTFORMAT_NO_IMPLICIT_ACTION_SHIMS */
#endif /* compiler */

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
 * classes
 */

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

#ifndef STLSOFT_AUTO_BUFFER_NEW_FORM
# error This is only compatible with stlsoft::auto_buffer in new mode
#endif /* !STLSOFT_AUTO_BUFFER_NEW_FORM */

/** Formats into an auto_buffer
 *
 * \ingroup group__sinks
 *
 * Because the auto_buffer does not provide any string-carrying semantics
 * we need to define a strict protocol for the semantics of this function:
 *
 * - if the auto_buffer is empty, then the result is written to the given
 *   length, along with the line-terminator if required, and a terminating
 *   nul character is appended
 * - if the auto_buffer is not empty, then the last character is examined
 *    and removed if it is the nul-terminator. Then the result is written,
 *    along with the line-terminator if required, and a terminating nul
 *    character is appended
 *
 * \note For efficiency, this provides the <i>weak exception guarantee</i>,
 *   not the strong. IS THIS TRUE?!?!?!?
 */
#ifndef FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT
template <typename C, size_t N, typename A>
inline stlsoft::auto_buffer<C, N, A>& fmt_slices(
    stlsoft::auto_buffer<C, N, A>&      sink
#else /* ? !FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT */
inline stlsoft::auto_buffer<ff_char_t>& fmt_slices(
    stlsoft::auto_buffer<ff_char_t>&    sink
#endif /* !FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT */
,   int                                 flags
,   size_t                              cchTotal
,   size_t                              numResults
,   ff_string_slice_t const*            results
)
{
#ifndef FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT
    typedef C           char_t;
#else /* ? !FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT */
    typedef ff_char_t   char_t;
#endif /* !FASTFORMAT_AUTO_BUFFER_SINK_ONLY_SIMPLE_FORM_SUPPORT */

    STLSOFT_STATIC_ASSERT(sizeof(char_t) == sizeof(ff_char_t));

    // There're some complications with the size here:
    //
    //  - auto_buffer is guaranteed not to discard allocated memory as long
    //    as resize(0) is not called
    //  - we want strong exception semantics
    //
    // Consequently we ask for the maximum possible size, which is
    //  <current-size> + cchTotal + 1 (for '\0') + 2 (for CR / LF). We will
    // subsequently discard some of this if not needed, without risking
    // needing to ask again for more memory later

    const size_t            initialSize = sink.size();

    // do the resize
    if(sink.resize(initialSize + cchTotal + 1 + 2)) // Check for alloc failure, even though will never return false when exception-handling support is on
    {
        size_t currentSize = initialSize;

        // first we check for a current trailing nul character

        if( 0 != currentSize && 
            '\0' == sink[currentSize - 1])
        {
            --currentSize;
        }

        // next we concatenate all the slices

        ff_char_t* p = sink.data() + currentSize;

        { for(size_t i = 0; i < numResults; ++i)
        {
            ff_string_slice_t const& slice = results[i];

            ::memcpy(p, slice.ptr, slice.len * sizeof(char_t));
            p += slice.len;
        }}

        // then append the new line, if required

        if(flags::ff_newLine & flags)
        {
            const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

            ::memcpy(p, crlf.ptr, crlf.len * sizeof(char_t));
            p += crlf.len;
        }

        // finally we append the terminating nul character

        *p++ = '\0';

        FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_STATE_APPL_LAYER(p <= sink.end(), "auto_buffer sink writing logic failed: write pointer exceeds available space");
        FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_STATE_APPL_LAYER(static_cast<size_t>(p - sink.data()) <= sink.size(), "auto_buffer sink writing logic failed: write pointer exceeds available space");
        //FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_STATE_APPL_LAYER(static_cast<size_t>(p - sink.data()) == currentSize, "auto_buffer sink writing logic failed: write pointer exceeds available space");
        FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_STATE_APPL_LAYER(((sink.data() + currentSize) - p) < static_cast<ptrdiff_t>(fastformat_getNewlineForPlatform().len), "auto_buffer sink writing logic failed: write pointer exceeds available space");

        sink.resize(static_cast<size_t>(p - sink.data()));
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

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_AUTO_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */
