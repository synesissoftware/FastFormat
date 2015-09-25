/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/fastformat.h
 *
 * Purpose:     FastFormat Core API.
 *
 * Created:     18th September 2006
 * Updated:     25th September 2015
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2015, Matthew Wilson and Synesis Software
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


/** \file fastformat/fastformat.h
 *
 * [C, C++] Primary include file for the \ref group__core_library.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT
#define FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_H_FASTFORMAT_MAJOR       1
# define FASTFORMAT_VER_FASTFORMAT_H_FASTFORMAT_MINOR       21
# define FASTFORMAT_VER_FASTFORMAT_H_FASTFORMAT_REVISION    2
# define FASTFORMAT_VER_FASTFORMAT_H_FASTFORMAT_EDIT        99
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/** \def FASTFORMAT_VER_MAJOR
 * The major version number of FastFormat
 */

/** \def FASTFORMAT_VER_MINOR
 * The minor version number of FastFormat
 */

/** \def FASTFORMAT_VER_REVISION
 * The revision version number of FastFormat
 */

/** \def FASTFORMAT_VER
 * The current composite version number of FastFormat
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_0_6_1_ALPHA_1       0x00060101
# define FASTFORMAT_VER_0_6_2               0x000602ff
# define FASTFORMAT_VER_0_6_3               0x000603ff
# define FASTFORMAT_VER_0_6_4               0x000604ff
# define FASTFORMAT_VER_0_7_1_ALPHA_1       0x00070101
# define FASTFORMAT_VER_0_7_1_ALPHA_2       0x00070102
# define FASTFORMAT_VER_0_7_1_ALPHA_3       0x00070103
# define FASTFORMAT_VER_0_7_1_ALPHA_4       0x00070104
# define FASTFORMAT_VER_0_7_1_ALPHA_5       0x00070105
# define FASTFORMAT_VER_0_7_1_ALPHA_6       0x00070106
# define FASTFORMAT_VER_0_7_1_ALPHA_7       0x00070107
# define FASTFORMAT_VER_0_7_1_ALPHA_8       0x00070108
# define FASTFORMAT_VER_0_7_1_ALPHA_9       0x00070109
# define FASTFORMAT_VER_0_7_1_ALPHA_10      0x0007010a
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

#define FASTFORMAT_VER_MAJOR           0
#define FASTFORMAT_VER_MINOR           7
#define FASTFORMAT_VER_REVISION        1

#define FASTFORMAT_VER                 FASTFORMAT_VER_0_7_1_ALPHA_10

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

#include <stddef.h>     /* for size_t */

/* /////////////////////////////////////////////////////////////////////////
 * Feature detection
 */

/* By default, FastFormat is a multi-byte string library
 */
#ifndef FASTFORMAT_USE_WIDE_STRINGS
# if defined(_WIN32) && \
     defined(UNICODE) && \
     defined(_UNICODE)
#  define FASTFORMAT_USE_WIDE_STRINGS
# endif /* _WIN32 && UNICODE && _UNICODE */
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# ifndef _WCHAR_T_DEFINED
#  include <wchar.h>    /* for wchar_t (if not built-in) */
# endif /* !_WCHAR_T_DEFINED */
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#include <fastformat/internal/string_encoding.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(__cplusplus) && \
    !defined(FASTFORMAT_DOCUMENTATION_SKIP_SECTION) && \
    !defined(FASTFORMAT_NO_NAMESPACE)
# define FASTFORMAT_NO_NAMESPACE
#endif /* __cplusplus, etc. */

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** The FastFormat root namespace - \c fastformat.
 *
 * This the the root namespace for FastFormat, and contains the C-API functions, along
 * with appropriate type-defs
 */
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 3
 */

#ifdef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# include "./internal/shim_macros.h"
#else /* ? FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
# include <fastformat/internal/shim_macros.h>
#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

/** \def FASTFORMAT_DECLSPEC
 *
 * Storage class specifier to be applied to all FastFormat API functions
 *
 * \ingroup group__utility
 *
 * Defaults to no symbol. Can be defined to a symbol appropriate to the
 * operating system and linkage model. e.g. on Windows you might choose to
 * define it to <code>__declspec(dllexport)</code> when building FastFormat
 * and to <code>__declspec(dllimport)</code> in client code using FastFormat.
 *
 * Used in the FASTFORMAT_CALL() macro.
 */

