/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.fill_replacements.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.fill_replacements project.
 *
 * Created:     27th May 2008
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2017, Synesis Software Pty Ltd.
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
 * helper functions
 */

int ff_setup(void*);
int ff_teardown(void*);

int ff_setup(void*)
{
    return fastformat::fastformat_init();
}

int ff_teardown(void*)
{
    fastformat::fastformat_uninit();

    return 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if( XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(
            "test.unit.api.fill_replacements"
        ,   verbosity
        ,   NULL, NULL
        ,   NULL
        ,   xtests::c::xtestsReportOnlyNonEmptyCases
        ,   ff_setup, ff_teardown, NULL
        )
    )
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
    using fastformat::ff_handler_response_t;
    using fastformat::ff_string_slice_t;
    using fastformat::ff_replacement_action_t;
    using fastformat::ff_replacement_code_t;
    using fastformat::fastformat_fillReplacements;

    ff_handler_response_t
    FASTFORMAT_CALLCONV ignore_mismatched_handler(
        void*                       /* param */
    ,   ff_replacement_code_t       /* code */
    ,   size_t                      /* numArguments */
    ,   int                         /* mismatchedParameterIndex */
    ,   ff_replacement_action_t*    /* missingArgumentAction */
    ,   ff_string_slice_t*          /* slice */
    ,   void*                       /* reserved0 */
    ,   size_t                      /* reserved1 */
    ,   void*                       /* reserved2 */
    ,   int                         /* reserved3 */
    )
    {
        return fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
    }

    using   fastformat::ff_char_t;

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING



static void test_1_0()
{
    fastformat::format_element_t    patterns[] = 
    {
        {   0,  NULL,   -1, 0,  -1  }
    };
    fastformat::string_slice_t      replacements[] = 
    {
        {   0,  NULL    }
    };
    fastformat::string_slice_t      results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(0u, len);
}

static void test_1_1()
{
    fastformat::format_element_t patterns[] = 
    {
        {   1,  FF_STR("a"),    -1, 0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   0,  NULL    }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(1u, len);
}

static void test_1_2()
{
    fastformat::format_element_t   patterns[] = 
    {
        {   0,  NULL,   0,  0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   0,  NULL    }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(0u, len);
}

static void test_1_3()
{
    fastformat::format_element_t   patterns[] = 
    {
        {   0,  NULL,   0,  0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   1,  FF_STR("a") }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(1u, len);
}

static void test_1_4()
{
    fastformat::format_element_t   patterns[] = 
    {
        {   0,  NULL,   0,  0,  -1  },
        {   0,  NULL,   0,  0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   1,  FF_STR("a") }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(2u, len);
}

static void test_1_5()
{
    fastformat::format_element_t   patterns[] = 
    {
        {   0,  NULL,   0,  0,  -1  },
        {   0,  NULL,   0,  0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   1,  FF_STR("a") }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(2u, len);
}

static void test_1_6()
{
    fastformat::format_element_t   patterns[] = 
    {
        {   1,  FF_STR("a"),    0,  0,  -1  },
        {   0,  NULL,           0,  0,  -1  },
        {   1,  FF_STR("a"),    0,  0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   1,  FF_STR("a") }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(3u, len);
}

static void test_1_7()
{
    fastformat::format_element_t   patterns[] = 
    {
        {   1,  FF_STR("a"),        0,  0,  -1  },
        {   0,  NULL,               0,  0,  -1  },
        {   7,  FF_STR("fghijkl"),  0,  0,  -1  }
    };
    fastformat::string_slice_t  replacements[] = 
    {
        {   4,  FF_STR("bcde")  }
    };
    fastformat::string_slice_t  results[STLSOFT_NUM_ELEMENTS(patterns)];

    size_t numResultElements;
    size_t len = fastformat_fillReplacements(&results[0], &patterns[0], STLSOFT_NUM_ELEMENTS(patterns), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), ignore_mismatched_handler, NULL, &numResultElements);

    XTESTS_TEST_INTEGER_EQUAL(12u, len);
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
