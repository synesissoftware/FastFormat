/* /////////////////////////////////////////////////////////////////////////
 * File:    test/component/sink/null/entry.cpp
 *
 * Purpose: Implementation file for the test.component.sink.null project.
 *
 * Created: 10th December 2008
 * Updated: 5th November 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/sinks/null.hpp>
#include <fastformat/ff.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_1_0();
    static void TEST_1_1();
    static void TEST_1_2();
    static void TEST_1_5();
    static void TEST_1_6();
    static void TEST_1_7();
    static void TEST_1_10();
    static void TEST_1_11();
    static void TEST_1_12();
    static void TEST_1_15();
    static void TEST_1_16();
    static void TEST_1_17();
    static void TEST_1_18();
    static void TEST_1_19();

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER(__FILE__, verbosity))
    {
        XTESTS_RUN_CASE(TEST_1_0);
        XTESTS_RUN_CASE(TEST_1_1);
        XTESTS_RUN_CASE(TEST_1_2);
        XTESTS_RUN_CASE(TEST_1_5);
        XTESTS_RUN_CASE(TEST_1_6);
        XTESTS_RUN_CASE(TEST_1_7);
        XTESTS_RUN_CASE(TEST_1_10);
        XTESTS_RUN_CASE(TEST_1_11);
        XTESTS_RUN_CASE(TEST_1_12);
        XTESTS_RUN_CASE(TEST_1_15);
        XTESTS_RUN_CASE(TEST_1_16);
        XTESTS_RUN_CASE(TEST_1_17);
        XTESTS_RUN_CASE(TEST_1_18);
        XTESTS_RUN_CASE(TEST_1_19);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL(x, a)                     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                              FASTFORMAT_LITERAL_STRING


    static string_t crlf(ff::getNewlineForPlatform().ptr, ff::getNewlineForPlatform().len);


static void TEST_1_0()
{
    fastformat::sinks::null_sink sink;

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.numWrites);
}

static void TEST_1_1()
{
    fastformat::sinks::null_sink sink;

    ff::write(sink, FF_STR("abc"));
    ff::write(sink, FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(2u, sink.numWrites);
}

static void TEST_1_2()
{
    fastformat::sinks::null_sink sink;

    { for(char ch = 'a'; ; ++ch)
    {
        ff_char_t sz[2] = { ff_char_t(ch), ff_char_t('\0') };

        ff::write(sink, sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.numWrites);
}


static void TEST_1_5()
{
    fastformat::sinks::null_sink sink;

    ff::writeln(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.numWrites);
}

static void TEST_1_6()
{
    fastformat::sinks::null_sink sink;

    ff::writeln(sink, FF_STR("abc"));
    ff::writeln(sink, FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(2u, sink.numWrites);
}

static void TEST_1_7()
{
    fastformat::sinks::null_sink sink;

    { for(char ch = 'a'; ; ++ch)
    {
        ff_char_t sz[2] = { ff_char_t(ch), ff_char_t('\0') };

        ff::writeln(sink, sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.numWrites);
}


static void TEST_1_10()
{
    fastformat::sinks::null_sink sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.numWrites);
}

static void TEST_1_11()
{
    fastformat::sinks::null_sink sink;

    ff::fmt(sink, FF_STR("{0}"), FF_STR("abc"));
    ff::fmt(sink, FF_STR("{0}"), FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(2u, sink.numWrites);
}

static void TEST_1_12()
{
    fastformat::sinks::null_sink sink;
    ff_char_t                    sz[2] = { '?', '\0' };


    { for(char ch = 'a'; ; ++ch)
    {
        sz[0] = ch;

        ff::fmt(sink, FF_STR("{0}"), sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.numWrites);
}


static void TEST_1_15()
{
    fastformat::sinks::null_sink sink;

    ff::fmtln(sink, FF_STR("{0}"), FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(3u, sink.cchTotal);
}

static void TEST_1_16()
{
    fastformat::sinks::null_sink sink;

    ff::fmtln(sink, FF_STR("{0}"), FF_STR("abc"));
    ff::fmtln(sink, FF_STR("{0}"), FF_STR("def"));

    XTESTS_TEST_INTEGER_EQUAL(2u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(6u, sink.cchTotal);
}

static void TEST_1_17()
{
    fastformat::sinks::null_sink sink;

    { for(char ch = 'a'; ; ++ch)
    {
        ff_char_t sz[2] = { ff_char_t(ch), ff_char_t('\0') };

        ff::fmtln(sink, FF_STR("{0}"), sz);

        if('z' == ch)
        {
            break;
        }
    }}

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.numWrites);
}

static void TEST_1_18()
{
    fastformat::sinks::null_sink sink;

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(0u, sink.cchTotal);

    ff::write(sink, FF_STR("abc"));

    XTESTS_TEST_INTEGER_EQUAL(2u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(3u, sink.cchTotal);

    ff::write(sink, FF_STR(""));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(3u, sink.cchTotal);
}

static void TEST_1_19()
{
    fastformat::sinks::null_sink sink;

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(0u, sink.cchTotal);

    ff::flush(ff::write(sink, FF_STR("abc")));

    XTESTS_TEST_INTEGER_EQUAL(2u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(3u, sink.cchTotal);

    ff::flush(ff::write(sink, FF_STR("")));

    XTESTS_TEST_INTEGER_EQUAL(3u, sink.numWrites);
    XTESTS_TEST_INTEGER_EQUAL(3u, sink.cchTotal);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


