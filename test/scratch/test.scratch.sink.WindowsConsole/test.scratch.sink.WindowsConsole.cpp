/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.sink.WindowsConsole.cpp
 *
 * Purpose:     Implementation file for the test.scratch.sink.WindowsConsole project.
 *
 * Created:     6th January 2011
 * Updated:     25th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/WindowsConsole.hpp>

/* STLSoft header files */
#include <winstl/error/error_desc.hpp>

/* Standard C++ header files */
#include <exception>
#include <iostream>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    /* . */
    ff::writeln(std::cout, "a regular output line");

    ff::writeln(ff::sinks::WindowsConsole(FOREGROUND_RED), "a regular output line");

    ff::writeln(std::cout, "another regular output line");


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
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
