/* /////////////////////////////////////////////////////////////////////////
 * File:        src/init_code_strings.cpp
 *
 * Purpose:     Initialisation code strings for FastFormat API
 *
 * Created:     27th May 2008
 * Updated:     6th February 2024
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "ximpl_core.hpp"
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif
#include <fastformat/internal/threading.h>
#include <fastformat/init_codes.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

#ifdef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
struct InitCodeString
#else /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
# define InitCodeString        fastformat_src_util_InitCodeString
typedef struct InitCodeString  InitCodeString;
struct InitCodeString
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
{
    int                 code;   /*!< The initialisation code.   */
    ff_char_t const*    str;    /*!< The string.                */
    size_t              len;    /*!< The string length.         */
};

static ff_char_t s_emptyString[1] = { '\0' };


#define INIT_ERR_STR_DECL(rc, desc)                                                     \
                                                                                        \
    static const ff_char_t       s_str##rc[] =   FASTFORMAT_LITERAL_STRING(desc);       \
    static const InitCodeString s_rct##rc = { rc, s_str##rc, STLSOFT_NUM_ELEMENTS(s_str##rc) - 1 }


#define INIT_ERR_STR_ENTRY(rc)                                                          \
                                                                                        \
    &s_rct##rc


static ff_char_t const* fastformat_LookupCodeA_(int code, InitCodeString const** mappings, size_t cMappings, size_t* len)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    /* Use Null Object (Variable) here for len, so do not need to check
     * elsewhere.
     */
    size_t  len_;

    if(NULL == len)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        len = &len_;
    }

    /* Linear search. */
    { size_t i; for(i = 0; i < cMappings; ++i)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        if(code == mappings[i]->code)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            return (*len = mappings[i]->len, mappings[i]->str);
        }
    }}

    FASTFORMAT_COVER_MARK_ENTRY();

    return (*len = 0, s_emptyString);
}

static ff_char_t const* fastformat_LookupInitCodeStringA_(int code, size_t* len)
{
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_SUCCESS                             ,   "operation completed successfully"              );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_OUT_OF_MEMORY                       ,   "out of memory"                                 );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION               ,   "unspecified exception"                         );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_UNKNOWN_ERROR                       ,   "unknown error"                                 );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR                   ,   "unspecified error"                             );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_NOT_IMPLEMENTED                     ,   "feature not implemented"                       );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_CANNOT_CREATE_TSS_INDEX             ,   "cannot create TSS index"                       );
    INIT_ERR_STR_DECL(FASTFORMAT_INIT_RC_CANNOT_CREATE_THREAD                ,   "cannot create thread"                          );

    static const InitCodeString* s_strings[] =
    {
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_SUCCESS                    ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_OUT_OF_MEMORY              ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION      ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_UNKNOWN_ERROR              ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR          ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_NOT_IMPLEMENTED            ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_CANNOT_CREATE_TSS_INDEX    ),
        INIT_ERR_STR_ENTRY(FASTFORMAT_INIT_RC_CANNOT_CREATE_THREAD       ),
    };

    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_LookupCodeA_(code, s_strings, STLSOFT_NUM_ELEMENTS(s_strings), len);
}

FASTFORMAT_CALL(ff_char_t const*) fastformat_getInitCodeString(int code)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_LookupInitCodeStringA_((int)code, NULL);
}

FASTFORMAT_CALL(size_t) fastformat_getInitCodeStringLength(int code)
{
    size_t  len;

    FASTFORMAT_COVER_MARK_ENTRY();

    return (fastformat_LookupInitCodeStringA_((int)code, &len), len);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
