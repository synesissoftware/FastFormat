/* /////////////////////////////////////////////////////////////////////////
 * File:        src/enum_strings.cpp
 *
 * Purpose:     Parse code strings for FastFormat API
 *
 * Created:     11th November 2013
 * Updated:     6th February 2024
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2013-2019, Matthew Wilson and Synesis Software
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
 * includes
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
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

template <typename E>
struct mapping_t
{
    E                   code;   /*!< The enumeration code. */
    ff_char_t const*    str;    /*!< The string.        */
    size_t              len;    /*!< The string length. */
};

static ff_char_t s_emptyString[1] = { '\0' };


#define INIT_ERR_STR_DECL(enumeration, rc, desc)                                                                \
                                                                                                                \
    static const ff_char_t              s_str##rc[] =   FASTFORMAT_LITERAL_STRING(desc);                        \
    static const mapping_t<enumeration> s_rct##rc   =   { rc, s_str##rc, STLSOFT_NUM_ELEMENTS(s_str##rc) - 1 }


#define INIT_ERR_STR_ENTRY(rc)                                                          \
                                                                                        \
    &s_rct##rc


template <typename M>
ff_char_t const*
fastformat_LookupCodeA_(
    int             code
,   M const* const* mappings
,   size_t          cMappings
,   size_t*         len
)
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

/* ///////////////////////////////////////////////
 * ff_parse_code_t
 */

static
ff_char_t const*
fastformat_LookupParseCodeStringA_(
    ff_parse_code_t parseCode
,   size_t*         len
)
{
    INIT_ERR_STR_DECL(ff_parse_code_t, FF_PARSECODE_SUCCESS                 ,   "parsing operation completed successfully"                  );
    INIT_ERR_STR_DECL(ff_parse_code_t, FF_PARSECODE_INCOMPLETEREPLACEMENT   ,   "an incomplete replacement parameter was encountered"       );
    INIT_ERR_STR_DECL(ff_parse_code_t, FF_PARSECODE_INVALIDINDEX            ,   "an invalid replacement parameter index was encountered"    );

    static const mapping_t<ff_parse_code_t>* const s_mappings[] =
    {
        INIT_ERR_STR_ENTRY(FF_PARSECODE_SUCCESS              ),
        INIT_ERR_STR_ENTRY(FF_PARSECODE_INCOMPLETEREPLACEMENT),
        INIT_ERR_STR_ENTRY(FF_PARSECODE_INVALIDINDEX         ),
    };

    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_LookupCodeA_((int)parseCode, s_mappings, STLSOFT_NUM_ELEMENTS(s_mappings), len);
}

FASTFORMAT_CALL(ff_char_t const*) fastformat_getParseCodeString(ff_parse_code_t parseCode)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_LookupParseCodeStringA_(parseCode, NULL);
}

FASTFORMAT_CALL(size_t) fastformat_getParseCodeStringLength(ff_parse_code_t parseCode)
{
    size_t  len;

    FASTFORMAT_COVER_MARK_ENTRY();

    return (fastformat_LookupParseCodeStringA_(parseCode, &len), len);
}

/* ///////////////////////////////////////////////
 * ff_replacement_code_t
 */

static
ff_char_t const*
fastformat_LookupReplacementCodeStringA_(
    ff_replacement_code_t   replacementCode
,   size_t*                 len
)
{
    INIT_ERR_STR_DECL(ff_replacement_code_t, FF_REPLACEMENTCODE_SUCCESS                 ,   "replacement operation completed successfully"              );
    INIT_ERR_STR_DECL(ff_replacement_code_t, FF_REPLACEMENTCODE_MISSING_ARGUMENT        ,   "one or more arguments were not supplied by the caller"     );
    INIT_ERR_STR_DECL(ff_replacement_code_t, FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT   ,   "one or more arguments were not referenced in the format"   );

    static const mapping_t<ff_replacement_code_t>* const s_mappings[] =
    {
        INIT_ERR_STR_ENTRY(FF_REPLACEMENTCODE_SUCCESS               ),
        INIT_ERR_STR_ENTRY(FF_REPLACEMENTCODE_MISSING_ARGUMENT      ),
        INIT_ERR_STR_ENTRY(FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT ),
    };

    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_LookupCodeA_((int)replacementCode, s_mappings, STLSOFT_NUM_ELEMENTS(s_mappings), len);
}

FASTFORMAT_CALL(ff_char_t const*) fastformat_getReplacementCodeString(ff_replacement_code_t replacementCode)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    return fastformat_LookupReplacementCodeStringA_(replacementCode, NULL);
}

FASTFORMAT_CALL(size_t) fastformat_getReplacementCodeStringLength(ff_replacement_code_t replacementCode)
{
    size_t  len;

    FASTFORMAT_COVER_MARK_ENTRY();

    return (fastformat_LookupReplacementCodeStringA_(replacementCode, &len), len);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
