/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.performance.one_integer.cpp
 *
 * Purpose:     Implementation file for the test.performance.one_integer project.
 *
 * Created:     9th September 2006
 * Updated:     22nd January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////////// */


//#define FASTFORMAT_NO_USE_JIT_CACHE

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#if defined(_WIN32) && \
    defined(_AFXDLL)
# include <mfcstl/mfcstl.hpp>
#endif


/* FastFormat Header Files */
#include <fastformat/internal/stlsoft.h>
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
# define _CRT_SECURE_NO_DEPRECATE
# pragma warning(disable : 4996)
# pragma warning(disable : 4505)
#endif
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
 /* These warnings only for Boost. Ho hum. */
# pragma warning(disable : 4511)
# pragma warning(disable : 4512)
# pragma warning(disable : 4671)
# pragma warning(disable : 4673)
# pragma warning(disable : 4702)
# endif /* compiler */
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#include <fastformat/shims/conversion/filter_type/fast_integers.hpp>
#if defined(__BORLANDC__) && \
    __BORLANDC__ < 0x0610
 /* Borland is really messed up, so we have to skip around the filter_type
  * mechanism, and instead define string access shims
  *
  * WARNING: The following implementation is hack that is good enough only
  * to make this compilation unit run correctly. Do not take this code and
  * put it into production
  */
# include <stdio.h>
# include <string.h>

    namespace 
    {
        char    s_realBuffer[1001];
    }

    namespace stlsoft
    {
        char const* c_str_data_a(double d)
        {
            int n = ::snprintf(&s_realBuffer[0], STLSOFT_NUM_ELEMENTS(s_realBuffer) - 1, "%G", d);

            if(n < 0)
            {
                n = STLSOFT_NUM_ELEMENTS(s_realBuffer) - 1;
            }

            s_realBuffer[n] = '\0';

            return s_realBuffer;
        }
        size_t c_str_len_a(double d)
        {
            return strlen(c_str_data_a(d));
        }
    }

#else /* ? compiler */
# include <fastformat/shims/conversion/filter_type/reals.hpp>
#endif /* compiler */
#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>

#if defined(_WIN32) && \
    defined(UNIX)
# include <winsock2.h>
# include <sys/time.h>
# include <platformstl/performance/performance_counter.hpp>
#endif

/* STLSoft Header Files */
#if defined(_WIN32) && \
    defined(_AFXDLL)
# include <mfcstl/mfcstl.hpp>
# include <mfcstl/string/grab_cstring_buffer.hpp>
# include <fastformat/sinks/CString.hpp>
#endif /* OS */
#include <stlsoft/stlsoft.h>
#include <stlsoft/shims/access/string/std/time.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <stlsoft/string/simple_string.hpp>
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <comstl/shims/access/string.hpp>
#endif /* OS */
#include <platformstl/performance/performance_counter.hpp>

#include <fastformat/sinks/ostream.hpp>
#include <fastformat/fastformat.hpp>

/* Boost Header Files */
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
# include <boost/format.hpp>
# include <boost/spirit/include/karma.hpp>
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

/* Loki Header Files */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
# include <loki/SafeFormat.h>
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */

/* xTests Header Files */
#include <xtests/xtests.h>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>
#include <sstream>

/* Standard C Header Files */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* /////////////////////////////////////////////////////////////////////////////
 * globals
 */

extern "C" const char PANTHEIOS_FE_PROCESS_IDENTITY[] = "test.performance.one_integer";

/* /////////////////////////////////////////////////////////////////////////////
 * types
 */

/* /////////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static std::string  with_Streams(int value);
static std::string  with_IOStreams(int value);
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
static std::string  with_BoostFormat(int value);
static std::string  with_BoostSpiritKarma(int value);
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
static std::string  with_Loki(int value);
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */
static std::string  with_STLSoftI2S(int value);
#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
static CString      with_MFC(int value);
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
static std::string  with_FF_Write(int value);
static std::string  with_FF_Format(int value);

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
#ifdef _DEBUG
    unsigned ITERATIONS =   3;
    unsigned WARMUPS    =   1;
#else /* ? _DEBUG */
    unsigned ITERATIONS =   100000;
    unsigned WARMUPS    =   2;
#endif /* _DEBUG */
    size_t   length     =   0;

    int verbosity;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

#ifndef NDEBUG
    if(!XTESTS_START_RUNNER("test.performance.one_integer", verbosity))
    {
        fprintf(stderr, "Could not start xTests runner!\n");

        return EXIT_FAILURE;
    }
    else if(!XTESTS_CASE_BEGIN("case", ""))
    {
        fprintf(stderr, "Could not start xTests test case!\n");

        return EXIT_FAILURE;
    }
