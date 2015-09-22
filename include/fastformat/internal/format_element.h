/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/format_element.h
 *
 * Purpose:     Definition of the format element type and associated
 *              constants
 *
 * Created:     6th November 2008
 * Updated:     13th September 2010
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


/** \file fastformat/internal/format_element.h
 *
 * [INTERNAL: C, C++] Definition of the format element type and associated
 *   constants
 *
 * \note The types and constants defined in this file are subject to
 *   change at any time, without warning: DO NOT rely on any aspect of this
 *   file
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_FORMAT_ELEMENT
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_FORMAT_ELEMENT

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Constants and definitions
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

#define FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_       (-1)
#define FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_INVALID_       (-2)

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

typedef short   ff_format_element_width_t_;

enum ff_format_element_alignment_t_
{
        FASTFORMAT_ALIGNMENT_NONE   =   0   /*!< default alignment (right-aligned) */
    ,   FASTFORMAT_ALIGNMENT_LEFT   =   1   /*!< left-aligned */
    ,   FASTFORMAT_ALIGNMENT_RIGHT  =   2   /*!< right-aligned */
    ,   FASTFORMAT_ALIGNMENT_CENTRE =   3   /*!< centre-aligned. Not currently supported */
};

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* Three kinds of elements:
 *
 * 1. Literals
 *  index       ==  FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_
 *  len         ->  length of the literal slice
 *  ptr         ->  pointer to the slice
 *  minWidth    ->  UNDEFINED
 *  maxWidth    ->  UNDEFINED
 *
 * 2. Replacements
 *  index       ->  the replacement index (>= 0)
 *  len         ->  UNDEFINED
 *  ptr         ->  UNDEFINED
 *  minWidth    ->  UNDEFINED
 *  maxWidth    ->  UNDEFINED
 *
 * 3. Spacers
 *  index       ->  { FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_PAD_LEFT_ | FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_PAD_RIGHT_ }
 *  len         ->  UNDEFINED
 *  ptr         ->  UNDEFINED
 *  minWidth    ->  minimum width of field
 *  maxWidth    ->  maximum width of field
 *
 *   Spacers always precede Replacements
 */

/** Format element
 *
 * \ingroup group__rigging
 */
struct ff_format_element_t
{
    size_t                          len;        /*!< Length of the replacement string slice. */
    ff_char_t const*                ptr;        /*!< Pointer to the base of the replacement string slice. */
    int                             index;      /*!< -1 if literal, -2 if malformed (and len+ptr correspond to all of it) */
    ff_format_element_width_t_      minWidth;   /*!< Minimum length of field */
    ff_format_element_width_t_      maxWidth;   /*!< Maximum length of field */
    ff_format_element_alignment_t_  alignment;  /*!< alignment of field */
    int                             fill;       /*!< fill instruction of field */
#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
    int                             reserved1;
    void*                           reserved2;
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_FORMAT_ELEMENT */

/* ///////////////////////////// end of file //////////////////////////// */
