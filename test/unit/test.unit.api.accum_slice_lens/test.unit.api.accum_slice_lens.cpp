/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.accum_slice_lens.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.accum_slice_lens project.
 *
 * Created:     27th May 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/fastformat.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <platformstl/platformstl.h>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


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

    if(XTESTS_START_RUNNER("test.unit.api.accum_slice_lens", verbosity))
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

#define FF_STR  FASTFORMAT_LITERAL_STRING

    using fastformat::fastformat_accumulateSliceLengths;


static void test_1_0()
{
    size_t len = fastformat_accumulateSliceLengths(0, NULL);

    XTESTS_TEST_INTEGER_EQUAL(0u, len);
}

static void test_1_1()
{
    fastformat::string_slice_t  slices[] = 
    {
        {   0, NULL }
    };

    size_t len = fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(0u, len);
}

static void test_1_2()
{
    fastformat::string_slice_t  slices[] = 
    {
        {   0, FF_STR("abc") }
    };

    size_t len = fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(0u, len);
}

static void test_1_3()
{
    fastformat::string_slice_t  slices[] = 
    {
        {   1, FF_STR("abc") }
    };

    size_t len = fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, len);
}

static void test_1_4()
{
    fastformat::string_slice_t  slices[] = 
    {
        {   3, FF_STR("abc") }
    };

    size_t len = fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
}

static void test_1_5()
{
    fastformat::string_slice_t  slices[] = 
    {
            {   1, FF_STR("a")  }
        ,   {   2, FF_STR("bc") }
    };

    size_t len = fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
}

static void test_1_6()
{
    fastformat::string_slice_t  slices[] = 
    {
            {   1, FF_STR("a")  }
        ,   {   0, FF_STR("bc") }
        ,   {   2, FF_STR("bc") }
    };

    size_t len = fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
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


} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

