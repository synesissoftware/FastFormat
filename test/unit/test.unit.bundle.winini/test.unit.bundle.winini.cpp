/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.bundle.winini.cpp
 *
 * Purpose:     Implementation file for the test.unit.bundle.winini project.
 *
 * Created:     12th April 2008
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#include <fastformat/bundles/winini_bundle.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>


/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define t2m        stlsoft::w2m
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define t2m(x)     x
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR(x)                           FASTFORMAT_LITERAL_STRING(x)

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{
    using   fastformat::ff_char_t;

#define WININI_UNITTEST_FILE_NAME_          "./test.unit.bundle.winini.ini"
    static const ff_char_t   WININI_UNITTEST_FILE_NAME[] = FF_STR(WININI_UNITTEST_FILE_NAME_);

    static void test_1_1();
    static void test_1_2();
    static void test_1_3();
    static void test_1_4();
    static void test_1_5();
    static void test_1_6();
    static void test_1_7();
    static void test_1_8();

} /* anonymous namespace */

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.bundle.winini", verbosity))
    {
        // Prepare the ini file
        FILE*   stm = ::fopen(WININI_UNITTEST_FILE_NAME_, "w");

        if(NULL == stm)
        {
            retCode = EXIT_FAILURE;
        }
        else
        {
            fprintf(stm, "[section-1]\n");
            fprintf(stm, "val1=abc\n");
            fprintf(stm, "val2=def\n");
            fprintf(stm, "val3=\n");
            fprintf(stm, "[section-2]\n");

            ::fclose(stm);
        }

        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_5, std::out_of_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_6, std::out_of_range);
        XTESTS_RUN_CASE_THAT_THROWS(test_1_7, std::out_of_range);
        XTESTS_RUN_CASE(test_1_8);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);

        ::remove(WININI_UNITTEST_FILE_NAME_);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    typedef std::basic_string<ff_char_t>    string_t;


static void test_1_1()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-1"));
}

static void test_1_2()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-1"));

    string_t val1    =   bundle[FF_STR("val1")];

    XTESTS_TEST_STRING_EQUAL("abc", val1);
}

static void test_1_3()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-1"));

    string_t val2    =   bundle[FF_STR("val2")];

    XTESTS_TEST_STRING_EQUAL("def", val2);
}

static void test_1_4()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-1"));

    string_t val3    =   bundle[FF_STR("val3")];

    XTESTS_TEST_STRING_EQUAL("", val3);
}

static void test_1_5()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-1"));

    string_t val4    =   bundle[FF_STR("val4")];

    XTESTS_TEST_STRING_EQUAL("", val4);
}

static void test_1_6()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-2"));

    string_t val1    =   bundle[FF_STR("val1")];

    XTESTS_TEST_STRING_EQUAL("", val1);
}

static void test_1_7()
{
    fastformat::winini_bundle   bundle(WININI_UNITTEST_FILE_NAME, FF_STR("section-3"));

    string_t val1    =   bundle[FF_STR("val1")];

    XTESTS_TEST_STRING_EQUAL("", val1);
}

static void test_1_8()
{
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */
