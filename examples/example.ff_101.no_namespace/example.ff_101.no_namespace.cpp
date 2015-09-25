/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.ff_101.no_namespace/example.ff_101.no_namespace.cpp
 *
 * Purpose:     Implementation file for the example.ff_101.no_namespace project.
 *
 * Created:     2nd June 2008
 * Updated:     25th September 2015
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


#ifndef FASTFORMAT_NO_NAMESPACE
# define FASTFORMAT_NO_NAMESPACE
#endif /* !FASTFORMAT_NO_NAMESPACE */

#ifdef _AFXDLL
# include <afx.h>
#endif /* _AFXDLL */

/* FastFormat header files */
#include <fastformat/sinks/ostream.hpp>
#ifdef __AFX_H__
# include <fastformat/sinks/CString.hpp>
#endif /* __AFX_H__ */
#include <fastformat/fastformat.hpp>

/* STLSoft header files */
#include <stlsoft/string/simple_string.hpp>
#include <platformstl/platformstl.hpp>
#ifdef __AFX_H__
//# include <
#endif /* __AFX_H__ */

#ifdef PLATFORMSTL_OS_IS_WINDOWS
# include <comstl/util/initialisers.hpp>
# include <comstl/util/variant.hpp>
#endif /* OS */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C header files */
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    // Case 1:
    //
    // - sink:      std::string
    // - format:    C-style string
    // - arguments: C-style string, std::string, int
    {
        std::string             sink;

        char const*             arg0    =   "arg0";
        std::string             arg1    =   "arg1";
#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
        char                    arg2[]  =   "10";
#else /* ? FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */
        int                     arg2    =   10;
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

        sink.erase();
        fmt(sink, "A c-style string: {0}", arg0);

        sink.erase();
        fmt(sink, "A std::string: {0}", arg1);

        sink.erase();
        fmt(sink, "A c-style string: {0}, and a std::string: {1}", arg0, arg1);

        sink.erase();
        fmt(sink, "A c-style string: {1}, and an int: {0}", arg2, arg0);
    }

    // Case 2:
    //
    // - sink:      stlsoft::simple_string
    // - format:    std::string
    // - arguments: C-style string, std::string, int
    {
        stlsoft::simple_string  sink;

        std::string             fmt0("A c-style string: {0}");
        std::string             fmt1("A std::string: {0}");
        std::string             fmt2("A c-style string: {0}, and a std::string: {1}");
        std::string             fmt3("A c-style string: {1}, and an int: {0}");

        char const*             arg0    =   "arg0";
        std::string             arg1    =   "arg1";
#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
        char                    arg2[]  =   "10";
#else /* ? FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */
        int                     arg2    =   10;
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

        sink.clear();
        fmt(sink, fmt0, arg0);

        sink.clear();
        fmt(sink, fmt1, arg1);

        sink.clear();
        fmt(sink, fmt2, arg0, arg1);

        sink.clear();
        fmt(sink, fmt3, arg2, arg0);
    }

    // Case 3:
    //
    // - sink:      std::cout
    // - format:    std::string
    // - arguments: C-style string, std::string, int
    {
        std::ostream&           sink = std::cout;

        std::string             fmt0("A c-style string: {0}");
        std::string             fmt1("A std::string: {0}");
        std::string             fmt2("A c-style string: {0}, and a std::string: {1}");
        std::string             fmt3("A c-style string: {1}, and an int: {0}");

        char const*             arg0    =   "arg0";
        std::string             arg1    =   "arg1";
#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
        char                    arg2[]  =   "10";
#else /* ? FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */
        int                     arg2    =   10;
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

        sink.clear();
        fmtln(sink, fmt0, arg0);

        sink.clear();
        fmtln(sink, fmt1, arg1);

        sink.clear();
        fmtln(sink, fmt2, arg0, arg1);

        sink.clear();
        fmtln(sink, fmt3, arg2, arg0);
    }

#ifdef __AFX_H__
    // Case 4:
    //
    // - sink:      CString
    // - format:    stlsoft::simple_string
    // - arguments: C-style string, CString, int
    {
        CString                 sink;

        stlsoft::simple_string  fmt0("A c-style string: {0}");
        stlsoft::simple_string  fmt1("A stlsoft::simple_string: {0}");
        stlsoft::simple_string  fmt2("A c-style string: {0}, and a stlsoft::simple_string: {1}");
        stlsoft::simple_string  fmt3("A c-style string: {1}, and an int: {0}");

        char const*             arg0    =   "arg0";
        CString                 arg1    =   "arg1";
#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
        char                    arg2[]  =   "10";
#else /* ? FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */
        int                     arg2    =   10;
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

        sink.Empty();
        fmt(sink, fmt0, arg0);

        sink.Empty();
        fmt(sink, fmt1, arg1);

        sink.Empty();
        fmt(sink, fmt2, arg0, arg1);

        sink.Empty();
        fmt(sink, fmt3, arg2, arg0);
    }
#endif /* __AFX_H__ */

#ifdef PLATFORMSTL_OS_IS_WINDOWS
    // Case 5:
    //
    // - sink:      std::cout
    // - format:    VARIANT
    // - arguments: C-style string, VARIANT, unsigned short
    {
        std::ostream&           sink = std::cout;

        comstl::variant         fmt0( "A c-style string: {0}");
        comstl::variant         fmt1(L"A VARIANT: {0}");
        comstl::variant         fmt2( "A c-style string: {0}, and a VARIANT: {1}");
        comstl::variant         fmt3(L"A c-style string: {1}, and an unsigned short: {0}");

        char const*             arg0    =   "arg0";
        comstl::variant         arg1    =   "arg1";
#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
        char                    arg2[]  =   "10";
#else /* ? FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */
        unsigned short          arg2    =   10;
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

        fmt(sink, fmt0, arg0);

        fmt(sink, fmt1, arg1);

        fmt(sink, fmt2, arg0, arg1);

        fmt(sink, fmt3, arg2, arg0);
    }
#endif /* OS */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    try
    {
#ifdef PLATFORMSTL_OS_IS_WINDOWS
        comstl::com_initialiser coinit;
#endif /* OS */

        return main_(argc, argv);
    }
    catch(std::exception& x)
    {
        cerr << "Unhandled error: " << x.what() << endl;
    }
    catch(...)
    {
        cerr << "Unhandled unknown error" << endl;
    }

    return EXIT_FAILURE;
}

/* ////////////////////////////////////////////////////////////////////// */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

# if defined(_DEBUG) && \
     defined(STLSOFT_COMPILER_IS_MSVC)

  /* These are just included to verify that the NO_NAMESPACE stuff works */

#  include <fastformat/sinks/auto_buffer.hpp>
#  include <fastformat/sinks/c_string.hpp>
#  include <fastformat/sinks/char_buffer.hpp>
#  ifdef __AFX_H__
#   include <fastformat/sinks/CString.hpp>
#  endif /* __AFX_H__ */
#  include <fastformat/sinks/FILE.hpp>
#  include <fastformat/sinks/ostream.hpp>
#  if defined(WIN32) || \
      defined(WIN64)
#   include <fastformat/sinks/CComBSTR.hpp>
#   include <fastformat/sinks/speech.hpp>
#  endif /* Windows */
//#  include <fastformat/sinks/string_array.hpp>
#  include <fastformat/sinks/stringstream.hpp>
#  if _MSC_VER == 1200 && \
      defined(UNIX)
#   include <fastformat/sinks/vectored_file.hpp>
#  endif /* UNIXem */

# endif /* _DEBUG */

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* ///////////////////////////// end of file //////////////////////////// */
