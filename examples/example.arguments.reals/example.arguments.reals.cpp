/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.arguments.reals/example.arguments.reals.cpp
 *
 * Purpose:     Implementation file for the example.arguments.reals project.
 *
 * Created:     2nd June 2008
 * Updated:     5th February 2017
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/shims/conversion/filter_type/reals.hpp>
#include <fastformat/fastformat.hpp>

#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
# error Cannot compile this file with a compiler that does not support the filter_type mechanism
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

/* STLSoft Header Files */

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** /*argv*/)
{
    const float     flt =   1.2345f;
    const double    dbl =   -123E-45;

#ifdef FASTFORMAT_USE_WIDE_STRINGS

    // Wide string

    fastformat::fmtln(std::wcout, L"a float={0}", flt);
    fastformat::fmtln(std::wcout, L"a double={0}", dbl);

    fastformat::writeln(std::wcout, L"a float=", flt);
    fastformat::writeln(std::wcout, L"a double=", dbl);

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

    // Multibyte string

    fastformat::fmtln(std::cout, "a float={0}", flt);
    fastformat::fmtln(std::cout, "a double={0}", dbl);

    fastformat::writeln(std::cout, "a float=", flt);
    fastformat::writeln(std::cout, "a double=", dbl);

#endif /* FASTFORMAT_USE_WIDE_STRINGS */



#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
    // This code just to ensure widestring compatibility for integral types
    if(0 == argc)
    {
        const int       i   =   -123;
    
# ifdef FASTFORMAT_USE_WIDE_STRINGS
        fastformat::fmtln(std::wcout, L"an integer={0}", i);
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
        fastformat::fmtln(std::cout, "an integer={0}", i);
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
    }
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

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
