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
* [ ] remove all implicit-link files and inclusions (keep **implicit_link.h**);
* [ ] decent docs;
* [ ] decent website;
* [ ] Debian package;
* [ ] GNU Autotools : "./configure; make; make install";
* [ ] RPM package;


<!-- ########################### end of file ########################### -->
