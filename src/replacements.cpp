/* /////////////////////////////////////////////////////////////////////////
 * File:        src/replacements.cpp
 *
 * Purpose:     Implementation file for FastFormat core API: replacements.
 *
 * Created:     18th September 2006
 * Updated:     22nd August 2015
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



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

// #define FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS // This is not defined by default, but unreferenced arguments are not always a defect

#include "ximpl_core.hpp"
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif
#include <fastformat/internal/format_element.h>
#include <fastformat/internal/threading.h>
#include <fastformat/exceptions.hpp>
#include <fastformat/init_codes.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/conversion/truncation_test.hpp>
#include <stlsoft/iterators/member_selector_iterator.hpp>
#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string/std/c_string.h>
#include <stlsoft/string/tokeniser_functions.hpp> // for find_next_token

#include <algorithm>
#include <numeric>
#include <map>
#include <stdexcept>

#include <ctype.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define fastformat_strtol_     ::wcstol
# define fastformat_strchr_     ::wcschr
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define fastformat_strtol_     ::strtol
# define fastformat_strchr_     ::strchr
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

namespace
{
#if !defined(FASTFORMAT_NO_NAMESPACE)
    using fastformat::ff_char_t;
    using fastformat::ff_parse_code_t;
    using fastformat::format_element_t;
    using fastformat::ff_format_element_alignment_t_;
    using fastformat::ff_format_element_width_t_;
    using fastformat::FASTFORMAT_ALIGNMENT_NONE;
    using fastformat::FASTFORMAT_ALIGNMENT_LEFT;
    using fastformat::FASTFORMAT_ALIGNMENT_RIGHT;
    using fastformat::FASTFORMAT_ALIGNMENT_CENTRE;
    using fastformat::FF_PARSECODE_SUCCESS;
    using fastformat::FF_PARSECODE_INCOMPLETEREPLACEMENT;
    using fastformat::FF_PARSECODE_INVALIDINDEX;
#endif /* !FASTFORMAT_NO_NAMESPACE */

    typedef int unreferenced_argument_flag_t;   // TODO: establish whether using bool is faster; (unlikely)

    enum alignment_t
    {
            unspecified
        ,   left
        ,   centre
        ,   right
        ,   hashFill
    };

    enum
    {
            foundIndex      =   0x01
        ,   foundMinWidth   =   0x02
        ,   foundMaxWidth   =   0x04
        ,   foundAlign      =   0x08
        ,   foundFill       =   0x10
    };

    enum
    {
            FF_ILLFORMED_EMPTY_PARAMETER_       =   -1001
        ,   FF_ILLFORMED_INVALID_INDEX_
        ,   FF_ILLFORMED_INVALID_MIN_WIDTH_
        ,   FF_ILLFORMED_INVALID_MAX_WIDTH_
        ,   FF_ILLFORMED_INVALID_ALIGN_CHAR_
        ,   FF_ILLFORMED_INVALID_FILL_CHAR_
        ,   FF_ILLFORMED_INVALID_ALIGN_FIELD_
        ,   FF_ILLFORMED_SURPLUS_FIELD_
    };

    static const ff_char_t ValidFillCharacters[] = FASTFORMAT_LITERAL_STRING("# ");

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////////
 * Functions
 */

namespace
{
    // There are three possible fields:
    //
    //  1. The parameter index. Mandatory. Must be non-negative. Terminated with ',' or '}'
    //  2. The width(s) specification. Optional. Can contain only digits and '-'. Terminated with ',' or '}'
    //  3. The alignment specification. Optional. Can only be the character '<' or '>'. Terminated with '}'
    //
    // {0}          =>  index = 0, exact width
    // {0,10}       =>  index = 0, min-width = 10, right-aligned (default)
    // {0,10,<}     =>  index = 0, min-width = 10, left-aligned
    // {0,10,>}     =>  index = 0, min-width = 10, right-aligned
    // {0,10,^}     =>  index = 0, min-width = 10, centre-aligned ???
    // {0,10-20,<}  =>  index = 0, min-width = 10, max-width=20, left-aligned
    // {0,-20,<}    =>  index = 0, max-width=20, left-aligned

    // TODO: replace with STLSoft 1.10+'s stlsoft::string_to_integer
    // function template
    inline long strtol_dec(ff_char_t const* s, ff_char_t** endptr)
    {
        return fastformat_strtol_(s, endptr, 10);
    }

    inline ff_parse_code_t code_from_index_(int index)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(index < 0, "must be negative (i.e. in error)");

        // TODO: flesh out with more parse codes

        switch(index)
        {
            case    FF_ILLFORMED_EMPTY_PARAMETER_:
                break;
            case    FF_ILLFORMED_INVALID_INDEX_:
                break;
            case    FF_ILLFORMED_INVALID_MIN_WIDTH_:
                break;
            case    FF_ILLFORMED_INVALID_MAX_WIDTH_:
                break;
            case    FF_ILLFORMED_INVALID_ALIGN_CHAR_:
                break;
            case    FF_ILLFORMED_INVALID_FILL_CHAR_:
                break;
            case    FF_ILLFORMED_INVALID_ALIGN_FIELD_:
                break;
            case    FF_ILLFORMED_SURPLUS_FIELD_:
                break;
            default:
                break;
        }

        return FF_PARSECODE_INVALIDINDEX;
    }

    // This function writes the (defectively-specified) parameter into the
    // format element as a literal, and updates the counters. It does NOT
    // update the pointer(s)
    inline void record_parameter_as_literal_(
        ff_char_t const*        p0
    ,   ff_char_t const* const  p1
    ,   format_element_t*       formatElements
    ,   unsigned&               num
    ,   unsigned&               numRes
    )
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != p0, "p0 may not be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != p1, "p1 may not be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(p0 < p1, "p1 must be later than p0");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL('{' == *p0, "p0 must point to opening character");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL('}' == *p1, "p1 must point to closing character");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != formatElements, "format elements pointer may not be null");

        formatElements[num].ptr   =   p0;
        formatElements[num].len   =   static_cast<size_t>((p1 + 1) - p0);
        formatElements[num].index =   FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_;

        ++num;
        ++numRes;
    }

    inline int parse_replacement_find_next_token(
        ff_char_t const*        start
    ,   ff_char_t const* const  end
    ,   format_element_t*       formatElement
    )
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != start, "start may not be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != end, "end may not be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(start < end, "end must be later than start");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL('{' == *start, "start must point to opening character");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL('}' == *end, "end must point to closing character");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != formatElement, "format element pointer may not be null");

        int                 res =   0;
        ff_char_t const*    p0  =   start + 1;
        ff_char_t const*    p1  =   p0;

        // Field 0: index
        stlsoft::find_next_token(p0, p1, end, FASTFORMAT_LITERAL_CHARACTER(','));
        if(p0 == p1)
        {
            return FF_ILLFORMED_EMPTY_PARAMETER_; // Empty parameter
        }
        else
        {
            ff_char_t*  endptr;
            long        result = strtol_dec(p0, &endptr);

            if(p1 != endptr)
            {
                return FF_ILLFORMED_INVALID_INDEX_;
            }

            formatElement->index = int(result);

            if(formatElement->index < 0)
            {
                return FF_ILLFORMED_INVALID_INDEX_;
            }

            res |= foundIndex;
        }

        if(end != p1)
        {
            // Field 1: minimum width
            stlsoft::find_next_token(p0, p1, end, FASTFORMAT_LITERAL_CHARACTER(','));
            if(p1 != p0)
            {
                ff_char_t*  endptr;
                long        result = strtol_dec(p0, &endptr);

                if(p1 != endptr)
                {
                    return FF_ILLFORMED_INVALID_MIN_WIDTH_;
                }

                formatElement->minWidth = short(result);

                if(formatElement->minWidth < 0)
                {
                    return FF_ILLFORMED_INVALID_MIN_WIDTH_;
                }

                res |= foundMinWidth;
            }

            // Field 2: maximum width
            stlsoft::find_next_token(p0, p1, end, FASTFORMAT_LITERAL_CHARACTER(','));
            if(p1 != p0)
            {
                ff_char_t*  endptr;
                long        result = strtol_dec(p0, &endptr);

                if(p1 != endptr)
                {
                    return FF_ILLFORMED_INVALID_MAX_WIDTH_;
                }

                formatElement->maxWidth = short(result);

                if(formatElement->maxWidth < 0)
                {
                    return FF_ILLFORMED_INVALID_MAX_WIDTH_;
                }

                res |= foundMaxWidth;
            }

            stlsoft::find_next_token(p0, p1, end, FASTFORMAT_LITERAL_CHARACTER(','));
            if(p1 != p0)
            {
                // Field 3: alignment
                if(p1 != p0)
                {
                    switch(p0[0])
                    {
                        default:
                            return FF_ILLFORMED_INVALID_ALIGN_CHAR_; // Invalid alignment
                        case    '<':
                            formatElement->alignment = FASTFORMAT_ALIGNMENT_LEFT;
                            break;
                        case    '>':
                            formatElement->alignment = FASTFORMAT_ALIGNMENT_RIGHT;
                            break;
                        case    '^':
                            formatElement->alignment = FASTFORMAT_ALIGNMENT_CENTRE;
                            break;
                    }

                    res |= foundAlign;
                    ++p0;
                }

                // Field 4: fill
                if(p1 != p0)
                {
                    if(NULL == fastformat_strchr_(ValidFillCharacters, 0[p0]))
                    {
                        return FF_ILLFORMED_INVALID_FILL_CHAR_;
                    }

                    formatElement->fill = p0[0];
                    res |= foundFill;
                    ++p0;
                }
            }

            if(p1 != p0)
            {
                return FF_ILLFORMED_INVALID_ALIGN_FIELD_; // Invalid argument
            }
        }

        if(p1 != end)
        {
            return FF_ILLFORMED_SURPLUS_FIELD_;
        }

        return res;
    }

    // This function parses and writes the (correctly-specified) parameter
    // into the format element as a literal, and updates the counters. It
    // does NOT update the pointer(s)
    inline int parse_parameter_(
        ff_char_t const*        p0
    ,   ff_char_t const* const  p1
    ,   format_element_t*       formatElements
    ,   unsigned&               num
    ,   unsigned&               numRes
    )
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != p0, "p0 may not be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != p1, "p1 may not be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(p0 < p1, "p1 must be later than p0");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL('{' == *p0, "p0 must point to opening character");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL('}' == *p1, "p1 must point to closing character");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != formatElements, "format elements pointer may not be null");

        format_element_t& element = formatElements[num];

        int res = parse_replacement_find_next_token(p0, p1, &element);

        if(res < 0)
        {
            return res;
        }
        else
        {
            // Valid parameter: record it, and adjust contents

            element.ptr   =   p0;
            element.len   =   static_cast<size_t>((p1 + 1) - p0);

            ++num;
            ++numRes;

            // Field 0: index
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(0 != (res & foundIndex));

            // Field 3: alignment
            //
            // NOTE: Have to do alignment before minWidth
            if(0 == (res & foundAlign))
            {
                element.alignment = FASTFORMAT_ALIGNMENT_NONE;
            }

            // Field 1: minimum width

            if(0 == (res & foundMinWidth))
            {
                element.minWidth = 0;
            }

            if(0 != element.minWidth)
            {
                ++numRes;

                if(FASTFORMAT_ALIGNMENT_CENTRE == element.alignment)
                {
                    ++numRes;
                }
            }

            // Field 2: maximum width

            if(0 == (res & foundMaxWidth))
            {
                element.maxWidth = -1;
            }

            // Field 4: fill
            if(0 == (res & foundFill))
            {
                element.fill = ' ';
            }

            return element.index;
        }
    }

} // anonymous namespace

