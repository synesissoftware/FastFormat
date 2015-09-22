/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/fastformat.hpp
 *
 * Purpose:     FastFormat C++ primary include.
 *
 * Created:     19th September 2006
 * Updated:     17th June 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2012, Matthew Wilson and Synesis Software
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


/** \file fastformat/fastformat.hpp
 *
 * [C++ only] FastFormat C++ primary include.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_HPP_FASTFORMAT
#define FASTFORMAT_INCL_FASTFORMAT_HPP_FASTFORMAT

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_HPP_FASTFORMAT_MAJOR     2
# define FASTFORMAT_VER_FASTFORMAT_HPP_FASTFORMAT_MINOR     4
# define FASTFORMAT_VER_FASTFORMAT_HPP_FASTFORMAT_REVISION  2
# define FASTFORMAT_VER_FASTFORMAT_HPP_FASTFORMAT_EDIT      46
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

#include <fastformat/fastformat.h>
#include <fastformat/exceptions.hpp>
#include <fastformat/format/standard_flags.hpp>
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
# include <fastformat/internal/format_element.h>
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */
#include <fastformat/internal/stlsoft.h>
#include <fastformat/quality/contract.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

/* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
 *
 * Some compilers can't handle the filter_type mechanism, so we must allow
 * for it to be disabled
 */

#if (   defined(STLSOFT_COMPILER_IS_BORLAND) && \
        __BORLANDC__ < 0x0600) /* This is a guess, since I cannot verify whether 5.9.x supports filter_type; 5.8 does not, 6.1 does */ || \
    defined(STLSOFT_COMPILER_IS_DMC) || \
    defined(STLSOFT_COMPILER_IS_WATCOM)
# define FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
#endif /* compiler */

/* FASTFORMAT_SUPPORT_IMPLICIT_SHIM_STRING_ACTION_SHIM
 *
 * Determines whether support for using a shim string as a sink is
 * available
 */

#ifndef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
# if defined(STLSOFT_COMPILER_IS_MWERKS) || \
     (  defined(STLSOFT_COMPILER_IS_GCC) && \
        (   __GNUC__ >= 4 || \
            (   __GNUC__ == 3 && \
                __GNUC_MINOR__ >= 4))) || \
    (   defined(STLSOFT_COMPILER_IS_MSVC) && \
        _MSC_VER >= 1310)
  /* allow shim string action shim for these compilers ...
   *
   * ... unless STLSoft main line is not 1.10 and 1.10 alpha is not
   * present
   */
#  include <stlsoft/string/shim_string.hpp>
#  if _STLSOFT_VER >= 0x010a0000 || \
      (   defined(_STLSOFT_1_10_VER) && \
          _STLSOFT_1_10_VER >= 0x010a0105)
#   define FASTFORMAT_SUPPORT_IMPLICIT_SHIM_STRING_ACTION_SHIM
#  else /* ? shim string version */
#   ifndef FASTFORMAT_NO_VERSION_NAG
#    ifdef STLSOFT_PPF_pragma_message_SUPPORT
#     pragma message(__FILE__ "(" STLSOFT_STRINGIZE(__LINE__) "): " "NOTE: Implicit support for shim_string sinks is not enabled. To enable this, download STLSoft 1.10 alpha 5+ and add -I$STLSOFT_1_10/include to your command-line/project include directories _before_ -$STLSOFT/include; to suppress this message, #define FASTFORMAT_NO_VERSION_NAG")
#    endif /* STLSOFT_PPF_pragma_message_SUPPORT */
#   endif /* !FASTFORMAT_NO_VERSION_NAG */
#  endif /* shim string version */
# endif /* compiler */
#endif /* !FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string.hpp>
#ifdef FASTFORMAT_SUPPORT_IMPLICIT_SHIM_STRING_ACTION_SHIM
# include <stlsoft/string/shim_string.hpp>
#endif /* FASTFORMAT_SUPPORT_IMPLICIT_SHIM_STRING_ACTION_SHIM */
#include <stlsoft/string/string_traits.hpp>
#include <stlsoft/string/string_view.hpp>

 /* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

/** Closed namespace for definition of private, but publicly-visible, types
 */
struct defs
{
#ifdef FASTFORMAT_NO_USE_JIT_CACHE
    typedef stlsoft::auto_buffer<ff_format_element_t>   format_elements_t;
#endif /* FASTFORMAT_NO_USE_JIT_CACHE */
    typedef stlsoft::auto_buffer<ff_string_slice_t>     slices_buffer_t;
};

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Creator functions
 */

/** [PROVISIONAL] Degenerate conversion shim for specifying a sink.
 *
 *
 * \note This function is provisional, and may be subject to change in any
 *   pre-1.0 release.
 */
template <typename T>
inline
T&
to_sink(T& sink)
{
    return sink;
}

