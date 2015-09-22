/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/initialiser.hpp (derived from Pantheios)
 *
 * Purpose:     Automatic initialisation of FastFormat library
 *
 * Created:     21st June 2005
 * Updated:     29th March 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2005-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/internal/initialiser.hpp
 *
 * [C, C++] INTERNAL FILE: Do not include directly. Provides
 *   automatic initialisation of FastFormat library.
 *
 * This file declares an instance of the fastformat::fastformat_initialiser
 * class in each compilation unit in which it is included.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_HPP_INITIALISER
#define FASTFORMAT_INCL_FASTFORMAT_HPP_INITIALISER

/* /////////////////////////////////////////////////////////////////////////
 * Feature discrimination
 */

/* Which diagnostic output to use if initialisation fails */
#if defined(PANTHEIOS_INCL_PANTHEIOS_H_PANTHEIOS)
# define FASTFORMAT_INIT_FAILURE_REPORT_VIA_PANTHEIOS
#elif defined(WIN32) && \
      !defined(_CONSOLE)
# define FASTFORMAT_INIT_FAILURE_REPORT_VIA_WINDOWS_LOGGING
#else /* ? Pantheios || Windows GUI || stderr */
# define FASTFORMAT_INIT_FAILURE_REPORT_VIA_STDERR
#endif /* Pantheios || Windows GUI || stderr */

/* Whether the compiler supports Windows' Structure Exception Handling */
#if defined(STLSOFT_CF_SUPPORTS_SEH)
# define FASTFORMAT_INIT_FAILURE_USE_SEH
#else
# if defined(STLSOFT_COMPILER_IS_MSVC) || \
     (  defined(STLSOFT_COMPILER_IS_INTEL) && \
        defined(PLATFORMSTL_OS_IS_WINDOWS))
#  define FASTFORMAT_INIT_FAILURE_USE_SEH
# endif /* compiler / OS */
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_HPP_FASTFORMAT
# error This file can only be included from within fastformat/fastformat.hpp
#endif /* !FASTFORMAT_INCL_FASTFORMAT_HPP_FASTFORMAT */


#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_PANTHEIOS
 // Nothing to include
#endif
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_WINDOWS_LOGGING
 // fastformat_util_snprintf
# include <fastformat/util/string/snprintf.h>
 // Include Windows header
# include <windows.h>
#endif
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_STDERR
 // Include Streams header
# include <stdio.h>
#endif
#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/**  Schwarz Counter initialiser for the FastFormat library
 *
 * In "normal" use, this file is included by fastformat/fastformat.hpp, so
 * that every C++ compilation unit that may potentially be issuing
 * FastFormat calls contains, at file scope (well, actually in an
 * anonymous namespace that is itself at file scoope) an instance of the
 * initialiser. Since the FastFormat core is a reference-counted API
 * (see Chapter 11 of
 * <a href = "http://imperfectcplusplus.com" target="_blank">Imperfect C++</a>),
 * this means that the first C++ compilation linked in initialises the
 * core, and the remainder keep it initialised, until they are all
 * "completed". In other words, just including fastformat/fastformat.hpp
 * causes FastFormat to be initialised.
 *
 * In non-"normal" cases, the inclusion is not made, and the initialisation
 * is not performed. These cases are either when:
 *  - The link-unit being built is a dynamic library (as discriminated by
 *     the presence of the processor symbol <code>_USRDLL</code> or
 *     <code>_WINDLL</code>, and the preprocessor symbol
 *     <code>FASTFORMAT_FORCE_AUTO_INIT</code> is <b>not</b> defined), or
 *  - The preprocessor symbol <code>FASTFORMAT_NO_AUTO_INIT</code> <b>is</b>
 *     defined.
 *
 * In either of these cases, you <b>must</b> explicitly initialise the
 * FastFormat core (which initialises the front-end and back-end(s))
 * explicitly, using
 * \link fastformat::fastformat_init fastformat_init()\endlink
 * and
 * \link fastformat::fastformat_uninit fastformat_uninit()\endlink.
 */
