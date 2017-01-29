/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.shims_and_namespaces.without_fastformat_namespace.cpp
 *
 * Purpose:     Without-namespace implementation file for the test.unit.shims_and_namespaces project.
 *
 * Created:     11th November 2013
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2013-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * preprocessor feature control
 */

#define FASTFORMAT_NO_NAMESPACE

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* FastFormat header files */
#include <fastformat/fastformat.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

extern "C++"
{

    namespace without_fastformat_namespace
    {
        void test_slice_empty_and_null(void);
        void test_slice_empty_and_non_null(void);
        void test_slice_short_full_string(void);
        void test_slice_short_partial_string(void);

        void test_parse_code_1(void);
        void test_parse_code_2(void);
        void test_parse_code_3(void);
        void test_replacement_code_1(void);
        void test_replacement_code_2(void);
        void test_replacement_code_3(void);

    } /* namespace without_fastformat_namespace */

} // extern "C++"

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

extern "C++"
{

namespace without_fastformat_namespace
{

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define XTESTS_TEST_STRING_EQUAL_N(s1, s2, n)      XTESTS_TEST_WIDE_STRING_EQUAL_N(s1, s2, n)
# define XTESTS_TEST_STRING_CONTAIN_APPROX_(s1, s2) XTESTS_TEST_WIDE_STRING_CONTAIN_APPROX(FASTFORMAT_LITERAL_STRING(s1), s2)
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define XTESTS_TEST_STRING_EQUAL_N(s1, s2, n)      XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N(s1, s2, n)
# define XTESTS_TEST_STRING_CONTAIN_APPROX_(s1, s2) XTESTS_TEST_MULTIBYTE_STRING_CONTAIN_APPROX(FASTFORMAT_LITERAL_STRING(s1), s2)
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
#define FF_STR                                      FASTFORMAT_LITERAL_STRING

#ifndef FASTFORMAT_NO_NAMESPACE
    using fastformat::ff_char_t;
    using fastformat::ff_string_slice_t;

    using fastformat::ff_parse_code_t;
        using fastformat::FF_PARSECODE_SUCCESS;
        using fastformat::FF_PARSECODE_INCOMPLETEREPLACEMENT;
        using fastformat::FF_PARSECODE_INVALIDINDEX;
    using fastformat::fastformat_getParseCodeString;
    using fastformat::fastformat_getParseCodeStringLength;

    using fastformat::ff_replacement_code_t;
        using fastformat::FF_REPLACEMENTCODE_SUCCESS;
        using fastformat::FF_REPLACEMENTCODE_MISSING_ARGUMENT;
        using fastformat::FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT;
    using fastformat::fastformat_getReplacementCodeString;
    using fastformat::fastformat_getReplacementCodeStringLength;
#endif /* !FASTFORMAT_NO_NAMESPACE */


void test_slice_empty_and_null()
{
    ff_string_slice_t   slice = { 0u, NULL };

    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft_ns_qual(c_str_len)(slice));
    XTESTS_TEST_POINTER_EQUAL(NULL, stlsoft_ns_qual(c_str_data)(slice));
}

void test_slice_empty_and_non_null()
{
    ff_string_slice_t   slice = { 0u, FF_STR("abc") };

    XTESTS_TEST_INTEGER_EQUAL(0u, stlsoft_ns_qual(c_str_len)(slice));
    XTESTS_TEST_POINTER_EQUAL(slice.ptr, stlsoft_ns_qual(c_str_data)(slice));
}

void test_slice_short_full_string()
{
    ff_string_slice_t   slice = { 3u, FF_STR("abc") };

    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft_ns_qual(c_str_len)(slice));
    XTESTS_TEST_POINTER_EQUAL(slice.ptr, stlsoft_ns_qual(c_str_data)(slice));
}

void test_slice_short_partial_string()
{
    ff_string_slice_t   slice = { 3u, FF_STR("abcdef") };

    XTESTS_TEST_INTEGER_EQUAL(3u, stlsoft_ns_qual(c_str_len)(slice));
    XTESTS_TEST_POINTER_EQUAL(slice.ptr, stlsoft_ns_qual(c_str_data)(slice));
}


