/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.inserters.integer.cpp
 *
 * Purpose:     Implementation file for the test.unit.inserters.integer project.
 *
 * Created:     11th December 2010
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/inserters/integer.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/util/limit_traits.h>

/* Standard C++ Header Files */
#include <numeric>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL_(x, a)    XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL_          XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
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

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.inserters.integer", verbosity))
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
 * test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;
    using   fastformat::string_slice_t;
    using   fastformat::fastformat_accumulateSliceLengths;

    typedef std::basic_string<ff_char_t>    string_t;


static void test_1_0()
{
#if 0
    XTESTS_TEST_STRING_EQUAL("", fastformat::integer(0, 0, 0));
    XTESTS_TEST_STRING_EQUAL(" ", fastformat::integer(0, 1, 0));
#endif /* 0 */
    XTESTS_TEST_STRING_EQUAL("0", fastformat::integer(0, 0, 1));


    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer( 0, 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer( 1, 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(-1, 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer( 10, 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(-10, 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer( 100, 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(-100, 0, 1));
}

static void test_1_1()
{
    typedef signed char int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(int_t(-1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(int_t(-10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(int_t(-100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_2()
{
    typedef signed char int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(int_t(-1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(int_t(-10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(int_t(-100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_3()
{
    typedef signed short int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(int_t(-1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(int_t(-10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(int_t(-100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_4()
{
    typedef unsigned short int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_5()
{
    typedef signed int int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(int_t(-1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(int_t(-10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(int_t(-100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_6()
{
    typedef unsigned long int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_7()
{
    typedef signed long int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(int_t(-1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(int_t(-10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(int_t(-100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_8()
{
    typedef ::stlsoft::uint32_t int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_9()
{
    typedef ::stlsoft::sint32_t int_t;

    XTESTS_TEST_STRING_EQUAL( "0", fastformat::integer(int_t( 0), 0, 1));
    XTESTS_TEST_STRING_EQUAL( "1", fastformat::integer(int_t( 1), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-1", fastformat::integer(int_t(-1), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "10", fastformat::integer(int_t( 10), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-10", fastformat::integer(int_t(-10), 0, 1));

    XTESTS_TEST_STRING_EQUAL( "100", fastformat::integer(int_t( 100), 0, 1));
    XTESTS_TEST_STRING_EQUAL("-100", fastformat::integer(int_t(-100), 0, 1));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::minimum(), 0, 1));

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_STRING_EQUAL_(s, fastformat::integer(stlsoft::limit_traits<int_t>::maximum(), 0, 1));
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
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


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */
