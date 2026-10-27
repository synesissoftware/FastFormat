/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.cpp
 *
 * Purpose: Lists composite version macros for FastFormat and its
 *          dependencies.
 *
 * Created: 17th September 2026
 * Updated: 27th October 2026
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

#ifdef HAS_xTests
# include <xtests/xtests.h>
#endif

#include <iomanip>
#include <iostream>

#include <stdlib.h>


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
)
{
    stm
        << prefix
        << libname
        << ": v"
        << ((libver >> 24) & 0xff)
        << '.'
        << ((libver >> 16) & 0xff)
        << '.'
        << ((libver >> 8) & 0xff)
        << '.'
        << ((libver >> 0) & 0xff)
        << " ("
        << macroname
        << " = 0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
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

