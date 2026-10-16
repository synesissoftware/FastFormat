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
  - [Utilities and string shims](#utilities-and-string-shims)
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

Line badges mark the **MAJOR.MINOR** line that first shipped each component
in the public API. Items that pre-date **0.7** are labelled **0.7**. The
**0.9** badge is reserved for a future line and is unused below.

![0.7](https://img.shields.io/badge/0.7-0A66C2)
![0.8](https://img.shields.io/badge/0.8-C45C26)
![0.9](https://img.shields.io/badge/0.9-6B4C9A)


### Core and application layer

| Header / API | Role | Since |
| ------------ | ---- | :---: |
| [`fastformat/fastformat.h`](./include/fastformat/fastformat.h) | Core types, version macros (`FASTFORMAT_VER`, `FASTFORMAT_VER_RELSTATUS`), C API entry points, initialisation | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| `fastformat_getVersion()` | Runtime packed version query | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| `fastformat_getParseCodeString[Length]()` / `fastformat_getReplacementCodeString[Length]()` | Human-readable strings for parse and replacement codes | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| Ill-formed / mismatched handler model (`ff_handler_response_t`, `ff_parse_action_t`, `ff_replacement_action_t`, `ff_*Handler_info_t` setters) | Explicit continue / next-handler responses and recovery actions (blank, literal, or slice) | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`fastformat/fastformat.hpp`](./include/fastformat/fastformat.hpp) | C++ application layer: `fmt`, `fmtln`, `write`, `writeln`, `flush` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`fastformat/ff.hpp`](./include/fastformat/ff.hpp) | Convenience include that pulls in the application layer | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`fastformat/exceptions.hpp`](./include/fastformat/exceptions.hpp) | Exception types; argument-count field is `numArguments` (was `numberOfReplacements` on **0.7**) | ![0.7](https://img.shields.io/badge/0.7-0A66C2) ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`fastformat/init_codes.h`](./include/fastformat/init_codes.h) | Initialisation result codes | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`fastformat/implicit_link.h`](./include/fastformat/implicit_link.h) | Implicit-link helpers for selected toolchains | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |

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

| Header | Purpose | Since |
| ------ | ------- | :---: |
| [`to_i.hpp`](./include/fastformat/inserters/to_i.hpp) / [`integer.hpp`](./include/fastformat/inserters/integer.hpp) | Integral types | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`to_x.hpp`](./include/fastformat/inserters/to_x.hpp) | Integral types in hexadecimal | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`to_e.hpp`](./include/fastformat/inserters/to_e.hpp) / [`to_f.hpp`](./include/fastformat/inserters/to_f.hpp) / [`to_g.hpp`](./include/fastformat/inserters/to_g.hpp) / [`real.hpp`](./include/fastformat/inserters/real.hpp) | Floating-point forms | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`ch.hpp`](./include/fastformat/inserters/ch.hpp) / [`character.hpp`](./include/fastformat/inserters/character.hpp) | Character types | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`to_i_null_if_zero.hpp`](./include/fastformat/inserters/to_i_null_if_zero.hpp) / [`to_i_null_if_not.hpp`](./include/fastformat/inserters/to_i_null_if_not.hpp) | Nullable integral forms | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`WindowsLargeIntegers.hpp`](./include/fastformat/inserters/WindowsLargeIntegers.hpp) (and related) | Windows `LARGE_INTEGER` / `ULARGE_INTEGER` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`storage_size.hpp`](./include/fastformat/inserters/storage_size.hpp) | Unsigned byte counts as size-qualified text (`990B`, `12kB`, `1MB`, …) | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`lc_i.hpp`](./include/fastformat/inserters/lc_i.hpp) | Locale-aware integers (`localeconv` grouping / thousands separator) | ![0.8](https://img.shields.io/badge/0.8-C45C26) |


### Sinks

Sinks under [`include/fastformat/sinks/`](./include/fastformat/sinks/) receive
the formatted slices. Common headers:

| Header | Purpose | Since |
| ------ | ------- | :---: |
| [`ostream.hpp`](./include/fastformat/sinks/ostream.hpp) | `std::ostream` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`iostream.hpp`](./include/fastformat/sinks/iostream.hpp) | Shorthand for the `std::ostream` sink plus `<iostream>` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`stringstream.hpp`](./include/fastformat/sinks/stringstream.hpp) | `std::stringstream` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`FILE.hpp`](./include/fastformat/sinks/FILE.hpp) | `FILE*` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`stlsoft/FILE_stream.hpp`](./include/fastformat/sinks/stlsoft/FILE_stream.hpp) | **STLSoft** `FILE_stream` / `thread_shareable_FILE_stream` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`c_string.hpp`](./include/fastformat/sinks/c_string.hpp) / [`char_buffer.hpp`](./include/fastformat/sinks/char_buffer.hpp) | Fixed character buffers | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`auto_buffer.hpp`](./include/fastformat/sinks/auto_buffer.hpp) | **STLSoft** `auto_buffer` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`null.hpp`](./include/fastformat/sinks/null.hpp) | Bit-bucket sink | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`CString.hpp`](./include/fastformat/sinks/CString.hpp) | MFC `CString` (Windows / MFC) | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`CComBSTR.hpp`](./include/fastformat/sinks/CComBSTR.hpp) | ATL `CComBSTR` (Windows / ATL) | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`OutputDebugString.hpp`](./include/fastformat/sinks/OutputDebugString.hpp) | Windows `OutputDebugString` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`WindowsConsole.hpp`](./include/fastformat/sinks/WindowsConsole.hpp) / [`WindowsMessageBox.hpp`](./include/fastformat/sinks/WindowsMessageBox.hpp) | Windows console / message-box | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`speech.hpp`](./include/fastformat/sinks/speech.hpp) | Windows Speech API | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`vectored_file.hpp`](./include/fastformat/sinks/vectored_file.hpp) | UNIX `writev()` | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`exception.hpp`](./include/fastformat/sinks/exception.hpp) | Format into a message, then `throw` a chosen exception type | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`ribbon.hpp`](./include/fastformat/sinks/ribbon.hpp) | Width-capped write to a string (truncate / truncate+ellipsis) | ![0.8](https://img.shields.io/badge/0.8-C45C26) |


### Bundles

Localised format-string sources under
[`include/fastformat/bundles/`](./include/fastformat/bundles/):

| Header | Purpose | Since |
| ------ | ------- | :---: |
| [`properties_bundle.hpp`](./include/fastformat/bundles/properties_bundle.hpp) | Java-style `.properties` files | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`winini_bundle.hpp`](./include/fastformat/bundles/winini_bundle.hpp) | Windows INI files | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`windows_resource_bundle.hpp`](./include/fastformat/bundles/windows_resource_bundle.hpp) | Windows resource strings | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`openrj_bundle.hpp`](./include/fastformat/bundles/openrj_bundle.hpp) | Open-RJ records | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |


### Utilities and string shims

| Header / API | Purpose | Since |
| ------------ | ------- | :---: |
| [`util/filesystem/FILE_functions.hpp`](./include/fastformat/util/filesystem/FILE_functions.hpp) (`fopen_or_throw()`) | Open a `FILE*` or throw on failure | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`shims/access/string/parse_code.hpp`](./include/fastformat/shims/access/string/parse_code.hpp) | String access shims for `ff_parse_code_t` | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`shims/access/string/replacement_code.hpp`](./include/fastformat/shims/access/string/replacement_code.hpp) | String access shims for `ff_replacement_code_t` | ![0.8](https://img.shields.io/badge/0.8-C45C26) |
| [`shims/access/string/string_slice.hpp`](./include/fastformat/shims/access/string/string_slice.hpp) | String access shims for `ff_string_slice_t` | ![0.8](https://img.shields.io/badge/0.8-C45C26) |


### Iterators and format-defect handling

| Header | Purpose | Since |
| ------ | ------- | :---: |
| [`iterators/format_iterator.hpp`](./include/fastformat/iterators/format_iterator.hpp) | Output iterator that formats each assigned value | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`format/standard_flags.hpp`](./include/fastformat/format/standard_flags.hpp) | Standard format flags (e.g. newline) | ![0.7](https://img.shields.io/badge/0.7-0A66C2) |
| [`format/specification_defect_handling/`](./include/fastformat/format/specification_defect_handling/) | Scopes / handlers for ill-formed formats and mismatched arguments (action model extended on **0.8**; see Core) | ![0.7](https://img.shields.io/badge/0.7-0A66C2) ![0.8](https://img.shields.io/badge/0.8-C45C26) |


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
