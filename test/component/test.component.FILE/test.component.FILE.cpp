/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.FILE.cpp
 *
 * Purpose:     Implementation file for the test.component.FILE project.
 *
 * Created:     3rd January 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#include <fastformat/sinks/FILE.hpp>
#include <fastformat/ff.hpp>
#include <fastformat/util/filesystem/FILE_functions.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft header files */
#if _STLSOFT_VER >= 0x010a0182
# include <platformstl/exception/platformstl_exception.hpp>
#else
# include <platformstl/error/exceptions.hpp>
#endif
#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/system/system_traits.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <string>

/* Standard C Header Files */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
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
            FILE*                           f = ff::util::fopen_or_throw(FILE_NAME, "w");
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
            FILE*                           f = ff::util::fopen_or_throw(FILE_NAME, "w");
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
            FILE*                           f = ff::util::fopen_or_throw(FILE_NAME, "w");
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
            FILE*                           f = ff::util::fopen_or_throw(FILE_NAME, "w");
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


/* ///////////////////////////// end of file //////////////////////////// */

