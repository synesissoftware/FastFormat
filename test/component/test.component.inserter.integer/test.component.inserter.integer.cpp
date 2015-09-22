/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.inserter.integer.cpp
 *
 * Purpose:     Implementation file for the test.component.inserter.integer project.
 *
 * Created:     26th April 2008
 * Updated:     8th March 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/inserters/integer.hpp>
#include <fastformat/inserters/to_i.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/string/trim_functions.hpp>
#include <stlsoft/util/minmax.hpp>

/* Standard C Header Files */
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Decimal places expected as correct, per compiler
 */

namespace
{

#if defined(STLSOFT_COMPILER_IS_MSVC)
    const int   CORRECT_DEC_PLACES  =   511;
#elif defined(STLSOFT_COMPILER_IS_BORLAND)
    const int   CORRECT_DEC_PLACES  =   12;
    const int   MAX_DEC_PLACES      =   35;
#elif defined(STLSOFT_COMPILER_IS_GCC)
    const int   CORRECT_DEC_PLACES  =   12;
#elif defined(STLSOFT_COMPILER_IS_MWERKS)
    const int   CORRECT_DEC_PLACES  =   12;
#else
    const int   CORRECT_DEC_PLACES  =   20;
#endif

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
    static void test_1_5(void);
    static void test_1_6(void);
    static void test_1_7(void);
    static void test_1_8(void);
    static void test_1_9(void);
#if 0
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
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);

    static void test_2_0(void);
    static void test_2_1(void);
    static void test_2_2(void);
    static void test_2_3(void);
    static void test_2_4(void);
    static void test_2_5(void);
    static void test_2_6(void);
    static void test_2_7(void);
    static void test_2_8(void);
    static void test_2_9(void);
    static void test_2_10(void);
    static void test_2_11(void);
    static void test_2_12(void);
    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
    static void test_2_16(void);
    static void test_2_17(void);
    static void test_2_18(void);
    static void test_2_19(void);
    static void test_2_20(void);
    static void test_2_28(void);
    static void test_2_29(void);

    static void test_3_0(void);
    static void test_3_1(void);
    static void test_3_2(void);
    static void test_3_3(void);
    static void test_3_4(void);
    static void test_3_5(void);
    static void test_3_6(void);
    static void test_3_7(void);
    static void test_3_8(void);
    static void test_3_9(void);
    static void test_3_10(void);
    static void test_3_11(void);
    static void test_3_12(void);
    static void test_3_13(void);
    static void test_3_14(void);
    static void test_3_15(void);
    static void test_3_16(void);
    static void test_3_17(void);
    static void test_3_18(void);
    static void test_3_19(void);
    static void test_3_20(void);
    static void test_3_28(void);
    static void test_3_29(void);
