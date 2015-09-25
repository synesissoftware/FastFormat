/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.FILE.cpp
 *
 * Purpose:     Implementation file for the test.scratch.FILE project.
 *
 * Created:     24th September 2006
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////////// */

#if defined(_DEBUG) && \
    defined(WIN32) && \
    defined(_MSC_VER)
# define DO_OTHER_TYPE_TESTS
#endif

#if defined(_DEBUG) && \
    defined(WIN32) && \
    defined(_MSC_VER) && \
    defined(_DLL)
# define USE_MFC
#endif

#ifdef USE_MFC
# include <mfcstl/mfcstl.hpp>
#endif


/* FastFormat header files */
#include <fastformat/sinks/FILE.hpp>
#include <fastformat/ff.hpp>

#ifdef DO_OTHER_TYPE_TESTS
# include <fastformat/sinks/auto_buffer.hpp>
# include <fastformat/sinks/char_buffer.hpp>
# include <fastformat/sinks/c_string.hpp>
# include <fastformat/sinks/null.hpp>
# include <fastformat/sinks/ostream.hpp>
#  include <iostream>
# include <fastformat/sinks/stringstream.hpp>
# if defined(WIN32) || \
     defined(WIN64)
#  include <fastformat/sinks/CComBSTR.hpp>
#  ifdef USE_MFC
#   include <fastformat/sinks/CString.hpp>
#  endif
#  include <fastformat/sinks/OutputDebugString.hpp>
# endif
#endif

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <platformstl/platformstl.hpp>

/* Standard C++ header files */
#include <exception>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////////
 * Character-encoding compatibility
 */

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define    std_cout        std::wcout
# define    std_string      std::wstring
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define    std_cout        std::cout
# define    std_string      std::string
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */

#define FF_STR      FASTFORMAT_LITERAL_STRING

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /* argv */)
{
    {
#if 1
        FILE* file = stdout;

        ff::fmtln(file
#else /* ? 0 */
        ff::fmtln(ff::FILE_ref(stdout, ff::buffered)
#endif /* 0 */
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        FILE* file = stdout;

        ff::fmt(file
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
        puts("");
    }

    {
        ff::fmt(ff::to_sink(stdout)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
        puts("");
    }

    {
        ff::flush(
            ff::fmt(ff::to_sink(stdout)
                ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
                )
        );
        puts("");
    }

    try
    {
        FILE* file = stdin;

        ff::fmt(file
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
        puts("");
    }
    catch(ff::sink_output_exception& x)
    {
        FILE* file = stderr;

        ff::writeln(file, x);
    }

#ifdef DO_OTHER_TYPE_TESTS

# if 0
    {
        FILE* sink = stdout;

        ff::fmt(ff::flushed(stdout)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
        puts("");
    }

    {
        ff::fmt(ff::flushed(std_cout)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
        puts("");
    }

    {
        std_string sink;

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        stlsoft::auto_buffer<ff::ff_char_t, 1000> sink(0);

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        ff::ff_char_t buff[1001];

        ff::sinks::char_buffer_sink sink(STLSOFT_NUM_ELEMENTS(buff), buff);

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        ff::ff_char_t buff[1001];

        ff::sinks::c_string_sink sink(STLSOFT_NUM_ELEMENTS(buff), buff);

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        ff::sinks::null_sink sink;

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

#  if defined(WIN32) || \
      defined(WIN64)

    {
        CComBSTR    sink;

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        CString sink;

        ff::fmt(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

    {
        ff::sinks::OutputDebugString_sink   sink;

        ff::fmtln(ff::flushed(sink)
            , FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def"));
    }

#  endif
# else
    {
        FILE* sink = stdout;

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
        puts("");
    }

    {
        ff::flush(
            ff::fmt(
                std_cout
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
        puts("");
    }

    {
        std_string sink;

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }

#  if 0
    {
        stlsoft::auto_buffer<ff::ff_char_t, 1000> sink(0);

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }
#  endif /* 0 */

    {
        ff::ff_char_t buff[1001];

        ff::sinks::char_buffer_sink sink(STLSOFT_NUM_ELEMENTS(buff), buff);

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }

    {
        ff::ff_char_t buff[1001];

        ff::sinks::c_string_sink sink(STLSOFT_NUM_ELEMENTS(buff), buff);

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }

    {
        ff::sinks::null_sink sink;

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }

#  if defined(WIN32) || \
      defined(WIN64)

    {
        CComBSTR    sink;

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }

#   ifdef USE_MFC
    {
        CString sink;

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }
#   endif

    {
        ff::sinks::OutputDebugString_sink   sink;

        ff::flush(
            ff::fmt(
                sink
            ,   FF_STR("Param #1: {0}; param #2: {1}; param #1 again: {0}"), FF_STR("abc"), FF_STR("def")
            )
        );
    }

#  endif
# endif
#endif /* DO_OTHER_TYPE_TESTS */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.FILE: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        return main_(argc, argv);
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

/* ///////////////////////////// end of file //////////////////////////// */
