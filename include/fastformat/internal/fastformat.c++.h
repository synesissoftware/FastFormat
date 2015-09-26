/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/internal/fastformat.c++.h
 *
 * Purpose:     FastFormat Core API C++ utilities and overloads.
 *
 * Created:     18th September 2006
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/internal/fastformat.c++.h
 *
 * [C, C++] Primary include file for the \ref group__core_library.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
# error This file is included by fastformat/fastformat.h, and cannot be included directly
#endif /* !FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus
#define FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus_MAJOR    2
# define FASTFORMAT_VER_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus_REVISION 1
# define FASTFORMAT_VER_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus_EDIT     102
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */
#ifdef FASTFORMAT_NO_NAMESPACE
# error This file cannot be included when FastFormat namespace support is suppressed
#endif

/* /////////////////////////////////////////////////////////////////////////
 * C++ API Functions
 */

/** Equivalent to \ref fastformat::fastformat_init "fastformat_init()".
 *
 * \ingroup group__init
 */
inline int init()
{
    return fastformat_init();
}

/** Equivalent to \ref fastformat::fastformat_uninit "fastformat_uninit()".
 *
 * \ingroup group__init
 */
inline void uninit()
{
    fastformat_uninit();
}

/** Equivalent to \ref fastformat::fastformat_getInitCodeString "fastformat_getInitCodeString()".
 *
 * \ingroup group__init
 */
inline ff_char_t const* getInitCodeString(int code)
{
    return fastformat_getInitCodeString(code);
}

/** Equivalent to \ref fastformat::fastformat_getInitCodeStringLength "fastformat_getInitCodeStringLength()".
 *
 * \ingroup group__init
 */
inline size_t getInitCodeStringLength(int code)
{
    return fastformat_getInitCodeStringLength(code);
}

/** Equivalent to \ref fastformat::fastformat_getProcessIllformedHandler "fastformat_getProcessIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_illformedHandler_info_t getProcessIllformedHandler()
{
    return fastformat_getProcessIllformedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setProcessIllformedHandler "fastformat_setProcessIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_illformedHandler_info_t setProcessIllformedHandler(ff_illformedHandler_info_t handler_info)
{
    return fastformat_setProcessIllformedHandler(handler_info);
}

/** Equivalent to \ref fastformat::fastformat_getThreadIllformedHandler "fastformat_getThreadIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_illformedHandler_info_t getThreadIllformedHandler()
{
    return fastformat_getThreadIllformedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setThreadIllformedHandler "fastformat_setThreadIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_illformedHandler_info_t setThreadIllformedHandler(ff_illformedHandler_info_t handler_info)
{
    return fastformat_setThreadIllformedHandler(handler_info);
}

/** Equivalent to \ref fastformat::fastformat_getProcessMismatchedHandler "fastformat_getProcessMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_mismatchedHandler_info_t getProcessMismatchedHandler()
{
    return fastformat_getProcessMismatchedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setProcessMismatchedHandler "fastformat_setProcessMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_mismatchedHandler_info_t setProcessMismatchedHandler(ff_mismatchedHandler_info_t handler_info)
{
    return fastformat_setProcessMismatchedHandler(handler_info);
}

/** Equivalent to \ref fastformat::fastformat_getThreadMismatchedHandler "fastformat_getThreadMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_mismatchedHandler_info_t getThreadMismatchedHandler()
{
    return fastformat_getThreadMismatchedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setThreadMismatchedHandler "fastformat_setThreadMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline ff_mismatchedHandler_info_t setThreadMismatchedHandler(ff_mismatchedHandler_info_t handler_info)
{
    return fastformat_setThreadMismatchedHandler(handler_info);
}

/** Equivalent to \ref fastformat::fastformat_getNewlineForPlatform "fastformat_getNewlineForPlatform()".
 *
 * \ingroup group__core_library
 */
inline string_slice_t getNewlineForPlatform()
{
    return fastformat_getNewlineForPlatform();
}

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_INTERNAL_H_FASTFORMAT_Cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */
