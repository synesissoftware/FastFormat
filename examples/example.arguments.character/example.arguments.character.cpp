/* /////////////////////////////////////////////////////////////////////////
 * File:        examples/example.arguments.character/example.arguments.character.cpp
 *
 * Purpose:     Implementation file for the example.arguments.character project.
 *
 * Created:     2nd June 2008
 * Updated:     10th January 2017
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat Header Files */
#include <fastformat/fastformat.h>
#include <fastformat/sinks/ostream.hpp>

/* STLSoft Header Files */

/* Standard C++ Header Files */
#include <exception>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace filters
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

#if 1
    inline std::basic_string<ff_char_t> filter_type(char value, char const*, ff_char_t const volatile*)
    {
        return std::basic_string<ff_char_t>(1u, value);
    }
#else /* ? 0 */
    inline ff_string_slice_t filter_type(char const& value, char const*, ff_char_t const volatile*)
    {
        ff_string_slice_t   result;

        result.len  =   1;
        result.ptr  =   &value;

        return result;
    }
#endif /* 0 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace filters */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

#include <fastformat/fastformat.hpp>

#ifdef FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT
# error Cannot compile this file with a compiler that does not support the filter_type mechanism
#endif /* FASTFORMAT_NO_FILTER_TYPE_CONVERSION_SHIM_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

static int main_(int /* argc */, char** /*argv*/)
{
#ifdef FASTFORMAT_USE_WIDE_STRINGS
# define    stm     std::wcout
#else /* ? FASTFORMAT_USE_WIDE_STRINGS */
# define    stm     std::cout
#endif /* FASTFORMAT_USE_WIDE_STRINGS */

    const char      c1  =   '~';

    fastformat::fmtln(stm, FASTFORMAT_LITERAL_STRING("c1={0}"), c1);
    fastformat::writeln(stm, FASTFORMAT_LITERAL_STRING("c1="), c1);

#if 0
    const wchar_t   c2  =   L'#';

    fastformat::fmtln(stm, FASTFORMAT_LITERAL_STRING("c2={0}"), c2);
    fastformat::writeln(stm, FASTFORMAT_LITERAL_STRING("c2="), c2);
#endif /* 0 */

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    try
    {
        return main_(argc, argv);
    }
    catch(std::exception& x)
    {
        cerr << "Unhandled error: " << x.what() << endl;
    }
    catch(...)
    {
        cerr << "Unhandled unknown error" << endl;
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
