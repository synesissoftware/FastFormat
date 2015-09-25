/* /////////////////////////////////////////////////////////////////////////
 * File:        example.inserter.integers.cpp
 *
 * Purpose:     Implementation file for the example.inserter.integers project.
 *
 * Created:     26th May 2009
 * Updated:     25th September 2015
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
#include <fastformat/fastformat.h>
#include <fastformat/inserters/to_i.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

/* STLSoft header files */

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
#ifdef FASTFORMAT_USE_WIDE_STRINGS

# define    stm     std::wcout

    ff::fmtln(stm, L"i={0}; j={1}; k={2};", ff::to_i(123456), ff::to_i(123456, -10), ff::to_i(123456, 10));
    ff::writeln(stm, L"i=", ff::to_i(-123456), L"; j=", ff::to_i(-123456, -10), L"; k=", ff::to_i(-123456, 10), L";");

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define    stm     std::cout

    ff::fmtln(stm, "i={0}", ff::to_i(123456));
    ff::fmtln(stm, "i={0}", ff::to_i(123456, 0, 10));
    ff::fmtln(stm, "i={0}", ff::to_i(123456, 0, 100));

    ff::fmtln(stm, "i={0}; j={1}; k={2};", ff::to_i(123456), ff::to_i(123456, -10), ff::to_i(123456, 10));
    ff::writeln(stm, "i=", ff::to_i(-123456), "; j=", ff::to_i(-123456, -10), "; k=", ff::to_i(-123456, 10), ";");

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