namespace
{

#if !defined(FASTFORMAT_NO_NAMESPACE)
    using fastformat::ff_string_slice_t;
    using fastformat::ff_replacement_code_t;
    using fastformat::FF_REPLACEMENTCODE_SUCCESS;
    using fastformat::FF_REPLACEMENTCODE_MISSING_ARGUMENT;
    using fastformat::FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT;
    using fastformat::missing_argument_exception;
    using fastformat::unreferenced_argument_exception;
#endif /* !FASTFORMAT_NO_NAMESPACE */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    int FASTFORMAT_CALLCONV fastformat_stock_mismatchedHandler_throw(
        void*                   /* param */
    ,   ff_replacement_code_t   code
    ,   size_t                  numParameters
    ,   int                     parameterIndex
    ,   ff_string_slice_t*      /* slice */
    ,   void*                   /* reserved0 */
    ,   size_t                  /* reserved1 */
    ,   void*                   /* reserved2 */
    )
    {
        // Simplistic factory for exceptions

        switch(code)
        {
            default:
                FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unknown parse code");
                break;
            case    FF_REPLACEMENTCODE_SUCCESS:
                // This is ignored. This code is passed to indicate completion of the statement
                break;
            case    FF_REPLACEMENTCODE_MISSING_ARGUMENT:
                throw missing_argument_exception("a required argument is missing from the argument list", code, int(numParameters), parameterIndex);
            case    FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT:
                throw unreferenced_argument_exception("an argument was unreferenced in the format", code, int(numParameters), parameterIndex);
        }

        return 0;
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    int FASTFORMAT_CALLCONV fastformat_stock_mismatchedHandler_ignore(
        void*                   /* param */
    ,   ff_replacement_code_t   /* code */
    ,   size_t                  /* numParameters */
    ,   int                     /* parameterIndex */
    ,   ff_string_slice_t*      /* slice */
    ,   void*                   /* reserved0 */
    ,   size_t                  /* reserved1 */
    ,   void*                   /* reserved2 */
    )
    {
        // No-op

        return 0; // Return 0 to indicate
    }

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Types & Non-local variables
 */

namespace
{
    struct replacements_context_t_
    {
        ff_char_t   spaces[1000];
        ff_char_t   hashes[1000];

        replacements_context_t_()
        {
            std::fill(&spaces[0], &spaces[0] + STLSOFT_NUM_ELEMENTS(spaces), FASTFORMAT_LITERAL_CHARACTER(' '));
            std::fill(&hashes[0], &hashes[0] + STLSOFT_NUM_ELEMENTS(hashes), FASTFORMAT_LITERAL_CHARACTER('#'));
        }
    };

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

FASTFORMAT_CALL(size_t) fastformat_calculateNumberOfRequiredReplacements(
    ff_char_t const*    /* format */
,   size_t              cchFormat
)
{
    // TODO: Implement this
    return (1 + cchFormat) / 2;
}

/*
 *
 *  format:   "i={0}; j={1,10,20,^}"                                2 literals, 2 replacement parameters
 *
 *          |
 *          | via fastformat_parseFormat()
 *          |
 *          v
 *
 *  format elements: "i=", [0], "; j=", [1,10,20,^]                 4 format elements, (up to) 6 result elements
 *
 *          |
 *          | via fastformat_fillReplacements()
 *          |
 *          v
 *
 * (with the arguments "abc" and "wxyz")
 *
 *  result elements: "i=", "abc", "; j=", "   ", "wxyz", "   "      6 result elements
 */

FASTFORMAT_CALL(unsigned) fastformat_parseFormat(
    ff_char_t const*    fmt
,   size_t              cchFmt
,   format_element_t*   formatElements
,   size_t              numFormatElements
,   illformedHandler_t  handler
,   void*               param
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    // Cannot be compiled when unsigned cannot hold two 16-bit values
    STLSOFT_STATIC_ASSERT(sizeof(unsigned) >= 4);

    enum state_t
    {
            literal
        ,   openCurly
        ,   parameter
    };

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != fmt || 0 == cchFmt, "format can only be null when the format length is 0, and vice versa");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != formatElements || 0 == numFormatElements, "format elements pointer can only be null when the number of pattern elements is 0, and vice versa");
    STLSOFT_SUPPRESS_UNUSED(numFormatElements);

    illformed_handler_info_t    handler_info = { handler, param };

    if(NULL == handler_info.handler)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        handler_info = fastformat_getThreadIllformedHandler();
    }

    if(NULL == handler_info.handler)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        handler_info = fastformat_getProcessIllformedHandler();
    }

    if(NULL == handler_info.handler)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

    handler_info = fastformat_getDefaultIllformedHandler();
    }

    unsigned                num     =   0;              // number of replacement elements written
    unsigned                numRes  =   0;
    ff_char_t const*        p0      =   fmt;
    ff_char_t const*        p1      =   p0;
    ff_char_t const* const  end     =   p0 + cchFmt;
    state_t                 state   =   literal;

    { for(; p1 != end; ++p1)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        int parameterIndex;

        switch(state)
        {
            default:
                FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("Invalid parse state");
            case    literal:
                FASTFORMAT_COVER_MARK_ENTRY();

                // The only transition here is to '{'; '}' is handled later
                switch(*p1)
                {
                    case    '{': // to be matched later by '}'
                        state = openCurly;
                        break;
                    default:
                        break;
                }
                break;
            case    openCurly:
                FASTFORMAT_COVER_MARK_ENTRY();

                if(p1 != p0 + 1) // Only create a slice if not-empty, i.e. if there was a literal between two replacements
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

                    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(num < numFormatElements, "insufficient replacement storage provided to fastformat_parseFormat(); recode using fastformat_calculateNumberOfRequiredReplacements()");

                    formatElements[num].ptr   =   p0;
                    formatElements[num].len   =   static_cast<size_t>((p1 - p0) - 1);
                    formatElements[num].index =   FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_;

                    p0 = p1 - 1;

                    ++num;
                    ++numRes;
                }
                switch(*p1)
                {
                    case    '{': // escaping; not required for '}'
                        FASTFORMAT_COVER_MARK_ENTRY();

                        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(num < numFormatElements, "insufficient replacement storage provided to fastformat_parseFormat(); recode using fastformat_calculateNumberOfRequiredReplacements()");

                        formatElements[num].ptr   =   p1;
                        formatElements[num].len   =   1;
                        formatElements[num].index =   FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_;

                        p0 = p1 + 1;

                        ++num;
                        ++numRes;

                        state = literal;
                        break;
                    default:
                        FASTFORMAT_COVER_MARK_ENTRY();

                        state = parameter;
                        break;
                }

                // Must either go back to LITERAL or to PARAMETER
                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION((literal == state || parameter == state));

                break;
            case    parameter:
                FASTFORMAT_COVER_MARK_ENTRY();

                switch(*p1)
                {
                    case    '0':
                    case    '1':
                    case    '2':
                    case    '3':
                    case    '4':
                    case    '5':
                    case    '6':
                    case    '7':
                    case    '8':
                    case    '9':
                    case    ',':
                    case    '-':
                    case    '<':
                    case    '>':
                    case    '^':
                    case    '#':
                    case    ' ':
                        FASTFORMAT_COVER_MARK_ENTRY();
                        break;
                    case    '}': // Matching earlier '{'
                        FASTFORMAT_COVER_MARK_ENTRY();

                        state = literal;

                        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(num < numFormatElements, "insufficient replacement storage provided to fastformat_parseFormat(); recode using fastformat_calculateNumberOfRequiredReplacements()");

                        parameterIndex = parse_parameter_(p0, p1, formatElements, num, numRes);

                        if(parameterIndex < 0)
                        {
                            FASTFORMAT_COVER_MARK_ENTRY();

                            if(NULL != handler_info.handler)
                            {
                                FASTFORMAT_COVER_MARK_ENTRY();

                                ff_parse_code_t xc  =   code_from_index_(parameterIndex);
                                int             r   =   (*handler_info.handler)(handler_info.param, xc, fmt, cchFmt, num, p0, static_cast<size_t>((p1 + 1) - p0), -1, NULL, 0, NULL);

                                if(0 == r)
                                {
                                    FASTFORMAT_COVER_MARK_ENTRY();

                                    return (num & 0xffff) | ((numRes & 0xffff) << 16);
                                }
                                else if(r < 0)
                                {
                                    FASTFORMAT_COVER_MARK_ENTRY();

                                    handler_info.handler = NULL;
                                }

                                FASTFORMAT_COVER_MARK_ENTRY();
                            }

                            // Here we have been instructed to accept it as a literal, so

                            FASTFORMAT_COVER_MARK_ENTRY();

                            record_parameter_as_literal_(p0, p1, formatElements, num, numRes);
                        }

                        FASTFORMAT_COVER_MARK_ENTRY();

                        p0 = p1 + 1;

                        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(num <= numFormatElements, "insufficient replacement storage provided to fastformat_parseFormat(); recode using fastformat_calculateNumberOfRequiredReplacements()");

                        break;
                    default:
                        FASTFORMAT_COVER_MARK_ENTRY();

                        // Handle "malformed"
                        if(NULL != handler_info.handler)
                        {
                            FASTFORMAT_COVER_MARK_ENTRY();

                            size_t  len = 2; // TODO: find '}' in [p1, end), and use that distance; assume '{'
                            int     res;

                            { for(ff_char_t const* p2 = p1; end != p2; ++p2)
                            {
                                FASTFORMAT_COVER_MARK_ENTRY();

                                if('}' == *p2) // '{'
                                {
                                    FASTFORMAT_COVER_MARK_ENTRY();

                                    len = size_t(p2 - p0) + 2;
                                    break;
                                }
                            }}

                            res = (*handler_info.handler)(handler_info.param, FF_PARSECODE_INVALIDINDEX, fmt, cchFmt, num, p0, len, -1, NULL, 0, NULL);

                            if(0 == res)
                            {
                                FASTFORMAT_COVER_MARK_ENTRY();

                                return (num & 0xffff) | ((numRes & 0xffff) << 16);
                            }
                            else if(res < 0)
                            {
                                FASTFORMAT_COVER_MARK_ENTRY();

                                handler_info.handler = NULL;
                            }
                        }

                        FASTFORMAT_COVER_MARK_ENTRY();

                        state = literal; // Ignored
                        break;
                }
                break;
        }
    }}

    if(p1 != p0)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        if(state != literal)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            // Handle "malformed"
            if(NULL != handler_info.handler)
            {
                FASTFORMAT_COVER_MARK_ENTRY();

                int res = (*handler_info.handler)(handler_info.param, FF_PARSECODE_INCOMPLETEREPLACEMENT, fmt, cchFmt, num, p0, 0, -1, NULL, 0, NULL);

                if(0 == res)
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

                    return (num & 0xffff) | ((numRes & 0xffff) << 16);
                }
                else if(res < 0)
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

                    handler_info.handler = NULL;
                }
            }

            FASTFORMAT_COVER_MARK_ENTRY();
        }

        FASTFORMAT_COVER_MARK_ENTRY();

        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(num < numFormatElements, "insufficient replacement storage provided to fastformat_parseFormat(); recode using fastformat_calculateNumberOfRequiredReplacements()");

        formatElements[num].ptr   =   p0;
        formatElements[num].len   =   static_cast<size_t>(p1 - p0);
        formatElements[num].index =   FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_;

        ++num;
        ++numRes;
    }

    return (num & 0xffff) | ((numRes & 0xffff) << 16);
}

