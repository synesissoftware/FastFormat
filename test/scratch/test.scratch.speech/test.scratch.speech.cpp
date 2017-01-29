/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.speech.cpp
 *
 * Purpose:     Implementation file for the test.scratch.speech project.
 *
 * Created:     27th November 2007
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2007-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


//#include <sapi.h>
//#define COMSTL_SPEECH_SAPI_UTIL_USE_MS_SAPI_HEADERS

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/speech.hpp>
#include <fastformat/ff.hpp>


/* VOLE Header Files */
#ifdef FASTFORMAT_USE_VOLE
# include <vole/vole.hpp>
#endif /* FASTFORMAT_USE_VOLE */

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <comstl/conversion/interface_cast.hpp>

/* Standard C++ Header Files */
#include <exception>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#define FF_STR          FASTFORMAT_LITERAL_STRING

#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define FF_STRINGIZE       STLSOFT_STRINGIZE_w
# define FF_ENCODING        "wide string"
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define FF_STRINGIZE       STLSOFT_STRINGIZE_a
# define FF_ENCODING        "multibyte string"
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

#include <fastformat/internal/threading.h>

#if defined(FASTFORMAT_MT)
# if defined(_DLL) || \
     defined(__DLL)
#  if defined(NDEBUG)
#   define FF_CONFIGURATION "DLL multithreaded release"
#  else /* ? NDEBUG */
#   define FF_CONFIGURATION "DLL multithreaded debug"
#  endif /* NDEBUG */
# else /* ? DLL */
#  if defined(NDEBUG)
#   define FF_CONFIGURATION "multithreaded release"
#  else /* ? NDEBUG */
#   define FF_CONFIGURATION "multithreaded debug"
#  endif /* NDEBUG */
# endif /* DLL */
#else /* ? FASTFORMAT_MT */
# if defined(NDEBUG)
#  define FF_CONFIGURATION  "single-threaded release"
# else /* ? NDEBUG */
#  define FF_CONFIGURATION  "single-threaded debug"
# endif /* NDEBUG */
#endif /* FASTFORMAT_MT */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    ff::sinks::speech_sink sink(SPF_IS_FILENAME);

#ifdef FASTFORMAT_USE_VOLE
    vole::object    speaker(comstl::interface_cast<IDispatch>(sink.get()));
#endif /* FASTFORMAT_USE_VOLE */

#ifdef FASTFORMAT_USE_VOLE
    { for(long rate = 0; 5 != rate; ++rate)
    {
        speaker.put_property(L"Rate", rate * 2);
#endif /* FASTFORMAT_USE_VOLE */

        ff::fmt(sink
            ,   FF_STR("This is a demonstration of FastFormat's ability to speak, compiled with {0}, in configuration {1}, and with the {2} encoding")
            /* {0}: compiler name */
            ,   FF_STRINGIZE(STLSOFT_COMPILER_VERSION_STRING)
            /* {1}: configuration */
            ,   FF_STRINGIZE(FF_CONFIGURATION)
            /* {2}: encoding */
            ,   FF_STRINGIZE(FF_ENCODING)
            );

#ifdef FASTFORMAT_USE_VOLE
    }}
#endif /* FASTFORMAT_USE_VOLE */

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
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
