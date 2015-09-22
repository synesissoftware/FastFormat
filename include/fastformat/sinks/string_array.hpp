/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/string_array.hpp
 *
 * Purpose:     A FastFormat sink for string sequences.
 *
 * Created:     24th December 2007
 * Updated:     13th September 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2010, Matthew Wilson and Synesis Software
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



#error This file is not ready

/** \file fastformat/sinks/string_array.hpp
 *
 * [C++ only] A FastFormat sink for string sequences.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_STRING_ARRAY
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_STRING_ARRAY

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRING_ARRAY_MAJOR      0
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRING_ARRAY_MINOR      0
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRING_ARRAY_REVISION   1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_STRING_ARRAY_EDIT       5
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

#include <platformstl/error/exceptions.hpp>
#include <stlsoft/memory/auto_buffer.hpp>

#include <string>

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

/** Sink for translating a statement into an entry in an array of strings
 *
 * \ingroup group__sinks
 */
class string_array_sink
{
public:
    /// This type
    typedef string_array_sink     class_type;

public:
    /// Constructs from a string array
    string_array_sink(int fh)
        : m_fh(fh)
        , m_delim()
    {}
    /// Constructs from a string array and a delimiter
    string_array_sink(int fh, char const* delim)
        : m_fh(fh)
        , m_delim(delim)
    {}

public:
    /// Writes the results, according to the given flags
    class_type& write(size_t numResults, ff_string_slice_t const* results, int flags)
    {
        stlsoft::auto_buffer<iovec>     vectors(numResults + 2);
        ff_string_slice_t               crlf = fastformat_getNewlineForPlatform();

#ifdef STLSOFT_CF_THROW_BAD_ALLOC
        if(!vectors.empty())
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
        {
            STLSOFT_ASSERT(vectors.size() == numResults + 2);

            { for(size_t i = 0; i != vectors.size() - 2; ++i)
            {
                vectors[i].iov_base =   const_cast<char*>(results[i].ptr);
                vectors[i].iov_len  =   results[i].len;
            }}

            if(!m_delim.empty())
            {
                vectors[vectors.size() - 2].iov_base    =   const_cast<char*>(m_delim.data());
                vectors[vectors.size() - 2].iov_len     =   m_delim.size();
            }
            else
            {
                vectors.resize(vectors.size() - 1);
            }

            if(flags::ff_newLine & flags)
            {
                vectors[vectors.size() - 1].iov_base    =   const_cast<char*>(crlf.ptr);
                vectors[vectors.size() - 1].iov_len     =   crlf.len;
            }
            else
            {
                vectors.resize(vectors.size() - 1);
            }

            if(::writev(m_fh, &vectors[0], static_cast<int>(vectors.size())) < 0)
            {
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
                throw platformstl::platform_exception("failed to write vector payload", errno);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
            }

#if 0
            if(flags::ff_flush & flags)
            {
                ::flush(m_fh);
            }
#endif /* 0 */
        }

        return *this;
    }

private:
    int         m_fh;
    std::string m_delim;
};

/* /////////////////////////////////////////////////////////////////////////
 * Action Shims
 */

/** Writes an array of string slices into a string array sink.
 *
 * \ingroup group__sinks
 *
 */
inline string_array_sink& fmt_slices(string_array_sink& sink, int flags, size_t /* cchTotal */, size_t numResults, ff_string_slice_t const* results)
{
    return sink.write(numResults, results, flags);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_STRING_ARRAY */

/* ///////////////////////////// end of file //////////////////////////// */
