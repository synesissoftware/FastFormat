/* /////////////////////////////////////////////////////////////////////////
 * File:        example.overload.3.server_log.cpp
 *
 * Purpose:     Implementation file for the example.overload.3.server_log
 *              project.
 *
 * Created:     29th April 2009
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <fastformat/fastformat.h>

#include <inetstl/inetstl.h>
#include <inetstl/includes/std/in_addr.h>

#include <platformstl/performance/performance_counter.hpp>

#include <stlsoft/internal/safestr.h>

#include <string>

#include <stdio.h>
#include <time.h>

struct connection_t
{
    std::string     connectionId;
    struct in_addr  remoteAddress;
    struct in_addr  localAddress;
    unsigned short  port;
    unsigned long   numBytesTransferred;
    struct tm       completionTime;
};

void log_connection_streams(connection_t const& conn);
void log_connection_iostreams(connection_t const& conn);
void log_connection_ff_fmt_1(connection_t const& conn);
void log_connection_ff_fmt_2(connection_t const& conn);
void log_connection_ff_write(connection_t const& conn);
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
void log_connection_boost(connection_t const& conn);
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

int main()
{
    connection_t    conn;

    time_t          t;

    ::time(&t);

    conn.remoteAddress.s_addr =   htonl(0xC0A8A0f7);
    conn.localAddress.s_addr  =   htonl(0x7f000001);
    conn.port                 =   5651;
    conn.numBytesTransferred  =   102401;
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
    gmtime_s(&conn.completionTime, &t);
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
    conn.completionTime       =   *::gmtime(&t);
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
    conn.connectionId         =   "channel-1";

    platformstl::performance_counter                counter;
    platformstl::performance_counter::interval_type t_streams   =   0;
    platformstl::performance_counter::interval_type t_iostreams =   0;
    platformstl::performance_counter::interval_type t_ff_fmt_1  =   0;
    platformstl::performance_counter::interval_type t_ff_fmt_2  =   0;
    platformstl::performance_counter::interval_type t_ff_write  =   0;
#ifdef FASTFORMAT_PERFTEST_USE_BOOST
    platformstl::performance_counter::interval_type t_boost     =   0;
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */

    { for(int WARMUPS = 3; 0 != WARMUPS; --WARMUPS)
    {
#ifdef _DEBUG
        const int ITERATIONS = 1;
        WARMUPS = 1;
#else /* ? _DEBUG */
        const int ITERATIONS = 10000;
#endif /* _DEBUG */

        puts("Streams:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            log_connection_streams(conn);
        }}
        counter.stop();
        puts("");
        t_streams = counter.get_microseconds();

        puts("IOStreams:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            log_connection_iostreams(conn);
        }}
        counter.stop();
        puts("");
        t_iostreams = counter.get_microseconds();

        puts("FastFormat.Format (1):");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            log_connection_ff_fmt_1(conn);
        }}
        counter.stop();
        puts("");
        t_ff_fmt_1 = counter.get_microseconds();

        puts("FastFormat.Format (2):");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            log_connection_ff_fmt_2(conn);
        }}
        counter.stop();
        puts("");
        t_ff_fmt_2 = counter.get_microseconds();

        puts("FastFormat.Write:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            log_connection_ff_write(conn);
        }}
        counter.stop();
        puts("");
        t_ff_write = counter.get_microseconds();

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
        puts("Boost:");
        counter.start();
        { for(int j = 0; j != ITERATIONS; ++j)
        {
            log_connection_boost(conn);
        }}
        counter.stop();
        puts("");
        t_boost = counter.get_microseconds();
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */
    }}

    fprintf(stderr
        ,   "streams:               %luus\n"
            "iostreams:             %luus\n"
            "FastFormat.Format (1): %luus\n"
            "FastFormat.Format (2): %luus\n"
            "FastFormat.Write:      %luus\n"
        ,   static_cast<unsigned long>(t_streams)
        ,   static_cast<unsigned long>(t_iostreams)
        ,   static_cast<unsigned long>(t_ff_fmt_1)
        ,   static_cast<unsigned long>(t_ff_fmt_2)
        ,   static_cast<unsigned long>(t_ff_write)
        );

    return EXIT_SUCCESS;
}

#include <stlsoft/stlsoft.h>

#include <stdio.h>

#include <fastformat/util/string/snprintf.h>

