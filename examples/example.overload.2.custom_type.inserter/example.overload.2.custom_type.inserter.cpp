/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.overload.2.custom_type.inserter/example.overload.2.custom_type.inserter.cpp
 *
 * Purpose:     Implementation file for the example.overload.2.custom_type.inserter project.
 *
 * Created:     2nd March 2009
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/test/util/compiler_warnings_suppression.first_include.h>

/* /////////////////////////////////////////////////////////////////////////
 * Custom types
 *
 * We put this at the start of the file, to emulate the circumstances where
 * the application specific types are in a header, which, of course, would
 * be included before 3pty / standard header files
 */

#include <stlsoft/stlsoft.h>
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

public: /// Member Variables
    const string_type   name;
    const int           weight;
    const int           strength;
    const int           goodness;
};


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* FastFormat header files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>
#include <fastformat/bundles/properties_bundle.hpp>

/* STLSoft header files */

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
 /* This is legitimate *only* in the case of the behaviour of this code */
# include <windows.h>
# define sprintf    wsprintf
#endif /* VC++ 8+ */

#include <fastformat/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

std::string edna_1(superhero const& hero);
std::string edna_2(superhero const& hero);
#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
std::string edna_3(superhero const& hero);
std::string edna_4(superhero const& hero);
std::string edna_5(superhero const& hero);
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

std::string edna_1(superhero const& hero)
{
  std::string result;
  char        num[21];
  result += hero.name;
  result += " {weight=";
  result.append(num, (size_t)sprintf(num, "%d", hero.weight));
  result += ", strength=";
  result.append(num, (size_t)sprintf(num, "%d", hero.strength));
  result += ", goodness=";
  result.append(num, (size_t)sprintf(num, "%d", hero.goodness));
  result += '}';

  return result;
}

std::string edna_2(superhero const& hero)
{
  std::string result;
  char        num[21];
  result.reserve(hero.name.size() + 32 + (3 * 20));
  result += hero.name;
  result += " {weight=";
  result.append(num, (size_t)sprintf(num, "%d", hero.weight));
  result += ", strength=";
  result.append(num, (size_t)sprintf(num, "%d", hero.strength));
  result += ", goodness=";
  result.append(num, (size_t)sprintf(num, "%d", hero.goodness));
  result += '}';

  return result;
}

#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */

std::string edna_3(superhero const& hero)
{
  std::string result;
  ff::write(result, hero.name, " {weight=", hero.weight
          , ", strength=", hero.strength, ", goodness=", hero.goodness
          , "}");
  return result;
}

std::string edna_4(superhero const& hero)
{
  std::string result;
  ff::fmt(result, "{0} {{weight={1}, strength={2}, goodness={3}}"
        , hero.name, hero.weight
        , hero.strength, hero.goodness);
  return result;
}

ff::properties_bundle const& getAppBundle();

std::string edna_5(superhero const& hero)
{
  std::string result;
  ff::properties_bundle const& bundle = getAppBundle();

  ff::fmt(result, bundle["superhero.format"]
        , hero.name, hero.weight
        , hero.strength, hero.goodness);
  return result;
}

#endif /* compiler */


/* ////////////////////////////////////////////////////////////////////// */

ff::properties_bundle* bundle;

ff::properties_bundle const& getAppBundle()
{
    STLSOFT_ASSERT(NULL != bundle);

    return *bundle;
}


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    char const* bundlePath  =   "superhero.properties";

    if(argc > 1)
    {
        bundlePath = argv[1];
    }

#if 1
    superhero   thing("The Thing", 200, 99, 100);
    superhero   batman("Batman", 100, 80, 95);

# if 0
    ff::writeln(std::cout, "Ben Grimm is ", thing);
    ff::fmtln(std::cout, "Bruce Wayne is {0}", batman);
# else /* ? 0 */

    ff::properties_bundle   bundle_(bundlePath);

    bundle = &bundle_;

    ff::writeln(std::cout, "Ben Grimm is ", edna_1(thing));
    ff::writeln(std::cout, "Ben Grimm is ", edna_2(thing));
#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
    ff::writeln(std::cout, "Ben Grimm is ", edna_3(thing));
    ff::writeln(std::cout, "Ben Grimm is ", edna_4(thing));
    ff::writeln(std::cout, "Ben Grimm is ", edna_5(thing));
#endif /* compiler */

    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_1(batman));
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_2(batman));
#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_3(batman));
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_4(batman));
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_5(batman));
#endif /* compiler */

    bundle = NULL;

# endif /* 0 */
#else /* ? 0 */

#if 0
    std::string sink1, sink2;
    ff::fmt(ff::fmt(sink1, "{0}", 1), "{0}", 2);
    ff::write(ff::write(sink2, 1), 2);
#endif /* 0 */


    OutputDebugString(NULL);
#endif /* 0 */

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

