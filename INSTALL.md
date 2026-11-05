# FastFormat - Installation and Use <!-- omit in toc -->

Updated:    5th November 2026


## Table of Contents <!-- omit in toc -->

- [Installing](#installing)
  - [Cloning project, installing via CMake (recommended)](#cloning-project-installing-via-cmake-recommended)
  - [Downloading a release archive, installing via CMake](#downloading-a-release-archive-installing-via-cmake)
- [Understanding the top-level project build scripts](#understanding-the-top-level-project-build-scripts)


## Installing

There are two supported ways to obtain and install **FastFormat**, and both use **CMake**. The recommended way is to [clone and install via CMake](#cloning-project-installing-via-cmake-recommended). The other is to [download a release archive and install via CMake](#downloading-a-release-archive-installing-via-cmake).


### Cloning project, installing via CMake (recommended)

0. First, ensure that [**STLSoft**](https://github.com/synesissoftware/STLSoft) (**1.11.5** or later) has been cloned and then built and installed via CMake, as per the instructions in that project. To build and run the tests, install [**xTests**](https://github.com/synesissoftware/xTests) (**0.28.2** or later) the same way; pass **`--disable-testing`** to **prepare_cmake.sh** when **xTests** is not installed. Optionally, install [**shwild**](https://github.com/synesissoftware/shwild) (richer **xTests** matches) and [**woad**](https://github.com/synesissoftware/woad) (colour for **test.scratch.versions**, via **`--use-woad`**). On Windows, when tests are enabled, also install [**UNIXem**](https://github.com/synesissoftware/UNIXem) (**1.14.2** or later) so scratch programs that include `<unixem/unixem.h>` can build.


1. Clone **FastFormat** from GitHub, as in;

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ git clone -b dev-0.8 https://github.com/synesissoftware/FastFormat
```

2. "Prepare" the **CMake** build context:

When using **CMake**, a prepare-step is required. In order to assist with getting the correct incantations for CMake use, [a number of build scripts are provided](#understanding-the-top-level-project-build-scripts). (Look for the **.sh** files in the root directory of the project.)

If you're working on Linux and OSX, or using Git Bash (or similar) on Windows, then you can use the CMake driver script **prepare_cmake.sh** provided by the project, as follows:

```bash
$ cd ~/open-source/FastFormat
$ ./prepare_cmake.sh
```

---
**NOTE**

The **prepare_cmake.sh** script has a bunch of command-line flags/options to customise the compilation, which can be obtained by using the flag `--help`, which gives the following output in the current version:

```plaintext
FastFormat is an extremely fast, 100% type-safe, infinitely-extensible, I18N/L10N-friendly C++ output/formatting library
Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
Copyright (c) 2006-2019, Matthew Wilson and Synesis Software
Creates/reinitialises the CMake build script(s)

./prepare_cmake.sh [ ... flags/options ... ]

Flags/options:

    behaviour:

    -A
    --always-use-colors
    --always-use-colours
        forces use of colours even when stdout is not a TTY

    --build-shared-libs
        builds FastFormat as a shared library (BUILD_SHARED_LIBS=ON)

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (CMAKE_VERBOSE_MAKEFILE=ON)

    -d
    --debug-configuration
        use Debug configuration (CMAKE_BUILD_TYPE=Debug). Default is Release

    -E
    --disable-examples
        disables building of examples (BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (BUILD_TESTING=OFF)

    --mingw
        uses explicitly the "MinGW Makefiles" generator

    --msvc-mt
        when using Visual C++ (MSVC), select the static runtime library

    -m
    --run-make
        executes a build via cmake --build after a successful configure

    --use-woad
        opts in to the woad library (USE_WOAD=ON), whose version is then
        reported, in colour, by test.scratch.versions


    standard flags:

    --help
        displays this help and terminates

```

If you are using **MinGW**/**MinGW-64** on Windows, you should specify `--mingw`.

If you are using **Visual C++** (on Windows) and want to use static linking, specify `--msvc-mt`.

If you wish to prepare and build in one step, you should specify `-m` (=== `--run-make`).

If you don't want to build examples, you should specify `-E` (=== `--disable-examples`).

If you don't want to build tests, you should specify `-T` (=== `--disable-testing`), in which case there is no need for **xTests** to be available.

**shwild**, when installed, enables richer pattern matches in **xTests**. **woad** is used only when `--use-woad` is passed, and then only to colour **test.scratch.versions**.


---

3. Install the **CMake** build artefacts such that they are available for use _and_ that **FastFormat** may be found by other **CMake**-based installations:

```bash
$ cd ~/open-source/FastFormat
$ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
```

(**NOTE**: The recommended installation path remains [Cloning project, installing via CMake](#cloning-project-installing-via-cmake-recommended).)

A consumer target links the exported library:

```cmake
find_package(FastFormat REQUIRED)

target_link_libraries(hello
    PRIVATE
        FastFormat::fastformat
)
```

The shortest program that uses that target is in [**README.md**](./README.md) under **Developer Experience**.


### Downloading a release archive, installing via CMake

0. Install the same prerequisites as in the clone section: [**STLSoft**](https://github.com/synesissoftware/STLSoft) (**1.11.5** or later), built and installed with **CMake**. [**xTests**](https://github.com/synesissoftware/xTests) (**0.28.2** or later) is required when tests are built. Optional [**shwild**](https://github.com/synesissoftware/shwild), [**woad**](https://github.com/synesissoftware/woad), and (on Windows) [**UNIXem**](https://github.com/synesissoftware/UNIXem) are the same as there. Release archives for the Synesis libraries are on each project's GitHub tags page.


1. Download the **FastFormat** **0.8.1-beta1** archive (or a later tag) and unpack it, as in:

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ curl -L -o FastFormat-0.8.1-beta1.zip https://github.com/synesissoftware/FastFormat/archive/refs/tags/0.8.1-beta1.zip
$ unzip FastFormat-0.8.1-beta1.zip
```

The archive unpacks to **FastFormat-0.8.1-beta1**.


2. Prepare, build, and install from that directory. The flags are the same as [step 2 of the clone section](#cloning-project-installing-via-cmake-recommended):

```bash
$ cd ~/open-source/FastFormat-0.8.1-beta1
$ ./prepare_cmake.sh
$ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
```

(`./prepare_cmake.sh -m` prepares and builds in one step.)


----


## Understanding the top-level project build scripts

These **Bash** scripts live in the project root and drive a **CMake** build. Each `run_all_*.sh` has a native **`cmd.exe`** counterpart of the same basename (`run_all_unit_tests.cmd`, and so on) for Windows hosts that do not use Bash.

| Script | Purpose |
| ------ | ------- |
| **build_cmake.sh** | Rebuilds from an existing **CMake** tree. Meaningful only after **prepare_cmake.sh** has configured once.<br/><br/>Use `./build_cmake.sh --help` for further information. |
| **clean_cmake.sh** | Cleans the **CMake** build tree. Meaningful only after a configure and a build.<br/><br/>Use `./clean_cmake.sh --help` for further information. |
| **ctest_cmake.sh** | Runs **CTest** over the configured build (builds first unless `-M`).<br/><br/>Use `./ctest_cmake.sh --help` for further information. |
| **generate_doxygen.sh** | Generates HTML API documentation from the public headers (output under `_build/doxygen` by default; honours **`SIS_CMAKE_BUILD_DIR`**).<br/><br/>Use `./generate_doxygen.sh --help` for further information. |
| **libver.sh** | Builds (unless `-M`) and runs **test.scratch.versions**, which prints composite version macros for **FastFormat** and its discovered dependencies.<br/><br/>Use `./libver.sh --help` for further information. |
| **prepare_cmake.sh** | Creates or reinitialises the **CMake** build. Recommended first command: `./prepare_cmake.sh -m -v` (`-m` builds after a successful configure; `-v` sets `CMAKE_VERBOSE_MAKEFILE`).<br/><br/>Use `./prepare_cmake.sh --help` for further information. |
| **remove_cmake_artefacts.sh** | Deletes the build directory (default `./_build`, or **`SIS_CMAKE_BUILD_DIR`**) so **prepare_cmake.sh** can start again.<br/><br/>Use `./remove_cmake_artefacts.sh --help` for further information. |
| **run_all_automated_tests.sh** | Builds (unless suppressed) and runs unit and component tests. `--unit-only` and `--component-only` select one category.<br/><br/>Use `./run_all_automated_tests.sh --help` for further information. |
| **run_all_component_tests.sh** | Builds (unless suppressed) and runs component-test programs (`test.component.*`).<br/><br/>Use `./run_all_component_tests.sh --help` for further information. |
| **run_all_examples.sh** | Builds (unless suppressed) and runs example programs (`example*`, excluding `*.md`).<br/><br/>Use `./run_all_examples.sh --help` for further information. |
| **run_all_performance_tests.sh** | Builds (unless suppressed) and runs performance-test programs (`test.performance.*`).<br/><br/>Use `./run_all_performance_tests.sh --help` for further information. |
| **run_all_scratch_tests.sh** | Builds (unless suppressed) and runs scratch programs (`test.scratch.*`). Honours `--skip-interactive`.<br/><br/>Use `./run_all_scratch_tests.sh --help` for further information. |
| **run_all_unit_tests.sh** | Builds (unless suppressed) and runs unit-test programs (`test.unit.*` and the legacy `test_unit*` form).<br/><br/>Use `./run_all_unit_tests.sh --help` for further information. |


<!-- ########################### end of file ########################### -->