size_t format_in_addr(char (&buff)[16], struct in_addr const* addr);
size_t format_in_addr(char (&buff)[16], struct in_addr const* addr)
{
    // NOTE: the use of fastformat_util_snprintf() here will have a minor
    // performance cost. The reason it's used is to avoid the snprintf() /
    // _snprintf() / _snprintf_s() hassles that come with supporting lots
    // of compilers.

    using fastformat::util::fastformat_util_snprintf;

    STLSOFT_ASSERT(NULL != buff);

    unsigned long l = ntohl(addr->s_addr);
    int n = fastformat_util_snprintf(
            buff, 16
        ,   "%d.%d.%d.%d"
        ,   int(l >> 24) & 0xff
        ,   int(l >> 16) & 0xff
        ,   int(l >>  8) & 0xff
        ,   int(l >>  0) & 0xff);

    if( n < 0 ||
        n > 15)
    {
        n = 0;
        buff[0] = '\0';
    }

    return size_t(n);
}

void log_connection_streams(connection_t const& conn)
{
    /* <conn-id> <completion-time> <remote-addr> <local-addr> <port> <num-bytes-transferred> */

#if 0

    char    time[101];
    size_t  n0 = strftime(&time[0], STLSOFT_NUM_ELEMENTS(time), "%b %d %H:%M:%S %Y", &conn.completionTime);

    STLSOFT_ASSERT(n0 < STLSOFT_NUM_ELEMENTS(time));

    char    addr1[16];
    char    addr2[16];
    size_t  n1 = format_in_addr(addr1, &conn.remoteAddress);
    size_t  n2 = format_in_addr(addr2, &conn.localAddress);

    fprintf(
        stdout
    ,   "%.*s %.*s %.*s %.*s %d %lu\n"
    ,   int(conn.connectionId.size()), conn.connectionId.data()
    ,   int(n0), time
    ,   int(n1), addr1
    ,   int(n2), addr2
    ,   conn.port
    ,   conn.numBytesTransferred
    );

#else /* ? 0 */

    char    time[101];
    size_t  n0 = strftime(&time[0], STLSOFT_NUM_ELEMENTS(time), "%b %d %H:%M:%S %Y", &conn.completionTime);

    STLSOFT_ASSERT(n0 < STLSOFT_NUM_ELEMENTS(time));

    unsigned long ra_l = ntohl(conn.remoteAddress.s_addr);
    unsigned long la_l = ntohl(conn.localAddress.s_addr);

    fprintf(
        stdout
    ,   "%.*s %.*s %d.%d.%d.%d %d.%d.%d.%d %d %lu\n"
    ,   int(conn.connectionId.size()), conn.connectionId.data()
    ,   int(n0), time
    ,   int((ra_l >> 24) & 0xff),
        int((ra_l >> 16) & 0xff),
        int((ra_l >>  8) & 0xff),
        int((ra_l >>  0) & 0xff)
    ,   int((la_l >> 24) & 0xff),
        int((la_l >> 16) & 0xff),
        int((la_l >>  8) & 0xff),
        int((la_l >>  0) & 0xff)
    ,   conn.port
    ,   conn.numBytesTransferred
    );

#endif /* 0 */
}

#include <iostream>


#if 1
inline std::ostream& operator <<(
  std::ostream&     stm
, struct tm const&  t
)
{
  char    time[21];
  size_t  n0 = strftime(
      &time[0], STLSOFT_NUM_ELEMENTS(time)
    , "%b %d %H:%M:%S %Y"
    , &t);
  STLSOFT_ASSERT(n0 < STLSOFT_NUM_ELEMENTS(time));

  return stm.write(time, std::streamsize(n0));
}

inline std::ostream& operator <<(
  std::ostream&         stm
, struct in_addr const& addr
)
{
  typedef unsigned uint32_t;

  uint32_t ra = ntohl(addr.s_addr);

  return stm
      << ((ra >> 24) & 0xff)
      << '.'
      << ((ra >> 16) & 0xff)
      << '.'
      << ((ra >> 8) & 0xff)
      << '.'
      << ((ra >> 0) & 0xff);
}
#endif /* 0 */


