/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/WindowsLargeIntegers.hpp
 *
 * Purpose:     Inserter functions for Windows' large integer types.
 *
 * Created:     13th September 2010
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2010-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/inserters/WindowsLargeIntegers.hpp
 *
 * [C++ only] Inserter functions for Windows' large integer types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS_REVISION  1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS_EDIT      2
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_ULARGE_INTEGER
# include <fastformat/inserters/ULARGE_INTEGER.hpp>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_ULARGE_INTEGER */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER
# include <fastformat/inserters/LARGE_INTEGER.hpp>
#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_LARGE_INTEGER */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_WINDOWSLARGEINTEGERS */

/* ///////////////////////////// end of file //////////////////////////// */
