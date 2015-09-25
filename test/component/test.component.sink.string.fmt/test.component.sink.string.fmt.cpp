/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.sink.string.fmt.cpp
 *
 * Purpose:     Implementation file for the test.component.sink.string.fmt project.
 *
 * Created:     19th December 2007
 * Updated:     25th September 2015
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


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/string/static_string.hpp>

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

    static void test_1_0_a();
    static void test_1_1_a();
    static void test_1_1_b();
    static void test_1_1_c();
    static void test_1_2_a();
    static void test_1_2_b();
    static void test_1_2_c();
    static void test_1_3_a();
    static void test_1_3_b();
    static void test_1_3_c();
    static void test_1_4_a();
    static void test_1_4_b();
    static void test_1_4_c();
    static void test_1_5_a();
    static void test_1_5_b();
    static void test_1_5_c();
    static void test_1_6_a();
    static void test_1_6_b();
    static void test_1_6_c();
    static void test_1_7_a();
    static void test_1_7_b();
    static void test_1_7_c();
    static void test_1_8_a();
    static void test_1_8_b();
    static void test_1_8_c();
    static void test_1_9();
    static void test_1_10();

    static void test_2_0();
    static void test_2_1();
    static void test_2_2();
    static void test_2_3();
    static void test_2_4();
    static void test_2_5();
    static void test_2_6();
    static void test_2_7();
    static void test_2_8();
    static void test_2_9();
    static void test_2_10();
    static void test_2_11();

} // anonymous namespace

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.sink.string.fmt", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0_a);
        XTESTS_RUN_CASE(test_1_1_a);
        XTESTS_RUN_CASE(test_1_1_b);
        XTESTS_RUN_CASE(test_1_1_c);
        XTESTS_RUN_CASE(test_1_2_a);
        XTESTS_RUN_CASE(test_1_2_b);
        XTESTS_RUN_CASE(test_1_2_c);
        XTESTS_RUN_CASE(test_1_3_a);
        XTESTS_RUN_CASE(test_1_3_b);
        XTESTS_RUN_CASE(test_1_3_c);
        XTESTS_RUN_CASE(test_1_4_a);
        XTESTS_RUN_CASE(test_1_4_b);
        XTESTS_RUN_CASE(test_1_4_c);
        XTESTS_RUN_CASE(test_1_5_a);
        XTESTS_RUN_CASE(test_1_5_b);
        XTESTS_RUN_CASE(test_1_5_c);
        XTESTS_RUN_CASE(test_1_6_a);
        XTESTS_RUN_CASE(test_1_6_b);
        XTESTS_RUN_CASE(test_1_6_c);
        XTESTS_RUN_CASE(test_1_7_a);
        XTESTS_RUN_CASE(test_1_7_b);
        XTESTS_RUN_CASE(test_1_7_c);
        XTESTS_RUN_CASE(test_1_8_a);
        XTESTS_RUN_CASE(test_1_8_b);
        XTESTS_RUN_CASE(test_1_8_c);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);

        XTESTS_RUN_CASE(test_2_0);
        XTESTS_RUN_CASE(test_2_1);
        XTESTS_RUN_CASE(test_2_2);
        XTESTS_RUN_CASE(test_2_3);
        XTESTS_RUN_CASE(test_2_4);
        XTESTS_RUN_CASE(test_2_5);
        XTESTS_RUN_CASE(test_2_6);
        XTESTS_RUN_CASE(test_2_7);
        XTESTS_RUN_CASE(test_2_8);
        XTESTS_RUN_CASE(test_2_9);
        XTESTS_RUN_CASE(test_2_10);
        XTESTS_RUN_CASE(test_2_11);

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


static void test_1_0_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0,,0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("", sink);
}

static void test_1_1_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_1_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_1_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_2_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_2_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_2_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_3_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0}{1}{2}"), FF_STR("a"), FF_STR("b"), FF_STR("c"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_3_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}{1}{2}"), FF_STR("a"), FF_STR("b"), FF_STR("c"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_3_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0}{1}{2}"), FF_STR("a"), FF_STR("b"), FF_STR("c"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_4_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0}{2}{1}"), FF_STR("a"), FF_STR("c"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_4_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}{2}{1}"), FF_STR("a"), FF_STR("c"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_4_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0}{2}{1}"), FF_STR("a"), FF_STR("c"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_5_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{2}{1}{0}"), FF_STR("c"), FF_STR("b"), FF_STR("a"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_5_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{2}{1}{0}"), FF_STR("c"), FF_STR("b"), FF_STR("a"));

    XTESTS_TEST_STRING_EQUAL("abc", sink);
}

static void test_1_5_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{2}{1}{0}"), FF_STR("c"), FF_STR("b"), FF_STR("a"));

    XTESTS_TEST_STRING_EQUAL("abc", sink.c_str());
}

static void test_1_6_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0}{1}{2}{3}{4}{5}{6}{7}{8}{9}{10}{11}{12}{13}{14}{15}{16}{17}{18}{19}{20}{21}{22}{23}{24}{25}{26}{27}{28}{29}{30}{31}"), FF_STR("a"), FF_STR("b"), FF_STR("c"), FF_STR("d"), FF_STR("e"), FF_STR("f"), FF_STR("g"), FF_STR("h"), FF_STR("i"), FF_STR("j"), FF_STR("k"), FF_STR("l"), FF_STR("m"), FF_STR("n"), FF_STR("o"), FF_STR("p"), FF_STR("q"), FF_STR("r"), FF_STR("s"), FF_STR("t"), FF_STR("u"), FF_STR("v"), FF_STR("w"), FF_STR("x"), FF_STR("y"), FF_STR("z"), FF_STR("0"), FF_STR("1"), FF_STR("2"), FF_STR("3"), FF_STR("4"), FF_STR("5"));

    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz012345", sink);
}