/** \def FASTFORMAT_EXTERN_C
 *
 * Resolves to <code>extern</code> when compiling in C, and
 * <code>extern "C"</code> when compiling in C++.
 *
 * \ingroup group__utility
 *
 * Used in the FASTFORMAT_CALL() macro.
 */

/** \def FASTFORMAT_CALLCONV
 *
 * Calling convention specifier to be applied to all FastFormat API functions
 *
 * Used in the FASTFORMAT_CALL() macro.
 *
 * \ingroup group__utility
 */

/** \def FASTFORMAT_CALL
 *
 * Used to declare and define FastFormat API functions.
 *
 * \ingroup group__utility
 */

#if !defined(FASTFORMAT_DECLSPEC)
# define FASTFORMAT_DECLSPEC
#endif /* !FASTFORMAT_DECLSPEC */

#if defined(__cplusplus) || \
    defined(FASTFORMAT_DOCUMENTATION_SKIP_SECTION)
# define FASTFORMAT_EXTERN_C           extern "C"
#else /* ? __cplusplus */
# define FASTFORMAT_EXTERN_C           extern
#endif /* !__cplusplus */

#if !defined(FASTFORMAT_CALLCONV)
# define FASTFORMAT_CALLCONV
#endif /* !FASTFORMAT_CALLCONV */

#if defined(FASTFORMAT_DOCUMENTATION_SKIP_SECTION) || \
    !defined(FASTFORMAT_CALL)
# define FASTFORMAT_CALL(rt)           FASTFORMAT_DECLSPEC FASTFORMAT_EXTERN_C rt FASTFORMAT_CALLCONV
#endif /* !FASTFORMAT_CALL */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** Character type used by the library
 *
 * This will be <code>wchar_t</code> if
 * <code>FASTFORMAT_USE_WIDE_STRINGS</code> is defined, otherwise
 * <code>char</code>.
 */
#ifdef FASTFORMAT_USE_WIDE_STRINGS
typedef wchar_t     ff_char_t;
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
typedef char        ff_char_t;
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

/** Read-only string slice
 *
 * \ingroup group__rigging
 */
struct ff_string_slice_t
{
    size_t              len;        /*!< Length of the source string slice. */
    ff_char_t const*    ptr;        /*!< Pointer to the base of the source string slice. */
};
#ifndef __cplusplus
typedef struct ff_string_slice_t    ff_string_slice_t;
#endif /* !__cplusplus */

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to ff_string_slice_t
 */
typedef ff_string_slice_t           string_slice_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */

/** Replacement element descriptor
 *
 * \ingroup group__rigging
 */
struct ff_format_element_t;
#ifndef __cplusplus
typedef struct ff_format_element_t  ff_format_element_t;
#endif /* !__cplusplus */

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to ff_format_element_t
 */
typedef ff_format_element_t         format_element_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/** Represents format parsing conditions
 *
 * \ingroup group__format_specification_defect_handling
 */
enum ff_parse_code_t
{
        FF_PARSECODE_SUCCESS                =   0   /*!< The parsing detects no format errors. */
    ,   FF_PARSECODE_INCOMPLETEREPLACEMENT  =   1   /*!< The replacement is not complete; the terminating '}' is missing. */
    ,   FF_PARSECODE_INVALIDINDEX           =   2   /*!< The replacement is empty, or contains invalid symbols. */
};
#ifndef __cplusplus
typedef enum ff_parse_code_t            ff_parse_code_t;
#endif /* !__cplusplus */

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to ff_parse_code_t
 */
typedef ff_parse_code_t                 parse_code_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */


/** Represents parameter replacement conditions
 *
 * \ingroup group__format_specification_defect_handling
 */
enum ff_replacement_code_t
{
        FF_REPLACEMENTCODE_SUCCESS                  =   0   /*!< The replacement is successful. */
    ,   FF_REPLACEMENTCODE_MISSING_ARGUMENT         =   1   /*!< One or more required arguments are missing from the argument list. */
    ,   FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT    =   2   /*!< One or more arguments are unreferenced in the format. */
};
#ifndef __cplusplus
typedef enum ff_replacement_code_t      ff_replacement_code_t;
#endif /* !__cplusplus */

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to ff_replacement_code_t
 */
