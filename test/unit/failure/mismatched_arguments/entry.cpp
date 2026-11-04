/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/failure/mismatched_arguments/entry.cpp
 *
 * Purpose: Unit tests for failure.mismatched.arguments.
 *
 * Created: 28th October 2013
 * Updated: 5th November 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/ff.hpp>
#include <fastformat/format/specification_defect_handling/ignore_missing_arguments_scope.hpp>
#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void TEST_THAT_SINGLE_USED_ARGUMENT_SUCCEEDS();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_SUCCEEDS_WITH_SCOPER();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_SUCCEEDS_WITH_SCOPER_0();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_1();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_2();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_3();
    static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_NEGATIVE_1();
    static void TEST_THAT_SINGLE_MISSING_ARGUMENT_FAILS();
    static void TEST_THAT_SINGLE_MISSING_ARGUMENT_FAILS_WHEN_TOLD_TO_IGNORE_UNREFERENCED_ARGUMENTS();
    static void TEST_THAT_SINGLE_MISSING_ARGUMENT_SUCCEEDS_WITH_SCOPER();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER(__FILE__, verbosity))
    {
        XTESTS_RUN_CASE(TEST_THAT_SINGLE_USED_ARGUMENT_SUCCEEDS);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE(TEST_THAT_SINGLE_UNUSED_ARGUMENT_SUCCEEDS_WITH_SCOPER);
        XTESTS_RUN_CASE(TEST_THAT_SINGLE_UNUSED_ARGUMENT_SUCCEEDS_WITH_SCOPER_0);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_1, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_2, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_3, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_NEGATIVE_1, ff::unreferenced_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_MISSING_ARGUMENT_FAILS, ff::missing_argument_exception);
        XTESTS_RUN_CASE_THAT_THROWS(TEST_THAT_SINGLE_MISSING_ARGUMENT_FAILS_WHEN_TOLD_TO_IGNORE_UNREFERENCED_ARGUMENTS, ff::missing_argument_exception);
        XTESTS_RUN_CASE(TEST_THAT_SINGLE_MISSING_ARGUMENT_SUCCEEDS_WITH_SCOPER);
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

static void TEST_THAT_SINGLE_USED_ARGUMENT_SUCCEEDS()
{
    std::string sink;

    ff::fmt(sink, "{0}", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS()
{
    std::string sink;

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_SUCCEEDS_WITH_SCOPER()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper;

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_SUCCEEDS_WITH_SCOPER_0()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper;

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_1()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(1);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_2()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(2);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_3()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(3);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_UNUSED_ARGUMENT_FAILS_WITH_SCOPER_NEGATIVE_1()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper(-1);

    ff::fmt(sink, "", "");

    XTESTS_TEST_PASSED();
}


static void TEST_THAT_SINGLE_MISSING_ARGUMENT_FAILS()
{
    std::string sink;

    ff::fmt(sink, "{0}{1}", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_MISSING_ARGUMENT_FAILS_WHEN_TOLD_TO_IGNORE_UNREFERENCED_ARGUMENTS()
{
    std::string sink;

    ff::ignore_unreferenced_arguments_scope scoper;

    ff::fmt(sink, "{0}{1}", "");

    XTESTS_TEST_PASSED();
}

static void TEST_THAT_SINGLE_MISSING_ARGUMENT_SUCCEEDS_WITH_SCOPER()
{
    std::string sink;

    ff::ignore_missing_arguments_scope  scoper;

    ff::fmt(sink, "{0}{1}", "");

    XTESTS_TEST_PASSED();
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


