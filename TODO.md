# FastFormat - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* [ ] ensure that platform-specific EOL is only emitted in file output;
* [ ] inserters:
  * [ ] lc_i - these will do "thousands" (or whatever is appropriate to a given locale) formatting on integers, e.g. "100,000,000";
  * [ ] storage_size;
* [ ] sinks:
  * [ ] add macOS speech variant;
  * [ ] include/fastformat/sinks/WindowsFileHANDLE.hpp;
  * [ ] include/fastformat/sinks/to_sink.hpp;
  * [ ] re-enable speech output;
  * [ ] synchronisation of ostream sink : spin / thread_mutex;


## Performance improvements

* \<none>


## Packaging improvements

* [x] ~~~full distribution of makefiles, project files, workspace files, etc. (legacy build trees removed; CMake-only)~~~ - ❌;
* [ ] diagnose MinGW access violation in **example.overload.2.custom_type.inserter** when constructing / using **`properties_bundle`** (bundle-free overloads are fine; that path is skipped under `__MINGW32__` until fixed);
* [ ] create an **xTests**-like internal **`checked_main`** (**include/fastformat/internal/checked_main.hpp**, mirroring **xtests/internal/checked_main.hpp**) and apply it across examples, unit/component/scratch/performance programs that currently hand-roll `main` / `main_` exception and CRT-leak wrappers;
* [ ] create a set of internal helper macros (as in gold projects such as **Pantheios** and **STLSoft**) for language/compiler compatibility — e.g. public copy / closed assignment (`= delete` vs C++03 private declaration), and related facilities — and replace ad-hoc definitions such as **`FASTFORMAT_EXCEPTION_NO_ASSIGN_`** in **exceptions.hpp**;
* [ ] remove all implicit-link files and inclusions (keep **implicit_link.h**);
* [ ] simplify example and directory names (drop redundant `example.` / deep `overload.N.` nesting where a shorter stem still reads clearly; keep CMake targets and **EXAMPLES.md** in sync);
* [ ] decent docs;
* [ ] decent website;
* [ ] Debian package;
* [ ] GNU Autotools : "./configure; make; make install";
* [ ] RPM package;


<!-- ########################### end of file ########################### -->