/* /////////////////////////////////////////////////////////////////////////
 * Stock sinks
 *
 * This section includes all the implicit action shims that are available
 * for sinks, without the need to explicitly include sinks files (e.g.
 * fastformat/sinks/ostream.hpp)
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

#if !defined(FASTFORMAT_NO_IMPLICIT_ACTION_SHIMS)

 /* Default sinks:
  *
  * - "generic string", aka anything that is structurally conformant with std::basic_string<ff_char_t>
  * - STLSoft's shim string
  */

# if !defined(FASTFORMAT_NO_IMPLICIT_GENERIC_STRING_ACTION_SHIM)
#  include <fastformat/shims/action/fmt_slices/generic_string.hpp>
# endif /* !FASTFORMAT_NO_IMPLICIT_GENERIC_STRING_ACTION_SHIM */

# if !defined(FASTFORMAT_NO_IMPLICIT_SHIM_STRING_ACTION_SHIM)
#  if defined(FASTFORMAT_SUPPORT_IMPLICIT_SHIM_STRING_ACTION_SHIM)
#   include <fastformat/sinks/shim_string.hpp>
#  endif /* FASTFORMAT_SUPPORT_IMPLICIT_SHIM_STRING_ACTION_SHIM */
# endif /* !FASTFORMAT_NO_IMPLICIT_SHIM_STRING_ACTION_SHIM */

# ifndef FASTFORMAT_LEAN_AND_MEAN

 /* Other common sinks
  *
  * - std::basic_ostream<ff_char_t>  (supported as of version 0.6.4)
  */

#  if !defined(FASTFORMAT_NO_IMPLICIT_OSTREAM_ACTION_SHIM)
#   ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OSTREAM
#    include <fastformat/sinks/ostream.hpp>
#   endif /* !FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_OSTREAM */
#  endif /* !FASTFORMAT_NO_IMPLICIT_OSTREAM_ACTION_SHIM */

# endif /* !FASTFORMAT_LEAN_AND_MEAN */

#endif /* !FASTFORMAT_NO_IMPLICIT_ACTION_SHIMS */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Conversion shims for implicit filtering
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace filters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/// Degenerate case, which does no conversion.
template<   typename T /* The type to be converted */
        ,   typename C /* The character type */
        >
inline T const& filter_type(T const& t, T const*, C const volatile*)
{
    return t;
}

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace filters */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Stock filtering
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

#if !defined(FASTFORMAT_NO_DEFAULT_CONVERSION_SHIMS)

  /* By default uses the fast non-l7d conversions. Can request l7d ones
   * by FASTFORMAT_USE_L7D_INTEGER_CONVERSION_SHIMS.
   */
# if defined(FASTFORMAT_USE_L7D_INTEGER_CONVERSION_SHIMS)
#  error Feature not yet implemented. Please register your interest via http://sourceforge.net/projects/fastformat/forums/forum/612781 and your wish might be granted
/* #  include <fastformat/shims/conversion/filter_type/l7d_integers.hpp> */
# elif !defined(FASTFORMAT_NO_DEFAULT_INTEGER_CONVERSION_SHIMS)
#  include <fastformat/shims/conversion/filter_type/fast_integers.hpp>
# endif /* !FASTFORMAT_NO_DEFAULT_INTEGER_CONVERSION_SHIMS */

# if defined(FASTFORMAT_USE_L7D_REAL_CONVERSION_SHIMS)
#  error Feature not yet implemented. Please register your interest via http://sourceforge.net/projects/fastformat/forums/forum/612781 and your wish might be granted
/* #  include <fastformat/shims/conversion/filter_type/l7d_reals.hpp> */
# endif /* FASTFORMAT_USE_L7D_REAL_CONVERSION_SHIMS */

# if defined(FASTFORMAT_USE_VOID_POINTERS_CONVERSION_SHIMS)
#  include <fastformat/shims/conversion/filter_type/void_pointers.hpp>
# endif /* FASTFORMAT_USE_VOID_POINTERS_CONVERSION_SHIMS */

# if defined(FASTFORMAT_USE_CHAR_CONVERSION_SHIMS)
#  error Feature not yet implemented. Please register your interest via http://sourceforge.net/projects/fastformat/forums/forum/612781 and your wish might be granted
/* #  include <fastformat/shims/conversion/filter_type/characters.hpp> */
# endif /* FASTFORMAT_USE_CHAR_CONVERSION_SHIMS */

# if defined(FASTFORMAT_USE_BOOLEAN_CONVERSION_SHIMS)
#  error Feature not yet implemented. Please register your interest via http://sourceforge.net/projects/fastformat/forums/forum/612781 and your wish might be granted
/* #  include <fastformat/shims/conversion/filter_type/boolean.hpp> */
# endif /* FASTFORMAT_USE_BOOLEAN_CONVERSION_SHIMS */

#endif /* !FASTFORMAT_NO_DEFAULT_CONVERSION_SHIMS */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace internal
{
namespace helpers
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_INCLUDING_HELPER_FUNCTIONS
# include <fastformat/internal/generated/helper_functions.hpp>
# undef FASTFORMAT_INCLUDING_HELPER_FUNCTIONS
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace helpers */
} /* namespace internal */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