#endif /* !NDEBUG */



    // The scenario:
    //
    // int into std::string/CString

    platformstl::performance_counter                counter;
    platformstl::performance_counter::interval_type tm_Streams          =   1;
    platformstl::performance_counter::interval_type tm_IOStreams        =   1;
    platformstl::performance_counter::interval_type tm_CString_Format   =   1;
    platformstl::performance_counter::interval_type tm_BoostFormat      =   1;
    platformstl::performance_counter::interval_type tm_BoostSpiritKarma =   1;
    platformstl::performance_counter::interval_type tm_Loki             =   1;
    platformstl::performance_counter::interval_type tm_STLSoftI2S       =   1;
    platformstl::performance_counter::interval_type tm_FF_Format        =   1;
    platformstl::performance_counter::interval_type tm_FF_Write         =   1;

    const int   args[] =
    {
            INT_MIN
        ,   -1000
        ,   -1
        ,   0
        ,   1
        ,   10
        ,   1000
        ,   INT_MAX
    };

    // Streams()

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_Streams(arg);

#ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
#endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_Streams = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "Streams:  %lu\t(%lu)\n", (unsigned long)tm_Streams, (unsigned long)length);
        }
    }}

    // Test Identifier

    std::string TestId = PANTHEIOS_FE_PROCESS_IDENTITY;

    // IOStreams

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_IOStreams(arg);

#ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
#endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_IOStreams = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "IOStreams:  %lu\t(%lu)\n", (unsigned long)tm_IOStreams, (unsigned long)length);
        }
    }}

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
    // Boost.Format

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_BoostFormat(arg);

# ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
# endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_BoostFormat = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "Boost.Format:  %lu\t(%lu)\n", (unsigned long)tm_BoostFormat, (unsigned long)length);
        }
    }}

    // Boost.Spirit.Karma

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_BoostSpiritKarma(arg);

# ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
# endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_BoostSpiritKarma = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "Boost.Spirit.Karma:  %lu\t(%lu)\n", (unsigned long)tm_BoostSpiritKarma, (unsigned long)length);
        }
    }}
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

#ifdef FASTFORMAT_PERFTEST_USE_LOKI
    // Loki.SafeFormat

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_Loki(arg);

# ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
# endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();

        tm_Loki = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "Loki.SafeFormat: %lu\t(%lu)\n", (unsigned long)tm_Loki, (unsigned long)length);
        }
    }}
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */


    // STLSoft.I2S

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_STLSoftI2S(arg);

# ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
# endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();

        tm_STLSoftI2S = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "STLSoft.I2S: %lu\t(%lu)\n", (unsigned long)tm_STLSoftI2S, (unsigned long)length);
        }
    }}

#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
    // MFC

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_MFC(arg);

# ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
# endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_CString_Format = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "MFC:  %lu\t(%lu)\n", (unsigned long)tm_CString_Format, (unsigned long)length);
        }
    }}
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */

    // FF_Write

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_FF_Write(arg);

#ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
#endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_FF_Write = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "FF_Write:  %lu\t(%lu)\n", (unsigned long)tm_FF_Write, (unsigned long)length);
        }
    }}

    // FF_Format

    { for(unsigned j = 0; j < WARMUPS; ++j)
    {
        length = 0;
        counter.start();
        { for(unsigned i = 0; i < ITERATIONS; ++i)
        {
            const int arg = args[i % STLSOFT_NUM_ELEMENTS(args)];

            std::string res = with_FF_Format(arg);

#ifndef NDEBUG
            {
                char        sz[21];
                char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), arg);

                XTESTS_TEST_MULTIBYTE_STRING_EQUAL(s, res);
            }
#endif /* !NDEBUG */

            length += res.size();
        }}
        counter.stop();
        tm_FF_Format = counter.get_microseconds();

        if( verbosity >= 3 &&
            j == WARMUPS - 1)
        {
            ::fprintf(stdout, "FastFormat.Format:  %lu\t(%lu)\n", (unsigned long)tm_FF_Format, (unsigned long)length);
        }
    }}

    STLSOFT_SUPPRESS_UNUSED(length);

    std::string     fmt1;
    std::string     fmt2;

    fastformat::ignore_unreferenced_arguments_scope scoper;

    switch(verbosity)
    {
        case    0:
            // no output
            break;
        case    1:
            fmt1 = "";
            fmt1 += "S:FF.F:\t{0}";
            fmt1 += "\tIOS:FF.F:\t{1}";
            fmt1 += "\tFF.W:FF.F:\t{3}";
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            fmt1 += "\tB.F:FF.F:\t{4}";
            fmt1 += "\tB.SK:FF.F:\t{6}";
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
            fmt1 += "\tL.SF:FF.F:\t{5}";
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */
#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
            fmt1 += "\tMFC.F:FF.F:\t{2}";
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
            fmt1 += "\tS.I2S:FF.F:\t{7}";
            fastformat::fmtln(  std::cout, fmt1
                            ,   double(tm_Streams) / double(tm_FF_Format)
                            ,   double(tm_IOStreams) / double(tm_FF_Format)
                            ,   double(tm_CString_Format) / double(tm_FF_Format)
                            ,   double(tm_FF_Write) / double(tm_FF_Format)
                            ,   double(tm_BoostFormat) / double(tm_FF_Format)
                            ,   double(tm_Loki) / double(tm_FF_Format)
                            ,   double(tm_BoostSpiritKarma) / double(tm_FF_Format)
                            ,   double(tm_STLSoftI2S) / double(tm_FF_Format)
                            );
            fmt1 = "";
            fmt1 += "S:FF.W:\t{0}";
            fmt1 += "\tIOS:FF.W:\t{1}";
            fmt1 += "\tFF.F:FF.W:\t{2}";
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            fmt1 += "\tB.F:FF.W:\t{3}";
            fmt1 += "\tB.SK:FF.W:\t{6}";
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
            fmt1 += "\tL.SF:FF.W:\t{5}";
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */
#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
            fmt1 += "\tMFC.F:FF.W:\t{4}";
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
            fmt1 += "\tS.I2S:FF.W:\t{7}";
            fastformat::fmtln(  std::cout, fmt1
                            ,   double(tm_Streams) / double(tm_FF_Write)
                            ,   double(tm_IOStreams) / double(tm_FF_Write)
                            ,   double(tm_CString_Format) / double(tm_FF_Write)
                            ,   double(tm_FF_Format) / double(tm_FF_Write)
                            ,   double(tm_BoostFormat) / double(tm_FF_Write)
                            ,   double(tm_Loki) / double(tm_FF_Write)
                            ,   double(tm_BoostSpiritKarma) / double(tm_FF_Write)
                            ,   double(tm_STLSoftI2S) / double(tm_FF_Write)
                            );
            break;
        case    2:
            fastformat::fmtln(std::cout, "{0}\tFastFormat.Format\tFastFormat.Write", TestId);
            fastformat::fmtln(std::cout, "Streams\t{0}\t{1}", double(tm_Streams) / double(tm_FF_Format), double(tm_Streams) / double(tm_FF_Write));
            fastformat::fmtln(std::cout, "IOStreams\t{0}\t{1}", double(tm_IOStreams) / double(tm_FF_Format), double(tm_IOStreams) / double(tm_FF_Write));
#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
            fastformat::fmtln(std::cout, "CString::Format\t{0}\t{1}", double(tm_CString_Format) / double(tm_FF_Format), double(tm_CString_Format) / double(tm_FF_Write));
#else /* ? FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
            fastformat::writeln(std::cout, "");
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            fastformat::fmtln(std::cout, "Boost.Format\t{0}\t{1}", double(tm_BoostFormat) / double(tm_FF_Format), double(tm_BoostFormat) / double(tm_FF_Write));
            fastformat::fmtln(std::cout, "Boost.Spirit.Karma\t{0}\t{1}", double(tm_BoostSpiritKarma) / double(tm_FF_Format), double(tm_BoostSpiritKarma) / double(tm_FF_Write));
#else /* ? FASTFORMAT_PERFTEST_USE_BOOST */
            fastformat::writeln(std::cout, "");
            fastformat::writeln(std::cout, "");
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
            fastformat::fmtln(std::cout, "Loki.SafeFormat\t{0}\t{1}", double(tm_Loki) / double(tm_FF_Format), double(tm_Loki) / double(tm_FF_Write));
#else /* ? FASTFORMAT_PERFTEST_USE_LOKI */
            fastformat::writeln(std::cout, "");
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */
            fastformat::fmtln(std::cout, "STLSoft.I2S\t{0}\t{1}", double(tm_STLSoftI2S) / double(tm_FF_Format), double(tm_STLSoftI2S) / double(tm_FF_Write));
            fastformat::fmtln(std::cout, "FastFormat.Format\t{0}\t{1}", "", double(tm_FF_Format) / double(tm_FF_Write));
            fastformat::fmtln(std::cout, "FastFormat.Write\t{0}\t{1}", double(tm_FF_Write) / double(tm_FF_Format), "");
            break;
        case    3:
            ::puts("");
            ::fprintf(stdout, "sprintf():FastFormat.Format:         \t%2.04g\n", double(tm_Streams) / double(tm_FF_Format));
            ::fprintf(stdout, "IOStreams:FastFormat.Format:         \t%2.04g\n", double(tm_IOStreams) / double(tm_FF_Format));
#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
            ::fprintf(stdout, "CString::Format():FastFormat.Format: \t%2.04g\n", double(tm_CString_Format) / double(tm_FF_Format));
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            ::fprintf(stdout, "Boost.Format:FastFormat.Format:      \t%2.04g\n", double(tm_BoostFormat) / double(tm_FF_Format));
            ::fprintf(stdout, "Boost.Spirit.Karma:FastFormat.Format:\t%2.04g\n", double(tm_BoostSpiritKarma) / double(tm_FF_Format));
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
            ::fprintf(stdout, "Loki.SafeFormat:FastFormat.Format:   \t%2.04g\n", double(tm_Loki) / double(tm_FF_Format));
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */
            ::fprintf(stdout, "STLSoft.I2S:FastFormat.Format:       \t%2.04g\n", double(tm_STLSoftI2S) / double(tm_FF_Format));
            ::puts("");
            ::fprintf(stdout, "sprintf():FastFormat.Write:          \t%2.04g\n", double(tm_Streams) / double(tm_FF_Write));
            ::fprintf(stdout, "IOStreams:FastFormat.Write:          \t%2.04g\n", double(tm_IOStreams) / double(tm_FF_Write));
#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
            ::fprintf(stdout, "CString::Format():FastFormat.Write:  \t%2.04g\n", double(tm_CString_Format) / double(tm_FF_Write));
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            ::fprintf(stdout, "Boost.Format:FastFormat.Write:       \t%2.04g\n", double(tm_BoostFormat) / double(tm_FF_Write));
            ::fprintf(stdout, "Boost.Karma.Spirit:FastFormat.Write: \t%2.04g\n", double(tm_BoostSpiritKarma) / double(tm_FF_Write));
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
#ifdef FASTFORMAT_PERFTEST_USE_LOKI
            ::fprintf(stdout, "Loki.SafeFormat:FastFormat.Write:    \t%2.04g\n", double(tm_Loki) / double(tm_FF_Write));
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */
            ::fprintf(stdout, "STLSoft.I2S:FastFormat.Write:        \t%2.04g\n", double(tm_STLSoftI2S) / double(tm_FF_Write));
            ::fprintf(stdout, "\n");
            ::fprintf(stdout, "FastFormat.Format:FastFormat.Write:  \t%2.04g\n", double(tm_FF_Format) / double(tm_FF_Write));
            break;
    }

