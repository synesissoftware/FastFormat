/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.arguments.void_pointers/example.arguments.void_pointers.cpp
 *
 * Purpose:     Implementation file for the example.arguments.void_pointers project.
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


/* FastFormat header files */
#define FASTFORMAT_USE_VOID_POINTERS_CONVERSION_SHIMS
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/fastformat.hpp>

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
    void*                   p   =   &p;
    void const*             pc  =   &pc;
    void volatile*          pv  =   &pv;
    void const volatile*    pcv =   &pcv;

#ifdef FASTFORMAT_USE_WIDE_STRINGS

    // Wide string

    fastformat::fmtln(std::wcout, L"a void* pointer: {0}", p);
    fastformat::fmtln(std::wcout, L"a void const* pointer: {0}", pc);
    fastformat::fmtln(std::wcout, L"a void volatile* pointer: {0}", pv);
    fastformat::fmtln(std::wcout, L"a void const volatile* pointer: {0}", pcv);

    fastformat::writeln(std::wcout, L"a void* pointer: ", p);
    fastformat::writeln(std::wcout, L"a void const* pointer: ", pc);
    fastformat::writeln(std::wcout, L"a void volatile* pointer: ", pv);
    fastformat::writeln(std::wcout, L"a void const volatile* pointer: ", pcv);

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

    // Multibyte string

    fastformat::fmtln(std::cout, "a void* pointer: {0}", p);
    fastformat::fmtln(std::cout, "a void const* pointer: {0}", pc);
    fastformat::fmtln(std::cout, "a void volatile* pointer: {0}", pv);
    fastformat::fmtln(std::cout, "a void const volatile* pointer: {0}", pcv);

    fastformat::writeln(std::cout, "a void* pointer: ", p);
    fastformat::writeln(std::cout, "a void const* pointer: ", pc);
    fastformat::writeln(std::cout, "a void volatile* pointer: ", pv);
    fastformat::writeln(std::cout, "a void const volatile* pointer: ", pcv);

#endif /* FASTFORMAT_USE_WIDE_STRINGS */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    try
    {
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
