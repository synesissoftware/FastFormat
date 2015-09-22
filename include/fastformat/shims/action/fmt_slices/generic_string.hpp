/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/shims/action/fmt_slices/generic_string.hpp
 *
 * Purpose:     FastFormat formatting action shim for generic string types.
 *
 * Created:     19th September 2006
 * Updated:     7th March 2010
 *
 * Thanks:      To Ric Parkin for pointing out the ramifications of 
 *              21.3.5.2/6 and 21.3.1/6 before I change the definition of
 *              c_str_data[_a|_w] to allow NULL to be returned.
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/shims/action/fmt_slices/generic_string.hpp
 *
 * [C++ only] FastFormat formatting action shim for generic string types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING
#define FASTFORMAT_INCL_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING_MAJOR     3
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING_MINOR     2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING_EDIT      21
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
#include <fastformat/internal/stlsoft.h>
#include <fastformat/quality/contract.h>
#include <fastformat/format/standard_flags.hpp>

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
 * Overloadable functions
 */

/** Action shim for generic string types 
 *
 * \remarks Users are encouraged to overload this function (which is an
 *   <i>Action Shim</i>; see "Breaking Up The Monolith") in order to make
 *   their string type compatible and/or to maximise the performance of the
 *   concatenation.
 *
 * \note It is a deliberate design feature to favour speed over
 *   exception-safety here. The exception safety offers only the basic
 *   exception-safety guarantee, rather than the strong. If you require the
 *   strong guarantee, you should write your own action shim.
 */
template <typename S>
inline S& fmt_slices(
    S&                          sink
,   int                         flags
,   size_t                      cchTotal
,   size_t                      numResults
,   ff_string_slice_t const*    results
)
{
    sink.reserve(sink.size() + cchTotal + 2);  // Ask for two more, in case need CR (&LF)

    { for(size_t i = 0; i != numResults; ++i)
    {
        ff_string_slice_t const& slice = results[i];

        if(0u != slice.len) // This test required by 21.3.5.2/6 => 21.3.1/6
        {
            sink.append(slice.ptr, slice.len);
        }
    }}

    if(flags::ff_newLine & flags)
    {
        const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

        sink.append(crlf.ptr, crlf.len);
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

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SHIMS_ACTION_FMT_SLICES_HPP_GENERIC_STRING */

/* ///////////////////////////// end of file //////////////////////////// */
