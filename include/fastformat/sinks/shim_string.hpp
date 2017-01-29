/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/shim_string.hpp
 *
 * Purpose:     A FastFormat sink for STLSoft's shim_string class template.
 *
 * Created:     12th November 2008
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


/** \file fastformat/sinks/shim_string.hpp
 *
 * [C++ only] A FastFormat sink for STLSoft's shim_string class template.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_SHIM_STRING
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_SHIM_STRING

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SHIM_STRING_SINK_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SHIM_STRING_SINK_MINOR      0
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SHIM_STRING_SINK_REVISION   5
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SHIM_STRING_SINK_EDIT       13
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

#include <stlsoft/shims/access/string/std/c_string.h>
#include <stlsoft/string/shim_string.hpp>

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
 * compatibility
 */

#if _STLSOFT_VER < 0x010a0000 && \
    defined(_STLSOFT_1_10_VER)
# if _STLSOFT_1_10_VER < 0x010a0109
#  error This file cannot be used with STLSoft 1.10.1 alpha 1 - STLSoft 1.10.1 alpha 8, and is not necessary with STLSoft 1.10.1 alpha 9+ (for which it is not necessary)
# endif /* _STLSOFT_1_10_VER */
#endif /* _STLSOFT_VER */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This class acts as a sink for string shims, to be used with STLSoft 1.9
 *
 * \ingroup group__sinks
 *
 * For example
<pre>
  // in namespace mystuff
  class Thing
  {};

  // in namespace stlsoft
  inline shim_string_sink c_str_ptr_a(mystuff::Thing const& thing)
  {
    shim_string_sink  result;


    return result;
  }
</pre>
 *
 * \note This class is only necessary for STLSoft 1.9. If you're using
 *   STLSoft 1.10 (or the STLSoft 1.10 alpha in combination with
 *   STLSoft 1.9), then you can (and should!) just go ahead and
 *   use <code>stlsoft::basic_shim_string</code>.
 */
class shim_string_sink
    : public stlsoft::basic_shim_string<ff_char_t>
{
public: // Member Types
    /// This type
    typedef shim_string_sink                        class_type;
    /// The parent type
    typedef stlsoft::basic_shim_string<ff_char_t>   parent_class_type;
    /// The size type
    typedef parent_class_type::size_type            size_type;
private:

public: // Construction

    /// Constructs an empty instance
    shim_string_sink()
        : parent_class_type(size_type(0))
#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)
        , m_len(0)
#endif
    {}
    /// Constructs an empty instance with the given capacity
    ///
    /// \param n The required capacity
    explicit shim_string_sink(size_type n)
        : parent_class_type(n)
#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)
        , m_len(0)
#endif
    {}
private:
    class_type& operator =(class_type const& rhs); // Not supported

public: // Operations

    /// Reserves the given capacity
    ///
    /// \param n The required capacity
    void reserve(size_type n)
    {
#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)

        parent_class_type::buffer_type& buffer = parent_class_type::get_buffer();

        if(buffer.resize(n + 1))
        {
            buffer[n] = '\0';
        }

#else
        parent_class_type::reserve(n);
#endif
    }

    /// Appends part of a C-style string
    class_type& append(ff_char_t const* s, size_type n)
    {
#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)

        parent_class_type::buffer_type& buffer = parent_class_type::get_buffer();

        if(m_len + n + 1 > buffer.size())
        {
            if(!buffer.resize(m_len + n + 1))
            {
                buffer[0] = '\0';
                m_len = 0;

                return *this;
            }
        }

        ::memcpy(&buffer[0] + m_len, s, sizeof(ff_char_t) * n);
        m_len += n;
        buffer[m_len] = '\0';

#else
        parent_class_type::append(s, n);
#endif

        return *this;
    }

    /// appends a C-style string
    class_type& append(ff_char_t const* s)
    {
#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)

        append(s, stlsoft::c_str_len(s));

#else
        parent_class_type::append(s);
#endif

        return *this;
    }

    /// truncates the string
    void truncate(size_type n)
    {
        parent_class_type::truncate(n);
    }

#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)

public: // Accessors

    /// The string size 
    size_type size() const
    {
        STLSOFT_ASSERT(m_len < const_cast<class_type*>(this)->parent_class_type::get_buffer().size());

        return m_len;
    }

    /// The string size
    operator size_type() const
    {
        return size();
    }

private:
    size_type   m_len;
#endif
};

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the shim string */
inline
#ifdef FASTFORMAT_USE_WIDE_STRINGS
wchar_t const*
c_str_data_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
char const*
c_str_data_a(
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
    shim_string_sink const& sink
)
{
    return sink.data();
}

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the shim string */
inline
ff_char_t const*
c_str_data(
    shim_string_sink const& sink
)
{
    return sink.data();
}

/** Returns the number of characters in the length of the C-style string representing the shim string */
inline
size_t
#ifdef FASTFORMAT_USE_WIDE_STRINGS
c_str_len_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
c_str_len_a(
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
    shim_string_sink const& sink
)
{
    return sink.size();
}

/** Returns the number of characters in the length of the C-style string representing the shim string */
inline
size_t
c_str_len(
    shim_string_sink const& sink
)
{
    return size_t(sink.size());
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_SHIM_STRING_SINK */

/* ///////////////////////////// end of file //////////////////////////// */
