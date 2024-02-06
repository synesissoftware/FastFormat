/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.inserter.hex.cpp
 *
 * Purpose:     Implementation file for the test.component.inserter.hex project.
 *
 * Created:     16th January 2010
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/inserters/to_x.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/string/trim_functions.hpp>
#include <stlsoft/util/minmax.hpp>

/* Standard C header files */
#include <math.h>
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * Decimal places expected as correct, per compiler
 */

namespace
{

} /* anonymous namespace */


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
    static void test_1_20(void);

    static void test_2_0(void);
    static void test_2_1(void);
    static void test_2_2(void);
    static void test_2_3(void);
    static void test_2_4(void);
    static void test_2_5(void);
    static void test_2_6(void);
    static void test_2_7(void);
    static void test_2_8(void);
    static void test_2_9(void);
    static void test_2_10(void);
    static void test_2_11(void);
    static void test_2_12(void);
    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
    static void test_2_16(void);
    static void test_2_17(void);
    static void test_2_18(void);
    static void test_2_19(void);
    static void test_2_20(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.component.inserter.hex", verbosity))
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
        XTESTS_RUN_CASE(test_1_20);

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
        XTESTS_RUN_CASE(test_2_12);
        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16);
        XTESTS_RUN_CASE(test_2_17);
        XTESTS_RUN_CASE(test_2_18);
        XTESTS_RUN_CASE(test_2_19);
        XTESTS_RUN_CASE(test_2_20);

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

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)         XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define XTESTS_TEST_STRING_EQUAL_N(x, a, n)    XTESTS_TEST_WIDE_STRING_EQUAL_N(FASTFORMAT_LITERAL_STRING(x), a, n)
# define XTESTS_TEST_STRING_CONTAIN(x, a)       XTESTS_TEST_WIDE_STRING_CONTAIN(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL               XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N             XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_STRING_CONTAIN             XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                  FASTFORMAT_LITERAL_STRING

    static string_t crlf(ff::getNewlineForPlatform().ptr, ff::getNewlineForPlatform().len);

static void test_1_0()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0));

    XTESTS_TEST_STRING_EQUAL("0", sink);
}

static void test_1_1()
{
    string_t    sink;

    ff::write(sink, ff::to_x(1));

    XTESTS_TEST_STRING_EQUAL("1", sink);
}

static void test_1_2()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x1234));

    XTESTS_TEST_STRING_EQUAL("1234", sink);
}

static void test_1_3()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x12345678));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_1_4()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x1234, 8));

    XTESTS_TEST_STRING_EQUAL("    1234", sink);
}

static void test_1_5()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x12345678, 8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_1_6()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x1234, -8));

    XTESTS_TEST_STRING_EQUAL("1234    ", sink);
}

static void test_1_7()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x12345678, -8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_1_8()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x1234, 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_1_9()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x12345678, 8, 8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_1_10()
{
    string_t    sink;

    ff::write(sink, ff::to_x(0x1234, 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_1_11()
{
    string_t    sink;

    ff::write(sink, ff::to_x(stlsoft::uint16_t(0x1234), 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_1_12()
{
    string_t    sink;

    ff::write(sink, ff::to_x(stlsoft::uint32_t(0x1234), 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_1_13()
{
    string_t    sink;

    ff::write(sink, ff::to_x(stlsoft::uint64_t(0x1234), 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_1_14()
{
    string_t    sink;

    ff::write(sink, ff::to_x(stlsoft::uint64_t(0x12345678), 8, 8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_1_15()
{
    string_t    sink;

    ff::write(sink, ff::to_x(STLSOFT_GEN_UINT64_SUFFIX(0x123456789abc)));

    XTESTS_TEST_STRING_EQUAL("123456789abc", sink);
}

static void test_1_16()
{
    string_t    sink;

    ff::write(sink, ff::to_x(STLSOFT_GEN_UINT64_SUFFIX(0x123456789abc), 16, 16));

    XTESTS_TEST_STRING_EQUAL("0000123456789abc", sink);
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}

static void test_1_20()
{
}


static void test_2_0()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0));

    XTESTS_TEST_STRING_EQUAL("0", sink);
}

static void test_2_1()
{
    string_t    sink;

    ff::write(sink, ff::to_X(1));

    XTESTS_TEST_STRING_EQUAL("1", sink);
}

static void test_2_2()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x1234));

    XTESTS_TEST_STRING_EQUAL("1234", sink);
}

static void test_2_3()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x12345678));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_2_4()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x1234, 8));

    XTESTS_TEST_STRING_EQUAL("    1234", sink);
}

static void test_2_5()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x12345678, 8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_2_6()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x1234, -8));

    XTESTS_TEST_STRING_EQUAL("1234    ", sink);
}

static void test_2_7()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x12345678, -8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_2_8()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x1234, 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_2_9()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x12345678, 8, 8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_2_10()
{
    string_t    sink;

    ff::write(sink, ff::to_X(0x1234, 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_2_11()
{
    string_t    sink;

    ff::write(sink, ff::to_X(stlsoft::uint16_t(0x1234), 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_2_12()
{
    string_t    sink;

    ff::write(sink, ff::to_X(stlsoft::uint32_t(0x1234), 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_2_13()
{
    string_t    sink;

    ff::write(sink, ff::to_X(stlsoft::uint64_t(0x1234), 8, 8));

    XTESTS_TEST_STRING_EQUAL("00001234", sink);
}

static void test_2_14()
{
    string_t    sink;

    ff::write(sink, ff::to_X(stlsoft::uint64_t(0x12345678), 8, 8));

    XTESTS_TEST_STRING_EQUAL("12345678", sink);
}

static void test_2_15()
{
    string_t    sink;

    ff::write(sink, ff::to_X(STLSOFT_GEN_UINT64_SUFFIX(0x123456789abc)));

    XTESTS_TEST_STRING_EQUAL("123456789ABC", sink);
}

static void test_2_16()
{
    string_t    sink;

    ff::write(sink, ff::to_X(STLSOFT_GEN_UINT64_SUFFIX(0x123456789abc), 16, 16));

    XTESTS_TEST_STRING_EQUAL("0000123456789ABC", sink);
}

static void test_2_17()
{
}

static void test_2_18()
{
}

static void test_2_19()
{
}

static void test_2_20()
{
}


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

