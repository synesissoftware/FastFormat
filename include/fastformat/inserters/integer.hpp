/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/integer.hpp
 *
 * Purpose:     Inserter functions for integral types
 *
 * Created:     26th May 2009
 * Updated:     5th February 2017
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


/** \file fastformat/inserters/integer.hpp
 *
 * [C++ only] Inserter functions for integral types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_INTEGER
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_INTEGER

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_INTEGER_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_INTEGER_MINOR      2
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_INTEGER_REVISION   8
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_INTEGER_EDIT       23
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>
#include <fastformat/internal/inserters/int_typedefs.hpp>

#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/meta/is_integral_type.hpp>
#include <stlsoft/string/case_functions.hpp>
#include <stlsoft/string/ctype_traits.hpp>
#include <stlsoft/string/shim_string.hpp>
#include <stlsoft/shims/access/string/std/c_string.h>
#if STLSOFT_LEAD_VER >= 0x010a0000
 /* presumption of STLSoft 1.10 */
# include <stlsoft/limits/integral_limits.hpp>
#else /* ? STLSOFT_LEAD_VER */
 /* presumption of STLSoft 1.9 */
# include <stlsoft/util/limit_traits.h>
#endif /* STLSOFT_LEAD_VER */
#if STLSOFT_LEAD_VER >= 0x010a0000
 /* presumption of STLSoft 1.10 */
# include <stlsoft/traits/integral_printf_format_traits.hpp>
#else /* ? STLSOFT_LEAD_VER */
 /* presumption of STLSoft 1.9 */
# include <stlsoft/util/integral_printf_traits.hpp>
#endif /* STLSOFT_LEAD_VER */

#include <ctype.h>      /* for ::toupper */
#include <stdlib.h>     /* for abs() */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace inserters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
namespace ximpl_integer
{

enum ff_i2s_case_selection_t
{
        FF_ximpl_REQUIRE_LOWERCASE  =   0
    ,   FF_ximpl_REQUIRE_UPPERCASE  =   1
};


inline int default_width_sentinel_()
{
#if STLSOFT_LEAD_VER >= 0x010a0000
    return stlsoft::integral_limits<int>::minimum();
#else /* ? STLSOFT_LEAD_VER */
    return stlsoft::limit_traits<int>::minimum();
#endif /* STLSOFT_LEAD_VER */
}

inline int default_precision_sentinel_()
{
    return -1;
}

inline ff_char_t* make_x_upper_(ff_char_t* from, ff_char_t* to)
{
    for(; to != from; ++from)
    {
        if('x' == *from)
        {
            *from = 'X';
            break;
        }
    }

    return from;
}

template <typename I>
inline ff_to_i_r_t_ integer_helper_2(
    I const&            value
,   ff_char_t const*    fmt
)
{
    STLSOFT_STATIC_ASSERT(stlsoft::is_integral_type<I>::value);

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != fmt, "fmt may not be null");

    typedef ff_to_i_r_t_   result_t;

    enum { maxRepeats = 3 };

#ifdef FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_

    result_t    result(20u, '~');

    { for(int i = 0;; )
    {
        int n = fastformat_util_snprintf(&result[0], result.size(), fmt, value);

        if(n > int(result.size()))
        {
            // An implementation that does it correctly, so just resize
            // to the desired size and go again

            // This'll only return false when exception-handling is
            // suppressed, but the code is correct without preprocessor
            // logic in either case, so leave as is
            result.resize(n);
        }
        else if(n < 0)
        {
            if(maxRepeats == ++i)
            {
                result.clear();
                break;
            }
            else
            {
                // This'll only return false when exception-handling is
                // suppressed, but the code is correct without preprocessor
                // logic in either case, so leave as is
                result.resize(1u + result.size() * 3);
            }
        }
        else
        {
            // It's worked!
            //
            // We must nul-terminate, and resize, so that the shim string's
            // length is evaluated correctly
            result.resize(size_t(n));

            break;
        }
    }}

    return result;

#else /* ? FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_ */


# if _STLSOFT_VER < 0x010a0000 && \
     defined(_STLSOFT_1_10_VER) && \
     _STLSOFT_1_10_VER < 0x010a0109

    /* Using STLSoft 1.10.1 alpha 1 - alpha 8 */

#  error This class cannot work with STLSoft 1.10 versions between 1.10.1 alpha 1 and 1.10.1 alpha 9. Please download the latest version of STLSoft 1.10 alpha

# elif _STLSOFT_VER >= 0x010a0000 || \
       defined(_STLSOFT_1_10_VER)

    /* Using STLSoft 1.10+ version of basic_shim_string */

    // We use the public interface of the shim string.

    result_t result(64);

#  ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(!result.empty())
#  endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    {
        // Unlike integral types, the string representation of floating
        // point values do not have a known maximum length, so we must be
        // flexible.
        //
        // However, some implementations of snprintf() return -1 instead of
        // the length that would be required, so we cannot assume -1
        // indicates error. To handle this, we double the size of the buffer
        // up to four times, at which point we admit defeat.

        { for(int i = 0;; )
        {
            int n = fastformat_util_snprintf(result.data(), result.size() - 1, fmt, value);

            if(n > int(result.size()))
            {
                // An implementation that does it correctly, so just resize
                // to the desired size and go again

                // This'll only return false when exception-handling is
                // suppressed, but the code is correct without preprocessor
                // logic in either case, so leave as is
                if(!result.resize(n))
                {
                    result.truncate(0);
                    break;
                }
            }
            else if(n < 0)
            {
                if(maxRepeats == ++i)
                {
                    result.truncate(0);
                    break;
                }
                else
                {
                    // This'll only return false when exception-handling is
                    // suppressed, but the code is correct without preprocessor
                    // logic in either case, so leave as is
                    if(!result.resize(1u + result.size() * 3))
                    {
                        result.truncate(0);
                        break;
                    }
                }
            }
            else
            {
                // It's worked!
                //
                // We must nul-terminate, and resize, so that the shim string's
                // length is evaluated correctly
                result.truncate(size_t(n));

                break;
            }
        }}
    }

    return result;

# else /* ? STLSoft 1.x */

    /* Using STLSoft 1.9+ version of basic_shim_string */

    // We have to use the internal buffer, which means that we are
    // relying on the internal workings of shim string, which is ugly.
    // With 1.10, we don't need to do this.

    result_t                result(64);
    result_t::buffer_type&  buffer = result.get_buffer();

#  ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(!buffer.empty())
#  endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
    {
        // Unlike integral types, the string representation of floating
        // point values do not have a known maximum length, so we must be
        // flexible.
        //
        // However, some implementations of snprintf() return -1 instead of
        // the length that would be required, so we cannot assume -1
        // indicates error. To handle this, we double the size of the buffer
        // up to four times, at which point we admit defeat.

        { for(int i = 0;; )
        {
            int n = fastformat_util_snprintf(&buffer[0], buffer.size() - 1, fmt, value);

            if(n > int(buffer.size() - 1))
            {
                // An implementation that does it correctly, so just resize
                // to the desired size and go again

                // This'll only return false when exception-handling is
                // suppressed, but the code is correct without preprocessor
                // logic in either case, so leave as is
                if(!buffer.resize(size_t(n) + 1u))
                {
                    buffer.resize(1u);
                    break;
                }
            }
            else if(n < 0)
            {
                if(maxRepeats == ++i)
                {
                    break;
                }
                else
                {
                    // This'll only return false when exception-handling is
                    // suppressed, but the code is correct without preprocessor
                    // logic in either case, so leave as is
                    if(!buffer.resize(1u + buffer.size() * 3))
                    {
                        buffer.resize(1u);
                        break;
                    }
                }
            }
            else
            {
                // It's worked!
                //
                // We must nul-terminate, and resize, so that the shim string's
                // length is evaluated correctly
                buffer[size_t(n)] = '\0';

                buffer.resize(size_t(n) + 1u);

                break;
            }
        }}
    }

    return result;
# endif /* STLSoft 1.x */
#endif /* FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_ */
}

#ifndef STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_MAJOR
inline ff_to_i_r_t_ hex_integer_helper(
    stlsoft::uint64_t       value
,   ff_i2s_case_selection_t uppercaseAlpha
)
{
#if STLSOFT_LEAD_VER >= 0x010a0000
    typedef stlsoft::integral_printf_format_traits<stlsoft::uint64_t>   printf_format_traits_t;
#else /* ? STLSOFT_LEAD_VER */
    typedef stlsoft::integral_printf_traits<stlsoft::uint64_t>          printf_format_traits_t;
#endif /* STLSOFT_LEAD_VER */

    ff_char_t   result[17];
    int         n = fastformat_util_snprintf(
                        &result[0]
                    ,   STLSOFT_NUM_ELEMENTS(result)
#ifdef FASTFORMAT_USE_WIDE_STRINGS
                    ,    printf_format_traits_t::hexadecimal_format_w(false)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
                    ,    printf_format_traits_t::hexadecimal_format_a(false)
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
                    ,   value);

    if(FF_ximpl_REQUIRE_UPPERCASE == uppercaseAlpha)
    {
        typedef stlsoft::ctype_traits<ff_char_t> ctype_traits_t;

        stlsoft::std_transform(result, result + n, result, ctype_traits_t::to_upper);
    }

    return ff_to_i_r_t_(result, size_t(n));
}

inline ff_to_i_r_t_ hex_integer_helper(
    stlsoft::sint64_t       value
,   ff_i2s_case_selection_t uppercaseAlpha
)
{
    return hex_integer_helper(static_cast<stlsoft::uint64_t>(value), uppercaseAlpha);
}

template <typename I>
inline ff_to_i_r_t_ hex_integer_helper(
    I const&                value
,   ff_i2s_case_selection_t uppercaseAlpha
)
{
    ff_char_t   fmt[3] = { FASTFORMAT_LITERAL_CHARACTER('%'), (FF_ximpl_REQUIRE_UPPERCASE == uppercaseAlpha) ? FASTFORMAT_LITERAL_CHARACTER('X') : FASTFORMAT_LITERAL_CHARACTER('x'), FASTFORMAT_LITERAL_CHARACTER('\0') };
    ff_char_t   result[17];
    int         n = fastformat_util_snprintf(&result[0], STLSOFT_NUM_ELEMENTS(result), fmt, value);

    return ff_to_i_r_t_(result, size_t(n));
}
#endif /* !STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_MAJOR */

template <typename I>
inline ff_to_i_r_t_ integer_helper_5(
    I const&                value
,   int                     minimumWidth
,   int                     precision
,   int                     base
,   ff_i2s_case_selection_t uppercaseAlpha
)
{
#if STLSOFT_LEAD_VER >= 0x010a0000
    typedef stlsoft::integral_printf_format_traits<I>   printf_format_traits_t;
#else /* ? STLSOFT_LEAD_VER */
    typedef stlsoft::integral_printf_traits<I>          printf_format_traits_t;
#endif /* STLSOFT_LEAD_VER */

    STLSOFT_STATIC_ASSERT(stlsoft::is_integral_type<I>::value);

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(10 == base || 16 == base, "base must be 10 (decimal) or 16 (hex)");

    if( default_width_sentinel_() == minimumWidth &&
        precision < 0)
    {
        // no special formatting (width or precision) required

        if(10 == base)
        {
            ff_char_t           sz[21];
            size_t              n;
#if _STLSOFT_VER >= 0x010a0182
            ff_char_t const*    s = stlsoft::integer_to_decimal_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), value, &n);
#else
            ff_char_t const*    s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), value, &n);
#endif

            return ff_to_i_r_t_(s, n);
        }
        else
        {
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(16 == base);

#ifdef STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_MAJOR
            ff_char_t           sz[17];
            size_t              n;
            ff_char_t const*    s = stlsoft::integer_to_hexadecimal_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), value, &n);

            if(FF_ximpl_REQUIRE_UPPERCASE == uppercaseAlpha)
            {
                typedef stlsoft::ctype_traits<ff_char_t> ctype_traits_t;

                stlsoft::std_transform(s, s + n, const_cast<ff_char_t*>(s), ctype_traits_t::to_upper);
            }

            return ff_to_i_r_t_(s, n);
#else 
            return hex_integer_helper(value, uppercaseAlpha);
