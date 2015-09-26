/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/util/memory/auto_buffer_selector.hpp
 *
 * Purpose:     Type generator template for defining stlsoft::auto_buffer
 *              specialisations.
 *
 * Created:     22nd April 2008
 * Updated:     18th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/util/memory/auto_buffer_selector.hpp
 *
 * [C++ only] A <a href = "http://extendedstl.com/glossary.html#type-generator-template">Type Generator</a>
 *  for defining <code>stlsoft::auto_buffer</code>
 *  specialisations.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR
#define FASTFORMAT_INCL_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR_MAJOR     2
# define FASTFORMAT_VER_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR_EDIT      16
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
# include <fastformat/fastformat.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT
# include <fastformat/internal/stlsoft.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
# define FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED
#endif /* compiler */

#ifndef FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED
# ifdef FASTFORMAT_STLSOFT_1_12_OR_LATER
#  ifndef STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR
#   include <stlsoft/memory/util/allocator_selector.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_MEMORY_UTIL_HPP_ALLOCATOR_SELECTOR */
# else /* ? STLSoft 1.12+ */
#  ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR
#   include <stlsoft/memory/allocator_selector.hpp>
#  endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_ALLOCATOR_SELECTOR */
# endif /* STLSoft 1.12+ */
#endif /* !FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED */
#ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER
# include <stlsoft/memory/auto_buffer.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_AUTO_BUFFER */
#ifdef FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED
# ifndef STLSOFT_INCL_STLSOFT_MEMORY_HPP_MALLOC_ALLOCATOR
#  include <stlsoft/memory/malloc_allocator.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_MEMORY_HPP_MALLOC_ALLOCATOR */
#endif /* FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace util
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** A <a href = "http://extendedstl.com/glossary.html#type-generator-template">Type Generator</a>
 *   that deduces the appropriate specialisation of
 *   <code>stlsoft::auto_buffer</code>.
 *
 * \ingroup group__utility
 *
 * There are two reasons for this:
 * - Some (older) compilers have to use the old (pre-1.9) form of 
 *   <code>stlsoft::auto_buffer</code>. Using 
 *   fastformat::auto_buffer_selector makes FastFormat code independent of
 *   such compilers' behavioural odities.
 * - Visual C++ 8 & 9 both have  bug that causes them to exhibit a linker
 *   error (LNK2005) whereby std::allocator<>::allocate() and
 *   std::allocator<>::deallocate() are multiply defined. In that case, we
 *   always select stlsoft::malloc_allocator as the allocator, as this will
 *   still hook into the VC++ memory tracing debug API.
 */
template<   typename    T
        ,   size_t      N
#ifdef FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED
        ,   typename    A = stlsoft::malloc_allocator<T>
#else /* ? FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED */
        ,   typename    A = ss_typename_type_def_k stlsoft::allocator_selector<T>::allocator_type
#endif /* FASTFORMAT_COMPILER_CF_STD_ALLOCATOR_SYMBOLS_MULTIPLY_DEFINED */
        >
struct auto_buffer_selector
{
    /** The generated type */
#ifdef STLSOFT_AUTO_BUFFER_NEW_FORM
    typedef stlsoft::auto_buffer<T, N, A>           type;
#else /* ? STLSOFT_AUTO_BUFFER_NEW_FORM */
    typedef stlsoft::auto_buffer<T, A, N>           type;
#endif /* STLSOFT_AUTO_BUFFER_NEW_FORM */
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace util */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_UTIL_MEMORY_HPP_AUTO_BUFFER_SELECTOR */

/* ///////////////////////////// end of file //////////////////////////// */
