/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/example.overload.2.custom_type.inserter/example.overload.2.custom_type.inserter.cpp
 *
 * Purpose: Example for custom-type overload via inserter.
 *
 * Created: 2nd March 2009
 * Updated: 16th October 2026
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
#include <fastformat/util/string/snprintf.h>

/* STLSoft header files */

/* Standard C++ header files */
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

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
#if !defined(__MINGW32__)
std::string edna_5(superhero const& hero, ff::properties_bundle const& appBundle);
#endif /* !__MINGW32__ */
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */

std::string edna_1(superhero const& hero)
{
  using fastformat::fastformat_util_snprintf;

  std::string result;
  char        num[21];
  int         n;

  result += hero.name;
  result += " {weight=";
  n = fastformat_util_snprintf(num, STLSOFT_NUM_ELEMENTS(num), "%d", hero.weight);
  result.append(num, n < 0 ? size_t(0) : size_t(n));
  result += ", strength=";
  n = fastformat_util_snprintf(num, STLSOFT_NUM_ELEMENTS(num), "%d", hero.strength);
  result.append(num, n < 0 ? size_t(0) : size_t(n));
  result += ", goodness=";
  n = fastformat_util_snprintf(num, STLSOFT_NUM_ELEMENTS(num), "%d", hero.goodness);
  result.append(num, n < 0 ? size_t(0) : size_t(n));
  result += '}';

  return result;
}

std::string edna_2(superhero const& hero)
{
  using fastformat::fastformat_util_snprintf;

  std::string result;
  char        num[21];
  int         n;

  result.reserve(hero.name.size() + 32 + (3 * 20));
  result += hero.name;
  result += " {weight=";
  n = fastformat_util_snprintf(num, STLSOFT_NUM_ELEMENTS(num), "%d", hero.weight);
  result.append(num, n < 0 ? size_t(0) : size_t(n));
  result += ", strength=";
  n = fastformat_util_snprintf(num, STLSOFT_NUM_ELEMENTS(num), "%d", hero.strength);
  result.append(num, n < 0 ? size_t(0) : size_t(n));
  result += ", goodness=";
  n = fastformat_util_snprintf(num, STLSOFT_NUM_ELEMENTS(num), "%d", hero.goodness);
  result.append(num, n < 0 ? size_t(0) : size_t(n));
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

#if !defined(__MINGW32__)
std::string edna_5(superhero const& hero, ff::properties_bundle const& appBundle)
{
  std::string result;
  std::string const format = appBundle["superhero.format"];

  ff::fmt(result, format
        , hero.name, hero.weight
        , hero.strength, hero.goodness);
  return result;
}
#endif /* !__MINGW32__ */

#endif /* compiler */


/* ////////////////////////////////////////////////////////////////////// */

#if !defined(__MINGW32__)
static char const* select_bundle_path(int argc, char* argv[])
{
    if(argc > 1)
    {
        return argv[1];
    }

    // Repo-root runners (CI, run_all_examples.sh) keep the sample bundle
    // under test/data/bundles. A copy in the working directory still wins.
    char const* candidates[] =
    {
        "superhero.properties",
        "test/data/bundles/superhero.properties",
        NULL,
    };

    for(size_t i = 0; NULL != candidates[i]; ++i)
    {
        std::ifstream stm(candidates[i]);

        if(stm.is_open())
        {
            return candidates[i];
        }
    }

    return NULL;
}
#endif /* !__MINGW32__ */

static int main_(int argc, char* argv[])
{
    superhero   thing("The Thing", 200, 99, 100);
    superhero   batman("Batman", 100, 80, 95);

    // Bundle-free overloads first so a properties load fault cannot hide
    // the rest of the example.
    ff::writeln(std::cout, "Ben Grimm is ", edna_1(thing));
    ff::writeln(std::cout, "Ben Grimm is ", edna_2(thing));
#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
    ff::writeln(std::cout, "Ben Grimm is ", edna_3(thing));
    ff::writeln(std::cout, "Ben Grimm is ", edna_4(thing));
#endif /* compiler */

    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_1(batman));
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_2(batman));
#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_3(batman));
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_4(batman));
#endif /* compiler */

    // Flush before the properties load so a fault there cannot hide the
    // bundle-free output under Windows process-kill (no atexit flush).
    std::cout.flush();

#if defined(__MINGW32__)
    // MinGW AVs in/after properties_bundle construction here (0xC0000005);
    // bundle-free overloads above are enough for CI. See TODO.md.
    STLSOFT_SUPPRESS_UNUSED(argc);
    STLSOFT_SUPPRESS_UNUSED(argv);
#else /* ? __MINGW32__ */
    char const* bundlePath = select_bundle_path(argc, argv);

    if(NULL == bundlePath)
    {
        throw std::runtime_error("superhero.properties not found (tried cwd and test/data/bundles)");
    }

    ff::properties_bundle const bundle(bundlePath);

#if !defined(STLSOFT_COMPILER_IS_BORLAND) /* Borland is messed up, and cannot handle the filter type mechanism */ && \
    !defined(STLSOFT_COMPILER_IS_DMC) /* DMC++ gets confused and can't find any matches for c_str_data_a */
    ff::writeln(std::cout, "Ben Grimm is ", edna_5(thing, bundle));
    ff::fmtln(std::cout, "Bruce Wayne is {0}", edna_5(batman, bundle));
#endif /* compiler */
#endif /* __MINGW32__ */

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    try
    {
        return main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "exception: " << x.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "unhandled unknown error" << std::endl;
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */
