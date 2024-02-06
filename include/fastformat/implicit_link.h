/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/implicit_link.h (formerly fastformat/fastformat_implicit_link.h)
 *
 * Purpose:     Implicit linking for the FastFormat API
 *
 * Created:     30th January 2007
 * Updated:     21st March 2021
 *
 * Home:        http://fastformat.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
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


/** \file fastformat/implicit_link.h Implicit linking for the FastFormat API
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_IMPLICIT_LINK
#define FASTFORMAT_INCL_FASTFORMAT_H_IMPLICIT_LINK

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_H_IMPLICIT_LINK_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_H_IMPLICIT_LINK_MINOR    6
# define FASTFORMAT_VER_FASTFORMAT_H_IMPLICIT_LINK_REVISION 2
# define FASTFORMAT_VER_FASTFORMAT_H_IMPLICIT_LINK_EDIT     23
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
# include <fastformat/fastformat.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

#include <platformstl/platformstl.h>

/* /////////////////////////////////////////////////////////////////////////
 * implicit linking
 */

#if defined(_WIN32) || \
    defined(_WIN64)

# if defined(__BORLANDC__) || \
     /* defined(__DMC__) || */ \
     defined(__INTEL_COMPILER) || \
     defined(__MWERKS__) || \
     defined(_MSC_VER)
#  if !defined(__COMO__)
#   define FASTFORMAT_IMPLICIT_LINK_SUPPORT
#  endif /* compiler */
# endif /* compiler */

# if defined(FASTFORMAT_IMPLICIT_LINK_SUPPORT) && \
     defined(FASTFORMAT_NO_IMPLICIT_LINK)
#  undef FASTFORMAT_IMPLICIT_LINK_SUPPORT
# endif /* FASTFORMAT_IMPLICIT_LINK_SUPPORT && FASTFORMAT_NO_IMPLICIT_LINK */

# if defined(FASTFORMAT_IMPLICIT_LINK_SUPPORT)

  /* prefix */

#  define FASTFORMAT_IMPL_LINK_PREFIX

  /* library basename */

#  define FASTFORMAT_IMPL_LINK_LIBRARY_BASENAME         "fastformat"

  /* major version */

#  define FASTFORMAT_IMPL_LINK_MAJOR_VERSION            "." STLSOFT_STRINGIZE(FASTFORMAT_VER_MAJOR) 

  /* module name */

#  define FASTFORMAT_IMPL_LINK_MODULE_NAME              ".core"

  /* compiler tag */

#  if defined(__BORLANDC__)
#   if __BORLANDC__ == 0x0550
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc55"
#   elif (__BORLANDC__ == 0x0551)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc551"
#   elif (__BORLANDC__ == 0x0560)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc56"
#   elif (__BORLANDC__ == 0x0564)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc564"
#   elif (__BORLANDC__ == 0x0582)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc582"
#   elif (0x0590 == (__BORLANDC__ & 0xfff0))
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc59x"
#   elif (0x0610 == (__BORLANDC__ & 0xfff0))
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "bc61x"
#   else /* ? __BORLANDC__ */
#    error Unrecognised value of __BORLANDC__
#   endif /* __BORLANDC__ */

/*
#  elif defined(__DMC__)
#   define FASTFORMAT_IMPL_LINK_COMPILER_NAME           "dm"
 */

#  elif defined(__INTEL_COMPILER)
#   if __INTEL_COMPILER == 600
#    define   FASTFORMAT_IMPL_LINK_COMPILER_NAME        "icl6"
#   elif __INTEL_COMPILER == 700
#    define   FASTFORMAT_IMPL_LINK_COMPILER_NAME        "icl7"
#   elif __INTEL_COMPILER == 800
#    define   FASTFORMAT_IMPL_LINK_COMPILER_NAME        "icl8"
#   elif __INTEL_COMPILER == 900
#    define   FASTFORMAT_IMPL_LINK_COMPILER_NAME        "icl9"
#   elif __INTEL_COMPILER == 1000
#    define   FASTFORMAT_IMPL_LINK_COMPILER_NAME        "icl10"
#   elif __INTEL_COMPILER == 1100
#    define   FASTFORMAT_IMPL_LINK_COMPILER_NAME        "icl11"
#   else /* ? __INTEL_COMPILER */
#    error Intel C/C++ version not supported
#   endif /* __INTEL_COMPILER */

#  elif defined(__MWERKS__)
#   if ((__MWERKS__ & 0xFF00) == 0x2400)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "cw7"
#   elif ((__MWERKS__ & 0xFF00) == 0x3000)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "cw8"
#   elif ((__MWERKS__ & 0xFF00) == 0x3200)
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "cw9"
#   else /* ? __MWERKS__ */
#    error CodeWarrior version not supported
#   endif /* __MWERKS__ */

#  elif defined(_MSC_VER)
#   if _MSC_VER == 1000
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc4"
#   elif _MSC_VER == 1020
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc42"
#   elif _MSC_VER == 1100
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc5"
#   elif _MSC_VER == 1200
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc6"
#   elif _MSC_VER == 1300
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc7"
#   elif _MSC_VER == 1310
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc71"
#   elif _MSC_VER == 1400
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc8"
#   elif _MSC_VER == 1500
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc9"
#   elif _MSC_VER == 1600
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc10"
#   elif _MSC_VER == 1700
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc11"
#   elif _MSC_VER == 1800
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc12"
#   elif _MSC_VER == 1900
#    define FASTFORMAT_IMPL_LINK_COMPILER_NAME          "vc14"
#   elif _MSC_VER >= 1910
#    if 0
#    elif _MSC_VER < 1920
#     define FASTFORMAT_IMPL_LINK_COMPILER_NAME         "vc15"
#    elif _MSC_VER <= 1929
#     define FASTFORMAT_IMPL_LINK_COMPILER_NAME         "vc16"
#    else
#     error Visual C++ version that is >= vc16 is not recognised
#    endif
#   else /* ? _MSC_VER */
#    error Visual C++ version not supported
#   endif /* _MSC_VER */

