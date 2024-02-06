/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.sink.string.write.cpp
 *
 * Purpose:     Implementation file for the test.component.sink.string.write project.
 *
 * Created:     19th December 2007
 * Updated:     6th February 2024
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
#include <exception>
#include <string>

/* Standard C header files */
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

    if(XTESTS_START_RUNNER("test.component.sink.string.write", verbosity))
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

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING


static void test_1_1()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_2()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_3()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("a"), FF_STR("b"), FF_STR("c"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_4()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("a"), FF_STR("c"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("acb", sink.c_str());
}

static void test_1_5()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("c"), FF_STR("b"), FF_STR("a"));

    XTESTS_TEST_STRING_EQUAL("cba", sink.c_str());
}

static void test_1_6()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("a"), FF_STR("b"), FF_STR("c"), FF_STR("d"), FF_STR("e"), FF_STR("f"), FF_STR("g"), FF_STR("h"), FF_STR("i"), FF_STR("j"), FF_STR("k"), FF_STR("l"), FF_STR("m"), FF_STR("n"), FF_STR("o"), FF_STR("p"), FF_STR("q"), FF_STR("r"), FF_STR("s"), FF_STR("t"), FF_STR("u"), FF_STR("v"), FF_STR("w"), FF_STR("x"), FF_STR("y"), FF_STR("z"), FF_STR("0"), FF_STR("1"), FF_STR("2"), FF_STR("3"), FF_STR("4"), FF_STR("5"));

    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz012345", sink.c_str());
}

static void test_1_7()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("the"), FF_STR("cat"), FF_STR("sat"), FF_STR("on"), FF_STR("mat"));

    XTESTS_TEST_STRING_EQUAL("thecatsatonmat", sink.c_str());
}

static void test_1_8()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR("a"), FF_STR("a"), FF_STR("a"), FF_STR("a"), FF_STR("b"), FF_STR("b"), FF_STR("b"), FF_STR("b"), FF_STR("c"), FF_STR("c"), FF_STR("c"), FF_STR("c"));

    XTESTS_TEST_STRING_EQUAL("aaaabbbbcccc", sink.c_str());
}

static void test_1_9()
{
    std::basic_string<ff_char_t> sink;

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(0u, sink.size());
    XTESTS_TEST_STRING_EQUAL("", sink.data());

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}

static void test_1_10()
{
    std::basic_string<ff_char_t> sink;

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(0u, sink.size());
    XTESTS_TEST_STRING_EQUAL("", sink.data());

    ff::flush(ff::write(sink, FF_STR("abc")));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

