/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/shim_macros.h
 *
 * Purpose:     Definitions of macros used internally in the library
 *              components
 *
 * Created:     19th September 2006
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/internal/shim_macros.h
 *
 * [C, C++] Definitions of macros used internally in the library components
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_SHIM_MACROS
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_SHIM_MACROS

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# include <fastformat/fastformat.h>
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

/* /////////////////////////////////////////////////////////////////////////
 * Compiler compatibility
 */

/* The Digital Mars and GCC compilers both exhibit strange behaviour (bugs?)
 * with respect to the invocation of shims.
 *
 * - DMC++ requires explicit qualification, even in the presence of a
 *    (local) using declaration
 * - GCC requires a local using declaration and *must not* have explicit
 *    qualification.
 *
 * - all other compilers work fine without any using declaration and with
 *    explicit qualification.
 *
 * As currently defined, we follow the GCC way (which works for all other
 * compilers, except DMC++), and explicitly qualify for DMC++.
 *
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

/* 1. String access shims
 * ----------------------
 */

# ifdef FASTFORMAT_INVOKE_c_str_data_
#  undef FASTFORMAT_INVOKE_c_str_data_
# endif /* FASTFORMAT_INVOKE_c_str_data_ */
# ifdef FASTFORMAT_INVOKE_c_str_len_
#  undef FASTFORMAT_INVOKE_c_str_len_
# endif /* FASTFORMAT_INVOKE_c_str_len_ */
# ifdef FASTFORMAT_INVOKE_c_str_ptr_
#  undef FASTFORMAT_INVOKE_c_str_ptr_
# endif /* FASTFORMAT_INVOKE_c_str_ptr_ */
# ifdef FASTFORMAT_INVOKE_SHIM_PAIR_
#  undef FASTFORMAT_INVOKE_SHIM_PAIR_
# endif /* FASTFORMAT_INVOKE_SHIM_PAIR_ */
# ifdef FASTFORMAT_c_str_data_name_
#  undef FASTFORMAT_c_str_data_name_
# endif /* FASTFORMAT_c_str_data_name_ */

# ifdef FASTFORMAT_USE_WIDE_STRINGS
#  define FASTFORMAT_c_str_data_name_                   c_str_data_w
#  define FASTFORMAT_c_str_len_name_                    c_str_len_w
#  define FASTFORMAT_c_str_ptr_name_                    c_str_ptr_w
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
#  define FASTFORMAT_c_str_data_name_                   c_str_data_a
#  define FASTFORMAT_c_str_len_name_                    c_str_len_a
#  define FASTFORMAT_c_str_ptr_name_                    c_str_ptr_a
# endif /* FASTFORMAT_USE_WIDE_STRINGS */

# if defined(STLSOFT_COMPILER_IS_DMC)
#  define FASTFORMAT_INVOKE_c_str_data_(x)              stlsoft::FASTFORMAT_c_str_data_name_(x)
#  define FASTFORMAT_INVOKE_c_str_len_(x)               stlsoft::FASTFORMAT_c_str_len_name_(x)
#  define FASTFORMAT_INVOKE_c_str_ptr_(x)               stlsoft::FASTFORMAT_c_str_ptr_name_(x)
#  define FASTFORMAT_DECLARE_c_str_ptr_()               stlsoft_static_cast(void, 0)
#  define FASTFORMAT_DECLARE_c_str_datalen_PAIR_()      stlsoft_static_cast(void, 0)
# elif defined(STLSOFT_COMPILER_IS_GCC)
#  define FASTFORMAT_INVOKE_c_str_data_(x)              FASTFORMAT_c_str_data_name_(x)
#  define FASTFORMAT_INVOKE_c_str_len_(x)               FASTFORMAT_c_str_len_name_(x)
#  define FASTFORMAT_INVOKE_c_str_ptr_(x)               FASTFORMAT_c_str_ptr_name_(x)
#  define FASTFORMAT_DECLARE_c_str_ptr_()               using ::stlsoft::FASTFORMAT_c_str_ptr_name_
#  define FASTFORMAT_DECLARE_c_str_datalen_PAIR_()      using ::stlsoft::FASTFORMAT_c_str_data_name_; using ::stlsoft::FASTFORMAT_c_str_len_name_
# else /* ? compiler */
#  define FASTFORMAT_INVOKE_c_str_data_(x)              FASTFORMAT_c_str_data_name_(x)
#  define FASTFORMAT_INVOKE_c_str_len_(x)               FASTFORMAT_c_str_len_name_(x)
#  define FASTFORMAT_INVOKE_c_str_ptr_(x)               FASTFORMAT_c_str_ptr_name_(x)
#  define FASTFORMAT_DECLARE_c_str_ptr_()               using ::stlsoft::FASTFORMAT_c_str_ptr_name_
#  define FASTFORMAT_DECLARE_c_str_datalen_PAIR_()      using ::stlsoft::FASTFORMAT_c_str_data_name_; using ::stlsoft::FASTFORMAT_c_str_len_name_
# endif /* compiler */
# define FASTFORMAT_INVOKE_SHIM_PAIR_(x)                FASTFORMAT_INVOKE_c_str_data_(x), FASTFORMAT_INVOKE_c_str_len_(x)


