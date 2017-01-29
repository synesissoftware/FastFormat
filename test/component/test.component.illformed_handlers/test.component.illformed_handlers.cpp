/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.illformed_handlers.cpp
 *
 * Purpose:     Implementation file for the test.component.illformed_handlers project.
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

    static void test_scenario_1_configuration_0(void);
    static void test_scenario_1_configuration_1(void);
    static void test_scenario_1_configuration_2(void);
    static void test_scenario_1_configuration_3(void);
    static void test_scenario_1_configuration_4(void);
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

using fastformat::ff_handler_domain_t;

class illformed_handler_scope_specifier_base
{
public:
    typedef fastformat::ff_illformedHandler_info_t  handler_info_type;
protected:
    typedef handler_info_type
                              (FASTFORMAT_CALLCONV *handler_specifier_function_type)(handler_info_type);

protected:
    illformed_handler_scope_specifier_base(ff_handler_domain_t domain)
        : m_specifier(select_specifier_(domain))
    {}

private:
    static handler_specifier_function_type select_specifier_(ff_handler_domain_t domain)
    {
        using namespace fastformat;

        return (fastformat::FF_HANDLERDOMAIN_PROCESS == domain) ? fastformat_setProcessIllformedHandler : fastformat_setThreadIllformedHandler;
    }

protected:
    handler_specifier_function_type const   m_specifier;
};

class illformed_handler_scope_base
    : protected illformed_handler_scope_specifier_base
{
public:
    typedef fastformat::ff_illformedHandler_info_t  handler_info_type;
    typedef fastformat::ff_handler_response_t       handler_response_type;
protected:
    typedef fastformat::ff_parse_action_t           ff_parse_action_t;
    typedef fastformat::ff_parse_code_t             ff_parse_code_t;
    typedef fastformat::ff_string_slice_t           ff_string_slice_t;
    typedef illformed_handler_scope_specifier_base  parent_class_type;
public:
    typedef illformed_handler_scope_base            class_type;

protected: // Construction
    illformed_handler_scope_base(ff_handler_domain_t domain)
        : parent_class_type(domain)
        , m_previous((*m_specifier)(handler_info_type::make(&class_type::handler, get_this_())))
    {}

    virtual ~illformed_handler_scope_base() throw()
    {
        (*m_specifier)(m_previous);
    }

protected: // Overrides
    virtual handler_response_type handle(
        ff_parse_code_t     code
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   defect
    ,   ff_parse_action_t*  illformedAction
    ) = 0;

private: // Implementation
    class_type* get_this_()
    {
        return this;
    }

    static handler_response_type handler(
        void*               param
    ,   ff_parse_code_t     code
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   defect
    ,   ff_parse_action_t*  illformedAction
    ,   void*               reserved0
    ,   size_t              reserved1
    ,   void*               reserved2
    ,   int                 reserved3
    )
    {
        class_type* pThis = static_cast<class_type*>(param);

        handler_response_type hr = pThis->handle(code, format, defect, illformedAction);

        if(fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING == hr)
        {
            return hr;
        }

        if(NULL != pThis->m_previous.handler)
        {
            return (*pThis->m_previous.handler)(pThis->m_previous.param, code, format, defect, illformedAction, reserved0, reserved1, reserved2, reserved3);
        }

        return fastformat::FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

private: // Fields
    handler_info_type const                 m_previous;
};

class ignore_illformed_handler_scope
    : protected illformed_handler_scope_base
{
protected: // Types
    typedef illformed_handler_scope_base    parent_class_type;

public: // Construction
    explicit ignore_illformed_handler_scope(ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
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
        ff_parse_code_t     code
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   defect
    ,   ff_parse_action_t*  illformedAction
    )
    {
        ++m_numCalls;

        return fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
    }

private: // Fields
    unsigned    m_numCalls;
};

class trace_illformed_handler_scope
    : protected illformed_handler_scope_base
{
protected: // Types
    typedef illformed_handler_scope_base    parent_class_type;

public: // Construction
    trace_illformed_handler_scope(ff_handler_domain_t domain = fastformat::FF_HANDLERDOMAIN_THREAD)
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
        ff_parse_code_t     code
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   defect
    ,   ff_parse_action_t*  illformedAction
    )
    {
#ifdef _DEBUG
        fprintf(stderr, "illformed format: '%.*s' in '%.*s'\n", defect.len, defect.ptr, format.len, format.ptr);
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
            "test.component.illformed_handlers"
        ,   verbosity
        ,   NULL, NULL
        ,   NULL
        ,   xtests::c::xtestsReportOnlyNonEmptyCases
        ,   ff_setup, ff_teardown, NULL
        ))
    {
        XTESTS_RUN_CASE(test_scenario_1_configuration_0);
        XTESTS_RUN_CASE_THAT_THROWS(test_scenario_1_configuration_1, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE(test_scenario_1_configuration_2);
        XTESTS_RUN_CASE(test_scenario_1_configuration_3);
        XTESTS_RUN_CASE(test_scenario_1_configuration_4);
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


static void test_scenario_1_configuration_0()
{
    ff::setProcessIllformedHandler(ff::illformedHandler_info_t::make(NULL, NULL));
    ff::setThreadIllformedHandler(ff::illformedHandler_info_t::make(NULL, NULL));

    std::string sink;

    ff::fmt(sink, "x={0}, y={{", "x");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x=x, y={", sink);
}

static void test_scenario_1_configuration_1()
{
    ff::setProcessIllformedHandler(ff::illformedHandler_info_t::make(NULL, NULL));
    ff::setThreadIllformedHandler(ff::illformedHandler_info_t::make(NULL, NULL));

    std::string sink;

    ff::fmt(sink, "x={0}, y={", "x");

    XTESTS_TEST_FAIL("should not get here");
}

static void test_scenario_1_configuration_2()
{
    trace_illformed_handler_scope   scoper1(fastformat::FF_HANDLERDOMAIN_PROCESS);

    std::string sink;

    try
    {
        ff::fmt(sink, "x={0}, y={", "x");

        XTESTS_TEST_FAIL("should not get here");
    }
    catch(fastformat::illformed_format_exception& /* x */)
    {
        XTESTS_TEST_INTEGER_EQUAL(1u, scoper1.get_num_calls());
    }
}

static void test_scenario_1_configuration_3()
{
    trace_illformed_handler_scope   scoper1(fastformat::FF_HANDLERDOMAIN_PROCESS);
    ignore_illformed_handler_scope  scoper2;

    std::string sink;

    ff::fmt(sink, "x={0}, y={", "x");

    XTESTS_TEST_INTEGER_EQUAL(0u, scoper1.get_num_calls());
    XTESTS_TEST_INTEGER_EQUAL(1u, scoper2.get_num_calls());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x=x, y={", sink);
}

static void test_scenario_1_configuration_4()
{
    trace_illformed_handler_scope   scoper1(fastformat::FF_HANDLERDOMAIN_PROCESS);
    ignore_illformed_handler_scope  scoper2;
    trace_illformed_handler_scope   scoper3;

    std::string sink;

    ff::fmt(sink, "x={0}, y={", "x");

    XTESTS_TEST_INTEGER_EQUAL(0u, scoper1.get_num_calls());
    XTESTS_TEST_INTEGER_EQUAL(1u, scoper2.get_num_calls());
    XTESTS_TEST_INTEGER_EQUAL(1u, scoper3.get_num_calls());
    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x=x, y={", sink);
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
