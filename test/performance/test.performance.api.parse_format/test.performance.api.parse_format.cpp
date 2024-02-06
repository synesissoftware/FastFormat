/* /////////////////////////////////////////////////////////////////////////
 * File:        test.performance.api.parse_format.cpp
 *
 * Purpose:     Implementation file for the test.performance.api.parse_format project.
 *
 * Created:     17th November 2008
 * Updated:     6th February 2024
 * *
 * ////////////////////////////////////////////////////////////////////// */

//#define FF_PRSFMT_USE_SV_PARAM


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/fastformat.hpp>
#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>

/* STLSoft Header Files */
#include <stlsoft/string/split_functions.hpp>
#include <stlsoft/string/string_view.hpp>
#include <stlsoft/string/tokeniser_functions.hpp> // for find_next_token
#include <platformstl/platformstl.hpp>
#include <platformstl/performance/performance_counter.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * constants and definitions
 */

#ifdef _DEBUG
const unsigned INCREMENTS   =   10;
#else /* ? _DEBUG */
const unsigned INCREMENTS   =   20000/* 0 */;
#endif /* _DEBUG */

#if 0
platformstl::performance_counter::interval_type (platformstl::performance_counter::*pmfn)() const = &platformstl::performance_counter::get_milliseconds;
#else /* ? 0 */
platformstl::performance_counter::interval_type (platformstl::performance_counter::*pmfn)() const = &platformstl::performance_counter::get_microseconds;
#endif /* 0 */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

typedef stlsoft::string_view    string_view_t;

enum alignment_t
{
        unspecified
    ,   left
    ,   centre
    ,   right
    ,   hashFill
};

enum
{
        foundIndex      =   0x01
    ,   foundMinWidth   =   0x02
    ,   foundMaxWidth   =   0x04
    ,   foundAlign      =   0x08
};

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

int parse_replacement_raw(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    index
,   int*                    minWidth
,   int*                    maxWidth
,   int*                    alignment
);
int parse_replacement_find_next_token(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    index
,   int*                    minWidth
,   int*                    maxWidth
,   int*                    alignment
);
int parse_replacement_string_view(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    index
,   int*                    minWidth
,   int*                    maxWidth
,   int*                    alignment
);
int parse_replacement_std_string(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    index
,   int*                    minWidth
,   int*                    maxWidth
,   int*                    alignment
);

int FASTFORMAT_CALLCONV ignore_unreferenced_params_handler(
    void*                           param
,   fastformat::replacement_code_t  code
,   size_t                          numArguments
,   int                             mismatchedParameterIndex
,   fastformat::string_slice_t*     slice
,   void*                           reserved0
,   size_t                          reserved1
,   void*                           reserved2
);

