/* /////////////////////////////////////////////////////////////////////////
 * File:        example.inserter.integers.WindowsLargeIntegers.cpp
 *
 * Purpose:     Implementation file for the example.inserter.integers.WindowsLargeIntegers project.
 *
 * Created:     30th November 2010
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/inserters/WindowsLargeIntegers.hpp>

/* STLSoft Header Files */
#include <stlsoft/util/limit_traits.h>

/* Standard C++ Header Files */
#include <iostream>

/* Standard C Header Files */
#include <stdlib.h>


/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
  { // LARGE_INTEGER
    LARGE_INTEGER li;

    li.QuadPart = STLSOFT_GEN_SINT64_SUFFIX(0x1234567890abcdef);

    ff::writeln(std::cout, "li:  ", ff::to_i(li));
  }

  { // ULARGE_INTEGER
    ULARGE_INTEGER uli;

    uli.QuadPart = STLSOFT_GEN_UINT64_SUFFIX(0x1234567890abcdef);

    ff::writeln(std::cout, "uli: ", ff::to_i(uli));
  }


  { // LARGE_INTEGER
    LARGE_INTEGER li;

    li.QuadPart = STLSOFT_GEN_SINT64_SUFFIX(0x1234567890abcdef);

    ff::fmtln(std::cout, "li:  {0}", ff::to_i(li));
  }

  { // ULARGE_INTEGER
    ULARGE_INTEGER uli;

    uli.QuadPart = STLSOFT_GEN_UINT64_SUFFIX(0x1234567890abcdef);

    ff::fmtln(std::cout, "uli: {0}", ff::to_i(uli));
  }


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
    std::cerr << "Unhandled error: " << x.what() << std::endl;
  }
  catch(...)
  {
    std::cerr << "Unhandled unknown error" << std::endl;
  }

  return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

