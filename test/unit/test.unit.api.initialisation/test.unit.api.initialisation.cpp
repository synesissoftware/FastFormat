/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api.initialisation.cpp
 *
 * Purpose: Implementation file for the test.unit.api.initialisation project.
 *
 * Created: 27th May 2008
 * Updated: 16th October 2026
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

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/char_conversions.hpp>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#define FF_STR                                              FASTFORMAT_LITERAL_STRING


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.api.initialisation", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
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

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define t2m                                                stlsoft::w2m
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define t2m(x)     x
#endif /* FASTFORMAT_USE_WIDE_STRINGS */


static void test_1_0()
{
    int res = fastformat::init();

    if(res < 0)
    {
        fastformat::ff_char_t const*    qualifier = fastformat::getInitCodeString(res);

        XTESTS_TEST_FAIL_WITH_QUALIFIER("FastFormat API failed to initialise", t2m(qualifier));
    }
    else
    {
        XTESTS_TEST_PASSED();

        fastformat::uninit();
    }
}

static void test_1_1()
{
    { for(size_t i = 0u; i != 100000u; ++i)
    {
        int res = fastformat::init();

        if(res < 0)
        {
            fastformat::ff_char_t const* qualifier = fastformat::getInitCodeString(res);

            XTESTS_TEST_FAIL_WITH_QUALIFIER("FastFormat API failed to initialise", t2m(qualifier));

            break;
        }
        else
        {
            XTESTS_TEST_PASSED();

            fastformat::uninit();
        }
    }}
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


