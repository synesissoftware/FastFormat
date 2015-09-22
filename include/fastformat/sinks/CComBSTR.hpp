/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/CComBSTR.hpp
 *
 * Purpose:     A FastFormat sink adaptor for ATL's CComBSTR.
 *
 * Created:     21st November 2008
 * Updated:     14th September 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/CComBSTR.hpp
 *
 * [C++ only] A FastFormat sink adaptor for ATL's CComBSTR.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CCOMBSTR
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CCOMBSTR

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CCOMBSTR_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CCOMBSTR_MINOR      3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CCOMBSTR_REVISION   1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_CCOMBSTR_EDIT       15
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
#include <fastformat/quality/contract.h>
#include <fastformat/format/standard_flags.hpp>
#include <fastformat/util/sinks/helpers.hpp>

#include <atlbase.h>

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
 * Action Shims
 */

/** Writes an array of string slices into a <code>CComBSTR</code> sink.
 *
 * \ingroup group__sinks
 *
 */
inline CComBSTR& fmt_slices(CComBSTR& sink, int flags, size_t cchTotal, size_t numResults, ff_string_slice_t const* results)
{
    if( 0 != cchTotal ||
        0 != flags)
    {
#if !defined(FASTFORMAT_NO_NAMESPACE)
        using ::fastformat::util::concat_slices;
#endif /* !FASTFORMAT_NO_NAMESPACE */

        const ff_string_slice_t crlf = fastformat_getNewlineForPlatform();

        if(flags::ff_newLine & flags)
        {
            cchTotal += crlf.len;
        }

        if(0u != cchTotal)
        {
            stlsoft::auto_buffer<ff_char_t> buff(1 + cchTotal);

            concat_slices(buff, numResults, results);
            buff[cchTotal] = '\0';

            const unsigned int  len     =   sink.Length();
            const unsigned int  newLen  =   len + static_cast<unsigned int>(cchTotal);
            CComBSTR            newSink(newLen);

            if(newLen != newSink.Length())
            {
                throw std::bad_alloc();
            }
            else
            {
                // Copy in the original
                ::memcpy(newSink.m_str, sink.m_str, len * sizeof(OLECHAR));

#ifdef FASTFORMAT_USE_WIDE_STRINGS

                ::memcpy(newSink.m_str + len, buff.data(), cchTotal * sizeof(OLECHAR));

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

                int r = ::MultiByteToWideChar(0, 0, buff.data(), int(cchTotal), &newSink.m_str[0] + len, int(cchTotal));

                if(0 == r)
                {
                    //DWORD e = ::GetLastError();

                    // TODO: Use more-derived exception and capture GetLastError()
                    throw sink_output_exception("character encoding conversion failed");
                }

#endif /* FASTFORMAT_USE_WIDE_STRINGS */

                if(flags::ff_newLine & flags)
                {
                    { for(size_t i = 0; i != crlf.len; ++i)
                    {
                        newSink.m_str[newLen - crlf.len + i] = crlf.ptr[i];
                    }}
                }

                newSink.m_str[newLen] = L'\0';

                std::swap(sink.m_str, newSink.m_str);
            }
        }
    }

    return sink;
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CCOMBSTR */

/* ///////////////////////////// end of file //////////////////////////// */
