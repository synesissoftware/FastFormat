/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/inserters/storage_size.hpp
 *
 * Purpose:     Inserter functions for storage sizes.
 *
 * Created:     16th August 2010
 * Updated:     21st January 2017
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2010-2017, Matthew Wilson and Synesis Software
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
 * version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_MINOR     0
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_REVISION  7
# define FASTFORMAT_VER_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE_EDIT      11
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/util/string/snprintf.h>
#include <fastformat/internal/inserters/int_typedefs.hpp>

#include <platformstl/platformstl.h>
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
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace inserters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * implementation
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

    /*
     * 
     * 1000    -   KiloByte
     * 1024    -   KibiByte
     * 
     * kilobyte  (kB)  10^3     2^10     0.9766  kibibyte (KiB)  2^10   int16
     * megabyte (MB)   10^6     2^20     0.9537  mebibyte (MiB)  2^20   int32
     * gigabyte (GB)   10^9     2^30     0.9313  gibibyte (GiB)  2^30   int32
     * terabyte (TB)   10^12    2^40     0.9095  tebibyte (TiB)  2^40   int64
     * petabyte (PB)   10^15    2^50     0.8882  pebibyte (PiB)  2^50   int64
     * exabyte (EB)    10^18    2^60     0.8674  exbibyte (EiB)  2^60   int64
     * zettabyte (ZB)  10^21    2^70     0.8470  zebibyte (ZiB)  2^70   
     * yottabyte (YB)  10^24    2^80     0.8272  yobibyte (YiB)  2^80   
     *
     *
     * Max OOMs:
     *
     *  uint8   1
     *  uint16  3
     *  uint32  8
     *  uint64  18
     */

#if 0
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

#endif
};


static
size_t
lookup_suffix_(
    size_t              oom
,   ff_char_t const**   pps 
)
{
    // Do x [4] in case want to change/borrow for Kibbi, etc.
    static ff_char_t const symbols[27][4] =
    {
        FASTFORMAT_LITERAL_STRING("B"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("kB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("MB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("GB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("TB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("PB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("EB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("ZB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

        FASTFORMAT_LITERAL_STRING("YB"),
        FASTFORMAT_LITERAL_STRING("??"),
        FASTFORMAT_LITERAL_STRING("??"),

    };

    switch(oom)
    {
        case  0:
            *pps = symbols[0];
            return 1;
        case     3:
        case     6:
        case     9:
        case    12:
        case    15:
        case    18:
        case    21:
        case    24:
            *pps = symbols[oom];
            return 2;
        default:
            STLSOFT_ASSERT(false);
            *pps = NULL;
            return 0;
    }
}

template <typename I>
ximpl_storage_size::ff_stg_size_r_t_
storage_size_with_suffix_(
    I /* const& */      i
,   ff_char_t const*    suffix
,   size_t              cchSuffix
)
{
    ff_char_t           buffer[20 + 3 + 1];
    size_t const        cch2    =   cchSuffix;
    size_t              cch1;
    ff_char_t const*    s       =   stlsoft::integer_to_string(&buffer[0], STLSOFT_NUM_ELEMENTS(buffer) - 2u, i, &cch1);

    ff_char_t* t = &buffer[0] + STLSOFT_NUM_ELEMENTS(buffer) - (1u + 2u);
    for(; '\0' != *suffix; ++t, ++suffix)
    {
        *t = *suffix;
    }
    *t = '\0';

    return ximpl_storage_size::ff_stg_size_r_t_(s, cch1 + cch2);
}

ximpl_storage_size::ff_stg_size_r_t_
storage_size_(
    stlsoft::uint8_t    i
)
{
    ff_char_t const*    suffix;
    size_t const        cchSuffix   =   lookup_suffix_(0, &suffix);

    return storage_size_with_suffix_(i, suffix, cchSuffix);
}

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER < 1600

template <typename I>
ximpl_storage_size::ff_stg_size_r_t_
storage_size_(
    I /* const& */      i
)
{
    size_t              oom         =   0;

    for(; i >= 1000; )
    {
        i   /=  1000;
        oom +=   3;
    }

    ff_char_t const*    suffix;
    size_t const        cchSuffix   =   lookup_suffix_(oom, &suffix);

    return storage_size_with_suffix_(i, suffix, cchSuffix);
}

#else
ximpl_storage_size::ff_stg_size_r_t_
storage_size_(
    stlsoft::uint16_t   i
)
{
    size_t              oom         =   0;

    if(i >= 1000)
    {
        i   /=  1000;
        oom +=  3;
    }

    ff_char_t const*    suffix;
    size_t const        cchSuffix   =   lookup_suffix_(oom, &suffix);

    return storage_size_with_suffix_(i, suffix, cchSuffix);
}

ximpl_storage_size::ff_stg_size_r_t_
storage_size_(
    stlsoft::uint32_t   i
)
{
    size_t              oom         =   0;

    for(; i >= 1000; )
    {
        i   /=  1000;
        oom +=   3;
    }

    ff_char_t const*    suffix;
    size_t const        cchSuffix   =   lookup_suffix_(oom, &suffix);

    return storage_size_with_suffix_(i, suffix, cchSuffix);
}
#endif

ximpl_storage_size::ff_stg_size_r_t_
storage_size_(
    stlsoft::uint64_t   i
)
{
#if 0 ||\
    defined(PLATFORMSTL_ARCH_IS_X86) ||\
    0
    if(0 == (STLSOFT_GEN_UINT64_SUFFIX(0xFFFFFFFF00000000) & i))
    {
        return storage_size_(static_cast<stlsoft::uint32_t>(i));
    }
#endif

    size_t              oom         =   0;

    for(; i >= 1000; )
    {
        i   /=  1000;
        oom +=   3;
    }

    ff_char_t const*    suffix;
    size_t const        cchSuffix   =   lookup_suffix_(oom, &suffix);

    return storage_size_with_suffix_(i, suffix, cchSuffix);
}

} /* namespace ximpl_storage_size */
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * inserter functions
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
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} // namespace inserters
using ::fastformat::inserters::storage_size;
} // namespace fastformat
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !FASTFORMAT_INCL_FASTFORMAT_INSERTERS_HPP_STORAGE_SIZE */

/* ///////////////////////////// end of file //////////////////////////// */