FASTFORMAT_CALL(size_t) fastformat_fillReplacements(
    string_slice_t*                 resultElements      // Pointer to receiver of result slices
,   format_element_t const*         formatElements      // Pointer to format elements
,   size_t                          numFormatElements
,   string_slice_t const*           arguments           // Pointer to arguments
,   size_t                          numArguments
,   fastformat_mismatchedHandler_t  handler
,   void*                           param
,   size_t*                         pnumResultElements
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != resultElements, "result elements may not be null");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API(NULL != pnumResultElements, "result element count pointer may not be null");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API((NULL != formatElements || 0 == numFormatElements), "pattern elements may not be null, unless numFormatElements is 0");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_API((0 != numArguments) == (NULL != arguments), "arguments can only be null when there are 0 arguments, and vice versa");

    mismatched_handler_info_t   handler_info        =   { handler, param };
    size_t                      cchTotal            =   0;
    string_slice_t              defaultSlice        =   {   0,  NULL    };
    int                         handlerReturned     =   0;
    string_slice_t* const       resultElementsBase  =   resultElements;

#ifndef FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS
    stlsoft::auto_buffer<unreferenced_argument_flag_t>   argumentReferenceFlags(numArguments);

    std::fill(argumentReferenceFlags.begin(), argumentReferenceFlags.end(), 0);
