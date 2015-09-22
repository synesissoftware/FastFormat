/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/init_codes.h
 *
 * Purpose:     Initialisation codes.
 *
 * Created:     27th May 2008
 * Updated:     13th September 2010
 *
 * Home:        http://www.include.org/
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


/** \file fastformat/init_codes.h
 *
 * [C, C++] Initialisation codes.
 *
 * This file defines advisory status codes for initialisation.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_ERROR_CODES
#define FASTFORMAT_INCL_FASTFORMAT_H_ERROR_CODES

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_H_ERROR_CODES_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_H_ERROR_CODES_MINOR      0
# define FASTFORMAT_VER_FASTFORMAT_H_ERROR_CODES_REVISION   1
# define FASTFORMAT_VER_FASTFORMAT_H_ERROR_CODES_EDIT       5
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
# include <include/include.h>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

/* /////////////////////////////////////////////////////////////////////////
 * Documentation
 */

/** \defgroup group__status_codes FastFormat Low-level Status Codes
 *
 * \ingroup group__core_library
 *
 * Status codes for use by the implementors of the various sub-systems.
 */

/* /////////////////////////////////////////////////////////////////////////
 * Status codes
 */

/** \def FASTFORMAT_INIT_RC_SUCCESS
 *
 * Specifies that the operation completed successfully
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_SUCCESS                       (0)

/** \def FASTFORMAT_INIT_RC_OUT_OF_MEMORY
 *
 * Specifies that the operation failed due to memory exhaustion
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_OUT_OF_MEMORY                 (-1)

/** \def FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION
 *
 * Specifies that the operation failed because a general, standard-derived, exception was thrown
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION         (-2)

/** \def FASTFORMAT_INIT_RC_UNKNOWN_ERROR
 *
 * Specifies that the operation failed because a bespoke, non-standard-derived, exception was thrown
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_UNKNOWN_ERROR                 (-3)

/** \def FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR
 *
 * Specifies that the operation failed in an unspecified manner
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR             (-4)

/** \def FASTFORMAT_INIT_RC_NOT_IMPLEMENTED
 *
 * Specifies that the operation failed because it is not implemented
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_NOT_IMPLEMENTED               (-5)

/** \def FASTFORMAT_INIT_RC_CANNOT_CREATE_TSS_INDEX
 *
 * Specifies that the operation failed because a Thread-Specific Storage key
 * could not be created.
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_CANNOT_CREATE_TSS_INDEX       (-6)

/** \def FASTFORMAT_INIT_RC_CANNOT_CREATE_THREAD
 *
 * Specifies that the operation failed because a thread could not be
 * created.
 *
 * \ingroup group__status_codes
 */
#define FASTFORMAT_INIT_RC_CANNOT_CREATE_THREAD          (-7)

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_ERROR_CODES */

/* ///////////////////////////// end of file //////////////////////////// */
