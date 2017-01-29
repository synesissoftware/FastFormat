/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/util/bundle/windows_replacement_translation_functions.hpp
 *
 * Purpose:     Functions to assist with translation between Windows and
 *              FastFormat replacement parameters.
 *
 * Created:     24th April 2009
 * Updated:     10th January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2017, Matthew Wilson and Synesis Software
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


/** \file fastformat/util/bundle/windows_replacement_translation_functions.hpp
 *
 * [C++ only] Functions to assist with translation between Windows and
 *  FastFormat replacement parameters.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS
#define FASTFORMAT_INCL_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS_MINOR      0
# define FASTFORMAT_VER_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS_REVISION   3
# define FASTFORMAT_VER_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS_EDIT       8
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace util
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/** Calculates the number of replacement parameters in a Windows format
 * string
 *
 * \param str Pointer to the string
 * \param len Length of the string
 *
 * \return The number of replacement parameters
 */
inline
size_t
calculate_number_of_windows_replacement_parameters(
    ff_char_t const*    str
,   size_t              len
)
{
    enum state_t
    {
        normal, percent
    }                   state   =   normal;
    ff_char_t const*    begin   =   str;
    ff_char_t const*    end     =   str + len;
    size_t              n       =   0;

    for(; begin != end; ++begin)
    {
        switch(*begin)
        {
            case    '%':
                state = (normal == state) ? percent : normal;
                break;
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
                if(percent == state)
                {
                    ++n;
                }
                // fall through
            default:
                state = normal;
                break;
        }
    }

    return n;
}

/** Calculates the number of replacement parameters in a FastFormat format
 * string
 *
 * \param str Pointer to the string
 * \param len Length of the string
 *
 * \return The number of replacement parameters
 */
inline
size_t
calculate_number_of_fastformat_replacement_parameters(
    ff_char_t const*    str
,   size_t              len
)
{
    enum state_t
    {
        normal, replacement
    }                   state   =   normal;
    ff_char_t const*    begin   =   str;
    ff_char_t const*    end     =   str + len;
    size_t              n       =   0;

    for(; begin != end; ++begin)
    {
        switch(*begin)
        {
            case    '{':
                state = (normal == state) ? replacement : normal;
                break;
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
                if(replacement == state)
                {
                    ++n;
                }
                // fall through
            default:
                state = normal;
                break;
        }
    }

    return n;
}


/** Converts a Windows format string to a FastFormat.Format format string
 */
template <typename S>
inline
S
change_windows_replacement_parameters_to_fastformat(
    S const& str
)
{
    typedef ss_typename_type_k S::const_iterator    iter_t;

    enum state_t
    {
        normal, percent, number
    }       state   =   normal;
    S       str2;
    int     index   =   0;

    str2.reserve(str.size() + 10);

    { for(iter_t begin = str.begin(); begin != str.end(); ++begin)
    {
        bool isNumber = false;

        switch(*begin)
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
                isNumber = true;
        }

        if( number == state &&
            !isNumber)
        {
            ff_char_t   parameter[32];
            int         cch = fastformat_util_snprintf(&parameter[0], STLSOFT_NUM_ELEMENTS(parameter), FASTFORMAT_LITERAL_STRING("{%d}"), index - 1);

            str2.append(parameter, size_t(cch));

            state = normal;

            if('%' == *begin)
            {
                goto found_percent;
            }

            str2.append(1u, *begin);
        }
        else
        {
            switch(*begin)
            {
                case    '%':
found_percent:
                    switch(state)
                    {
                        default:
                        case    number:
                            FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unexpected state");
                        case    normal:
                            state = percent;
                            break;
                        case    percent:
                            state = normal;
                            str2.append(1, '%');
                            break;
                    }
                    break;
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
                    switch(state)
                    {
                        default:
                            FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unexpected state");
                        case    normal:
                            str2.append(1, *begin);
                            break;
                        case    percent:
                            state = number;
                            index = (*begin - '0');
                            break;
                        case    number:
                            index = (10 * index) + (*begin - '0');
                            break;
                    }
                    break;
                default:
                    state = normal;
                    str2.append(1, *begin);
                    break;
            }
        }
    }}

    if(number == state)
	{
        ff_char_t   parameter[32];
        int         cch = fastformat_util_snprintf(&parameter[0], STLSOFT_NUM_ELEMENTS(parameter), FASTFORMAT_LITERAL_STRING("{%d}"), index - 1);

        str2.append(parameter, size_t(cch));
    }

    return str2;
}

/** Converts a literal string into a FastFormat.Format compatible
 * string by replacing any '{' characters with a sequence of "{{"
 */
template <typename S>
inline
S
escape_fastformat_replacement_parameters(
    S const& str
)
{
    typedef ss_typename_type_k S::const_iterator    iter_t;

    S   str2;

    str2.reserve(str.size() + 10);

    { for(iter_t begin = str.begin(); begin != str.end(); ++begin)
    {
        switch(*begin)
        {
            case    '{':
                str2.append(1, '{');
                // fall through
            default:
                str2.append(1, *begin);
                break;
        }
    }}

    return str2;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace util */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_UTIL_BUNDLE_HPP_WINDOWS_REPLACEMENT_TRANSLATION_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
