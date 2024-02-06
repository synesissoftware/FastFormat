/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.bundle.util.cpp
 *
 * Purpose:     Implementation file for the test.unit.bundle.util project.
 *
 * Created:     30th November 2016
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#include <fastformat/util/bundle/windows_replacement_translation_functions.hpp>

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_WIDE_STRING_EQUAL
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define t2m        stlsoft::w2m
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define t2m(x)     x
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR(x)                           FASTFORMAT_LITERAL_STRING(x)


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{
    using fastformat::ff_char_t;

    static void calculate_number_of_windows_replacement_parameters_1();
    static void calculate_number_of_windows_replacement_parameters_2();
    static void calculate_number_of_windows_replacement_parameters_3();
    static void calculate_number_of_windows_replacement_parameters_4();
    static void calculate_number_of_windows_replacement_parameters_5();
    static void calculate_number_of_windows_replacement_parameters_6();
    static void calculate_number_of_windows_replacement_parameters_7();
    static void calculate_number_of_windows_replacement_parameters_8();
    static void calculate_number_of_windows_replacement_parameters_9();
    static void calculate_number_of_windows_replacement_parameters_10();

    static void calculate_number_of_fastformat_replacement_parameters_1();
    static void calculate_number_of_fastformat_replacement_parameters_2();
    static void calculate_number_of_fastformat_replacement_parameters_3();
    static void calculate_number_of_fastformat_replacement_parameters_4();
    static void calculate_number_of_fastformat_replacement_parameters_5();
    static void calculate_number_of_fastformat_replacement_parameters_6();
    static void calculate_number_of_fastformat_replacement_parameters_7();
    static void calculate_number_of_fastformat_replacement_parameters_8();
    static void calculate_number_of_fastformat_replacement_parameters_9();
    static void calculate_number_of_fastformat_replacement_parameters_10();

    static void change_windows_replacement_parameters_to_fastformat_1();
    static void change_windows_replacement_parameters_to_fastformat_2();
    static void change_windows_replacement_parameters_to_fastformat_3();
    static void change_windows_replacement_parameters_to_fastformat_4();
    static void change_windows_replacement_parameters_to_fastformat_5();
    static void change_windows_replacement_parameters_to_fastformat_6();
    static void change_windows_replacement_parameters_to_fastformat_7();
    static void change_windows_replacement_parameters_to_fastformat_8();
    static void change_windows_replacement_parameters_to_fastformat_9();
    static void change_windows_replacement_parameters_to_fastformat_10();

    static void escape_fastformat_replacement_parameters_1();
    static void escape_fastformat_replacement_parameters_2();
    static void escape_fastformat_replacement_parameters_3();
    static void escape_fastformat_replacement_parameters_4();
    static void escape_fastformat_replacement_parameters_5();
    static void escape_fastformat_replacement_parameters_6();
    static void escape_fastformat_replacement_parameters_7();
    static void escape_fastformat_replacement_parameters_8();
    static void escape_fastformat_replacement_parameters_9();
    static void escape_fastformat_replacement_parameters_10();

    static void test_1_1();
    static void test_1_2();
    static void test_1_3();
    static void test_1_4();
    static void test_1_5();
    static void test_1_6();
    static void test_1_7();
    static void test_1_8();

} /* anonymous namespace */


/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.bundle.util", verbosity))
    {
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_1);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_2);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_3);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_4);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_5);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_6);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_7);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_8);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_9);
        XTESTS_RUN_CASE(calculate_number_of_windows_replacement_parameters_10);

        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_1);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_2);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_3);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_4);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_5);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_6);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_7);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_8);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_9);
        XTESTS_RUN_CASE(calculate_number_of_fastformat_replacement_parameters_10);

        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_1);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_2);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_3);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_4);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_5);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_6);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_7);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_8);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_9);
        XTESTS_RUN_CASE(change_windows_replacement_parameters_to_fastformat_10);

        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_1);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_2);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_3);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_4);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_5);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_6);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_7);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_8);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_9);
        XTESTS_RUN_CASE(escape_fastformat_replacement_parameters_10);

        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* ////////////////////////////////////////////////////////////////////// */

namespace
{
    using ::fastformat::util::calculate_number_of_fastformat_replacement_parameters;
    using ::fastformat::util::calculate_number_of_windows_replacement_parameters;
    using ::fastformat::util::change_windows_replacement_parameters_to_fastformat;
    using ::fastformat::util::escape_fastformat_replacement_parameters;

