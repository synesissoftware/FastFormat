/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.shims_and_namespaces.main.cpp
 *
 * Purpose: Main implementation file for the test.unit.shims_and_namespaces project.
 *
 * Created: 11th November 2013
 * Updated: 5th November 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* FastFormat header files */
#include <fastformat/fastformat.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

extern "C++"
{

    namespace TEST_WITH_FASTFORMAT_NAMESPACE
    {
        void TEST_slice_EMPTY_AND_NULL();
        void TEST_slice_EMPTY_AND_NON_NULL();
        void TEST_slice_SHORT_FULL_STRING();
        void TEST_slice_SHORT_PARTIAL_STRING();

        void TEST_parse_code_1();
        void TEST_parse_code_2();
        void TEST_parse_code_3();
        void TEST_replacement_code_1();
        void TEST_replacement_code_2();
        void TEST_replacement_code_3();
    } // namespace TEST_WITH_FASTFORMAT_NAMESPACE */

    namespace TEST_WITHOUT_FASTFORMAT_NAMESPACE
    {
        void TEST_slice_EMPTY_AND_NULL();
        void TEST_slice_EMPTY_AND_NON_NULL();
        void TEST_slice_SHORT_FULL_STRING();
        void TEST_slice_SHORT_PARTIAL_STRING();

        void TEST_parse_code_1();
        void TEST_parse_code_2();
        void TEST_parse_code_3();
        void TEST_replacement_code_1();
        void TEST_replacement_code_2();
        void TEST_replacement_code_3();
    } // namespace TEST_WITHOUT_FASTFORMAT_NAMESPACE

    namespace TEST_WITHOUT_STLSOFT_NAMESPACE
    {
        void TEST_slice_EMPTY_AND_NULL();
        void TEST_slice_EMPTY_AND_NON_NULL();
        void TEST_slice_SHORT_FULL_STRING();
        void TEST_slice_SHORT_PARTIAL_STRING();

        void TEST_parse_code_1();
        void TEST_parse_code_2();
        void TEST_parse_code_3();
        void TEST_replacement_code_1();
        void TEST_replacement_code_2();
        void TEST_replacement_code_3();
    } // namespace TEST_WITHOUT_STLSOFT_NAMESPACE */

    namespace TEST_WITHOUT_EITHER_NAMESPACE
    {
        void TEST_slice_EMPTY_AND_NULL();
        void TEST_slice_EMPTY_AND_NON_NULL();
        void TEST_slice_SHORT_FULL_STRING();
        void TEST_slice_SHORT_PARTIAL_STRING();

        void TEST_parse_code_1();
        void TEST_parse_code_2();
        void TEST_parse_code_3();
        void TEST_replacement_code_1();
        void TEST_replacement_code_2();
        void TEST_replacement_code_3();
    } // namespace TEST_WITHOUT_EITHER_NAMESPACE */
} // extern "C++"


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    int const executionFlags    =   0
                                |   xtests::c::xtestsReportOnlyNonEmptyCases
                                ;

    if(XTESTS_START_RUNNER_WITH_FLAGS("test.unit.shims_and_namespaces", verbosity, executionFlags))
    {
        // TEST_WITH_FASTFORMAT_NAMESPACE

        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_slice_EMPTY_AND_NULL);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_slice_EMPTY_AND_NON_NULL);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_slice_SHORT_FULL_STRING);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_slice_SHORT_PARTIAL_STRING);

        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_parse_code_1);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_parse_code_2);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_parse_code_3);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_replacement_code_1);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_replacement_code_2);
        XTESTS_RUN_CASE(TEST_WITH_FASTFORMAT_NAMESPACE::TEST_replacement_code_3);

        // TEST_WITHOUT_FASTFORMAT_NAMESPACE

        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_slice_EMPTY_AND_NULL);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_slice_EMPTY_AND_NON_NULL);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_slice_SHORT_FULL_STRING);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_slice_SHORT_PARTIAL_STRING);

        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_parse_code_1);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_parse_code_2);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_parse_code_3);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_replacement_code_1);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_replacement_code_2);
        XTESTS_RUN_CASE(TEST_WITHOUT_FASTFORMAT_NAMESPACE::TEST_replacement_code_3);

        // TEST_WITHOUT_STLSOFT_NAMESPACE

        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_slice_EMPTY_AND_NULL);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_slice_EMPTY_AND_NON_NULL);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_slice_SHORT_FULL_STRING);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_slice_SHORT_PARTIAL_STRING);

        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_parse_code_1);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_parse_code_2);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_parse_code_3);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_replacement_code_1);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_replacement_code_2);
        XTESTS_RUN_CASE(TEST_WITHOUT_STLSOFT_NAMESPACE::TEST_replacement_code_3);

        // TEST_WITHOUT_EITHER_NAMESPACE

        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_slice_EMPTY_AND_NULL);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_slice_EMPTY_AND_NON_NULL);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_slice_SHORT_FULL_STRING);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_slice_SHORT_PARTIAL_STRING);

        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_parse_code_1);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_parse_code_2);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_parse_code_3);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_replacement_code_1);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_replacement_code_2);
        XTESTS_RUN_CASE(TEST_WITHOUT_EITHER_NAMESPACE::TEST_replacement_code_3);


        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* ///////////////////////////// end of file //////////////////////////// */


