/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/format/standard_flags.hpp
 *
 * Purpose:     FastFormat standard format flags.
 *
 * Created:     18th November 2007
 * Updated:     7th March 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/format/standard_flags.hpp
 *
 * [C++ only] FastFormat standard format flags.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS
#define FASTFORMAT_INCL_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS_REVISION  8
# define FASTFORMAT_VER_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS_EDIT      11
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

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT
# include <fastformat/internal/stlsoft.h>   /* for sint16_t */
#endif /* !FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT */

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

namespace flags
{

/** Flag passed through to the fmt_slices() action shim to denote a request
 *   to issue a new line at the end of the processing of the current
 *   statement.
 */
const ::stlsoft::sint16_t   ff_newLine  =   0x0001;

/** Flag passed through to the fmt_slices() action shim to denote a request
 *   to flush the sink at the end of the processing of the current
 *   statement.
 */
const ::stlsoft::sint16_t   ff_flush    =   0x0002;

} /* namespace flags */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_FORMAT_HPP_STANDARD_FLAGS */

/* ///////////////////////////// end of file //////////////////////////// */
