/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.inserters.storage_size.cpp
 *
 * Purpose:     Implementation file for the test.unit.inserters.storage_size project.
 *
 * Created:     23rd July 2015
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/inserters/storage_size.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/integer_to_string.hpp>

/* Standard C++ header files */
#include <numeric>
#include <string>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL_(x, a)    XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL_          XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_zero(void);
    static void text_B(void);
    static void text_KB(void);
    static void text_MB(void);
    static void text_GB(void);
    static void text_TB(void);
    static void text_PB(void);
    static void text_ZB(void);
    static void test_1_8(void);
    static void test_1_9(void);
    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_12(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.inserters.storage_size", verbosity))
    {
        XTESTS_RUN_CASE(test_zero);
        XTESTS_RUN_CASE(text_B);
        XTESTS_RUN_CASE(text_KB);
        XTESTS_RUN_CASE(text_MB);
        XTESTS_RUN_CASE(text_GB);
        XTESTS_RUN_CASE(text_TB);
        XTESTS_RUN_CASE(text_PB);
        XTESTS_RUN_CASE(text_ZB);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;
    using   fastformat::string_slice_t;
    using   fastformat::fastformat_accumulateSliceLengths;

    typedef std::basic_string<ff_char_t>    string_t;

    using   stlsoft::uint32_t;
    using   stlsoft::uint64_t;

    template <ss_typename_param_k I>
    string_t
    itos_suf(
        I const&            i
    ,   ff_char_t const*    suffix
    )
    {
        ff_char_t           num[21];
        size_t              n;
        ff_char_t const*    s = stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), i, &n);

        return string_t(s, n) + suffix;
    }
                    



static void test_zero()
{
    XTESTS_TEST_STRING_EQUAL("0B", fastformat::storage_size(0u));
}

static void text_B()
{
    { for(uint32_t i = 0; i != 1000; ++i)
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i, FASTFORMAT_LITERAL_STRING("B")), fastformat::storage_size(i)));
    }}
}

static void text_KB()
{
    { for(uint32_t i = 1000; i != 1000000; ++i)
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i / 1000, FASTFORMAT_LITERAL_STRING("kB")), fastformat::storage_size(i)));
    }}
}

static void text_MB()
{
    { for(uint32_t i = 1000000; i != 1000000000; i += 1000)
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i / 1000000, FASTFORMAT_LITERAL_STRING("MB")), fastformat::storage_size(i)));
    }}
}

static void text_GB()
{
    { for(uint64_t i = 1000000000; i != STLSOFT_GEN_UINT64_SUFFIX(1000000000000); i += 1000000)
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i / 1000000000, FASTFORMAT_LITERAL_STRING("GB")), fastformat::storage_size(i)));
    }}
}

static void text_TB()
{
    { for(uint64_t i = STLSOFT_GEN_UINT64_SUFFIX(1000000000000); i != STLSOFT_GEN_UINT64_SUFFIX(1000000000000000); i += 1000000000)
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i / STLSOFT_GEN_UINT64_SUFFIX(1000000000000), FASTFORMAT_LITERAL_STRING("TB")), fastformat::storage_size(i)));
    }}
}

static void text_PB()
{
    { for(uint64_t i = STLSOFT_GEN_UINT64_SUFFIX(1000000000000000); i != STLSOFT_GEN_UINT64_SUFFIX(1000000000000000000); i += STLSOFT_GEN_UINT64_SUFFIX(1000000000000))
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i / STLSOFT_GEN_UINT64_SUFFIX(1000000000000000), FASTFORMAT_LITERAL_STRING("PB")), fastformat::storage_size(i)));
    }}
}

static void text_ZB()
{
    { for(uint64_t i = STLSOFT_GEN_UINT64_SUFFIX(1000000000000000000); i != STLSOFT_GEN_UINT64_SUFFIX(10000000000000000000); i += STLSOFT_GEN_UINT64_SUFFIX(1000000000000000))
    {
        XTESTS_REQUIRE(XTESTS_TEST_STRING_EQUAL_(itos_suf(i / STLSOFT_GEN_UINT64_SUFFIX(1000000000000000000), FASTFORMAT_LITERAL_STRING("EB")), fastformat::storage_size(i)));
    }}
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
