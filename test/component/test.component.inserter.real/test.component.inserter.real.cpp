/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.inserter.real.cpp
 *
 * Purpose:     Implementation file for the test.component.inserter.real project.
 *
 * Created:     26th April 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/inserters/real.hpp>

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

#if defined(STLSOFT_COMPILER_IS_MSVC)
    const int   CORRECT_DEC_PLACES  =   511;
#elif defined(STLSOFT_COMPILER_IS_BORLAND)
    const int   CORRECT_DEC_PLACES  =   12;
    const int   MAX_DEC_PLACES      =   35;
#elif defined(STLSOFT_COMPILER_IS_CLANG) || \
      defined(STLSOFT_COMPILER_IS_GCC)
    const int   CORRECT_DEC_PLACES  =   12;
#elif defined(STLSOFT_COMPILER_IS_MWERKS)
    const int   CORRECT_DEC_PLACES  =   12;
#else
    const int   CORRECT_DEC_PLACES  =   20;
#endif

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
    static void test_1_2(void);
    static void test_1_3(void);
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
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);

    static void test_2_0(void);
    static void test_2_1(void);
    static void test_2_2(void);
    static void test_2_3(void);
    static void test_2_4(void);
    static void test_2_5(void);
    static void test_2_6(void);
    static void test_2_7(void);
    static void test_2_8(void);
    static void test_2_9(void);
    static void test_2_10(void);
    static void test_2_11(void);
    static void test_2_12(void);
    static void test_2_13(void);
    static void test_2_14(void);
    static void test_2_15(void);
    static void test_2_16(void);
    static void test_2_17(void);
    static void test_2_18(void);
    static void test_2_19(void);
    static void test_2_20(void);
    static void test_2_28(void);
    static void test_2_29(void);

    static void test_3_0(void);
    static void test_3_1(void);
    static void test_3_2(void);
    static void test_3_3(void);
    static void test_3_4(void);
    static void test_3_5(void);
    static void test_3_6(void);
    static void test_3_7(void);
    static void test_3_8(void);
    static void test_3_9(void);
    static void test_3_10(void);
    static void test_3_11(void);
    static void test_3_12(void);
    static void test_3_13(void);
    static void test_3_14(void);
    static void test_3_15(void);
    static void test_3_16(void);
    static void test_3_17(void);
    static void test_3_18(void);
    static void test_3_19(void);
    static void test_3_20(void);
    static void test_3_28(void);
    static void test_3_29(void);

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

#if 0
    fprintf(stderr, "%%2.2e:      [%2.2e]\n", 12345.67);
    fprintf(stderr, "%%2.2f:      [%2.2f]\n", 12345.67);
    fprintf(stderr, "%%2.2g:      [%2.2g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-2.2e:     [%-2.2e]\n", 12345.67);
    fprintf(stderr, "%%-2.2f:     [%-2.2f]\n", 12345.67);
    fprintf(stderr, "%%-2.2g:     [%-2.2g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%9.2e:      [%9.2e]\n", 12345.67);
    fprintf(stderr, "%%9.2f:      [%9.2f]\n", 12345.67);
    fprintf(stderr, "%%9.2g:      [%9.2g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-9.2e:     [%-9.2e]\n", 12345.67);
    fprintf(stderr, "%%-9.2f:     [%-9.2f]\n", 12345.67);
    fprintf(stderr, "%%-9.2g:     [%-9.2g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%19.2e:     [%19.2e]\n", 12345.67);
    fprintf(stderr, "%%19.2f:     [%19.2f]\n", 12345.67);
    fprintf(stderr, "%%19.2g:     [%19.2g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-19.2e:    [%-19.2e]\n", 12345.67);
    fprintf(stderr, "%%-19.2f:    [%-19.2f]\n", 12345.67);
    fprintf(stderr, "%%-19.2g:    [%-19.2g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%19.12e:    [%19.12e]\n", 12345.67);
    fprintf(stderr, "%%19.12f:    [%19.12f]\n", 12345.67);
    fprintf(stderr, "%%19.12g:    [%19.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-19.12e:   [%-19.12e]\n", 12345.67);
    fprintf(stderr, "%%-19.12f:   [%-19.12f]\n", 12345.67);
    fprintf(stderr, "%%-19.12g:   [%-19.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%39.12e:    [%39.12e]\n", 12345.67);
    fprintf(stderr, "%%39.12f:    [%39.12f]\n", 12345.67);
    fprintf(stderr, "%%39.12g:    [%39.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-39.12e:   [%-39.12e]\n", 12345.67);
    fprintf(stderr, "%%-39.12f:   [%-39.12f]\n", 12345.67);
    fprintf(stderr, "%%-39.12g:   [%-39.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%89.12e:    [%89.12e]\n", 12345.67);
    fprintf(stderr, "%%89.12f:    [%89.12f]\n", 12345.67);
    fprintf(stderr, "%%89.12g:    [%89.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-89.12e:   [%-89.12e]\n", 12345.67);
    fprintf(stderr, "%%-89.12f:   [%-89.12f]\n", 12345.67);
    fprintf(stderr, "%%-89.12g:   [%-89.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%89.72e:    [%89.72e]\n", 12345.67);
    fprintf(stderr, "%%89.72f:    [%89.72f]\n", 12345.67);
    fprintf(stderr, "%%89.72g:    [%89.72g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-89.72e:   [%-89.72e]\n", 12345.67);
    fprintf(stderr, "%%-89.72f:   [%-89.72f]\n", 12345.67);
    fprintf(stderr, "%%-89.72g:   [%-89.72g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%189.12e:   [%189.12e]\n", 12345.67);
    fprintf(stderr, "%%189.12f:   [%189.12f]\n", 12345.67);
    fprintf(stderr, "%%189.12g:   [%189.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-189.12e:  [%-189.12e]\n", 12345.67);
    fprintf(stderr, "%%-189.12f:  [%-189.12f]\n", 12345.67);
    fprintf(stderr, "%%-189.12g:  [%-189.12g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%189.172e:  [%189.172e]\n", 12345.67);
    fprintf(stderr, "%%189.172f:  [%189.172f]\n", 12345.67);
    fprintf(stderr, "%%189.172g:  [%189.172g]\n", 12345.67);
    fprintf(stderr, "\n");

    fprintf(stderr, "%%-189.172e: [%-189.172e]\n", 12345.67);
    fprintf(stderr, "%%-189.172f: [%-189.172f]\n", 12345.67);
    fprintf(stderr, "%%-189.172g: [%-189.172g]\n", 12345.67);
    fprintf(stderr, "\n");

    if(argc > 0)    return EXIT_SUCCESS;
#endif /* 0 */

    if(XTESTS_START_RUNNER("test.component.inserter.real", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
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
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);

        XTESTS_RUN_CASE(test_2_0);
        XTESTS_RUN_CASE(test_2_1);
        XTESTS_RUN_CASE(test_2_2);
        XTESTS_RUN_CASE(test_2_3);
        XTESTS_RUN_CASE(test_2_4);
        XTESTS_RUN_CASE(test_2_5);
        XTESTS_RUN_CASE(test_2_6);
        XTESTS_RUN_CASE(test_2_7);
        XTESTS_RUN_CASE(test_2_8);
        XTESTS_RUN_CASE(test_2_9);
        XTESTS_RUN_CASE(test_2_10);
        XTESTS_RUN_CASE(test_2_11);
        XTESTS_RUN_CASE(test_2_12);
        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16);
        XTESTS_RUN_CASE(test_2_17);
        XTESTS_RUN_CASE(test_2_18);
        XTESTS_RUN_CASE(test_2_19);
        XTESTS_RUN_CASE(test_2_20);
        XTESTS_RUN_CASE(test_2_28);
        XTESTS_RUN_CASE(test_2_29);

        XTESTS_RUN_CASE(test_3_0);
        XTESTS_RUN_CASE(test_3_1);
        XTESTS_RUN_CASE(test_3_2);
        XTESTS_RUN_CASE(test_3_3);
        XTESTS_RUN_CASE(test_3_4);
        XTESTS_RUN_CASE(test_3_5);
        XTESTS_RUN_CASE(test_3_6);
        XTESTS_RUN_CASE(test_3_7);
        XTESTS_RUN_CASE(test_3_8);
        XTESTS_RUN_CASE(test_3_9);
        XTESTS_RUN_CASE(test_3_10);
        XTESTS_RUN_CASE(test_3_11);
        XTESTS_RUN_CASE(test_3_12);
        XTESTS_RUN_CASE(test_3_13);
        XTESTS_RUN_CASE(test_3_14);
        XTESTS_RUN_CASE(test_3_15);
        XTESTS_RUN_CASE(test_3_16);
        XTESTS_RUN_CASE(test_3_17);
        XTESTS_RUN_CASE(test_3_18);
        XTESTS_RUN_CASE(test_3_19);
        XTESTS_RUN_CASE(test_3_20);
        XTESTS_RUN_CASE(test_3_28);
        XTESTS_RUN_CASE(test_3_29);

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
    using   fastformat::ff_char_t;

    typedef std::basic_string<ff_char_t>    string_t;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)         XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define XTESTS_TEST_STRING_EQUAL_N(x, a, n)    XTESTS_TEST_WIDE_STRING_EQUAL_N(FASTFORMAT_LITERAL_STRING(x), a, n)