/* 2. Conversion shims
 * -------------------
 */

# ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
#  define FASTFORMAT_DECLARE_filter_type_()             stlsoft_static_cast(void, 0)
#  define FASTFORMAT_INVOKE_filter_type_(x, y, z)       (x)
# else /* ? FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */
#  ifdef FASTFORMAT_NO_NAMESPACE
#   define FASTFORMAT_DECLARE_filter_type_()            stlsoft_static_cast(void, 0)
#  else /* ? FASTFORMAT_NO_NAMESPACE */
#   define FASTFORMAT_DECLARE_filter_type_()            using ::fastformat::filters::filter_type
#  endif /* FASTFORMAT_NO_NAMESPACE */
#  define FASTFORMAT_INVOKE_filter_type_(x, y, z)       filter_type(x, y, z)
# endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */


/* 3. Action shims
 * ---------------
 */

# if defined(FASTFORMAT_NO_NAMESPACE)
#  define FASTFORMAT_DECLARE_fmt_slices_()
#  define FASTFORMAT_INVOKE_fmt_slices_(s, f, t, e, r)  fmt_slices(s, f, t, e, r)
# else /* FASTFORMAT_NO_NAMESPACE */
#  if defined(STLSOFT_COMPILER_IS_DMC)
#   define FASTFORMAT_DECLARE_fmt_slices_()             stlsoft_static_cast(void, 0)
#   define FASTFORMAT_INVOKE_fmt_slices_(s, f, t, e, r) ::fastformat::sinks::fmt_slices(s, f, t, e, r)
#  elif defined(STLSOFT_COMPILER_IS_GCC)
#   define FASTFORMAT_DECLARE_fmt_slices_()             using ::fastformat::sinks::fmt_slices
#   define FASTFORMAT_INVOKE_fmt_slices_(s, f, t, e, r) fmt_slices(s, f, t, e, r)
#  else /* ? compiler */
#   define FASTFORMAT_DECLARE_fmt_slices_()             using ::fastformat::sinks::fmt_slices
#   define FASTFORMAT_INVOKE_fmt_slices_(s, f, t, e, r) fmt_slices(s, f, t, e, r)
#  endif /* compiler */

# endif /* FASTFORMAT_NO_NAMESPACE */


/* 4. Internal helpers
 * -------------------
 */

# if !defined(FASTFORMAT_NO_NAMESPACE)
#  define FASTFORMAT_QUALIFY_HELPER_(x)                 ::fastformat::internal::helpers::x
# else /* !FASTFORMAT_NO_NAMESPACE */
#  define FASTFORMAT_QUALIFY_HELPER_(x)                 x
# endif /* !FASTFORMAT_NO_NAMESPACE */

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_SHIM_MACROS */

/* ///////////////////////////// end of file //////////////////////////// */