typedef ff_replacement_code_t           replacement_code_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */


/** Ill-formed format handler callback function
 *
 * \ingroup group__format_specification_defect_handling
 *
 * This function is invoked when an ill-formed format string is encountered
 * during parsing
 *
 * \param param The parameter specified, along with the function pointer, to
 *   fastformat_parseFormat()
 * \param code One of the enumerators of ff_parse_code_t
 * \param format Pointer to the format string being parsed. It may not be
 *   <code>NULL</code>, but the string it points to does not have to be
 *   nul-terminated.
 * \param formatLen The number of characters in the string pointed to by
 *   <code>format</code>
 * \param replacementIndex The 0-based index of the string fragment being
 *   parsed
 * \param defect Pointer in the string where the defect lies occurred
 * \param defectLen Length of the area of error
 * \param parameterIndex The replacement parameter number, or -1 for a
 *   literal fragment
 * \param reserved0 Reserved for future use. Must be <code>NULL</code>
 * \param reserved1 Reserved for future use. Must be zero
 * \param reserved2 Reserved for future use. Must be <code>NULL</code>
 *
 * \return Cancels, or continues, processing in light of error.
 * \retval 0 Cancel processing.
 * \retval >0 Continue processing.
 * \retval <0 Continue processing, and don't invoke this function again.
 *
 * \note The memory pointed to by <code>format</code> and
 *   <code>defect</code> is not valid outside the scope of the handler. Any
 *   implementing functions <b>must</b> copy these parameters if they wish
 *   to utilise the information outside this scope, e.g. within an
 *   exception.
 */
typedef int (FASTFORMAT_CALLCONV* fastformat_illformedHandler_t)(
    void*               param
,   ff_parse_code_t     code
,   ff_char_t const*    format
,   size_t              formatLen
,   size_t              replacementIndex
,   ff_char_t const*    defect
,   size_t              defectLen
,   int                 parameterIndex
,   void*               reserved0
,   size_t              reserved1
,   void*               reserved2
);

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to fastformat_illformedHandler_t
 */
typedef fastformat_illformedHandler_t  illformedHandler_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */

/** Structure returned from fastformat_getProcessIllformedHandler(),
 * fastformat_setProcessIllformedHandler(),
 * fastformat_getThreadIllformedHandler(), and
 * fastformat_setThreadIllformedHandler().
 *
 * \ingroup group__format_specification_defect_handling
 */
struct ff_illformed_handler_info_t
{
    fastformat_illformedHandler_t   handler;    /*!< mismatch handler */
    void*                           param;      /*!< parameter */
};

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to ff_illformed_handler_info_t
 */
typedef ff_illformed_handler_info_t     illformed_handler_info_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */

/** Mismatched replacement index handler callback function
 *
 * \ingroup group__format_specification_defect_handling
 *
 * The function can do/request one of four things:
 *
 * 1. It can throw an exception. In this case, there is no return value
 * 2. It can request that the invalid replacement parameter be left as
 *    is in the resultant string - the return value is 0
 * 3. It can request that the invalid replacement parameter be replaced with
 *    the value contained in <code>*slice</code>, to which it will write
 *    the replacement form - the return value is >0
 * 4. It can request that the current and all subsequent invalid replacement
 *    parameters be replaced with the value contained in
 *    <code>*slice</code>, to which it will write the replacement form -
 *    the return value is <0
 *
 * In cases 3 and 4, the function implementation is responsible for ensuring
 * that the contents of <code>*slice</code> remain valid until it is next
 * called. To assist with this, when the mismatched handler is invoked and
 * returns non-0 within a given replacements fill operation, a further call
 * to the handler will be made in which <code>slice</code>
 * is <code>NULL</code>, to indicate the end of the operation. This <b>does
 * not indicate</b> that the contents of <code>*slice</code> may be
 * invalidated, because the sink has not yet received the arguments, but it
 * does provide an anchor to the invocation cycle. An implementation may
 * note this sentinel value call, and know that the next time it is called
 * a new cycle will be underway, and the previously allocated memory may be
 * freed.
 *
 * \param param The caller-supplied parameter passed to fastformat_fillReplacements()
 * \param code One of the enumerators of ff_replacement_code_t. May be
 *   FF_REPLACEMENTCODE_SUCCESS (0), which ; may be 0 (success)
 * \param numParameters The number of parameters
 * \param parameterIndex The mismatched parameter index
 * \param slice A pointer to a slice to receive any replacement string for
 *   the bad parameter
 * \param reserved0 Reserved for future use. Must be <code>NULL</code>
 * \param reserved1 Reserved for future use. Must be zero
 * \param reserved2 Reserved for future use. Must be <code>NULL</code>
 *
 * \return A value that will control the behaviour of fastformat_fillReplacements()
 *
 * \note The memory pointed to by <code>format</code> and
 *   <code>defect</code> is not valid outside the scope of the handler. Any
 *   implementing functions <b>must</b> copy these parameters if they wish
 *   to utilise the information outside this scope, e.g. within an
 *   exception.
 */
typedef int (FASTFORMAT_CALLCONV* fastformat_mismatchedHandler_t)(
    void*                   param
,   ff_replacement_code_t   code
,   size_t                  numParameters
,   int                     parameterIndex
,   ff_string_slice_t*      slice
,   void*                   reserved0
,   size_t                  reserved1
,   void*                   reserved2
);

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to fastformat_mismatchedHandler_t
 */
typedef fastformat_mismatchedHandler_t  mismatchedHandler_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */

/** Structure returned from fastformat_getProcessMismatchedHandler(),
 * fastformat_setProcessMismatchedHandler(),
 * fastformat_getThreadMismatchedHandler(), and
 * fastformat_setThreadMismatchedHandler().
 *
 * \ingroup group__format_specification_defect_handling
 */
struct ff_mismatched_handler_info_t
{
    fastformat_mismatchedHandler_t  handler;    /*!< mismatch handler */
    void*                           param;      /*!< parameter */
};

#if !defined(FASTFORMAT_NO_NAMESPACE)
/** Equivalent to ff_mismatched_handler_info_t
 */
typedef ff_mismatched_handler_info_t    mismatched_handler_info_t;
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API Initialisation Functions
 */

/** Initialises the FastFormat library
 *
 * \ingroup group__init
 *
 * \return Indicates
 * \retval <0 initialisation has failed, and the library cannot be used
 * \retval >=0 initialisation has succeeded, and the library can be used.
 *   fastformat_uninit() should be called when the library is no longer
 *   needed
 *
 * \note C++ compilation units that include fastformat/fastformat.hpp do not
 *   need to explicitly call FastFormat_init() / FastFormat_uninit(), since
 *   they will be automatically called by the FastFormat_initialiser Schwarz
 *   counter class defined by the C++ inclusion. Further note that this is
 *   disabled by the definition of the <code>FASTFORMAT_NO_AUTO_INIT</code>,
 *   which is  automatically defined by a Windows DLL build (as detected by
 *   the presence of any of the <code>__DLL__</code>, <code>_WINDLL</code>
 *   or <code>_USRDLL</code> symbols).
 *   Auto-initialisation can be forced regardless of the definition of
 *   <code>FASTFORMAT_NO_AUTO_INIT</code> by the definition of the symbol
 *   <code>FASTFORMAT_FORCE_AUTO_INIT</code>.
 */
FASTFORMAT_CALL(int)
fastformat_init(void);

/** Uninitialises the FastFormat library.
 *
 * \ingroup group__init
 *
 * Should be called for every call to fastformat_init() that returns a
 * non-negative code
 *
 * \note C++ compilation units that include fastformat/fastformat.hpp do not
 *   need to explicitly call fastformat_init() / fastformat_uninit(), since
 *   they will be automatically called by the fastformat_initialiser Schwarz
 *   counter class defined by the C++ inclusion. Further note that this is
 *   disabled by the definition of the <code>FASTFORMAT_NO_AUTO_INIT</code>,
 *   which is  automatically defined by a Windows DLL build (as detected by
 *   the presence of any of the <code>__DLL__</code>, <code>_WINDLL</code>,
 *   <code>_USRDLL</code> or <code>_AFXDLL</code> symbols).
 *   Auto-initialisation can be forced regardless of the definition of
 *   <code>FASTFORMAT_NO_AUTO_INIT</code> by the definition of the symbol
 *   <code>FASTFORMAT_FORCE_AUTO_INIT</code>.
 */
