/* /////////////////////////////////////////////////////////////////////////
 * File:    test.component.iterators.format_iterator.cpp
 *
 * Purpose: Implementation file for the test.component.iterators.format_iterator project.
 *
 * Created: 26th April 2008
 * Updated: 16th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/iterators/format_iterator.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/util/minmax.hpp>

/* Standard C header files */
#include <math.h>
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * Decimal places expected as correct, per compiler
 */

namespace
{

} // anonymous namespace


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

    if(XTESTS_START_RUNNER("test.component.iterators.format_iterator", verbosity))
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

    typedef std::basic_string<ff_char_t>    string_t;

    ff_char_t const*  strings[] =
    {
        FASTFORMAT_LITERAL_STRING(""),
        FASTFORMAT_LITERAL_STRING("abc"),
        FASTFORMAT_LITERAL_STRING("def"),
        FASTFORMAT_LITERAL_STRING("ghi"),
        FASTFORMAT_LITERAL_STRING("jkl"),
        FASTFORMAT_LITERAL_STRING("mno"),
        FASTFORMAT_LITERAL_STRING("pqr"),
        FASTFORMAT_LITERAL_STRING("stu"),
        FASTFORMAT_LITERAL_STRING("v"),
        FASTFORMAT_LITERAL_STRING("w"),
        FASTFORMAT_LITERAL_STRING("x"),
        FASTFORMAT_LITERAL_STRING("y"),
        FASTFORMAT_LITERAL_STRING("z"),
    };

#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define XTESTS_TEST_STRING_EQUAL(x, a)                     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define XTESTS_TEST_STRING_EQUAL_N(x, a, n)                XTESTS_TEST_WIDE_STRING_EQUAL_N(FASTFORMAT_LITERAL_STRING(x), a, n)
# define XTESTS_TEST_STRING_CONTAIN(x, a)                   XTESTS_TEST_WIDE_STRING_CONTAIN(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N                         XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_STRING_CONTAIN                         XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                              FASTFORMAT_LITERAL_STRING


static void test_1_0()
{
    std::basic_string<ff_char_t> sink;

    std::copy(
        strings,
        strings + STLSOFT_NUM_ELEMENTS(strings),
        fastformat::format_iterator(sink, FASTFORMAT_LITERAL_STRING("{0}")));

    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", sink);
}

static void test_1_1()
{
    std::basic_string<ff_char_t> sink;

    std::copy(
        strings,
        strings + STLSOFT_NUM_ELEMENTS(strings),
        fastformat::format_iterator(
            sink,
            FASTFORMAT_LITERAL_STRING("{1}{0}{2}"),
            FASTFORMAT_LITERAL_STRING("["),
            FASTFORMAT_LITERAL_STRING("]")));

    XTESTS_TEST_STRING_EQUAL("[][abc][def][ghi][jkl][mno][pqr][stu][v][w][x][y][z]", sink);
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */


