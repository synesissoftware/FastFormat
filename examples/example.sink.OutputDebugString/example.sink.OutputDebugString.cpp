/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.sink.OutputDebugString/example.sink.OutputDebugString.cpp
 *
 * Purpose:     Implementation file for the example.sink.OutputDebugString project.
 *
 * Created:     19th April 2009
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* FastFormat header files */
#include <fastformat/sinks/OutputDebugString.hpp>
#include <fastformat/ff.hpp>

/* STLSoft header files */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
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