FASTFORMAT_CALL(void)
fastformat_uninit(void);

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
FASTFORMAT_CALL(void)
fastformat_exitProcess(int code);
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/** Returns a constant pointer to a non-NULL non-modifiable nul-terminated string
 * representing the initialisation code.
 *
 * \ingroup group__init
 *
 * \param code The initialisation code whose string explanation is to be
 *   returned. If the code is not recognised, the empty
 *   string (<code>""</code>) will be returned.
 */
FASTFORMAT_CALL(ff_char_t const*)
fastformat_getInitCodeString(int code);

/** Returns the length of the string returned by fastformat_getInitCodeString().
 *
 * \ingroup group__init
 *
 * \param code The initialisation code whose string equivalent is to be
 *   returned. If the code is not recognised, 0 will be returned.
 */
FASTFORMAT_CALL(size_t)
fastformat_getInitCodeStringLength(int code);

#ifndef FASTFORMAT_NO_NAMESPACE
/** Equivalent to \ref fastformat::fastformat_init "fastformat_init()".
 *
 * \ingroup group__init
 */
inline
int
init()
{
    return fastformat_init();
}

/** Equivalent to \ref fastformat::fastformat_uninit "fastformat_uninit()".
 *
 * \ingroup group__init
 */
inline
void
uninit()
{
    fastformat_uninit();
}

/** Equivalent to \ref fastformat::fastformat_getInitCodeString "fastformat_getInitCodeString()".
 *
 * \ingroup group__init
 */
inline
ff_char_t const*
getInitCodeString(int code)
{
    return fastformat_getInitCodeString(code);
}

/** Equivalent to \ref fastformat::fastformat_getInitCodeStringLength "fastformat_getInitCodeStringLength()".
 *
 * \ingroup group__init
 */
inline
size_t
getInitCodeStringLength(int code)
{
    return fastformat_getInitCodeStringLength(code);
}
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Failure-handling Functions
 */

/** Gets the ill-formed format handler for the calling process
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \return The handler for the process
 */
FASTFORMAT_CALL(ff_illformed_handler_info_t)
fastformat_getProcessIllformedHandler(void);

/** Sets the ill-formed format handler for the calling process
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \param handler The new handler for the process
 * \param param The parameter associated with the handler
 *
 * \return The previous handler for the process
 */
FASTFORMAT_CALL(ff_illformed_handler_info_t)
fastformat_setProcessIllformedHandler(fastformat_illformedHandler_t handler, void* param);

/** Gets the ill-formed format handler for the calling thread
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \return The handler for the thread
 */
FASTFORMAT_CALL(ff_illformed_handler_info_t)
fastformat_getThreadIllformedHandler(void);

/** Sets the ill-formed format handler for the calling thread
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \param handler The new handler for the thread
 * \param param The parameter associated with the handler
 *
 * \return The previous handler for the thread
 */
FASTFORMAT_CALL(ff_illformed_handler_info_t)
fastformat_setThreadIllformedHandler(fastformat_illformedHandler_t handler, void* param);

/** Gets the default ill-formed format handler
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \return The default handler
 */
FASTFORMAT_CALL(ff_illformed_handler_info_t)
fastformat_getDefaultIllformedHandler(void);


/** Gets the mismatched parameter handler for the calling process
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \return The handler for the process
 */
FASTFORMAT_CALL(ff_mismatched_handler_info_t)
fastformat_getProcessMismatchedHandler(void);

/** Sets the mismatched parameter handler for the calling process
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \param handler The new handler for the process
 * \param param The parameter associated with the handler
 *
 * \return The previous handler for the process
 */
FASTFORMAT_CALL(ff_mismatched_handler_info_t)
fastformat_setProcessMismatchedHandler(fastformat_mismatchedHandler_t handler, void* param);

/** Gets the mismatched parameter handler for the calling thread
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \return The handler for the thread
 */