#endif /* !FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS */

    if(NULL == handler_info.handler)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        handler_info = fastformat_getThreadMismatchedHandler();
    }

    if(NULL == handler_info.handler)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        handler_info = fastformat_getProcessMismatchedHandler();
    }

    if(NULL == handler_info.handler)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

    handler_info = fastformat_getDefaultMismatchedHandler();
    }

    // Process every format element:
    //
    //  - if literal, copy over
    //  - if replacement, lookup argument and copy over/report mismatch
    //  - if spacer, evaluate whether spacing needed, and then
    { for(size_t i = 0; i != numFormatElements; ++i, ++resultElements)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        format_element_t const& pattern_element = formatElements[i];

        if(FASTFORMAT_INTERNAL_FORMAT_ELEMENT_INDEX_LITERAL_ == pattern_element.index)
        {
            // A literal fragment, so just copy into destination

            FASTFORMAT_COVER_MARK_ENTRY();

            resultElements->len  =   pattern_element.len;
            resultElements->ptr  =   pattern_element.ptr;

            cchTotal += pattern_element.len;
        }
        else
        {
            // A replacement parameter, so work out whether to truncate or
            // to insert any fill slices (before, after, or both)
            //
            // 1. If a maximum width is specified and the source slice
            //    length is greater than the maximum, then we truncate
            // 2. If a minimum width is specified and the source slice
            //    length is less than the minimum, then we insert one or
            //    more slices:
            // 2.a. If left-aligned, then we insert a pad slice after
            //      the current slice
            // 2.b. If right-aligned, then we insert a pad slice before
            //      the current slice
            // 2.c. If centre-aligned, then we insert pad slices before
            //      and after the current slice
            // 3. If none of these are satisfied, then copy over the
            //    source slice as-is

            // But, first, we need to validate the index
            if(pattern_element.index >= static_cast<int>(numArguments))
            {
                // Pattern element index is out of range, e.g. fmtln(sink, "val0={2}", v0, v1);

                FASTFORMAT_COVER_MARK_ENTRY();

                FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL != handler_info.handler);

                if(handlerReturned >= 0)
                {
                    handlerReturned = (*handler_info.handler)(handler_info.param, FF_REPLACEMENTCODE_MISSING_ARGUMENT, numArguments, pattern_element.index, &defaultSlice, NULL, 0, NULL);
                }

                // Handler has returned, so no exception has been thrown
                //
                // If 0, insert the pattern_element, otherwise insert the
                // default slice.

                if(handlerReturned != 0)
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

#if 0
                    // We cannot take the default slice, because the application has
                    // not provided any space for us to write it, so ...
                    resultElements->len  =   defaultSlice.len;
                    resultElements->ptr  =   defaultSlice.ptr;
#else /* ? 0 */
                    // ... we skip it (by decrementing in anticipation of the increment
                    // as we loop round again).
                    --resultElements;
#endif /* 0 */
                }
                else
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

                    resultElements->len  =   pattern_element.len;
                    resultElements->ptr  =   pattern_element.ptr;
                }
            }
            else
            {
                string_slice_t const&   src_slice = arguments[pattern_element.index];
                ff_char_t const*        (FASTFORMAT_CALLCONV* pfnFill)(size_t) = ('#' == pattern_element.fill) ? fastformat_getHashesSlice : fastformat_getSpacesSlice;

                if( pattern_element.maxWidth >= 0 &&
                    size_t(pattern_element.maxWidth) < src_slice.len)
                {
                    // Truncating, so see if we're truncating left/centre/right

                    resultElements->len = pattern_element.maxWidth;

                    switch(pattern_element.alignment)
                    {
                        default:
                            FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("invalid enumerator");
                        case    FASTFORMAT_ALIGNMENT_NONE:
                        case    FASTFORMAT_ALIGNMENT_RIGHT:
                            resultElements->ptr = src_slice.ptr + (src_slice.len - pattern_element.maxWidth);
                            break;
                        case    FASTFORMAT_ALIGNMENT_CENTRE:
                            resultElements->ptr = src_slice.ptr + (src_slice.len - pattern_element.maxWidth) / 2;
                            break;
                        case    FASTFORMAT_ALIGNMENT_LEFT:
                            resultElements->ptr = src_slice.ptr;
                            break;
                    }

                    cchTotal += pattern_element.maxWidth;
                }
                else if(0 != pattern_element.minWidth &&
                        size_t(pattern_element.minWidth) > src_slice.len)
                {
                    switch(pattern_element.alignment)
                    {
                        default:
                            FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("invalid enumerator");
                        case    FASTFORMAT_ALIGNMENT_NONE:
                        case    FASTFORMAT_ALIGNMENT_RIGHT:
                            // insert a spaces slice before the source slice
                            resultElements->len = size_t(pattern_element.minWidth) - src_slice.len;
                            resultElements->ptr = pfnFill(resultElements->len);

                            ++resultElements;

                            resultElements->len = src_slice.len;
                            resultElements->ptr = src_slice.ptr;
                            break;
                        case    FASTFORMAT_ALIGNMENT_CENTRE:
                            // insert a spaces slice before and after the source slice
                            resultElements->len = (size_t(pattern_element.minWidth) - src_slice.len) / 2;
                            resultElements->ptr = pfnFill(resultElements->len);

                            ++resultElements;

                            resultElements->len = src_slice.len;
                            resultElements->ptr = src_slice.ptr;

                            ++resultElements;

                            resultElements->len = size_t(pattern_element.minWidth) - (resultElements[-1].len + resultElements[-2].len);
                            resultElements->ptr = pfnFill(resultElements->len);
                            break;
                        case    FASTFORMAT_ALIGNMENT_LEFT:
                            // insert a spaces slice after the source slice
                            resultElements->len = src_slice.len;
                            resultElements->ptr = src_slice.ptr;

                            ++resultElements;

                            resultElements->len = size_t(pattern_element.minWidth) - src_slice.len;
                            resultElements->ptr = pfnFill(resultElements->len);
                            break;
                    }

                    cchTotal += pattern_element.minWidth;
                }
                else
                {
                    // Not truncating, so just copy over

                    resultElements->len = src_slice.len;
                    resultElements->ptr = src_slice.ptr;

                    cchTotal += src_slice.len;
                }
            }

