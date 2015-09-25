/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.overload.2.custom_type.filter_type/example.overload.2.custom_type.filter_type.cpp
 *
 * Purpose:     Implementation file for the example.overload.2.custom_type.filter_type project.
 *
 * Created:     2nd March 2009
 * Updated:     26th September 2015
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


/* /////////////////////////////////////////////////////////////////////////
 * Custom types
 */

#include <string>

class superhero
{
public: /// Member Types
    typedef std::string     string_type;
    typedef superhero       class_type;

public: /// Construction
    superhero(string_type const& name, int weight, int strength, int goodness)
        : name(name)
        , weight(weight)
        , strength(strength)
        , goodness(goodness)
    {}
private:
    class_type& operator =(class_type const&);

public:
    const string_type   name;
    const int           weight;
    const int           strength;
    const int           goodness;
};

class extrasuperhero
    : public superhero
{
public:
    extrasuperhero(string_type const& name, int weight, int strength, int goodness)
        : superhero(name, weight, strength, goodness)
    {}
};

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

// Borland, Digital Mars and Visual C++ (pre 7.1) do not support the filter
// type mechanism
#include <stlsoft/stlsoft.h>

#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */ && \
    (   !defined(STLSOFT_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1310) /* VC++ 6 - no chance */
# define FF_COMPILER_SUPPORTS_FILTER_TYPE
#endif


// GCC does not obey the namespace rules, so we cannot use any fastformat
// statements before we've declared them all inline, so we implement them
// indirectly via the superhero_to_string function

std::string superhero_to_string(superhero const& hero);

#ifdef FF_COMPILER_SUPPORTS_FILTER_TYPE

namespace fastformat
{
namespace filters
{

    inline std::string filter_type(superhero const& hero, superhero const*, char const volatile*)
    {
        return superhero_to_string(hero);
    }

    inline std::string filter_type(extrasuperhero const& hero, extrasuperhero const*, char const volatile* p)
    {
        superhero const& regular_hero = hero;

        return filter_type(regular_hero, &regular_hero, p);
    }

} // namespace filters
} // namespace fastformat

#endif /* FF_COMPILER_SUPPORTS_FILTER_TYPE */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* FastFormat header files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

/* STLSoft header files */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C header files */
#include <stdlib.h>

/* ////////////////////////////////////////////////////////////////////// */

std::string superhero_to_string(superhero const& hero)
{
    std::string result;

#ifdef FF_COMPILER_SUPPORTS_FILTER_TYPE

    ff::fmt(result, "{0} {{weight={1}, strength={2}, goodness={3}}"
        ,   hero.name, hero.weight
        ,   hero.strength, hero.goodness);

#else /* ? FF_COMPILER_SUPPORTS_FILTER_TYPE */

    STLSOFT_SUPPRESS_UNUSED(hero);

#endif /* FF_COMPILER_SUPPORTS_FILTER_TYPE */

    return result;
}

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
    superhero   thing("The Thing", 200, 99, 100);
    extrasuperhero  batman("Batman", 100, 80, 95);

#ifdef FF_COMPILER_SUPPORTS_FILTER_TYPE

    ff::writeln(std::cout, "Ben Grimm is ", thing);
    ff::fmtln(std::cout, "Bruce Wayne is {0}", batman);

#endif /* FF_COMPILER_SUPPORTS_FILTER_TYPE */

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
