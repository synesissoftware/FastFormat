/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/storage_size.hpp
 *
 * Purpose:     Inserter functions for storage sizes.
 *
 * Created:     16th August 2010
 * Updated:     25th July 2015
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2010-2015, Matthew Wilson and Synesis Software
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


/** \file fastformat/inserters/storage_size.hpp
 *
 * [C++ only] Inserter functions for storage sizes.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE
#define FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_REVISION  6
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_EDIT      9
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
#include <stlsoft/meta/is_signed_type.hpp>
#include <stlsoft/string/shim_string.hpp>
#if STLSOFT_LEAD_VER >= 0x010a0000
 /* presumption of STLSoft 1.10 */
# include <stlsoft/limits/integral_limits.h>
#else /* ? STLSOFT_LEAD_VER */
# include <stlsoft/util/limit_traits.h>
#endif /* STLSOFT_LEAD_VER */

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
namespace ximpl_storage_size
{

# ifdef FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_
typedef stlsoft::basic_simple_string<ff_char_t>         ff_stg_size_r_t_;
# else /* ? FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_ */
typedef stlsoft::basic_shim_string<ff_char_t, 20 + 3>   ff_stg_size_r_t_;
# endif /* FASTFORMAT_INSERTER_INTEGER_NO_USE_SHIM_STRING_ */

    struct storage_size_constants
    {
        typedef stlsoft::ss_uint16_t        uint16_type;
        typedef stlsoft::ss_uint32_t        uint32_type;
        typedef stlsoft::ss_uint64_t        uint64_type;

        /* Standard SI
         */
        static uint16_type one_kilobyte()
        {
            return STLSOFT_GEN_UINT16_SUFFIX(1000);
        }
        static uint32_type one_megabyte()
        {
            return STLSOFT_GEN_UINT32_SUFFIX(1000000);
        }
        static uint32_type one_gigabyte()
        {
            return STLSOFT_GEN_UINT32_SUFFIX(1000000000);
        }
        static uint64_type one_terabyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1000000000000);
        }
        static uint64_type one_petabyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1000000000000000);
        }
        static uint64_type one_exabyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1000000000000000000);
        }
#if 0
        static uint128_type one_zettabyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1000000000000000000000);
        }
        static uint128_type one_yottabyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1000000000000000000000000);
        }
#endif /* 0 */

        /* Binary SI
         */
        static uint16_type one_kibibyte()
        {
            return STLSOFT_GEN_UINT16_SUFFIX(1024);
        }
        static uint32_type one_mebibyte()
        {
            return STLSOFT_GEN_UINT32_SUFFIX(1048576);
        }
        static uint32_type one_gibibyte()
        {
            return STLSOFT_GEN_UINT32_SUFFIX(1073741824);
        }
        static uint64_type one_tebibyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1099511627776);
        }
        static uint64_type one_pebibyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1125899906842624);
        }
        static uint64_type one_exbibyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1152921504606846976);
        }
#if 0
        static uint128_type one_zebibyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1180591620717411303424);
        }
        static uint128_type one_yobibyte()
        {
            return STLSOFT_GEN_UINT64_SUFFIX(1208925819614629174706176);
        }
#endif /* 0 */

        template <typename I>
        static
        bool
        is_definitely_giga_or_more(
            I const& i
        )
        {
            stlsoft::uint64_t const& i2 = i;

            return 0 != (i2 >> 32);
        }

        static
        bool
        is_definitely_giga_or_more(
            stlsoft::uint8_t const&
        )
        {
            return false;
        }

        static
        bool
        is_definitely_giga_or_more(
            stlsoft::uint16_t const&
        )
        {
            return false;
        }

    };

template <typename I>
inline
ximpl_storage_size::ff_stg_size_r_t_
storage_size_(
    I /* const& */ i
)
{

    ff_char_t   buffer[21 + 2];
    size_t      cch2    =   2u;
    char const* suffix;

    /*
         * 
         * 1000    -   KiloByte
         * 1024    -   KibiByte
         * 
         * kilobyte  (kB)  10^3     2^10     0.9766  kibibyte (KiB)  2^10
         * megabyte (MB)   10^6     2^20     0.9537  mebibyte (MiB)  2^20
         * gigabyte (GB)   10^9     2^30     0.9313  gibibyte (GiB)  2^30
         * terabyte (TB)   10^12    2^40     0.9095  tebibyte (TiB)  2^40
         * petabyte (PB)   10^15    2^50     0.8882  pebibyte (PiB)  2^50
         * exabyte (EB)    10^18    2^60     0.8674  exbibyte (EiB)  2^60
         * zettabyte (ZB)  10^21    2^70     0.8470  zebibyte (ZiB)  2^70
         * yottabyte (YB)  10^24    2^80     0.8272  yobibyte (YiB)  2^80
         * 
         */

#if 0
# if 0
    if(i >= ximpl_storage_size::storage_size_constants::one_yottabyte())
    {
        suffix = "YB";
        i /= ximpl_storage_size::storage_size_constants::one_yottabyte();
    }
    else
    if(i >= ximpl_storage_size::storage_size_constants::one_zettabyte())
    {
        suffix = "ZB";
        i /= ximpl_storage_size::storage_size_constants::one_zettabyte();
    }
    else
# endif /* 0 */
    if(i >= ximpl_storage_size::storage_size_constants::one_exabyte())
    {
        suffix = "EB";
        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_exabyte());
    }
    else
    if(i >= ximpl_storage_size::storage_size_constants::one_petabyte())
    {
        suffix = "PB";
        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_petabyte());
    }
    else
    if(i >= ximpl_storage_size::storage_size_constants::one_terabyte())
    {
        suffix = "TB";
        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_terabyte());
    }
    else
    if(i >= ximpl_storage_size::storage_size_constants::one_gigabyte())
    {
        suffix = "GB";
        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_gigabyte());
    }
    else
    if(i >= ximpl_storage_size::storage_size_constants::one_megabyte())
    {
        suffix = "MB";
        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_megabyte());
    }
    else
    if(i >= ximpl_storage_size::storage_size_constants::one_kilobyte())
    {
        suffix = "kB";
        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_kilobyte());
    }
    else
    {
        suffix  =   "B";
        cch2    =   1u;
    }