FASTFORMAT_CALL(ff_mismatched_handler_info_t)
fastformat_getThreadMismatchedHandler(void);

/** Sets the mismatched parameter handler for the calling thread
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \param handler The new handler for the thread
 * \param param The parameter associated with the handler
 *
 * \return The previous handler for the thread
 */
FASTFORMAT_CALL(ff_mismatched_handler_info_t)
fastformat_setThreadMismatchedHandler(fastformat_mismatchedHandler_t handler, void* param);

/** Gets the default mismatched parameter handler
 *
 * \ingroup group__format_specification_defect_handling
 *
 * \return The default handler
 */
FASTFORMAT_CALL(ff_mismatched_handler_info_t)
fastformat_getDefaultMismatchedHandler(void);

/* /////////////////////////////////////////////////////////////////////////
 * API Parsing Functions
 */

/** Calculates the exact number of replacements required for the given
 *   format
 *
 * \ingroup group__core_library
 *
 * \param format Pointer to the format string. Does not have to be
 *   nul-terminated. May not be NULL, unless <code>cchFormat</code> is 0
 * \param cchFormat Number of characters in the string pointed to by
 *   <code>format</code>
 *
 * \pre (0 == cchFormat || NULL != format)
 */
FASTFORMAT_CALL(size_t)
fastformat_calculateNumberOfRequiredReplacements(
    ff_char_t const*    format
,   size_t              cchFormat
);

/** Parses a format string into an array of replacement element descriptors
 *
 * \ingroup group__core_library
 *
 * \param format Pointer to the format string. Does not have to be
 *   nul-terminated. May not be NULL, unless <code>cchFormat</code> is 0
 * \param cchFormat Number of characters in the string pointed to by
 *   <code>format</code>
 * \param formatElements Pointer to an array of replacements into which the
 *   parsed replacement slices are written
 * \param numFormatElements Number of format elements
 * \param handler Handler for ill-formed format
 * \param param Parameter to be passed to handler
 *
 * \pre (0 == cchFormat || NULL != format)
 * \pre The number of replacements provided <b>must</b> be of sufficient
 *   size for the given format. To obtain the exact number required
 *   guaranteed to be sufficient, call
 *   fastformat_calculateNumberOfRequiredReplacements(). To obtain a quick
 *   value guaranteed to be sufficient, use the format length divided by
 *   2.
 *
 * \return Information describing the number of elements written/required
 */

FASTFORMAT_CALL(unsigned)
fastformat_parseFormat(
    ff_char_t const*                format
,   size_t                          cchFormat
,   ff_format_element_t*            formatElements
,   size_t                          numFormatElements
,   fastformat_illformedHandler_t   handler
,   void*                           param
);

/** Takes a number of pattern and replacement elements and populates an
 *   array of result elements.
 *
 * \ingroup group__core_library
 *
 * \param resultElements        Pointer to an array of result elements. This must have at least the number of elements indicated for the pattern elements.
 * \param formatElements        Pointer to an array of pattern elements.
 * \param numElements           Number of pattern elements.
 * \param arguments             Pointer to an array of replacement parameters.
 * \param numArguments          The number of replacement parameters.
 * \param handler               A handler to be invoked in the event of a mismatch between the format elements and the arguments.
 * \param param                 A parameter to be passed through to the handler.
 * \param pnumResultElements    Pointer to variable to receive the number of result elements. This may be greater than the number of pattern elements in the case where formatting (width) is applied
 *
 * \return The total number of characters required in the resultant string.
 */
FASTFORMAT_CALL(size_t)
fastformat_fillReplacements(
    ff_string_slice_t*              resultElements
,   ff_format_element_t const*      formatElements
,   size_t                          numElements
,   ff_string_slice_t const*        arguments
,   size_t                          numArguments
,   fastformat_mismatchedHandler_t  handler
,   void*                           param
,   size_t*                         pnumResultElements
);

/** Calculates the total length of an array of string slices
 *
 * \ingroup group__core_library
 */
FASTFORMAT_CALL(size_t)
fastformat_accumulateSliceLengths(
    size_t                      numSlices
,   ff_string_slice_t const*    slices
);

/* /////////////////////////////////////////////////////////////////////////
 * API Format Caching Functions
 */

