/* /////////////////////////////////////////////////////////////////////////
 * File:        example.overload.3.tabulations.cpp
 *
 * Purpose:     Implementation file for the example.overload.3.tabulations
 *              project.
 *
 * Created:     29th April 2009
 * Updated:     23rd September 2015
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


#include <fastformat/fastformat.h>

#include <platformstl/performance/performance_counter.hpp>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

char const* forenames[] =
{
        "Marc-Francois Michel"
    ,   "Jean"
};

char const* surnames[] =
{
        "Durand"
    ,   "de Lattre de Tassigny"
};

char const* tels[] =
{
        "+33 (0) 123 456 789"
    ,   "+33 (0) 987 654 321"
};

#include <string>
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER <= 1310
#  pragma warning(push)
#  pragma warning(disable : 4702)
# endif
#include <vector>
# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER <= 1310
#  pragma warning(pop)
# endif

std::vector<std::string>    forenames_;
std::vector<std::string>    surnames_;
std::vector<std::string>    tels_;

static void setup()
{
    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(forenames); ++i)
    {
        forenames_.push_back(forenames[i]);
    }}

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(surnames); ++i)
    {
        surnames_.push_back(surnames[i]);
    }}

    { for(size_t i = 0; i != STLSOFT_NUM_ELEMENTS(tels); ++i)
    {
        tels_.push_back(tels[i]);
    }}

#define forenames   forenames_
#define surnames    surnames_
#define tels        tels_
}

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
int output_by_boost();
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
int output_by_ff();

int main()
{
    setup();

    platformstl::performance_counter                counter;
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
    platformstl::performance_counter::interval_type t_boost     =   0;
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
    platformstl::performance_counter::interval_type t_ff_fmt    =   0;

    { for(int WARMUPS = 3; 0 != WARMUPS; --WARMUPS)
    {
#ifdef _DEBUG
        const int ITERATIONS = 1;
        WARMUPS = 1;
#else /* ? _DEBUG */
        const int ITERATIONS = 10000;
#endif /* _DEBUG */

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
        puts("Boost:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_boost();
        }}
        counter.stop();
        puts("");
        t_boost = counter.get_microseconds();
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

        puts("FastFormat.Format:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            output_by_ff();
        }}
        counter.stop();
        puts("");
        t_ff_fmt = counter.get_microseconds();
    }}

    fprintf(stderr
        ,   "FastFormat.Format: %luus\n"
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
            "Boost.Format:      %luus\n"
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
        ,   static_cast<unsigned long>(t_ff_fmt)
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
        ,   static_cast<unsigned long>(t_boost)
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
        );

    return EXIT_SUCCESS;
}

#include <stlsoft/stlsoft.h>

#include <fastformat/sinks/FILE.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/sinks/shim_string.hpp>
#include <fastformat/ff.hpp>

FILE* FILE_stm = stdout;
//#define ff_stm    FILE_stm
#define ff_stm  std::cout

int output_by_ff()
{
#ifdef forenames
    for(unsigned int i = 0; i < forenames.size(); ++i)
#else /* forenames */
    for(unsigned int i = 0; i < STLSOFT_NUM_ELEMENTS(forenames); ++i)
#endif /* forenames */
    {
#if 1
        std::string                             scratch;
#else /* ? 0 */
        stlsoft::basic_shim_string<char, 128>   scratch;
#endif /* 0 */

        ff::fmtln(
            ff_stm
        ,   "{0,40,,<}{1}"
        ,   ff::fmt(
                scratch
            ,   "{0}, {1}, "
            ,   forenames[i]
            ,   surnames[i]
            )
        ,   tels[i]
        );
    }

    return 0;
}


#ifdef FASTFORMAT_PERFTEST_USE_BOOST

# if defined(STLSOFT_COMPILER_IS_MSVC) && \
     _MSC_VER <= 1310
#  pragma warning(disable : 4511 4512 4671 4673)
# endif

# include <boost/format.hpp>

int output_by_boost()
{
# ifdef forenames
    for(unsigned int i = 0; i < forenames.size(); ++i)
# else /* forenames */
    for(unsigned int i = 0; i < STLSOFT_NUM_ELEMENTS(forenames); ++i)
# endif /* forenames */
    {
        std::cout << boost::format("%1%, %2%, %|40t|%3%\n") % forenames[i] % surnames[i] % tels[i];
    }

    return 0;
}
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

/* ///////////////////////////// end of file //////////////////////////// */
