/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.sink.c_string/example.sink.c_string.cpp
 *
 * Purpose:     Implementation file for the example.sink.c_string project.
 *
 * Created:     17th May 2009
 * Updated:     11th December 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/c_string.hpp>
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
 * Compatibility
 */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /* argv */)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

    char const* arg0    =   "abcdefghi";
    const char  arg1[]  =            "jklmnopq";
    std::string arg2    =                    "rstuvwxyz";

    {
        char    buff[30];

        ff::sinks::c_string_sink   sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);

        ff::write(sink, arg0);

        STLSOFT_ASSERT(9u == sink.size());

        ff::write(sink, arg1);

        STLSOFT_ASSERT(17u == sink.size());

        ff::write(sink, arg2);

        STLSOFT_ASSERT(26u == sink.size());

        STLSOFT_ASSERT(0 == ::strcmp("abcdefghijklmnopqrstuvwxyz", buff));
    }

    try
    {
        char    buff[20];

        ff::sinks::c_string_sink   sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);

        ff::write(sink, arg0);

        STLSOFT_ASSERT(9u == sink.size());

        ff::write(sink, arg1);

        STLSOFT_ASSERT(17u == sink.size());

        ff::write(sink, arg2); // Teleport to ... 

        STLSOFT_MESSAGE_ASSERT("should never get here", 0);
    }
    catch(std::out_of_range& /* x */)
    {
        // ... here!
    }

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