/** Looks up the array of replacement element descriptors, corresponding to
 *   the given pattern, from the pattern cache
 *
 * \ingroup group__core_library
 *
 * \param pattern Pointer to an array of characters representing the string
 * \param cchPattern The number of characters in the string parameter
 *   <code>pattern</code>
 * \param elements Pointer to a variable to receive the pointer to the
 *   array of replacement element descriptors.
 *
 * \return The number of replacement element descriptors.
 */
FASTFORMAT_CALL(unsigned)
fastformat_lookupPattern(
    ff_char_t const*            pattern
,   size_t                      cchPattern
,   ff_format_element_t const** elements
);

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
FASTFORMAT_CALL(ff_char_t const*) fastformat_getSpacesSlice(size_t len);
FASTFORMAT_CALL(ff_char_t const*) fastformat_getHashesSlice(size_t len);
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * API Utility Functions
 */

/** Returns a slice representing the CR/LF combination for the current
 *   platform
 */
FASTFORMAT_CALL(ff_string_slice_t)
fastformat_getNewlineForPlatform(void);

/* /////////////////////////////////////////////////////////////////////////
 * C++ API Functions
 */

#ifndef FASTFORMAT_NO_NAMESPACE

/** Equivalent to \ref fastformat::fastformat_getProcessIllformedHandler "fastformat_getProcessIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_illformed_handler_info_t
getProcessIllformedHandler()
{
    return fastformat_getProcessIllformedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setProcessIllformedHandler "fastformat_setProcessIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_illformed_handler_info_t
setProcessIllformedHandler(illformedHandler_t handler, void* param)
{
    return fastformat_setProcessIllformedHandler(handler, param);
}

/** Equivalent to \ref fastformat::fastformat_getThreadIllformedHandler "fastformat_getThreadIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_illformed_handler_info_t
getThreadIllformedHandler()
{
    return fastformat_getThreadIllformedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setThreadIllformedHandler "fastformat_setThreadIllformedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_illformed_handler_info_t
setThreadIllformedHandler(illformedHandler_t handler, void* param)
{
    return fastformat_setThreadIllformedHandler(handler, param);
}

/** Equivalent to \ref fastformat::fastformat_getProcessMismatchedHandler "fastformat_getProcessMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_mismatched_handler_info_t
getProcessMismatchedHandler()
{
    return fastformat_getProcessMismatchedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setProcessMismatchedHandler "fastformat_setProcessMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_mismatched_handler_info_t
setProcessMismatchedHandler(mismatchedHandler_t handler, void* param)
{
    return fastformat_setProcessMismatchedHandler(handler, param);
}

/** Equivalent to \ref fastformat::fastformat_getThreadMismatchedHandler "fastformat_getThreadMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_mismatched_handler_info_t
getThreadMismatchedHandler()
{
    return fastformat_getThreadMismatchedHandler();
}

/** Equivalent to \ref fastformat::fastformat_setThreadMismatchedHandler "fastformat_setThreadMismatchedHandler()".
 *
 * \ingroup group__format_specification_defect_handling
 */
inline
ff_mismatched_handler_info_t
setThreadMismatchedHandler(mismatchedHandler_t handler, void* param)
{
    return fastformat_setThreadMismatchedHandler(handler, param);
}

/** Equivalent to \ref fastformat::fastformat_getNewlineForPlatform "fastformat_getNewlineForPlatform()".
 *
 * \ingroup group__core_library
 */
inline
string_slice_t
getNewlineForPlatform()
{
    return fastformat_getNewlineForPlatform();
}

#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Internal functions
 */

# ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
/*
 * \ingroup group__core_library
 *
 * \param cb The number of bytes to allocate
 *
 * \return the NULL pointer if allocation failed, otherwise a pointer to a
 *   correctly aligned block of bytes, all of whose values are 0x00.
 */
FASTFORMAT_CALL(void*) fastformat_malloc(size_t cb);
# endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * String Access Shims
 */

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the slice */
inline
#ifdef FASTFORMAT_USE_WIDE_STRINGS
wchar_t const*
c_str_data_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
char const* c_str_data_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
    ff_string_slice_t const&
    slice
)
{
    return slice.ptr;
}

