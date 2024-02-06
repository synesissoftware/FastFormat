/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/stlsoft/FILE_stream.hpp
 *
 * Purpose:     A FastFormat sink for STLSoft's stlsoft::FILE_stream.
 *
 * Created:     19th July 2010
 * Updated:     6th February 2024
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/stlsoft/FILE_stream.hpp
 *
 * [C++ only] A FastFormat sink for STLSoft's stlsoft::FILE_stream.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM
#define FASTFORMAT_INCL_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM_REVISION 3
# define FASTFORMAT_VER_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM_EDIT     6
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
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/quality/contract.h>
#include <fastformat/util/sinks/helpers.hpp>

#include <platformstl/filesystem/FILE_stream.hpp>

#include <ios>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if _STLSOFT_VER < 0x010a0181

# define FASTFORMAT_SINK_STLSOFT_FILE_stream_NS_(x)     stlsoft::x
#else

# define FASTFORMAT_SINK_STLSOFT_FILE_stream_NS_(x)     platformstl::x
#endif

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
 * helper functions
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_FILE_stream
{

template <typename F>
inline F& fmt_slices_(
    F&                          sink
,   int                         flags
,   size_t                      cchTotal
,   size_t                      numResults
,   ff_string_slice_t const*    results
)
{
    stlsoft::auto_buffer<ff_char_t> buff(cchTotal + 1);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(!buff.empty())   // May return false when exception-handling not enabled
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    {
#if !defined(FASTFORMAT_NO_NAMESPACE)
        using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

        concat_slices(buff, numResults, results);

        if(flags::ff_newLine & flags)
        {
            buff[cchTotal] = '\n';
        }
        else
        {
            buff.resize(buff.size() - 1);
        }

        // TODO: translate the exceptions into ff::sink_output_exception

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER == 1400
        // VC++ 8 erroneously (at least IMO) asserts on the validity of the
        // pointer given to write() even when count is 0. Other versions
        // (including 9) don't do this, so we won't bother to catch it
        // otherwise.
        if(0 != buff.size())
#endif /* compiler */
        {
            sink.write(buff.data(), static_cast<std::streamsize>(buff.size()));
        }

        if(flags::ff_flush & flags)
        {
            sink.flush();
        }
    }

    return sink;
}

} /* namespace ximpl_FILE_stream */

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/** Writes an array of string slices into
 * a <code>platformstl::FILE_stream</code> sink.
 */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310

inline
platformstl::FILE_stream&
fmt_slices(
    platformstl::FILE_stream&   sink
,   int                         flags
,   size_t                      cchTotal
,   size_t                      numResults
,   ff_string_slice_t const*    results
)
{
    return ximpl_FILE_stream::fmt_slices_(sink, flags, cchTotal, numResults, results);
}

inline
platformstl::thread_shareable_FILE_stream&
fmt_slices(
    platformstl::thread_shareable_FILE_stream&  sink
,   int                                         flags
,   size_t                                      cchTotal
,   size_t                                      numResults
,   ff_string_slice_t const*                    results
)
{
    return ximpl_FILE_stream::fmt_slices_(sink, flags, cchTotal, numResults, results);
}

#else /* ? compiler */

template<
    typename R
,   typename I
>
inline
platformstl::FILE_stream_base<R, I>&
fmt_slices(
    platformstl::FILE_stream_base<R, I>&    sink
,   int                                     flags
,   size_t                                  cchTotal
,   size_t                                  numResults
,   ff_string_slice_t const*                results
)
{
    return ximpl_FILE_stream::fmt_slices_(sink, flags, cchTotal, numResults, results);
}

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINKS_STLSOFT_HPP_FILE_STREAM */

/* ///////////////////////////// end of file //////////////////////////// */

