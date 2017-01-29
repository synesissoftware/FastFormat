/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/iterators/format_iterator.hpp
 *
 * Purpose:     Definition of the fastformat::format_iterator output
 *              iterator.
 *
 * Created:     20th May 2009
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/iterators/format_iterator.hpp
 *
 * [C++ only] Definition of the fastformat::format_iterator output iterator.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR
#define FASTFORMAT_INCL_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR_MINOR      1
# define FASTFORMAT_VER_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR_REVISION   6
# define FASTFORMAT_VER_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR_EDIT       13
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

#include <fastformat/fastformat.hpp>
#include <fastformat/internal/stlsoft.h>
#include <fastformat/quality/contract.h>

#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/util/std/iterator_helper.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace iterators
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_format_iterator
{

    struct no_arg_t
    {};

    template <typename T>
    struct ref_helper
    {
    public:
        static T const& get_ref(T const& t)
        {
            return t;
        }
    };
    STLSOFT_TEMPLATE_SPECIALISATION
    struct ref_helper<no_arg_t>
    {
        static ff_char_t const* get_ref(no_arg_t const&)
        {
            static ff_char_t s_empty[] = { '\0' };

            return s_empty;
        }
    };

} /* namespace ximpl_format_iterator */

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** This class template defines an output iterator that writes to
 *   a given sink using fastformat::fmt()
 *
 * For examples of usage, see the fastformat::format_iterator() creator
 * function.
 */
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        ,   typename A5
        ,   typename A6
        ,   typename A7
        ,   typename A8
        >
class format_output_iterator
    : public stlsoft::iterator_base<std::output_iterator_tag, void, void, void, void>
{
public:
    /// This type
    typedef format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, A7, A8>    class_type;
    /// The sink type
    typedef S                                                               sink_type;
    /// The format type
    typedef F                                                               format_type;
private:
    typedef std::basic_string<ff_char_t>                                    string_type_;

private:
    class deref_proxy;
    friend class deref_proxy;

#if defined(STLSOFT_COMPILER_IS_MWERKS)
public:
#else
private:
#endif
    static ximpl_format_iterator::no_arg_t const& no_arg_ref_()
    {
      // NOTE: this is a race-condition, but it's entirely benign

      static ximpl_format_iterator::no_arg_t r;

      return r;
    }

public:
    /// Constructor
    format_output_iterator(sink_type& sink, format_type const& format)
        : m_sink(&sink)
        , m_format(::stlsoft::c_str_data(format), ::stlsoft::c_str_len(format))
        , m_n(0)
        , m_arg1(&no_arg_ref_())
        , m_arg2(&no_arg_ref_())
        , m_arg3(&no_arg_ref_())
        , m_arg4(&no_arg_ref_())
        , m_arg5(&no_arg_ref_())
        , m_arg6(&no_arg_ref_())
        , m_arg7(&no_arg_ref_())
        , m_arg8(&no_arg_ref_())
    {}
    /// Constructor taking 1-8 additional format parameters
    format_output_iterator(
        sink_type&          sink
    ,   format_type const&  format
    ,   unsigned            n
    ,   A1 const&           arg1
    ,   A2 const&           arg2 = no_arg_ref_()
    ,   A3 const&           arg3 = no_arg_ref_()
    ,   A4 const&           arg4 = no_arg_ref_()
    ,   A5 const&           arg5 = no_arg_ref_()
    ,   A6 const&           arg6 = no_arg_ref_()
    ,   A7 const&           arg7 = no_arg_ref_()
    ,   A8 const&           arg8 = no_arg_ref_()
    )
        : m_sink(&sink)
        , m_format(::stlsoft::c_str_data(format), ::stlsoft::c_str_len(format))
        , m_n(n)
        , m_arg1(&arg1)
        , m_arg2(&arg2)
        , m_arg3(&arg3)
        , m_arg4(&arg4)
        , m_arg5(&arg5)
        , m_arg6(&arg6)
        , m_arg7(&arg7)
        , m_arg8(&arg8)
    {}

private:
    /** <a href="http://synesis.com.au/publishing/xstl/glossary.html#dereference-proxy">Dereference Proxy</a> for
     * \c fastformat::iterators::format_output_iterator
     */
    class deref_proxy
    {
    public:
        deref_proxy(format_output_iterator* it)
            : m_it(it)
        {}

    public:
        template <typename A>
        void operator =(A const& value)
        {
            m_it->invoke_(value);
        }

    private:
        format_output_iterator* const m_it;

    private:
        void operator =(deref_proxy const&);
    };

    template <typename A>
    void invoke_(A const& value)
    {
        switch(m_n)
        {
            case    0:
                fmt(*m_sink, m_format, value);
                break;
            case    1:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1));
                break;
            case    2:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2));
                break;
            case    3:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2), ximpl_format_iterator::ref_helper<A3>::get_ref(*m_arg3));
                break;
            case    4:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2), ximpl_format_iterator::ref_helper<A3>::get_ref(*m_arg3), ximpl_format_iterator::ref_helper<A4>::get_ref(*m_arg4));
                break;
            case    5:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2), ximpl_format_iterator::ref_helper<A3>::get_ref(*m_arg3), ximpl_format_iterator::ref_helper<A4>::get_ref(*m_arg4), ximpl_format_iterator::ref_helper<A5>::get_ref(*m_arg5));
                break;
            case    6:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2), ximpl_format_iterator::ref_helper<A3>::get_ref(*m_arg3), ximpl_format_iterator::ref_helper<A4>::get_ref(*m_arg4), ximpl_format_iterator::ref_helper<A5>::get_ref(*m_arg5), ximpl_format_iterator::ref_helper<A6>::get_ref(*m_arg6));
                break;
            case    7:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2), ximpl_format_iterator::ref_helper<A3>::get_ref(*m_arg3), ximpl_format_iterator::ref_helper<A4>::get_ref(*m_arg4), ximpl_format_iterator::ref_helper<A5>::get_ref(*m_arg5), ximpl_format_iterator::ref_helper<A6>::get_ref(*m_arg6), ximpl_format_iterator::ref_helper<A7>::get_ref(*m_arg7));
                break;
            case    8:
                fmt(*m_sink, m_format, value, ximpl_format_iterator::ref_helper<A1>::get_ref(*m_arg1), ximpl_format_iterator::ref_helper<A2>::get_ref(*m_arg2), ximpl_format_iterator::ref_helper<A3>::get_ref(*m_arg3), ximpl_format_iterator::ref_helper<A4>::get_ref(*m_arg4), ximpl_format_iterator::ref_helper<A5>::get_ref(*m_arg5), ximpl_format_iterator::ref_helper<A6>::get_ref(*m_arg6), ximpl_format_iterator::ref_helper<A7>::get_ref(*m_arg7), ximpl_format_iterator::ref_helper<A8>::get_ref(*m_arg8));
                break;
        }
    }

