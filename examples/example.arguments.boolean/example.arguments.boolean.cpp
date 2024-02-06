/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.arguments.boolean/example.arguments.boolean.cpp
 *
 * Purpose:     Implementation file for the example.arguments.boolean project.
 *
 * Created:     2nd June 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#include <fastformat/fastformat.h>
#include <fastformat/shims/conversion/filter_type/bool.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/fastformat.hpp>

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

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
# error Cannot compile this file with a compiler that does not support the filter_type mechanism
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define    stm     std::wcout
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define    stm     std::cout
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

    const bool  True    =   true;
    const bool  False   =   false;

    fastformat::fmtln(stm, FASTFORMAT_LITERAL_STRING("True={0}"), True);
    fastformat::fmtln(stm, FASTFORMAT_LITERAL_STRING("False={0}"), False);

    fastformat::writeln(stm, FASTFORMAT_LITERAL_STRING("True="), True);
    fastformat::writeln(stm, FASTFORMAT_LITERAL_STRING("False="), False);

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

