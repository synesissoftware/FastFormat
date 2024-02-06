/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.sink.vectored_file.cpp
 *
 * Purpose:     Implementation file for the test.scratch.sink.vectored_file project.
 *
 * Created:     28th October 2006
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <unixem/implicit_link.h>
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

/* FastFormat header files */
#include <fastformat/sinks/vectored_file.hpp>
#include <fastformat/fastformat.hpp>

/* STLSoft header files */
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <platformstl/filesystem/file_path_buffer.hpp>
#include <platformstl/filesystem/file_lines.hpp>

/* Standard C++ header files */
#include <exception>
#include <string>

/* Standard C header files */
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#if defined(_MSC_VER)
# if defined(_DEBUG)
#  include <crtdbg.h>
# endif /* _DEBUG */
# include <io.h>
#endif /* _MSC_VER) && _DEBUG */


/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char ** /*argv*/)
{
    platformstl::file_path_buffer       path1;
    platformstl::file_path_buffer       path2;

    stlsoft::scoped_handle<char const*>     scoper1(::tmpnam(&path1[0]), ::remove);
    stlsoft::scoped_handle<char const*>     scoper2(::tmpnam(&path2[0]), ::remove);

    // Define the data:
    //
    // "FastFormat can write to vectored file APIs"
    static char fragment0[] =   " ";
    static char fragment1[] =   "FastFormat";
    static char fragment2[] =   "can";
    static char fragment3[] =   "write";
    static char fragment4[] =   "to";
    static char fragment5[] =   "vectored";
    static char fragment6[] =   "file";
    static char fragment7[] =   "APIs";

    fprintf(stdout, "writing to '%s' via raw API (writev())\n", path1.c_str());
    {
        iovec   vecs[] = 
        {
                {   &fragment1[0],  STLSOFT_NUM_ELEMENTS(fragment1) - 1 }   // "FastFormat"
            ,   {   &fragment0[0],  STLSOFT_NUM_ELEMENTS(fragment0) - 1 }   // " "
            ,   {   &fragment2[0],  STLSOFT_NUM_ELEMENTS(fragment2) - 1 }   // "can"
            ,   {   &fragment0[0],  STLSOFT_NUM_ELEMENTS(fragment0) - 1 }   // " "
            ,   {   &fragment3[0],  STLSOFT_NUM_ELEMENTS(fragment3) - 1 }   // "write"
            ,   {   &fragment0[0],  STLSOFT_NUM_ELEMENTS(fragment0) - 1 }   // " "
            ,   {   &fragment4[0],  STLSOFT_NUM_ELEMENTS(fragment4) - 1 }   // "to"
            ,   {   &fragment0[0],  STLSOFT_NUM_ELEMENTS(fragment0) - 1 }   // " "
            ,   {   &fragment5[0],  STLSOFT_NUM_ELEMENTS(fragment5) - 1 }   // "vectored"
            ,   {   &fragment0[0],  STLSOFT_NUM_ELEMENTS(fragment0) - 1 }   // " "
            ,   {   &fragment6[0],  STLSOFT_NUM_ELEMENTS(fragment6) - 1 }   // "file"
            ,   {   &fragment0[0],  STLSOFT_NUM_ELEMENTS(fragment0) - 1 }   // " "
            ,   {   &fragment7[0],  STLSOFT_NUM_ELEMENTS(fragment7) - 1 }   // "APIs"
        };

        int     fh  =   ::open(path1.c_str(), O_RDWR | O_CREAT, S_IWRITE | S_IREAD);
        ssize_t cb  =   ::writev(fh, &vecs[0], STLSOFT_NUM_ELEMENTS(vecs));

        ::close(fh);

        STLSOFT_SUPPRESS_UNUSED(cb);
    }

    fprintf(stdout, "writing to '%s' via FastFormat's vectored_file sink\n", path2.c_str());
    {
        int                             fh  =   ::open(path2.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IWRITE | S_IREAD);
        stlsoft::scoped_handle<int>     fh_(fh, ::close, -1);
        fastformat::sinks::vectored_file_sink  s(fh);

        fastformat::fmt(s, "{1}{0}{2}{0}{3}{0}{4}{0}{5}{0}{6}{0}{7}", fragment0, fragment1, fragment2, fragment3, fragment4, fragment5, fragment6, fragment7);
    }

    fprintf(stdout, "memory mapping '%s'\n", path1.c_str());
    platformstl::file_lines lines1(path1.c_str());

    fprintf(stdout, "memory mapping '%s'\n", path2.c_str());
    platformstl::file_lines lines2(path2.c_str());

    if(lines1 != lines2)
    {
        fprintf(stderr, "file contents differ!\n");
    }
    else
    {
        fprintf(stdout, "file contents identical\n");
    }

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    try
    {
        if(fastformat::init() < 0)
        {
            fprintf(stderr, "Failed to initialise FastFormat\n");

            res = EXIT_FAILURE;
        }
        else
        {
            res = main_(argc, argv);

            fastformat::uninit();
        }
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* ///////////////////////////// end of file //////////////////////////// */

