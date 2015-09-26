/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/to_g.hpp
 *
 * Purpose:     Inserter functions for floating-point types
 *
 * Created:     30th April 2009
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/inserters/to_g.hpp
 *
 * [C++ only] Inserter functions for floating-point types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_TO_G
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_TO_G

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_G_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_G_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_G_REVISION  4
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_G_EDIT      7
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/inserters/real.hpp>

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

/** Inserts the string form of a floating-point value
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> to_g(
    double const&   value
)
{
    return 
#if !defined(FASTFORMAT_NO_NAMESPACE)
      ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        real(value, ximpl_real::default_width_sentinel_(), ximpl_real::default_precision_sentinel_(), 'g');
}

/** Inserts the string form of a floating-point value
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> to_G(
    double const&   value
)
{
    return 
#if !defined(FASTFORMAT_NO_NAMESPACE)
      ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        real(value, ximpl_real::default_width_sentinel_(), ximpl_real::default_precision_sentinel_(), 'G');
}

/** Inserts the string form of a floating-point value, with the given width
 * and precision
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 * \param minimumWidth The minimum width of the resulting string form
 * \param decimalPlaces The number of decimal places to be included
 *
 * \pre minimumWidth < 512
 * \pre decimalPlaces <= minimumWidth
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> to_g(
    double const&   value
,   int             minimumWidth
,   int             decimalPlaces
)
{
    return 
#if !defined(FASTFORMAT_NO_NAMESPACE)
      ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        real(value, minimumWidth, decimalPlaces, 'g');
}

/** Inserts the string form of a floating-point value, with the given width
 * and precision
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 * \param minimumWidth The minimum width of the resulting string form
 * \param decimalPlaces The number of decimal places to be included
 *
 * \pre minimumWidth < 512
 * \pre decimalPlaces <= minimumWidth
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> to_G(
    double const&   value
,   int             minimumWidth
,   int             decimalPlaces
)
{
    return 
#if !defined(FASTFORMAT_NO_NAMESPACE)
      ::fastformat::inserters::
#endif /* !FASTFORMAT_NO_NAMESPACE */
        real(value, minimumWidth, decimalPlaces, 'G');
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::to_g;
using ::fastformat::inserters::to_G;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_TO_G */

/* ///////////////////////////// end of file //////////////////////////// */
