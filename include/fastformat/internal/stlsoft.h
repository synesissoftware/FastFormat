/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/stlsoft.h
 *
 * Purpose:     "Entry point" include into the STLSoft libraries.
 *
 * Created:     18th November 2007
 * Updated:     22nd July 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2012, Matthew Wilson and Synesis Software
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


/** \file fastformat/internal/stlsoft.h
 *
 * [C, C++] "Entry point" include into the STLSoft libraries.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#if !defined(_STLSOFT_VER) || \
    _STLSOFT_VER < 0x010973ff
# error Requires STLSoft 1.9.115, or later. (www.stlsoft.org)
#endif /* STLSoft version */

#if _STLSOFT_VER < 0x010a0000 && \
    defined(_STLSOFT_1_10_VER) && \
    _STLSOFT_1_10_VER < 0x010a0109

# error Not all aspects of FastFormat work with STLSoft 1.10 versions between 1.10.1 alpha 1 and 1.10.1 alpha 8. If you wish to use STLSoft 1.10 alpha with FastFormat, please download the latest version from www.stlsoft.org

#endif /* STLSoft 1.10.1 alpha 1 - alpha 8 */


#ifdef _STLSOFT_NO_NAMESPACE
# error FastFormat requires that STLSoft`s namespace has not been disabled
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT */

/* ///////////////////////////// end of file //////////////////////////// */
