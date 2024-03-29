FastFormat - FAQ
================

Updated:    11th December 2010



The FAQ list is under (constant) development. If you post a question on the
Tutorials forum (https://sourceforge.net/forum/forum.php?forum_id=828687)
it will be used to create one.

FAQs:
=====

Q1: "How do I build FastFormat?"

A1:
  There are two ways:
  
    1. Build from the command-line
    2. Build from the Visual Studio IDE

  Method 1 is prefered, because FastFormat comes with a comprehensive set of
  makefiles for all supported compilers, whereas it (currently) comes with
  project files comprehensive only for Visual Studio '98 (aka Visual C++ 6),
  along with an incomplete set for Visual Studio 2005 and 2008. (FYI: this
  is solely due to a delay in finalising the project file generator to
  produce all version of Visual C++ project files, along with Borland,
  XCode, and more. It should *not* be interpreted to mean that FastFormat
  works only with the anachronistic Visual C++ 6.)

  To build from the command-line you need to do the following:

    A. Download and extract the latest FastFormat and STLSoft distributions,
       according to the instructions given in FAQ #2
    B. Open a console/command-box and change directory to reside in the
       $FASTFORMAT_ROOT/build directory. For example, if you're on UNIX and
       have installed FastFormat to /3pty/fastformat-0.7.1, then cd to 
       /3pty/fastformat-0.7.1/build.
    C. Next cd to the directory reflecting your compiler. For example, if
       you're using Visual C++ 9 for x64, you would cd to 'vc9.x64'
    D. Finally, build the library, using the appropriate make command for
       your compiler (make for GCC, nmake for VC++, etc.). We suggest you
       make and test, by the command

         > make build test

       Alternatively, if you want to build the FastFormat core libraries and
       nothing else, issue the command

         > make build.libs.core


Q2: "How do I install FastFormat?"

A2:
  There are four steps:
    1. Download the latest distribution of FastFormat, from http://fastformat.org/
    2. Extract it to a directory of your choice, e.g c:\3pty\fastformat-0.7.1
    3. Define an environment variable FASTFORMAT_ROOT, whose value is the directory
       in which you unzipped it, e.g. FASTFORMAT_ROOT=c:\3pty\fastformat-0.7.1
    4. Download the latest distribution of STLSoft, from http://stlsoft.org/
    5. Extract it to a directory of your choice, e.g c:\3pty\stlsoft-1.9.104
    6. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=c:\3pty\stlsoft-1.9.104


Q3: "How do I use FastFormat?"

A3:
  Assuming you've built and installed it (as per instructions in FAQ #1 and FAQ #2):

  In your IDE settings, add the include directories $(FASTFORMAT_ROOT)/include
  and $(STLSOFT)/include, OR in your makefiles, add the include directories:
    * -I$FASTFORMAT_ROOT/include and -I$STLSOFT/include (if you're on UNIX), OR
    * -I%FASTFORMAT_ROOT%/include and -I%STLSOFT%/include (if you're on Windows)

  Then you simply #include the headers you want, and use the components. For
  example, to use fstream without Abstraction Dissonance (see A4 & A5), you
  could do the following:

    #include <fastformat/fastformat.hpp>

    #include <iostream>
    #include <string>

    int main()
    {
      char         arg0[] = "abc";
      std::string  arg1   = "def";
      int          arg3   = -101;

      std::string  result;

      // format to a string
      fastformat::fmt(result, "Arguments in arbitrary order, such as {2}, {0} and {1}", arg0, arg1, arg2);

      // format to cout, with a newline
      fastformat::fmtln(std::cout, "Arguments in arbitrary order, such as {2}, {0} and {1}", arg0, arg1, arg2);

      return 0;
    }



Q4: "How does FastFormat work?"

A4:
  It defines a Type Tunnel whose interface is N-ary Generated Function
  Templates, and whose tunnel mechanism is Shims.


Q5: "What is a 'Type Tunnel', what are 'N-ary Generated Function
  Templates', and what are 'Shims' ?"

A5:
  Those things are all explained in in detail in the forthcoming book
  "Breaking Up The Monolith: Advanced C++ Design Without Compromise". See
  http://breakingupthemonolith.com/glossary.html#type-tunnel for a start on
  finding out.


Q6: "Is it possible to set the width, precision, alignment, etc. of
  [floating point] numbers in FastFormat?"

A6:
  As of version 0.3.1 beta 4 (released 9th March 2009) it is. You can use
  the fastformat::real() inserter function(s) suite, as shown in the
  test.component.inserter.real test program.


Q7: "Why have both "Write" and "Format" APIs?"

A7:
  It's simply because there are two ways of doing formatted output: 
  concatenation-based (a la FastFormat.Write, IOStreams) and 
  replacement-based (a la FastFormat.Format, Boost.Format, Streams)

  Each has their pros and cons:
   * FastFormat.Write is usually faster, and is 100% robust - it is
     impossible to compile defective code using it!
   * FastFormat.Format is more flexible, only uses arguments once, and
     supports I18N/L10N

  By supporting both, you get to choose whichever is more appropriate. None
  of the other major formatting libraries allow this (as well as being less
  robust, less flexible, and a *lot* less efficient.)

  You can read more about the issues in the series of articles in the ACCU's
  Overload magazine. The first instalment is now online at
  http://accu.org/index.php/journals/1539


Q8: "What's the fastest way to convert an integer to a string?"

A8:
  The answer to this is quite involved, so the best thing is to consult the
  publication lists on http://synesis.com.au/publications.html and
  http://fastformat.org/
  
  However, in brief, you should consider the following:
  
   * prefer write() over fmt() (and writeln() over fmtln())
   * consider using the char_buffer_sink or c_string_sink instead of writing
     to a (std::string / std::wstring) instance
   * maybe using stlsoft::integer_to_string() directly, and skipping
     FastFormat altogether


Q9: "How do I verify the performance claims made on the FastFormat website,
   and in the articles?"

A9:
  Type "make test.performance"


=============================== End of file ================================

