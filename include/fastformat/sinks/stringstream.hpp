/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/stringstream.hpp
 *
 * Purpose:     A FastFormat sink for IOStreams' std::stringstream.
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


/** \file fastformat/sinks/stringstream.hpp
 *
 * [C++ only] A FastFormat sink for IOStreams' std::stringstream.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_STRINGSTREAM
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_STRINGSTREAM

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRINGSTREAM_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRINGSTREAM_MINOR      3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRINGSTREAM_REVISION   1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRINGSTREAM_EDIT       13
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

#include <sstream>

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

/** Writes an array of string slices into a <code>std::stringstream</code> sink.
 *
 * \ingroup group__sinks
 *
 */
inline std::basic_stringstream<ff_char_t>&
fmt_slices(
    std::basic_stringstream<ff_char_t>& sink
,   int                                 flags
,   size_t                              /* cchTotal */
,   size_t                              numResults
,   ff_string_slice_t const*            results
)
{
    { for(size_t i = 0; i < numResults; ++i)
    {
        ff_string_slice_t const &slice = results[i];

        if(0 != slice.len)
        {
            sink.write(slice.ptr, static_cast<std::streamsize>(slice.len));
        }
    }}

    switch((0 != (flags::ff_newLine & flags)) + 2 * (0 != (flags::ff_flush & flags)))
    {
        default:
            FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_APPL_LAYER("impossible flags combination permutation");
        case    0:  // Do nothing
            break;
        case    1:  // New line only
            sink.write(FASTFORMAT_LITERAL_STRING("\n"), 1);
            break;
        case    2:  // Flush only
            sink.flush();
            break;
        case    3:  // New line and flush
            sink << std::endl;
            break;
    }

    if(sink.fail())
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        // TODO: Use more-derived exception and capture errno
        throw sink_output_exception("Failed to write statement");
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

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_STRINGSTREAM */

/* ///////////////////////////// end of file //////////////////////////// */
