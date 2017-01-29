/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/char_buffer.hpp
 *
 * Purpose:     A FastFormat sink for fixed length character buffers.
 *
 * Created:     14th April 2008
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


/** \file fastformat/sinks/char_buffer.hpp
 *
 * [C++ only] A FastFormat sink for fixed length character buffers.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CHAR_BUFFER
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CHAR_BUFFER

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CHAR_BUFFER_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CHAR_BUFFER_MINOR       2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CHAR_BUFFER_REVISION    4
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CHAR_BUFFER_EDIT        18
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

#include <stdexcept>

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

/** Sink for translating a statement into char_buffer instructions
 *
 * \ingroup group__sinks
 */
class char_buffer_sink
{
public:
    /// This type
    typedef char_buffer_sink    class_type;
    /// The character type
    typedef ff_char_t           char_type;
    /// The size type
    typedef size_t              size_type;

public:
    /// Constructs from a character buffer
    char_buffer_sink(size_type n, char_type* buffer)
        : m_capacity(n)
        , m_len(0)
        , m_buffer(buffer)
    {}
#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
    /// Constructs from a character array
    template <size_t N>
    explicit
    char_buffer_sink(char_type (&ar)[N])
        : m_capacity(N)
        , m_len(0)
        , m_buffer(&ar[0])
    {}
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */

public: // Attributes
    /// The number of characters written to the sink
    size_type size() const
    {
        return m_len;
    }
    /// The total number of characters accessible to the sink
    size_type capacity() const
    {
        return m_capacity;
    }

public: // Operations
    /// Outputs the results, according to the given flags
    class_type& write(size_type cchTotal, size_type numResults, ff_string_slice_t const* results, int flags)
    {
        const ff_string_slice_t crlf            =   fastformat_getNewlineForPlatform();

        const size_type         requiredSize    =   size()
                                                    +   cchTotal
                                                    +   ((flags::ff_newLine & flags) ? crlf.len : 0)
                                                    ;

        if(requiredSize > capacity())
        {
            throw std::out_of_range("character buffer sink capacity exceeded");
        }
        else
        {
            char_type* p = &m_buffer[0] + size();

            // next we concatenate all the slices

            { for(size_type i = 0; i < numResults; ++i)
            {
                ff_string_slice_t const& slice = results[i];

                ::memcpy(p, slice.ptr, slice.len * sizeof(char_type));
                p += slice.len;
            }}

            m_len += cchTotal;

            // then append the new line, if required

            if(flags::ff_newLine & flags)
            {
                ::memcpy(p, crlf.ptr, crlf.len * sizeof(char_type));
                p += crlf.len;

                m_len += crlf.len;
            }

            FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_STATE_APPL_LAYER(p == &m_buffer[0] + size(), "char_buffer sink writing logic failed: write pointer in wrong place");
        }

        return *this;
    }

private: // Member variables
    const size_type     m_capacity;
    size_t              m_len;
    char_type* const    m_buffer;

private: // Not to be implemented
    char_buffer_sink(class_type const&);
    class_type& operator =(class_type const&);
};

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/** Formats into a char_buffer
 *
 * \ingroup group__sinks
 *
 */
inline char_buffer_sink& fmt_slices(char_buffer_sink& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
    return sink.write(cchTotal, numResults, results, flags);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CHAR_BUFFER */

/* ///////////////////////////// end of file //////////////////////////// */
