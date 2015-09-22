/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.sink.ostream.cpp
 *
 * Purpose:     Implementation file for the test.component.sink.ostream project.
 *
 * Created:     14th September 2010
 * Updated:     14th September 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#define FASTFORMAT_NO_IMPLICIT_GENERIC_STRING_ACTION_SHIM
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <platformstl/error/exceptions.hpp>
#include <platformstl/filesystem/file_lines.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <fstream>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

static void test_1_1();
static void test_1_2();
static void test_1_3();
static void test_1_4();
static void test_1_5();
static void test_1_6();
static void test_1_7();
static void test_1_8();

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.sink.ostream", verbosity))
    {
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ////////////////////////////////////////////////////////////////////// */

using   fastformat::ff_char_t;

typedef std::basic_string<ff_char_t>    string_t;
typedef std::basic_ostream<ff_char_t>   ostream_t;
typedef std::basic_ofstream<ff_char_t>  ofstream_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

static void open_or_throw(
    char const* fileName
,   ofstream_t& stm
);


static void test_1_1()
{
    const char FILE_NAME[]  = "test_1_1.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::fmt(f, FF_STR("{0}"), FF_STR("abc"));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_2()
{
    const char FILE_NAME[]  = "test_1_2.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::fmtln(f, FF_STR("{0}"), FF_STR("abc"));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_3()
{
    const char FILE_NAME[]  = "test_1_3.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::fmt(f, FF_STR("{0}"), FF_STR("abc"));
            ff::fmt(f, FF_STR("{0}"), FF_STR("def"));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", lines[0].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_4()
{
    const char FILE_NAME[]  = "test_1_4.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::fmtln(f, FF_STR("{0}"), FF_STR("abc"));
            ff::fmtln(f, FF_STR("{0}"), FF_STR("def"));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(2u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0].c_str());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", lines[1].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_5()
{
    const char FILE_NAME[]  = "test_1_1.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::flush(ff::fmt(f, FF_STR("{0}"), FF_STR("abc")));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_6()
{
    const char FILE_NAME[]  = "test_1_2.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::flush(ff::fmtln(f, FF_STR("{0}"), FF_STR("abc")));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_7()
{
    const char FILE_NAME[]  = "test_1_3.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::flush(ff::fmt(f, FF_STR("{0}"), FF_STR("abc")));
            ff::flush(ff::fmt(f, FF_STR("{0}"), FF_STR("def")));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abcdef", lines[0].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void test_1_8()
{
    const char FILE_NAME[]  = "test_1_4.results";

    try
    {
        {
            ofstream_t   stm;
            ostream_t&   f = stm;

            open_or_throw(FILE_NAME, stm);

            ff::flush(ff::fmtln(f, FF_STR("{0}"), FF_STR("abc")));
            ff::flush(ff::fmtln(f, FF_STR("{0}"), FF_STR("def")));
        }

        platformstl::file_lines lines(FILE_NAME);

        XTESTS_TEST_INTEGER_EQUAL(2u, lines.size());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", lines[0].c_str());
        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", lines[1].c_str());

        ::remove(FILE_NAME);
    }
    catch(...)
    {
        ::remove(FILE_NAME);

        throw;
    }
}

static void open_or_throw(
    char const*  fileName
,   ofstream_t&  stm
)
{
    stm.exceptions(std::ios_base::failbit);

    stm.open(fileName);
}

/* ///////////////////////////// end of file //////////////////////////// */
