/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.parse_format.cpp
 *
 * Purpose:     Implementation file for the test.unit.api.parse_format project.
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

#include <fastformat/fastformat.h>
#include <fastformat/internal/format_element.h>
#include <fastformat/exceptions.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/conversion/char_conversions.hpp>
#include <stlsoft/conversion/integer_to_string.hpp>
#include <platformstl/platformstl.h>

/* Standard C++ Header Files */
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////////
 * macros and definitions
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
 * forward declarations
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

    static void test_illformed_defaulting_to_next_0(void);
    static void test_illformed_defaulting_to_next_1(void);
    static void test_illformed_defaulting_to_next_2(void);
    static void test_illformed_defaulting_to_next_3(void);
    static void test_illformed_defaulting_to_next_4(void);
    static void test_illformed_defaulting_to_next_5(void);
    static void test_illformed_defaulting_to_next_6(void);
    static void test_illformed_defaulting_to_next_7(void);
    static void test_illformed_defaulting_to_next_8(void);
    static void test_illformed_defaulting_to_next_9(void);

    static void test_illformed_continue_with_blank_0(void);
    static void test_illformed_continue_with_blank_1(void);
    static void test_illformed_continue_with_blank_2(void);
    static void test_illformed_continue_with_blank_3(void);
    static void test_illformed_continue_with_blank_4(void);
    static void test_illformed_continue_with_blank_5(void);
    static void test_illformed_continue_with_blank_6(void);
    static void test_illformed_continue_with_blank_7(void);
    static void test_illformed_continue_with_blank_8(void);
    static void test_illformed_continue_with_blank_9(void);

    static void test_illformed_continue_with_format_as_literal_0(void);
    static void test_illformed_continue_with_format_as_literal_1(void);
    static void test_illformed_continue_with_format_as_literal_2(void);
    static void test_illformed_continue_with_format_as_literal_3(void);
    static void test_illformed_continue_with_format_as_literal_4(void);
    static void test_illformed_continue_with_format_as_literal_5(void);
    static void test_illformed_continue_with_format_as_literal_6(void);
    static void test_illformed_continue_with_format_as_literal_7(void);
    static void test_illformed_continue_with_format_as_literal_8(void);
    static void test_illformed_continue_with_format_as_literal_9(void);

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

int ff_setup(void*);
int ff_teardown(void*);

int ff_setup(void*)
{
    return fastformat::fastformat_init();
}

int ff_teardown(void*)
{
    fastformat::fastformat_uninit();

    return 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if( XTESTS_START_RUNNER_WITH_REPORTER_AND_STREAM_AND_FLAGS_AND_SETUP_FNS(
            "test.unit.api.parse_format"
        ,   verbosity
        ,   NULL, NULL
        ,   NULL
        ,   xtests::c::xtestsReportOnlyNonEmptyCases
        ,   ff_setup, ff_teardown, NULL
        )
    )
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

        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_0, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_1, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_2, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_3, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_4, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_5, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_6, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_7, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_8, fastformat::illformed_format_exception);
        XTESTS_RUN_CASE_THAT_THROWS(test_illformed_defaulting_to_next_9, fastformat::illformed_format_exception);

        XTESTS_RUN_CASE(test_illformed_continue_with_blank_0);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_1);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_2);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_3);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_4);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_5);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_6);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_7);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_8);
        XTESTS_RUN_CASE(test_illformed_continue_with_blank_9);

        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_0);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_1);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_2);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_3);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_4);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_5);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_6);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_7);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_8);
        XTESTS_RUN_CASE(test_illformed_continue_with_format_as_literal_9);

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
    typedef std::vector<string_t>           strings_t;

    using fastformat::ff_char_t;
    using fastformat::ff_handler_response_t;
        using fastformat::FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
        using fastformat::FF_HANDLERRESPONSE_NEXT_HANDLER;
    using fastformat::ff_parse_action_t;
        using fastformat::FF_PARSEACTION_REPLACE_FORMAT_WITH_BLANK;
        using fastformat::FF_PARSEACTION_TREAT_FORMAT_AS_LITERAL;
    using fastformat::ff_parse_code_t;
    using fastformat::ff_string_slice_t;
    using fastformat::fastformat_parseFormat;
    using fastformat::FASTFORMAT_ALIGNMENT_NONE;
    using fastformat::FASTFORMAT_ALIGNMENT_LEFT;
    using fastformat::FASTFORMAT_ALIGNMENT_CENTRE;
    using fastformat::FASTFORMAT_ALIGNMENT_RIGHT;

    struct parse_error_t
    {
        string_t    format;
        string_t    defect;
    };

    // NOTE: we must use error handlers here, otherwise we'll have to
    // initialise the FF core (in which case this would not be a unit-test)


    // This parse error handler reports the error and cancels processing.
    ff_handler_response_t
    FASTFORMAT_CALLCONV test_failing_if_called_illformed_handler(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   /* defect */
    ,   ff_parse_action_t*  /* illformedAction */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    ,   int                 /* reserved3 */
    )
    {
        string_t details;

        details += FF_STR("format: ");
        details.append(format.ptr, format.len);

        XTESTS_TEST_FAIL_WITH_QUALIFIER("parsing error", t2m(details));

        // Cancel processing
        return FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

    // Mock used to test the parse errors
    ff_handler_response_t
    FASTFORMAT_CALLCONV defaulting_to_next_illformed_handler(
        void*               /* param */
    ,   ff_parse_code_t     /* code */
    ,   ff_string_slice_t   /* format */
    ,   ff_string_slice_t   /* defect */
    ,   ff_parse_action_t*  /* illformedAction */
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    ,   int                 /* reserved3 */
    )
    {
        return FF_HANDLERRESPONSE_NEXT_HANDLER;
    }

    // Mock used to test the parse errors
    ff_handler_response_t
    FASTFORMAT_CALLCONV continue_with_blank_illformed_handler(
        void*               param
    ,   ff_parse_code_t     /* code */
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   defect
    ,   ff_parse_action_t*  illformedAction
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    ,   int                 /* reserved3 */
    )
    {
        if(NULL == param)
        {
            XTESTS_TEST_FAIL("NULL param passed to handler");

            // Cancel processing
            return FF_HANDLERRESPONSE_NEXT_HANDLER;
        }
        else
        {
            parse_error_t& pe = *static_cast<parse_error_t*>(param);

            pe.format.assign(format.ptr, format.len);
            pe.defect.assign(defect.ptr, defect.len);

            *illformedAction = FF_PARSEACTION_REPLACE_FORMAT_WITH_BLANK;

            // Continue processing, and don't invoke this again
            return FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
        }
    }

    // Mock used to test the parse errors
    ff_handler_response_t
    FASTFORMAT_CALLCONV continue_with_format_as_literal_illformed_handler(
        void*               param
    ,   ff_parse_code_t     /* code */
    ,   ff_string_slice_t   format
    ,   ff_string_slice_t   defect
    ,   ff_parse_action_t*  illformedAction
    ,   void*               /* reserved0 */
    ,   size_t              /* reserved1 */
    ,   void*               /* reserved2 */
    ,   int                 /* reserved3 */
    )
    {
        if(NULL == param)
        {
            XTESTS_TEST_FAIL("NULL param passed to handler");

            // Cancel processing
            return FF_HANDLERRESPONSE_NEXT_HANDLER;
        }
        else
        {
            parse_error_t& pe = *static_cast<parse_error_t*>(param);

            pe.format.assign(format.ptr, format.len);
            pe.defect.assign(defect.ptr, defect.len);

            *illformedAction = FF_PARSEACTION_TREAT_FORMAT_AS_LITERAL;

            // Continue processing, and don't invoke this again
            return FF_HANDLERRESPONSE_CONTINUE_PROCESSING;
        }
    }


static void test_good_0()
{
    const ff_char_t                 fmt[] = FF_STR("");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    size_t                          numFormatElements;
    size_t                          numResultElements;

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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

    unsigned n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), test_failing_if_called_illformed_handler, NULL);

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



static void test_illformed_defaulting_to_next_0()
{
    const ff_char_t                 fmt[] = FF_STR("{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];

    fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), defaulting_to_next_illformed_handler, NULL);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_illformed_defaulting_to_next_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];

    fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), defaulting_to_next_illformed_handler, NULL);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_illformed_defaulting_to_next_2()
{
    const ff_char_t                 fmt[] = FF_STR("a{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];

    fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), defaulting_to_next_illformed_handler, NULL);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_illformed_defaulting_to_next_3()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];

    fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), defaulting_to_next_illformed_handler, NULL);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_illformed_defaulting_to_next_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];

    fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), defaulting_to_next_illformed_handler, NULL);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_illformed_defaulting_to_next_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];

    fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), defaulting_to_next_illformed_handler, NULL);

    XTESTS_TEST_FAIL("should not get here");
}

static void test_illformed_defaulting_to_next_6()
{
    // Stub to satisfy test invocation
    throw fastformat::illformed_format_exception("blah", ff_parse_code_t(), FF_STR(""));
}

static void test_illformed_defaulting_to_next_7()
{
    // Stub to satisfy test invocation
    throw fastformat::illformed_format_exception("blah", ff_parse_code_t(), FF_STR(""));
}

static void test_illformed_defaulting_to_next_8()
{
    // Stub to satisfy test invocation
    throw fastformat::illformed_format_exception("blah", ff_parse_code_t(), FF_STR(""));
}

static void test_illformed_defaulting_to_next_9()
{
    // Stub to satisfy test invocation
    throw fastformat::illformed_format_exception("blah", ff_parse_code_t(), FF_STR(""));
}



static void test_illformed_continue_with_blank_0()
{
    const ff_char_t                 fmt[] = FF_STR("{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), pe.defect);
}

static void test_illformed_continue_with_blank_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), pe.defect);
}

static void test_illformed_continue_with_blank_2()
{
    const ff_char_t                 fmt[] = FF_STR("a{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), pe.defect);
}

static void test_illformed_continue_with_blank_3()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
}

static void test_illformed_continue_with_blank_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), pe.defect);
}

static void test_illformed_continue_with_blank_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("b{"), pe.defect);
}

static void test_illformed_continue_with_blank_6()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
}

static void test_illformed_continue_with_blank_7()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}{bb}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_blank_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING(""), string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
}

static void test_illformed_continue_with_blank_8()
{
}

static void test_illformed_continue_with_blank_9()
{
}



static void test_illformed_continue_with_format_as_literal_0()
{
    const ff_char_t                 fmt[] = FF_STR("{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_1()
{
    const ff_char_t                 fmt[] = FF_STR("{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_2()
{
    const ff_char_t                 fmt[] = FF_STR("a{0"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{0"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_3()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_4()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_5()
{
    const ff_char_t                 fmt[] = FF_STR("a{0}b{"); // Missing }
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("b{"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_6()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_7()
{
    const ff_char_t                 fmt[] = FF_STR("a{a}{55}{bb}");
    fastformat::format_element_t    replacements[1 + STLSOFT_NUM_ELEMENTS(fmt) / 2];
    parse_error_t                   pe;
    unsigned const                  n = fastformat_parseFormat(fmt, stlsoft::c_str_len(fmt), &replacements[0], STLSOFT_NUM_ELEMENTS(replacements), continue_with_format_as_literal_illformed_handler, &pe);
    size_t const                    numFormatElements = n & 0xffff;
    size_t const                    numResultElements = ((n >> 16) & 0xffff);

    XTESTS_TEST_INTEGER_EQUAL(1u, numFormatElements);
    XTESTS_TEST_INTEGER_EQUAL(1u, numResultElements);
    XTESTS_TEST_INTEGER_EQUAL(-1, replacements[0].index);
    XTESTS_TEST_STRING_EQUAL(fmt, string_t(replacements[0].ptr, replacements[0].len));

    XTESTS_TEST_STRING_EQUAL(fmt, pe.format);
    XTESTS_TEST_STRING_EQUAL(FASTFORMAT_LITERAL_STRING("{a}"), pe.defect);
}

static void test_illformed_continue_with_format_as_literal_8()
{
}

static void test_illformed_continue_with_format_as_literal_9()
{
}


} /* anonymous namespace */

/* ///////////////////////////// end of file //////////////////////////// */