#endif /* 0 */

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.inserter.integer", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
#if 0
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
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);

        XTESTS_RUN_CASE(test_2_0);
        XTESTS_RUN_CASE(test_2_1);
        XTESTS_RUN_CASE(test_2_2);
        XTESTS_RUN_CASE(test_2_3);
        XTESTS_RUN_CASE(test_2_4);
        XTESTS_RUN_CASE(test_2_5);
        XTESTS_RUN_CASE(test_2_6);
        XTESTS_RUN_CASE(test_2_7);
        XTESTS_RUN_CASE(test_2_8);
        XTESTS_RUN_CASE(test_2_9);
        XTESTS_RUN_CASE(test_2_10);
        XTESTS_RUN_CASE(test_2_11);
        XTESTS_RUN_CASE(test_2_12);
        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16);
        XTESTS_RUN_CASE(test_2_17);
        XTESTS_RUN_CASE(test_2_18);
        XTESTS_RUN_CASE(test_2_19);
        XTESTS_RUN_CASE(test_2_20);
        XTESTS_RUN_CASE(test_2_28);
        XTESTS_RUN_CASE(test_2_29);

        XTESTS_RUN_CASE(test_3_0);
        XTESTS_RUN_CASE(test_3_1);
        XTESTS_RUN_CASE(test_3_2);
        XTESTS_RUN_CASE(test_3_3);
        XTESTS_RUN_CASE(test_3_4);
        XTESTS_RUN_CASE(test_3_5);
        XTESTS_RUN_CASE(test_3_6);
        XTESTS_RUN_CASE(test_3_7);
        XTESTS_RUN_CASE(test_3_8);
        XTESTS_RUN_CASE(test_3_9);
        XTESTS_RUN_CASE(test_3_10);
        XTESTS_RUN_CASE(test_3_11);
        XTESTS_RUN_CASE(test_3_12);
        XTESTS_RUN_CASE(test_3_13);
        XTESTS_RUN_CASE(test_3_14);
        XTESTS_RUN_CASE(test_3_15);
        XTESTS_RUN_CASE(test_3_16);
        XTESTS_RUN_CASE(test_3_17);
        XTESTS_RUN_CASE(test_3_18);
        XTESTS_RUN_CASE(test_3_19);
        XTESTS_RUN_CASE(test_3_20);
        XTESTS_RUN_CASE(test_3_28);
        XTESTS_RUN_CASE(test_3_29);
#endif /* 0 */

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

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL_(x, a)        XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL(x, a)         XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define XTESTS_TEST_STRING_EQUAL_N(x, a, n)    XTESTS_TEST_WIDE_STRING_EQUAL_N(FASTFORMAT_LITERAL_STRING(x), a, n)
# define XTESTS_TEST_STRING_CONTAIN(x, a)       XTESTS_TEST_WIDE_STRING_CONTAIN(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL_              XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL               XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N             XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_STRING_CONTAIN             XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                  FASTFORMAT_LITERAL_STRING

    static string_t crlf(ff::getNewlineForPlatform().ptr, ff::getNewlineForPlatform().len);

    static const int    values[] =
    {
            0
        ,   -1
        ,   +1
        ,   -3
        ,   +3
        ,   -10
        ,   +10
        ,   -30
        ,   +30
        ,   -100
        ,   +100
        ,   -300
        ,   +300
        ,   -1000
        ,   +1000
        ,   -3000
        ,   +3000
        ,   -10000
        ,   +10000
        ,   -30000
        ,   +30000
        ,   -100000
        ,   +100000
        ,   -300000
        ,   +300000
        ,   -1000000
        ,   +1000000
        ,   -3000000
        ,   +3000000
        ,   -10000000
        ,   +10000000
        ,   -30000000
        ,   +30000000
        ,   -100000000
        ,   +100000000
        ,   -300000000
        ,   +300000000
        ,   -1000000000
        ,   +1000000000
        ,   -2000000000
        ,   +2000000000
        ,   INT_MIN
        ,   INT_MAX
    };

static void test_1_0()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::to_i(0));

    XTESTS_TEST_STRING_EQUAL("0", sink);
}

static void test_1_1()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::to_i(1));

    XTESTS_TEST_STRING_EQUAL("1", sink);
}

static void test_1_2()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::to_i(-1));

    XTESTS_TEST_STRING_EQUAL("-1", sink);
}

static void test_1_3()
{
}

static void test_1_4()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        std::basic_string<ff_char_t>    sink;
        ff_char_t                       expected[21];

        ff::fmt(sink, FF_STR("{0}"), ff::to_i(value));

        ff_char_t const* s = stlsoft::integer_to_string(expected, STLSOFT_NUM_ELEMENTS(expected), value);

        XTESTS_TEST_STRING_EQUAL_(s, sink);
    }}
}

static void test_1_5()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        std::basic_string<ff_char_t>    sink;
        ff_char_t                       expected[21];

        ff::fmt(sink, FF_STR("{0}"), ff::to_i(value, 30));

        XTESTS_TEST_INTEGER_EQUAL(30u, sink.size());

        stlsoft::trim_left(sink);

        ff_char_t const* s = stlsoft::integer_to_string(expected, STLSOFT_NUM_ELEMENTS(expected), value);

        XTESTS_TEST_STRING_EQUAL_(s, sink);
    }}
}

