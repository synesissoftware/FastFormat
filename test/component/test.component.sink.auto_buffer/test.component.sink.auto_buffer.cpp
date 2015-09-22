/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.sink.auto_buffer.cpp
 *
 * Purpose:     Implementation file for the test.component.sink.auto_buffer project.
 *
 * Created:     26th April 2008
 * Updated:     14th September 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
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
#define FASTFORMAT_NO_IMPLICIT_ACTION_SHIMS // VC++ 6 can't distinguish the auto_buffer action shim from the generic string one
#include <fastformat/sinks/auto_buffer.hpp>
#include <fastformat/ff.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
    static void test_1_5(void);
    static void test_1_6(void);
    static void test_1_7(void);
    static void test_1_8(void);
    static void test_1_9(void);
    static void test_1_10(void);
    static void test_1_11(void);
    static void test_1_12(void);
    static void test_1_13(void);
    static void test_1_14(void);
    static void test_1_15(void);
    static void test_1_16(void);
    static void test_1_17(void);
    static void test_1_18(void);
    static void test_1_19(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.sink.auto_buffer", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
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
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;

    typedef std::basic_string<ff_char_t>    string_t;


    static string_t crlf(ff::getNewlineForPlatform().ptr, ff::getNewlineForPlatform().len);


static void test_1_0()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(4u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}

static void test_1_1()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::write(sink, FF_STR("abc"));
    ff::write(sink, FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(7u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abcdef", sink.data());
}

static void test_1_2()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    { for(ff_char_t ch = 'a'; ; ++ch)
    {
        ff_char_t    sz[2] = { ch, '\0' };

        ff::write(sink, sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(27u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", sink.data());
}

static void test_1_3()
{
}

static void test_1_4()
{
}

static void test_1_5()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::writeln(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(4u + crlf.size(), sink.size());
    XTESTS_TEST_STRING_EQUAL("abc" + crlf, sink.data());
}

static void test_1_6()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::writeln(sink, FF_STR("abc"));
    ff::writeln(sink, FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(7u + 2u * crlf.size(), sink.size());
    XTESTS_TEST_STRING_EQUAL("abc" + crlf + FF_STR("def") + crlf, sink.data());
}

static void test_1_7()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    { for(ff_char_t ch = 'a'; ; ++ch)
    {
        ff_char_t    sz[2] = { ch, '\0' };

        ff::writeln(sink, sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(27u + 26u * crlf.size(), sink.size());
    XTESTS_TEST_STRING_EQUAL("a" + crlf + FF_STR("b") + crlf + FF_STR("c") + crlf + FF_STR("d") + crlf + FF_STR("e") + crlf + FF_STR("f") + crlf + FF_STR("g") + crlf + FF_STR("h") + crlf + FF_STR("i") + crlf + FF_STR("j") + crlf + FF_STR("k") + crlf + FF_STR("l") + crlf + FF_STR("m") + crlf + FF_STR("n") + crlf + FF_STR("o") + crlf + FF_STR("p") + crlf + FF_STR("q") + crlf + FF_STR("r") + crlf + FF_STR("s") + crlf + FF_STR("t") + crlf + FF_STR("u") + crlf + FF_STR("v") + crlf + FF_STR("w") + crlf + FF_STR("x") + crlf + FF_STR("y") + crlf + FF_STR("z") + crlf, sink.data());
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(4u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}

static void test_1_11()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));
    ff::fmt(sink, FF_STR("{0}"), FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(7u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abcdef", sink.data());
}

static void test_1_12()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);
    ff_char_t                        sz[2] = { '?', '\0' };


    { for(ff_char_t ch = 'a'; ; ++ch)
    {
        sz[0] = ch;

        ff::fmt(sink, FF_STR("{0}"), sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(27u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", sink.data());
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::fmtln(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(4u + crlf.size(), sink.size());
    XTESTS_TEST_STRING_EQUAL("abc" + crlf, sink.data());
}

static void test_1_16()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::fmtln(sink, FF_STR("{0}"), FF_STR("abc"));
    ff::fmtln(sink, FF_STR("{0}"), FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(7u + 2u * crlf.size(), sink.size());
    XTESTS_TEST_STRING_EQUAL("abc" + crlf + FF_STR("def") + crlf, sink.data());
}

static void test_1_17()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    { for(ff_char_t ch = 'a'; ; ++ch)
    {
        ff_char_t    sz[2] = { ch, '\0' };

        ff::fmtln(sink, FF_STR("{0}"), sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(27u + 26u * crlf.size(), sink.size());
    XTESTS_TEST_STRING_EQUAL("a" + crlf + FF_STR("b") + crlf + FF_STR("c") + crlf + FF_STR("d") + crlf + FF_STR("e") + crlf + FF_STR("f") + crlf + FF_STR("g") + crlf + FF_STR("h") + crlf + FF_STR("i") + crlf + FF_STR("j") + crlf + FF_STR("k") + crlf + FF_STR("l") + crlf + FF_STR("m") + crlf + FF_STR("n") + crlf + FF_STR("o") + crlf + FF_STR("p") + crlf + FF_STR("q") + crlf + FF_STR("r") + crlf + FF_STR("s") + crlf + FF_STR("t") + crlf + FF_STR("u") + crlf + FF_STR("v") + crlf + FF_STR("w") + crlf + FF_STR("x") + crlf + FF_STR("y") + crlf + FF_STR("z") + crlf, sink.data());
}

static void test_1_18()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.size());
    XTESTS_TEST_STRING_EQUAL("", sink.data());

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(4u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(4u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}

static void test_1_19()
{
    stlsoft::auto_buffer<ff_char_t>  sink(0);

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.size());
    XTESTS_TEST_STRING_EQUAL("", sink.data());

    ff::flush(ff::write(sink, FF_STR("abc")));

    XTESTS_TEST_INTEGER_EQUAL(4u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(4u, sink.size());
    XTESTS_TEST_STRING_EQUAL("abc", sink.data());
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
