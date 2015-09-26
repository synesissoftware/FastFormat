/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.sink.exceptions.cpp
 *
 * Purpose:     Implementation file for the test.scratch.sink.exceptions project.
 *
 * Created:     12th November 2012
 * Updated:     7th June 2014
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2012-2014, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/ff.hpp>
#include <fastformat/sinks/exception.hpp>
#include <fastformat/sinks/FILE.hpp>

#include <iostream>
#include <stdexcept>
#include <typeinfo>

#include <stlsoft/stlsoft.h>

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

class application_exception
    : public std::runtime_error
{
public: // Construction
    application_exception(char const* msg)
        : std::runtime_error(msg)
    {}
};

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static
int program_main(int , char** )
{
    ff::fmt(
        ff::sinks::x<application_exception>()
    ,   FASTFORMAT_LITERAL_STRING("{0}: ({2}) {1}")
    ,   FASTFORMAT_LITERAL_STRING("test.scratch.sink.exception")
    ,   FASTFORMAT_LITERAL_STRING("some-condition")
    ,   -1
    );

    return EXIT_FAILURE;
}

int main(int argc, char** argv)
{
    try
    {
        return program_main(argc, argv);
    }
    catch(application_exception& x)
    {
        ff::fmtln(
            ff::to_sink(stdout)
        ,   "expected exception ({0}) : {1}"
#if defined(STLSOFT_VER) && \
    STLSOFT_VER < 0x010c0000
        ,   typeid(x)
#else
        ,   typeid(x).name()
#endif
        ,   x
        );

        return EXIT_SUCCESS;
    }
    catch(std::bad_alloc&)
    {
        fputs("out of memory\n", stderr);

        return EXIT_FAILURE;
    }
    catch(std::exception& x)
    {
        ff::fmtln(
            ff::to_sink(stdout)
        ,   "unexpected exception ({0}) : {1}"
#if defined(STLSOFT_VER) && \
    STLSOFT_VER < 0x010c0000
        ,   typeid(x)
#else
        ,   typeid(x).name()
#endif
        ,   x
        );

        return EXIT_FAILURE;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
