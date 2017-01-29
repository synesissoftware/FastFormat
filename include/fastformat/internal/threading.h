/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/threading.h
 *
 * Purpose:     Detects whether the library is being built single- or
 *              multi-threaded.
 *
 * Created:     20th November 2007
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/internal/threading.h
 *
 * [C, C++] Detects whether the library is being built single- or
 *   multi-threaded.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_THREADING
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_THREADING

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>

#include <platformstl/platformstl.h>
#include <platformstl/synch/util/features.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifdef FASTFORMAT_MT
# undef FASTFORMAT_MT
#endif /* FASTFORMAT_MT */

#if defined(FASTFORMAT_FORCE_MT)
# define FASTFORMAT_MT
#elif !defined(FASTFORMAT_NO_MT)
# if defined(PLATFORMSTL_OS_IS_UNIX)
#  if defined(UNIXSTL_USING_PTHREADS)
#   define FASTFORMAT_MT
#  endif /* UNIXSTL_USING_PTHREADS */
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)
#  if defined(__MT__) || \
      defined(_REENTRANT) || \
      defined(_MT)
#   define FASTFORMAT_MT
#  endif /* ?? mt ?? */
# else /* ? OS */
#  error Platform is not yet discriminated
# endif /* OS */
#endif /* FASTFORMAT_FORCE_MT || FASTFORMAT_NO_MT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_THREADING */

/* ///////////////////////////// end of file //////////////////////////// */