class fastformat_initialiser
{
/// \name Member Types
/// @{
public:
    typedef fastformat_initialiser   class_type;
/// @}

/// \name Construction
/// @{
public:
    ///  Initialises the FastFormat library
    ///
    /// Calls fastformat::fastformat_init(), calling exit(1) on failure
    fastformat_initialiser()
    {
        int r = fastformat_init();

        if(r < 0)
        {
            // TODO: use SEH to place exitProcess in finally
#ifdef FASTFORMAT_INIT_FAILURE_USE_SEH
            __try
#endif // FASTFORMAT_INIT_FAILURE_USE_SEH
            {
                record_init_failure_(r);
            }
#ifdef FASTFORMAT_INIT_FAILURE_USE_SEH
            __finally
#endif // FASTFORMAT_INIT_FAILURE_USE_SEH
            {
                fastformat_exitProcess(1);
            }
        }
    }
    ///  Uninitialises the FastFormat library
    ///
    /// Calls fastformat::fastformat_uninit()
    ~fastformat_initialiser()
    {
        fastformat_uninit();
    }
/// @}

/// \name Implementation
/// @{
private:
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_WINDOWS_LOGGING
    static void record_init_failure_Windows_GUI_(ff_char_t const* message)
    {
        // to debug stream
        ::OutputDebugString(message);

        // to event log
        //
        // NOTE: to have this displayed properly in the Windows Event Log,
        // users should download and install Pantheios.COM
        HANDLE h = ::RegisterEventSource(NULL, FASTFORMAT_LITERAL_STRING("logging-bailout"));
        if(NULL != h)
        {
            LPCTSTR strings[2] = { FASTFORMAT_LITERAL_STRING("process"), message };
            ::ReportEvent(h, EVENTLOG_ERROR_TYPE, 0, 1001, 0, 2, 0, strings, 0);
            ::DeregisterEventSource(h);
        }        
    }
#endif // FASTFORMAT_INIT_FAILURE_REPORT_VIA_WINDOWS_LOGGING
    static void record_init_failure_(int r)
    {
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_PANTHEIOS
        {
# ifndef PANTHEIOS_NO_NAMESPACE
            using pantheios::pantheios_logprintf;
# endif /* !PANTHEIOS_NO_NAMESPACE */

            // Record initialisation failure to Pantheios logging API
            //
            // Assumes that FastFormat and Pantheios both use multi-byte
            // string build, or both use wide-string build
            pantheios_logprintf(PANTHEIOS_SEV_ALERT, PANTHEIOS_LITERAL_STRING("could not initialise the FastFormat library: %s"), fastformat_getInitCodeString(r));
        }
#endif
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_WINDOWS_LOGGING
        {
            // Record initialisation failure to Windows debugger
            //
            // Assumes that FastFormat and Windows API both use multi-byte
            // string build, or both use wide-string build
            ff_char_t   message[1024];
            int const   n = fastformat_util_snprintf(&message[0], (sizeof(message) / sizeof(message[0])) - 1, FASTFORMAT_LITERAL_STRING("could not initialise the FastFormat library: %s"), fastformat_getInitCodeString(r));

            if(n < 0)
            {
                record_init_failure_Windows_GUI_(FASTFORMAT_LITERAL_STRING("could not initialise the FastFormat library: cause not indicated"));
            }
            else
            {
                message[n + 0] = '\n';
                message[n + 1] = '\0';

                record_init_failure_Windows_GUI_(message);
            }
        }
#endif
#ifdef FASTFORMAT_INIT_FAILURE_REPORT_VIA_STDERR
        {
            // Record initialisation failure to stderr
# ifdef FASTFORMAT_USE_WIDE_STRINGS
            ::fwprintf(
# else // ? FASTFORMAT_USE_WIDE_STRINGS
            ::fprintf(
# endif // FASTFORMAT_USE_WIDE_STRINGS
                stderr
            ,   FASTFORMAT_LITERAL_STRING("could not initialise the FastFormat library: %s\n")
            ,   fastformat_getInitCodeString(r)
            );
        }
#endif
    }
/// @}

/// \name Not to be implemented
/// @{
private:
    fastformat_initialiser(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

namespace
{
    /// The per-compilation unit instance of fastformat_initialiser, which
    /// ensures that the FastFormat library is initialised prior to use.
    static fastformat_initialiser    s_fastformat_initialiser;

} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_HPP_INITIALISER */

/* ///////////////////////////// end of file //////////////////////////// */
