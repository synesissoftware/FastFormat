# FastFormat {#mainpage}

**FastFormat** is an extremely fast, 100% type-safe, infinitely-extensible,
I18N/L10N-friendly C++ output/formatting library. Format strings use
replacement parameters of the form `{0}`, `{1}`, …; arguments are type-safe
at compile time; and output goes to any *sink* that accepts an array of
string slices.

**FastFormat** has two APIs:
* **Write** API — a concatenation-based API, where arguments are expressed
  one after another;
* **Format** API — a replacement-parameter API, where a format string names
  each argument by `{0}`, `{1}`, …;


## Quick start

Install [STLSoft](https://github.com/synesissoftware/STLSoft) (**1.11.9**
or later) via **CMake**, then from a **FastFormat** tree:

```bash
./prepare_cmake.sh --run-make # also use '--cmake-verbose-makefile' to see verbose output
./run_all_automated_tests.sh --no-make
```

Automated tests need [xTests](https://github.com/synesissoftware/xTests)
(**0.29.0** or later) and, optionally,
[shwild](https://github.com/synesissoftware/shwild).


### via Format API

A format statement names a sink, a format string, and the arguments.
`<fastformat/ff.hpp>` is the application layer;
`<fastformat/sinks/ostream.hpp>` writes the slices to `std::ostream`.
The shortest program prints one line:

```cpp
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <iostream>
#include <string>

int main()
{
    std::string const world("World");

    ff::fmtln(std::cout, "Hello, {0}!", world);

    return 0;
}
```


### via Write API

A write statement names a sink and the arguments, in order. There is no
format string. `<fastformat/ff.hpp>` is the application layer;
`<fastformat/sinks/ostream.hpp>` writes the slices to `std::ostream`.
The shortest program prints one line:

```cpp
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <iostream>
#include <string>

int main()
{
    std::string const world("World");

    ff::writeln(std::cout, "Hello, ", world, "!");

    return 0;
}
```


### CMake configuration

```cmake
find_package(FastFormat REQUIRED)

target_link_libraries(hello
    PRIVATE
        FastFormat::fastformat
)
```

Clone or a release archive:
[INSTALL.md](https://github.com/synesissoftware/FastFormat/blob/0.8.1/INSTALL.md).
The longer walkthrough is **examples/101/normal**.


## Innate Software Quality Characteristics

According to the seven **Innate Software Quality Characteristics** — from
_Quality Matters: Introductions, and Nomenclature_, Matthew Wilson, ACCU
Overload, August 2009;
https://accu.org/journals/overload/17/92/wilson_1572/ - FastFormat scores
high to very high on several of them:

| Characteristic                         | Score     | Discussion |
| -------------------------------------- | --------- | ------ |
| **Correctness/reliability/robustness** | Very High | Using the **Write** API it is impossible to write defective code. Using the **Format** API the only possible error is to supply the wrong number of parameters (and that will be resolved in a forthcoming version using `constexpr` processing). |
| **Efficiency**                         | Very High | Even now, after 20 years since its first release, FastFormat is on par with or faster than other popular C++ formatting libraries. In coming releases there will be a refreshed set of comparisons provided in the distribution. |
| **Discoverability and transparency**   | Moderate  | Like most sophisticated C++ template libraries, compiler error messages can be challenging to interpret. |
| **Modularity**                         | Moderate  | Depends on the STLSoft libraries. That dependency represents additional effort (see INSTALL.md for instructions). |
| **Expressiveness**                     | Very High | Supporting both the concatenation-based **Write** API and the replacement-parameter **Format** API, the latter of which has a small set of simple rules. |
| **Flexibility**                        | Very High | FastFormat is infinitely extensible, and any type that is expressible in string form may be adapted. It supports I18N/L10N via dynamic format strings. Integers, `std::string`, and `std::ostream` are accepted by default; further standard and operating-system types (`FILE*`, `struct iovec`, and others) are available from an explicit sink or inserter header. |
| **Portability**                        | High      | Tested on Linux, macOS, Windows |

Notwithstanding this pretty positive picture, there are some significant
issues for the 20+ year-old design. These will be addressed in the coming
0.9, 0.10, ... release plan.


## Components

| Module | Header | Summary |
| ------ | ------ | ------- |
| \ref group__core_library | `<fastformat/fastformat.h>` | Core formatting API |
| \ref group__application_layer | `<fastformat/fastformat.hpp>` (or `<fastformat/ff.hpp>`) | Application-layer API |
| \ref group__interface_functions | `<fastformat/fastformat.hpp>` (or `<fastformat/ff.hpp>`) | Format and Write interface functions |
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