#ifndef NDEBUG
    XTESTS_CASE_END("case");
    XTESTS_PRINT_RESULTS();
    XTESTS_END_RUNNER();
#endif /* !NDEBUG */

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    try
    {
        if(fastformat::init() < 0)
        {
            fprintf(stderr, "Failed to initialise FastFormat\n");
        }
        else
        {
#if defined(STLSOFT_COMPILER_IS_GCC) && \
    defined(_WIN32)
#else
            stlsoft::scoped_handle<void> scoper(fastformat::uninit); // Causes a link error with GCC on Windows
#endif

            return main_(argc, argv);
        }
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");
    }

    return EXIT_FAILURE;
}

/* /////////////////////////////////////////////////////////////////////////
 * conversion functions
 */

static std::string with_Streams(int value)
{
    char    num[21];

    return std::string(num, size_t(::sprintf(&num[0], "%d", value)));
}

static std::string with_IOStreams(int value)
{
    std::stringstream   ss;

    ss << value;

    return ss.str();
}

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
static std::string with_BoostFormat(int value)
{
    return boost::str(boost::format("%1%") % value);
}

static std::string with_BoostSpiritKarma(int value)
{
    using namespace boost::spirit;
    using boost::spirit::karma::generate;

    char x[21];

    char *p = x;
    generate(p, int_, value);
#if 0
    *p = 0;

    return std::string(x);
#else /* ? 0 */
    return std::string(x, p);
#endif /* 0 */
}
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

#ifdef FASTFORMAT_PERFTEST_USE_LOKI
static std::string with_Loki(int value)
{
    std::string s;

    Loki::SPrintf(s, "%d")(value);

    return s;
}
#endif /* FASTFORMAT_PERFTEST_USE_LOKI */

static std::string with_STLSoftI2S(int value)
{
    size_t      n;
    char        sz[21];
    char const* s = stlsoft::integer_to_string(&sz[0], STLSOFT_NUM_ELEMENTS(sz), value, &n);

    return std::string(s, n);
}

#ifdef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING
static CString with_MFC(int value)
{
    CString str;
    
    str.Format(TEXT("%d"), value);

    return str;
}
#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_CSTRING */

static std::string with_FF_Write(int value)
{
    std::string str;

    fastformat::write(str, value);

    return str;
}

static std::string with_FF_Format(int value)
{
    std::string str;

    fastformat::fmt(str, "{0}", value);

    return str;
}

/* ///////////////////////////// end of file //////////////////////////// */
