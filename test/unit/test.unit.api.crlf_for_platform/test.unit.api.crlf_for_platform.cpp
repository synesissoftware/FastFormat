/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api.crlf_for_platform.cpp
 *
 * Purpose: Implementation file for the test.unit.api.crlf_for_platform project.
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
#include <platformstl/platformstl.h>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_0(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.api.crlf_for_platform", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
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

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL(x, a)                     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                              FASTFORMAT_LITERAL_STRING


static void test_1_0()
{
    fastformat::string_slice_t  crlf = fastformat::getNewlineForPlatform();

#if defined(PLATFORMSTL_OS_IS_UNIX)
# if defined(UNIXSTL_OS_IS_MACOSX)

    XTESTS_TEST_INTEGER_EQUAL(1u, crlf.len);
    XTESTS_TEST_STRING_EQUAL("\r", crlf.ptr);

# else /* ? OS */

    XTESTS_TEST_INTEGER_EQUAL(1u, crlf.len);
    XTESTS_TEST_STRING_EQUAL("\n", crlf.ptr);

# endif /* OS */

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    XTESTS_TEST_INTEGER_EQUAL(2u, crlf.len);
    XTESTS_TEST_STRING_EQUAL("\r\n", crlf.ptr);

#else /* ? OS */
# error Platform not discriminated
#endif /* OS */
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


