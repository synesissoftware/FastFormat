/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.cpp
 *
 * Purpose: Lists composite version macros for FastFormat and its
 *          dependencies.
 *
 * Created: 17th September 2026
 * Updated: 15th November 2026
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
# include <woad/iostreams.hpp>
#endif

#ifdef HAS_xTests
# include <xtests/xtests.h>
#endif

#include <iomanip>
#include <iostream>

#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef HAS_woad

# define VERSIONS_CLR_NAME_(stm)                            WOAD_FG_BLUE_FOR(stm)
# define VERSIONS_CLR_VERSION_(stm)                         WOAD_FG_GREEN_FOR(stm)
# define VERSIONS_CLR_MACRO_(stm)                           WOAD_FG_CYAN_FOR(stm)
# define VERSIONS_CLR_RESET_(stm)                           WOAD_RESET_FOR(stm)
#else /* ? HAS_woad */

# define VERSIONS_CLR_NAME_(stm)                            ""
# define VERSIONS_CLR_VERSION_(stm)                         ""
# define VERSIONS_CLR_MACRO_(stm)                           ""
# define VERSIONS_CLR_RESET_(stm)                           ""
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
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
,   char const* version_string = nullptr
)
{
    stm
        << prefix
        << VERSIONS_CLR_NAME_(stm)
        << libname
        << VERSIONS_CLR_RESET_(stm)
        << ": "
        << VERSIONS_CLR_VERSION_(stm)
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
        << VERSIONS_CLR_RESET_(stm)
        << " ("
        << VERSIONS_CLR_MACRO_(stm)
        << macroname
        << VERSIONS_CLR_RESET_(stm)
        << " = "
        << VERSIONS_CLR_VERSION_(stm)
        << "0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << VERSIONS_CLR_RESET_(stm)
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

        version(std::cout, "", "FastFormat", "FASTFORMAT_VER", libver);
    }

#ifdef HAS_shwild

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = SHWILD_VER;

        version(std::cout, "\t", "shwild", "SHWILD_VER", libver);
    }
#endif

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }

#ifdef HAS_UNIXem

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = UNIXEM_VER;

        version(std::cout, "\t", "UNIXem", "UNIXEM_VER", libver);
    }
#endif

#ifdef HAS_woad

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = WOAD_VER;

        version(std::cout, "\t", "woad", "WOAD_VER", libver, woad::version_string());
    }
#endif

#ifdef HAS_xTests

    if (0 == efferents_count++)
    {
        std::cout << "\n" << "efferent dependencies:" << std::endl;
    }

    {
        unsigned const libver = _XTESTS_VER;

        version(std::cout, "\t", "xTests", "_XTESTS_VER", libver);
    }
#endif

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */


