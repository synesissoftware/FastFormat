/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.format_specification_defect_exceptions.cpp
 *
 * Purpose: Implementation file for the test.component.format_specification_defect_exceptions project.
 *
 * Created: 13th April 2010
 * Updated: 16th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
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

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_illformed_by_missing_closing_curly_brace_1(void);
    static void test_illformed_by_missing_closing_curly_brace_2(void);
    static void test_illformed_by_missing_digit_and_curly_brace_1(void);
    static void test_illformed_by_missing_digit_1(void);
    static void test_illformed_by_missing_digit_2(void);
    static void test_illformed_by_missing_digit_3(void);
    static void test_illformed_by_missing_digit_4(void);
    static void test_illformed_by_missing_digit_5(void);
    static void test_illformed_by_missing_digit_6(void);
    static void test_2_0(void);
    static void test_2_1(void);
    static void test_2_2(void);
    static void test_2_3(void);
    static void test_2_4(void);
    static void test_2_5(void);
    static void test_3_0(void);
    static void test_3_1(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.format_specification_defect_exceptions", verbosity))
    {
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_closing_curly_brace_1, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_closing_curly_brace_2, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_and_curly_brace_1, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_1, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_2, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_3, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_4, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_5, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_by_missing_digit_6, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE(test_2_0);
        XTESTS_RUN_CASE(test_2_1);
        XTESTS_RUN_CASE(test_2_2);
        XTESTS_RUN_CASE(test_2_3);
        XTESTS_RUN_CASE(test_2_4);
        XTESTS_RUN_CASE_THAT_THROWS(test_2_5, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_3_0, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_3_1, fastformat::illformed_format_exception);
        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL(x, a)                     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define XTESTS_TEST_STRING_EQUAL_N(x, a, n)                XTESTS_TEST_WIDE_STRING_EQUAL_N(FASTFORMAT_LITERAL_STRING(x), a, n)
# define XTESTS_TEST_STRING_CONTAIN(x, a)                   XTESTS_TEST_WIDE_STRING_CONTAIN(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N                         XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_STRING_CONTAIN                         XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                              FASTFORMAT_LITERAL_STRING


static void test_illformed_by_missing_closing_curly_brace_1()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0,"), FASTFORMAT_LITERAL_STRING("")); // }
}

static void test_illformed_by_missing_closing_curly_brace_2()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{0"), FASTFORMAT_LITERAL_STRING("")); // }
}

static void test_illformed_by_missing_digit_and_curly_brace_1()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,"), FASTFORMAT_LITERAL_STRING("")); // }
}

static void test_illformed_by_missing_digit_1()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_illformed_by_missing_digit_2()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_illformed_by_missing_digit_3()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_illformed_by_missing_digit_4()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_illformed_by_missing_digit_5()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,,,}"), FASTFORMAT_LITERAL_STRING(""));
}

static void test_illformed_by_missing_digit_6()
{
    string_t    sink;

    ff::fmtln(sink, FASTFORMAT_LITERAL_STRING("{,,,,,}"), FASTFORMAT_LITERAL_STRING(""));
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


