/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.sink.char_buffer.cpp
 *
 * Purpose:     Implementation file for the test.unit.sink.char_buffer project.
 *
 * Created:     28th May 2008
 * Updated:     14th October 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/sinks/char_buffer.hpp>
//#include <fastformat/shims/action/generic_string.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/iterators/member_selector_iterator.hpp>

/* Standard C++ Header Files */
#include <numeric>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Macros
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL_(x, a)    XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_STRING_EQUAL_(FASTFORMAT_LITERAL_STRING(x), a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL_(x, a)    XTESTS_TEST_MULTIBYTE_STRING_EQUAL(x, a)
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_STRING_EQUAL_
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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.sink.char_buffer", verbosity))
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

        XTESTS_RUN_CASE(test_2_0);
#if 1
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
        XTESTS_RUN_CASE_THAT_THROWS(test_2_11, std::out_of_range);
        XTESTS_RUN_CASE(test_2_12);
        XTESTS_RUN_CASE(test_2_13);
        XTESTS_RUN_CASE(test_2_14);
        XTESTS_RUN_CASE(test_2_15);
        XTESTS_RUN_CASE(test_2_16);
        XTESTS_RUN_CASE(test_2_17);
        XTESTS_RUN_CASE(test_2_18);
        XTESTS_RUN_CASE(test_2_19);
#endif

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
    using   fastformat::sinks::char_buffer_sink;
    using   fastformat::string_slice_t;
    using   fastformat::fastformat_accumulateSliceLengths;
    using   fastformat::getNewlineForPlatform;

    typedef std::basic_string<ff_char_t>    string_t;


    static const string_slice_t s_slices[] =
    {
        {   0,  NULL                                },
        {   1,  FF_STR("a")                         },
        {   2,  FF_STR("bc")                        },
        {   0,  NULL                                },
        {   7,  FF_STR("defghij")                   },
        {   7,  FF_STR("klmnopq")                   },
        {   1,  FF_STR("r")                         },
        {   13, FF_STR("stuvwxyz01234")             },
        {   0,  NULL                                },
        {   7,  FF_STR("56789AB")                   },
        {   22, FF_STR("CDEFGHIJKLMNOPQRSTUVWX")    },
        {   1,  FF_STR("Y")                         },
        {   1,  FF_STR("Z")                         },
        {   0,  NULL                                },
    };

    static const ff_char_t           s_source[] = FF_STR("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");


static void test_1_0()
{
    ff_char_t                           buff[1] = { '~' };
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   0,  NULL    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(0u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('~'), buff[0]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(0u, n);
    XTESTS_TEST_STRING_EQUAL("", result);
}

static void test_1_1()
{
    ff_char_t                           buff[1] = { '~' };
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("a") },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_STRING_EQUAL("a", result);
}

static void test_1_2()
{
    ff_char_t                           buff[1] = { '~' };
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(1u, n);
    XTESTS_TEST_STRING_EQUAL("a", result);
}

static void test_1_3()
{
    ff_char_t                           buff[26];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   26, FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u, n);
    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", result);
}

static void test_1_4()
{
    ff_char_t                           buff[26];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")        },
        {   25, FF_STR("abcdefghijklmnopqrstuvwxyz") + 1    },
    };
    const int                           flags   =   0;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u, n);
    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", result);
}

static void test_1_5()
{
    ff_char_t                           buff[26];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
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

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u, n);
    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", result);
}

static void test_1_6()
{
    ff_char_t                           buff[26];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
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

    XTESTS_TEST_INTEGER_EQUAL(26u, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u, n);
    XTESTS_TEST_STRING_EQUAL("abcdefghijklmnopqrstuvwxyz", result);
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
    // Both Borland and CodeWarrior seem to think that there's a conversion
    // from size_t to long somewhere in the invocation of accumulate. 
#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    ff_char_t    buff[1024];

    // For all buffer sizes ...
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(buff); ++i)
    {
        // For all slices ...
        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(s_slices); ++j)
        {
            const size_t cchTotal = std::accumulate(stlsoft::member_selector(s_slices, &string_slice_t::len)
                                                ,   stlsoft::member_selector(s_slices, &string_slice_t::len) + j
                                                ,   size_t(0));

            try
            {
                char_buffer_sink sink(i, buff);

                fastformat::sinks::fmt_slices(sink, 0, cchTotal, j, s_slices);

                if(cchTotal > i)
                {
                    XTESTS_TEST_FAIL("char_buff_sink() failed to detect insufficient space");
                }
                else
                {
                    XTESTS_TEST_INTEGER_EQUAL(0, ::memcmp(s_source, buff, cchTotal * sizeof(ff_char_t)));
                }
            }
            catch(std::out_of_range&)
            {
                if(cchTotal > i)
                {
                    XTESTS_TEST_PASSED();
                }
                else
                {
                    // Should not have occurred, so rethrow
                    throw;
                }
            }
        }}
    }}

#endif /* compiler */
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


