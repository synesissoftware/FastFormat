/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.sink.WindowsMessageBox.cpp
 *
 * Purpose:     Implementation file for the test.scratch.sink.WindowsMessageBox project.
 *
 * Created:     4th January 2009
 * Updated:     5th February 2012
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2012, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat Header Files */
#include <fastformat/bundles/windows_resource_bundle.hpp>
#include <fastformat/sinks/WindowsMessageBox.hpp>
#include <fastformat/ff.hpp>
#include <fastformat/format/specification_defect_handling/ignore_unreferenced_arguments_scope.hpp>

/* STLSoft Header Files */
#include <winstl/conversion/char_conversions.hpp>
#include <winstl/error/error_desc.hpp>
#include <winstl/string/resource_string.hpp>

/* Windows Header Files */
#include <windows.h>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

#include "resource.h"

/* ////////////////////////////////////////////////////////////////////// */

void Display32bitFileSize(HINSTANCE hinst, HWND parent, LPCTSTR fileName)
;

void Display32bitFileSize_(HINSTANCE hinst, HWND parent, LPCTSTR fileName)
{
//    typedef winstl::basic_resource_string<std::string> res_str_t;
//            ,   res_str_t(hinst, IDS_FMT_MISSING_FILE)

    WIN32_FIND_DATA fd;
    HANDLE          h = ::FindFirstFile(fileName, &fd);

    if(INVALID_HANDLE_VALUE == h)
    {
        DWORD const                 err = ::GetLastError();
        ff::windows_resource_bundle bundle(hinst);

        ff::ignore_unreferenced_arguments_scope scoper;

        ff::fmt(ff::sinks::MessageBox(parent, FASTFORMAT_LITERAL_STRING("Problem"), MB_ICONWARNING)
            ,   bundle[IDS_FMT_MISSING_FILE]
            ,   fileName
            ,   err
            ,   winstl::error_desc(err));
    }
    else
    {
        // . . . do something useful with file size
        ff::windows_resource_bundle bundle(hinst);

        ff::ignore_unreferenced_arguments_scope scoper;

        ff::fmt(ff::sinks::MessageBox(parent, NULL, MB_ICONWARNING)
            ,   bundle[IDS_FMT_FOUND_FILE]
            ,   fileName
            ,   fd.nFileSizeLow);

        ::FindClose(h);
    }
}

BOOL CALLBACK ParentProc(HWND hwnd, UINT code, WPARAM wParam, LPARAM lParam)
{
    if(WM_INITDIALOG == code)
    {
        LPCTSTR         argv0   =   (char const*)lParam;
        const HINSTANCE hinst   =   ::GetModuleHandleA(argv0);

        Display32bitFileSize_(hinst, hwnd, argv0);

        ::EndDialog(hwnd, 0);
    }

    return 0;
}


void Display32bitFileSize(HINSTANCE hinst, HWND parent, LPCTSTR fileName)
{
    ::DialogBoxParam(hinst, MAKEINTRESOURCE(IDD_PARENT), parent, ParentProc, (LPARAM)fileName);
}

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    const HINSTANCE hinst = ::GetModuleHandleA(argv[0]);

    Display32bitFileSize(hinst, NULL, winstl::a2t(argv[0]));
    Display32bitFileSize(hinst, NULL, FASTFORMAT_LITERAL_STRING("abc|def"));
    Display32bitFileSize(hinst, NULL, FASTFORMAT_LITERAL_STRING("does.not.exist"));

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
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
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.sink.WindowsMessageBox: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;

        res = EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}

/* ///////////////////////////// end of file //////////////////////////// */