# define XTESTS_TEST_STRING_CONTAIN(x, a)       XTESTS_TEST_WIDE_STRING_CONTAIN(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL               XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL_N             XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_STRING_CONTAIN             XTESTS_TEST_MULTIBYTE_STRING_CONTAIN
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                                  FASTFORMAT_LITERAL_STRING

    inline double str_to_double(ff_char_t const* s)
    {
        ff_char_t*  endptr;
        double      result;

#ifdef FASTFORMAT_USE_WIDE_STRINGS
        result = ::wcstod(s, &endptr);
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
        result = ::strtod(s, &endptr);
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

        if( NULL == endptr ||
            '\0' != *endptr)
        {
            result = HUGE_VAL;
        }

        return result;
    }

    static string_t crlf(ff::getNewlineForPlatform().ptr, ff::getNewlineForPlatform().len);


    static string_t strip_leading_zeroes_(ff_char_t const* s, size_t len)
    {
        ff_char_t   prev2   =   '\0';
        ff_char_t   prev1   =   '\0';
        string_t    result;

        STLSOFT_SUPPRESS_UNUSED(prev2); // Silly old Borland

        { for(size_t i = 0; i != len; ++i)
        {
            const ff_char_t ch = s[i];

            if('0' == ch)
            {
                switch(prev1)
                {
                    case    '-':
                    case    '+':
                        break;
                    default:
                        prev2 = prev1;
                        prev1 = ch;
                        result.append(1u, ch);

                        STLSOFT_SUPPRESS_UNUSED(prev2); // Silly old Borland
                        break;
                }
            }
            else
            {
                prev2 = prev1;
                prev1 = ch;
                result.append(1u, ch);

                STLSOFT_SUPPRESS_UNUSED(prev2); // Silly old Borland
            }
        }}

        return result;
    }

    template <typename S>
    static string_t strip_leading_zeroes(S const& str)
    {
        return strip_leading_zeroes_(stlsoft::c_str_data(str), stlsoft::c_str_len(str));
    }



static void test_1_0()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456));

    XTESTS_TEST_STRING_EQUAL("123.456000", sink);
}

static void test_1_1()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 0, 3));

    XTESTS_TEST_STRING_EQUAL("123.456", sink);
}

static void test_1_2()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 10, 3));

    XTESTS_TEST_STRING_EQUAL("   123.456", sink);
}

static void test_1_3()
{
}

static void test_1_4()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67));

    XTESTS_TEST_STRING_EQUAL("12345.670000", sink);
}

static void test_1_5()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 0));

    XTESTS_TEST_STRING_EQUAL("     12346", sink);
}

static void test_1_6()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 1));

    XTESTS_TEST_STRING_EQUAL("   12345.7", sink);
}