#endif /* STLSOFT_VER_STLSOFT_CONVERSION_INTEGER_TO_STRING_HPP_INTEGER_TO_HEXADECIMAL_STRING_MAJOR */
        }
    }
    else
    {
        // Performance tests with ff::real() showed a substantial advantage
        // in using integer_to_string() over fastformat_util_snprintf() for
        // the preparation of the format string, so we'll do so again here,
        // even though it's a little more complex, due to the need to work
        // for different integral types.

        // Now need to prepare the format string, and then invoke integer_helper_2()
        //
        // 1. %
        // 2. width
        // 3. .
        // 4. precision
        // 5. type
        // 6. nul

        ff_char_t           fmt_[101]; // max possible is 1 ('%') + 20 + 1 + 20 + 2 ('ld')
        ff_char_t*          fmt     =   fmt_;
        ff_char_t const*    type;
        size_t              typeLen;

        if(10 == base)
        {
#ifdef FASTFORMAT_USE_WIDE_STRINGS
            type    =   printf_format_traits_t::decimal_format_w() + 1;
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
            type    =   printf_format_traits_t::decimal_format_a() + 1;
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
            typeLen =   stlsoft::c_str_len(type);
        }
        else
        {
            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(16 == base);

#ifdef FASTFORMAT_USE_WIDE_STRINGS
            type    =   printf_format_traits_t::hexadecimal_format_w(false) + 1;
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
            type    =   printf_format_traits_t::hexadecimal_format_a(false) + 1;
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
            typeLen =   stlsoft::c_str_len(type);
        }

        if(default_width_sentinel_() == minimumWidth)
        {
            minimumWidth = 0;
        }
        if(precision < 0)
        {
            precision = (0 == value) ? 1 : 0;
        }

        size_t const    fmtDim  =   STLSOFT_NUM_ELEMENTS(fmt_) - 1;
        ff_char_t*      end     =   &fmt[fmtDim];
        size_t          n1;
        size_t          n2;

        // Because integer_to_string (i) writes backwards, and (ii) appends
        // a nul terminator, we need to do this is a strange order

        // 4. precision
#if _STLSOFT_VER >= 0x010a0182
        stlsoft::integer_to_decimal_string(end - (21 + typeLen), 21, precision, &n1);
#else
        stlsoft::integer_to_string(end - (21 + typeLen), 21, precision, &n1);
#endif

        // 5. type
        ::memcpy(end - (typeLen + 1), type, sizeof(ff_char_t) * typeLen);
        if(FF_ximpl_REQUIRE_UPPERCASE == uppercaseAlpha)
        {
            // Make only the first (should be only) 'x' uppercase
            make_x_upper_(end - (typeLen + 1), end - (typeLen + 1) + typeLen);
        }

        // 6. nul
        *--end = '\0';

        end -= typeLen;
        end -= n1;

        // 2. width
#if _STLSOFT_VER >= 0x010a0182
        stlsoft::integer_to_decimal_string(end - 21, 21, minimumWidth, &n2);
#else
        stlsoft::integer_to_string(end - 21, 21, minimumWidth, &n2);
#endif

        // 3. .
        *--end = '.';

        end -= n2;

        // 1. %
        *--end = '%';
        fmt = end;

        return integer_helper_2(value, fmt);
    }
}

template <typename I>
inline ff_to_i_r_t_ integer_helper_3(
    I const&    value
,   int         minimumWidth
,   int         precision
)
{
    return integer_helper_5(value, minimumWidth, precision, 10, FF_ximpl_REQUIRE_LOWERCASE);
}

template <typename I>
inline ff_to_i_r_t_ integer_helper_hex_3(
    I const&                value
,   int                     minimumWidth
,   int                     precision
,   ff_i2s_case_selection_t uppercaseX
)
{
    return integer_helper_5(value, minimumWidth, precision, 16, uppercaseX);
}

} /* namespace ximpl_integer */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Inserter functions
 */

/** Inserts the string form of an integral value
 *
 * \ingroup group__inserters
 *
 * \param value The integral value to be converted to string form
 * \param minimumWidth The minimum width of the result. If negative, the
 *   integer is aligned to the left of the resulting field
 * \param precision The minimum number of digits in the field, which will
 *   result in zero-padding if the given integer has fewer digits
 *
 * \return An instance of an insertable type containing the string form of
 *   the integer
 *
 * \pre abs(minimumWidth) < 512
 * \pre decimalPlaces <= minimumWidth
 */
template <typename I>
inline ximpl_integer::ff_to_i_r_t_ integer(
    I const&    value
,   int         minimumWidth
,   int         precision
)
{
    STLSOFT_STATIC_ASSERT(stlsoft::is_integral_type<I>::value);

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(abs(minimumWidth) < 512, "maximum value for width exceeded");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(abs(minimumWidth) < 1 || precision <= abs(minimumWidth), "decimal places must not exceed width");

    return ximpl_integer::integer_helper_3(value, minimumWidth, precision);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::integer;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_INTEGER */

/* ///////////////////////////// end of file //////////////////////////// */