/** \defgroup group__interface_functions Interface Functions
 *
 * \ingroup group__application_layer
 *
 * 
 */

/** \defgroup group__interface_functions__api_format Format API Interface Functions
 *
 * \ingroup group__interface_functions
 *
 * The <b>Format API</b> consists of two suites of
 * <a href="http://www.breakingupthemonolith.com/glossary.html#type-tunnel">N-ary Generated Function Templates</a>
 * whose names are <code>fmt()</code> and <code>fmtln()</code>. By default
 * the suites each contain 32 overloads, of between 1 and 32 arguments, of
 * the form:
 *
 * <code>fastformat::&lt;func>(&lt;sink>, &lt;format>, &lt;args>)</code>
 *
 * where:
 *
 * - &lt;func> is either <code>fmt</code> or <code>fmtln</code>
 * - &lt;sink> is a sink instance that will receive the result of the
 *   statement
 * - &lt;format> is a format string
 * - &lt;args> is a sequence of between 1 and 32 arguments
 *
 * as in the examples:
<pre>
  std::string   sink;
  char const*   arg0   = "abc";
  char          arg1[] = "def";
  std::string   arg2   = "ghi";

  // Write the three arguments to the string sink
  fastformat::fmt(sink, "{0} {1} {2}", arg0, arg1, arg2);

  // Write the three arguments in reverse order to stdout and
  // append a new line
  fastformat::fmtln(std::cout, "{2} {1} {0}", arg0, arg1, arg2);
</pre>
 */

/** \defgroup group__interface_functions__api_write Write API Interface Functions
 *
 * \ingroup group__interface_functions
 *
 * The <b>Write API</b> consists of two suites of
 * <a href="http://www.breakingupthemonolith.com/glossary.html#type-tunnel">N-ary Generated Function Templates</a>
 * whose names are <code>write()</code> and <code>writeln()</code>. By default
 * the suites each contain 32 overloads, of between 1 and 32 arguments, of
 * the form:
 *
 * <code>fastformat::&lt;func>(&lt;sink>, &lt;args>)</code>
 *
 * where:
 *
 * - &lt;func> is either <code>write</code> or <code>writeln</code>
 * - &lt;sink> is a sink instance that will receive the result of the
 *   statement
 * - &lt;args> is a sequence of between 1 and 32 arguments
 *
 * as in the examples:
<pre>
  std::string   sink;
  char const*   arg0   = "abc";
  char          arg1[] = "def";
  std::string   arg2   = "ghi";

  // Write the three arguments to the string sink
  fastformat::write(sink, arg0, " ", arg1, " ", arg2);

  // Write the three arguments in reverse order to stdout and
  // append a new line
  fastformat::writeln(std::cout, " ", arg2, " ", arg1, " ", arg0);
</pre>
 */

#ifdef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# include "./internal/generated/api_functions.hpp"
#else /* ? FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
# define FASTFORMAT_INCLUDING_API_FUNCTIONS
# include <fastformat/internal/generated/api_functions.hpp>
# undef FASTFORMAT_INCLUDING_API_FUNCTIONS
#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/** Flushes the given sink, by formatting an empty statement with the
 * flag fastformat::flags::ff_flush.
 *
 * \ingroup group__interface_functions
 */

template <typename S>
inline S& flush(
    S& sink
)
{
    FASTFORMAT_DECLARE_fmt_slices_();

    return FASTFORMAT_INVOKE_fmt_slices_(sink, flags::ff_flush, 0, 0, NULL);
}

/* /////////////////////////////////////////////////////////////////////////
 * Auto-initialisation
 *
 * Except when making a DLL, this is automatic, unless FASTFORMAT_NO_AUTO_INIT
 * is defined.
 *
 * To force it for a DLL, define FASTFORMAT_FORCE_AUTO_INIT
 */

#if defined(__DLL__) /* Borland, with -WD */ || \
    defined(_WINDLL) /* VC++, defined by user/wizard */ || \
    defined(_USRDLL) /* VC++, defined by user/wizard */
# define FASTFORMAT_NO_AUTO_INIT
#endif /* dynamic library */

#ifdef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# include "./internal/initialiser.hpp"
#else /* ? FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
# if defined(FASTFORMAT_FORCE_AUTO_INIT) || \
     !defined(FASTFORMAT_NO_AUTO_INIT)
#  include <fastformat/internal/initialiser.hpp> /* Schwarz counter initialisation */
# endif /* FASTFORMAT_FORCE_AUTO_INIT || !FASTFORMAT_NO_AUTO_INIT */
#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Application-layer includes - 2
 */

#ifndef FASTFORMAT_LEAN_AND_MEAN



#endif /* !FASTFORMAT_LEAN_AND_MEAN */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_HPP_FASTFORMAT */

/* ///////////////////////////// end of file //////////////////////////// */
