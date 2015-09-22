/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/WindowsConsole.hpp
 *
 * Purpose:     A FastFormat sink for coloured output via Windows' console.
 *
 * Created:     6th January 2011
 * Updated:     2nd March 2011
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2011, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/WindowsConsole.hpp
 *
 * [C++ only] A FastFormat sink for coloured output via Windows' console.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE_REVISION 2
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE_EDIT     2
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
#include <fastformat/exceptions.hpp>
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/quality/contract.h>
#include <fastformat/util/sinks/helpers.hpp>

#include <winstl/system/console_colour_scope.hpp>
#ifdef _WIN64
# include <stlsoft/conversion/truncation_cast.hpp>
#endif /* _WIN64 */

#include <windows.h>

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
 * Classes
 */

/** Sink for coloured output via Windows' console.
 *
 * \ingroup group__sinks
 */
class WindowsConsole_sink
{
public:
    /// Constructs an instance of the sink
    ///
    /// \param hConsole Handle of the console, or NULL to use the standard output
    ///   handle.
    /// \param textAttributes Text attributes to be used by the sink.
    ///
    WindowsConsole_sink(HANDLE hConsole, WORD textAttributes)
        : m_hConsole(hConsole)
        , m_textAttributes(textAttributes)
    {}
    /// Copy constructor
    WindowsConsole_sink(WindowsConsole_sink const& rhs);
private:
    WindowsConsole_sink& operator =(WindowsConsole_sink const& rhs);

public:
    /// Coalesces the slices and write the result to the Windows' console
    WindowsConsole_sink& write(int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
    {
#if !defined(FASTFORMAT_NO_NAMESPACE)
        using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

        stlsoft::auto_buffer<ff_char_t> text(cchTotal + 1u + 2u);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
        if(text.empty())
        {
        }
        else
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
        {
            concat_slices(text, numResults, results);

            if(flags::ff_newLine & flags)
            {
                const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

                ::memcpy(&text[cchTotal], crlf.ptr, crlf.len * sizeof(ff_char_t));
                cchTotal += crlf.len;
            }

            text[cchTotal] = '\0';

            winstl::console_colour_scope scoper(m_hConsole, m_textAttributes);

            WriteConsole_(m_hConsole, text.data(), cchTotal);
        }

        return *this;
    }

private:
#ifdef _WIN64
    static int WriteConsole_(HANDLE hConsole, ff_char_t const* message, size_t cchMessage)
    {
        return WriteConsole_(hConsole, message, stlsoft::truncation_cast<DWORD>(cchMessage));
    }
#endif /* _WIN64 */

    static int WriteConsole_(HANDLE hConsole, char const* message, DWORD cchMessage)
    {
        DWORD numWritten;

        return ::WriteConsoleA(hConsole, message, cchMessage, &numWritten, NULL);
    }
    static int WriteConsole_(HANDLE hConsole, wchar_t const* message, DWORD cchMessage)
    {
        DWORD numWritten;

        return ::WriteConsoleW(hConsole, message, cchMessage, &numWritten, NULL);
    }

private:
    HANDLE const    m_hConsole;
    WORD const      m_textAttributes;
};

/* /////////////////////////////////////////////////////////////////////////
 * Creator Functions
 */

/** Creator function for the WindowsConsole_sink class
 *
 * \ingroup group__sinks
 */
inline WindowsConsole_sink WindowsConsole(HANDLE hConsole, WORD textAttributes)
{
    return WindowsConsole_sink(hConsole, textAttributes);
}

/** Creator function for the WindowsConsole_sink class
 *
 * \ingroup group__sinks
 */
inline WindowsConsole_sink WindowsConsole(WORD textAttributes)
{
    return WindowsConsole_sink(::GetStdHandle(STD_OUTPUT_HANDLE), textAttributes);
}

/* /////////////////////////////////////////////////////////////////////////
 * Action Shims
 */

/** Writes an array of string slices into a
 * <code>WindowsConsole_sink</code> sink.
 *
 * \ingroup group__sinks
 *
 */
inline WindowsConsole_sink& fmt_slices(WindowsConsole_sink& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
    return sink.write(flags, cchTotal, numResults, results);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_WINDOWSCONSOLE */

/* ///////////////////////////// end of file //////////////////////////// */
