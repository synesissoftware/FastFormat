/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.illformed_handlers.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.illformed_handlers project.
 *
 * Created:     27th May 2008
 * Updated:     25th April 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2009, Synesis Software Pty Ltd.
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
#include <fastformat/internal/threading.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* Standard C++ Header Files */
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define t2m        stlsoft::w2m
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define t2m(x)     x
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING


#ifndef XTESTS_TEST_FN_POINTER_EQUAL

    typedef int (*illformed_pfn_t_)(
        void*               /* param */
    ,   fastformat::ff_parse_code_t     /* code */
    ,   fastformat::ff_char_t const*    /* format */
    ,   size_t              /* formatLen */
    ,   size_t              /* replacementIndex */
    ,   fastformat::ff_char_t const*    /* defect */
    ,   size_t              /* defectLen */
    ,   int                 /* parameterIndex */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    );

union param
{
    param(illformed_pfn_t_ f)
        : f(f)
    {}
#if 0
    param(void const*)
        : f(0)
    {}
    param(int)
        : f(0)
    {}
#endif /* 0 */

    illformed_pfn_t_    f;
    void const*         p;
};


inline int compare_function_pointers(param p1, param p2, XTESTS_NS_C_QUAL(xtests_comparison_t) comparison, char const* file, int line)
{
    void const* expected    =   p1.p;
    void const* actual      =   p2.p;

    return XTESTS_NS_C_QUAL(xtests_testPointers)(file, line, XTESTS_GET_FUNCTION_(), "", (expected), (actual), comparison);
}

#define XTESTS_TEST_FN_POINTER_EQUAL(expected, actual)          compare_function_pointers((expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonEqual), __FILE__, __LINE__)

#define XTESTS_TEST_FN_POINTER_NOT_EQUAL(expected, actual)      compare_function_pointers((expected), (actual), XTESTS_NS_C_QUAL(xtestsComparisonNotEqual), __FILE__, __LINE__)

#endif

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_0(void);
    static void test_1(void);
    static void test_2(void);
    static void test_3(void);
    static void test_4(void);
    static void test_5(void);
    static void test_6(void);
    static void test_7(void);
    static void test_8(void);
    static void test_9(void);
    static void test_10(void);
    static void test_11(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
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
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if( XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(
            "test.unit.api.illformed_handlers"
        ,   verbosity
        ,   NULL, NULL
        ,   NULL
        ,   xtests::c::xtestsReportOnlyNonEmptyCases
        ,   ff_setup, ff_teardown, NULL
        )
    )
    {
        XTESTS_RUN_CASE(test_0);
        XTESTS_RUN_CASE(test_1);
        XTESTS_RUN_CASE(test_2);
        XTESTS_RUN_CASE(test_3);
        XTESTS_RUN_CASE(test_4);
        XTESTS_RUN_CASE(test_5);
        XTESTS_RUN_CASE(test_6);
        XTESTS_RUN_CASE(test_7);
        XTESTS_RUN_CASE(test_8);
        XTESTS_RUN_CASE(test_9);
        XTESTS_RUN_CASE(test_10);
        XTESTS_RUN_CASE(test_11);

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
    using   fastformat::ff_parse_code_t;
    using   fastformat::ff_illformed_handler_info_t;
    using   fastformat::fastformat_getProcessIllformedHandler;
    using   fastformat::fastformat_getThreadIllformedHandler;
    using   fastformat::fastformat_setProcessIllformedHandler;
    using   fastformat::fastformat_setThreadIllformedHandler;


    int FASTFORMAT_CALLCONV illformed_handler_1_cancel(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    /* format */
    ,   size_t              /* formatLen */
    ,   size_t              /* replacementIndex */
    ,   ff_char_t const*    /* defect */
    ,   size_t              /* defectLen */
    ,   int                 /* parameterIndex */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        return 0;
    }
    int FASTFORMAT_CALLCONV illformed_handler_1_continue_once(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    /* format */
    ,   size_t              /* formatLen */
    ,   size_t              /* replacementIndex */
    ,   ff_char_t const*    /* defect */
    ,   size_t              /* defectLen */
    ,   int                 /* parameterIndex */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        return +1;
    }
    int FASTFORMAT_CALLCONV illformed_handler_1_continue_always(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    /* format */
    ,   size_t              /* formatLen */
    ,   size_t              /* replacementIndex */
    ,   ff_char_t const*    /* defect */
    ,   size_t              /* defectLen */
    ,   int                 /* parameterIndex */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        return -1;
    }


static void test_0()
{
    fastformat_getProcessIllformedHandler();

    XTESTS_TEST_PASSED();
}

static void test_1()
{
    fastformat_getThreadIllformedHandler();

    XTESTS_TEST_PASSED();
}

static void test_2()
{
    ff_illformed_handler_info_t info = fastformat_getProcessIllformedHandler();

    XTESTS_TEST_FN_POINTER_NOT_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);
}

static void test_3()
{
    ff_illformed_handler_info_t info = fastformat_getThreadIllformedHandler();

#ifdef FASTFORMAT_MT

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);

#else /* ? FASTFORMAT_MT */

    XTESTS_TEST_FN_POINTER_NOT_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);

#endif /* FASTFORMAT_MT */
}

static void test_4()
{
    void*   param = &param;

    ff_illformed_handler_info_t original = fastformat_getProcessIllformedHandler();

    XTESTS_TEST_FN_POINTER_NOT_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

    ff_illformed_handler_info_t previous = fastformat_setProcessIllformedHandler(illformed_handler_1_cancel, param);

    XTESTS_TEST_FN_POINTER_EQUAL(original.handler, previous.handler);
    XTESTS_TEST_POINTER_EQUAL(original.param, previous.param);

    ff_illformed_handler_info_t replaced = fastformat_getProcessIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(illformed_handler_1_cancel, replaced.handler);
    XTESTS_TEST_POINTER_EQUAL(param, replaced.param);
}

static void test_5()
{
    void*   param = &param;

    ff_illformed_handler_info_t original = fastformat_getThreadIllformedHandler();

#ifdef FASTFORMAT_MT

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

#else /* ? FASTFORMAT_MT */

    XTESTS_TEST_FN_POINTER_NOT_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

#endif /* FASTFORMAT_MT */

    ff_illformed_handler_info_t previous = fastformat_setThreadIllformedHandler(illformed_handler_1_cancel, param);

    XTESTS_TEST_FN_POINTER_EQUAL(original.handler, previous.handler);
    XTESTS_TEST_POINTER_EQUAL(original.param, previous.param);

    ff_illformed_handler_info_t replaced = fastformat_getThreadIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(illformed_handler_1_cancel, replaced.handler);
    XTESTS_TEST_POINTER_EQUAL(param, replaced.param);
}

static void test_6()
{
}

static void test_7()
{
}

static void test_8()
{
}

static void test_9()
{
}

static void test_10()
{
}

static void test_11()
{
}

} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