#ifndef FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS
            // Have to do a runtime test here, in case where additional
            // arguments are specified (and exception suppressed by use of
            // fastformat::ignore_missing_arguments_scope).
            if(size_t(pattern_element.index) < argumentReferenceFlags.size())
            {
                argumentReferenceFlags[size_t(pattern_element.index)] = 1;
            }
#endif /* !FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS */
        }
    }}

#ifndef FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS
    stlsoft::auto_buffer<unreferenced_argument_flag_t>::iterator it;

    if(argumentReferenceFlags.end() != (it = std::find(argumentReferenceFlags.begin(), argumentReferenceFlags.end(), 0)))
    {
        int firstMismatchedReplacementIndex = static_cast<int>(it - argumentReferenceFlags.begin());

        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL != handler_info.handler);

        (*handler_info.handler)(handler_info.param, FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT, numArguments, firstMismatchedReplacementIndex, NULL, NULL, 0, NULL);
    }
#endif /* !FASTFORMAT_DO_NOT_DETECT_UNREFERENCED_ARGUMENTS */

    if(0 != handlerReturned)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(NULL != handler_info.handler);

        (*handler_info.handler)(handler_info.param, FF_REPLACEMENTCODE_SUCCESS, numArguments, -1, NULL, NULL, 0, NULL);
    }

    *pnumResultElements = static_cast<size_t>(resultElements - resultElementsBase);

    return cchTotal;
}

