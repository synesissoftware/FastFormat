/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.inserter.real.cpp
 *
 * Purpose:     Implementation file for the test.scratch.inserter.real project.
 *
 * Created:     1st March 2009
 * Updated:     22nd September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/inserters/real.hpp>
#include <fastformat/inserters/to_e.hpp>
#include <fastformat/inserters/to_f.hpp>
#include <fastformat/inserters/to_g.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* UNIXem header files */
#if defined(_WIN32) || \
    defined(_WIN64)
# include <unixem/unixem.h>
#endif /* Win32 || Win64 */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    const double    values[] =
    {
            0.0
        ,   -12.34
        ,   +12.34
        ,   -12345.12345
        ,   +12345.12345
        ,   -12.34e-5
        ,   +12.34e+5
    };

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        puts("");
        printf("%%f:     [%f]\n", values[i]);
        printf("%%20f:   [%20f]\n", values[i]);
        printf("%%20.8f: [%20.8f]\n", values[i]);
        printf("%%20.4f: [%20.4f]\n", values[i]);
        printf("%%15f:   [%15f]\n", values[i]);
        printf("%%15.8f: [%15.8f]\n", values[i]);
        printf("%%15.4f: [%15.4f]\n", values[i]);
        printf("%%10f:   [%10f]\n", values[i]);
        printf("%%10.8f: [%10.8f]\n", values[i]);
        printf("%%10.4f: [%10.4f]\n", values[i]);
        printf("%%6f:    [%6f]\n", values[i]);
        printf("%%6.8f:  [%6.8f]\n", values[i]);
        printf("%%6.4f:  [%6.4f]\n", values[i]);
        printf("%%5f:    [%5f]\n", values[i]);
        printf("%%5.8f:  [%5.8f]\n", values[i]);
        printf("%%5.4f:  [%5.4f]\n", values[i]);
    
        printf("%%.5f:   [%.5f]\n", values[i]);
    }}

//    printf("[%-14.3f%-14.3f]\n", 12345.12345, 12345.12345); // => [12345.123     12345.123     ]

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const double    value = values[i];

        // ff::real

        ff::writeln(std::cout, "ff::real");
        ff::fmtln(std::cout, "[{0} {0}]", ff::real(value));
        ff::fmtln(std::cout, "[{0} {0}]", ff::real(value, 14, 3));
        ff::fmtln(std::cout, "[{0} {0}]", ff::real(value, -14, 3));

        // ff::to_f

        ff::writeln(std::cout, "ff::to_f");
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_f(value));
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_f(value, 14, 3));
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_f(value, -14, 3));

        // ff::to_g

        ff::writeln(std::cout, "ff::to_g");
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_g(value));
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_g(value, 14, 3));
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_g(value, -14, 3));

        // ff::to_e

        ff::writeln(std::cout, "ff::to_e");
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_e(value));
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_e(value, 14, 3));
        ff::fmtln(std::cout, "[{0} {0}]", ff::to_e(value, -14, 3));

        ff::writeln(std::cout, "");
        ff::writeln(std::cout, "");
    }}

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
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.inserter.real: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;

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

/* ///////////////////////////// end of file //////////////////////////// */
