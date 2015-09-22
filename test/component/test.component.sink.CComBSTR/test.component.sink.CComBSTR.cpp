/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.sink.CComBSTR.cpp
 *
 * Purpose:     Implementation file for the test.component.sink.CComBSTR project.
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


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/CComBSTR.hpp>

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

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

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

} // anonymous namespace

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.sink.CComBSTR", verbosity))
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

namespace
{

    using   fastformat::ff_char_t;

    typedef CComBSTR    string_t;

#define FF_STR                              FASTFORMAT_LITERAL_STRING


static void test_1_1()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);
}

static void test_1_2()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);
}

static void test_1_3()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("a"), FF_STR("b"), FF_STR("c"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);
}

static void test_1_4()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("a"), FF_STR("c"), FF_STR("b"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"acb", sink);
}

static void test_1_5()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("c"), FF_STR("b"), FF_STR("a"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"cba", sink);
}

static void test_1_6()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("a"), FF_STR("b"), FF_STR("c"), FF_STR("d"), FF_STR("e"), FF_STR("f"), FF_STR("g"), FF_STR("h"), FF_STR("i"), FF_STR("j"), FF_STR("k"), FF_STR("l"), FF_STR("m"), FF_STR("n"), FF_STR("o"), FF_STR("p"), FF_STR("q"), FF_STR("r"), FF_STR("s"), FF_STR("t"), FF_STR("u"), FF_STR("v"), FF_STR("w"), FF_STR("x"), FF_STR("y"), FF_STR("z"), FF_STR("0"), FF_STR("1"), FF_STR("2"), FF_STR("3"), FF_STR("4"), FF_STR("5"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"abcdefghijklmnopqrstuvwxyz012345", sink);
}

static void test_1_7()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("the"), FF_STR("cat"), FF_STR("sat"), FF_STR("on"), FF_STR("mat"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"thecatsatonmat", sink);
}

static void test_1_8()
{
    CComBSTR sink;

    ff::write(sink, FF_STR("a"), FF_STR("a"), FF_STR("a"), FF_STR("a"), FF_STR("b"), FF_STR("b"), FF_STR("b"), FF_STR("b"), FF_STR("c"), FF_STR("c"), FF_STR("c"), FF_STR("c"));

    XTESTS_TEST_WIDE_STRING_EQUAL(L"aaaabbbbcccc", sink);
}

static void test_1_9()
{
    CComBSTR sink;

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(0, sink.Length());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"", sink);

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(3, sink.Length());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(3, sink.Length());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);
}

static void test_1_10()
{
    CComBSTR sink;

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(0, sink.Length());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"", sink);

    ff::flush(ff::write(sink, FF_STR("abc")));

    XTESTS_TEST_INTEGER_EQUAL(3, sink.Length());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(3, sink.Length());
    XTESTS_TEST_WIDE_STRING_EQUAL(L"abc", sink);
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
