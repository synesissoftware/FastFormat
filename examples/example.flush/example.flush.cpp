/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/example.flush/example.flush.cpp
 *
 * Purpose: Example for flush().
 *
 * Created: 16th October 2026
 * Updated: 16th October 2026
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