FASTFORMAT_CALL(size_t) fastformat_accumulateSliceLengths(
    size_t                      numSlices
,   ff_string_slice_t const*    slices
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

    // The sophisticated way
    return std::accumulate( stlsoft::member_selector(slices, &ff_string_slice_t::len)
                        ,   stlsoft::member_selector(slices + numSlices, &ff_string_slice_t::len)
                        ,   size_t(0));

#else /* ? compiler */

    // The crappy way, for less-than compilers
    size_t  total = 0;

    { for(size_t i = 0; i != numSlices; ++i)
    {
        total += slices[i].len;
    }}

    return total;
#endif /* compiler */
}


/* /////////////////////////////////////////////////////////////////////////
 * Implementation Functions
 */

int ximpl_core::fastformat_impl_replacements_init(void** ptoken)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != ptoken, "token pointer must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    try
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        replacements_context_t_* ctxt = new replacements_context_t_();

        if(NULL == ctxt)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            return FASTFORMAT_INIT_RC_OUT_OF_MEMORY;
        }

        *ptoken = ctxt;

        return FASTFORMAT_INIT_RC_SUCCESS;
    }
    catch(std::bad_alloc&)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return FASTFORMAT_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
    catch(...)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR;
    }
}

void ximpl_core::fastformat_impl_replacements_uninit(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != token, "token must not be null");

    delete static_cast<replacements_context_t_*>(token);
}