void test_parse_code_1()
{
    static ff_parse_code_t const    parseCodes[]    =
    {
            FF_PARSECODE_SUCCESS
        ,   FF_PARSECODE_INCOMPLETEREPLACEMENT
        ,   FF_PARSECODE_INVALIDINDEX
    };

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(parseCodes); ++i)
    {
        ff_parse_code_t const   code    =   parseCodes[i];
        ff_char_t const* const  ptr     =   fastformat_getParseCodeString(code);
        size_t const            len     =   fastformat_getParseCodeStringLength(code);

        XTESTS_TEST_INTEGER_EQUAL(len, stlsoft_ns_qual(c_str_len)(code));
        XTESTS_TEST_STRING_EQUAL_N(ptr, code, int(len));
    }}
}

void test_parse_code_2()
{
    XTESTS_TEST_STRING_CONTAIN_APPROX_("success", fastformat_getParseCodeString(FF_PARSECODE_SUCCESS));

    XTESTS_TEST_STRING_CONTAIN_APPROX_("incomplete", fastformat_getParseCodeString(FF_PARSECODE_INCOMPLETEREPLACEMENT));
    XTESTS_TEST_STRING_CONTAIN_APPROX_("replacement", fastformat_getParseCodeString(FF_PARSECODE_INCOMPLETEREPLACEMENT));

    XTESTS_TEST_STRING_CONTAIN_APPROX_("invalid", fastformat_getParseCodeString(FF_PARSECODE_INVALIDINDEX));
    XTESTS_TEST_STRING_CONTAIN_APPROX_("index", fastformat_getParseCodeString(FF_PARSECODE_INVALIDINDEX));
}

void test_parse_code_3()
{
    XTESTS_TEST_STRING_CONTAIN_APPROX_("success", FF_PARSECODE_SUCCESS);

    XTESTS_TEST_STRING_CONTAIN_APPROX_("incomplete", FF_PARSECODE_INCOMPLETEREPLACEMENT);
    XTESTS_TEST_STRING_CONTAIN_APPROX_("replacement", FF_PARSECODE_INCOMPLETEREPLACEMENT);

    XTESTS_TEST_STRING_CONTAIN_APPROX_("invalid", FF_PARSECODE_INVALIDINDEX);
    XTESTS_TEST_STRING_CONTAIN_APPROX_("index", FF_PARSECODE_INVALIDINDEX);
}

void test_replacement_code_1()
{
    static ff_replacement_code_t const    replacementCodes[]    =
    {
            FF_REPLACEMENTCODE_SUCCESS
        ,   FF_REPLACEMENTCODE_MISSING_ARGUMENT
        ,   FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT
    };

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(replacementCodes); ++i)
    {
        ff_replacement_code_t const code    =   replacementCodes[i];
        ff_char_t const* const      ptr     =   fastformat_getReplacementCodeString(code);
        size_t const                len     =   fastformat_getReplacementCodeStringLength(code);

        XTESTS_TEST_INTEGER_EQUAL(len, stlsoft_ns_qual(c_str_len)(code));
        XTESTS_TEST_STRING_EQUAL_N(ptr, code, int(len));
    }}
}

void test_replacement_code_2()
{
    XTESTS_TEST_STRING_CONTAIN_APPROX_("success", fastformat_getReplacementCodeString(FF_REPLACEMENTCODE_SUCCESS));

    XTESTS_TEST_STRING_CONTAIN_APPROX_("argument", fastformat_getReplacementCodeString(FF_REPLACEMENTCODE_MISSING_ARGUMENT));
    XTESTS_TEST_STRING_CONTAIN_APPROX_("not supplied", fastformat_getReplacementCodeString(FF_REPLACEMENTCODE_MISSING_ARGUMENT));

    XTESTS_TEST_STRING_CONTAIN_APPROX_("argument", fastformat_getReplacementCodeString(FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT));
    XTESTS_TEST_STRING_CONTAIN_APPROX_("not reference", fastformat_getReplacementCodeString(FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT));
}

void test_replacement_code_3()
{
    XTESTS_TEST_STRING_CONTAIN_APPROX_("success", FF_REPLACEMENTCODE_SUCCESS);

    XTESTS_TEST_STRING_CONTAIN_APPROX_("argument", FF_REPLACEMENTCODE_MISSING_ARGUMENT);
    XTESTS_TEST_STRING_CONTAIN_APPROX_("not supplied", FF_REPLACEMENTCODE_MISSING_ARGUMENT);

    XTESTS_TEST_STRING_CONTAIN_APPROX_("argument", FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT);
    XTESTS_TEST_STRING_CONTAIN_APPROX_("not reference", FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT);
}

} /* namespace without_fastformat_namespace */

} // extern "C++"

/* ///////////////////////////// end of file //////////////////////////// */
