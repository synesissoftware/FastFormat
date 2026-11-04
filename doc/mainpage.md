# FastFormat {#mainpage}

**FastFormat** is an extremely fast, 100% type-safe, infinitely-extensible,
I18N/L10N-friendly C++ output/formatting library. Format strings use
replacement parameters of the form `{0}`, `{1}`, …; arguments are type-safe
at compile time; and output goes to any *sink* that accepts an array of
string slices.


## Quick start

Install [STLSoft](https://github.com/synesissoftware/STLSoft) (**1.11.5**
or later) via **CMake**, then from a **FastFormat** tree:

```bash
./prepare_cmake.sh --run-make # also use '--cmake-verbose-makefile' to see verbose output
./run_all_automated_tests.sh --no-make
```

Automated tests need [xTests](https://github.com/synesissoftware/xTests)
(**0.28.2** or later). [shwild](https://github.com/synesissoftware/shwild)
is optional.

A format statement names a sink, a format string, and the arguments.
`<fastformat/ff.hpp>` is the application layer;
`<fastformat/sinks/ostream.hpp>` writes the slices to `std::ostream`.
The shortest program prints one line:

```cpp
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <iostream>

int main()
{
    fastformat::fmtln(std::cout, "Hello, {0}!", "World");

    return 0;
}
```

```cmake
find_package(FastFormat REQUIRED)

target_link_libraries(hello
    PRIVATE
        FastFormat::fastformat
)
```

Clone or a release archive:
[INSTALL.md](https://github.com/synesissoftware/FastFormat/blob/dev-0.8/INSTALL.md).
The longer walkthrough is **examples/101/normal**.


## Components

| Module | Header | Summary |
| ------ | ------ | ------- |
| \ref group__core_library | `<fastformat/fastformat.h>` | Core formatting API |
| \ref group__application_layer | `<fastformat/fastformat.hpp>` | Application-layer API |
| \ref group__interface_functions | `<fastformat/fastformat.hpp>` | Format and Write interface functions |
| \ref group__init | `<fastformat/fastformat.h>` | Library initialisation |
| \ref group__format_specification_defect_handling | `<fastformat/fastformat.h>` | Ill-formed / mismatched argument handling |
| \ref group__utility | `<fastformat/fastformat.h>` | Utility helpers |
| Inserters | `<fastformat/inserters/*.hpp>` | Typed inserters (`to_i`, `to_x`, `real`, …) |
| Sinks | `<fastformat/sinks/*.hpp>` | Output sinks (`ostream`, `FILE`, …) |


## Related projects

* [Pantheios](https://github.com/synesissoftware/Pantheios) — diagnostic logging API
* [shwild](https://github.com/synesissoftware/shwild) — optional, for enhanced **xTests** matching
* [STLSoft](https://github.com/synesissoftware/STLSoft/) — required dependency
* [UNIXem](https://github.com/synesissoftware/UNIXem) — Unix API emulation on Windows for selected scratch programs
* [xTests](https://github.com/synesissoftware/xTests) — test harness


<!-- ########################### end of file ########################### -->
