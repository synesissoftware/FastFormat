/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/speech.hpp
 *
 * Purpose:     A FastFormat sink for the Windows Speech API.
 *
 * Created:     27th November 2007
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/speech.hpp
 *
 * [C++ only] A FastFormat sink for the Windows Speech API.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_SPEECH
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_SPEECH

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SPEECH_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SPEECH_MINOR    3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SPEECH_REVISION 1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_SPEECH_EDIT     22
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

#if !defined(WIN32) && \
    !defined(WIN64)
# error The speech_sink component is currently implemented only on Windows, using SAPI; contributions for Mac, Linux and others are welcomed
#endif /* OS */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/exceptions.hpp>
#include <fastformat/util/sinks/helpers.hpp>
#include <fastformat/format/standard_flags.hpp>

#include <comstl/speech/sapi_util.hpp>
#include <comstl/util/initialisers.hpp>

#include <stlsoft/smartptr/ref_ptr.hpp>
#include <stlsoft/memory/auto_buffer.hpp>

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

/** Sink for translating a statement into speech
 *
 * \ingroup group__sinks
 *
 * \note This component currently is only available on Windows, because it
 *  uses the Microsoft Speech API (SAPI). If anyone cares to contribute
 *  implementations for Linux or Mac OS-X, that would be very welcome.
 */
class speech_sink
{
public: // Member Types
    /// This type
    typedef speech_sink                     class_type;
    /// The underlying voice type
    typedef stlsoft::ref_ptr<ISpVoice>      voice_type;

public: // Construction
    /// Constructs an instance
    explicit speech_sink(int flags = 0)
        : m_coinit()
        , m_voice(init_voice_())
        , m_flags(flags & ~disallowed_flags_())
    {}

public: // Accessors
    /// Returns a managed reference to the underlying speech instance.
    voice_type get() const
    {
        return m_voice;
    }

public: // Shim Operations
    /// Outputs the results
    class_type& write(int /* flags */, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
    {
        stlsoft::auto_buffer<ff_char_t> buff(1 + cchTotal);

#ifndef STLSOFT_CF_THROW_BAD_ALLOC
        if( !m_voice.empty() &&
            !buff.empty())
#endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
        {
#if !defined(FASTFORMAT_NO_NAMESPACE)
            using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

            concat_slices(buff, numResults, results);
            buff[cchTotal] = '\0';

            HRESULT hr = comstl::sapi_speak(m_voice, buff.data(), static_cast<DWORD>(m_flags));

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
            if(FAILED(hr))
            {
                // TODO: Use more-derived exception and capture hr
                throw sink_output_exception("Failed to write statement");
            }
#else /* STLSOFT_CF_EXCEPTION_SUPPORT */
            STLSOFT_SUPPRESS_UNUSED(hr);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        }

        return *this;
    }

private: // Implementation
    static int disallowed_flags_()
    {
        return SPF_IS_FILENAME;
    }

    static voice_type init_voice_()
    {
        voice_type  voice;
        HRESULT     hr = comstl::sapi_create(voice);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        if(FAILED(hr))
        {
// TODO:            throw 
        }
#else /* STLSOFT_CF_EXCEPTION_SUPPORT */
        STLSOFT_SUPPRESS_UNUSED(hr);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

        return voice;
    }

private: // Member Variables
    comstl::com_initializer m_coinit;
    voice_type              m_voice;
    const int               m_flags;
};

/* /////////////////////////////////////////////////////////////////////////
 * action shims
 */

/** Writes an array of string slices into a speech sink.
 *
 * \ingroup group__sinks
 *
 */
inline speech_sink& fmt_slices(speech_sink& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
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

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_SPEECH */

/* ///////////////////////////// end of file //////////////////////////// */
