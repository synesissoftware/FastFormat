/* /////////////////////////////////////////////////////////////////////////
 * File:        example.overload.3.floatingpoint_columns.cpp
 *
 * Purpose:     Implementation file for the example.overload.3.floatingpoint_columns
 *              project.
 *
 * Created:     30th April 2009
 * Updated:     8th July 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/fastformat.h>

#include <platformstl/performance/performance_counter.hpp>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

int output_by_streams();
int output_by_iostreams();
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
int output_by_boost_1();
int output_by_boost_2();
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
int output_by_ff_fmt_1();
int output_by_ff_fmt_2();
int output_by_ff_fmt_3();

int main()
{
    platformstl::performance_counter                counter;
    platformstl::performance_counter::interval_type t_streams   =   0;
    platformstl::performance_counter::interval_type t_iostreams =   0;
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
    platformstl::performance_counter::interval_type t_boost_1   =   0;
    platformstl::performance_counter::interval_type t_boost_2   =   0;
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
    platformstl::performance_counter::interval_type t_ff_fmt_1  =   0;
    platformstl::performance_counter::interval_type t_ff_fmt_2  =   0;
    platformstl::performance_counter::interval_type t_ff_fmt_3  =   0;

    { for(int WARMUPS = 3; 0 != WARMUPS; --WARMUPS)
    {
#ifdef _DEBUG
        const int ITERATIONS = 1;
        WARMUPS = 1;
#else /* ? _DEBUG */
        const int ITERATIONS = 10000;
#endif /* _DEBUG */

        puts("Streams:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_streams();
        }}
        counter.stop();
        puts("");
        t_streams = counter.get_microseconds();

        puts("IOStreams:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_iostreams();
        }}
        counter.stop();
        puts("");
        t_iostreams = counter.get_microseconds();

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
        puts("Boost:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_boost_1();
        }}
        counter.stop();
        puts("");
        t_boost_1 = counter.get_microseconds();

        puts("Boost (N):");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_boost_2();
        }}
        counter.stop();
        puts("");
        t_boost_2 = counter.get_microseconds();
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

        puts("FastFormat.Format (1):");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_ff_fmt_1();
        }}
        counter.stop();
        puts("");
        t_ff_fmt_1 = counter.get_microseconds();

        puts("FastFormat.Format (2):");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_ff_fmt_2();
        }}
        counter.stop();
        puts("");
        t_ff_fmt_2 = counter.get_microseconds();

        puts("FastFormat.Format (3):");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_ff_fmt_3();
        }}
        counter.stop();
        puts("");
        t_ff_fmt_3 = counter.get_microseconds();
    }}

    fprintf(stderr
        ,   "Streams:                        %luus\n"
            "IOStreams:                      %luus\n"
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            "Boost.Format:                   %luus\n"
            "Boost.Format (N):               %luus\n"
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
            "FastFormat.Format (implicit):   %luus\n"
            "FastFormat.Format (inserter):   %luus\n"
            "FastFormat.Format (inserter-N): %luus\n"
        ,   static_cast<unsigned long>(t_streams)
        ,   static_cast<unsigned long>(t_iostreams)
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
        ,   static_cast<unsigned long>(t_boost_1)
        ,   static_cast<unsigned long>(t_boost_2)
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
        ,   static_cast<unsigned long>(t_ff_fmt_1)
        ,   static_cast<unsigned long>(t_ff_fmt_2)
        ,   static_cast<unsigned long>(t_ff_fmt_3)
        );

    return EXIT_SUCCESS;
}

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER <= 1310
# pragma warning(push)
# pragma warning(disable : 4702)
# include <vector>
# pragma warning(pop)
#endif

#include <stlsoft/stlsoft.h>

int output_by_streams()
{
    printf("[%-14.3f%-14.3f]\n", 12345.12345, 12345.12345);

    return 0;
}

#include <iomanip>

int output_by_iostreams()
{
    std::cout 
        << '['
        << std::setiosflags(std::ios::fixed)
        << std::left
        << std::setprecision(3)
        << std::setw(14)
        << 12345.12345
        << std::setw(14)
        << 12345.12345
        << ']'
        << std::endl;

    return 0;
}


#include <fastformat/shims/conversion/filter_type/reals.hpp>
#include <fastformat/inserters/real.hpp>
#include <fastformat/inserters/to_f.hpp>
#include <fastformat/sinks/FILE.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/sinks/shim_string.hpp>
#include <fastformat/ff.hpp>

FILE* FILE_stm = stdout;
//#define ff_stm    FILE_stm
#define ff_stm  std::cout

int output_by_ff_fmt_1()
{
    ff::fmtln(
        ff_stm
    ,   "[{0,14,,<}{1,14,,<}]"
    ,   12345.12345
    ,   12345.12345
    );

    return 0;
}

int output_by_ff_fmt_2()
{
    ff::fmtln(
        ff_stm
    ,   "[{0}{1}]"
    ,   ff::to_f(12345.12345, -14, 3)
    ,   ff::to_f(12345.12345, -14, 3)
    );

    return 0;
}

int output_by_ff_fmt_3()
{
    ff::fmtln(
        ff_stm
    ,   "[{0}{0}]"
    ,   ff::to_f(12345.12345, -14, 3)
    );

    return 0;
}


#ifdef FASTFORMAT_PERFTEST_USE_BOOST

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER <= 1310
#  pragma warning(disable : 4511 4512 4671 4673)
# endif

# include <boost/format.hpp>

int output_by_boost_1()
{
    std::cout << boost::format("[%-14.3f%-14.3f]\n") % 12345.12345 % 12345.12345;

    return 0;
}

int output_by_boost_2()
{
    std::cout << boost::format("[%1$-14.3f%1$-14.3f]\n") % 12345.12345;

    return 0;
}
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

/* ///////////////////////////// end of file //////////////////////////// */
