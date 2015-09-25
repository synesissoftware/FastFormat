/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.mismatched_handlers.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.mismatched_handlers project.
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
#include <fastformat/internal/threading.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* Standard C++ header files */
#include <string>
#include <vector>

/* Standard C header files */
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

    typedef int (*mismatched_pfn_t_)(
        void*                   /* param */
    ,   fastformat::ff_replacement_code_t   /* code */
    ,   size_t                  /* numParameters */
    ,   int                     /* parameterIndex */
    ,   fastformat::ff_string_slice_t*      /* slice */
    ,   void*                   /* reserved0 */
    ,   size_t                  /* reserved1 */
    ,   void*                   /* reserved2 */
    );

union param
{
    param(mismatched_pfn_t_ f)
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

    mismatched_pfn_t_   f;
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

    static void test_call_to_getProcessMismatchedHandler(void);
    static void test_call_to_getThreadMismatchedHandler(void);
    static void test_return_from_getProcessMismatchedHandler(void);
    static void test_return_from_getThreadMismatchedHandler(void);
    static void test_setProcessMismatchedHandler(void);
    static void test_setThreadMismatchedHandler(void);
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
            "test.unit.api.mismatched_handlers"
        ,   verbosity
        ,   NULL, NULL
        ,   NULL
        ,   xtests::c::xtestsReportOnlyNonEmptyCases
        ,   ff_setup, ff_teardown, NULL
        )
    )
    {
        XTESTS_RUN_CASE(test_call_to_getProcessMismatchedHandler);
        XTESTS_RUN_CASE(test_call_to_getThreadMismatchedHandler);
        XTESTS_RUN_CASE(test_return_from_getProcessMismatchedHandler);
        XTESTS_RUN_CASE(test_return_from_getThreadMismatchedHandler);
        XTESTS_RUN_CASE(test_setProcessMismatchedHandler);
        XTESTS_RUN_CASE(test_setThreadMismatchedHandler);
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
    using   fastformat::ff_string_slice_t;
    using   fastformat::ff_replacement_code_t;
    using   fastformat::ff_mismatched_handler_info_t;
    using   fastformat::fastformat_getProcessMismatchedHandler;
    using   fastformat::fastformat_getThreadMismatchedHandler;
    using   fastformat::fastformat_setProcessMismatchedHandler;
    using   fastformat::fastformat_setThreadMismatchedHandler;


    int FASTFORMAT_CALLCONV mismatched_handler_1_cancel(
        void*                   /* param */
    ,   ff_replacement_code_t   /* code */
    ,   size_t                  /* numParameters */
    ,   int                     /* parameterIndex */
    ,   ff_string_slice_t*      /* slice */
    ,   void*                   /* reserved0 */
    ,   size_t                  /* reserved1 */
    ,   void*                   /* reserved2 */
    )
    {
        return 0;
    }
#if 0
    int FASTFORMAT_CALLCONV mismatched_handler_1_continue_once(
        void*                   /* param */
    ,   ff_replacement_code_t   /* code */
    ,   size_t                  /* numParameters */
    ,   int                     /* parameterIndex */
    ,   ff_string_slice_t*      /* slice */
    ,   void*                   /* reserved0 */
    ,   size_t                  /* reserved1 */
    ,   void*                   /* reserved2 */
    )
    {
        return +1;
    }
    int FASTFORMAT_CALLCONV mismatched_handler_1_continue_always(
        void*                   /* param */
    ,   ff_replacement_code_t   /* code */
    ,   size_t                  /* numParameters */
    ,   int                     /* parameterIndex */
    ,   ff_string_slice_t*      /* slice */
    ,   void*                   /* reserved0 */
    ,   size_t                  /* reserved1 */
    ,   void*                   /* reserved2 */
    )
    {
        return -1;
    }
#endif /* 0 */


static void test_call_to_getProcessMismatchedHandler()
{
    fastformat_getProcessMismatchedHandler();

    XTESTS_TEST_PASSED();
}

static void test_call_to_getThreadMismatchedHandler()
{
    fastformat_getThreadMismatchedHandler();

    XTESTS_TEST_PASSED();
}

static void test_return_from_getProcessMismatchedHandler()
{
    ff_mismatched_handler_info_t    info = fastformat_getProcessMismatchedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);
}

static void test_return_from_getThreadMismatchedHandler()
{
    ff_mismatched_handler_info_t    info = fastformat_getThreadMismatchedHandler();

#ifdef FASTFORMAT_MT

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);

#else /* ? FASTFORMAT_MT */

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);

#endif /* FASTFORMAT_MT */
}

static void test_setProcessMismatchedHandler()
{
	int i;
    void* const param = &i;

    ff_mismatched_handler_info_t    original = fastformat_getProcessMismatchedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

    ff_mismatched_handler_info_t    previous = fastformat_setProcessMismatchedHandler(mismatched_handler_1_cancel, param);

    XTESTS_TEST_FN_POINTER_EQUAL(original.handler, previous.handler);
    XTESTS_TEST_POINTER_EQUAL(original.param, previous.param);

    ff_mismatched_handler_info_t    replaced = fastformat_getProcessMismatchedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(mismatched_handler_1_cancel, replaced.handler);
    XTESTS_TEST_POINTER_EQUAL(param, replaced.param);
}

static void test_setThreadMismatchedHandler()
{
	int i;
    void* const param = &i;

    ff_mismatched_handler_info_t    original = fastformat_getThreadMismatchedHandler();

#ifdef FASTFORMAT_MT

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

#else /* ? FASTFORMAT_MT */

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

#endif /* FASTFORMAT_MT */

    ff_mismatched_handler_info_t    previous = fastformat_setThreadMismatchedHandler(mismatched_handler_1_cancel, param);

    XTESTS_TEST_FN_POINTER_EQUAL(original.handler, previous.handler);
    XTESTS_TEST_POINTER_EQUAL(original.param, previous.param);

    ff_mismatched_handler_info_t    replaced = fastformat_getThreadMismatchedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(mismatched_handler_1_cancel, replaced.handler);
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
