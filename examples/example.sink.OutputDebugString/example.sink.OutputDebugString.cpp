/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.sink.OutputDebugString/example.sink.OutputDebugString.cpp
 *
 * Purpose:     Implementation file for the example.sink.OutputDebugString project.
 *
 * Created:     19th April 2009
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


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/OutputDebugString.hpp>
#include <fastformat/ff.hpp>

/* STLSoft Header Files */

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /* argv */)
{
    ff::sinks::OutputDebugString_sink   sink;

#ifdef FASTFORMAT_USE_WIDE_STRINGS

    ff::fmtln(sink, L"Hello, {0}{1}", L"Debugger", L"!");

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

    ff::fmtln(sink, "Hello, {0}{1}", "Debugger", "!");

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
        fprintf(stderr, "exception: %s\n", x.what());
    }
    catch(...)
    {
        fprintf(stderr, "unhandled unknown error");
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