fastformat::mismatchedHandler_t prev = NULL;

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    platformstl::performance_counter                counter;
    platformstl::performance_counter::interval_type tmManual;
    platformstl::performance_counter::interval_type tmFindNextToken;
    platformstl::performance_counter::interval_type tmStringView;
    platformstl::performance_counter::interval_type tmStdString;

    char const* params[] = 
    {
            "{0}"
        ,   "{1}"
        ,   "{2}"
        ,   "{4}"
        ,   "{8}"
        ,   "{16}"
        ,   "{31}"
        ,   "{}"
        ,   "{,}"
        ,   "{2,^,20,^}"
        ,   "{2,10}"
        ,   "{2,,10}"
        ,   "{2,,20}"
        ,   "{,,20}"
        ,   "{2,10,20}"
        ,   "{2,10,,<}"
        ,   "{2,10,,>}"
        ,   "{2,10,,^}"
        ,   "{2,10,,}"
        ,   "{2,10,20,<}"
        ,   "{2,10,20,>}"
        ,   "{2,10,20,^}"
        ,   "{2,10,20,^^}"
        ,   "{2,10,20,}"
        ,   "{1,,,<}"
        ,   "{1,,,>}"
        ,   "{1,,,^}"
    };

    int totalRes1 = 0;
    int totalRes2 = 0;
    int totalRes3 = 0;
    int totalRes4 = 0;

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(params); ++i)
    {
        string_view_t   param(params[i]);

        int index1      =   -1;
        int minWidth1   =   -1;
        int maxWidth1   =   -1;
        int alignment1  =   -1;
#ifdef FF_PRSFMT_USE_SV_PARAM
        int res1        =   parse_replacement_raw(param, &index1, &minWidth1, &maxWidth1, &alignment1);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
        int res1        =   parse_replacement_raw(param.begin(), param.end(), &index1, &minWidth1, &maxWidth1, &alignment1);
#endif /* FF_PRSFMT_USE_SV_PARAM */
        int index2      =   -1;
        int minWidth2   =   -1;
        int maxWidth2   =   -1;
        int alignment2  =   -1;
#ifdef FF_PRSFMT_USE_SV_PARAM
        int res2        =   parse_replacement_find_next_token(param, &index2, &minWidth2, &maxWidth2, &alignment2);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
        int res2        =   parse_replacement_find_next_token(param.begin(), param.end(), &index2, &minWidth2, &maxWidth2, &alignment2);
#endif /* FF_PRSFMT_USE_SV_PARAM */
        int index3      =   -1;
        int minWidth3   =   -1;
        int maxWidth3   =   -1;
        int alignment3  =   -1;
#ifdef FF_PRSFMT_USE_SV_PARAM
        int res3        =   parse_replacement_string_view(param, &index3, &minWidth3, &maxWidth3, &alignment3);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
        int res3        =   parse_replacement_string_view(param.begin(), param.end(), &index3, &minWidth3, &maxWidth3, &alignment3);
#endif /* FF_PRSFMT_USE_SV_PARAM */
        int index4      =   -1;
        int minWidth4   =   -1;
        int maxWidth4   =   -1;
        int alignment4  =   -1;
#ifdef FF_PRSFMT_USE_SV_PARAM
        int res4        =   parse_replacement_std_string(param, &index4, &minWidth4, &maxWidth4, &alignment4);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
        int res4        =   parse_replacement_std_string(param.begin(), param.end(), &index4, &minWidth4, &maxWidth4, &alignment4);
#endif /* FF_PRSFMT_USE_SV_PARAM */
        if(res1 < 0)
        {}
        else
        {
            (0 == (res1 & foundIndex)) && (index1 = -1), true;
            (0 == (res1 & foundMinWidth)) && (minWidth1 = -1), true;
            (0 == (res1 & foundMaxWidth)) && (maxWidth1 = -1), true;
            (0 == (res1 & foundAlign)) && (alignment1 = -1), true;
        }

        if(res2 < 0)
        {}
        else
        {
            (0 == (res2 & foundIndex)) && (index2 = -1), true;
            (0 == (res2 & foundMinWidth)) && (minWidth2 = -1), true;
            (0 == (res2 & foundMaxWidth)) && (maxWidth2 = -1), true;
            (0 == (res2 & foundAlign)) && (alignment2 = -1), true;
        }

        if(res3 < 0)
        {}
        else
        {
            (0 == (res3 & foundIndex)) && (index3 = -1), true;
            (0 == (res3 & foundMinWidth)) && (minWidth3 = -1), true;
            (0 == (res3 & foundMaxWidth)) && (maxWidth3 = -1), true;
            (0 == (res3 & foundAlign)) && (alignment3 = -1), true;
        }

        if(res4 < 0)
        {}
        else
        {
            (0 == (res4 & foundIndex)) && (index4 = -1), true;
            (0 == (res4 & foundMinWidth)) && (minWidth4 = -1), true;
            (0 == (res4 & foundMaxWidth)) && (maxWidth4 = -1), true;
            (0 == (res4 & foundAlign)) && (alignment4 = -1), true;
        }

        if( -1 == res1 &&
            -1 == res2 &&
            -1 == res3 &&
            -1 == res4)
        {}
        else if(    (   res1 != res2 ||
                        index1 != index2 ||
                        minWidth1 != minWidth2 ||
                        maxWidth1 != maxWidth2 ||
                        alignment1 != alignment2) ||
                    (   res1 != res3 ||
                        index1 != index3 ||
                        minWidth1 != minWidth3 ||
                        maxWidth1 != maxWidth3 ||
                        alignment1 != alignment3) ||
                    (   res1 != res4 ||
                        index1 != index4 ||
                        minWidth1 != minWidth4 ||
                        maxWidth1 != maxWidth4 ||
                        alignment1 != alignment4)
                )
        {
            fastformat::fmtln(std::cerr, "\nmismatch when parsing parameter {1}: \"{0}\"", param, i);

            if( res1 != res2 ||
                res1 != res3 ||
                res1 != res4)
            {
                fastformat::fmtln(std::cerr, "results do not match: res1={0}, res2={1}, res3={2}, res4={3}", res1, res2, res3, res4);
            }
            if( index1 != index2 ||
                index1 != index3 ||
                index1 != index4)
            {
                fastformat::fmtln(std::cerr, "indexes do not match: index1={0}, index2={1}, index3={2}, index4={3}", index1, index2, index3, index4);
            }
            if( minWidth1 != minWidth2 ||
                minWidth1 != minWidth3 ||
                minWidth1 != minWidth4)
            {
                fastformat::fmtln(std::cerr, "minWidths do not match: minWidth1={0}, minWidth2={1}, minWidth3={2}, minWidth4={3}", minWidth1, minWidth2, minWidth3, minWidth4);
            }
            if( maxWidth1 != maxWidth2 ||
                maxWidth1 != maxWidth3 ||
                maxWidth1 != maxWidth4)
            {
                fastformat::fmtln(std::cerr, "maxWidths do not match: maxWidth1={0}, maxWidth2={1}, maxWidth3={2}, maxWidth4={3}", maxWidth1, maxWidth2, maxWidth3, maxWidth4);
            }
            if( alignment1 != alignment2 ||
                alignment1 != alignment3 ||
                alignment1 != alignment4)
            {
                fastformat::fmtln(std::cerr, "alignments do not match: alignment1={0}, alignment2={1}, alignment3={2}, alignment4={3}", alignment1, alignment2, alignment3, alignment4);
            }
        }
    }}

    { for(unsigned WARMUPS = 2; 0 != --WARMUPS; )
    {
        int index;
        int minWidth;
        int maxWidth;
        int alignment;
        int res;

        counter.start();
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(params); ++i)
        {
            { for(unsigned j = 0; j != INCREMENTS; ++j)
            {
                string_view_t   param(params[i]);

#ifdef FF_PRSFMT_USE_SV_PARAM
                totalRes1 += res = parse_replacement_raw(param, &index, &minWidth, &maxWidth, &alignment);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                totalRes1 += res = parse_replacement_raw(param.begin(), param.end(), &index, &minWidth, &maxWidth, &alignment);
#endif /* FF_PRSFMT_USE_SV_PARAM */
            }}
        }}
        counter.stop();
        tmManual = (counter.*pmfn)();

        counter.start();
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(params); ++i)
        {
            { for(unsigned j = 0; j != INCREMENTS; ++j)
            {
                string_view_t   param(params[i]);

#ifdef FF_PRSFMT_USE_SV_PARAM
                totalRes2 += res = parse_replacement_find_next_token(param, &index, &minWidth, &maxWidth, &alignment);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                totalRes2 += res = parse_replacement_find_next_token(param.begin(), param.end(), &index, &minWidth, &maxWidth, &alignment);
#endif /* FF_PRSFMT_USE_SV_PARAM */
            }}
        }}
        counter.stop();
        tmFindNextToken = (counter.*pmfn)();

        counter.start();
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(params); ++i)
        {
            { for(unsigned j = 0; j != INCREMENTS; ++j)
            {
                string_view_t   param(params[i]);

#ifdef FF_PRSFMT_USE_SV_PARAM
                totalRes3 += res = parse_replacement_string_view(param, &index, &minWidth, &maxWidth, &alignment);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                totalRes3 += res = parse_replacement_string_view(param.begin(), param.end(), &index, &minWidth, &maxWidth, &alignment);
#endif /* FF_PRSFMT_USE_SV_PARAM */
            }}
        }}
        counter.stop();
        tmStringView = (counter.*pmfn)();

        counter.start();
        { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(params); ++i)
        {
            { for(unsigned j = 0; j != INCREMENTS; ++j)
            {
                string_view_t   param(params[i]);

#ifdef FF_PRSFMT_USE_SV_PARAM
                totalRes4 += res = parse_replacement_std_string(param, &index, &minWidth, &maxWidth, &alignment);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                totalRes4 += res = parse_replacement_std_string(param.begin(), param.end(), &index, &minWidth, &maxWidth, &alignment);
#endif /* FF_PRSFMT_USE_SV_PARAM */
            }}
        }}
        counter.stop();
        tmStdString = (counter.*pmfn)();
    }}

    // Disable "unreferenced arguments" warning here
    fastformat::ignore_unreferenced_arguments_scope scope;

