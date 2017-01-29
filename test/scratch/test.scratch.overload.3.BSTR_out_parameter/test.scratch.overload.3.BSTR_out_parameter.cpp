/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.overload.3.BSTR_out_parameter.cpp
 *
 * Purpose:     Implementation file for the test.scratch.overload.3.BSTR_out_parameter project.
 *
 * Created:     4th January 2009
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <afx.h>

/* FastFormat Header Files */
#include <fastformat/sinks/CComBSTR.hpp>
#include <fastformat/ff.hpp>
#include <fastformat/format/specification_defect_handling/ignore_missing_arguments_scope.hpp>

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

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

HRESULT get_BSTR_original(BSTR* bstr1);
HRESULT get_BSTR_ff(BSTR* bstr2);

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int argc, char** argv)
{
    BSTR    bstr1;
    BSTR    bstr2;
    HRESULT hr1;
    HRESULT hr2;

    hr1 = get_BSTR_original(&bstr1);
    hr2 = get_BSTR_ff(&bstr2);

    if(0 != ::wcscmp(bstr1, bstr2))
    {
        puts("failed");
    }
    ::SysFreeString(bstr1);
    ::SysFreeString(bstr2);

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
        puts("test.scratch.overload.3.BSTR_out_parameter: " __STLSOFT_COMPILER_LABEL_STRING);
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

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

enum dimension_t { X, Y, Z };

HRESULT GetFilter_old(dimension_t dimension, short index, BSTR* filter);
HRESULT GetFilter_new(dimension_t dimension, short index, BSTR* filter);

HRESULT get_BSTR_original(BSTR* bstr1)
{
    return GetFilter_old(dimension_t(), short(), bstr1);
}

HRESULT get_BSTR_ff(BSTR* bstr2)
{
    return GetFilter_new(dimension_t(), short(), bstr2);
}

#define atFilter    1

#define strFilterSeparator  L"-"



#include <atlbase.h>

HRESULT XXGetFilterEx_(dimension_t dimension, int newIndex, std::string* fg, std::string* fv)
{
    *fg = "fg"; // +1 
    *fv = "fv"; // +1

    return S_OK;
}

int offset_to_new_index_(int filter, dimension_t dimension, int index)
{
    return index + 1;
}

// From:

HRESULT GetFilter_old(dimension_t dimension, short index, BSTR* filter)
{
    std::string  szFG;
    std::string  szFV;
    int  newIndex  = offset_to_new_index_(atFilter, dimension, index);

    XXGetFilterEx_(dimension, newIndex, &szFG, &szFV);

    CString flt(szFG.c_str());  // +1
    flt += strFilterSeparator;  // +2
    flt += szFV.c_str();        // +1

    CComBSTR bFilter(flt);      // +1

    *filter = bFilter.Detach();

    return S_OK;
}

// To:

HRESULT GetFilter_new(dimension_t dimension, short index, BSTR* filter)
{
    std::string szFG;
    std::string szFV;
    int  newIndex  = offset_to_new_index_(atFilter,dimension, index);

    XXGetFilterEx_(dimension, newIndex, &szFG, &szFV);

    CComBSTR bFilter;

//  ff::ignore_missing_arguments_scope  scoper;
//  fastformat::fmt(bFilter, "{0}{1}{2}{3}", szFG, winstl::w2m(strFilterSeparator), szFV);

#if 0
    fastformat::write(bFilter, szFG, winstl::w2m(strFilterSeparator), szFV); // +1

    *filter = bFilter.Detach();
#else /* ? 0 */

# if 1

    *filter = fastformat::write(bFilter, szFG, winstl::w2m(strFilterSeparator), szFV).Detach(); // +1

# else /* ? 0 */

    // This should not work, but does with some compilers ...

    *filter = fastformat::write(CComBSTR(), szFG, winstl::w2m(strFilterSeparator), szFV).Detach(); // +1

# endif /* 0 */

#endif /* 0 */

    return S_OK;
}

/* ///////////////////////////// end of file //////////////////////////// */