#else /* ? 0 */

    // Slight optimisation, looking for definitely large numbers
    if(ximpl_storage_size::storage_size_constants::is_definitely_giga_or_more(i))
    {
        goto is_giga_or_more;
    }

    if(i >= ximpl_storage_size::storage_size_constants::one_kilobyte())
    {
        if(i >= ximpl_storage_size::storage_size_constants::one_megabyte())
        {
            if(i >= ximpl_storage_size::storage_size_constants::one_gigabyte())
            {
is_giga_or_more:
                if(i >= ximpl_storage_size::storage_size_constants::one_terabyte())
                {
                    if(i >= ximpl_storage_size::storage_size_constants::one_petabyte())
                    {
                        if(i >= ximpl_storage_size::storage_size_constants::one_exabyte())
                        {
                            suffix = "EB";
                            i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_exabyte());
                        }
                        else
                        {
# if 0
                            if(i >= ximpl_storage_size::storage_size_constants::one_zettabyte())
                            {
                                if(i >= ximpl_storage_size::storage_size_constants::one_yottabyte())
                                {
                                    suffix = "YB";
                                    i /= ximpl_storage_size::storage_size_constants::one_yottabyte();
                                }
                                else
                                {
                                    suffix = "ZB";
                                    i /= ximpl_storage_size::storage_size_constants::one_zettabyte();
                                }
                            }
                            else

# endif /* 0 */
                            {
                                suffix = "PB";
                                i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_petabyte());
                            }
                        }
                    }
                    else
                    {
                        suffix = "TB";
                        i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_terabyte());
                    }
                }
                else
                {
                    suffix = "GB";
                    i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_gigabyte());
                }
            }
            else
            {
                suffix = "MB";
                i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_megabyte());
            }
        }
        else
        {
            suffix = "kB";
            i /= static_cast<I>(ximpl_storage_size::storage_size_constants::one_kilobyte());
        }
    }
    else
    {
        suffix  =   "B";
        cch2    =   1u;
    }
#endif /* 0 */

    STLSOFT_ASSERT(cch2 <= 2u);

    size_t              cch1;
#if STLSOFT_LEAD_VER >= 0x010a0000
    ff_char_t const*    s = stlsoft::integer_to_string(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer) - 2u, i, &cch1);
#else /* ? STLSOFT_LEAD_VER */
    ff_char_t const*    s = stlsoft::integer_to_string(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer) - 2u, i, cch1);
#endif /* STLSOFT_LEAD_VER */

    ff_char_t* t = &buffer[0] + STLSOFT_NUM_ELEMENTS(buffer) - (1u + 2u);
    for(; '\0' != *suffix; ++t, ++suffix)
    {
        *t = *suffix;
    }
    *t = '\0';

    return ximpl_storage_size::ff_stg_size_r_t_(s, cch1 + cch2);
}


} /* namespace ximpl_storage_size */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Inserter functions
 */

/** Inserts an integer in size-qualified form.
 *
 * \ingroup group__inserters
 *
 * Size-qualified form is determined in orders of 1000. For example, a value
 * of 990 will be inserted as "990B", a value of 12,345 as "12kB", a value
 * of 1,234,567 as "1MB", and so on.
 *
 * \param i The value to be inserted (in size-qualified form).
 */
template <typename I>
inline
ximpl_storage_size::ff_stg_size_r_t_
  storage_size(
    I /* const& */ i
)
{
    STLSOFT_STATIC_ASSERT(stlsoft::is_integral_type<I>::value);
    STLSOFT_STATIC_ASSERT(!stlsoft::is_signed_type<I>::value); // Only valid for unsigned types (since can't have -ve storage size)

    return ximpl_storage_size::storage_size_(i);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::storage_size;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE */

/* ///////////////////////////// end of file //////////////////////////// */
