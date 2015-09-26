/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/ostream.hpp
 *
 * Purpose:     A FastFormat sink for writing width-limited output.
 *
 * Created:     21st February 2012
 * Updated:     6th September 2014
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2012-2014, Matthew Wilson and Synesis Software
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
 * [C++ only] A FastFormat sink for writing width-limited output.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINKS_HPP_RIBBON
#define FASTFORMAT_INCL_FASTFORMAT_SINKS_HPP_RIBBON

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINKS_HPP_RIBBON_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_SINKS_HPP_RIBBON_MINOR       0
# define FASTFORMAT_VER_FASTFORMAT_SINKS_HPP_RIBBON_REVISION    1
# define FASTFORMAT_VER_FASTFORMAT_SINKS_HPP_RIBBON_EDIT        1
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>
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
 * Typedefs
 */

enum ribbon_flags_t
{
        ribbon_truncate =   1
    ,   ribbon_truncate_with_ellispsis
};

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template <typename S>
class ribbon_string_adaptor
{
public: // Member Types
    typedef S                           string_type;
    typedef size_t                      size_type;
    typedef ribbon_string_adaptor<S>    class_type;
private:
    typedef string_type::value_type     char_type_;

public: // Construction
    ribbon_string_adaptor(
        string_type&    s
    ,   size_type       maxWidth
    )
        : m_s(s)
        , m_maxWidth(maxWidth)
        , m_flags(ribbon_truncate)
    {}

    ribbon_string_adaptor(
        string_type&    s
    ,   size_type       maxWidth
    ,   ribbon_flags_t  flags
    )
        : m_s(s)
        , m_maxWidth(maxWidth)
        , m_flags(flags)
    {}

public: // Operations
    void
    reserve(
        size_type   n
    )
    {
        if(n > m_maxWidth)
        {
            n = m_maxWidth;
        }

        m_s.reserve(n);
    }

    size_type
    size() const
    {
        return 0;
    }

    void
    append(
        char_type_ const*   p
    ,   size_type           n
    )
    {
        switch(m_flags)
        {
            default:
                FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_APPL_LAYER("unexpected flags value");
            case    ribbon_truncate:
                append_(p, n);
                break;
            case    ribbon_truncate_with_ellispsis:
                append_with_ellipsis_(p, n);
                break;
        }
    }

private: // Implementation
    void
    append_(
        char_type_ const*   p
    ,   size_type           n
    )
    {
        if(n > m_maxWidth)
        {
            n = m_maxWidth;
        }

        m_s.assign(p, n);
    }

    void
    append_with_ellipsis_(
        char_type_ const*   p
    ,   size_type           n
    )
    {
        static char_type_ const s_ellipsis[4] = { '.', '.', '.', '\0' };

        if(n <= m_maxWidth)
        {
            m_s.assign(p, n);
        }
        else
        {
            if(m_maxWidth < 3)
            {
                m_s.assign(s_ellipsis, m_maxWidth);
            }
            else
            {
                m_s.assign(p, m_maxWidth - 3);
                m_s.append(s_ellipsis);
            }
        }
    }

private: // Fields
    string_type&            m_s;
    size_type const         m_maxWidth;
    ribbon_flags_t const    m_flags;
};

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

template <typename S>
inline
ribbon_string_adaptor<S>
ribbon(
    S&              s
,   size_t          maxWidth
,   ribbon_flags_t  flags
)
{
    return ribbon_string_adaptor<S>(s, maxWidth, flags);
}

template <typename S>
inline
ribbon_string_adaptor<S>
ribbon(
    S&      s
,   size_t  maxWidth
)
{
    return ribbon_string_adaptor<S>(s, maxWidth);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */

using ::fastformat::sinks::ribbon;

} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINKS_HPP_RIBBON */

/* ///////////////////////////// end of file //////////////////////////// */