static void test_1_6()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        std::basic_string<ff_char_t>    sink;
        ff_char_t                       expected[21];

        ff::fmt(sink, FF_STR("{0}"), ff::to_i(value, -30));

        XTESTS_TEST_INTEGER_EQUAL(30u, sink.size());

        stlsoft::trim_right(sink);

        ff_char_t const* s = stlsoft::integer_to_string(expected, STLSOFT_NUM_ELEMENTS(expected), value);

        XTESTS_TEST_STRING_EQUAL_(s, sink);
    }}
}

static void test_1_7()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        std::basic_string<ff_char_t>    sink;
        ff_char_t                       expected[30 + 1]; // 29 digits, possible - sign, nul terminator

        fastformat::fastformat_util_snprintf(&expected[0], STLSOFT_NUM_ELEMENTS(expected), FASTFORMAT_LITERAL_STRING("%-30.29d"), value);

        ff::fmt(sink, FF_STR("{0}"), ff::to_i(value, -30, 29));

        XTESTS_TEST_INTEGER_EQUAL(30u, sink.size());
        XTESTS_TEST_STRING_EQUAL_(expected, sink);
    }}
}

static void test_1_8()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        std::basic_string<ff_char_t>    sink;
        ff_char_t                       expected[31 + 1]; // 30 digits, possible - sign, nul terminator

        fastformat::fastformat_util_snprintf(&expected[0], STLSOFT_NUM_ELEMENTS(expected), FASTFORMAT_LITERAL_STRING("%-30.30d"), value);

        ff::fmt(sink, FF_STR("{0}"), ff::to_i(value, -30, 30));

        XTESTS_TEST_INTEGER_LESS(32u, sink.size());
        XTESTS_TEST_INTEGER_GREATER(29u, sink.size());
        XTESTS_TEST_STRING_EQUAL_(expected, sink);
    }}
}

static void test_1_9()
{
    // Write each value into a variety of widths and precisions

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        { for(int width = 1; width != 40; ++width)
        {
            { for(int precision = width; precision != 40 + 1; ++precision)
            {
                std::basic_string<ff_char_t>    sink;
                ff_char_t                       fmt[21];
                std::basic_string<ff_char_t>    plain(stlsoft::integer_to_string(fmt, STLSOFT_NUM_ELEMENTS(fmt), value));

                fastformat::fastformat_util_snprintf(&fmt[0], STLSOFT_NUM_ELEMENTS(fmt), FASTFORMAT_LITERAL_STRING("%%%d.%dd"), width, precision);

                ff_char_t                       expected[101];

                fastformat::fastformat_util_snprintf(&expected[0], STLSOFT_NUM_ELEMENTS(expected), fmt, value);

                ff::fmt(sink, FF_STR("{0}"), ff::to_i(value, width, precision));

                // Ensure that the width is not less than the precision, and not
                // more than max(width, max(precision, plain.size()))

                size_t maxWidth = stlsoft::maximum(size_t(width), stlsoft::maximum(size_t(precision), plain.size()));

                XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(plain.size(), sink.size());
                XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(size_t(width), sink.size());
                XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(size_t(precision), sink.size());
                if(value < 0 && size_t(precision) >= plain.size())
                {
                    // In this case the leading zeros AND the - sign will push it one over

                    XTESTS_TEST_INTEGER_EQUAL(maxWidth + 1u, sink.size());
                }
                else
                {
                    XTESTS_TEST_INTEGER_EQUAL(maxWidth, sink.size());
                }
                XTESTS_TEST_STRING_EQUAL_(expected, sink);
            }}
        }}
    }}
}

