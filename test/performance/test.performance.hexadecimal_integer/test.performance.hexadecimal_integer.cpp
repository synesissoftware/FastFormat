

#include <fastformat/ff.hpp>
#include <fastformat/inserters/to_i.hpp>
#include <fastformat/inserters/to_x.hpp>
#include <fastformat/sinks/char_buffer.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <platformstl/performance/performance_counter.hpp>

//#include <stlsoft/util/rand.hpp>

#include <iostream>

#include <stdio.h>
#include <limits.h>

#ifdef _DEBUG
const size_t NUM_ITERATIONS =   1;
#else
const size_t NUM_ITERATIONS =   10000000;
#endif

int main()
{
    platformstl::performance_counter    counter;

    unsigned    x = 0;

    ff::fmtln(std::cout, "_STLSOFT_VER={0}", ff::to_x(_STLSOFT_VER));

    {
        { for(int WARMUPS = 2; 0 != WARMUPS--; )
        {
            counter.start();

            { for(size_t i = 0; i != NUM_ITERATIONS; ++i)
            {
                char                        sz[21];
                ff::sinks::char_buffer_sink sink(sz);

                ff::write(sink, ff::to_x(i));

                x ^= sz[0];
            }}

            counter.stop();
        }}

        ff::fmtln(std::cout, "{0} incremental (size_t) numbers in {1}us", NUM_ITERATIONS, counter.get_microseconds());
    }

    {
        { for(int WARMUPS = 2; 0 != WARMUPS--; )
        {
            counter.start();

            { for(int i = INT_MIN / 16; i != INT_MAX / 16; ++i)
            {
                char                        sz[21];
                ff::sinks::char_buffer_sink sink(sz);

                ff::write(sink, ff::to_x(i));

                x ^= sz[0];
            }}

            counter.stop();
        }}

        ff::fmtln(std::cout, "{0} incremental (int) numbers in {1}us", static_cast<unsigned long>(INT_MAX) * 2, counter.get_microseconds());
    }

    if(~(0) == x)
    {
        fputs("", stdin);
    }

    return 0;
}
