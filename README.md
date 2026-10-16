# FastFormat <!-- omit in toc -->

The fastest, most robust C++ formatting library


![C/C++](https://img.shields.io/badge/C%2FC%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/FastFormat.svg)](https://github.com/synesissoftware/FastFormat/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/FastFormat)](https://github.com/synesissoftware/FastFormat/commits/master)
[![CI](https://github.com/synesissoftware/FastFormat/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/FastFormat/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Developer Experience](#developer-experience)
- [Installation](#installation)
  - [API documentation (Doxygen)](#api-documentation-doxygen)
- [Components](#components)
  - [Core and application layer](#core-and-application-layer)
  - [Inserters](#inserters)
  - [Sinks](#sinks)
  - [Bundles](#bundles)
  - [Iterators and format-defect handling](#iterators-and-format-defect-handling)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
    - [Runtime dependency](#runtime-dependency)
    - [Development dependencies](#development-dependencies)
    - [Windows-only test / scratch dependency](#windows-only-test--scratch-dependency)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**FastFormat** is an extremely fast, 100% type-safe, infinitely-extensible,
I18N/L10N-friendly C++ output/formatting library. Format strings use
replacement parameters of the form `{0}`, `{1}`, …; arguments are type-safe
at compile time; and output goes to any *sink* that accepts an array of
string slices (streams, `FILE*`, buffers, platform-specific destinations,
speech synthesisers, and more).

The library is released under a BSD-style licence. Source and issues live
at https://github.com/synesissoftware/FastFormat.


## Developer Experience

**FastFormat** needs [**STLSoft**](https://github.com/synesissoftware/STLSoft)
**1.11** or later for the library itself. Examples and automated tests also
need [**xTests**](https://github.com/synesissoftware/xTests) **0.26** or
later; [**shwild**](https://github.com/synesissoftware/shwild) is optional
and enables richer **xTests** matches. On Windows, scratch programs that
include `<unixem/unixem.h>` need
[**UNIXem**](https://github.com/synesissoftware/UNIXem) **1.14.2** or later
(see [Dependencies](#dependencies)).

```bash
./prepare_cmake.sh -v
cmake --build _build
./run_all_unit_tests.sh
```

Try **examples/example.ff_101** for a first walkthrough. A local **STLSoft**
tree can be passed with `./prepare_cmake.sh --stlsoft-root-dir <dir>`. Full
options are in [**INSTALL.md**](./INSTALL.md); `./prepare_cmake.sh --help`.


## Installation

Detailed instructions — via **CMake** — are provided in the accompanying
[**INSTALL.md**](./INSTALL.md) file.

Consumer projects may use:

```cmake
find_package(FastFormat REQUIRED)
target_link_libraries(<your-target> PRIVATE FastFormat::fastformat)
```


### API documentation (Doxygen)

HTML API reference for the public headers may be generated locally:

```bash
./generate_doxygen.sh
```

Open `_build/doxygen/html/index.html` in a browser (or
`<build-dir>/doxygen/html/index.html` when `SIS_CMAKE_BUILD_DIR` is set).
Requires [Doxygen](https://www.doxygen.nl/) on `PATH`.


## Components

**FastFormat** is organised around a core formatting API, typed *inserters*,
output *sinks*, optional localised *bundles*, and helpers for format-defect
handling. The usual include is **`fastformat/ff.hpp`** (or
**`fastformat/fastformat.hpp`**), plus the sink header for the destination
you use.


### Core and application layer

| Header | Role |
| ------ | ---- |
| [`fastformat/fastformat.h`](./include/fastformat/fastformat.h) | Core types, version macros (`FASTFORMAT_VER`, `FASTFORMAT_VER_RELSTATUS`), C API entry points, initialisation |
| [`fastformat/fastformat.hpp`](./include/fastformat/fastformat.hpp) | C++ application layer: `fmt`, `fmtln`, `write`, `writeln`, `flush` |
| [`fastformat/ff.hpp`](./include/fastformat/ff.hpp) | Convenience include that pulls in the application layer |
| [`fastformat/exceptions.hpp`](./include/fastformat/exceptions.hpp) | Exception types |
| [`fastformat/init_codes.h`](./include/fastformat/init_codes.h) | Initialisation result codes |
| [`fastformat/implicit_link.h`](./include/fastformat/implicit_link.h) | Implicit-link helpers for selected toolchains |

Minimal use:

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


### Inserters

Typed adapters under [`include/fastformat/inserters/`](./include/fastformat/inserters/)
format values that are not already string-compatible. Common headers:

| Header | Purpose |
| ------ | ------- |
| [`to_i.hpp`](./include/fastformat/inserters/to_i.hpp) / [`integer.hpp`](./include/fastformat/inserters/integer.hpp) | Integral types |
| [`to_x.hpp`](./include/fastformat/inserters/to_x.hpp) | Integral types in hexadecimal |
| [`to_e.hpp`](./include/fastformat/inserters/to_e.hpp) / [`to_f.hpp`](./include/fastformat/inserters/to_f.hpp) / [`to_g.hpp`](./include/fastformat/inserters/to_g.hpp) / [`real.hpp`](./include/fastformat/inserters/real.hpp) | Floating-point forms |
| [`ch.hpp`](./include/fastformat/inserters/ch.hpp) / [`character.hpp`](./include/fastformat/inserters/character.hpp) | Character types |
| [`to_i_null_if_zero.hpp`](./include/fastformat/inserters/to_i_null_if_zero.hpp) / [`to_i_null_if_not.hpp`](./include/fastformat/inserters/to_i_null_if_not.hpp) | Nullable integral forms |
| [`WindowsLargeIntegers.hpp`](./include/fastformat/inserters/WindowsLargeIntegers.hpp) (and related) | Windows `LARGE_INTEGER` / `ULARGE_INTEGER` |


### Sinks

Sinks under [`include/fastformat/sinks/`](./include/fastformat/sinks/) receive
the formatted slices. Common headers:

| Header | Purpose |
| ------ | ------- |
| [`ostream.hpp`](./include/fastformat/sinks/ostream.hpp) | `std::ostream` |
| [`stringstream.hpp`](./include/fastformat/sinks/stringstream.hpp) | `std::stringstream` |
| [`FILE.hpp`](./include/fastformat/sinks/FILE.hpp) | `FILE*` |
| [`c_string.hpp`](./include/fastformat/sinks/c_string.hpp) / [`char_buffer.hpp`](./include/fastformat/sinks/char_buffer.hpp) | Fixed character buffers |
| [`auto_buffer.hpp`](./include/fastformat/sinks/auto_buffer.hpp) | **STLSoft** `auto_buffer` |
| [`null.hpp`](./include/fastformat/sinks/null.hpp) | Bit-bucket sink |
| [`CString.hpp`](./include/fastformat/sinks/CString.hpp) | MFC `CString` (Windows / MFC) |
| [`CComBSTR.hpp`](./include/fastformat/sinks/CComBSTR.hpp) | ATL `CComBSTR` (Windows / ATL) |
| [`OutputDebugString.hpp`](./include/fastformat/sinks/OutputDebugString.hpp) | Windows `OutputDebugString` |
| [`WindowsConsole.hpp`](./include/fastformat/sinks/WindowsConsole.hpp) / [`WindowsMessageBox.hpp`](./include/fastformat/sinks/WindowsMessageBox.hpp) | Windows console / message-box |
| [`speech.hpp`](./include/fastformat/sinks/speech.hpp) | Windows Speech API |
| [`vectored_file.hpp`](./include/fastformat/sinks/vectored_file.hpp) | UNIX `writev()` |


### Bundles

Localised format-string sources under
[`include/fastformat/bundles/`](./include/fastformat/bundles/):

| Header | Purpose |
| ------ | ------- |
| [`properties_bundle.hpp`](./include/fastformat/bundles/properties_bundle.hpp) | Java-style `.properties` files |
| [`winini_bundle.hpp`](./include/fastformat/bundles/winini_bundle.hpp) | Windows INI files |
| [`windows_resource_bundle.hpp`](./include/fastformat/bundles/windows_resource_bundle.hpp) | Windows resource strings |
| [`openrj_bundle.hpp`](./include/fastformat/bundles/openrj_bundle.hpp) | Open-RJ records |


### Iterators and format-defect handling

| Header | Purpose |
| ------ | ------- |
| [`iterators/format_iterator.hpp`](./include/fastformat/iterators/format_iterator.hpp) | Output iterator that formats each assigned value |
| [`format/standard_flags.hpp`](./include/fastformat/format/standard_flags.hpp) | Standard format flags (e.g. newline) |
| [`format/specification_defect_handling/`](./include/fastformat/format/specification_defect_handling/) | Scopes / handlers for ill-formed formats and mismatched arguments |


## Examples

Examples are provided in the [`examples`](./examples/) directory. A detailed
catalogue is in [**EXAMPLES.md**](./EXAMPLES.md). After a **CMake** build,
`./run_all_examples.sh` (or `run_all_examples.cmd` on Windows) exercises the
matching programs (see [**INSTALL.md**](./INSTALL.md)).

The shortest walkthrough is **example.ff_101**:

```cpp
#include <fastformat/ff.hpp>
#include <fastformat/sinks/ostream.hpp>

#include <iostream>
#include <string>

int main()
{
    std::string sink;

    ff::fmt(sink, "A c-style string: {0}", "arg0");

    ff::fmtln(std::cout, "A std::string: {0}", std::string("arg1"));
    ff::fmtln(std::cout, "An int: {0}", 10);

    return 0;
}
```


## Project Information


### Where to get help

* [GitHub repository](https://github.com/synesissoftware/FastFormat);
* [GitHub Issues](https://github.com/synesissoftware/FastFormat/issues);
* [**FAQ.md**](./FAQ.md);
* [**HOW_YOU_CAN_HELP.md**](./HOW_YOU_CAN_HELP.md);
* [**KNOWN_ISSUES.md**](./KNOWN_ISSUES.md);
* [http://www.fastformat.org/](http://www.fastformat.org/);


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on
https://github.com/synesissoftware/FastFormat.

If you'd like to help out with the project, please raise an issue via
[GitHub Issues](https://github.com/synesissoftware/FastFormat/issues) — you'll
be very welcome! See also [**HOW_YOU_CAN_HELP.md**](./HOW_YOU_CAN_HELP.md).


### Dependencies

**FastFormat** is a C++ library. Its public interface and implementation both
depend on **STLSoft**. Tests, examples, and (on Windows) some scratch
programs pull in further packages as listed below.


#### Runtime dependency

| Package | Minimum | Role | Required? |
| ------- | ------- | ---- | --------- |
| [**STLSoft**](https://github.com/synesissoftware/STLSoft) | **1.11** | Compiler/platform discrimination, string shims, containers, and related facilities used by the core library and the public C++ API | **Yes** — always |

**STLSoft** may be supplied as:

* a **CMake** package (`find_package(STLSoft 1.11 REQUIRED)`); or
* a tree pointed at by the **CMake** variable `STLSOFT` or the environment
  variable `STLSOFT` (include directory `${STLSOFT}/include`), e.g.
  `./prepare_cmake.sh --stlsoft-root-dir <dir>`.


#### Development dependencies

Required when `BUILD_TESTING` is on (the default for a full tree):

| Package | Minimum | Role | Required? |
| ------- | ------- | ---- | --------- |
| [**xTests**](https://github.com/synesissoftware/xTests) | **0.26** | Unit and component test harness | **Yes** when building tests |
| [**shwild**](https://github.com/synesissoftware/shwild) | (any installable package) | Optional; enables richer pattern matches in **xTests** (`XTESTS_HAS_SHWILD`) | No — detected with `find_package(shwild QUIET)` unless `NO_SHWILD` is set |

Examples (`BUILD_EXAMPLES`) use the same **STLSoft** install as the library;
they do not add a separate package beyond what the library already needs.


#### Windows-only test / scratch dependency

| Package | Minimum | Role | Required? |
| ------- | ------- | ---- | --------- |
| [**UNIXem**](https://github.com/synesissoftware/UNIXem) | **1.14.2** | Supplies `<unixem/unixem.h>` for Windows scratch programs that include that header | **Yes** when `WIN32` and `BUILD_TESTING` |

**UNIXem**'s own configure rejects non-Windows hosts. The modular CI
dependency list therefore appends **UNIXem** on Windows only
(`STLSoft shwild xTests UNIXem`).

Selected Windows programs also need host SDKs that are not CMake packages:

* MFC — `test.unit.sink.CString`, `test.scratch.overload.3.BSTR_out_parameter` (built only with MSVC; the BSTR scratch defines `_AFXDLL`);
* ATL — `test.component.sink.CComBSTR` (built only with MSVC);
* Windows Speech API / SAPI — `test.scratch.speech` (present in the tree; currently left out of the default Windows CMake build because the installed **STLSoft** SAPI helpers do not compile on current MSVC).


### Related projects

Projects that use or sit alongside **FastFormat** include:

* [**Pantheios**](https://github.com/synesissoftware/Pantheios) — diagnostic logging API (often paired with **FastFormat** for message preparation);
* [**STLSoft**](https://github.com/synesissoftware/STLSoft) — required runtime dependency;
* [**xTests**](https://github.com/synesissoftware/xTests) — test harness used by this tree;
* [**UNIXem**](https://github.com/synesissoftware/UNIXem) — Unix API emulation on Windows for selected scratch programs;


### License

**FastFormat** is released under the 3-clause BSD license. See
[**LICENSE**](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