static void test_1_7()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 2));

    XTESTS_TEST_STRING_EQUAL("  12345.67", sink);
}

static void test_1_8()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 3));

    XTESTS_TEST_STRING_EQUAL(" 12345.670", sink);
}

static void test_1_9()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 4));

    XTESTS_TEST_STRING_EQUAL("12345.6700", sink);
}

static void test_1_10()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 5));

    XTESTS_TEST_STRING_EQUAL("12345.67000", sink);
}

static void test_1_11()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 6));

    XTESTS_TEST_STRING_EQUAL("12345.670000", sink);
}

static void test_1_12()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, 5));

    XTESTS_TEST_STRING_EQUAL("12345.67000", sink);
}

static void test_1_13()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67));

    XTESTS_TEST_STRING_EQUAL("12345.670000", sink);
}

static void test_1_14()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 20, 0));

    XTESTS_TEST_STRING_EQUAL("               12346", sink);
}

static void test_1_15()
{
}

static void test_1_16()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 7, 7));

    XTESTS_TEST_STRING_EQUAL("12345.6700000", sink);
}


static void test_1_17()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 15, 15));

    XTESTS_TEST_STRING_EQUAL_N("12345.670000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));
}

static void test_1_18()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 31, 31));

    XTESTS_TEST_STRING_EQUAL_N("12345.6700000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));
}

static void test_1_19()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 63, 63));

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL_N("12345.670000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_20()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 127, 127));

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL_N("12345.6700000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_21()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 255, 255));

#if !defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL_N("12345.670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_22()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 511, 511));

#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL_N("12345.6700000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", sink, stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#endif /* compiler */
}

static void test_1_23()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(-0.00001234567, 10, 10, 'g'));

    XTESTS_TEST_STRING_EQUAL("-1.234567e-5", strip_leading_zeroes(sink));
}

static void test_1_24()
{
}

static void test_1_25()
{
}

static void test_1_26()
{
}

static void test_1_27()
{
}

static void test_1_28()
{
}

static void test_1_29()
{
}





static void test_2_0()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 0, 3, 'g'));

    XTESTS_TEST_STRING_EQUAL("123", sink);
}

static void test_2_1()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 6, 3, 'g'));

    XTESTS_TEST_STRING_EQUAL("   123", sink);
}

static void test_2_2()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 10, 3, 'g'));

    XTESTS_TEST_STRING_EQUAL("       123", sink);
}

static void test_2_3()
{
}

static void test_2_4()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, 1, 'g'));

    XTESTS_TEST_STRING_EQUAL("1e+4", strip_leading_zeroes(sink));
}

static void test_2_5()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 0, 'g'));

#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);

#endif /* compiler */
}

static void test_2_6()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 1, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
}

static void test_2_7()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 2, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.2e+", sink);
}

static void test_2_8()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 3, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.23e+", sink);
}

static void test_2_9()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 4, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
}

static void test_2_10()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 5, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_EQUAL("     12346", sink);
}

static void test_2_11()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 6, 'g'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_EQUAL("   12345.7", sink);
}

static void test_2_12()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, 5, 'g'));

    XTESTS_TEST_STRING_EQUAL("12346", sink);
}

static void test_2_13()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, 1, 'g'));

    XTESTS_TEST_STRING_EQUAL("1e+4", strip_leading_zeroes(sink));
}

static void test_2_14()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 20, 0, 'g'));

#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    XTESTS_TEST_STRING_CONTAIN("1e+", sink);

#endif /* compiler */
}

static void test_2_15()
{
#if 1

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 15, 15, 'g'));

    XTESTS_TEST_STRING_EQUAL("       12345.67", sink);

#endif /* compiler */
}

static void test_2_16()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 31, 7, 'g'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

    XTESTS_TEST_STRING_EQUAL("                       12345.67", sink);
}

static void test_2_17()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 63, 7, 'g'));

#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_18()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 127, 127, 'g'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                                                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_19()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 255, 255, 'g'));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                                                                                                                                                                                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_20()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 511, 511, 'g'));

# if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
     !defined(STLSOFT_COMPILER_IS_MWERKS)

    XTESTS_TEST_STRING_EQUAL("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       12345.67", sink);

# endif /* compiler */
#endif /* compiler */
}

static void test_2_28()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(1e-10, 0, -1, 'g'));

#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    XTESTS_TEST_STRING_CONTAIN("1e-", sink);

#endif /* compiler */
}

static void test_2_29()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(1e-10, 0, -1, 'g'));

#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    XTESTS_TEST_STRING_CONTAIN("1e-", sink);

#endif /* compiler */
}




static void test_3_0()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 0, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1e+2", strip_leading_zeroes(sink));
}

static void test_3_1()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 0, 3, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
}

static void test_3_2()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(123.456, 10, 3, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
}

static void test_3_3()
{
}

static void test_3_4()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1e+4", strip_leading_zeroes(sink));
}

static void test_3_5()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 0, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
}

static void test_3_6()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 1, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.2e+", sink);
}

static void test_3_7()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 2, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.23e+", sink);
}

static void test_3_8()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 3, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(10u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1.235e+", sink);
}

static void test_3_9()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 4, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.2346e+", sink);
}

static void test_3_10()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 5, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.23457e+", sink);
}

static void test_3_11()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 10, 6, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.234567e+", sink);
}

static void test_3_12()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, 5, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1.23457e+", sink);
}

static void test_3_13()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 0, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1e+4", strip_leading_zeroes(sink));
}

static void test_3_14()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 20, 0, 'e'));

    XTESTS_TEST_INTEGER_EQUAL(20u, sink.size());
    XTESTS_TEST_STRING_CONTAIN("1e+", sink);
}

static void test_3_15()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 15, 15, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

#if defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000e+4", strip_leading_zeroes(sink));

#elif defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000e+4", strip_leading_zeroes(sink));

#else

#endif /* compiler */
}

static void test_3_16()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 31, 31, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

#if defined(STLSOFT_COMPILER_IS_BORLAND)

    XTESTS_TEST_STRING_EQUAL_N("1.2345670000000000000000000000000e+4", strip_leading_zeroes(sink), stlsoft::minimum(6 + CORRECT_DEC_PLACES, (int)sink.length()));

#elif defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.2345670000000000000000000000000e+4", strip_leading_zeroes(sink));

#else

#endif /* compiler */
}

static void test_3_17()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 63, 63, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000000000000000000000000000000000000000000000000000e+4", strip_leading_zeroes(sink));

# endif /* compiler */
#endif /* compiler */
}

static void test_3_18()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 127, 127, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.2345670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+4", strip_leading_zeroes(sink));

# endif /* compiler */
#endif /* compiler */
}

static void test_3_19()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 255, 255, 'e'));

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

# if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.234567000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+4", strip_leading_zeroes(sink));

# endif /* compiler */
# endif /* compiler */
}

static void test_3_20()
{
#if !defined(STLSOFT_COMPILER_IS_GCC) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS) && \
    !defined(STLSOFT_COMPILER_IS_CLANG)

    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(12345.67, 511, 511, 'e'));

# if !defined(STLSOFT_COMPILER_IS_MSVC) || \
     _MSC_VER < 1400

    XTESTS_TEST_FLOATINGPOINT_EQUAL(12345.67, str_to_double(sink.c_str()));

#  if defined(STLSOFT_COMPILER_IS_MSVC)

    XTESTS_TEST_STRING_EQUAL("1.2345670000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e+4", strip_leading_zeroes(sink));

#  endif /* compiler */
# endif /* compiler */
#endif /* compiler */
}

static void test_3_28()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(1e-10, 0, -1, 'e'));

    XTESTS_TEST_STRING_CONTAIN("1e-10", strip_leading_zeroes(sink));
}

static void test_3_29()
{
    std::basic_string<ff_char_t> sink;

    ff::fmt(sink, FF_STR("{0}"), ff::real(1e-10, 0, -1, 'E'));

    XTESTS_TEST_STRING_CONTAIN("1E-10", strip_leading_zeroes(sink));
}


} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

