/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.sink.ribbon.cpp
 *
 * Purpose:     Implementation file for the test.unit.sink.ribbon project.
 *
 * Created:     6th September 2014
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <fastformat/sinks/ribbon.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/util/temp_file.hpp>
#include <xtests/xtests.h>

/* FastFormat header files */
#include <fastformat/ff.hpp>

/* STLSoft header files */
#include <stlsoft/filesystem/FILE_stream.hpp>
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_types_exist(void);
    static void test_string_ribbon_1(void);
    static void test_string_ribbon_2(void);
    static void test_string_ribbon_3(void);
    static void test_string_ribbon_4(void);
    static void test_string_ribbon_5(void);
    static void test_string_ribbon_6(void);
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

    if(XTESTS_START_RUNNER("test.unit.sink.ribbon", verbosity))
    {
        XTESTS_RUN_CASE(test_types_exist);
        XTESTS_RUN_CASE(test_string_ribbon_1);
        XTESTS_RUN_CASE(test_string_ribbon_2);
        XTESTS_RUN_CASE(test_string_ribbon_3);
        XTESTS_RUN_CASE(test_string_ribbon_4);
        XTESTS_RUN_CASE(test_string_ribbon_5);
        XTESTS_RUN_CASE(test_string_ribbon_6);
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
    using ::xtests::cpp::temp_file;

    typedef fastformat::ff_char_t           char_t;
 
    typedef std::basic_string<char_t>       string_t;


static void test_types_exist()
{
    typeid(::fastformat::sinks::ribbon_string_adaptor<string_t>);

    XTESTS_TEST_PASSED();
}

static void test_string_ribbon_1()
{
    string_t s;

    ff::write(ff::ribbon(s, 10), "abc");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);
}

static void test_string_ribbon_2()
{
    string_t s;

    ff::write(ff::ribbon(s, 10), "abc");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("abc", s);

    ff::write(ff::ribbon(s, 10), "def");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("def", s);

    ff::write(ff::ribbon(s, 10), "ghi");

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("ghi", s);
}

static void test_string_ribbon_3()
{
    string_t s;

    { for(size_t i = 0; i != 10; ++i)
    {
        string_t t(i, '~');

        ff::write(ff::ribbon(s, 10), t);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(t, s);
    }}

    { for(size_t i = 10; i != 100; ++i)
    {
        string_t e(10, '~');
        string_t t(i, '~');

        ff::write(ff::ribbon(s, 10), t);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(e, s);
    }}
}

static void test_string_ribbon_4()
{
    string_t s;

    { for(size_t i = 0; i != 10; ++i)
    {
        string_t t(i, '~');

        ff::write(ff::ribbon(s, 10, ff::sinks::ribbon_truncate), t);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(t, s);
    }}

    { for(size_t i = 10; i != 100; ++i)
    {
        string_t e(10, '~');
        string_t t(i, '~');

        ff::write(ff::ribbon(s, 10, ff::sinks::ribbon_truncate), t);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(e, s);
    }}
}

static void test_string_ribbon_5()
{
    string_t s;

    { for(size_t i = 0; i != 10; ++i)
    {
        string_t t(i, '~');

        ff::write(ff::ribbon(s, 10, ff::sinks::ribbon_truncate_with_ellispsis), t);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL(t, s);
    }}

    { for(size_t i = 11; i != 100; ++i)
    {
        string_t t(i, '~');

        ff::write(ff::ribbon(s, 10, ff::sinks::ribbon_truncate_with_ellispsis), t);

        XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~~~~~~~...", s);
    }}
}

static void test_string_ribbon_6()
{
    string_t const  t(100, '~');
    string_t        s;

    ff::write(ff::ribbon(s, 0, ff::sinks::ribbon_truncate_with_ellispsis), t);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("", s);

    ff::write(ff::ribbon(s, 1, ff::sinks::ribbon_truncate_with_ellispsis), t);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", s);

    ff::write(ff::ribbon(s, 2, ff::sinks::ribbon_truncate_with_ellispsis), t);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("..", s);

    ff::write(ff::ribbon(s, 3, ff::sinks::ribbon_truncate_with_ellispsis), t);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("...", s);

    ff::write(ff::ribbon(s, 4, ff::sinks::ribbon_truncate_with_ellispsis), t);

    XTESTS_TEST_MULTIBYTE_STRING_EQUAL("~...", s);
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

static void test_1_9()
{
}

static void test_1_10()
{
    temp_file               tf(temp_file::DeleteOnClose);

}

static void test_1_11()
{
}

static void test_1_12()
{
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
