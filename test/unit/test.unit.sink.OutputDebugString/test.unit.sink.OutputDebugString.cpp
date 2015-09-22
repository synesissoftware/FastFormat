/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.sink.OutputDebugString.cpp
 *
 * Purpose:     Implementation file for the test.unit.sink.OutputDebugString project.
 *
 * Created:     28th May 2008
 * Updated:     25th April 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

 /* Mock of OutputDebugString */
#include <windows.h>
#include <memory>   // This required because DMC++'s STLport declares OutputDebugStringA (in stl/_threads.h)
void OutputDebugStringA_mock(char const* s);
void OutputDebugStringW_mock(wchar_t const* s);
int OutputDebugString_setup(void* );
#define OutputDebugStringA  OutputDebugStringA_mock
#define OutputDebugStringW  OutputDebugStringW_mock

#include <fastformat/sinks/OutputDebugString.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* Standard C++ Header Files */
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

static unsigned ods_numWrites   =   0;
static size_t ods_length        =   0;

void OutputDebugStringA_mock(char const* s)
{
    ods_numWrites   +=  1;
    ods_length      +=  strlen(s);
}

void OutputDebugStringW_mock(wchar_t const* s)
{
    ods_numWrites   +=  1;
    ods_length      +=  wcslen(s);
}

int OutputDebugString_setup(void* )
{
    ods_numWrites   =   0;
    ods_length      =   0;

    return 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.unit.sink.OutputDebugString", verbosity, OutputDebugString_setup, NULL, NULL))
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
 * Test function implementations
 */

namespace
{
    using   fastformat::ff_char_t;
    using   fastformat::fastformat_accumulateSliceLengths;

    typedef std::basic_string<ff_char_t>    string_t;


static void test_1_0()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   0,  NULL    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(0u, ods_length);
}

static void test_1_1()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   1,  FF_STR("a") },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(1u, ods_length);
}

static void test_1_2()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(STLSOFT_NUM_ELEMENTS(slices), ods_length);
}

static void test_1_3()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   26, FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(26u, ods_length);
}

static void test_1_4()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")        },
        {   25, FF_STR("abcdefghijklmnopqrstuvwxyz") + 1    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(26u, ods_length);
}

static void test_1_5()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")        },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 1    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 2    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 3    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 4    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 5    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 6    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 7    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 8    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 9    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 10   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 11   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 12   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 13   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 14   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 15   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 16   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 17   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 18   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 19   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 20   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 21   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 22   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 23   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 24   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 25   },
        {   0,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 26   },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(26u, ods_length);
}

static void test_1_6()
{
    fastformat::sinks::OutputDebugString_sink   sink;
    const fastformat::string_slice_t            slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")        },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 1    },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 2    },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 3    },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 4    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 5    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 6    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 7    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 8    },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 9    },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 10   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 11   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 12   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 13   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 14   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 15   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 16   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 17   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 18   },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 19   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 20   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 21   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 22   },
        {   0,  NULL                                },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 23   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 24   },
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 25   },
        {   0,  FF_STR("abcdefghijklmnopqrstuvwxyz") + 26   },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   0,  NULL                                },
        {   0,  NULL                                },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, ods_numWrites);
    XTESTS_TEST_INTEGER_EQUAL(26u, ods_length);
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


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
