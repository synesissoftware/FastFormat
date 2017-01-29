/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/string_encoding.h
 *
 * Purpose:     Utilities to assist with implementation as multibyte or
 *              wide string
 *
 * Created:     12th September 2008
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/internal/string_encoding.h
 *
 * [C, C++] Utilities to assist with implementation as multibyte or wide
 *   string
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_STRING_ENCODING
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_STRING_ENCODING

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** Used to define literal strings
 *
 * This will be <code>L ## x</code> if
 * <code>FASTFORMAT_USE_WIDE_STRINGS</code> is defined, otherwise
 * <code>x</code>.
 */

/** \def FASTFORMAT_LITERAL_STRING(s)
 *
 * Defines the literal string as a multibyte or wide string, depending on
 * the absence or presence, respectively, of the symbol FASTFORMAT_USE_WIDE_STRINGS
 */

/** \def FASTFORMAT_LITERAL_CHARACTER(s)
 *
 * Defines the literal string as a multibyte or wide character, depending on
 * the absence or presence, respectively, of the symbol FASTFORMAT_USE_WIDE_STRINGS
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define FASTFORMAT_LITERAL_STRING(s)       L ## s
# define FASTFORMAT_LITERAL_CHARACTER(c)    L ## c
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define FASTFORMAT_LITERAL_STRING(s)       s
# define FASTFORMAT_LITERAL_CHARACTER(c)    c
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_STRING_ENCODING */

/* ///////////////////////////// end of file //////////////////////////// */
