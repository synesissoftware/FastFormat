/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/util/sinks/helpers.hpp
 *
 * Purpose:     Sink implementation helper functions for the FastFormat
 *              library.
 *
 * Created:     19th December 2007
 * Updated:     5th February 2012
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


/** \file fastformat/util/sinks/helpers.hpp
 *
 * [C++ only] Sink implementation helper functions for the FastFormat
 *  library.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_UTIL_SINKS_HPP_HELPERS
#define FASTFORMAT_INCL_FASTFORMAT_UTIL_SINKS_HPP_HELPERS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_UTIL_SINKS_HPP_HELPERS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_UTIL_SINKS_HPP_HELPERS_MINOR     2
# define FASTFORMAT_VER_FASTFORMAT_UTIL_SINKS_HPP_HELPERS_REVISION  1
# define FASTFORMAT_VER_FASTFORMAT_UTIL_SINKS_HPP_HELPERS_EDIT      14
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
#include <fastformat/quality/contract.h>
#include <fastformat/format/standard_flags.hpp>

#if _STLSOFT_VER >= 0x010a0182
# include <platformstl/exception/platformstl_exception.hpp>
#else
# include <platformstl/error/exceptions.hpp>
#endif
#include <stlsoft/memory/auto_buffer.hpp>

#include <string>

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
 * Functions
 */


/** Writes a number of slices into a buffer pre-allocated to have sufficient
 * space.
 *
 * \param buff A mutable (non-<code>const</code>) reference to a buffer that
 *   has sufficient space to hold all the elements
 * \param numResults The number of entries in the array pointed to by the
 *   <code>results</code> parameter
 * \param results Pointer to an array of \link fastformat::ff_string_slice_t string_slice_t\endlink elements to be
 *   written into <code>buff</code>.
 *
 * \remarks The buffer may be any type that is structurally conformant to
 *   <code>stlsoft::auto_buffer</code> to the degree of having a subscript
 *   operator that returns a mutable (non-<code>const</code>) reference to
 *   the start of the contiguously arrayed elements, and a non-mutable
 *   (<code>const</code>) <code>size()</code> method returning the number
 *   of elements available to be written.
 */
template <typename B>
inline size_t concat_slices(B& buff, size_t numResults, ff_string_slice_t const* results)
{
    ff_char_t*  p       =   &buff[0];
    size_t      total   =   0;

    { for(size_t i = 0; i != numResults; ++i, ++results)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(total + results->len <= buff.size(), "insufficient space in buffer to write the results");

        STLSOFT_SUPPRESS_UNUSED(total);

        ::memcpy(p, results->ptr, results->len * sizeof(ff_char_t));

        p       +=  results->len;
        total   +=  results->len;
    }}

    return total;
}

/** Writes a number of slices into a character array that must have
 * sufficient space.
 *
 * \param cchBuff The number of characters in the array pointed to by the
 *   <code>buff</code> parameter
 * \param buff A pointer to an array that has sufficient space to hold all
 *  the elements
 * \param numResults The number of entries in the array pointed to by the
 *   <code>results</code> parameter
 * \param results Pointer to an array of \link fastformat::ff_string_slice_t string_slice_t\endlink elements to be
 *   written into <code>buff</code>.
 */
inline size_t concat_slices(size_t cchBuff, ff_char_t* buff, size_t numResults, ff_string_slice_t const* results)
{
    STLSOFT_SUPPRESS_UNUSED(cchBuff);

    ff_char_t*  p       =   &buff[0];
    size_t      total   =   0;

    { for(size_t i = 0; i != numResults; ++i, ++results)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(total + results->len <= cchBuff, "insufficient space in buffer to write the results");

        STLSOFT_SUPPRESS_UNUSED(total);

        ::memcpy(p, results->ptr, results->len * sizeof(ff_char_t));

        p       +=  results->len;
        total   +=  results->len;
    }}

    return total;
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace util */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_UTIL_SINKS_HPP_HELPERS */

/* ///////////////////////////// end of file //////////////////////////// */
