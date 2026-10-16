/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.inserters.character.cpp
 *
 * Purpose: Implementation file for the test.unit.inserters.character project.
 *
 * Created: 11th December 2010
 * Updated: 16th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/inserters/character.hpp>


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <numeric>
#include <string>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL_(x, a)                    XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL(x, a)                     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL_                          XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

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

    if(XTESTS_START_RUNNER("test.unit.inserters.character", verbosity))
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
    using   fastformat::ff_char_t;
    using   fastformat::string_slice_t;
    using   fastformat::fastformat_accumulateSliceLengths;

    typedef std::basic_string<ff_char_t>    string_t;


static void test_1_0()
{
    XTESTS_TEST_STRING_EQUAL("a", fastformat::character('a'));
}

static void test_1_1()
{
    { for(ff_char_t ch = 'a'; ch != 'z'; ++ch)
    {
        ff_char_t sz[2] = { ch, '\0' };

        XTESTS_TEST_STRING_EQUAL_(sz, fastformat::character(ch));
    }}
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


