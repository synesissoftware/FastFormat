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
  * [ ] include/fastformat/sinks/WindowsFileHANDLE.hpp;
  * [ ] synchronisation of ostream sink : spin / thread_mutex;
  * [ ] include/fastformat/sinks/to_sink.hpp;


## Performance improvements

* \<none>


## Packaging improvements

* [-] ~~~full distribution of makefiles, project files, workspace files, etc. (legacy build trees removed; CMake-only)~~~ - ❌;
* [ ] decent docs;
* [ ] decent website;
* [ ] GNU Autotools : "./configure; make; make install";
* [ ] Debian package;
* [ ] RPM package;


<!-- ########################### end of file ########################### -->
