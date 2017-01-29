/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/ostream.hpp
 *
 * Purpose:     A FastFormat sink for IOStreams' std::ostream.
 *
 * Created:     19th January 2008
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


/** \file fastformat/sinks/ostream.hpp
 *
 * [C++ only] A FastFormat sink for IOStreams' std::ostream.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OSTREAM
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OSTREAM

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OSTREAM_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OSTREAM_MINOR       2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OSTREAM_REVISION    2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_OSTREAM_EDIT        28
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
#include <fastformat/exceptions.hpp>
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/quality/contract.h>
#include <fastformat/util/sinks/helpers.hpp>

#include <ostream>

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

/** Writes an array of string slices into a <code>std::ostream</code> sink.
 *
 * \ingroup group__sinks
 *
 * \note This sink always performs a concatenation, to avoid some atomicity
 *   problems in the output. If you are using string streams, instead
 *   include fastformat/sinks/stringstream.hpp to avoid this step, since it
 *   is unncessary in that case. If you are writing console output from
 *   multiple threads in a multi-threaded program, consider using instead
 *   C's streams library (i.e. <code>stdout</code>/<code>stderr</code>, via
 *   the <code>FILE*</code> sink
 */
inline std::basic_ostream<ff_char_t>& fmt_slices(
    std::basic_ostream<ff_char_t>&  sink
,   int                             flags
,   size_t                          cchTotal
,   size_t                          numResults
,   ff_string_slice_t const*        results
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

    if(sink.fail())
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        // TODO: Use more-derived exception and capture errno
        throw sink_output_exception("Failed to write/flush statement");
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
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

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OSTREAM */

/* ///////////////////////////// end of file //////////////////////////// */
