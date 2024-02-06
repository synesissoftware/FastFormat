/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.ff_101/example.ff_101.cpp
 *
 * Purpose:     Implementation file for the example.ff_101 project.
 *
 * Created:     2nd June 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


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
#include <stdio.h>
#include <stdlib.h>


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    // Case 1:
    puts("Case 1");
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
        fastformat::fmt(sink, "A c-style string: {0}", arg0);

        sink.erase();
        fastformat::fmt(sink, "A std::string: {0}", arg1);

        sink.erase();
        fastformat::fmt(sink, "A c-style string: {0}, and a std::string: {1}", arg0, arg1);

        sink.erase();
        fastformat::fmt(sink, "A c-style string: {1}, and an int: {0}", arg2, arg0);
    }

    // Case 2:
    puts("Case 2");
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
        fastformat::fmt(sink, fmt0, arg0);

        sink.clear();
        fastformat::fmt(sink, fmt1, arg1);

        sink.clear();
        fastformat::fmt(sink, fmt2, arg0, arg1);

        sink.clear();
        fastformat::fmt(sink, fmt3, arg2, arg0);
    }

    // Case 3:
    puts("Case 3");
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
        fastformat::fmtln(sink, fmt0, arg0);

        sink.clear();
        fastformat::fmtln(sink, fmt1, arg1);

        sink.clear();
        fastformat::fmtln(sink, fmt2, arg0, arg1);

        sink.clear();
        fastformat::fmtln(sink, fmt3, arg2, arg0);
    }

#ifdef __AFX_H__
    // Case 4:
    puts("Case 4");
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
        fastformat::fmt(sink, fmt0, arg0);

        sink.Empty();
        fastformat::fmt(sink, fmt1, arg1);

        sink.Empty();
        fastformat::fmt(sink, fmt2, arg0, arg1);

        sink.Empty();
        fastformat::fmt(sink, fmt3, arg2, arg0);
    }
#endif /* __AFX_H__ */

#ifdef PLATFORMSTL_OS_IS_WINDOWS
    // Case 5:
    puts("Case 5");
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

        fastformat::fmtln(sink, fmt0, arg0);

        fastformat::fmtln(sink, fmt1, arg1);

        fastformat::fmtln(sink, fmt2, arg0, arg1);

        fastformat::fmtln(sink, fmt3, arg2, arg0);
    }
#endif /* OS */

#ifndef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
    // Case 6: bad formats(s)
    puts("Case 6");
    //
    // - 
    puts("Case 6.1");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: {", number1, number2);
    }
    catch(fastformat::illformed_format_exception& x)
    {
        fastformat::writeln(std::cerr, "error: ", x, "; format=\"", x.format, "\"");
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }

    puts("Case 6.2");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: {1", number1, number2);
    }
    catch(fastformat::illformed_format_exception& x)
    {
        fastformat::writeln(std::cerr, "error: ", x, "; format=\"", x.format, "\"");
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }

    puts("Case 6.3");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: {1{", number1, number2);
    }
    catch(fastformat::illformed_format_exception& x)
    {
        fastformat::writeln(std::cerr, "error: ", x, "; format=\"", x.format, "\"");
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }

    puts("Case 6.4");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: {1:20-100}", number1, number2);
    }
    catch(fastformat::illformed_format_exception& x)
    {
        fastformat::writeln(std::cerr, "error: ", x, "; format=\"", x.format, "\"");
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }

    puts("Case 6.5");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: {1}", number1);

        STLSOFT_SUPPRESS_UNUSED(number2);
    }
    catch(fastformat::missing_argument_exception& x)
    {
        fastformat::fmtln(std::cerr, "error: {0}; arg {1} out of {2}", x, x.firstMismatchedReplacementIndex, x.numberOfReplacements);
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }

# ifdef FASTFORMAT_DETECT_UNREFERENCED_ARGUMENTS
    puts("Case 6.6");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: 1}", number1, number2);
    }
    catch(fastformat::unreferenced_argument_exception& x)
    {
        fastformat::fmtln(std::cerr, "error: {0}; arg {1} out of {2}", x, x.firstMismatchedReplacementIndex, x.numberOfReplacements);
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }

    puts("Case 6.7");
    try
    {
        int number1 = 1;
        int number2 = 2;

        fastformat::fmtln(std::cout, "number1: {{{0}}; number2: {}1", number1, number2);
    }
    catch(fastformat::unreferenced_argument_exception& x)
    {
        fastformat::writeln(std::cerr, "error: ", x);
    }
    catch(std::exception&)
    {
        fastformat::writeln(std::cerr, "Ooops!");
    }
# endif /* FASTFORMAT_DETECT_UNREFERENCED_ARGUMENTS */
#endif /* !FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

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


/* ///////////////////////////// end of file //////////////////////////// */