void log_connection_iostreams(connection_t const& conn)
{
    /* <conn-id> <completion-time> <remote-addr> <local-addr> <port> <num-bytes-transferred> */

#if 1

# if 1

    std::cout
        << conn.connectionId
        << ' '
        << conn.completionTime
        << ' '
        << conn.remoteAddress
        << ' '
        << conn.localAddress
        << ' '
        << conn.port
        << ' '
        << conn.numBytesTransferred
        << std::endl;

# else /* ? 0 */

    char    time[101];
    size_t  n0 = ::strftime(&time[0], STLSOFT_NUM_ELEMENTS(time), "%b %d %H:%M:%S %Y", &conn.completionTime);

    STLSOFT_SUPPRESS_UNUSED(n0);

    unsigned long ra_l = ntohl(conn.remoteAddress.s_addr);
    unsigned long la_l = ntohl(conn.localAddress.s_addr);

    std::cout
        << conn.connectionId
        << ' '
        << time
        << ' '
        << ((ra_l >> 24) & 0xff) << '.' << ((ra_l >> 16) & 0xff) << '.' << ((ra_l >> 8) & 0xff) << '.' << ((ra_l >> 0) & 0xff)
        << ' '
        << ((la_l >> 24) & 0xff) << '.' << ((la_l >> 16) & 0xff) << '.' << ((la_l >> 8) & 0xff) << '.' << ((la_l >> 0) & 0xff)
        << ' '
        << conn.port
        << ' '
        << conn.numBytesTransferred
        << std::endl;

# endif /* 0 */

#else /* ? 0 */

    char    time[101];
    size_t  n0 = ::strftime(&time[0], STLSOFT_NUM_ELEMENTS(time), "%b %d %H:%M:%S %Y", &conn.completionTime);

    STLSOFT_SUPPRESS_UNUSED(n0);

    char    addr1[16];
    char    addr2[16];
    size_t  n1 = format_in_addr(addr1, &conn.remoteAddress);
    size_t  n2 = format_in_addr(addr2, &conn.localAddress);

    STLSOFT_SUPPRESS_UNUSED(n1);
    STLSOFT_SUPPRESS_UNUSED(n2);

    std::cout
        << conn.connectionId
        << ' '
        << time
        << ' '
        << addr1
        << ' '
        << addr2
        << ' '
        << conn.port
        << ' '
        << conn.numBytesTransferred
        << std::endl;

#endif /* 0 */
}

#include <stlsoft/shims/access/string/std/time.hpp>
#include <inetstl/shims/access/string/std/in_addr.hpp>

#include <fastformat/sinks/FILE.hpp>
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

FILE* ff_stm = stdout;
//#define ff_stm    FILE_stm
#define ff_stm  std::cout

void log_connection_ff_fmt_1(connection_t const& conn)
{
    /* <conn-id> <completion-time> <remote-addr> <local-addr> <port> <num-bytes-transferred> */

    ff::fmtln(
        ff_stm
    ,   "{0} {5} {1} {2} {3} {4}"
    ,   conn.connectionId
    ,   conn.remoteAddress
    ,   conn.localAddress
    ,   conn.port
    ,   conn.numBytesTransferred
    ,   conn.completionTime
    );
}

void log_connection_ff_fmt_2(connection_t const& conn)
{
    /* <conn-id> <completion-time> <remote-addr> <local-addr> <port> <num-bytes-transferred> */

    ff::fmtln(
        ff_stm
    ,   "{1}{0}{6}{0}{2}{0}{3}{0}{4}{0}{5}"
    ,   " "
    ,   conn.connectionId
    ,   conn.remoteAddress
    ,   conn.localAddress
    ,   conn.port
    ,   conn.numBytesTransferred
    ,   conn.completionTime
    );
}

void log_connection_ff_write(connection_t const& conn)
{
    /* <conn-id> <completion-time> <remote-addr> <local-addr> <port> <num-bytes-transferred> */

    ff::writeln(
        ff_stm
    ,   conn.connectionId
    ,   " "
    ,   conn.completionTime
    ,   " "
    ,   conn.remoteAddress
    ,   " "
    ,   conn.localAddress
    ,   " "
    ,   conn.port
    ,   " "
    ,   conn.numBytesTransferred
    );
}

#ifdef FASTFORMAT_PERFTEST_USE_BOOST
//#include <boost/format.hpp>

void log_connection_boost(connection_t const& /* conn */)
{
//  puts("boost not implemented");
}
#endif /* FASTFORMAT_PERFTEST_USE_BOOST */


/* ///////////////////////////// end of file //////////////////////////// */