    typedef std::basic_string<ff_char_t>    string_t;


static void calculate_number_of_windows_replacement_parameters_1()
{
    string_t const  input;
    size_t const    expected    =   0;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_2()
{
    string_t const  input       =   FF_STR("");
    size_t const    expected    =   0;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_3()
{
    string_t const  input       =   FF_STR("abc def ghi {0}");
    size_t const    expected    =   0;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_4()
{
    string_t const  input       =   FF_STR("%1");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_5()
{
    string_t const  input       =   FF_STR(" %1");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_6()
{
    string_t const  input       =   FF_STR("%1 ");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_7()
{
    string_t const  input       =   FF_STR("abc %1 def");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_8()
{
    string_t const  input       =   FF_STR("abc %1%2 def");
    size_t const    expected    =   2;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_9()
{
    string_t const  input       =   FF_STR("%%abc %1%2 def%3");
    size_t const    expected    =   3;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_windows_replacement_parameters_10()
{
    string_t const  input       =   FF_STR("%3%3%3abc%3%3%3 %1%2 def%");
    size_t const    expected    =   8;
    size_t const    actual      =   calculate_number_of_windows_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}


static void calculate_number_of_fastformat_replacement_parameters_1()
{
    string_t const  input;
    size_t const    expected    =   0;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_2()
{
    string_t const  input       =   FF_STR("");
    size_t const    expected    =   0;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_3()
{
    string_t const  input       =   FF_STR("abc def ghi %1");
    size_t const    expected    =   0;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_4()
{
    string_t const  input       =   FF_STR("{100}");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_5()
{
    string_t const  input       =   FF_STR(" {100}");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_6()
{
    string_t const  input       =   FF_STR("{100} ");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_7()
{
    string_t const  input       =   FF_STR("abc {0} def");
    size_t const    expected    =   1;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_8()
{
    string_t const  input       =   FF_STR("abc {0}{1} def");
    size_t const    expected    =   2;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_9()
{
    string_t const  input       =   FF_STR("}abc {0}}{1}} def}}}}}}}}}}}{3}");
    size_t const    expected    =   3;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}

static void calculate_number_of_fastformat_replacement_parameters_10()
{
    string_t const  input       =   FF_STR("{2}{2}{2}abc{2}{2}{2} {0}{1} def{");
    size_t const    expected    =   8;
    size_t const    actual      =   calculate_number_of_fastformat_replacement_parameters(input.data(), input.size());

    XTESTS_TEST_INTEGER_EQUAL(expected, actual);
}


static void change_windows_replacement_parameters_to_fastformat_1()
{
    string_t const  input;
    string_t const  expected;
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_2()
{
    string_t const  input       =   FF_STR("");
    string_t const  expected    =   FF_STR("");
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_3()
{
    string_t const  input       =   FF_STR("abc");
    string_t const  expected    =   FF_STR("abc");
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_4()
{
    string_t const  input       =   FF_STR("%1");
    string_t const  expected    =   FF_STR("{0}");
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_5()
{
    string_t const  input       =   FF_STR("%1{1}");
    string_t const  expected    =   FF_STR("{0}{1}");
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_6()
{
    string_t const  input       =   FF_STR("%1%2");
    string_t const  expected    =   FF_STR("{0}{1}");
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_7()
{
    string_t const  input       =   FF_STR("%1%%");
    string_t const  expected    =   FF_STR("{0}%");
    string_t const  actual      =   change_windows_replacement_parameters_to_fastformat(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void change_windows_replacement_parameters_to_fastformat_8()
{
}

static void change_windows_replacement_parameters_to_fastformat_9()
{
}

static void change_windows_replacement_parameters_to_fastformat_10()
{
}



static void escape_fastformat_replacement_parameters_1()
{
    string_t const  input;
    string_t const  expected;
    string_t const  actual = escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_2()
{
    string_t const  input       =   FF_STR("abc");
    string_t const  expected    =   FF_STR("abc");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_3()
{
    string_t const  input       =   FF_STR("{");
    string_t const  expected    =   FF_STR("{{");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_4()
{
    string_t const  input       =   FF_STR("{abc");
    string_t const  expected    =   FF_STR("{{abc");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_5()
{
    string_t const  input       =   FF_STR("abc{");
    string_t const  expected    =   FF_STR("abc{{");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_6()
{
    string_t const  input       =   FF_STR("}");
    string_t const  expected    =   FF_STR("}");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_7()
{
    string_t const  input       =   FF_STR("{}");
    string_t const  expected    =   FF_STR("{{}");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_8()
{
    string_t const  input       =   FF_STR("{abc}");
    string_t const  expected    =   FF_STR("{{abc}");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_9()
{
    string_t const  input       =   FF_STR("}abc{");
    string_t const  expected    =   FF_STR("}abc{{");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}

static void escape_fastformat_replacement_parameters_10()
{
    string_t const  input       =   FF_STR("abc{def}ghi}jkl{");
    string_t const  expected    =   FF_STR("abc{{def}ghi}jkl{{");
    string_t const  actual      =   escape_fastformat_replacement_parameters(input);

    XTESTS_TEST_STRING_EQUAL(expected, actual);
}


static void test_1_1()
{
}

static void test_1_2()
{
}

static void test_1_3()
{
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

} /* anonymous namespace */


/* ///////////////////////////// end of file //////////////////////////// */

