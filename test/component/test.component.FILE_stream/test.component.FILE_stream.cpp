/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.FILE_stream.cpp
 *
 * Purpose:     Implementation file for the test.component.FILE_stream project.
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
#include <fastformat/sinks/stlsoft/FILE_stream.hpp>
#include <fastformat/ff.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>
#include <xtests/util/temp_file.hpp>

/* STLSoft Header Files */
#include <platformstl/filesystem/file_lines.hpp>
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
 * compatibility
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

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

#include <iostream>

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;


    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.FILE_stream", verbosity))
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

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

using   fastformat::ff_char_t;

using xtests::cpp::util::temp_file;

#if _STLSOFT_VER < 0x010a0181

using stlsoft::FILE_stream;
#else

using platformstl::FILE_stream;
#endif

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# if 0
typedef platformstl::file_lines_w       file_lines_t;

char const                              write_mode[] = "wb";
# else
typedef platformstl::file_lines_a       file_lines_t;

char const                              write_mode[] = "w";
# endif
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

typedef platformstl::file_lines_a       file_lines_t;

char const                              write_mode[] = "w";
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////
 * forward implementations
 */

static void test_1_1()
{
    temp_file       t(temp_file::EmptyOnOpen | temp_file::CloseOnOpen | temp_file::DeleteOnClose);

    {
        FILE_stream f(t.c_str(), write_mode);

        ff::fmt(f, FF_STR("{0}"), FF_STR("abc"));
    }

    file_lines_t    lines(t);

    XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("abc"), lines[0].c_str());
}

static void test_1_2()
{
    temp_file       t(temp_file::EmptyOnOpen | temp_file::CloseOnOpen | temp_file::DeleteOnClose);

    {
        FILE_stream f(t.c_str(), write_mode);

        ff::fmtln(f, FF_STR("{0}"), FF_STR("abc"));
    }

    file_lines_t    lines(t);

    XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("abc"), lines[0].c_str());
}

static void test_1_3()
{
    temp_file       t(temp_file::EmptyOnOpen | temp_file::CloseOnOpen | temp_file::DeleteOnClose);

    {
        FILE_stream f(t.c_str(), write_mode);

        ff::fmt(f, FF_STR("{0}"), FF_STR("abc"));
        ff::fmt(f, FF_STR("{0}"), FF_STR("def"));
    }

    file_lines_t    lines(t);

    XTESTS_TEST_INTEGER_EQUAL(1u, lines.size());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("abcdef"), lines[0].c_str());
}

static void test_1_4()
{
    temp_file       t(temp_file::EmptyOnOpen | temp_file::CloseOnOpen | temp_file::DeleteOnClose);

    {
        FILE_stream f(t.c_str(), write_mode);

        ff::fmtln(f, FF_STR("{0}"), FF_STR("abc"));
        ff::fmtln(f, FF_STR("{0}"), FF_STR("def"));
    }

    file_lines_t    lines(t);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2u, lines.size()));
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("abc"), lines[0].c_str());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(("def"), lines[1].c_str());
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

