/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.parse_format.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.parse_format project.
 *
 * Created:     27th May 2008
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <fastformat/fastformat.h>
#include <fastformat/internal/format_element.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <platformstl/platformstl.h>

/* Standard C++ header files */
#include <string>
#include <vector>

/* Standard C header files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL(x, a)     XTESTS_TEST_WIDE_STRING_EQUAL(x, a)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define t2m        stlsoft::w2m
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define t2m(x)     x
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#define FF_STR                              FASTFORMAT_LITERAL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_good_0(void);
    static void test_good_1(void);
    static void test_good_2(void);
    static void test_good_3(void);
    static void test_good_4(void);
    static void test_good_5(void);
    static void test_good_6(void);
    static void test_good_7(void);
    static void test_good_8(void);
    static void test_good_9(void);
    static void test_good_10(void);
    static void test_good_11(void);

    static void test_good_with_qualifiers_0(void);
    static void test_good_with_qualifiers_1(void);
    static void test_good_with_qualifiers_2(void);
    static void test_good_with_qualifiers_3(void);
    static void test_good_with_qualifiers_4(void);
    static void test_good_with_qualifiers_5(void);
    static void test_good_with_qualifiers_6(void);
    static void test_good_with_qualifiers_7(void);
    static void test_good_with_qualifiers_8(void);
    static void test_good_with_qualifiers_9(void);
    static void test_good_with_qualifiers_10(void);
    static void test_good_with_qualifiers_11(void);
    static void test_good_with_qualifiers_12(void);
    static void test_good_with_qualifiers_13(void);
    static void test_good_with_qualifiers_14(void);
    static void test_good_with_qualifiers_15(void);
    static void test_good_with_qualifiers_16(void);
    static void test_good_with_qualifiers_17(void);
    static void test_good_with_qualifiers_18(void);
    static void test_good_with_qualifiers_19(void);

    static void test_illformed_cancelling_0(void);
    static void test_illformed_cancelling_1(void);
    static void test_illformed_cancelling_2(void);
    static void test_illformed_cancelling_3(void);
    static void test_illformed_cancelling_4(void);
    static void test_illformed_cancelling_5(void);
    static void test_illformed_cancelling_6(void);
    static void test_illformed_cancelling_7(void);
    static void test_illformed_cancelling_8(void);
    static void test_illformed_cancelling_9(void);

    static void test_illformed_continuing_0(void);
    static void test_illformed_continuing_1(void);
    static void test_illformed_continuing_2(void);
    static void test_illformed_continuing_3(void);
    static void test_illformed_continuing_4(void);
    static void test_illformed_continuing_5(void);
    static void test_illformed_continuing_6(void);
    static void test_illformed_continuing_7(void);
    static void test_illformed_continuing_8(void);
    static void test_illformed_continuing_9(void);

    static void test_illformed_continue_once_0(void);
    static void test_illformed_continue_once_1(void);
    static void test_illformed_continue_once_2(void);
    static void test_illformed_continue_once_3(void);
    static void test_illformed_continue_once_4(void);
    static void test_illformed_continue_once_5(void);
    static void test_illformed_continue_once_6(void);
    static void test_illformed_continue_once_7(void);
    static void test_illformed_continue_once_8(void);
    static void test_illformed_continue_once_9(void);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.api.parse_format", verbosity))
    {
        XTESTS_RUN_CASE(test_good_0);
        XTESTS_RUN_CASE(test_good_1);
        XTESTS_RUN_CASE(test_good_2);
        XTESTS_RUN_CASE(test_good_3);
        XTESTS_RUN_CASE(test_good_4);
        XTESTS_RUN_CASE(test_good_5);
        XTESTS_RUN_CASE(test_good_6);
        XTESTS_RUN_CASE(test_good_7);
        XTESTS_RUN_CASE(test_good_8);
        XTESTS_RUN_CASE(test_good_9);
        XTESTS_RUN_CASE(test_good_10);
        XTESTS_RUN_CASE(test_good_11);

        XTESTS_RUN_CASE(test_good_with_qualifiers_0);
        XTESTS_RUN_CASE(test_good_with_qualifiers_1);
        XTESTS_RUN_CASE(test_good_with_qualifiers_2);
        XTESTS_RUN_CASE(test_good_with_qualifiers_3);
        XTESTS_RUN_CASE(test_good_with_qualifiers_4);
        XTESTS_RUN_CASE(test_good_with_qualifiers_5);
        XTESTS_RUN_CASE(test_good_with_qualifiers_6);
        XTESTS_RUN_CASE(test_good_with_qualifiers_7);
        XTESTS_RUN_CASE(test_good_with_qualifiers_8);
        XTESTS_RUN_CASE(test_good_with_qualifiers_9);
        XTESTS_RUN_CASE(test_good_with_qualifiers_10);
        XTESTS_RUN_CASE(test_good_with_qualifiers_11);
        XTESTS_RUN_CASE(test_good_with_qualifiers_12);
        XTESTS_RUN_CASE(test_good_with_qualifiers_13);
        XTESTS_RUN_CASE(test_good_with_qualifiers_14);
        XTESTS_RUN_CASE(test_good_with_qualifiers_15);
        XTESTS_RUN_CASE(test_good_with_qualifiers_16);
        XTESTS_RUN_CASE(test_good_with_qualifiers_17);
        XTESTS_RUN_CASE(test_good_with_qualifiers_18);
        XTESTS_RUN_CASE(test_good_with_qualifiers_19);

#if 1
        XTESTS_RUN_CASE(test_illformed_cancelling_0);
        XTESTS_RUN_CASE(test_illformed_cancelling_1);
        XTESTS_RUN_CASE(test_illformed_cancelling_2);
        XTESTS_RUN_CASE(test_illformed_cancelling_3);
        XTESTS_RUN_CASE(test_illformed_cancelling_4);
        XTESTS_RUN_CASE(test_illformed_cancelling_5);
        XTESTS_RUN_CASE(test_illformed_cancelling_6);
        XTESTS_RUN_CASE(test_illformed_cancelling_7);
        XTESTS_RUN_CASE(test_illformed_cancelling_8);
        XTESTS_RUN_CASE(test_illformed_cancelling_9);

        XTESTS_RUN_CASE(test_illformed_continuing_0);
        XTESTS_RUN_CASE(test_illformed_continuing_1);
        XTESTS_RUN_CASE(test_illformed_continuing_2);
        XTESTS_RUN_CASE(test_illformed_continuing_3);
        XTESTS_RUN_CASE(test_illformed_continuing_4);
        XTESTS_RUN_CASE(test_illformed_continuing_5);
        XTESTS_RUN_CASE(test_illformed_continuing_6);
        XTESTS_RUN_CASE(test_illformed_continuing_7);
        XTESTS_RUN_CASE(test_illformed_continuing_8);
        XTESTS_RUN_CASE(test_illformed_continuing_9);

        XTESTS_RUN_CASE(test_illformed_continue_once_0);
        XTESTS_RUN_CASE(test_illformed_continue_once_1);
        XTESTS_RUN_CASE(test_illformed_continue_once_2);
        XTESTS_RUN_CASE(test_illformed_continue_once_3);
        XTESTS_RUN_CASE(test_illformed_continue_once_4);
        XTESTS_RUN_CASE(test_illformed_continue_once_5);
        XTESTS_RUN_CASE(test_illformed_continue_once_6);
        XTESTS_RUN_CASE(test_illformed_continue_once_7);
        XTESTS_RUN_CASE(test_illformed_continue_once_8);
        XTESTS_RUN_CASE(test_illformed_continue_once_9);
#endif /* 0 */

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
    typedef std::vector<string_t>           strings_t;

    using fastformat::ff_char_t;
    using fastformat::ff_parse_code_t;
    using fastformat::fastformat_parseFormat;
    using fastformat::FASTFORMAT_ALIGNMENT_NONE;
    using fastformat::FASTFORMAT_ALIGNMENT_LEFT;
    using fastformat::FASTFORMAT_ALIGNMENT_CENTRE;
    using fastformat::FASTFORMAT_ALIGNMENT_RIGHT;

    struct parse_error_t
    {
        string_t    format;
        size_t      replacementIndex;
        string_t    defect;
        int         parameterIndex;
    };

    // NOTE: we must use error handlers here, otherwise we'll have to
    // initialise the FF core (in which case this would not be a unit-test)


    // This parse error handler reports the error and cancels processing.
    int FASTFORMAT_CALLCONV reporting_illformed_handler(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    format
    ,   size_t              formatLen
    ,   size_t              /* replacementIndex */
    ,   ff_char_t const*    /* defect */
    ,   size_t              /* defectLen */
    ,   int                 parameterIndex
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        ff_char_t   num[21];
        string_t    details;

        details += FF_STR("format: ");
        details.append(format, formatLen);
        details += FF_STR("; index: ");
        details += stlsoft::integer_to_string(&num[0], STLSOFT_NUM_ELEMENTS(num), parameterIndex);

        XTESTS_TEST_FAIL_WITH_QUALIFIER("parsing error", t2m(details));

        return 0; // Cancel processing
    }

    // Mock used to test the parse errors
    int FASTFORMAT_CALLCONV cancelling_mock_illformed_handler(
        void*               param
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    format
    ,   size_t              formatLen
    ,   size_t              replacementIndex
    ,   ff_char_t const*    defect
    ,   size_t              defectLen
    ,   int                 parameterIndex
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        if(NULL == param)
        {
            XTESTS_TEST_FAIL("NULL param passed to handler");

            return 0; // Cancel processing
        }
        else
        {
            parse_error_t&  pe = *static_cast<parse_error_t*>(param);

            pe.format.assign(format, formatLen);
            pe.replacementIndex = replacementIndex;
            pe.defect.assign(defect, defectLen);
            pe.parameterIndex = parameterIndex;

            return 0; // Cancel processing
        }
    }

    // Mock used to test the parse errors
    int FASTFORMAT_CALLCONV continuing_mock_illformed_handler(
        void*               param
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    format
    ,   size_t              formatLen
    ,   size_t              replacementIndex
    ,   ff_char_t const*    defect
    ,   size_t              defectLen
    ,   int                 parameterIndex
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        if(NULL == param)
        {
            XTESTS_TEST_FAIL("NULL param passed to handler");

            return 0; // Cancel processing
        }
        else
        {
            parse_error_t&  pe = *static_cast<parse_error_t*>(param);

            pe.format.assign(format, formatLen);
            pe.replacementIndex = replacementIndex;
            pe.defect.assign(defect, defectLen);
            pe.parameterIndex = parameterIndex;

            return +1; // Continue processing, and don't invoke this again
        }
    }

    // Mock used to test the parse errors
    int FASTFORMAT_CALLCONV continue_once_mock_illformed_handler(
        void*               param
    ,   ff_parse_code_t     /* code */
    ,   ff_char_t const*    format
    ,   size_t              formatLen
    ,   size_t              replacementIndex
    ,   ff_char_t const*    defect
    ,   size_t              defectLen
    ,   int                 parameterIndex
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    )
    {
        if(NULL == param)
        {
            XTESTS_TEST_FAIL("NULL param passed to handler");

            return 0; // Cancel processing
        }
        else
        {
            parse_error_t&  pe = *static_cast<parse_error_t*>(param);

            pe.format.assign(format, formatLen);
            pe.replacementIndex = replacementIndex;
            pe.defect.assign(defect, defectLen);
            pe.parameterIndex = parameterIndex;

            return -1; // Continue processing, and don't invoke this again
        }
    }


