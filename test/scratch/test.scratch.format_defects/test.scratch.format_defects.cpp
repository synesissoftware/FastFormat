/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.format_defects.cpp
 *
 * Purpose:     Implementation file for the test.scratch.format_defects project.
 *
 * Created:     1st June 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */



#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* FastFormat header files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>
#include <fastformat/format/specification_defect_handling/ignore_missing_arguments_scope.hpp>
#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>

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


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    fastformat::fmtln(std::cout, "format with two replacements; #1={0}, #2={1}", 10, 200);

    try
    {
        fastformat::fmtln(std::cout, "{0,", 10);
    }
    catch(fastformat::illformed_format_exception& x)
    {
        fprintf(stdout, "illformed_format_exception: %s\n", x.what());
    }
    catch(fastformat::format_parsing_exception& x)
    {
        fprintf(stdout, "format_parsing_exception: %s\n", x.what());
    }
    catch(fastformat::missing_argument_exception& x)
    {
        fprintf(stdout, "missing_argument_exception: %s\n", x.what());
    }
    catch(fastformat::unreferenced_argument_exception& x)
    {
        fprintf(stdout, "unreferenced_argument_exception: %s\n", x.what());
    }
    catch(fastformat::mismatched_replacements_exception& x)
    {
        fprintf(stdout, "mismatched_replacements_exception: %s\n", x.what());
    }

    try
    {
        fastformat::fmtln(std::cout, "format string with no replacements", 10, 200);
    }
    catch(fastformat::fastformat_exception& x)
    {
        fprintf(stdout, "exception: %s\n", x.what());
    }

    try
    {
        fastformat::ignore_unreferenced_arguments_scope scoper;

        fastformat::fmtln(std::cout, "format string with no replacements", 10, 200);
    }
    catch(fastformat::fastformat_exception& x)
    {
        fprintf(stdout, "exception: %s\n", x.what());
    }

    try
    {
        fastformat::fmtln(std::cout, "{0,,,}{1,,,}", 10, 200);
    }
    catch(fastformat::fastformat_exception& x)
    {
        fprintf(stdout, "exception: %s\n", x.what());
    }


    try
    {
        fastformat::ignore_missing_arguments_scope scoper;

        std::string str;

        fastformat::fmt(str, "format string with no replacements {0} {1}", 10);

        STLSOFT_ASSERT("format string with no replacements 10 " == str);
    }
    catch(fastformat::fastformat_exception& x)
    {
        fprintf(stdout, "exception: %s\n", x.what());
    }


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

