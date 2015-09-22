/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/shims/conversion/filter_type/fast_integers.hpp
 *
 * Purpose:     FastFormat argument conversion shim for fast, non-L10N,
 *              conversion of integral types.
 *
 * Created:     1st June 2008
 * Updated:     30th July 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2012, Matthew Wilson and Synesis Software
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


/** \file fastformat/shims/conversion/filter_type/fast_integers.hpp
 *
 * [C++ only] FastFormat argument conversion shim for fast, non-L10N,
 *  conversion of integral types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS
#define FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS_MAJOR     2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS_MINOR     2
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS_EDIT      20
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

#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/string/shim_string.hpp>
#if STLSOFT_LEAD_VER >= 0x010a0000
 /* presumption of STLSoft 1.10 */
# include <stlsoft/limits/integral_format_width_limits.hpp>
#else /* ? STLSOFT_LEAD_VER */
# include <stlsoft/util/integral_printf_traits.hpp>
#endif /* STLSOFT_LEAD_VER */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace filters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

namespace ximpl_fast_integers
{
    template <typename I>
    struct integer_shim
    {
    public:
        typedef I                                                               integer_type;
    private:
#if STLSOFT_LEAD_VER >= 0x010a0000
        typedef ss_typename_type_k stlsoft::integral_format_width_limits<I>     traits_type_;
#else /* ? STLSOFT_LEAD_VER */
        typedef ss_typename_type_k stlsoft::integral_printf_traits<I>           traits_type_;
#endif /* STLSOFT_LEAD_VER */

    public:
        enum
        {
#if STLSOFT_LEAD_VER >= 0x010a0000
            N = (1 + traits_type_::maxDecimalWidth)
#else /* ? STLSOFT_LEAD_VER */
            N = (1 + traits_type_::size_max)
#endif /* STLSOFT_LEAD_VER */
        };

    public:
        ff_char_t const*    ptr;
        ff_char_t           buff[N];
        size_t              len;

    public:
        integer_shim()
        {}

        integer_shim(integer_shim const& rhs)
            : ptr(&buff[0] + (rhs.ptr - &rhs.buff[0]))
            , len(rhs.len)
        {
            ::memcpy(const_cast<ff_char_t*>(ptr), rhs.ptr, sizeof(ff_char_t) * len);
        }

    public:
        void assign(ff_char_t const* p)
        {
            this->ptr = p;
        }

    public:
        ff_char_t const*    data() const
        {
            return ptr;
        }
        size_t              size() const
        {
            return len;
        }
    };

# if defined(STLSOFT_CF_BUILTIN_long_long_SUPPORT)
    typedef signed long long    ff_fi_sint64_t;
    typedef unsigned long long  ff_fi_uint64_t;
# elif defined(STLSOFT_CF_64BIT_INT_SUPPORT)
    typedef ::stlsoft::sint64_t ff_fi_sint64_t;
    typedef ::stlsoft::uint64_t ff_fi_uint64_t;
# else /* ? 64-bit / long long */
#  error Bad discrimination
# endif /* 64-bit / long long */


} /* namespace ximpl_fast_integers */

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Overloadable conversion shim functions:
 *
 * 64-bit/long long signed
 * 64-bit/long long unsigned
 * long signed
 * long unsigned
 * int signed
 * int unsigned
 * short signed
 * short unsigned
 */

#if defined(STLSOFT_CF_BUILTIN_long_long_SUPPORT) || \
    defined(STLSOFT_CF_64BIT_INT_SUPPORT)

/** Filtering conversion shim function for implicitly adapting signed
 *  64-bit/<code>long long</code> integers as format arguments.
 */

inline
ximpl_fast_integers::integer_shim<
    ximpl_fast_integers::ff_fi_sint64_t
>
filter_type(
    ximpl_fast_integers::ff_fi_sint64_t value
,   ximpl_fast_integers::ff_fi_sint64_t const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<ximpl_fast_integers::ff_fi_sint64_t> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/** Filtering conversion shim function for implicitly adapting unsigned
 *  64-bit/<code>long long</code> integers as format arguments.
 */

inline
ximpl_fast_integers::integer_shim<
    ximpl_fast_integers::ff_fi_uint64_t
>
filter_type(
    ximpl_fast_integers::ff_fi_uint64_t value
,   ximpl_fast_integers::ff_fi_uint64_t const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<ximpl_fast_integers::ff_fi_uint64_t> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

#endif /* STLSOFT_CF_BUILTIN_long_long_SUPPORT || STLSOFT_CF_64BIT_INT_SUPPORT */

/** Filtering conversion shim function for implicitly adapting signed
 *  <code>long</code> integers as format arguments.
 */
inline
ximpl_fast_integers::integer_shim<
    signed long
>
filter_type(
    signed long value
,   signed long const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<signed long> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/** Filtering conversion shim function for implicitly adapting unsigned
 *  <code>long</code> integers as format arguments.
 */
inline
ximpl_fast_integers::integer_shim<
    unsigned long
>
filter_type(
    unsigned long value
,   unsigned long const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<unsigned long> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/** Filtering conversion shim function for implicitly adapting signed
 *  <code>int</code> integers as format arguments.
 */
inline
ximpl_fast_integers::integer_shim<
    signed int
>
filter_type(
    signed int value
,   signed int const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<signed int> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/** Filtering conversion shim function for implicitly adapting unsigned
 *  <code>int</code> integers as format arguments.
 */
inline
ximpl_fast_integers::integer_shim<
    unsigned int
>
filter_type(
    unsigned int value
,   unsigned int const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<unsigned int> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/** Filtering conversion shim function for implicitly adapting signed
 *  <code>short</code> integers as format arguments.
 */
inline
ximpl_fast_integers::integer_shim<
    signed short
>
filter_type(
    signed short value
,   signed short const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<signed short> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/** Filtering conversion shim function for implicitly adapting unsigned
 *  <code>short</code> integers as format arguments.
 */
inline
ximpl_fast_integers::integer_shim<
    unsigned short
>
filter_type(
    unsigned short value
,   unsigned short const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<unsigned short> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, &r.len));

    return r;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifdef STLSOFT_CF_INT_DISTINCT_INT_TYPE
inline
ximpl_fast_integers::integer_shim<
    ::stlsoft::sint32_t
>
filter_type(
    ::stlsoft::sint32_t value
,   ::stlsoft::sint32_t const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<::stlsoft::sint32_t> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, r.len));

    return r;
}

inline
ximpl_fast_integers::integer_shim<
    ::stlsoft::uint32_t
>
filter_type(
    ::stlsoft::uint32_t value
,   ::stlsoft::uint32_t const*
,   ff_char_t const volatile*
)
{
    ximpl_fast_integers::integer_shim<::stlsoft::uint32_t> r;

    r.assign(stlsoft::integer_to_string(r.buff, STLSOFT_NUM_ELEMENTS(r.buff), value, r.len));

    return r;
}
#endif /* STLSOFT_CF_INT_DISTINCT_INT_TYPE */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
template <typename I>
#ifdef FASTFORMAT_USE_WIDE_STRINGS
inline
wchar_t const*
c_str_data_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline
char const*
c_str_data_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#if 1
    return s.data();
#else /* ? 0 */
    return s.ptr;
#endif /* 0 */
}

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
template <typename I>
inline
ff_char_t const*
c_str_data(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_data_w(s);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_data_a(s);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/** Returns the number of characters in the length of the C-style string representing the structure */
template <typename I>
#ifdef FASTFORMAT_USE_WIDE_STRINGS
inline
size_t
c_str_len_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline
size_t
c_str_len_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#if 0
    return s.size();
#else /* ? 0 */
    return s.len;
#endif /* 0 */
}

/** Returns the number of characters in the length of the C-style string representing the structure */
template <typename I>
inline
size_t
c_str_len(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_len_w(s);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_len_a(s);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace filters */
} /* namespace fastformat */

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

# ifdef FASTFORMAT_USE_WIDE_STRINGS
    using ::fastformat::filters::c_str_data_w;
    using ::fastformat::filters::c_str_len_w;
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    using ::fastformat::filters::c_str_data_a;
    using ::fastformat::filters::c_str_len_a;
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
    using ::fastformat::filters::c_str_data;
    using ::fastformat::filters::c_str_len;

# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#else /* ? !FASTFORMAT_NO_NAMESPACE */

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
template <typename I>
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
inline
wchar_t const*
c_str_data_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline
char const*
c_str_data_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#if 1
    return s.data();
#else /* ? 0 */
    return s.ptr;
#endif /* 0 */
}

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
template <typename I>
inline
ff_char_t const*
c_str_data(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_data_w(s);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_data_a(s);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/** Returns the number of characters in the length of the C-style string representing the structure */
template <typename I>
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
inline
size_t
c_str_len_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline
size_t
c_str_len_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#if 0
    return s.size();
#else /* ? 0 */
    return s.len;
#endif /* 0 */
}

/** Returns the number of characters in the length of the C-style string representing the structure */
template <typename I>
inline
size_t
c_str_len(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::filters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_fast_integers::integer_shim<I> const& s
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_len_w(s);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_len_a(s);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_HPP_FAST_INTEGERS */

/* ///////////////////////////// end of file //////////////////////////// */