#if 0
static void test_1_10()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 5));

    XTESTS_TEST_STRING_EQUAL("12345.67000", sink);
}

static void test_1_11()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 6));

    XTESTS_TEST_STRING_EQUAL("12345.670000", sink);
}

static void test_1_12()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, 5));

    XTESTS_TEST_STRING_EQUAL("12345.67000", sink);
}

static void test_1_13()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, -1));

    XTESTS_TEST_STRING_EQUAL("12345.670000", sink);
}

static void test_1_14()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 20, -1));

    XTESTS_TEST_STRING_EQUAL("               12346", sink);
}

static void test_1_15()
{
}

static void test_1_16()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 7, 7));

    XTESTS_TEST_STRING_EQUAL("12345.6700000", sink);
}


static void test_1_17()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 15, 15));

//    XTESTS_TEST_STRING_EQUAL("12345.670000000000000", sink);
    XTESTS_TEST_STRING_EQUAL_N("12345.670000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));
}

static void test_1_18()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 31, 31));

//    XTESTS_TEST_STRING_EQUAL("12345.6700000000000000000000000000000", sink);
    XTESTS_TEST_STRING_EQUAL_N("12345.6700000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));
}

static void test_1_19()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 63, 63));

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

//    XTESTS_TEST_STRING_EQUAL("12345.670000000000000000000000000000000000000000000000000000000000000", sink);
    XTESTS_TEST_STRING_EQUAL_N("12345.670000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_20()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 127, 127));

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

//    XTESTS_TEST_STRING_EQUAL("12345.6700000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink);
    XTESTS_TEST_STRING_EQUAL_N("12345.6700000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_21()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 255, 255));

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

//    XTESTS_TEST_STRING_EQUAL("12345.670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink);
    XTESTS_TEST_STRING_EQUAL_N("12345.670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_22()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 511, 511));

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

//    XTESTS_TEST_STRING_EQUAL("12345.6700000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink);
    XTESTS_TEST_STRING_EQUAL_N("12345.6700000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_23()
{
}

static void test_1_24()
{
}

static void test_1_25()
{
}

static void test_1_26()
{
}

static void test_1_27()
{
}

static void test_1_28()
{
}

static void test_1_29()
{
}





static void test_2_0()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(123.456, -1, -1, 'g'));

    XTESTS_TEST_STRING_EQUAL("123.456", sink);
}

static void test_2_1()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(123.456, 0, 3, 'g'));

    XTESTS_TEST_STRING_EQUAL("123", sink);
}

static void test_2_2()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(123.456, 10, 3, 'g'));

    XTESTS_TEST_STRING_EQUAL("       123", sink);
}

static void test_2_3()
{
}

static void test_2_4()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, -1, 'g'));

    XTESTS_TEST_STRING_EQUAL("12345.7", sink);
}

static void test_2_5()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 0, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
//    XTESTS_TEST_STRING_EQUAL("    1e+004", sink);
}

static void test_2_6()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 1, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
//    XTESTS_TEST_STRING_EQUAL("    1e+004", sink);
}

static void test_2_7()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 2, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.2e+", sink);
//    XTESTS_TEST_STRING_EQUAL("  1.2e+004", sink);
}

static void test_2_8()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 3, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.23e+", sink);
//    XTESTS_TEST_STRING_EQUAL(" 1.23e+004", sink);
}

static void test_2_9()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 4, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.235e+004", sink);
}

static void test_2_10()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 5, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_EQUAL("     12346", sink);
}

static void test_2_11()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 6, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_EQUAL("   12345.7", sink);
}

static void test_2_12()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, 5, 'g'));

    XTESTS_TEST_STRING_EQUAL("12346", sink);
}

static void test_2_13()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, -1, 'g'));

    XTESTS_TEST_STRING_EQUAL("12345.7", sink);
}

static void test_2_14()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 20, -1, 'g'));

    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
//    XTESTS_TEST_STRING_EQUAL("              1e+004", sink);
}

