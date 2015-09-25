/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.format_specification_defect_exceptions.cpp
 *
 * Purpose:     Implementation file for the test.component.format_specification_defect_exceptions project.
 *
 * Created:     13th April 2010
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

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <iostream>
#include <string>

/* Standard C header files */
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

    if(XTESTS_START_RUNNER("test.component.format_specification_defect_exceptions", verbosity))
    {
        XTESTS_RUN_CASE_THAT_THROWS(test_1_0, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_1, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_2, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_3, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_4, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_5, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_6, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_7, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_8, fastformat::illformed_format_exception);
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
        XTESTS_RUN_CASE_THAT_THROWS(test_2_5, fastformat::illformed_format_exception);
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

        XTESTS_RUN_CASE_THAT_THROWS(test_3_0, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_3_1, fastformat::illformed_format_exception);
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
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,"), FASTFORMAT_LITERAL_STRING("")); // }
}

static void test_1_1()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0"), FASTFORMAT_LITERAL_STRING("")); // }
}

static void test_1_2()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,"), FASTFORMAT_LITERAL_STRING("")); // }
}

static void test_1_3()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_1_4()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_1_5()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_1_6()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_1_7()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_1_8()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,,,,}"), FASTFORMAT_LITERAL_STRING(""));
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
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_2_1()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_2_2()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_2_3()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_2_4()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,,,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_2_5()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,,,,,}"), FASTFORMAT_LITERAL_STRING(""));
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
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,-1,8}"), 2);
}

static void test_3_1()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,1,-8}"), 2);
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