static void test_2_0()
{
    ff_char_t                           buff[3] = { '~', '~', '~' };
#ifdef STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT
    char_buffer_sink                    sink(buff);
#else /* ? STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
#endif /* STLSOFT_CF_STATIC_ARRAY_SIZE_DETERMINATION_SUPPORT */
    const fastformat::string_slice_t    slices[] = 
    {
        {   0,  NULL    },
    };
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(0u + getNewlineForPlatform().len, sink.size());
    { for(size_t i = 0; i != getNewlineForPlatform().len; ++i)
    {
        XTESTS_TEST_CHARACTER_EQUAL(getNewlineForPlatform().ptr[i], buff[i]);
    }}
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('~'), buff[getNewlineForPlatform().len]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(0u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(getNewlineForPlatform().ptr, result);
}

static void test_2_1()
{
    ff_char_t                           buff[4] = { '~', '~', '~', '~' };
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("a") },
    };
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u + getNewlineForPlatform().len, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'),  buff[0]);
    { for(size_t i = 0; i != getNewlineForPlatform().len; ++i)
    {
        XTESTS_TEST_CHARACTER_EQUAL(getNewlineForPlatform().ptr[i], buff[1 + i]);
    }}
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('~'), buff[1 + getNewlineForPlatform().len]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(1u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(string_t(FASTFORMAT_LITERAL_STRING("a")) + getNewlineForPlatform().ptr, result);
}

static void test_2_2()
{
    ff_char_t                           buff[4] = { '~', '~', '~', '~' };
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(1u + getNewlineForPlatform().len, sink.size());
    { for(size_t i = 0; i != getNewlineForPlatform().len; ++i)
    {
        XTESTS_TEST_CHARACTER_EQUAL(getNewlineForPlatform().ptr[i], buff[1 + i]);
    }}
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('~'), buff[1 + getNewlineForPlatform().len]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(1u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(string_t(FASTFORMAT_LITERAL_STRING("a")) + getNewlineForPlatform().ptr, result);
}

static void test_2_3()
{
    ff_char_t                           buff[28];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   26, FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(string_t(FASTFORMAT_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")) + getNewlineForPlatform().ptr, result);
}

static void test_2_4()
{
    ff_char_t                           buff[28];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")        },
        {   25, FF_STR("abcdefghijklmnopqrstuvwxyz") + 1    },
    };
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(string_t(FASTFORMAT_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")) + getNewlineForPlatform().ptr, result);
}

static void test_2_5()
{
    ff_char_t                           buff[28];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
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
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(string_t(FASTFORMAT_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")) + getNewlineForPlatform().ptr, result);
}

static void test_2_6()
{
    ff_char_t                           buff[28];
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
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
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, sink.size());
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('a'), buff[0]);
    XTESTS_TEST_CHARACTER_EQUAL(ff_char_t('z'), buff[25]);

    string_t                            result  =   string_t(&buff[0], sink.size());
    const size_t                        n       =   result.size();

    XTESTS_TEST_INTEGER_EQUAL(26u + getNewlineForPlatform().len, n);
    XTESTS_TEST_STRING_EQUAL_(string_t(FASTFORMAT_LITERAL_STRING("abcdefghijklmnopqrstuvwxyz")) + getNewlineForPlatform().ptr, result);
}

static void test_2_7()
{
}

static void test_2_8()
{
}

static void test_2_9()
{
}

static void test_2_10()
{
    // Both Borland and CodeWarrior seem to think that there's a conversion
    // from size_t to long somewhere in the invocation of accumulate. 
#if !defined(STLSOFT_COMPILER_IS_BORLAND) && \
    !defined(STLSOFT_COMPILER_IS_MWERKS)

    ff_char_t    buff[1024];

    // For all buffer sizes ...
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(buff); ++i)
    {
        // For all slices ...
        { for(size_t j = 0; j != STLSOFT_NUM_ELEMENTS(s_slices); ++j)
        {
            const size_t cchTotal = std::accumulate(stlsoft::member_selector(s_slices, &string_slice_t::len)
                                                ,   stlsoft::member_selector(s_slices, &string_slice_t::len) + j
                                                ,   size_t(0));

            try
            {
                char_buffer_sink sink(i, buff);

                fastformat::sinks::fmt_slices(sink, 0, cchTotal, j, s_slices);

                if(cchTotal > i)
                {
                    XTESTS_TEST_FAIL("char_buff_sink() failed to detect insufficient space");
                }
                else
                {
                    XTESTS_TEST_INTEGER_EQUAL(0, ::memcmp(s_source, buff, cchTotal * sizeof(ff_char_t)));
                }
            }
            catch(std::out_of_range&)
            {
                if(cchTotal > i)
                {
                    XTESTS_TEST_PASSED();
                }
                else
                {
                    // Should not have occurred, so rethrow
                    throw;
                }
            }
        }}
    }}

#endif /* compiler */
}

static void test_2_11()
{
    ff_char_t                           buff[1] = { '~' };
    char_buffer_sink                    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
    const fastformat::string_slice_t    slices[] = 
    {
        {   1,  FF_STR("abcdefghijklmnopqrstuvwxyz")    },
    };
    const int                           flags   =   fastformat::flags::ff_newLine;
    const size_t                        len     =   fastformat_accumulateSliceLengths(STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    fastformat::sinks::fmt_slices(sink, flags, len, STLSOFT_NUM_ELEMENTS(slices), &slices[0]);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_2_12()
{
}

static void test_2_13()
{
}

static void test_2_14()
{
}

static void test_2_15()
{
}

static void test_2_16()
{
}

static void test_2_17()
{
}

static void test_2_18()
{
}

static void test_2_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