#  else /* ? compiler */
#   error Unrecognised compiler
#  endif /* compiler */


  /* operating system tag */

#  if defined(_STLSOFT_FORCE_ANY_COMPILER) && \
      defined(PLATFORMSTL_OS_IS_UNIX) && \
      defined(_WIN32)
#   define FASTFORMAT_IMPL_LINK_OS_TAG                  ".unix"
#  endif /* pseudo UNIX */

#  if !defined(FASTFORMAT_IMPL_LINK_OS_TAG)
#   define FASTFORMAT_IMPL_LINK_OS_TAG                  ""
#  endif /* !FASTFORMAT_IMPL_LINK_OS_TAG */


  /* architecture tag */

#  if defined(PLATFORMSTL_ARCH_IS_X86)
#   define FASTFORMAT_IMPL_LINK_ARCH_TAG                ""
#  elif defined(PLATFORMSTL_ARCH_IS_X64)
#   define FASTFORMAT_IMPL_LINK_ARCH_TAG                ".x64"
#  elif defined(PLATFORMSTL_ARCH_IS_IA64)
#   define FASTFORMAT_IMPL_LINK_ARCH_TAG                ".ia64"
#  endif /* arch */

#  if !defined(FASTFORMAT_IMPL_LINK_ARCH_TAG)
#   define FASTFORMAT_IMPL_LINK_ARCH_TAG                ""
#  endif /* !FASTFORMAT_IMPL_LINK_ARCH_TAG */


  /* encoding tag */

#  if defined(FASTFORMAT_USE_WIDE_STRINGS)
#   define FASTFORMAT_IMPL_LINK_ENCODING_TAG            ".widestring"
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
#   define FASTFORMAT_IMPL_LINK_ENCODING_TAG            ""
#  endif /* FASTFORMAT_USE_WIDE_STRINGS */


  /* threading tag */

#  if defined(__MT__) || \
      defined(_REENTRANT) || \
      defined(_MT)
#   if defined(_DLL) || \
       defined(__DLL)
#    define FASTFORMAT_IMPL_LINK_THREADING_TAG          ".dll"
#   else /* ? dll */
#    define FASTFORMAT_IMPL_LINK_THREADING_TAG          ".mt"
#   endif /* dll */
#  else /* ? mt */
#    define FASTFORMAT_IMPL_LINK_THREADING_TAG          ""
#  endif /* mt */


  /* NoX */

#  if defined(FASTFORMAT_CF_NOX)
#   define FASTFORMAT_IMPL_LINK_NOX_TYPE                ".nox"
#  else /* ? FASTFORMAT_CF_NOX */
#   define FASTFORMAT_IMPL_LINK_NOX_TYPE                ""
#  endif /* FASTFORMAT_CF_NOX */


  /* debug tag */

#  if !defined(NDEBUG) && \
      defined(_DEBUG)
#   define FASTFORMAT_IMPL_LINK_DEBUG_TAG               ".debug"
#  else /* ? debug */
#   define FASTFORMAT_IMPL_LINK_DEBUG_TAG               ""
#  endif /* debug */


  /* suffix */

#  define FASTFORMAT_IMPL_LINK_SUFFIX                   ".lib"


   /* Library name is:
    *
    * [lib]<library-basename>.<major-version>.<module-name>.<compiler-name>[.<os-arch-tag>][.<char-encoding-tag>][.<threading-tag>][.<nox-tag>][.<debug-tag>].{a|lib}
    */

#  define FASTFORMAT_IMPL_LINK_LIBRARY_NAME             FASTFORMAT_IMPL_LINK_PREFIX \
                                                        FASTFORMAT_IMPL_LINK_LIBRARY_BASENAME \
                                                        FASTFORMAT_IMPL_LINK_MAJOR_VERSION \
                                                        FASTFORMAT_IMPL_LINK_MODULE_NAME \
                                                        "." FASTFORMAT_IMPL_LINK_COMPILER_NAME \
                                                        FASTFORMAT_IMPL_LINK_OS_TAG \
                                                        FASTFORMAT_IMPL_LINK_ARCH_TAG \
                                                        FASTFORMAT_IMPL_LINK_ENCODING_TAG \
                                                        FASTFORMAT_IMPL_LINK_THREADING_TAG \
                                                        FASTFORMAT_IMPL_LINK_NOX_TYPE \
                                                        FASTFORMAT_IMPL_LINK_DEBUG_TAG \
                                                        FASTFORMAT_IMPL_LINK_SUFFIX
                                                        

#  pragma message("lib: " FASTFORMAT_IMPL_LINK_LIBRARY_NAME)

#  pragma comment(lib, FASTFORMAT_IMPL_LINK_LIBRARY_NAME)

# endif /* FASTFORMAT_IMPLICIT_LINK_SUPPORT */

#endif /* Win-32 || Win-64 */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_IMPLICIT_LINK */

/* ///////////////////////////// end of file //////////////////////////// */
