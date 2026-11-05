/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/flush/main.cpp
 *
 * Purpose: Example for flush().
 *
 * Created: 16th October 2026
 * Updated: 3rd November 2026
 *
 * ////////////////////////////////////////////////////////////////////// */

#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

#include <iostream>

int main()
{
  ff::flush(ff::writeln(std::cout, "Hello, world!"));

  return 0;
}

/* ///////////////////////////// end of file //////////////////////////// */


