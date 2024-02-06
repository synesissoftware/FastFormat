/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.inserters.integer.cpp
 *
 * Purpose:     Implementation file for the test.unit.inserters.integer project.
 *
 * Created:     11th December 2010
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#define FASTFORMAT_SHIMS_CONVERSION_FILTER_TYPE_FAST_INTEGERS_DEFINE_c_str_ptr_SHIMS

#include <fastformat/shims/conversion/filter_type/fast_integers.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/util/limit_traits.h>

/* Standard C++ Header Files */
#include <numeric>
#include <string>

#   include <typeinfo>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL_(x, a)    XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
# define std_string                         std::wstring
# define XTESTS_TEST_FIIS_EXPR_t2s(x)       stlsoft::w2a(x).c_str()
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL_          XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define std_string                         std::string
# define XTESTS_TEST_FIIS_EXPR_t2s(x)       x
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING




#define XTESTS_TEST_FIIS_EXPR(expected, actual) \
                                                \
    (std::string("XTESTS_TEST_FIIS_EQUAL(\"") + XTESTS_TEST_FIIS_EXPR_t2s(expected) + "\", " + #actual + ")").c_str()

#define XTESTS_TEST_FIIS_EQUAL_(expected, actual)                                       \
                                                                                        \
    (!XTESTS_NS_C_QUAL(xTests_hasRequiredConditionFailed()) &&                          \
    xTests_testIntegerShim(                                                             \
        __FILE__                                                                        \
    ,   __LINE__                                                                        \
    ,   XTESTS_GET_FUNCTION_()                                                          \
    ,   XTESTS_TEST_FIIS_EXPR(expected, actual)                                         \
    ,   (expected)                                                                      \
    ,   fastformat::filters::filter_type((actual), NULL, static_cast<ff_char_t*>(0))    \
    ,   XTESTS_NS_C_QUAL(xtestsComparisonEqual)                                         \
    ))


#define XTESTS_TEST_FIIS_EQUAL(expected, actual)    XTESTS_TEST_FIIS_EQUAL_(FF_STR(expected), actual)

    
/* std::string(stlsoft::a2t"" #actual */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
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

} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.inserters.integer", verbosity))
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

    template <typename I>
    int
    xTests_testIntegerShim_(
        char const*                     file
    ,   int                             line
    ,   char const*                     function
    ,   char const*                     expr
    ,   size_t                          cchExpected
    ,   ff_char_t const*                expected
    ,   size_t                          cchActual
    ,   ff_char_t const*                actual
    ,   xtests::c::xtests_comparison_t  comp
    )
    {
        using namespace xtests;
        using namespace xtests::c;
        using namespace xtests::cpp;

        bool equal = false;

        STLSOFT_ASSERT(xtestsComparisonEqual == comp);
        STLSOFT_SUPPRESS_UNUSED(comp);

        if(cchExpected == cchActual)
        {
#ifdef FASTFORMAT_USE_WIDE_STRINGS
            if(0 == wcsncmp(expected, actual, cchExpected))
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
            if(0 == strncmp(expected, actual, cchExpected))
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
            {
                equal = true;
            }
        }

        if(equal)
        {
            stlsoft_static_cast(void, xtests_testPassed(file, line, function, expr));
        }
        else
        {
#if 0
            stlsoft_static_cast(void, xtests_failure_reporter<I>::xtests_report_failure_equal(file, line, function, expr
#else /* ? 0 */
            stlsoft_static_cast(void, xtests_testFailed(file, line, function, expr));
#endif /* 0 */
        }

        return equal;
    }

    template <typename IS>
    int
    xTests_testIntegerShim(
        char const*                     file
    ,   int                             line
    ,   char const*                     function
    ,   char const*                     expr
    ,   ff_char_t const*                expected
    ,   IS const&                       actual
    ,   xtests::c::xtests_comparison_t  comp
    )
    {
        typedef ss_typename_type_k IS::integer_type int_t;

        return xTests_testIntegerShim_<int_t>(
            file
        ,   line
        ,   function
        ,   expr
        ,   stlsoft::c_str_len(expected), stlsoft::c_str_data(expected)
        ,   stlsoft::c_str_len(actual), stlsoft::c_str_data(actual)
        ,   comp
        );
    }



static void test_1_0()
{
    XTESTS_TEST_FIIS_EQUAL( "0",  0);
    XTESTS_TEST_FIIS_EQUAL( "1",  1);
    XTESTS_TEST_FIIS_EQUAL("-1", -1);

    XTESTS_TEST_FIIS_EQUAL( "10",  10);
    XTESTS_TEST_FIIS_EQUAL("-10", -10);

    XTESTS_TEST_FIIS_EQUAL( "100",  100);
    XTESTS_TEST_FIIS_EQUAL("-100", -100);
}

static void test_1_1()
{
    typedef signed char int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));
    XTESTS_TEST_FIIS_EQUAL("-1", int_t(-1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));
    XTESTS_TEST_FIIS_EQUAL("-10", int_t(-10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));
    XTESTS_TEST_FIIS_EQUAL("-100", int_t(-100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_2()
{
    typedef unsigned short int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_3()
{
    typedef signed short int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));
    XTESTS_TEST_FIIS_EQUAL("-1", int_t(-1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));
    XTESTS_TEST_FIIS_EQUAL("-10", int_t(-10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));
    XTESTS_TEST_FIIS_EQUAL("-100", int_t(-100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_4()
{
    typedef unsigned int int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_5()
{
    typedef signed int int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));
    XTESTS_TEST_FIIS_EQUAL("-1", int_t(-1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));
    XTESTS_TEST_FIIS_EQUAL("-10", int_t(-10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));
    XTESTS_TEST_FIIS_EQUAL("-100", int_t(-100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_6()
{
    typedef unsigned long int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_7()
{
    typedef signed long int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));
    XTESTS_TEST_FIIS_EQUAL("-1", int_t(-1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));
    XTESTS_TEST_FIIS_EQUAL("-10", int_t(-10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));
    XTESTS_TEST_FIIS_EQUAL("-100", int_t(-100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_8()
{
    typedef ::stlsoft::uint32_t int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_9()
{
    typedef ::stlsoft::sint32_t int_t;

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));
    XTESTS_TEST_FIIS_EQUAL("-1", int_t(-1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));
    XTESTS_TEST_FIIS_EQUAL("-10", int_t(-10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));
    XTESTS_TEST_FIIS_EQUAL("-100", int_t(-100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_10()
{
# if defined(STLSOFT_CF_BUILTIN_long_long_SUPPORT)
    typedef unsigned long long  int_t;
# elif defined(STLSOFT_CF_64BIT_INT_SUPPORT)
    typedef ::stlsoft::uint64_t int_t;
# else /* ? 64-bit / long long */
#  error Bad discrimination
# endif /* 64-bit / long long */

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_11()
{
# if defined(STLSOFT_CF_BUILTIN_long_long_SUPPORT)
    typedef signed long long    int_t;
# elif defined(STLSOFT_CF_64BIT_INT_SUPPORT)
    typedef ::stlsoft::sint64_t int_t;
# else /* ? 64-bit / long long */
#  error Bad discrimination
# endif /* 64-bit / long long */

    XTESTS_TEST_FIIS_EQUAL( "0", int_t( 0));
    XTESTS_TEST_FIIS_EQUAL( "1", int_t( 1));
    XTESTS_TEST_FIIS_EQUAL("-1", int_t(-1));

    XTESTS_TEST_FIIS_EQUAL( "10", int_t( 10));
    XTESTS_TEST_FIIS_EQUAL("-10", int_t(-10));

    XTESTS_TEST_FIIS_EQUAL( "100", int_t( 100));
    XTESTS_TEST_FIIS_EQUAL("-100", int_t(-100));

    ff_char_t buff[21];
    ff_char_t const*    s;

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::minimum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::minimum());

    s = stlsoft::integer_to_string(&buff[0], STLSOFT_NUM_ELEMENTS(buff), stlsoft::limit_traits<int_t>::maximum());
    XTESTS_TEST_FIIS_EQUAL_(s, stlsoft::limit_traits<int_t>::maximum());
}

static void test_1_12()
{
#if 0
    { for(ff_char_t ch = 'a'; ch != 'z'; ++ch)
    {
        ff_char_t sz[2] = { ch, '\0' };

        XTESTS_TEST_STRING_EQUAL_(sz, fastformat::integer(ch));
    }}
#endif /* 0 */
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

