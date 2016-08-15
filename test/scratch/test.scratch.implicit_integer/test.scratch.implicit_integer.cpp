/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.implicit_integer.cpp
 *
 * Purpose:     Implementation file for the test.scratch.implicit_integer project.
 *
 * Created:     1st June 2008
 * Updated:     26th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

/* STLSoft header files */
#include <platformstl/platformstl.hpp>

/* Standard C++ header files */
#include <exception>
#include <iostream>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Macros and definitions
 */


/* /////////////////////////////////////////////////////////////////////////
 * Globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef std::string     string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * Filters
 */

namespace fastformat
{
    namespace filters
    {

        inline std::string filter_type(double t, double const*, char const volatile*)
        {
            char    num[100];
            int     n = ::sprintf(&num[0], "%G", t);

            if(n < 0)
            {
                n = 0;
            }

            return std::string(num, n);
        }

        inline std::string filter_type(float t, float const*, char const volatile*)
        {
            double t2 = t;

            return filter_type(t2, &t2, static_cast<char const volatile*>(0));
        }

    } // namespace filters

} // namespace fastformat

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    ff::writeln(std::cout, "1", " + ", "2", " = ", "3");

    ff::writeln(std::cout, 1, " + ", 2, " = ", 3);

    ff::fmtln(std::cout, "{0} + {1} = {2}", "1", "2", "3");

    ff::fmtln(std::cout, "{0} + {1} = {2}", 1, 2, 3);

    short   s   =   -10;
    int     i   =   -11;
    long    l   =   -12;
    float   f   =   static_cast<float>(-10.10);
    double  d   =   -20.20;

    ff::writeln(std::cout, "s = ", s);
    ff::writeln(std::cout, "i = ", i);
    ff::writeln(std::cout, "l = ", l);
    ff::writeln(std::cout, "f = ", f);
    ff::writeln(std::cout, "d = ", d);

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

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.implicit_integer: " __STLSOFT_COMPILER_LABEL_STRING);
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
