/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.format.standard_flags.cpp
 *
 * Purpose:     Implementation file for the test.unit.format.standard_flags project.
 *
 * Created:     27th May 2008
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
 * Test component header file include(s)
 */

#include <fastformat/format/standard_flags.hpp>
#include <fastformat/util/string/snprintf.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#if defined(STLSOFT_VER) && \
    STLSOFT_VER >= 0x010c0000
# include <stlsoft/container/frequency_map.hpp>
#else
# include <stlsoft/containers/frequency_map.hpp>
#endif

/* Standard C Header Files */
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

    if(XTESTS_START_RUNNER("test.unit.format.standard_flags", verbosity))
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

struct flag_descriptor_t
{
    char const* name;
    int         value;

#define FF_STDFLAGS_DESCRIBE(x)     { #x, x }
};

static const flag_descriptor_t flags[] =
{
    FF_STDFLAGS_DESCRIBE(fastformat::flags::ff_newLine),
    FF_STDFLAGS_DESCRIBE(fastformat::flags::ff_flush),
};


static void test_1_0()
{
    XTESTS_TEST_INTEGER_NOT_EQUAL(0, fastformat::flags::ff_newLine);
}

static void test_1_1()
{
    XTESTS_TEST_INTEGER_NOT_EQUAL(0, fastformat::flags::ff_flush);
}

static void test_1_2()
{
    typedef stlsoft::frequency_map<int> flags_map_t;

    flags_map_t frequencies;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(flags); ++i)
    {
        frequencies.push(flags[i].value);
    }}

    { for(flags_map_t::const_iterator i = frequencies.begin(); i != frequencies.end(); ++i)
    {
        flags_map_t::value_type value = *i;

        if(1 != value.second)
        {
            char msg[100];

            fastformat::fastformat_util_snprintf_a(&msg[0], STLSOFT_NUM_ELEMENTS(msg), "more than one flag has the value 0x%08x", static_cast<stlsoft::uint32_t>(value.first));

            XTESTS_TEST_FAIL(msg);
        }
    }}

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

static void test_1_9()
{
}

static void test_1_10()
{
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
