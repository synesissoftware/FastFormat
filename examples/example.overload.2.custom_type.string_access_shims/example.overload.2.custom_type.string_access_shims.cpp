/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.overload.2.custom_type.string_access_shims/example.overload.2.custom_type.string_access_shims.cpp
 *
 * Purpose:     Implementation file for the example.overload.2.custom_type.string_access_shims project.
 *
 * Created:     2nd March 2009
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * custom types
 */

#include <string>

class superhero
{
public:
    typedef std::string     string_type;
    typedef superhero       class_type;

public:
    superhero(string_type const& name, int weight, int strength, int goodness)
        : name(name)
        , weight(weight)
        , strength(strength)
        , goodness(goodness)
    {}

public:
    string_type name;
    int         weight;
    int         strength;
    int         goodness;

private:
    class_type& operator =(class_type const&);
};

/* Here we have to forward declare the shims, due to a namespace resolution
 * defect in GCC
 */
#include <stlsoft/stlsoft.h>
#include <stlsoft/string/shim_string.hpp>
#include <fastformat/sinks/shim_string.hpp>

# if _STLSOFT_VER < 0x010a0000 && \
  !defined(_STLSOFT_1_10_VER)
typedef fastformat::sinks::shim_string_sink     c_str_data_a_result_t;
# else
typedef stlsoft::basic_shim_string<char>        c_str_data_a_result_t;
# endif

namespace stlsoft
{
    c_str_data_a_result_t c_str_data_a(superhero const& hero);

    size_t c_str_len_a(superhero const& hero);
}


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

/* STLSoft Header Files */
#include <stlsoft/string/shim_string.hpp>

#if _STLSOFT_VER < 0x010a0000 && \
    !defined(_STLSOFT_1_10_VER)
# include <fastformat/sinks/shim_string.hpp>
#endif

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C Header Files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

namespace stlsoft
{

#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */

    // The version of basic_shim_string available from STLSoft 1.10.1
    // alpha 9, or later, can be used directly.
    //
    // Otherwise, we must use the fastformat::sinks::sinks::shim_string_sink
    // class, which is effectively an adaptor to make it all work
    //
    // fastformat::sinks::sinks::shim_string_sink can also be used with
    // STLSoft 1.10.1 alpha 9, or later

c_str_data_a_result_t c_str_data_a(superhero const& hero)
{
    c_str_data_a_result_t    result;

    ff::fmt(result, "{0} {{weight={1}, strength={2}, goodness={3}}"
        ,   hero.name, hero.weight
        ,   hero.strength, hero.goodness);

    return result;
}

size_t c_str_len_a(superhero const& hero)
{
#if 0
    size_t n = hero.name.size() + 32;
    char buff[21];

    n += sprintf(buff, "%d", hero.weight);
    n += sprintf(buff, "%d", hero.strength);
    n += sprintf(buff, "%d", hero.goodness);

    return n;
#else
    return c_str_data_a(hero);
#endif
}

#endif /* compiler */

} // namespace stlsoft


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    superhero   thing("The Thing", 200, 99, 100);
    superhero   batman("Batman", 100, 80, 95);

#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
    ff::writeln(std::cout, "Ben Grimm is ", thing);
    ff::fmtln(std::cout, "Bruce Wayne is {0}", batman);
#endif /* compiler */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    try
    {
        return main_(argc, argv);
    }
    catch(std::exception& x)
    {
        ff::fmtln(std::cerr, "exception: {0}", x);
    }
    catch(...)
    {
        ff::writeln(std::cerr, "unhandled unknown error");
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

