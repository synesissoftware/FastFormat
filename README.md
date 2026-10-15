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
- [Project Information](#project-information)


## Introduction

**FastFormat** is an extremely fast, 100% type-safe, infinitely-extensible,
I18N/L10N-friendly output/formatting library.


## Developer Experience

**FastFormat** needs [**STLSoft**](https://github.com/synesissoftware/STLSoft)
**1.11** or later. Examples and tests also need
[**xTests**](https://github.com/synesissoftware/xTests) **0.26** or later;
[**shwild**](https://github.com/synesissoftware/shwild) is optional and
enables richer **xTests** matches. On Windows, scratch programs that
include `<unixem/unixem.h>` need
[**UNIXem**](https://github.com/synesissoftware/UNIXem), via
`find_package(UNIXem)`.

```bash
./prepare_cmake.sh -v
cmake --build _build
./run_all_unit_tests.sh
```

A local **STLSoft** tree can be passed with
`./prepare_cmake.sh --stlsoft-root-dir <dir>`. Full options are in
**INSTALL.md**; `./prepare_cmake.sh --help`.


## Installation

Detailed instructions are in the accompanying **INSTALL.md**.


## Project Information

If you'd like to help out with the project, see **HOW_YOU_CAN_HELP.md**, or
contact us via https://github.com/synesissoftware/FastFormat — you'll be
very welcome!

For the FAQ, see **FAQ.md**. For changes in the releases, see **CHANGES.md**.
For the release chronology, see **NEWS.md**.


<!-- ########################### end of file ########################### -->
