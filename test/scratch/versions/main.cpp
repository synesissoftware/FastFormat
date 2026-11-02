/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.cpp
 *
 * Purpose: Lists composite version macros for FastFormat and its
 *          dependencies.
 *
 * Created: 17th September 2026
 * Updated: 3rd November 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <fastformat/fastformat.h>

#ifdef HAS_shwild
# include <shwild/shwild.h>
#endif

#include <stlsoft/stlsoft.h>

#ifdef HAS_UNIXem
# include <unixem/unixem.h>
#endif

#ifdef HAS_woad
# include <woad/woad.h>
#endif

#ifdef HAS_xTests
# include <xtests/xtests.h>
#endif

#include <iomanip>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>


#ifdef HAS_woad

# define VERSIONS_CLR_NAME_                                 WOAD_FG_BLUE_FOR(file)
# define VERSIONS_CLR_VERSION_                              WOAD_FG_GREEN_FOR(file)
# define VERSIONS_CLR_MACRO_                                WOAD_FG_CYAN_FOR(file)
# define VERSIONS_CLR_RESET_                                WOAD_RESET_FOR(file)
#else /* ? HAS_woad */

# define VERSIONS_CLR_NAME_                                 ""
# define VERSIONS_CLR_VERSION_                              ""
# define VERSIONS_CLR_MACRO_                                ""
# define VERSIONS_CLR_RESET_                                ""
#endif /* HAS_woad */


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

template<
    typename T_stream
,   typename T_integer
>
void
version(
    T_stream&   stm
,   FILE*       file
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
,   char const* version_string = nullptr
)
{
#ifndef HAS_woad

    (void)file;
#endif /* !HAS_woad */

    stm
        << prefix
        << VERSIONS_CLR_NAME_
        << libname
        << VERSIONS_CLR_RESET_
        << ": "
        << VERSIONS_CLR_VERSION_
        << 'v'
        ;

    if (nullptr != version_string)
    {
        stm << version_string;
    }
    else
    {
        stm
            << ((libver >> 24) & 0xff)
            << '.'
            << ((libver >> 16) & 0xff)
            << '.'
            << ((libver >> 8) & 0xff)
            << '.'
            << ((libver >> 0) & 0xff)
            ;
    }

    stm
        << VERSIONS_CLR_RESET_
        << " ("
        << VERSIONS_CLR_MACRO_
        << macroname
        << VERSIONS_CLR_RESET_
        << " = "
        << VERSIONS_CLR_VERSION_
        << "0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << VERSIONS_CLR_RESET_
        << ")"
        << std::endl
        ;
}

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /*argc*/, char* /*argv*/[])
{
    int efferents_count = 0;

    {
        unsigned const libver = FASTFORMAT_VER;

        version(std::cout, stdout, "", "FastFormat", "FASTFORMAT_VER", libver);
    }

#ifdef HAS_shwild

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = SHWILD_VER;

        version(std::cout, stdout, "\t", "shwild", "SHWILD_VER", libver);
    }
#endif

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, stdout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }

#ifdef HAS_UNIXem

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = UNIXEM_VER;

        version(std::cout, stdout, "\t", "UNIXem", "UNIXEM_VER", libver);
    }
#endif

#ifdef HAS_woad

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = WOAD_VER;

        version(std::cout, stdout, "\t", "woad", "WOAD_VER", libver, woad::version_string());
    }
#endif

#ifdef HAS_xTests

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = _XTESTS_VER;

        version(std::cout, stdout, "\t", "xTests", "_XTESTS_VER", libver);
    }
#endif

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

