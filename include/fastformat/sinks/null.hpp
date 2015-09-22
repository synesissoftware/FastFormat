/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/null.hpp
 *
 * Purpose:     A class that acts as a bit-bucket sink.
 *
 * Created:     3rd December 2008
 * Updated:     14th September 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/null.hpp
 *
 * [C++ only] A class that acts as a bit-bucket sink.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_NULL
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_NULL

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_NULL_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_NULL_MINOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_NULL_REVISION   2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_NULL_EDIT       6
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
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/quality/contract.h>

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
 * Classes
 */

/** A class that acts as a bit-bucket sink
 *
 * \ingroup group__sinks
 */
struct null_sink
{
    size_t  numWrites;  /*!< The number of times fmt_slices() was invoked on the instance */
    size_t  numSlices;  /*!< The total number of slices passed in all invocations of fmt_slices() */
    size_t  cchTotal;   /*!< The total number of characters passed in all invocations of fmt_slices() */

public: // Construction
    /** Initialises all statistics members to zero
     */
    null_sink()
        : numWrites(0u)
        , numSlices(0u)
        , cchTotal(0u)
    {}
};

/* /////////////////////////////////////////////////////////////////////////
 * Action Shims
 */

/** Writes an array of string slices into a <code>null_sink</code> sink.
 *
 * \ingroup group__sinks
 */
inline null_sink&
  fmt_slices(
    null_sink&                  sink
,   int                         /* flags */
,   size_t                      cchTotal
,   size_t                      numResults
,   ff_string_slice_t const*    results
)
{
    if(NULL == results)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(0u == cchTotal, "Cannot have non-zero size if the results array pointer is null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(0u == numResults, "Cannot have non-zero array elements if the results array pointer is null");
    }
    else
    {
        ++sink.numWrites;
        sink.numSlices  +=  numResults;
        sink.cchTotal   +=  cchTotal;
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

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_NULL */

/* ///////////////////////////// end of file //////////////////////////// */
