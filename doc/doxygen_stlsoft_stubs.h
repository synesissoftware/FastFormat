/* /////////////////////////////////////////////////////////////////////////
 * File:        doc/doxygen_stlsoft_stubs.h
 *
 * Purpose:     Documentation-only stand-ins for STLSoft integer typedefs
 *              named in FastFormat public headers. Keeps Doxygen link
 *              resolution working when STLSoft is not on INCLUDE_PATH.
 *
 * Created:     16th October 2026
 * Updated:     16th October 2026
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
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
 * - Neither the names of Matthew Wilson and Synesis Information Systems nor
 *   the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
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


/** \file doc/doxygen_stlsoft_stubs.h
 *
 * [Documentation only] Minimal STLSoft integer typedef stubs for Doxygen.
 *
 * Not compiled. Not installed. Used solely so that references such as
 * \c stlsoft::sint32_t in FastFormat signatures resolve when the real
 * STLSoft headers are absent from the documentation INCLUDE_PATH.
 */

#ifndef FASTFORMAT_INCL_DOC_H_DOXYGEN_STLSOFT_STUBS
#define FASTFORMAT_INCL_DOC_H_DOXYGEN_STLSOFT_STUBS


/* /////////////////////////////////////////////////////////////////////////
 * stubs
 */

/** Documentation stub for the STLSoft root namespace. */
namespace stlsoft
{

/** Documentation stub for STLSoft's 8-bit signed integer typedef. */
typedef signed char                                         sint8_t;
/** Documentation stub for STLSoft's 8-bit unsigned integer typedef. */
typedef unsigned char                                       uint8_t;
/** Documentation stub for STLSoft's 16-bit signed integer typedef. */
typedef signed short                                        sint16_t;
/** Documentation stub for STLSoft's 16-bit unsigned integer typedef. */
typedef unsigned short                                      uint16_t;
/** Documentation stub for STLSoft's 32-bit signed integer typedef. */
typedef signed int                                          sint32_t;
/** Documentation stub for STLSoft's 32-bit unsigned integer typedef. */
typedef unsigned int                                        uint32_t;
/** Documentation stub for STLSoft's 64-bit signed integer typedef. */
typedef signed long long                                    sint64_t;
/** Documentation stub for STLSoft's 64-bit unsigned integer typedef. */
typedef unsigned long long                                  uint64_t;

/** Documentation stub for STLSoft's ss_sint8_t. */
typedef sint8_t                                             ss_sint8_t;
/** Documentation stub for STLSoft's ss_uint8_t. */
typedef uint8_t                                             ss_uint8_t;
/** Documentation stub for STLSoft's ss_sint16_t. */
typedef sint16_t                                            ss_sint16_t;
/** Documentation stub for STLSoft's ss_uint16_t. */
typedef uint16_t                                            ss_uint16_t;
/** Documentation stub for STLSoft's ss_sint32_t. */
typedef sint32_t                                            ss_sint32_t;
/** Documentation stub for STLSoft's ss_uint32_t. */
typedef uint32_t                                            ss_uint32_t;
/** Documentation stub for STLSoft's ss_sint64_t. */
typedef sint64_t                                            ss_sint64_t;
/** Documentation stub for STLSoft's ss_uint64_t. */
typedef uint64_t                                            ss_uint64_t;

} /* namespace stlsoft */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_DOC_H_DOXYGEN_STLSOFT_STUBS */

/* ///////////////////////////// end of file //////////////////////////// */
