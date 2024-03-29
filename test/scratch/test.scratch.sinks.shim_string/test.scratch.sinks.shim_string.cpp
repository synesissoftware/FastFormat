/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.sinks.shim_string.cpp
 *
 * Purpose:     Implementation file for the test.scratch.sinks.shim_string project.
 *
 * Created:     12th November 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#include <fastformat/sinks/shim_string.hpp>
#include <fastformat/fastformat.hpp>

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
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

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

class Person
{
public: /// Member Types
  typedef std::string   string_type;
public: /// Construction
    Person(string_type const& forename, string_type const& surname, int age)
        : forename(forename)
        , surname(surname)
        , age(age)
    {}

public: /// Member Variables
    const string_type   forename;
    const string_type   surname;
    const int           age;
};


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    fastformat::sinks::shim_string_sink str(0u);

    str.reserve(100);

    str.append("abcdefghijlkmnopqrstuvwxyz");
    str.append("ABCDEFGHIJLKMNOPQRSTUVWXYZ");
    str.append("abcdefghijlkmnopqrstuvwxyz");
    str.append("ABCDEFGHIJLKMNOPQRSTUVWXYZ");

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
        puts("test.scratch.sinks.shim_string: " __STLSOFT_COMPILER_LABEL_STRING);
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

