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
overloads. Names follow the `example.<area>.…` form used by the
**CMake** targets.

| Group | Purpose |
| ----- | ------- |
| **arguments.*** | Built-in argument types (boolean, character, reals, void pointers) |
| **ff_101*** | First walkthrough of `fmt` / sinks |
| **flush** | Explicit `flush()` |
| **inserter.*** | Typed inserters (integers, hex, reals, Windows large integers) |
| **iterators.*** | `format_iterator` |
| **overload.*** | Custom-type and layout overloads |
| **pad.*** | Padding / hash formatting |
| **sink.*** | Specific sinks (`c_string`, `OutputDebugString`, …) |

Two directories remain in the tree but are currently commented out of
**examples/CMakeLists.txt**: **example.memory.1** and
**example.overload.3.server_log**. Windows-only examples are gated on
`_BUILD_AS_WIN32`.


## Catalogue

| Name | Source | Platform | Summary |
| ---- | ------ | -------- | ------- |
| **example.arguments.boolean** | [example.arguments.boolean](./examples/example.arguments.boolean/) | * | Boolean arguments |
| **example.arguments.character** | [example.arguments.character](./examples/example.arguments.character/) | * | Character arguments |
| **example.arguments.reals** | [example.arguments.reals](./examples/example.arguments.reals/) | * | Floating-point arguments |
| **example.arguments.void_pointers** | [example.arguments.void_pointers](./examples/example.arguments.void_pointers/) | * | Void-pointer arguments |
| **example.ff_101** | [example.ff_101](./examples/example.ff_101/) | * | Introductory walkthrough of sinks and `fmt` |
| **example.ff_101.no_namespace** | [example.ff_101.no_namespace](./examples/example.ff_101.no_namespace/) | * | Same walkthrough without the **FastFormat** namespace |
| **example.flush** | [example.flush](./examples/example.flush/) | * | Explicit `flush()` |
| **example.inserter.hex** | [example.inserter.hex](./examples/example.inserter.hex/) | * | Hexadecimal integer inserters |
| **example.inserter.integers** | [example.inserter.integers](./examples/example.inserter.integers/) | * | Integer inserters |
| **example.inserter.integers.WindowsLargeIntegers** | [example.inserter.integers.WindowsLargeIntegers](./examples/example.inserter.integers.WindowsLargeIntegers/) | Windows | Windows `LARGE_INTEGER` / `ULARGE_INTEGER` inserters |
| **example.inserter.reals** | [example.inserter.reals](./examples/example.inserter.reals/) | * | Floating-point inserters |
| **example.iterators.format_iterator** | [example.iterators.format_iterator](./examples/example.iterators.format_iterator/) | * | `format_iterator` |
| **example.memory.1** | [example.memory.1](./examples/example.memory.1/) | * | Memory / allocation behaviour (not in the default **CMake** build) |
| **example.overload.2.custom_type.filter_type** | [example.overload.2.custom_type.filter_type](./examples/example.overload.2.custom_type.filter_type/) | * | Custom type via `filter_type` |
| **example.overload.2.custom_type.inserter** | [example.overload.2.custom_type.inserter](./examples/example.overload.2.custom_type.inserter/) | * | Custom type via an inserter (uses a `.properties` bundle) |
| **example.overload.2.custom_type.string_access_shims** | [example.overload.2.custom_type.string_access_shims](./examples/example.overload.2.custom_type.string_access_shims/) | * | Custom type via string-access shims |
| **example.overload.3.floatingpoint_columns** | [example.overload.3.floatingpoint_columns](./examples/example.overload.3.floatingpoint_columns/) | * | Floating-point column layout |
| **example.overload.3.record_insert** | [example.overload.3.record_insert](./examples/example.overload.3.record_insert/) | * | Record-insert overload |
| **example.overload.3.server_log** | [example.overload.3.server_log](./examples/example.overload.3.server_log/) | * | Server-log overload (not in the default **CMake** build) |
| **example.overload.3.tabulations** | [example.overload.3.tabulations](./examples/example.overload.3.tabulations/) | * | Tabulation overload |
| **example.pad.hash** | [example.pad.hash](./examples/example.pad.hash/) | * | Padding / hash formatting |
| **example.sink.c_string** | [example.sink.c_string](./examples/example.sink.c_string/) | * | `c_string` sink |
| **example.sink.OutputDebugString** | [example.sink.OutputDebugString](./examples/example.sink.OutputDebugString/) | Windows | Windows `OutputDebugString` sink |


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
