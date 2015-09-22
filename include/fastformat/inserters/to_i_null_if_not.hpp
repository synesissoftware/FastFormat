/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/to_i_null_if_not.hpp
 *
 * Purpose:     Nullable inserter functions for integral types
 *
 * Created:     20th February 2010
 * Updated:     7th December 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/inserters/to_i_null_if_not.hpp
 *
 * [C++ only] Nullable inserter functions for integral types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT_REVISION  2
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT_EDIT      5
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>
#include <fastformat/internal/inserters/int_typedefs.hpp>

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

/** Inserts the string form of an integral value, or an empty string in the
 * case where the value is zero.
 *
 * \ingroup group__inserters
 *
 * \param i The integral value to be converted to string form.
 * \param sentinel The value to which \c i will be compared for exclusion.
 *
 * \return An instance of an insertable type containing the string form of the integer
 *
 * \pre I is an integral type
 */
template <typename I>
fastformat::inserters::ximpl_integer::ff_to_i_r_t_ to_i_null_if_not(
    I const& i
,   I const& sentinel
)
{
    if(i == sentinel)
    {
        return fastformat::inserters::ximpl_integer::ff_to_i_r_t_(static_cast<ff_char_t const*>(NULL), 0);
    }
    else
    {
        return to_i(i);
    }
}

/** Inserts the string form of an integral value, or an empty string in the
 * case where the value is zero if the parameter <code>nullIfZero</code> is
 * non-zero.
 *
 * \ingroup group__inserters
 *
 * \param i The integral value to be converted to string form.
 * \param sentinel The value to which \c i will be compared for exclusion.
 * \param nullIfSame Causes a <code>"0"</code> to be replaced by the empty string
 *
 * \return An instance of an insertable type containing the string form of the integer
 *
 * \pre I is an integral type
 */
template <typename I>
fastformat::inserters::ximpl_integer::ff_to_i_r_t_ to_i_null_if_not(
    I const&    i
,   I const&    sentinel
,   int         nullIfSame
)
{
    if( nullIfZero &&
        i == sentinel)
    {
        return fastformat::inserters::ximpl_integer::ff_to_i_r_t_(static_cast<ff_char_t const*>(NULL), 0);
    }
    else
    {
        return to_i(i);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::to_i_null_if_not;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_TO_I_NULL_IF_NOT */

/* ///////////////////////////// end of file //////////////////////////// */
