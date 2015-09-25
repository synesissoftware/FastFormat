/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.iterators.format_iterator.cpp
 *
 * Purpose:     Implementation file for the test.component.iterators.format_iterator project.
 *
 * Created:     26th April 2008
 * Updated:     25th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/iterators/format_iterator.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/minmax.hpp>

/* Standard C header files */
#include <math.h>
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Decimal places expected as correct, per compiler
 */

namespace
{

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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.iterators.format_iterator", verbosity))
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

    ff_char_t const*  strings[] =
    {
        FASTFORMAT_LITERAL_STRING(""),
        FASTFORMAT_LITERAL_STRING("abc"),
        FASTFORMAT_LITERAL_STRING("def"),
        FASTFORMAT_LITERAL_STRING("ghi"),
        FASTFORMAT_LITERAL_STRING("jkl"),
        FASTFORMAT_LITERAL_STRING("mno"),
        FASTFORMAT_LITERAL_STRING("pqr"),
        FASTFORMAT_LITERAL_STRING("stu"),
        FASTFORMAT_LITERAL_STRING("v"),
        FASTFORMAT_LITERAL_STRING("w"),
        FASTFORMAT_LITERAL_STRING("x"),
        FASTFORMAT_LITERAL_STRING("y"),
        FASTFORMAT_LITERAL_STRING("z"),
    };

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)         XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define XTESTS_TEST_STRING_EQUAL_N(x, a, n)    XTESTS_TEST_WIDE_STRING_EQUAL_N(FASTFORMAT_LITERAL_STRING(x), a, n)
# define XTESTS_TEST_STRING_CONTAIN(x, a)       XTESTS_TEST_WIDE_STRING_CONTAIN(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL               XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N             XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_STRING_CONTAIN             XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                  FASTFORMAT_LITERAL_STRING




static void test_1_0()
{
    std::basic_string<ff_char_t> sink;

    std::copy(
        strings,
        strings + STLSOFT_NUM_ELEMENTS(strings),
        fastformat::format_iterator(sink, FASTFORMAT_LITERAL_STRING("{0}")));

    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", sink);
}

static void test_1_1()
{
    std::basic_string<ff_char_t> sink;

    std::copy(
        strings,
        strings + STLSOFT_NUM_ELEMENTS(strings),
        fastformat::format_iterator(
            sink,
            FASTFORMAT_LITERAL_STRING("{1}{0}{2}"),
            FASTFORMAT_LITERAL_STRING("["),
            FASTFORMAT_LITERAL_STRING("]")));

    XTESTS_TEST_STRING_EQUAL("[][abc][def][ghi][jkl][mno][pqr][stu][v][w][x][y][z]", sink);
}

static void test_1_2()
{
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
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

static void test_1_20()
{
}

static void test_1_21()
{
}

static void test_1_22()
{
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
}

static void test_2_1()
{
}

static void test_2_2()
{
}

static void test_2_3()
{
}

static void test_2_4()
{
}

static void test_2_5()
{
}

static void test_2_6()
{
}

static void test_2_7()
{
}

static void test_2_8()
{
}

static void test_2_9()
{
}

static void test_2_10()
{
}

static void test_2_11()
{
}

static void test_2_12()
{
}

static void test_2_13()
{
}

static void test_2_14()
{
}

static void test_2_15()
{
}

static void test_2_16()
{
}

static void test_2_17()
{
}

static void test_2_18()
{
}

static void test_2_19()
{
}

static void test_2_20()
{
}

static void test_2_28()
{
}

static void test_2_29()
{
}




static void test_3_0()
{
}

static void test_3_1()
{
}

static void test_3_2()
{
}

static void test_3_3()
{
}

static void test_3_4()
{
}

static void test_3_5()
{
}

static void test_3_6()
{
}

static void test_3_7()
{
}

static void test_3_8()
{
}

static void test_3_9()
{
}

static void test_3_10()
{
}

static void test_3_11()
{
}

static void test_3_12()
{
}

static void test_3_13()
{
}

static void test_3_14()
{
}

static void test_3_15()
{
}

static void test_3_16()
{
}

static void test_3_17()
{
}

static void test_3_18()
{
}

static void test_3_19()
{
}

static void test_3_20()
{
}

static void test_3_28()
{
}

static void test_3_29()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */

