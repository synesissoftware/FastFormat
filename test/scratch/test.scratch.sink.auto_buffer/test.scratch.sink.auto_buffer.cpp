/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.sink.auto_buffer.cpp
 *
 * Purpose:     Implementation file for the test.component.sink.auto_buffer project.
 *
 * Created:     21st April 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#define FASTFORMAT_NO_IMPLICIT_ACTION_SHIMS // VC++ 6 can't distinguish the auto_buffer action shim from the generic string one
#include <fastformat/sinks/auto_buffer.hpp>
#include <fastformat/ff.hpp>

/* shwild header files */
#include <shwild/shwild.hpp>

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.hpp>


/* Standard C++ header files */
#include <exception>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

#if !defined(__WATCOMC__) && \
    (   !defined(_MSC_VER) || \
        _MSC_VER >= 1100)

#else /* ? __WATCOMC__ */
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */

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

#if 0
typedef std::string     string_t;
#endif /* 0 */


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    stlsoft::auto_buffer<char>          buff1(1);
    stlsoft::auto_buffer<char, 100>     buff2(1);

    ff::fmt(buff1, "{0}{1}{0}", "abc", "---");

    ff::fmt(buff2, "{0}{1}{0}", "abc", "---");

    ff::write(buff2, "xyz", "MNO");

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
    catch(std::exception &x)
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

