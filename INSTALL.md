FastFormat - Install
====================

Updated:    26th September 2015


The following steps are required to install FastFormat:

    1. Download the latest distribution of FastFormat, from
       http://fastformat.org/

    2. Unzip it to a directory of your choice, e.g c:\3pty\fastformat-0.7.1

    3. Define an environment variable FASTFORMAT_ROOT, whose
       value is the directory in which you unzipped
       it, e.g. FASTFORMAT_ROOT=c:\3pty\fastformat-0.7.1

    4. Download the latest distribution of STLSoft, from http://stlsoft.org/

    5. Unzip it to a directory of your choice, e.g c:\3pty\stlsoft-1.9.121

    6. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=c:\3pty\stlsoft-1.9.121

    7. Open a command shell in the appropriate directory that matches your
       compiler:

       * if you're compiling with Visual C++ 7.1 then cd to build/vc71
       * if you're compiling for UNIX with GCC 4.5, then cd
         to build/gcc42.unix
       * if you're compiling for Win-x64 with Visual C++ 9, then cd
         to build/vc9.x64

    8. Build using make:

       * to build the FastFormat core libraries: "make build.libs.core"
       * to build all libraries, examples and test: "make build"
       * to build and run unit/component tests: "make test"
       * to build and run performance tests: "make test.performance"
       * to build and run performance tests with Boost and Loki libraries,
         assuming the definition of environment variables BOOST and LOKI:
          "make -e test.performance"

NOTE: FastFormat depends on the (header-only) STLSoft libraries - version
  1.9.121 or later - available from http://www.stlsoft.org/.


=============================== End of file ================================

