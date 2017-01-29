/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/vectored_file.hpp
 *
 * Purpose:     A FastFormat sink for the UNIX writev() vector I/O function.
 *
 * Created:     24th November 2007
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/vectored_file.hpp
 *
 * [C++ only] A FastFormat sink for the UNIX writev() vector I/O function.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_VECTORED_FILE
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_VECTORED_FILE

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_VECTORED_FILE_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_VECTORED_FILE_MINOR     1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_VECTORED_FILE_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_VECTORED_FILE_EDIT      24
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
#include <fastformat/internal/stlsoft.h>
#include <fastformat/quality/contract.h>
#include <fastformat/format/standard_flags.hpp>

#ifdef FASTFORMAT_STLSOFT_1_10_B01_OR_LATER
# include <platformstl/exception/platformstl_exception.hpp>
#else /* ? STLSoft version */
# include <platformstl/error/exceptions.hpp>
#endif /* STLSoft version */
#include <stlsoft/memory/auto_buffer.hpp>

#include <string>
#include <sys/uio.h>

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

/** Sink for translating a statement into iovec instructions
 *
 * \ingroup group__sinks
 */
class vectored_file_sink
{
public:
    /// This type
    typedef vectored_file_sink     class_type;

public:
    /// Constructs from a file handle
    explicit vectored_file_sink(int fh)
        : m_fh(fh)
        , m_delim()
    {}
    /// Constructs from a file handle and a delimiter
    vectored_file_sink(int fh, char const* delim)
        : m_fh(fh)
        , m_delim(delim)
    {}

public:
    /// Outputs the results, according to the given flags
    class_type& write(size_t numResults, ff_string_slice_t const* results, int flags)
    {
        stlsoft::auto_buffer<iovec>     vectors(numResults + 2);

#ifdef STLSOFT_CF_THROW_BAD_ALLOC
        if(!vectors.empty())
#endif /* STLSOFT_CF_THROW_BAD_ALLOC */
        {
            FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(vectors.size() == numResults + 2, "vec array must be equal to 2 + the number of results");

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
                const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

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
                throw platformstl::platform_exception("failed to write vectored payload", errno);
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
 * action shims
 */

/** Writes an array of string slices into an <code>iovec</code> sink.
 *
 */
inline vectored_file_sink& fmt_slices(vectored_file_sink& sink, int flags, size_t /* cchTotal */, size_t numResults, ff_string_slice_t const* results)
{
    return sink.write(numResults, results, flags);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_VECTORED_FILE */

/* ///////////////////////////// end of file //////////////////////////// */
