/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.iterators.format_iterator/example.iterators.format_iterator.cpp
 *
 * Purpose:     Implementation file for the example.iterators.format_iterator project.
 *
 * Created:     26th March 2010
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

#if ( defined(STLSOFT_COMPILER_IS_INTEL) || \
      defined(STLSOFT_COMPILER_IS_MSVC)) && \
    _MSC_VER >= 1400
# pragma warning(disable : 4996)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/fastformat.h>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/iterators/format_iterator.hpp>
#include <fastformat/fastformat.hpp>

/* STLSoft Header Files */
#include <stlsoft/algorithms/debug.hpp>

/* Standard C++ Header Files */
#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
# error Cannot compile this file with a compiler that does not support the filter_type mechanism
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
  typedef std::wstring            string_t;
# define    stm                   std::wcout
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
  typedef std::string             string_t;
# define    stm                   std::cout
#endif /* FASTFORMAT_USE_WIDE_STRINGS */
  typedef std::vector<string_t>   strings_t;

  strings_t strings;

  strings.push_back(FASTFORMAT_LITERAL_STRING("abc"));
  strings.push_back(FASTFORMAT_LITERAL_STRING("def"));
  strings.push_back(FASTFORMAT_LITERAL_STRING("ghi"));



  stm << FASTFORMAT_LITERAL_STRING("via std::copy():") << std::endl;

  std::copy(
    strings.begin()
  , strings.end()
  , fastformat::format_iterator(stm, FASTFORMAT_LITERAL_STRING("\t{0}\n"))
  );

  stm << std::endl;



  stm << FASTFORMAT_LITERAL_STRING("via stlsoft::copy_postinc():") << std::endl;

  stlsoft::copy_postinc(
    strings.begin()
  , strings.end()
  , fastformat::format_iterator(stm, FASTFORMAT_LITERAL_STRING("\t{0}\n"))
  );

  stm << std::endl;



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
