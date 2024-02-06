/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.illformed_handlers.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.illformed_handlers project.
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
#include <fastformat/internal/threading.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
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
 * macros and definitions
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

    typedef fastformat::ff_handler_response_t (FASTFORMAT_CALLCONV *illformed_pfn_t_)(
        void*                           param
    ,   fastformat::ff_parse_code_t     code
    ,   fastformat::ff_string_slice_t   format
    ,   fastformat::ff_string_slice_t   defect
    ,   fastformat::ff_parse_action_t*  illformedAction
    ,   void*                           reserved0
    ,   size_t                          reserved1
    ,   void*                           reserved2
    ,   int                             reserved3
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
    ~param()
    {
        fastformat::illformedHandler_t pfn = f;

        STLSOFT_SUPPRESS_UNUSED(pfn);
    }

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
 * forward declarations
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
 * test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;
    using   fastformat::ff_handler_response_t;
        using   fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
        using   fastformat::FF_HANDLERRESPONSE_NEXT_HANDLER;
    using   fastformat::ff_illformedHandler_info_t;
    using   fastformat::ff_parse_action_t;
    using   fastformat::ff_parse_code_t;
    using   fastformat::ff_string_slice_t;
    using   fastformat::fastformat_getProcessIllformedHandler;
    using   fastformat::fastformat_getThreadIllformedHandler;
    using   fastformat::fastformat_setProcessIllformedHandler;
    using   fastformat::fastformat_setThreadIllformedHandler;


    ff_handler_response_t
    FASTFORMAT_CALLCONV illformedHandler_1_cancel(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_string_slice_t   /* format */
    ,   ff_string_slice_t   /* defect */
    ,   ff_parse_action_t*  /* illformedAction */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    ,   int                 /* reserved3 */
    )
    {
        return FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

#if 0
    ff_handler_response_t
    FASTFORMAT_CALLCONV illformedHandler_1_continue(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_string_slice_t   /* format */
    ,   ff_string_slice_t   /* defect */
    ,   ff_parse_action_t*  /* illformedAction */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    ,   int                 /* reserved3 */
    )
    {
        return FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
    }
#endif


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
    ff_illformedHandler_info_t info = fastformat_getProcessIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);
}

static void test_3()
{
    ff_illformedHandler_info_t info = fastformat_getThreadIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, info.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, info.param);
}

static void test_4()
{
    void*   param = &param;

    ff_illformedHandler_info_t original = fastformat_getProcessIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

    ff_illformedHandler_info_t previous = fastformat_setProcessIllformedHandler(ff_illformedHandler_info_t::make(illformedHandler_1_cancel, param));

    XTESTS_TEST_FN_POINTER_EQUAL(original.handler, previous.handler);
    XTESTS_TEST_POINTER_EQUAL(original.param, previous.param);

    ff_illformedHandler_info_t replaced = fastformat_getProcessIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(illformedHandler_1_cancel, replaced.handler);
    XTESTS_TEST_POINTER_EQUAL(param, replaced.param);
}

static void test_5()
{
    void*   param = &param;

    ff_illformedHandler_info_t original = fastformat_getThreadIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(NULL, original.handler);
    XTESTS_TEST_POINTER_EQUAL(NULL, original.param);

    ff_illformedHandler_info_t previous = fastformat_setThreadIllformedHandler(ff_illformedHandler_info_t::make(illformedHandler_1_cancel, param));

    XTESTS_TEST_FN_POINTER_EQUAL(original.handler, previous.handler);
    XTESTS_TEST_POINTER_EQUAL(original.param, previous.param);

    ff_illformedHandler_info_t replaced = fastformat_getThreadIllformedHandler();

    XTESTS_TEST_FN_POINTER_EQUAL(illformedHandler_1_cancel, replaced.handler);
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

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

