/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.inserter.integer.cpp
 *
 * Purpose:     Implementation file for the test.scratch.inserter.integer project.
 *
 * Created:     1st March 2009
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/inserters/integer.hpp>
#include <fastformat/inserters/to_i.hpp>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* UNIXem Header Files */
#if defined(_WIN32) || \
    defined(_WIN64)
# include <unixem/unixem.h>
#endif /* Win32 || Win64 */

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

/* Standard C Header Files */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    const int values[] =
    {
            0
        ,   -1
        ,   +1
        ,   -12
        ,   +12
        ,   -123
        ,   +123
        ,   -1234
        ,   +1234
        ,   -12345
        ,   +12345
        ,   INT_MIN
        ,   INT_MAX
    };

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(values); ++i)
    {
        const int value = values[i];

        puts("printf()");
        printf("%%d:       [%d]\n", value);
        printf("%%.5d:     [%.5d]\n", value);
        printf("%%20d:     [%20d]\n", value);
        printf("%%20.5d:   [%20.5d]\n", value);
        printf("%%20.20d:  [%20.20d]\n", value);
        printf("%%-.5d:    [%-.5d]\n", value);
        printf("%%-20d:    [%-20d]\n", value);
        printf("%%-20.5d:  [%-20.5d]\n", value);
        printf("%%-20.20d: [%-20.20d]\n", value);
#if 0
        printf("%% 20d:    [% 20d]\n", value);
        printf("%%20.0d:   [%20.0d]\n", value);
        printf("%%20.1d:   [%20.1d]\n", value);
#endif /* 0 */
#if 0
        printf("%%020d:    [%020d]\n", value);
        printf("%%020.5d:  [%020.5d]\n", value);
#endif /* 0 */
        puts("");

        // ff::integer

#if 0
        ff::writeln(std::cout, "ff::integer");
        ff::fmtln(std::cout, "[{0}]", ff::integer(value, 0));
        ff::fmtln(std::cout, "[{0}]", ff::integer(value, 14, 3));
        ff::fmtln(std::cout, "[{0}]", ff::integer(value, -14, 3));
#endif /* 0 */

        // ff::to_i

        ff::writeln(std::cout, "ff::to_i");
        ff::fmtln(std::cout, "%d:       [{0}]", ff::to_i(value));
        ff::fmtln(std::cout, "%.5d:     [{0}]", ff::to_i(value, 0, 5));
        ff::fmtln(std::cout, "%20d:     [{0}]", ff::to_i(value, 20));
        ff::fmtln(std::cout, "%20.5d:   [{0}]", ff::to_i(value, 20, 5));
        ff::fmtln(std::cout, "%20.20d:  [{0}]", ff::to_i(value, 20, 20));
        ff::fmtln(std::cout, "%-.5d:    [{0}]", ff::to_i(value, -0, 5));
        ff::fmtln(std::cout, "%-20d:    [{0}]", ff::to_i(value, -20));
        ff::fmtln(std::cout, "%-20.5d:  [{0}]", ff::to_i(value, -20, 5));
        ff::fmtln(std::cout, "%-20.20d: [{0}]", ff::to_i(value, -20, 20));

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
        puts("test.scratch.inserter.integer: " __STLSOFT_COMPILER_LABEL_STRING);
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