static void test_2_15()
{
#if 1

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 15, 15, 'g'));

    XTESTS_TEST_STRING_EQUAL("       12345.67", sink);

#endif /* compiler */
}

static void test_2_16()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 31, 7, 'g'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

//#if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("                       12345.67", sink);

//#endif /* compiler */
}

static void test_2_17()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 63, 7, 'g'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                       12345.67", sink);

#endif /* compiler */
}

static void test_2_18()
{
#if !defined(STLSOFT_COMPILER_IS_GCC)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 127, 127, 'g'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                                                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_19()
{
#if !defined(STLSOFT_COMPILER_IS_GCC)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 255, 255, 'g'));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                                                                                                                                                                                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_20()
{
#if !defined(STLSOFT_COMPILER_IS_GCC)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 511, 511, 'g'));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_28()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(1e-10, -1, -1, 'g'));

    XTESTS_TEST_STRING_CONTAIN("1e-", sink);
//    XTESTS_TEST_STRING_EQUAL("1e-010", sink);
}

static void test_2_29()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(1e-10, -1, -1, 'g'));

    XTESTS_TEST_STRING_CONTAIN("1e-", sink);
//    XTESTS_TEST_STRING_EQUAL("1e-010", sink);
}




static void test_3_0()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(123.456, -1, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.234560e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.234560e+002", sink);
}

static void test_3_1()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(123.456, 0, 3, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.235e+002", sink);
}

static void test_3_2()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(123.456, 10, 3, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.235e+002", sink);
}

static void test_3_3()
{
}

static void test_3_4()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.234567e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.234567e+004", sink);
}

static void test_3_5()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 0, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
//    XTESTS_TEST_STRING_EQUAL("    1e+004", sink);
}

static void test_3_6()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 1, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.2e+", sink);
//    XTESTS_TEST_STRING_EQUAL("  1.2e+004", sink);
}

static void test_3_7()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 2, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.23e+", sink);
//    XTESTS_TEST_STRING_EQUAL(" 1.23e+004", sink);
}

static void test_3_8()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 3, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.235e+004", sink);
}

static void test_3_9()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 4, 'e'));

//  XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.2346e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.2346e+004", sink);
}

static void test_3_10()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 5, 'e'));

//  XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.23457e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.23457e+004", sink);
}

static void test_3_11()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 10, 6, 'e'));

//  XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.234567e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.234567e+004", sink);
}

static void test_3_12()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, 5, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.23457e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.23457e+004", sink);
}

static void test_3_13()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, -1, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.234567e+", sink);
//    XTESTS_TEST_STRING_EQUAL("1.234567e+004", sink);
}

static void test_3_14()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 20, -1, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(20u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
//    XTESTS_TEST_STRING_EQUAL("              1e+004", sink);
}

static void test_3_15()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 15, 15, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

#if defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000e+04", sink);

#elif defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000e+004", sink);

#else 

#endif /* compiler */
}

static void test_3_16()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 31, 31, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

#if defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL_N("1.2345670000000000000000000000000e+04", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#elif defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.2345670000000000000000000000000e+004", sink);

#else 

#endif /* compiler */
}

static void test_3_17()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 63, 63, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000000000000000000000000000000000000000000000000000e+004", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_3_18()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 127, 127, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.2345670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+004", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_3_19()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 255, 255, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+004", sink);

# endif /* compiler */
# endif /* compiler */
}

static void test_3_20()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(12345.67, 511, 511, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.2345670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+004", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_3_28()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(1e-10, -1, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.000000e-", sink);
//    XTESTS_TEST_STRING_EQUAL("1.000000e-010", sink);
}

static void test_3_29()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::integer(1e-10, -1, -1, 'E'));

    XTESTS_TEST_STRING_CONTAIN("1.000000E-", sink);
//    XTESTS_TEST_STRING_EQUAL("1.000000E-010", sink);
}
#endif /* 0 */


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */

