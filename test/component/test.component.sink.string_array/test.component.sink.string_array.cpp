/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.string_array.cpp
 *
 * Purpose:     Implementation file for the test.component.string_array project.
 *
 * Created:     24th December 2007
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/string_array.hpp>
#include <fastformat/ff.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <exception>
#include <string>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


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
static void test_1_9();
static void test_1_10();


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.string_array", verbosity))
    {
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

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* ////////////////////////////////////////////////////////////////////// */

static void test_1_1()
{
    std::string sink;

    ff::fmt(sink, "abc");

    XTESTS_TEST("abc" == sink);
}

static void test_1_2()
{
    std::string sink;

    ff::fmt(sink, "{0}", "abc");

    XTESTS_TEST("abc" == sink);
}

static void test_1_3()
{
    std::string sink;

    ff::fmt(sink, "{0}{1}{2}", "a", "b", "c");

    XTESTS_TEST("abc" == sink);
}

static void test_1_4()
{
    std::string sink;

    ff::fmt(sink, "{0}{2}{1}", "a", "c", "b");

    XTESTS_TEST("abc" == sink);
}

static void test_1_5()
{
    std::string sink;

    ff::fmt(sink, "{2}{1}{0}", "c", "b", "a");

    XTESTS_TEST("abc" == sink);
}

static void test_1_6()
{
    std::string sink;

    ff::fmt(sink, "{0}{1}{2}{3}{4}{5}{6}{7}{8}{9}{10}{11}{12}{13}{14}{15}{16}{17}{18}{19}{20}{21}{22}{23}{24}{25}{26}{27}{28}{29}{30}{31}", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "0", "1", "2", "3", "4", "5");

    XTESTS_TEST("abcdefghijklmnopqrstuvwxyz012345" == sink);
}

static void test_1_7()
{
    std::string sink;

    ff::fmt(sink, "{0} {1} {2} {3} {0} {4}", "the", "cat", "sat", "on", "mat");

    XTESTS_TEST("the cat sat on the mat" == sink);
}

static void test_1_8()
{
    std::string sink;

    ff::fmt(sink, "{0}{0}{0}{0}{0}{0}{0}{0}{0}{0} {1}{1}{1}{1}{1}{1}{1}{1}{1}{1}", "a", "b", "c");

    XTESTS_TEST("aaaaaaaaaa bbbbbbbbbb" == sink);
}

static void test_1_9()
{
    std::string sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(0u, sink.size());
    XTESTS_TEST_STRING_EQUAL("", sink.data());

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());

    ff::fmt(sink, FF_STR("{0}"), FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}

static void test_1_10()
{
    std::string sink;

    ff::flush(ff::fmt(sink, FF_STR("{0}"), FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(0u, sink.size());
    XTESTS_TEST_STRING_EQUAL("", sink.data());

    ff::flush(ff::fmt(sink, FF_STR("{0}"), FF_STR("abc")));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());

    ff::flush(ff::fmt(sink, FF_STR("{0}"), FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}


/* ///////////////////////////// end of file //////////////////////////// */

