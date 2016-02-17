//   Copyright (c) 2002-2009 Joel Hartmut Kaiser
//   Copyright (c) 2002-2009 Joel de Guzman
// 
//   Distributed under the Boost Software License, Version 1.0. (See accompanying
//   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if 0
#include "../high_resolution_timer.hpp"
#else /* ? 0 */
# include <stlsoft/stlsoft.h>
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(disable : 4512)
# endif
# include <fastformat/ff.hpp>
# include <fastformat/inserters/to_f.hpp>
# include <fastformat/sinks/char_buffer.hpp>
# include <fastformat/sinks/ostream.hpp>
# include <platformstl/performance/performance_counter.hpp>

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/karma.hpp>
#include <boost/format.hpp>

#include <iostream>
#include <iomanip>

namespace util
{
    class high_resolution_timer
        : public platformstl::performance_counter
    {
    public:
        high_resolution_timer()
        {
            start();
        }
        interval_type elapsed()
        {
            stop();
            return get_microseconds();
        }
    };

} // namespace util

#endif /* 0 */

//#include <fastformat/ff.hpp>

//#define SHOW_FIRST_LINE

#ifdef SHOW_FIRST_LINE
# define NUMITERATIONS 1
#else
# define NUMITERATIONS 1000000
#endif

////////////////////////////////////////////////////////////////////////////
//  policy for real_generator, which forces to output trailing zeros in the 
//  fractional part
//[karma_format_performance_definitions
template <typename T>
struct double3_policy : boost::spirit::karma::real_policies<T>   
{
    //  we want to generate up to 3 fractional digits
    static unsigned int precision(T) { return 3; }
};

typedef boost::spirit::karma::real_generator<double, double3_policy<double> > 
    double3_type;
double3_type const double3 = double3_type();
//]

void format_performance_karma()
{
    using boost::spirit::karma::left_align;
    using boost::spirit::karma::generate;

    //[karma_format_performance_plain
    char buffer[256];
    //<-
    util::high_resolution_timer t;
    //->
    for (int i = 0; i < NUMITERATIONS; ++i) {
        char *p = buffer;
        generate(p
          , '[' << left_align(14)[double3] << left_align(14)[double3] << ']'
          , 12345.12345, 12345.12345);
        *p = '\0';
    }
    //]

    std::cout << "karma:\t\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << buffer << std::endl;
#endif
}

void format_performance_rule()
{
    using boost::spirit::karma::left_align;
    using boost::spirit::karma::generate;

    typedef boost::fusion::vector<double, double> rtype;
    boost::spirit::karma::rule<char*, rtype()> r;

    //[karma_format_performance_rule
    char buffer[256];
    r %= '[' << left_align(14)[double3] << left_align(14)[double3] << ']';
    //<-
    util::high_resolution_timer t;
    //->
    for (int i = 0; i < NUMITERATIONS; ++i) {
        char *p = buffer;
        generate(p, r, 12345.12345, 12345.12345);
        *p = '\0';
    }
    //]

    std::cout << "karma (rule):\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << buffer << std::endl;
#endif
}

void format_performance_string()
{
    using boost::spirit::karma::left_align;
    using boost::spirit::karma::generate;

    //[karma_format_performance_string
    std::string generated;
    std::back_insert_iterator<std::string> sink(generated);
    //<-
    util::high_resolution_timer t;
    //->
    for (int i = 0; i < NUMITERATIONS; ++i) {
        generated.clear();
        generate(sink
          , '[' << left_align(14)[double3] << left_align(14)[double3] << ']'
          , 12345.12345, 12345.12345);
    }
    //]

    std::cout << "karma (string):\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << generated << std::endl;
#endif
}

// Boost.Format  
void format_performance_boost_format()
{
    //[karma_format_performance_format
    std::string generated;
    boost::format outformat("[%-14.3f%-14.3f]");
    //<-
    util::high_resolution_timer t;
    //->
    for (int i = 0; i < NUMITERATIONS; ++i)
        generated = boost::str(outformat % 12345.12345 % 12345.12345);
    //]

    std::cout << "format:\t\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << generated << std::endl;
#endif
}

void format_performance_sprintf()
{
    util::high_resolution_timer t;

    //[karma_format_performance_printf
    char buffer[256];
    for (int i = 0; i < NUMITERATIONS; ++i) {
        sprintf(buffer, "[%-14.3f%-14.3f]", 12345.12345, 12345.12345);
    }
    //]

    std::cout << "sprintf:\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << buffer << std::endl;
#endif
}

void format_performance_iostreams()
{
    //[karma_format_performance_iostreams
    std::stringstream strm;
    //<-
    util::high_resolution_timer t;
    //->
    for (int i = 0; i < NUMITERATIONS; ++i) {
        strm.str("");
        strm << '[' 
          << std::setiosflags(std::ios::fixed)
          << std::left
          << std::setprecision(3)
          << std::setw(14)
          << 12345.12345
          << std::setw(14)
          << 12345.12345
          << ']';
    }
    //]

    std::cout << "iostreams:\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << strm.str() << std::endl;
#endif
}

////////////////////////////////////////////////////////////////////////////

void format_performance_ff()
{
    //[karma_format_performance_plain
    char buffer[256];
    //<-
    util::high_resolution_timer t;
    //->
    for (int i = 0; i < NUMITERATIONS; ++i) {
        ff::sinks::char_buffer_sink sink(buffer);
        ff::fmt(sink
#if 1
          , "[{0,14,,<}{0,14,,<}]"
          , ff::to_f(12345.12345/* , -1, 3 */)
#else /* ? 0 */
          , "[{0}{0}]"
          , ff::to_f(12345.12345, -14, 3)
#endif /* 0 */
          );
    }
    //]

    std::cout << "ff:\t\t" << t.elapsed() << std::endl;
#ifdef SHOW_FIRST_LINE
     std::cout << buffer << std::endl;
#endif
}

////////////////////////////////////////////////////////////////////////////

int main()
{
    format_performance_sprintf();
    format_performance_iostreams();
    format_performance_boost_format();
    format_performance_karma();
    format_performance_string();
    format_performance_rule();
    format_performance_ff();
    return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */
