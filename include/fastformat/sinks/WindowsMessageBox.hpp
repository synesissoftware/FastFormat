/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/WindowsMessageBox.hpp
 *
 * Purpose:     A FastFormat sink for Windows message boxes.
 *
 * Created:     4th January 2009
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


/** \file fastformat/sinks/FILE.hpp
 *
 * [C++ only] A FastFormat sink for Windows Windows message boxes.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX_MINOR     1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX_REVISION  1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX_EDIT      12
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

#include <fastformat/fastformat.h>
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/util/sinks/helpers.hpp>

#include <winstl/shims/access/string/HWND.hpp>
#include <stlsoft/memory/auto_buffer.hpp>

#include <windows.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace sinks
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Sink for sending a statement to Windows' <code>MessageBox()</code>.
 *
 * \ingroup group__sinks
 */
class WindowsMessageBox_sink
{
public: // Member Types
    /// This type
    typedef WindowsMessageBox_sink          class_type;
private:
    typedef std::basic_string<ff_char_t>    string_type_;

public: // Construction
    /// Constructs an instance of the sink
    ///
    /// \param hwnd Handle of the message box's owner window, or NULL if no
    ///   owner
    /// \param caption The string to be used as the message box's title
    /// \param type Flags controlling the contents and behaviour of the
    ///   message box, passed through to the underlying \c MessageBox() call
    WindowsMessageBox_sink(HWND hwnd, ff_char_t const* caption, UINT type)
        : m_hwnd(hwnd)
        , m_caption(get_caption_(hwnd, caption))
        , m_type(type)
        , m_result(0)
    {}
    /// Copy constructor
    WindowsMessageBox_sink(WindowsMessageBox_sink const& rhs);
private:
    WindowsMessageBox_sink& operator =(WindowsMessageBox_sink const& rhs);

public:
    /// Coalesces the slices and invokes \c MessageBox() with the result
    WindowsMessageBox_sink& write(int /* flags */, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
    {
#if !defined(FASTFORMAT_NO_NAMESPACE)
        using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

        stlsoft::auto_buffer<ff_char_t> text(cchTotal + 1u);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
        if(text.empty())
        {
            m_result = -1;
        }
        else
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
        {
            concat_slices(text, numResults, results);
            text[cchTotal] = '\0';

            m_result = MessageBox_(m_hwnd, text.data(), m_caption.c_str(), m_type);
        }

        return *this;
    }

public:
    /// Implicit conversion operator for retrieving the <code>MessageBox()</code> return code
    operator int() const
    {
        return m_result;
    }

private:
    static string_type_ get_caption_(HWND hwnd, ff_char_t const* caption)
    {
        // If no caption is specified, then ...
        if( NULL == caption &&
            NULL != hwnd)
        {
            // ... attempt to read it from the top-most parent
            { for(HWND hwndParent; (NULL != (hwndParent = ::GetWindow(hwnd, GW_OWNER))); )
            {
                hwnd = hwndParent;
            }}

            return string_type_(stlsoft::c_str_ptr(hwnd));
        }
        else
        {
            return stlsoft::c_str_ptr(caption);
        }
    }

    static int MessageBox_(HWND hwnd, char const* message, char const* caption, UINT type)
    {
        return ::MessageBoxA(hwnd, message, caption, type);
    }
    static int MessageBox_(HWND hwnd, wchar_t const* message, wchar_t const* caption, UINT type)
    {
        return ::MessageBoxW(hwnd, message, caption, type);
    }

private:
    const HWND          m_hwnd;
    string_type_ const  m_caption;
    const UINT          m_type;
    int                 m_result;
};

/* /////////////////////////////////////////////////////////////////////////
 * creator functions
 */

/** Creator function for the WindowsMessageBox_sink class
 *
 * \ingroup group__sinks
 */
inline WindowsMessageBox_sink MessageBox(HWND hwnd, LPCTSTR caption, UINT type)
{
    return WindowsMessageBox_sink(hwnd, caption, type);
}

/** Creator function for the WindowsMessageBox_sink class
 *
 * \ingroup group__sinks
 */
inline WindowsMessageBox_sink MessageBox(LPCTSTR caption, UINT type)
{
    return WindowsMessageBox_sink(NULL, caption, type);
}

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/** Writes an array of string slices into a
 * <code>WindowsMessageBox_sink</code> sink.
 *
 * \ingroup group__sinks
 *
 */
inline WindowsMessageBox_sink& fmt_slices(WindowsMessageBox_sink& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
    return sink.write(flags, cchTotal, numResults, results);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_WINDOWSMESSAGEBOX */

/* ///////////////////////////// end of file //////////////////////////// */