public:
    /// Dereference operator
    deref_proxy operator *()
    {
        return deref_proxy(this);
    }
    /// Pre-increment operator
    class_type& operator ++()
    {
        return *this;
    }
    /// Post-increment operator
    class_type operator ++(int)
    {
        return *this;
    }

private:
    sink_type*      m_sink;
    string_type_    m_format;
    unsigned        m_n;
    A1 const*       m_arg1;
    A2 const*       m_arg2;
    A3 const*       m_arg3;
    A4 const*       m_arg4;
    A5 const*       m_arg5;
    A6 const*       m_arg6;
    A7 const*       m_arg7;
    A8 const*       m_arg8;
};

#ifdef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
/** <a href="http://synesis.com.au/publishing/xstl/glossary.html#creator-function">Creator function</a> for 
 * the fastformat::iterators::format_output_iterator output iterator class template.
 *
 * Used as follows
<pre>
  std::vector&lt;std::string>  strings;

  strings.push_back("abc");
  strings.push_back("def");
  strings.push_back("ghi");

  std::cout &lt;&lt; "with std::ostream_iterator:\n";
  std::copy(strings.begin(), strings.end()
          , std::ostream_iterator&lt;string_t>(std::cout, "\n"));
  std::cout &lt;&lt; "\n";

  std::cout &lt;&lt; "with fastformat::format_iterator:\n";
  std::copy(strings.begin(), strings.end()
          , fastformat::format_iterator(std::cout, "\t{0}\n"));
  std::cout &lt;&lt; "\n";

  FILE* stm = stdout;
  std::cout &lt;&lt; "with fastformat::format_iterator (with stdout):\n";
  std::copy(strings.begin(), strings.end()
          , fastformat::format_iterator(stm, "\t{0}\n"));
  std::cout &lt;&lt; "\n";
</pre>
 *
 * \note Unlike \c std::ostream_iterator, there is no requirement to specify
 *   the value type, as that will be inferred by the FastFormat Application
 *   Layer in the usual manner.
 *
 * \param sink The sink to which to write, e.g. \c std::cout
 * \param format An instance of any string type, to be used as the format
 *   for the underlying fastformat::fmt() call, e.g. \c "\t{0}\n". It must
 *   contain at least one instance of the replacement parameter \c {0}, and
 *   no instances of any replacement parameters with higher indexes (except
 *   those specified by additional parameters).
 * \param ... up to 8 additional parameters, to be matched by format
 *   replacement parameters \c {1} to \c {8}
 */

