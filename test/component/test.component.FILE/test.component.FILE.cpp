/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.FILE.cpp
 *
 * Purpose:     Implementation file for the test.component.FILE project.
 *
 * Created:     3rd January 2008
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2007-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/sinks/FILE.hpp>
#include <fastformat/ff.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <platformstl/error/exceptions.hpp>
#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/system/system_traits.hpp>

/* Standard C++ header files */
#include <exception>
#include <string>

/* Standard C header files */
#include <errno.h>
#include <stdio.h>
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

static FILE* fopen_or_throw(char const* fileName, char const* mode = "w");
#if defined(__BORLANDC__) && \
    __BORLANDC__ < 0x0610
static int   fclose_(FILE* stm)
{
    int r;

    r = ::fclose(stm);

//  fprintf(stderr, "fclose_(%p): %d\n", stm, r);

    return r;
}
# define fclose     fclose_
#endif /* __BORLANDC__ */

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.FILE", verbosity))
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

static void test_1_1()
{
    using   fastformat::ff_char_t;

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING


    const char FILE_NAME[]  = "test_1_1.results";

    try
    {
        {
            FILE*                           f = ::fopen_or_throw(FILE_NAME);
            stlsoft::scoped_handle<FILE*>   f_(f, ::fclose);

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
            FILE*                           f = ::fopen_or_throw(FILE_NAME);
            stlsoft::scoped_handle<FILE*>   f_(f, ::fclose);

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
            FILE*                           f = ::fopen_or_throw(FILE_NAME);
            stlsoft::scoped_handle<FILE*>   f_(f, ::fclose);

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
            FILE*                           f = ::fopen_or_throw(FILE_NAME);
            stlsoft::scoped_handle<FILE*>   f_(f, ::fclose);

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
{}

static void test_1_6()
{}

static void test_1_7()
{}

static void test_1_8()
{}

static FILE* fopen_or_throw(char const* fileName, char const* mode /* = "r" */)
{
    FILE*   f = ::fopen(fileName, mode);

    if(NULL == f)
    {
        throw platformstl::platform_exception((std::string("Could not open file '") + fileName + "'").c_str(), platformstl::system_traits<char>::get_last_error());
    }

    return f;
}

/* ///////////////////////////// end of file //////////////////////////// */
