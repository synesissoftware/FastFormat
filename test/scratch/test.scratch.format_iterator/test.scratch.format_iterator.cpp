/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.format_iterator.cpp
 *
 * Purpose:     Implementation file for the test.scratch.format_iterator project.
 *
 * Created:     20th May 2009
 * Updated:     22nd September 2015
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
#include <fastformat/ff.hpp>
#include <fastformat/iterators/format_iterator.hpp>
#include <fastformat/sinks/FILE.hpp>
#include <fastformat/sinks/ostream.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.hpp>

/* UNIXem header files */
#if defined(_WIN32) || \
    defined(_WIN64)
# include <unixem/unixem.h>
#endif /* Win32 || Win64 */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>
#include <vector>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

typedef std::string             string_t;
typedef std::vector<string_t>   strings_t;

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    strings_t   strings;

    strings.push_back("abc");
    strings.push_back("def");
    strings.push_back("ghi");

    std::cout << "with std::ostream_iterator:\n";
    std::copy(  strings.begin(), strings.end()
            ,   std::ostream_iterator<string_t>(std::cout, "\n"));
    std::cout << "\n";


    std::cout << "with fastformat::format_iterator (with std::cout):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(std::cout, "\t{0}\n"));
    std::cout << "\n";


    FILE* stm = stdout;
    std::cout << "with fastformat::format_iterator (with stdout):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{0}\n"));
    std::cout << "\n";


    std::cout << "with fastformat::format_iterator (std::cout): 1 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{1}{0}\n", "*"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 2 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{1}{0}{2}\n", "{", "}"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 3 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{3}{1}{0}{2}\n", "{", "}", "*"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 4 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{3}{1}{0}{2}{4}\n", "{", "}", "*", "+"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 5 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{1}{0}{2}\t{5}{3}{0}{4}\n", "{", "}", "[", "]", "*"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 6 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{6}{1}{0}{2}\t{5}{3}{0}{4}\n", "{", "}", "[", "]", "*", "+"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 7 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{1}{0}{2}\t{3}{0}{4}\t{5}{0}{6}\t{7}\n", "{", "}", "[", "]", "<", ">", "*"));
    std::cout << "\n";

    std::cout << "with fastformat::format_iterator (std::cout): 8 arg(s):\n";
    std::copy(  strings.begin(), strings.end()
            ,   fastformat::format_iterator(stm, "\t{1}{0}{2}\t{3}{0}{4}\t{5}{0}{6}\t{7}{0}{8}\n", "{", "}", "[", "]", "<", ">", "(", ")"));
    std::cout << "\n";


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
        puts("test.scratch.format_iterator: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
