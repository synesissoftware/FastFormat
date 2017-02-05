/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/FILE.hpp
 *
 * Purpose:     A FastFormat sink for FILE*.
 *
 * Created:     3rd January 2008
 * Updated:     5th February 2017
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


/** \file fastformat/sinks/FILE.hpp
 *
 * [C++ only] A FastFormat sink for <code>FILE*</code>.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_FILE
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_FILE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_FILE_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_FILE_MINOR      3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_FILE_REVISION   7
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_FILE_EDIT       33
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
#include <fastformat/util/sinks/helpers.hpp>
#include <fastformat/format/standard_flags.hpp>

#if _STLSOFT_VER >= 0x010a0182
# include <platformstl/exception/platformstl_exception.hpp>
#else
# include <platformstl/error/exceptions.hpp>
#endif
#include <stlsoft/memory/auto_buffer.hpp>

#include <stdio.h>

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

/** Utility class that allows a standard C stream - \c stdout, \c stderr -
 * to be passed as a sink.
 *
 */
class ff_FILE_sink
{
public: // Member Types

public: // Construction
    /// Constructs an instance of the sink from a <code>FILE*</code>
    /// variable.
    explicit ff_FILE_sink(
        FILE* stm
    )
        : stream(stm)
    {}
    ~ff_FILE_sink() STLSOFT_NOEXCEPT
    {}
private:
    ff_FILE_sink& operator =(ff_FILE_sink const&);

public: // Fields
    /// The underlying <code>FILE*</code> stream.
    FILE* const stream;
};

/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

/** Conversion shim that allows a standard C stream - \c stdout, \c stderr -
 * to be passed as a sink.
 *
\htmlonly
<pre>
  ff::write(<strong>ff::to_sink</strong>(stderr), "oops!");
</pre>
\endhtmlonly
 */
inline
ff_FILE_sink
to_sink(FILE* stm)
{
    return ff_FILE_sink(stm);
}

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/** Writes an array of string slices into a <code>FILE*</code> sink.
 *
 * \ingroup group__sinks
 *
 * \remarks Some C standard library implementations define standard stream
 *   variables via \#define onto internal structures. Often in such cases it
 *   is not possible to pass the standard stream name - e.g. \c stdout -
 *   directly to a <code>fmt()</code> or <code>write()</code> function, since
 *   they need to be able to treat the sink argument as a mutating
 *   (non-<code>const</code>) reference. In such cases, the desired
 *   behaviour may be achieved by using the to_sink(FILE*) creator function,
 *   as in:
 *
\htmlonly
<pre>
  ff::write(<strong>ff::to_sink</strong>(stderr), "oops!");
</pre>
\endhtmlonly
 */
inline
FILE*&
fmt_slices(
    FILE*&                      sink
,   int                         flags
,   size_t                      cchTotal
,   size_t                      numResults
,   ff_string_slice_t const*    results
)
{
    if(NULL == sink)
    {
        return sink;
    }

#ifndef FASTFORMAT_FILE_SINK_OLD_IMPLEMENTATION
    stlsoft::auto_buffer<ff_char_t> buff(cchTotal + 1 + 1); // 1 for \0, 1 for newline (if needed)
#else /* ? !FASTFORMAT_FILE_SINK_OLD_IMPLEMENTATION */
    stlsoft::auto_buffer<ff_char_t> buff(cchTotal);
#endif /* !FASTFORMAT_FILE_SINK_OLD_IMPLEMENTATION */
    int                             n = 0;

# ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(!buff.empty())
# endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    {
# if !defined(FASTFORMAT_NO_NAMESPACE)
        using ::fastformat::util::concat_slices;
# endif /* !FASTFORMAT_NO_NAMESPACE */

#ifndef FASTFORMAT_FILE_SINK_OLD_IMPLEMENTATION

        size_t n2 = concat_slices(buff, numResults, results);
        if(flags::ff_newLine & flags)
        {
            buff[n2++] = '\n';
        }
        buff[n2++] = '\0';

# ifdef FASTFORMAT_USE_WIDE_STRINGS
        n = ::fputws(
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
        n = ::fputs(
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
            buff.data()
        ,   sink
        );

#else /* ? !FASTFORMAT_FILE_SINK_OLD_IMPLEMENTATION */

        concat_slices(buff, numResults, results);

# ifdef FASTFORMAT_USE_WIDE_STRINGS
        n = ::fwprintf(
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
        n = ::fprintf(
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
            sink
        ,   (flags::ff_newLine & flags) ? FASTFORMAT_LITERAL_STRING("%.*s\n") : FASTFORMAT_LITERAL_STRING("%.*s")
        ,   static_cast<int>(cchTotal), buff.data()
        );

#endif /* !FASTFORMAT_FILE_SINK_OLD_IMPLEMENTATION */
    }

    if( n >= 0 &&
        0 != (flags::ff_flush & flags))
    {
        if(0 != ::fflush(sink))
        {
            n = -1;
        }
    }

    if(n < 0)
    {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        // TODO: Use more-derived exception and capture errno
        throw sink_output_exception("Failed to write/flush statement");
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    return sink;
}


/** Writes an array of string slices into a <code>ff_FILE_sink</code> sink.
 *
 * \ingroup group__sinks
 */
inline
ff_FILE_sink&
fmt_slices(
    ff_FILE_sink&               sink
,   int                         flags
,   size_t                      cchTotal
,   size_t                      numResults
,   ff_string_slice_t const*    results
)
{
    FILE* stm = sink.stream;

    fmt_slices(stm, flags, cchTotal, numResults, results);

    return sink;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
using sinks::to_sink;
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
