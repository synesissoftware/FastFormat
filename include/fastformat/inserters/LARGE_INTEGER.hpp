/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/LARGE_INTEGER.hpp
 *
 * Purpose:     Inserter functions for Windows' LARGE_INTEGER type.
 *
 * Created:     24th November 2010
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2010-2013, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


/** \file fastformat/inserters/LARGE_INTEGER.hpp
 *
 * [C++ only] Inserter functions for Windows' LARGE_INTEGER type.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER_REVISION 3
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER_EDIT     5
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/inserters/to_i.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace inserters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inserter functions
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1310

inline
ximpl_integer::ff_to_i_r_t_
to_i(
    LARGE_INTEGER const&    value
)
{
    return to_i(value.QuadPart);
}
inline
ximpl_integer::ff_to_i_r_t_
to_i(
    LARGE_INTEGER const&    value
,   int                     minimumWidth
)
{
    return to_i(value.QuadPart, minimumWidth);
}
inline
ximpl_integer::ff_to_i_r_t_
to_i(
    LARGE_INTEGER const&    value
,   int                     minimumWidth
,   int                     precision
)
{
    return to_i(value.QuadPart, minimumWidth, precision);
}

#else /* ? compiler */

/** Inserts the string form of a LARGE_INTEGER value
 *
 * \ingroup group__inserters
 *
 * \param value The LARGE_INTEGER value to be converted to string form
 * \param minimumWidth The minimum width of the result. If negative, the
 *   integer is aligned to the left of the resulting field
 * \param precision The minimum number of digits in the field, which will
 *   result in zero-padding if the given integer has fewer digits
 *
 * \return An instance of an insertable type containing the string form of
 *   the integer
 *
 * \pre abs(minimumWidth) < 512
 * \pre decimalPlaces <= minimumWidth
 */
inline
ximpl_integer::ff_to_i_r_t_
to_i(
    LARGE_INTEGER const&    value
,   int                     minimumWidth    =   ximpl_integer::default_width_sentinel_()
,   int                     precision       =   ximpl_integer::default_precision_sentinel_()
)
{
    return to_i(value.QuadPart, minimumWidth, precision);
}

#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::to_i;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER */

/* ///////////////////////////// end of file //////////////////////////// */