static void test_good_0()
{
    const ff_char_t                 fmt[] = FF_STR("");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(0u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(0u, numResultElements);
}

static void test_good_1()
{
    const ff_char_t                 fmt[] = FF_STR("a");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
}

static void test_good_2()
{
    const ff_char_t                 fmt[] = FF_STR("abcdefghijklmnopqrstuvwxyz");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(26u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
}

static void test_good_3()
{
    const ff_char_t                 fmt[] = FF_STR("{0}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[1].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[1].maxWidth));
}

static void test_good_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[1].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[1].maxWidth));
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2].index);
}

static void test_good_6()
{
    const ff_char_t                 fmt[] = FF_STR("{0}a{0}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[2].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[2].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[2].maxWidth));
}

static void test_good_7()
{
    const ff_char_t                 fmt[] = FF_STR("{0}a{0}b{0}c{0}d{0}e{0}f{0}g{0}h{0}i{0}j{0}k{0}l{0}m{0}n{0}o{0}p{0}q{0}r{0}s{0}t{0}u{0}v{0}w{0}x{0}y{0}z{0}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(53u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(53u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
    { for(size_t i = 0; i != 26; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(1u,  replacements[2 * i + 1].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2 * i + 1].index);
        XTESTS_TEST_INTEGER_EQUAL(3u, replacements[2 * i + 2].len);
        XTESTS_TEST_INTEGER_EQUAL(0,  replacements[2 * i + 2].index);
        XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[2 * i + 2].minWidth));
        XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[2 * i + 2].maxWidth));
    }}
}

