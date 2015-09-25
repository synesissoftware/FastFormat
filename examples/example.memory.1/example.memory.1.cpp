/* /////////////////////////////////////////////////////////////////////////
 * File:        example.memory.1.cpp
 *
 * Purpose:     Implementation file for the example.memory.1 project.
 *
 * Created:     20th September 2008
 * Updated:     25th September 2015
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


#define FASTFORMAT_NO_USE_JIT_CACHE

/* FastFormat header files */
#include <fastformat/sinks/c_string.hpp>
#include <fastformat/sinks/char_buffer.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/fastformat.hpp>

/* STLSoft header files */
#include <platformstl/synch/atomic_functions.h>

/* Boost header files */
#include <boost/format.hpp>


/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <sstream>
#include <new>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Memory functions
 */

platformstl::atomic_int_t   scalar_count;
platformstl::atomic_int_t   vector_count;

void* operator new(size_t cb)
{
    platformstl::atomic_increment(&scalar_count);

    return ::malloc(cb);
}

void operator delete(void* pv)
{
    ::free(pv);
}

void* operator new[](size_t cb)
{
    platformstl::atomic_increment(&vector_count);

    return ::malloc(cb);
}

void operator delete[](void* pv)
{
    ::free(pv);
}

/* /////////////////////////////////////////////////////////////////////////
 * Test functions
 */

static void test_1()
{
    char        fastfmt[] = "FastFormat";
    long        year = 2008;
    std::string result_Boost;
    std::string result_IOStreams;
    std::string result_FastFormat;

    { // Boost

        long    s = -1;
        long    v = -1;

        { for(size_t i = 0; i != 2; ++i)
        {
            const platformstl::atomic_int_t spre = scalar_count;
            const platformstl::atomic_int_t vpre = vector_count;

            result_Boost = boost::str(boost::format("Releasing %1% in %2%? The answer is %3%") % fastfmt % year % "yes");

            const platformstl::atomic_int_t spost = scalar_count;
            const platformstl::atomic_int_t vpost = vector_count;

            s = long(spost - spre);
            v = long(vpost - vpre);
        }}

        fastformat::fmtln(std::cout, "Boost #allocs:\t{0}\t{1}", s, v);
    }

    { // IOStreams

        long    s = -1;
        long    v = -1;

        { for(size_t i = 0; i != 2; ++i)
        {
            const platformstl::atomic_int_t spre = scalar_count;
            const platformstl::atomic_int_t vpre = vector_count;

            std::stringstream   ss;

            ss << "Releasing " << fastfmt << " in " << year << "? The answer is " << "yes";

            result_IOStreams = ss.str();

            const platformstl::atomic_int_t spost = scalar_count;
            const platformstl::atomic_int_t vpost = vector_count;

            s = long(spost - spre);
            v = long(vpost - vpre);
        }}

        fastformat::fmtln(std::cout, "IOStreams #allocs:\t{0}\t{1}", s, v);
    }

    { // fmt() API

        long    s = -1;
        long    v = -1;

        { for(size_t i = 0; i != 2; ++i)
        {
            const platformstl::atomic_int_t spre = scalar_count;
            const platformstl::atomic_int_t vpre = vector_count;

            fastformat::fmt(result_FastFormat, "Releasing {0} in {1}? The answer is {2}", fastfmt, year, "yes");

            const platformstl::atomic_int_t spost = scalar_count;
            const platformstl::atomic_int_t vpost = vector_count;

            s = long(spost - spre);
            v = long(vpost - vpre);
        }}

        fastformat::fmtln(std::cout, "FastFormat #allocs:\t{0}\t{1}", s, v);
    }
}

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    test_1();

#if 0
    { // fmt() API

        std::string sink;
        char        fastfmt[] = "FastFormat";
        long        year = 2008;

        const platformstl::atomic_int_t spre = scalar_count;
        const platformstl::atomic_int_t vpre = vector_count;

        fastformat::fmt(sink, "Releasing {0} in {1}? Yes, it's {2} {3}", fastfmt, year, "already", "here");

        const platformstl::atomic_int_t spost = scalar_count;
        const platformstl::atomic_int_t vpost = vector_count;

        fastformat::fmtln(std::cout, "#allocs:\t{0}\t{1}", long(spost - spre), long(vpost - vpre));
    }

    { // fmt() API

        char                        buff[100];
        fastformat::c_string_sink   sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
        std::string                 fastfmt = "FastFormat";
        long                        year = 2008;

        const platformstl::atomic_int_t spre = scalar_count;
        const platformstl::atomic_int_t vpre = vector_count;

        fastformat::fmt(sink, "Releasing {0} in {1}?", fastfmt, year);

        const platformstl::atomic_int_t spost = scalar_count;
        const platformstl::atomic_int_t vpost = vector_count;

        fastformat::fmtln(std::cout, "#allocs:\t{0}\t{1}", long(spost - spre), long(vpost - vpre));
    }

    { // fmt() API

        char                            buff[100];
        fastformat::char_buffer_sink    sink(STLSOFT_NUM_ELEMENTS(buff), &buff[0]);
        std::string                     fastfmt = "FastFormat";
        long                            year = 2008;

        const platformstl::atomic_int_t spre = scalar_count;
        const platformstl::atomic_int_t vpre = vector_count;

        fastformat::fmt(sink, "Releasing {0} in {1}?", fastfmt, year);

        const platformstl::atomic_int_t spost = scalar_count;
        const platformstl::atomic_int_t vpost = vector_count;

        fastformat::fmtln(std::cout, "#allocs:\t{0}\t{1}", long(spost - spre), long(vpost - vpre));
    }
#endif

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
        puts("example.memory.1: " __STLSOFT_COMPILER_LABEL_STRING);
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