#if 1
    fastformat::fmtln(std::cout, "manual parse:   \t{1}", totalRes1, tmManual);
    fastformat::fmtln(std::cout, "find_next_token:\t{1}", totalRes2, tmFindNextToken);
    fastformat::fmtln(std::cout, "string_view:    \t{1}", totalRes3, tmStringView);
    fastformat::fmtln(std::cout, "std::string:    \t{1}", totalRes4, tmStdString);
#else /* ? 0 */
    fastformat::writeln(std::cout, "manual parse:   \t", tmManual, totalRes1 ? "" : "");
    fastformat::writeln(std::cout, "find_next_token:\t", tmFindNextToken, totalRes2 ? "" : "");
    fastformat::writeln(std::cout, "string_view:    \t", tmStringView, totalRes3 ? "" : "");
    fastformat::writeln(std::cout, "std::string:    \t", tmStdString, totalRes4 ? "" : "");
#endif /* 0 */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    try
    {
        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        fastformat::write(std::cerr, "Unhandled error: ", x) << std::endl;

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* /////////////////////////////////////////////////////////////////////////
 * function definitions 
 */

int FASTFORMAT_CALLCONV ignore_unreferenced_params_handler(
    void*                                   param
,   fastformat::replacement_code_t          code
,   size_t                                  numArguments
,   int                                     mismatchedParameterIndex
,   fastformat::ff_replacement_action_t*    missingArgumentAction
,   fastformat::string_slice_t*             slice
,   void*                                   reserved0
,   size_t                                  reserved1
,   void*                                   reserved2
,   int                                     reserved3
)
{
    if (fastformat::FF_REPLACEMENTCODE_UNREFERENCED_ARGUMENT == code)
    {
        return 0;
    }

    return prev(param, code, numArguments, mismatchedParameterIndex, missingArgumentAction, slice, reserved0, reserved1, reserved2, reserved3);
}


int parse_replacement_raw(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0_
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    pindex
,   int*                    pminWidth
,   int*                    pmaxWidth
,   int*                    palignment
)
{
#ifdef FF_PRSFMT_USE_SV_PARAM
    STLSOFT_ASSERT(!param.empty());
    STLSOFT_ASSERT(param.size() >= 2);
    STLSOFT_ASSERT('{' == param.front());
    STLSOFT_ASSERT('}' == param.back());
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    STLSOFT_ASSERT(p1 != p0_);
#endif /* FF_PRSFMT_USE_SV_PARAM */

    int                 res =   0;
#ifdef FF_PRSFMT_USE_SV_PARAM
    char const* const   p0_ =   param.begin() + 1;
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                        ++p0_;
#endif /* FF_PRSFMT_USE_SV_PARAM */
    char const*         p0  =   p0_;
#ifdef FF_PRSFMT_USE_SV_PARAM
    char const* const   p1  =   param.end() - 1;
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                        --p1;
#endif /* FF_PRSFMT_USE_SV_PARAM */
    int                 number;

    if(p0 == p1)
    {
        return -1; // Empty parameter
    }

    // Field 0: index
    { for(number = 0; p1 != p0; ++p0)
    {
        const char ch = *p0;

        switch(ch)
        {
            default:
                FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unexpected character: check switch in main machine loop");
                break;
            case    '0':
            case    '1':
            case    '2':
            case    '3':
            case    '4':
            case    '5':
            case    '6':
            case    '7':
            case    '8':
            case    '9':
                number = 10 * number + (ch - '0');
                continue;
            case    ',':
                if(p0_ == p0)
                {
                    return -1; // Empty index
                }
                else
                {
                    *pindex = number;
                }
                break;
            case    '<':
            case    '>':
            case    '^':
            case    '#':
                return -1; // Invalid index
        }

        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(',' == *p0); // Switch must have been broken on ','
        break;
    }}

    *pindex = number;
    res |= foundIndex;

    // Field 1: minimum width
    if(p1 != p0)
    {
        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(',' == *p0); // Switch must have been broken on ','

        { for(number = 0, ++p0; p1 != p0; ++p0)
        {
            const char ch = *p0;

            switch(ch)
            {
                default:
                    FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unexpected character: check switch in main machine loop");
                    break;
                case    '0':
                case    '1':
                case    '2':
                case    '3':
                case    '4':
                case    '5':
                case    '6':
                case    '7':
                case    '8':
                case    '9':
                    res |= foundMinWidth;
                    number = 10 * number + (ch - '0');
                    continue;
                case    ',':
                    break;
                case    '<':
                case    '>':
                case    '^':
                case    '#':
                    return -1; // Invalid width
            }

            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(',' == *p0); // Switch must have been broken on ','
            break;
        }}

        *pminWidth = number;
    }

    // Field 2: maximum width
    if(p1 != p0)
    {
        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(',' == *p0); // Switch must have been broken on ','

        { for(number = 0, ++p0; p1 != p0; ++p0)
        {
            const char ch = *p0;

            switch(ch)
            {
                default:
                    FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unexpected character: check switch in main machine loop");
                    break;
                case    '0':
                case    '1':
                case    '2':
                case    '3':
                case    '4':
                case    '5':
                case    '6':
                case    '7':
                case    '8':
                case    '9':
                    res |= foundMaxWidth;
                    number = 10 * number + (ch - '0');
                    continue;
                case    ',':
                    break;
                case    '<':
                case    '>':
                case    '^':
                case    '#':
                    return -1; // Invalid width
            }

            FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(',' == *p0); // Switch must have been broken on ','
            break;
        }}

        *pmaxWidth = number;
    }

    // Field 3: alignment
    if(p1 != p0)
    {
        FASTFORMAT_CONTRACT_ENFORCE_ASSUMPTION(',' == *p0); // Switch must have been broken on ','

        { for(++p0; p1 != p0; ++p0)
        {
            const char ch = *p0;

            if(foundAlign & res)
            {
                return -1; // Multiple alignment specifiers
            }

            switch(ch)
            {
                default:
                    FASTFORMAT_CONTRACT_ENFORCE_UNEXPECTED_CONDITION_INTERNAL("unexpected character: check switch in main machine loop");
                    break;
                case    '<':
                    *palignment = left;
                    break;
                case    '>':
                    *palignment = right;
                    break;
                case    '^':
                    *palignment = centre;
                    break;
                case    '#':
                    *palignment = hashFill;
                    break;
                case    ',':
                case    '0':
                case    '1':
                case    '2':
                case    '3':
                case    '4':
                case    '5':
                case    '6':
                case    '7':
                case    '8':
                case    '9':
                    return -1; // Invalid alignment
            }

            res |= foundAlign;
        }}
    }

    return res;
}

#define strtol(s, e, r)     stlsoft_strtol_10((s), (e))

inline long stlsoft_strtol_10(char const* s, char** endptr)
{
    long result = 0;

    for(;; ++s)
    {
        const char ch = *s;

        switch(ch)
        {
            case    '0':
            case    '1':
            case    '2':
            case    '3':
            case    '4':
            case    '5':
            case    '6':
            case    '7':
            case    '8':
            case    '9':
                result = 10 * result + (ch - '0');
                continue;
            default:
                break;
        }

        if(NULL != endptr)
        {
            *endptr = const_cast<char*>(s);
        }

        break;
    }

    return result;
}

int parse_replacement_find_next_token(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0_
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    pindex
,   int*                    pminWidth
,   int*                    pmaxWidth
,   int*                    palignment
)
{
#ifdef FF_PRSFMT_USE_SV_PARAM
    STLSOFT_ASSERT(!param.empty());
    STLSOFT_ASSERT(param.size() >= 2);
    STLSOFT_ASSERT('{' == param.front());
    STLSOFT_ASSERT('}' == param.back());
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    STLSOFT_ASSERT(p1 != p0_);
#endif /* FF_PRSFMT_USE_SV_PARAM */

    int                 res =   0;
#ifdef FF_PRSFMT_USE_SV_PARAM
    char const* const   p0_ =   param.begin() + 1;
#else /* ? FF_PRSFMT_USE_SV_PARAM */
                        ++p0_;
#endif /* FF_PRSFMT_USE_SV_PARAM */
    char const*         p0  =   p0_;
#ifdef FF_PRSFMT_USE_SV_PARAM
    char const*         p1  =   p0;
    char const* const   end =   param.end() - 1;
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const* const   end =   p1 - 1;
                        p1  =   p0;
#endif /* FF_PRSFMT_USE_SV_PARAM */

    // Field 0: index
    stlsoft::find_next_token(p0, p1, end, ',');
    if(p0 == p1)
    {
        return -1; // Empty parameter
    }
    else
    {
        char*   endptr;
        long    result = ::strtol(p0, &endptr, 10);

        if(p1 != endptr)
        {
            return -1;
        }

        *pindex = int(result);

        res |= foundIndex;
    }

    // Field 1: minimum width
    stlsoft::find_next_token(p0, p1, end, ',');
    if( /* p0 != end && */
        p1 != p0)
    {
        char*   endptr;
        long    result = ::strtol(p0, &endptr, 10);

        if(p1 != endptr)
        {
            return -1;
        }

        *pminWidth = int(result);

        res |= foundMinWidth;
    }

    // Field 1: maximum width
    stlsoft::find_next_token(p0, p1, end, ',');
    if( /* p0 != end && */
        p1 != p0)
    {
        char*   endptr;
        long    result = ::strtol(p0, &endptr, 10);

        if(p1 != endptr)
        {
            return -1;
        }

        *pmaxWidth = int(result);

        res |= foundMaxWidth;
    }

    stlsoft::find_next_token(p0, p1, end, ',');
    if(p1 != p0)
    {
        if(p1 != p0 + 1)
        {
            return -1; // Invalid argument
        }
        else
        {
            switch(p0[0])
            {
                default:
                    return -1; // Invalid alignment
                case    '<':
                    *palignment = left;
                    break;
                case    '>':
                    *palignment = right;
                    break;
                case    '^':
                    *palignment = centre;
                    break;
                case    '#':
                    *palignment = hashFill;
                    break;
            }

            res |= foundAlign;
        }
    }

    return res;
}

int parse_replacement_string_view(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param_
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    pindex
,   int*                    pminWidth
,   int*                    pmaxWidth
,   int*                    palignment
)
{
    int res = 0;

#ifdef FF_PRSFMT_USE_SV_PARAM
    STLSOFT_ASSERT(!param_.empty());
    STLSOFT_ASSERT(param_.size() >= 2);
    STLSOFT_ASSERT('{' == param_.front());
    STLSOFT_ASSERT('}' == param_.back());
#endif /* FF_PRSFMT_USE_SV_PARAM */

#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t   param = string_view_t(param_, 1, param_.size() - 2);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    string_view_t   param(p0 + 1, p1 - 1);
#endif /* FF_PRSFMT_USE_SV_PARAM */
    string_view_t   index;
    string_view_t   qualifiers;
    string_view_t   qualifiers2;
    string_view_t   minWidth;
    string_view_t   maxWidth;
    string_view_t   alignment;

    if(!stlsoft::split(param, ',', index, qualifiers))
    {
        index = param;
    }
    else
    {
        if(!stlsoft::split(qualifiers, ',', minWidth, qualifiers2))
        {
            minWidth = qualifiers;
        }
        else
        {
            if(!stlsoft::split(qualifiers2, ',', maxWidth, alignment))
            {
                maxWidth = qualifiers2;
            }
        }
    }


    if(index.empty())
    {
        return -1;
    }
    else
    {
        char*   endptr;
        long    result = ::strtol(index.data(), &endptr, 10);

        if(index.end() != endptr)
        {
            return -1;
        }

        *pindex = int(result);

        res |= foundIndex;
    }

    if(!minWidth.empty())
    {
        char*   endptr;
        long    result = ::strtol(minWidth.data(), &endptr, 10);

        if(minWidth.end() != endptr)
        {
            return -1;
        }

        *pminWidth = int(result);

        res |= foundMinWidth;
    }

    if(!maxWidth.empty())
    {
        char*   endptr;
        long    result = ::strtol(maxWidth.data(), &endptr, 10);

        if(maxWidth.end() != endptr)
        {
            return -1;
        }

        *pmaxWidth = int(result);

        res |= foundMaxWidth;
    }

    if(!alignment.empty())
    {
        if(1u != alignment.size())
        {
            return -1; // Invalid argument
        }
        else
        {
            switch(alignment[0])
            {
                default:
                    return -1; // Invalid alignment
                case    '<':
                    *palignment = left;
                    break;
                case    '>':
                    *palignment = right;
                    break;
                case    '^':
                    *palignment = centre;
                    break;
                case    '#':
                    *palignment = hashFill;
                    break;
            }

            res |= foundAlign;
        }
    }

    return res;
}


int parse_replacement_std_string(
#ifdef FF_PRSFMT_USE_SV_PARAM
    string_view_t const&    param_
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    char const*             p0
,   char const*             p1
#endif /* FF_PRSFMT_USE_SV_PARAM */
,   int*                    pindex
,   int*                    pminWidth
,   int*                    pmaxWidth
,   int*                    palignment
)
{
    int res = 0;

#ifdef FF_PRSFMT_USE_SV_PARAM
    STLSOFT_ASSERT(!param_.empty());
    STLSOFT_ASSERT(param_.size() >= 2);
    STLSOFT_ASSERT('{' == param_.front());
    STLSOFT_ASSERT('}' == param_.back());
#endif /* FF_PRSFMT_USE_SV_PARAM */

#ifdef FF_PRSFMT_USE_SV_PARAM
    std::string     param = std::string(param_.data() + 1, param_.size() - 2);
#else /* ? FF_PRSFMT_USE_SV_PARAM */
    std::string     param(p0 + 1, p1 - 1);
#endif /* FF_PRSFMT_USE_SV_PARAM */
    std::string     index;
    std::string     qualifiers;
    std::string     qualifiers2;
    std::string     minWidth;
    std::string     maxWidth;
    std::string     alignment;

    if(!stlsoft::split(param, ',', index, qualifiers))
    {
        index = param;
    }
    else
    {
        if(!stlsoft::split(qualifiers, ',', minWidth, qualifiers2))
        {
            minWidth = qualifiers;
        }
        else
        {
            if(!stlsoft::split(qualifiers2, ',', maxWidth, alignment))
            {
                maxWidth = qualifiers2;
            }
        }
    }


    if(index.empty())
    {
        return -1;
    }
    else
    {
        char*               endptr;
        char const* const   begin   =   index.c_str();
        char const* const   end     =   begin + index.size();
        long                result  =   ::strtol(begin, &endptr, 10);

        if(end != endptr)
        {
            return -1;
        }

        *pindex = int(result);

        res |= foundIndex;
    }

    if(!minWidth.empty())
    {
        char*               endptr;
        char const* const   begin   =   minWidth.c_str();
        char const* const   end     =   begin + minWidth.size();
        long                result  =   ::strtol(begin, &endptr, 10);

        if(end != endptr)
        {
            return -1;
        }

        *pminWidth = int(result);

        res |= foundMinWidth;
    }

    if(!maxWidth.empty())
    {
        char*               endptr;
        char const* const   begin   =   maxWidth.c_str();
        char const* const   end     =   begin + maxWidth.size();
        long                result  =   ::strtol(begin, &endptr, 10);

        if(end != endptr)
        {
            return -1;
        }

        *pmaxWidth = int(result);

        res |= foundMaxWidth;
    }

    if(!alignment.empty())
    {
        if(1u != alignment.size())
        {
            return -1; // Invalid argument
        }
        else
        {
            switch(alignment[0])
            {
                default:
                    return -1; // Invalid alignment
                case    '<':
                    *palignment = left;
                    break;
                case    '>':
                    *palignment = right;
                    break;
                case    '^':
                    *palignment = centre;
                    break;
                case    '#':
                    *palignment = hashFill;
                    break;
            }
            res |= foundAlign;
        }
    }

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
