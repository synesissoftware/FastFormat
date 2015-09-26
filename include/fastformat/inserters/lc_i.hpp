/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/lc_i.hpp
 *
 * Purpose:     Inserter function for integral types in locale format.
 *
 * Created:     1st September 2012
 * Updated:     2nd September 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2012, Matthew Wilson and Synesis Software
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


/** \file fastformat/inserters/lc_i.hpp
 *
 * [C++ only] Inserter function for integral types in locale format.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LC_I
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LC_I

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LC_I_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LC_I_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LC_I_REVISION  1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_LC_I_EDIT      1
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/internal/inserters/int_typedefs.hpp>

#include <stlsoft/conversion/integer_to_string/integer_to_lc_string.hpp>

#include <locale.h>

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

/** .
 *
 * \ingroup group__inserters
 *
 * \param value The integral value to be converted to string form
 *
 * \return An instance of an insertable type containing the string form of
 *   the integer
 *
 * \pre I is an integral type
 */
template <typename I>
inline
ximpl_integer::ff_to_i_r_t_
lc_i(
    I const& value
)
{
    STLSOFT_STATIC_ASSERT(stlsoft::is_integral_type<I>::value);

	ximpl_integer::ff_to_i_r_t_ r;

	struct lconv const* const lc = ::localeconv();

	ff_char_t	sz[41];
	size_t		n;

	ff_char_t const* const s = stlsoft::integer_to_lc_string(
		lc->grouping
	,	*lc->thousands_sep
	,	sz
	,	STLSOFT_NUM_ELEMENTS(sz)
	,	value
	,	&n
	);

	r.assign(s, n);

	return r;
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::lc_i;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LC_I */

/* ///////////////////////////// end of file //////////////////////////// */