static void test_good_8()
{
    const ff_char_t                 fmt[] = FF_STR("{0}a{1}b{2}c{3}d{4}e{5}f{6}g{7}h{8}i{9}j{10}k{11}l{12}m{13}n{14}o{15}p{16}q{17}r{18}s{19}t{20}u{21}v{22}w{23}x{24}y{25}z{26}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(53u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(53u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
    { for(size_t i = 0; i != 26; ++i)
    {
        XTESTS_TEST_INTEGER_EQUAL(1u,  replacements[2 * i + 1].len);
        XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2 * i + 1].index);
        if(i >= 9)
        {
            XTESTS_TEST_INTEGER_EQUAL(4u, replacements[2 * i + 2].len);
        }
        else
        {
            XTESTS_TEST_INTEGER_EQUAL(3u, replacements[2 * i + 2].len);
        }
        XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[2 * i + 2].minWidth));
        XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[2 * i + 2].maxWidth));
        XTESTS_TEST_INTEGER_EQUAL(int(i) + 1,  replacements[2 * i + 2].index);
    }}
}

static void test_good_9()
{
    const ff_char_t                 fmt[] = FF_STR("{{55}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1,  replacements[1].index);
}

static void test_good_10()
{
    const ff_char_t                 fmt[] = FF_STR("{{{55}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(55,  replacements[1].index);
}

static void test_good_11()
{
    const ff_char_t                 fmt[] = FF_STR("{{}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1,  replacements[1].index);
}



static void test_good_with_qualifiers_0()
{
    const ff_char_t                 fmt[] = FF_STR("{0}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
}

static void test_good_with_qualifiers_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_2()
{
    const ff_char_t                 fmt[] = FF_STR("{0,,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(5u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_3()
{
    const ff_char_t                 fmt[] = FF_STR("{0,,,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(6u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_4()
{
    const ff_char_t                 fmt[] = FF_STR("{0,0}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(5u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_5()
{
    const ff_char_t                 fmt[] = FF_STR("{0,0,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(6u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_6()
{
    const ff_char_t                 fmt[] = FF_STR("{0,0,,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(7u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_7()
{
    const ff_char_t                 fmt[] = FF_STR("{0,0,0,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(8u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(0,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_8()
{
    const ff_char_t                 fmt[] = FF_STR("{0,1,2,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(8u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(1,  int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(2,  int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_9()
{
}

static void test_good_with_qualifiers_10()
{
    const ff_char_t                 fmt[] = FF_STR("{23,20}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(7u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(20, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1, int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_11()
{
    const ff_char_t                 fmt[] = FF_STR("{23,20,}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(8u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(20, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(-1, int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_12()
{
    const ff_char_t                 fmt[] = FF_STR("{23,,10}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(8u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(0, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_13()
{
    const ff_char_t                 fmt[] = FF_STR("{23,10,20}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(10u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(20, int(replacements[0].maxWidth));
}

static void test_good_with_qualifiers_14()
{
    const ff_char_t                 fmt[] = FF_STR("{23,10,10}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(10u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].maxWidth));
    XTESTS_TEST_ENUM_EQUAL(FASTFORMAT_ALIGNMENT_NONE, replacements[0].alignment);
    XTESTS_TEST_INTEGER_EQUAL(int(' '), replacements[0].fill);
}

static void test_good_with_qualifiers_15()
{
    const ff_char_t                 fmt[] = FF_STR("{23,10,10,>}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(12u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].maxWidth));
    XTESTS_TEST_ENUM_EQUAL(FASTFORMAT_ALIGNMENT_RIGHT, replacements[0].alignment);
    XTESTS_TEST_INTEGER_EQUAL(int(' '), replacements[0].fill);
}

static void test_good_with_qualifiers_16()
{
    const ff_char_t                 fmt[] = FF_STR("{23,10,10,<}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(12u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].maxWidth));
    XTESTS_TEST_ENUM_EQUAL(FASTFORMAT_ALIGNMENT_LEFT, replacements[0].alignment);
    XTESTS_TEST_INTEGER_EQUAL(int(' '), replacements[0].fill);
}

static void test_good_with_qualifiers_17()
{
    const ff_char_t                 fmt[] = FF_STR("{23,10,10,^}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(12u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].maxWidth));
    XTESTS_TEST_ENUM_EQUAL(FASTFORMAT_ALIGNMENT_CENTRE, replacements[0].alignment);
    XTESTS_TEST_INTEGER_EQUAL(int(' '), replacements[0].fill);
}

static void test_good_with_qualifiers_18()
{
    const ff_char_t                 fmt[] = FF_STR("{23,10,10,>#}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), reporting_illformed_handler, NULL);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(13u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(23, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].minWidth));
    XTESTS_TEST_INTEGER_EQUAL(10, int(replacements[0].maxWidth));
    XTESTS_TEST_ENUM_EQUAL(FASTFORMAT_ALIGNMENT_RIGHT, replacements[0].alignment);
    XTESTS_TEST_INTEGER_EQUAL(int('#'), replacements[0].fill);
}

static void test_good_with_qualifiers_19()
{
}



static void test_illformed_cancelling_0()
{
    const ff_char_t                 fmt[] = FF_STR("{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), cancelling_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(0u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(0u, numResultElements);

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(0u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_cancelling_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), cancelling_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(0u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(0u, numResultElements);

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(0u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_cancelling_2()
{
    const ff_char_t                 fmt[] = FF_STR("a{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), cancelling_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);


    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_cancelling_3()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), cancelling_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_cancelling_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), cancelling_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0, replacements[1].index);

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(2u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_cancelling_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), cancelling_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0, replacements[1].index);

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(2u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_cancelling_6()
{
}

static void test_illformed_cancelling_7()
{
}

static void test_illformed_cancelling_8()
{
}

static void test_illformed_cancelling_9()
{
}


static void test_illformed_continuing_0()
{
    const ff_char_t                 fmt[] = FF_STR("{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(0u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(0u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_2()
{
    const ff_char_t                 fmt[] = FF_STR("a{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(2u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), string_t(replacements[1].ptr, replacements[1].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_3()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), string_t(replacements[1].ptr, replacements[1].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), string_t(replacements[2].ptr, replacements[2].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(2u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(2u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("b{"), string_t(replacements[2].ptr, replacements[2].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(2u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_6()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(55, replacements[2].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), string_t(replacements[1].ptr, replacements[1].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_7()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}{bb}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continuing_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(4u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(4u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(55, replacements[2].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[3].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[3].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), string_t(replacements[1].ptr, replacements[1].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{bb}"), string_t(replacements[3].ptr, replacements[3].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(3u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{bb}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continuing_8()
{
}

static void test_illformed_continuing_9()
{
}


static void test_illformed_continue_once_0()
{
    const ff_char_t                 fmt[] = FF_STR("{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(0u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(0u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_2()
{
    const ff_char_t                 fmt[] = FF_STR("a{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(2u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), string_t(replacements[1].ptr, replacements[1].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_3()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(2u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(2u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), string_t(replacements[1].ptr, replacements[1].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0,  replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), string_t(replacements[2].ptr, replacements[2].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(2u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(0, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(2u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[2].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("b{"), string_t(replacements[2].ptr, replacements[2].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(2u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_6()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(3u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(3u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(55, replacements[2].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), string_t(replacements[1].ptr, replacements[1].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_7()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}{bb}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_once_mock_illformed_handler, &pe);

    numFormatElements = n & 0xffff;
    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(4u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(4u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, replacements[0].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_INTEGER_EQUAL(3u, replacements[1].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[1].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[2].len);
    XTESTS_TEST_INTEGER_EQUAL(55, replacements[2].index);
    XTESTS_TEST_INTEGER_EQUAL(4u, replacements[3].len);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[3].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("a"), string_t(replacements[0].ptr, replacements[0].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), string_t(replacements[1].ptr, replacements[1].len));
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{bb}"), string_t(replacements[3].ptr, replacements[3].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_INTEGER_EQUAL(1u, pe.replacementIndex);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
    XTESTS_TEST_INTEGER_EQUAL(-1, pe.parameterIndex);
}

static void test_illformed_continue_once_8()
{
}

static void test_illformed_continue_once_9()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
