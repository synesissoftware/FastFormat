/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/real.hpp
 *
 * Purpose:     Inserter functions for floating-point types
 *
 * Created:     1st March 2009
 * Updated:     31st July 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2012, Matthew Wilson and Synesis Software
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


/** \file fastformat/inserters/real.hpp
 *
 * [C++ only] Inserter functions for floating-point types.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_REAL
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_REAL

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_REAL_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_REAL_MINOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_REAL_REVISION  6
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_REAL_EDIT      10
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>

#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/string/shim_string.hpp>
#if STLSOFT_LEAD_VER >= 0x010a0000
 /* presumption of STLSoft 1.10 */
# include <stlsoft/limits/integral_limits.hpp>
#else /* ? STLSOFT_LEAD_VER */
 /* presumption of STLSoft 1.9 */
# include <stlsoft/util/limit_traits.h>
#endif /* STLSOFT_LEAD_VER */

#include <stdlib.h> /* for abs() */

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
namespace ximpl_real
{

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

inline stlsoft::basic_shim_string<ff_char_t, 64> real_helper_2(
    double const&       value
,   ff_char_t const*    fmt
)
{
    typedef stlsoft::basic_shim_string<ff_char_t, 64>   result_t;

    enum { maxRepeats = 4 };

#if _STLSOFT_VER < 0x010a0000 && \
    defined(_STLSOFT_1_10_VER) && \
    _STLSOFT_1_10_VER < 0x010a0109

    /* Using STLSoft 1.10.1 alpha 1 - alpha 8 */

# error This class cannot work with STLSoft 1.10 versions between 1.10.1 alpha 1 and 1.10.1 alpha 9. Please download the latest version of STLSoft 1.10 alpha

#elif _STLSOFT_VER >= 0x010a0000 || \
      defined(_STLSOFT_1_10_VER)

    /* Using STLSoft 1.10+ version of basic_shim_string */

    // We use the public interface of the shim string.

    result_t result(64);

# ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(!result.empty())
# endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
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
                    if(!result.resize(1u + result.size() * 2))
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

#else /* ? STLSoft 1.x */

    /* Using STLSoft 1.9+ version of basic_shim_string */

    // We have to use the internal buffer, which means that we are
    // relying on the internal workings of shim string, which is ugly.
    // With 1.10, we don't need to do this.

    result_t                result(64);
    result_t::buffer_type&  buffer = result.get_buffer();

# ifndef STLSOFT_CF_THROW_BAD_ALLOC
    if(!buffer.empty())
# endif /* !STLSOFT_CF_THROW_BAD_ALLOC */
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
                    if(!buffer.resize(1u + buffer.size() * 2))
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
#endif /* STLSoft 1.x */
}

inline stlsoft::basic_shim_string<ff_char_t, 64> real_helper_4(
    double const&       value
,   int                 minimumWidth
,   int                 precision
,   ff_char_t const*    specifier
)
{
    ff_char_t   type    =   'f';
    ff_char_t   fmt_[]  =   FASTFORMAT_LITERAL_STRING("%-01234567890123456789.01234567890123456789f");
    ff_char_t*  fmt     =   fmt_;

    if(NULL != specifier)
    {
        type = *specifier;
    }

    if( default_width_sentinel_() == minimumWidth &&
        precision < 0)
    {
        fmt[1] = type;
        fmt[2] = '\0';
    }
    else
    {
        if(default_width_sentinel_() == minimumWidth)
        {
            minimumWidth = 0;
        }
        if(precision < 0)
        {
            precision = 0;
        }

        // Performance tests show a substantial advantage in using
        // integer_to_string() over fastformat_util_snprintf()

#if 0

        int n = fastformat_util_snprintf(&fmt[0], STLSOFT_NUM_ELEMENTS(fmt_) - 1, FASTFORMAT_LITERAL_STRING("%%%d.%d%c"), minimumWidth, precision, type);

        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION((n > 0) && (n < int(STLSOFT_NUM_ELEMENTS(fmt_)) - 1));

        fmt[n] = '\0';

#else /* ? 0 */

        const size_t    fmtDim  =   STLSOFT_NUM_ELEMENTS(fmt_) - 1;
        ff_char_t*      end     =   &fmt[fmtDim];
        size_t          n1;
        size_t          n2;

        stlsoft::integer_to_string(end - 21, 21, precision, &n1);
        *--end = type;
        end -= n1;
        stlsoft::integer_to_string(end - 21, 21, minimumWidth, &n2);
        *--end = '.';
        end -= n2;
        *--end = '%';
        fmt = end;

#endif /* 0 */
    }

    return real_helper_2(value, fmt);
}

} /* namespace ximpl_real */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Inserter functions
 */

/** [DEPRECATED] Inserts the string form of a floating-point value
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 *
 * \deprecated Use \c to_f(), \c to_g(), or \c to_e() instead
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> real(
    double const&   value
)
{
    return ximpl_real::real_helper_4(value, ximpl_real::default_width_sentinel_(), ximpl_real::default_precision_sentinel_(), NULL);
}

/** Inserts the string form of a floating-point value, with the given width
 * and precision
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 * \param minimumWidth The minimum width of the resulting string form. If
 *   non-negative, the result will be right-aligned. If negative, the result
 *   will be left-aligned
 * \param decimalPlaces The number of decimal places to be included
 *
 * \pre abs(minimumWidth) < 512
 * \pre decimalPlaces <= abs(minimumWidth)
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> real(
    double const&   value
,   int             minimumWidth
,   int             decimalPlaces
)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(abs(minimumWidth) < 512, "maximum value for width exceeded");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(abs(minimumWidth) < 1 || decimalPlaces <= abs(minimumWidth), "decimal places must not exceed width");

    return ximpl_real::real_helper_4(value, minimumWidth, decimalPlaces, NULL);
}

/** Inserts the string form of a floating-point value, with the given width,
 * precision and type
 *
 * \ingroup group__inserters
 *
 * \param value The \c double value to be converted to string form
 * \param minimumWidth The minimum width of the resulting string form. If
 *   non-negative, the result will be right-aligned. If negative, the result
 *   will be left-aligned
 * \param decimalPlaces The number of decimal places to be included
 * \param type One of the following characters that denote the type of the
 *   floating-point representation: \c e, \c E, \c f, \c F, \c g, or \c G
 *
 * \pre abs(minimumWidth) < 512
 * \pre decimalPlaces <= minimumWidth
 */
inline stlsoft::basic_shim_string<ff_char_t, 64> real(
    double const&   value
,   int             minimumWidth
,   int             decimalPlaces
,   ff_char_t       type
)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(abs(minimumWidth) < 512, "maximum value for width exceeded");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(abs(minimumWidth) < 1 || decimalPlaces <= abs(minimumWidth), "decimal places must not exceed width");
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(('f' == type) || ('e' == type) || ('E' == type) || ('g' == type) || ('G' == type), "type parameter must be one of 'f', 'e', 'E', 'g' or 'G'");

    return ximpl_real::real_helper_4(value, minimumWidth, decimalPlaces, &type);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::real;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_REAL */

/* ///////////////////////////// end of file //////////////////////////// */
