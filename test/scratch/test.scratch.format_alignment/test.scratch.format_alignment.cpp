/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.format_alignment.cpp
 *
 * Purpose:     Implementation file for the test.scratch.format_alignment project.
 *
 * Created:     1st June 2008
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#define FASTFORMAT_NO_USE_JIT_CACHE


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

/* STLSoft Header Files */
#include <platformstl/platformstl.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

#if 0
typedef std::string     string_t;
#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{

#if 1
    {
ff::fmtln(std::cout, "x={0}; y={0};", "abc");
ff::fmtln(std::cout, "x={0}; y={0,10};", "abc");
ff::fmtln(std::cout, "x={0}; y={0,10,,>};", "abc");
ff::fmtln(std::cout, "x={0}; y={0,10,,<};", "abc");
ff::fmtln(std::cout, "x={0}; y={0,10,,^};", "abc");
ff::fmtln(std::cout, "x={0}; y={0,,2};", "abc");
ff::fmtln(std::cout, "x={0}; y={0,,2,<};", "abc");
    }
#else /* ? 0 */

    int             i   =   -3;
    std::string     s   =   "abcdefghi";

    ff::fmtln(std::cout, "i={0}; s={1};", i, s);

    ff::fmtln(std::cout, "i={0}; s={1,,5};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,,5,>};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,,5,<};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,,5,^};", i, s);

    ff::fmtln(std::cout, "i={0}; s={1,12,20};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,12,20,>};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,12,20,<};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,12,20,^};", i, s);
    ff::fmtln(std::cout, "i={0}; s={1,5,20,<};", i, s);

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
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.format_alignment: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

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
