/* /////////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.ff_test_1.cpp
 *
 * Purpose:     Implementation file for the test.scratch.ff_test_1 project.
 *
 * Created:     15th September 2006
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2006-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/fastformat.hpp>

#if defined(_WIN32) && \
    defined(_AFXDLL)
 /* MFCSTL Header Files */
# include <mfcstl/mfcstl.hpp>
# include <mfcstl/string/grab_cstring_buffer.hpp>
# include <fastformat/sinks/CString.hpp>
#endif /* OS */

#include <platformstl/platformstl.h>
#include <fastformat/bundles/openrj_bundle.hpp>
#include <fastformat/bundles/properties_bundle.hpp>
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <fastformat/bundles/winini_bundle.hpp>
#endif /* OS */

/* Open-RJ Header Files */
#include <openrj/implicit_link.h>


/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/string/simple_string.hpp>
#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/shims/access/string/std/time.hpp>

/* PlatformSTL Header Files */
#include <platformstl/platformstl.hpp>
#include <platformstl/filesystem/path.hpp>
#include <platformstl/system/environment_map.hpp>

/* COMSTL Header Files */
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <comstl/shims/access/string.hpp>
#endif /* OS */


/* Standard C++ Header Files */
#include <exception>
#include <string>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* ////////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char * /* argv */ [])
{
    ::puts("to std:string");
    {
        namespace ff = ::fastformat;

        std::string     s;

#ifdef _DEBUG
        s = "abcdefghijklmonpqrstuvwxyz0123456789ABCDEFGHIJKLMONPQRSTUVWXYZ";
#endif /* _DEBUG */

        ff::fmt(s, "Param #1: {0; ", "abc", "def");

        ff::fmt(s, "Param #1: {0}; param #2: {1}; param #1 again: {0}", "abc", "def");

        fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
    }

#ifdef PLATFORMSTL_OS_IS_WINDOWS

# if defined(_WIN32) && \
     defined(_AFXDLL)

    ::puts("to CString");
    {
        namespace ff = ::fastformat;

        CString     s;

        ff::fmt(s, "Param #1: {0}; param #2: {1}; param #1 again: {0}", "abc", "def");

        fprintf(stdout, "Result: %.*s\n", s.GetLength(), static_cast<char const*>(s));
    }

# endif /* OS */

    ::puts("to stlsoft::simple_string");
    {
        namespace ff = ::fastformat;

        stlsoft::simple_string      s;

        GUID            guid;
        VARIANT         var;

        var.vt = VT_I4;

        ff::fmt(s, "Param #1: {{{0}}; param #2: {1}; param #1 again: {0}", guid, var);

        fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
    }
#endif /* PLATFORMSTL_OS_IS_WINDOWS */


#ifdef PLATFORMSTL_OS_IS_WINDOWS
    ::puts("to std::string; passing time argument");
    {
        namespace ff = ::fastformat;

        std::string     s;
        time_t          t   =   ::time(NULL);
        struct tm       *tm =   ::gmtime(&t);

        ff::fmt(s, "Param #1: {0}; param #2: {1}; param #1 again: {0}", tm, "def");

        fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
    }
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

    ::puts("to std::string; obtaining format strings from openrj_bundle");
    {
        namespace ff = ::fastformat;

        platformstl::environment_map    ENV;
        platformstl::path               path(ENV["FASTFORMAT_ROOT"]);

        ff::openrj_bundle               fmts(path / "bundles" / "bundle.orj");
        stlsoft::simple_string          name("Dr Proctor");
        stlsoft::simple_string          s;
#ifdef PLATFORMSTL_OS_IS_WINDOWS
        VARIANT                         age;

        age.vt      =   VT_I4;
        age.lVal    =   38;
#else /* ? OS */
        std::string                     age("38");
#endif /* OS */

        {
            ff::fmt(s, fmts["msg#1"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#2"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#3"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }
    }


    ::puts("to std::string; obtaining format strings from properties_bundle");
    {
        namespace ff = ::fastformat;

        platformstl::environment_map    ENV;
        platformstl::path               path(ENV["FASTFORMAT_ROOT"]);

        ff::properties_bundle           fmts(path / "bundles" / "bundle.properties");
        stlsoft::simple_string          name("Dr Proctor");
        stlsoft::simple_string          s;
#ifdef PLATFORMSTL_OS_IS_WINDOWS
        VARIANT                         age;

        age.vt      =   VT_I4;
        age.lVal    =   38;
#else /* ? OS */
        std::string                     age("38");
#endif /* OS */

        {
            ff::fmt(s, fmts["msg#1"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#2"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#3"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }
    }


#ifdef PLATFORMSTL_OS_IS_WINDOWS
    ::puts("to std::string; obtaining format strings from winini_bundle");
    {
        namespace ff = ::fastformat;

        platformstl::environment_map    ENV;
        platformstl::path               path(ENV["FASTFORMAT_ROOT"]);

        ff::winini_bundle               fmts(path / "bundles" / "bundle.ini", "all");
        stlsoft::simple_string          name("Dr Proctor");
        stlsoft::simple_string          s;
        VARIANT                         age;

        age.vt      =   VT_I4;
        age.lVal    =   38;

        {
            ff::fmt(s, fmts["msg#1"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#2"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#3"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }
    }
#endif /* OS */


    ::puts("to std::string; obtaining format strings from openrj_bundle");
    {
        namespace ff = ::fastformat;

        platformstl::environment_map    ENV;
        platformstl::path               path(ENV["FASTFORMAT_ROOT"]);

        ff::openrj_bundle               fmts(path / "bundles" / "bundle.orj");
        stlsoft::simple_string          name("Dr Proctor");
        stlsoft::simple_string          s;
#ifdef PLATFORMSTL_OS_IS_WINDOWS
        VARIANT                         age;

        age.vt      =   VT_I4;
        age.lVal    =   38;
#else /* ? OS */
        std::string                     age("38");
#endif /* OS */

        {
            ff::fmt(s, fmts["msg#1"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#2"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#3"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }
    }


    ::puts("to std::string; obtaining format strings from properties_bundle");
    {
        namespace ff = ::fastformat;

        platformstl::environment_map    ENV;
        platformstl::path               path(ENV["FASTFORMAT_ROOT"]);

        ff::properties_bundle           fmts(path / "bundles" / "bundle.properties");
        stlsoft::simple_string          name("Dr Proctor");
#ifdef PLATFORMSTL_OS_IS_WINDOWS
        VARIANT                         age;

        age.vt      =   VT_I4;
        age.lVal    =   38;
#else /* ? OS */
        std::string                     age("38");
#endif /* OS */
        stlsoft::simple_string          s;

        {
            ff::fmt(s, fmts["msg#1"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#2"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#3"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }
    }

#ifdef PLATFORMSTL_OS_IS_WINDOWS
    ::puts("to std::string; obtaining format strings from winini_bundle");
    {
        namespace ff = ::fastformat;

        platformstl::environment_map    ENV;
        platformstl::path               path(ENV["FASTFORMAT_ROOT"]);

        ff::winini_bundle               fmts(path / "bundles" / "bundle.ini", "all");
        stlsoft::simple_string          name("Dr Proctor");
        VARIANT                         age;

        age.vt      =   VT_I4;
        age.lVal    =   38;
        stlsoft::simple_string          s;

        {
            ff::fmt(s, fmts["msg#1"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#2"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }

        {
            ff::fmt(s, fmts["msg#3"], name, age);

            fprintf(stdout, "Result: %.*s\n", int(s.size()), s.c_str());
        }
    }
#endif /* OS */


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

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.ff_test_1: " STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        if(fastformat::init() < 0)
        {
            fprintf(stderr, "Failed to initialise FastFormat\n");
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
