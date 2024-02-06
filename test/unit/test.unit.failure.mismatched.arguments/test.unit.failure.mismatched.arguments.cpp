/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.failure.mismatched.arguments.cpp
 *
 * Purpose:     Implementation file for the test.unit.failure.mismatched.arguments project.
 *
 * Created:     28th October 2013
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/ff.hpp>
#include <fastformat/format/specification_defect_handling/ignore_missing_arguments_scope.hpp>
#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_that_single_used_argument_succeeds(void);
    static void test_that_single_unused_argument_fails(void);
    static void test_that_single_unused_argument_succeeds_with_scoper(void);
    static void test_that_single_unused_argument_succeeds_with_scoper_0(void);
    static void test_that_single_unused_argument_fails_with_scoper_1(void);
    static void test_that_single_unused_argument_fails_with_scoper_2(void);
    static void test_that_single_unused_argument_fails_with_scoper_3(void);
    static void test_that_single_unused_argument_fails_with_scoper_negative_1(void);
    static void test_1_8(void);
    static void test_1_9(void);
    static void test_that_single_missing_argument_fails(void);
    static void test_that_single_missing_argument_fails_when_told_to_ignore_unreferenced_arguments(void);
    static void test_that_single_missing_argument_succeeds_with_scoper(void);
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

    if(XTESTS_START_RUNNER("test.unit.failure.mismatched.arguments", verbosity))
    {
        XTESTS_RUN_CASE(test_that_single_used_argument_succeeds);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_unused_argument_fails, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE(test_that_single_unused_argument_succeeds_with_scoper);
        XTESTS_RUN_CASE(test_that_single_unused_argument_succeeds_with_scoper_0);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_unused_argument_fails_with_scoper_1, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_unused_argument_fails_with_scoper_2, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_unused_argument_fails_with_scoper_3, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_unused_argument_fails_with_scoper_negative_1, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_missing_argument_fails, ff::missing_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_that_single_missing_argument_fails_when_told_to_ignore_unreferenced_arguments, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE(test_that_single_missing_argument_succeeds_with_scoper);
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

static void test_that_single_used_argument_succeeds()
{
    std::string sink;

    ff::fmt(sink, "{0}", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_fails()
{
    std::string sink;

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_succeeds_with_scoper()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper;

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_succeeds_with_scoper_0()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper;

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_fails_with_scoper_1()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(1);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_fails_with_scoper_2()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(2);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_fails_with_scoper_3()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(3);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_unused_argument_fails_with_scoper_negative_1()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(-1);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_that_single_missing_argument_fails()
{
    std::string sink;

    ff::fmt(sink, "{0}{1}", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_missing_argument_fails_when_told_to_ignore_unreferenced_arguments()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper;

    ff::fmt(sink, "{0}{1}", "");

    XTESTS_TEST_PASSED();
}

static void test_that_single_missing_argument_succeeds_with_scoper()
{
    std::string sink;

    ff::ignore_missing_arguments_scope  scoper;

    ff::fmt(sink, "{0}{1}", "");

    XTESTS_TEST_PASSED();
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

