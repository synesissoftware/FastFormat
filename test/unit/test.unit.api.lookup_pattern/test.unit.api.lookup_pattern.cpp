/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.lookup_pattern.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.lookup_pattern project.
 *
 * Created:     27th May 2008
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/fastformat.h>
#include <fastformat/internal/format_element.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/conversion/char_conversions.hpp>
#include <platformstl/platformstl.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define t2m        stlsoft::w2m
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define t2m(x)     x
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

    if(XTESTS_START_RUNNER("test.unit.api.lookup_pattern", verbosity))
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
    using fastformat::ff_char_t;
    using fastformat::fastformat_lookupPattern;

    typedef std::basic_string<ff_char_t>    string_t;

static void test_1_0()
{
    int res = fastformat::init();

    if(res < 0)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("FastFormat API failed to initialise", t2m(fastformat::getInitCodeString(res)));
    }
    else
    {
        const ff_char_t                     pattern[] = FF_STR("abc");
        fastformat::format_element_t const* elements;
        size_t                              numFormatElements;
        size_t                              numResultElements;

        unsigned n = fastformat_lookupPattern(pattern, STLSOFT_NUM_ELEMENTS(pattern) - 1, &elements);

        numFormatElements = n & 0xffff;
        numResultElements = ((n >> 16) & 0xffff);

        XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
        XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[0].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, elements[0].index);
        XTESTS_TEST_STRING_EQUAL("abc", elements[0].ptr);

        fastformat::uninit();
    }
}

static void test_1_1()
{
    int res = fastformat::init();

    if(res < 0)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("FastFormat API failed to initialise", t2m(fastformat::getInitCodeString(res)));
    }
    else
    {
        const ff_char_t                     pattern[] = FF_STR("abc{0}");
        fastformat::format_element_t const* elements;
        size_t                              numFormatElements;
        size_t                              numResultElements;

        unsigned n = fastformat_lookupPattern(pattern, STLSOFT_NUM_ELEMENTS(pattern) - 1, &elements);

        numFormatElements = n & 0xffff;
        numResultElements = ((n >> 16) & 0xffff);

        XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
        XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[0].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, elements[0].index);
        XTESTS_TEST_STRING_EQUAL("abc", string_t(elements[0].ptr, elements[0].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[1].len);
        XTESTS_TEST_INTEGER_EQUAL(0, elements[1].index);
        XTESTS_TEST_STRING_EQUAL("{0}", string_t(elements[1].ptr, elements[1].len));

        fastformat::uninit();
    }
}

static void test_1_2()
{
    int res = fastformat::init();

    if(res < 0)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("FastFormat API failed to initialise", t2m(fastformat::getInitCodeString(res)));
    }
    else
    {
        const ff_char_t                     pattern[] = FF_STR("abc{0}{1}def{2}ghi{0}");
        fastformat::format_element_t const* elements;
        size_t                              numFormatElements;
        size_t                              numResultElements;

        unsigned n = fastformat_lookupPattern(pattern, STLSOFT_NUM_ELEMENTS(pattern) - 1, &elements);

        numFormatElements = n & 0xffff;
        numResultElements = ((n >> 16) & 0xffff);

        XTESTS_TEST_INTEGER_EQUAL(7u, numFormatElements);
        XTESTS_TEST_INTEGER_EQUAL(7u, numResultElements);

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[0].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, elements[0].index);
        XTESTS_TEST_STRING_EQUAL("abc", string_t(elements[0].ptr, elements[0].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[1].len);
        XTESTS_TEST_INTEGER_EQUAL(0, elements[1].index);
        XTESTS_TEST_STRING_EQUAL("{0}", string_t(elements[1].ptr, elements[1].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[2].len);
        XTESTS_TEST_INTEGER_EQUAL(1, elements[2].index);
        XTESTS_TEST_STRING_EQUAL("{1}", string_t(elements[2].ptr, elements[2].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[3].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, elements[3].index);
        XTESTS_TEST_STRING_EQUAL("def", string_t(elements[3].ptr, elements[3].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[4].len);
        XTESTS_TEST_INTEGER_EQUAL(2, elements[4].index);
        XTESTS_TEST_STRING_EQUAL("{2}", string_t(elements[4].ptr, elements[4].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[5].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, elements[5].index);
        XTESTS_TEST_STRING_EQUAL("ghi", string_t(elements[5].ptr, elements[5].len));

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[6].len);
        XTESTS_TEST_INTEGER_EQUAL(0, elements[6].index);
        XTESTS_TEST_STRING_EQUAL("{0}", string_t(elements[6].ptr, elements[6].len));

        fastformat::uninit();
    }
}

static void test_1_3()
{
    int res = fastformat::init();

    if(res < 0)
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("FastFormat API failed to initialise", t2m(fastformat::getInitCodeString(res)));
    }
    else
    {
        const ff_char_t                     pattern[] = FF_STR("abc{0,,}");
        fastformat::format_element_t const* elements;
        size_t                              numFormatElements;
        size_t                              numResultElements;

        unsigned n = fastformat_lookupPattern(pattern, STLSOFT_NUM_ELEMENTS(pattern) - 1, &elements);

        numFormatElements = n & 0xffff;
        numResultElements = ((n >> 16) & 0xffff);

        XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
        XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);

        XTESTS_TEST_INTEGER_EQUAL(3u, elements[0].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, elements[0].index);
        XTESTS_TEST_STRING_EQUAL("abc", string_t(elements[0].ptr, elements[0].len));

        XTESTS_TEST_INTEGER_EQUAL(5u, elements[1].len);
        XTESTS_TEST_INTEGER_EQUAL(0, elements[1].index);
        XTESTS_TEST_STRING_EQUAL("{0,,}", string_t(elements[1].ptr, elements[1].len));

        fastformat::uninit();
    }
}

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
