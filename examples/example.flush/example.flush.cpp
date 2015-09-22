
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

#include <iostream>

int main()
{
  ff::flush(ff::writeln(std::cout, "Hello, world!"));

  return 0;
}
