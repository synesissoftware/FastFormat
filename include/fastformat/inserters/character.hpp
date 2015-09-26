/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/character.hpp
 *
 * Purpose:     Inserter functions for character types.
 *
 * Created:     25th November 2010
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2010-2013, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/** \file fastformat/inserters/character.hpp
 *
 * [C++ only] Inserter functions for character types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_CHARACTER
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_CHARACTER

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_CHARACTER_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_CHARACTER_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_CHARACTER_REVISION 1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_CHARACTER_EDIT     5
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>

// TODO: implement in terms of stlsoft::string_slice, when STLSoft 1.10 released
//#include <stlsoft/string/string_slice.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace inserters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_character
{
    class character_state
    {
    public:
        typedef ff_char_t       char_type;
        typedef character_state class_type;

    public:
        explicit character_state(char_type ch)
        {
            m_chars[0] = ch;
            m_chars[1] = '\0';
        }

    public:
        char_type const* data() const
        {
            return m_chars;
        }
        size_t length() const
        {
            return 1u;
        }

    private:
        ff_char_t   m_chars[2];
    };

}/* namespace ximpl_character */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Inserter functions
 */

/** Inserts the string form of a character value.
 *
 * \ingroup group__inserters
 *
 * \param value The character value to be inserted.
 */
inline ximpl_character::character_state character(
    ff_char_t const& value
)
{
    return ximpl_character::character_state(value);
}

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

/** Returns a nul-terminated non-NULL C-style string representing the structure */
#ifdef FASTFORMAT_USE_WIDE_STRINGS
inline wchar_t const* c_str_ptr_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline char const* c_str_ptr_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
    return s.data();
}

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
#ifdef FASTFORMAT_USE_WIDE_STRINGS
inline wchar_t const* c_str_data_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline char const* c_str_data_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
    return s.data();
}

/** Returns the number of characters in the length of the C-style string representing the structure */
#ifdef FASTFORMAT_USE_WIDE_STRINGS
inline size_t c_str_len_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline size_t c_str_len_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
    return s.length();
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::character;
} // namespace fastformat

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

# ifdef FASTFORMAT_USE_WIDE_STRINGS
    using ::fastformat::inserters::c_str_ptr_w;
    using ::fastformat::inserters::c_str_data_w;
    using ::fastformat::inserters::c_str_len_w;
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    using ::fastformat::inserters::c_str_ptr_a;
    using ::fastformat::inserters::c_str_data_a;
    using ::fastformat::inserters::c_str_len_a;
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
//    using ::fastformat::inserters::c_str_ptr;
//    using ::fastformat::inserters::c_str_data;
//    using ::fastformat::inserters::c_str_len;

# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#else /* ? !FASTFORMAT_NO_NAMESPACE */

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
inline wchar_t const* c_str_data_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline char const* c_str_data_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
    return s.data();
}

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the structure */
inline ff_char_t const* c_str_data(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_data_w(s);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_data_a(s);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/** Returns a nul-terminated non-NULL C-style string representing the structure */
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
inline wchar_t const* c_str_ptr_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline char const* c_str_ptr_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
    return s.data();
}

/** Returns a nul-terminated non-NULL C-style string representing the structure */
inline ff_char_t const* c_str_ptr(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_ptr_w(s);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_ptr_a(s);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/** Returns the number of characters in the length of the C-style string representing the structure */
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
inline size_t c_str_len_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
inline size_t c_str_len_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
)
{
    return s.size();
}

/** Returns the number of characters in the length of the C-style string representing the structure */
inline size_t c_str_len(
#if !defined(FASTFORMAT_NO_NAMESPACE)
    ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        ximpl_character::character_state const& s
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
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_CHARACTER */

/* ///////////////////////////// end of file //////////////////////////// */