ff_mismatched_handler_info_t ximpl_core::fastformat_impl_handlers_getDefaultMismatchedHandler(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "token must not be null");
    STLSOFT_SUPPRESS_UNUSED(token);

    ff_mismatched_handler_info_t r;

    r.param   = NULL;

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    r.handler = fastformat_stock_mismatchedHandler_throw;

    STLSOFT_SUPPRESS_UNUSED(fastformat_stock_mismatchedHandler_ignore);
#else /* ? STLSOFT_CF_EXCEPTION_SUPPORT */
    r.handler = fastformat_stock_mismatchedHandler_ignore;

    STLSOFT_SUPPRESS_UNUSED(fastformat_stock_mismatchedHandler_throw);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

  return r;
}

ff_char_t const* ximpl_core::fastformat_impl_replacements_getSpaces(void* token, size_t len)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "state pointer must be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    replacements_context_t_* ctxt = static_cast<replacements_context_t_*>(token);

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(len <= STLSOFT_NUM_ELEMENTS(ctxt->spaces), "too many spaces requested");

    STLSOFT_SUPPRESS_UNUSED(len);

    return ctxt->spaces;
}

ff_char_t const* ximpl_core::fastformat_impl_replacements_getHashes(void* token, size_t len)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "state pointer must be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    replacements_context_t_* ctxt = static_cast<replacements_context_t_*>(token);

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(len <= STLSOFT_NUM_ELEMENTS(ctxt->hashes), "too many hashes requested");

    STLSOFT_SUPPRESS_UNUSED(len);

    return ctxt->hashes;
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
