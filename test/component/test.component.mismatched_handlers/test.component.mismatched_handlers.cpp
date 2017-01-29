/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.mismatched_handlers.cpp
 *
 * Purpose:     Implementation file for the test.component.mismatched_handlers project.
 *
 * Created:     11th November 2013
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2013-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * preprocessor control
 */

#define FASTFORMAT_NO_AUTO_INIT

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* xTests header files */
#include <xtests/xtests.h>

/* FastFormat header files */
#include <fastformat/fastformat.hpp>
//#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>
#include <fastformat/format/specification_defect_handling/mismatched_arguments_scope_base.hpp>


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

    static void test_scenario_2_configuration_1(void);
    static void test_scenario_2_configuration_2(void);
    static void test_scenario_2_configuration_3(void);
    static void test_scenario_2_configuration_4(void);
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
 * classes
 */

using fastformat::mismatched_arguments_scope_base;
using fastformat::ff_replacement_action_t;
using fastformat::ff_replacement_code_t;
using fastformat::ff_string_slice_t;
using fastformat::ff_handler_domain_t;

class ignore_mismatched_handler_scope
    : protected mismatched_arguments_scope_base
{
protected: // Types
    typedef mismatched_arguments_scope_base parent_class_type;

public: // Construction
    explicit ignore_mismatched_handler_scope(ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
        : parent_class_type(domain)
        , m_numCalls(0)
    {}

public: // Accessors
    unsigned get_num_calls() const
    {
        return m_numCalls;
    }

protected: // Overrides
    virtual handler_response_type handle(
        ff_replacement_code_t       code
    ,   size_t                      numArguments
    ,   int                         mismatchedParameterIndex
    ,   ff_replacement_action_t*    missingArgumentAction
    ,   ff_string_slice_t*          slice
    )
    {
        ++m_numCalls;

        return fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
    }

private: // Fields
    unsigned    m_numCalls;
};

class trace_mismatched_handler_scope
    : protected mismatched_arguments_scope_base
{
protected: // Types
    typedef mismatched_arguments_scope_base parent_class_type;

public: // Construction
    trace_mismatched_handler_scope(ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
        : parent_class_type(domain)
        , m_numCalls(0)
    {}

public: // Accessors
    unsigned get_num_calls() const
    {
        return m_numCalls;
    }

protected: // Overrides
    virtual handler_response_type handle(
        ff_replacement_code_t       code
    ,   size_t                      numArguments
    ,   int                         mismatchedParameterIndex
    ,   ff_replacement_action_t*    missingArgumentAction
    ,   ff_string_slice_t*          slice
    )
    {
#ifdef _DEBUG
        fprintf(stderr, "mismatched replacement: first mismatched replacement index %d with %d arguments\n", mismatchedParameterIndex, int(numArguments));
#endif /* _DEBUG */

        ++m_numCalls;

        return fastformat::FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

private: // Fields
    unsigned    m_numCalls;
};

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
            "test.component.mismatched_handlers"
        ,   verbosity
        ,   NULL, NULL
        ,   NULL
        ,   xtests::c::xtestsReportOnlyNonEmptyCases
        ,   ff_setup, ff_teardown, NULL
        ))
    {
        XTESTS_RUN_CASE_THAT_THROWS(test_scenario_2_configuration_1, fastformat::missing_argument_exception);
        XTESTS_RUN_CASE(test_scenario_2_configuration_2);
        XTESTS_RUN_CASE(test_scenario_2_configuration_3);
        XTESTS_RUN_CASE(test_scenario_2_configuration_4);
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
    namespace ff = ::fastformat;


static void test_scenario_2_configuration_1()
{
    std::string sink;

    ff::fmt(sink, "x={0}, y={1}", "x");

    XTESTS_TEST_FAIL("should not get here");
}

static void test_scenario_2_configuration_2()
{
    trace_mismatched_handler_scope   scoper1(fastformat::FF_HANDLERDOMAIN_PROCESS);

    std::string sink;

    try
    {
        ff::fmt(sink, "x={0}, y={1}", "x");

        XTESTS_TEST_FAIL("should not get here");
    }
    catch(fastformat::missing_argument_exception& /* x */)
    {
        XTESTS_TEST_INTEGER_EQUAL(1u, scoper1.get_num_calls());
    }
}

static void test_scenario_2_configuration_3()
{
    trace_mismatched_handler_scope   scoper1(fastformat::FF_HANDLERDOMAIN_PROCESS);
    ignore_mismatched_handler_scope  scoper2;

    std::string sink;

    ff::fmt(sink, "x={0}, y={1}", "x");

    XTESTS_TEST_INTEGER_EQUAL(0u, scoper1.get_num_calls());
    XTESTS_TEST_INTEGER_EQUAL(1u, scoper2.get_num_calls());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x=x, y=", sink);
}

static void test_scenario_2_configuration_4()
{
    trace_mismatched_handler_scope   scoper1(fastformat::FF_HANDLERDOMAIN_PROCESS);
    ignore_mismatched_handler_scope  scoper2;
    trace_mismatched_handler_scope   scoper3;

    std::string sink;

    ff::fmt(sink, "x={0}, y={1}", "x");

    XTESTS_TEST_INTEGER_EQUAL(0u, scoper1.get_num_calls());
    XTESTS_TEST_INTEGER_EQUAL(1u, scoper2.get_num_calls());
    XTESTS_TEST_INTEGER_EQUAL(1u, scoper3.get_num_calls());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x=x, y=", sink);
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


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */
