/* /////////////////////////////////////////////////////////////////////////
 * File:        example.inserter.reals.cpp
 *
 * Purpose:     Implementation file for the example.inserter.reals project.
 *
 * Created:     2nd June 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#include <fastformat/fastformat.h>
#include <fastformat/inserters/to_e.hpp>
#include <fastformat/inserters/to_g.hpp>
#include <fastformat/inserters/to_f.hpp>
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

    ff::fmtln(stm, L"e={0}; f={1}; g={2}", ff::to_e(+12345.6789), ff::to_f(+12345.6789), ff::to_g(+12345.6789));
    ff::writeln(stm, L"e=", ff::to_e(-12345.6789), L"; f=", ff::to_f(-12345.6789), L"; g=", ff::to_g(-12345.6789));

#else /* ? FASTFORMAT_USE_WIDE_STRINGS */

# define    stm     std::cout

    ff::fmtln(stm, "e={0}; f={1}; g={2}", ff::to_e(+12345.6789), ff::to_f(+12345.6789), ff::to_g(+12345.6789));
    ff::writeln(stm, "e=", ff::to_e(-12345.6789), "; f=", ff::to_f(-12345.6789), "; g=", ff::to_g(-12345.6789));

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

