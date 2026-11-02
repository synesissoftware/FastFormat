# FastFormat - Examples <!-- omit in toc -->

This index lists the sample programs under [`examples/`](./examples/). See
[README.md](./README.md#examples) for a short inline walkthrough. After a
**CMake** build, `./run_all_examples.sh` (or `run_all_examples.cmd` on
Windows) exercises matching programs (see [INSTALL.md](./INSTALL.md)).


## Table of Contents <!-- omit in toc -->

- [Overview](#overview)
- [Catalogue](#catalogue)
- [Building and running](#building-and-running)


## Overview

Each example is a small C++ program that exercises one facet of
**FastFormat** — arguments, inserters, sinks, iterators, or custom-type
overloads. Programs live under **examples/**. **CMake** targets follow
`example.cpp.<area>.…`.

| Group | Purpose |
| ----- | ------- |
| **101** | First walkthrough of `fmt` / sinks (`normal`, `no_namespace`) |
| **arguments** | Built-in argument types (boolean, character, reals, void pointers) |
| **flush** | Explicit `flush()` |
| **inserters** | Typed inserters (integers, hex, reals, Windows large integers) |
| **iterators** | `format_iterator` |
| **overload** | Custom-type and layout overloads |
| **pad** | Padding / hash formatting |
| **sink** | Specific sinks (`c_string`, `OutputDebugString`, …) |

Two programs remain in the tree but are currently commented out of the
build: **example.cpp.memory** (in **examples/CMakeLists.txt**) and
**example.cpp.overload.3.server_log** (in
**examples/overload/3/CMakeLists.txt**). Windows-only examples are
gated on `_BUILD_AS_WIN32`.


## Catalogue

| Name | Source | Platform | Summary |
| ---- | ------ | -------- | ------- |
| **example.cpp.101.no_namespace** | [101/no_namespace](./examples/101/no_namespace/) | * | Same walkthrough without the **FastFormat** namespace |
| **example.cpp.101.normal** | [101/normal](./examples/101/normal/) | * | Introductory walkthrough of sinks and `fmt` |
| **example.cpp.arguments.boolean** | [arguments/boolean](./examples/arguments/boolean/) | * | Boolean arguments |
| **example.cpp.arguments.character** | [arguments/character](./examples/arguments/character/) | * | Character arguments |
| **example.cpp.arguments.reals** | [arguments/reals](./examples/arguments/reals/) | * | Floating-point arguments |
| **example.cpp.arguments.void_pointers** | [arguments/void_pointers](./examples/arguments/void_pointers/) | * | Void-pointer arguments |
| **example.cpp.flush** | [flush](./examples/flush/) | * | Explicit `flush()` |
| **example.cpp.inserters.hex** | [inserters/hex](./examples/inserters/hex/) | * | Hexadecimal integer inserters |
| **example.cpp.inserters.integers** | [inserters/integers](./examples/inserters/integers/) | * | Integer inserters |
| **example.cpp.inserters.integers.WindowsLargeIntegers** | [inserters/integers/WindowsLargeIntegers](./examples/inserters/integers/WindowsLargeIntegers/) | Windows | Windows `LARGE_INTEGER` / `ULARGE_INTEGER` inserters |
| **example.cpp.inserters.reals** | [inserters/reals](./examples/inserters/reals/) | * | Floating-point inserters |
| **example.cpp.iterators.format_iterator** | [iterators/format_iterator](./examples/iterators/format_iterator/) | * | `format_iterator` |
| **example.cpp.memory** | [memory](./examples/memory/) | * | Memory / allocation behaviour (not in the default **CMake** build) |
| **example.cpp.overload.2.custom_type.filter_type** | [overload/2/custom_type/filter_type](./examples/overload/2/custom_type/filter_type/) | * | Custom type via `filter_type` |
| **example.cpp.overload.2.custom_type.inserter** | [overload/2/custom_type/inserter](./examples/overload/2/custom_type/inserter/) | * | Custom type via an inserter (uses a `.properties` bundle) |
| **example.cpp.overload.2.custom_type.string_access_shims** | [overload/2/custom_type/string_access_shims](./examples/overload/2/custom_type/string_access_shims/) | * | Custom type via string-access shims |
| **example.cpp.overload.3.floatingpoint_columns** | [overload/3/floatingpoint_columns](./examples/overload/3/floatingpoint_columns/) | * | Floating-point column layout |
| **example.cpp.overload.3.record_insert** | [overload/3/record_insert](./examples/overload/3/record_insert/) | * | Record-insert overload |
| **example.cpp.overload.3.server_log** | [overload/3/server_log](./examples/overload/3/server_log/) | * | Server-log overload (not in the default **CMake** build) |
| **example.cpp.overload.3.tabulations** | [overload/3/tabulations](./examples/overload/3/tabulations/) | * | Tabulation overload |
| **example.cpp.pad.hash** | [pad/hash](./examples/pad/hash/) | * | Padding / hash formatting |
| **example.cpp.sink.OutputDebugString** | [sink/OutputDebugString](./examples/sink/OutputDebugString/) | Windows | Windows `OutputDebugString` sink |
| **example.cpp.sink.c_string** | [sink/c_string](./examples/sink/c_string/) | * | `c_string` sink |


## Building and running

Configure and build with examples enabled (the default for
**prepare_cmake.sh**):

```bash
./prepare_cmake.sh -v
cmake --build _build
```

Run every discovered example program:

```bash
./run_all_examples.sh -M
```

On Windows, use the native runner under `cmd.exe`:

```bat
call run_all_examples.cmd
```


<!-- ########################### end of file ########################### -->