static void test_1_6_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}{1}{2}{3}{4}{5}{6}{7}{8}{9}{10}{11}{12}{13}{14}{15}{16}{17}{18}{19}{20}{21}{22}{23}{24}{25}{26}{27}{28}{29}{30}{31}"), FF_STR("a"), FF_STR("b"), FF_STR("c"), FF_STR("d"), FF_STR("e"), FF_STR("f"), FF_STR("g"), FF_STR("h"), FF_STR("i"), FF_STR("j"), FF_STR("k"), FF_STR("l"), FF_STR("m"), FF_STR("n"), FF_STR("o"), FF_STR("p"), FF_STR("q"), FF_STR("r"), FF_STR("s"), FF_STR("t"), FF_STR("u"), FF_STR("v"), FF_STR("w"), FF_STR("x"), FF_STR("y"), FF_STR("z"), FF_STR("0"), FF_STR("1"), FF_STR("2"), FF_STR("3"), FF_STR("4"), FF_STR("5"));

    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz012345", sink);
}

static void test_1_6_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0}{1}{2}{3}{4}{5}{6}{7}{8}{9}{10}{11}{12}{13}{14}{15}{16}{17}{18}{19}{20}{21}{22}{23}{24}{25}{26}{27}{28}{29}{30}{31}"), FF_STR("a"), FF_STR("b"), FF_STR("c"), FF_STR("d"), FF_STR("e"), FF_STR("f"), FF_STR("g"), FF_STR("h"), FF_STR("i"), FF_STR("j"), FF_STR("k"), FF_STR("l"), FF_STR("m"), FF_STR("n"), FF_STR("o"), FF_STR("p"), FF_STR("q"), FF_STR("r"), FF_STR("s"), FF_STR("t"), FF_STR("u"), FF_STR("v"), FF_STR("w"), FF_STR("x"), FF_STR("y"), FF_STR("z"), FF_STR("0"), FF_STR("1"), FF_STR("2"), FF_STR("3"), FF_STR("4"), FF_STR("5"));

    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz012345", sink.c_str());
}

static void test_1_7_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0} {1} {2} {3} {0} {4}"), FF_STR("the"), FF_STR("cat"), FF_STR("sat"), FF_STR("on"), FF_STR("mat"));

    XTESTS_TEST_STRING_EQUAL("the cat sat on the mat", sink);
}

static void test_1_7_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0} {1} {2} {3} {0} {4}"), FF_STR("the"), FF_STR("cat"), FF_STR("sat"), FF_STR("on"), FF_STR("mat"));

    XTESTS_TEST_STRING_EQUAL("the cat sat on the mat", sink);
}

static void test_1_7_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0} {1} {2} {3} {0} {4}"), FF_STR("the"), FF_STR("cat"), FF_STR("sat"), FF_STR("on"), FF_STR("mat"));

    XTESTS_TEST_STRING_EQUAL("the cat sat on the mat", sink.c_str());
}

static void test_1_8_a()
{
    string_t sink;

    ff::fmt(sink, FF_STR("{0}{0}{0}{0}{0}{0}{0}{0}{0}{0} {1}{1}{1}{1}{1}{1}{1}{1}{1}{1}"), FF_STR("a"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("aaaaaaaaaa bbbbbbbbbb", sink);
}

static void test_1_8_b()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}{0}{0}{0}{0}{0}{0}{0}{0}{0} {1}{1}{1}{1}{1}{1}{1}{1}{1}{1}"), FF_STR("a"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("aaaaaaaaaa bbbbbbbbbb", sink);
}

static void test_1_8_c()
{
    stlsoft::basic_static_string<ff_char_t, 100> sink;

    ff::fmt(sink, FF_STR("{0}{0}{0}{0}{0}{0}{0}{0}{0}{0} {1}{1}{1}{1}{1}{1}{1}{1}{1}{1}"), FF_STR("a"), FF_STR("b"));

    XTESTS_TEST_STRING_EQUAL("aaaaaaaaaa bbbbbbbbbb", sink.c_str());
}

static void test_1_9()
{
    stlsoft::basic_simple_string<ff_char_t> sink;

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
    stlsoft::basic_simple_string<ff_char_t> sink;

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




static void test_2_0()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10}|{0,,4}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|    abcdef|cdef", sink.c_str());
}

static void test_2_1()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,<}|{0,,4,<}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|abcdef    |abcd", sink.c_str());
}

static void test_2_2()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,^}|{0,,4,^}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|  abcdef  |bcde", sink.c_str());
}

static void test_2_3()
{
}

static void test_2_4()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,> }|{0,,4,> }"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|    abcdef|cdef", sink.c_str());
}

static void test_2_5()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,< }|{0,,4,< }"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|abcdef    |abcd", sink.c_str());
}

static void test_2_6()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,^ }|{0,,4,^ }"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|  abcdef  |bcde", sink.c_str());
}

static void test_2_7()
{
}

static void test_2_8()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,>#}|{0,,4,>#}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|####abcdef|cdef", sink.c_str());
}

static void test_2_9()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,<#}|{0,,4,<#}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|abcdef####|abcd", sink.c_str());
}

static void test_2_10()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,10,,^#}|{0,,4,^#}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef|##abcdef##|bcde", sink.c_str());
}

static void test_2_11()
{
    string_t    sink;

    string_t    arg0(FF_STR("abcdef"));

    ff::fmt(sink, FF_STR("{0}|{0,,0,^#}|{0,,4,^#}"), arg0);

    XTESTS_TEST_STRING_EQUAL("abcdef||bcde", sink.c_str());
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