template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        ,   typename A5
        ,   typename A6
        ,   typename A7
        ,   typename A8
        >
format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, A7, A8> format_iterator(S& sink, F const& format, ...)
{}
#else /* ? FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
template<   typename S
        ,   typename F
        >
inline format_output_iterator<S, F, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(S& sink, F const& format)
{
    return format_output_iterator<S, F, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format);
}
template<   typename S
        ,   typename F
        ,   typename A1
        >
inline format_output_iterator<S, F, A1, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
)
{
    return format_output_iterator<S, F, A1, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format, 1u, arg1);
}
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        >
inline format_output_iterator<S, F, A1, A2, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
)
{
    return format_output_iterator<S, F, A1, A2, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format, 2u, arg1, arg2);
}

template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        >
inline format_output_iterator<S, F, A1, A2, A3, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
,   A3 const&   arg3
)
{
    return format_output_iterator<S, F, A1, A2, A3, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format, 3u, arg1, arg2, arg3);
}
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        >
inline format_output_iterator<S, F, A1, A2, A3, A4, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
,   A3 const&   arg3
,   A4 const&   arg4
)
{
    return format_output_iterator<S, F, A1, A2, A3, A4, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format, 4u, arg1, arg2, arg3, arg4);
}
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        ,   typename A5
        >
inline format_output_iterator<S, F, A1, A2, A3, A4, A5, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
,   A3 const&   arg3
,   A4 const&   arg4
,   A5 const&   arg5
)
{
    return format_output_iterator<S, F, A1, A2, A3, A4, A5, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format, 5u, arg1, arg2, arg3, arg4, arg5);
}
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        ,   typename A5
        ,   typename A6
        >
inline format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
,   A3 const&   arg3
,   A4 const&   arg4
,   A5 const&   arg5
,   A6 const&   arg6
)
{
    return format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, ximpl_format_iterator::no_arg_t, ximpl_format_iterator::no_arg_t>(sink, format, 6u, arg1, arg2, arg3, arg4, arg5, arg6);
}
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        ,   typename A5
        ,   typename A6
        ,   typename A7
        >
inline format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, A7, ximpl_format_iterator::no_arg_t> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
,   A3 const&   arg3
,   A4 const&   arg4
,   A5 const&   arg5
,   A6 const&   arg6
,   A7 const&   arg7
)
{
    return format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, A7, ximpl_format_iterator::no_arg_t>(sink, format, 7u, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}
template<   typename S
        ,   typename F
        ,   typename A1
        ,   typename A2
        ,   typename A3
        ,   typename A4
        ,   typename A5
        ,   typename A6
        ,   typename A7
        ,   typename A8
        >
inline format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, A7, A8> format_iterator(
    S&          sink
,   F const&    format
,   A1 const&   arg1
,   A2 const&   arg2
,   A3 const&   arg3
,   A4 const&   arg4
,   A5 const&   arg5
,   A6 const&   arg6
,   A7 const&   arg7
,   A8 const&   arg8
)
{
    return format_output_iterator<S, F, A1, A2, A3, A4, A5, A6, A7, A8>(sink, format, 8u, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
}
#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace iterators */
using ::fastformat::iterators::format_iterator;
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_ITERATORS_HPP_FORMAT_ITERATOR */

/* ///////////////////////////// end of file //////////////////////////// */
