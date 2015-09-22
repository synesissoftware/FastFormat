/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/quality/cover.h
 *
 * Purpose:     Defines the cover monitoring constructs used in the
 *              FastFormat core.
 *
 * Created:     22nd April 2008
 * Updated:     18th February 2009
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2009, Matthew Wilson and Synesis Software
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


/** \file fastformat/quality/cover.h
 *
 * [C, C++] Defines the cover monitoring constructs used in the FastFormat
 *   core.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_QUALITY_H_COVER
#define FASTFORMAT_INCL_FASTFORMAT_QUALITY_H_COVER

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_QUALITY_H_COVER_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_QUALITY_H_COVER_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_QUALITY_H_COVER_REVISION 2
# define FASTFORMAT_VER_FASTFORMAT_QUALITY_H_COVER_EDIT     5
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>

#ifdef FASTFORMAT_USE_XCOVER
# include <xcover/xcover.h>
#else /* ? FASTFORMAT_USE_XCOVER */
# ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT
#  include <fastformat/internal/stlsoft.h>
# endif /* !FASTFORMAT_INCL_FASTFORMAT_INTERNAL_HPP_STLSOFT */
#endif /* FASTFORMAT_USE_XCOVER */

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef FASTFORMAT_USE_XCOVER

# error FastFormat does not currently work with xCover

#else /* ? FASTFORMAT_USE_XCOVER */

# define FASTFORMAT_COVER_MARK_ENTRY()           ((void)0)

#endif /* FASTFORMAT_USE_XCOVER */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_QUALITY_H_COVER */

/* ///////////////////////////// end of file //////////////////////////// */