/** Returns a possibly non-nul-terminated non-NULL C-style string representing the slice */
inline
ff_char_t const* c_str_data(
    ff_string_slice_t const&
    slice
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_data_w(slice);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_data_a(slice);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/** Returns the number of characters in the length of the C-style string representing the slice */
inline
#ifdef FASTFORMAT_USE_WIDE_STRINGS
size_t
c_str_len_w(
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
size_t c_str_len_a(
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
    ff_string_slice_t const&
    slice
)
{
    return slice.len;
}

/** Returns the number of characters in the length of the C-style string representing the slice */
inline
size_t c_str_len(
    ff_string_slice_t const&
    slice
)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
    return c_str_len_w(slice);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    return c_str_len_a(slice);
#endif /* !FASTFORMAT_USE_WIDE_STRINGS */
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)

/** FastFormat utility namespace
 *
 * \warning All entities defined within any sub-namespace whose name begins
 *   with <code>ximpl_</code> are subject to change without warning on any
 *   release, including revision releases.
 */
namespace util
{}

/** Namespace within which FastFormat filtering conversion shim functions
 *   are defined.
 *
 * \remarks This namespace is designed to contain the filter_type()
 *   conversion shim, and is open for extension by users who may define
 *   their own overloads of the shim
 *
 * \warning All entities defined within any sub-namespace whose name begins
 *   with <code>ximpl_</code> are subject to change without warning on any
 *   release, including revision releases.
 */
namespace filters
{}

/** Namespace within which FastFormat flag constants (of type <code>int</code>)
 *   are defined.
 *
 *
 * \warning All entities defined within any sub-namespace whose name begins
 *   with <code>ximpl_</code> are subject to change without warning on any
 *   release, including revision releases.
 */
namespace flags
{}

/** Namespace within which FastFormat iterators are defined.
 *
 *
 * \warning All entities defined within any sub-namespace whose name begins
 *   with <code>ximpl_</code> are subject to change without warning on any
 *   release, including revision releases.
 */
namespace iterators
{}

/** Namespace within which FastFormat sink functions are defined
 *
 * \remarks This namespace is designed to contain the fmt_slices()
 *   action shim, and is open for extension by users who may define
 *   their own overloads of the shim
 *
 * \warning All entities defined within any sub-namespace whose name begins
 *   with <code>ximpl_</code> are subject to change without warning on any
 *   release, including revision releases.
 */
namespace sinks
{}

/** Namespace within which internal FastFormat types and functions are defined
 *
 * \warning All entities defined within this namespace are subject to change
 *   without warning on any release, including revision releases.
 *
 * \warning All entities defined within any sub-namespace whose name begins
 *   with <code>ximpl_</code> are subject to change without warning on any
 *   release, including revision releases.
 */
namespace internal
{}

} /* namespace fastformat */


# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

#  ifdef FASTFORMAT_USE_WIDE_STRINGS
    using ::fastformat::c_str_data_w;
    using ::fastformat::c_str_len_w;
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    using ::fastformat::c_str_data_a;
    using ::fastformat::c_str_len_a;
#  endif /* FASTFORMAT_USE_WIDE_STRINGS */
    using ::fastformat::c_str_data;
    using ::fastformat::c_str_len;

# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */


#else /* ? !FASTFORMAT_NO_NAMESPACE */

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{

inline
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
wchar_t const*
c_str_data_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
char const* c_str_data_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
    ff_string_slice_t const&
    slice
)
{
    return slice.ptr;
}

inline
ff_char_t const* c_str_data(
    ff_string_slice_t const&
    slice
)
{
    return slice.ptr;
}

inline
#  ifdef FASTFORMAT_USE_WIDE_STRINGS
size_t
c_str_len_w(
#  else /* ? FASTFORMAT_USE_WIDE_STRINGS */
size_t c_str_len_a(
#  endif /* !FASTFORMAT_USE_WIDE_STRINGS */
    ff_string_slice_t const&
    slice
)
{
    return slice.len;
}

inline
size_t c_str_len(
    ff_string_slice_t const&
    slice
)
{
    return slice.len;
}

} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_H_FASTFORMAT */

/* ///////////////////////////// end of file //////////////////////////// */
