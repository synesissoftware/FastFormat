/* /////////////////////////////////////////////////////////////////////////
 * File:        example.overload.3.record_insert.cpp
 *
 * Purpose:     Implementation file for the example.overload.3.record_insert project.
 *
 * Created:     20th September 2008
 * Updated:     6th February 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat header files */
#include <fastformat/sinks/ostream.hpp>
#include <fastformat/ff.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* PlatformSTL header files */
#include <platformstl/platformstl.hpp>

#include <platformstl/performance/performance_counter.hpp>

platformstl_ns_using(performance_counter)


/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <sstream>

/* Standard C header files */
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#if 0
typedef std::string     string_t;
#endif /* 0 */


/* /////////////////////////////////////////////////////////////////////////
 * Record insertion functions
 */

const int   intNaN = 0x7fffffff;

class BusinessRecord
{
public:
    BusinessRecord()
        : member_1(1)
        , member_2(-1)
        , member_3(20)
        , member_4(-20)
        , member_5(303)
        , member_6(-303)
        , member_7(4040)
        , member_8(-4040)
        , member_9(50505)
        , member_10(-50505)
        , member_11(606060)
        , member_12(-606060)
        , member_13(7070707)
        , member_14(-7070707)
        , member_15(80808080)
        , member_16(-80808080)
        , member_17(909090909)
        , member_18(-909090909)
        , member_19(intNaN)
    {}

public:
    int member_1;
    int member_2;
    int member_3;
    int member_4;
    int member_5;
    int member_6;
    int member_7;
    int member_8;
    int member_9;
    int member_10;
    int member_11;
    int member_12;
    int member_13;
    int member_14;
    int member_15;
    int member_16;
    int member_17;
    int member_18;
    int member_19;
};

class BusinessAdapter
{
public:
    BusinessAdapter()
        : m_tablename("order_records")
        , m_id_1(12345678)
        , m_ss()
        , m_slice()
    {}
private:
    BusinessAdapter(BusinessAdapter const&);
    BusinessAdapter& operator =(BusinessAdapter const&);

public:
    std::string makeSlice(const int val);

    std::string insertRecord( const BusinessRecord& r );
    std::string insertRecord_ff_fmt_1( const BusinessRecord& r );
    std::string insertRecord_ff_fmt_2( const BusinessRecord& r );
    std::string insertRecord_ff_write( const BusinessRecord& r );

    std::string         m_tablename;
    int                 m_id_1;
    std::stringstream   m_ss;
    std::stringstream   m_slice;

};

std::string BusinessAdapter::insertRecord( const BusinessRecord& r )
{
    // build the insert statement
    m_ss.str("");
    m_ss << "insert[" << m_tablename    << ";(";
    m_ss << makeSlice(r.member_1)       << ";";
    m_ss << makeSlice(r.member_2)       << ";";
    m_ss << makeSlice(r.member_3)       << ";";
    m_ss << makeSlice(r.member_4)       << ";";
    m_ss << makeSlice(m_id_1)           << ";";
    m_ss << makeSlice(r.member_5)       << ";";
    m_ss << makeSlice(r.member_6)       << ";";
    m_ss << makeSlice(r.member_7)       << ";";
    m_ss << makeSlice(r.member_8)       << ";";
    m_ss << makeSlice(r.member_9)       << ";";
    m_ss << makeSlice(r.member_10)      << ";";
    m_ss << makeSlice(r.member_11)      << ";";
    m_ss << makeSlice(r.member_12)      << ";";
    m_ss << makeSlice(r.member_13)      << ";";
    m_ss << makeSlice(r.member_14)      << ";";
    m_ss << makeSlice(r.member_15)      << ";";
    m_ss << makeSlice(r.member_16)      << ";";
    m_ss << makeSlice(r.member_17)      << ";";
    m_ss << makeSlice(r.member_18)      << ";";
    m_ss << makeSlice(r.member_19)      << ")]";

// do something w/ m_ss.str().c_str()

    return m_ss.str();
}

std::string BusinessAdapter::makeSlice(const int val)
{
    m_slice.str("");
    if ( val == intNaN )
        m_slice << "0N";
    else
        m_slice << val;
    return m_slice.str();
}

template <typename T>
static stlsoft::basic_shim_string<char, 20> make_shim_string(T const& t)
{
    return stlsoft::basic_shim_string<char, 20>(t.data(), t.size());
}


static stlsoft::basic_shim_string<char, 20>
 make_slice(const int val)
{
    if(intNaN == val)
    {
        return stlsoft::basic_shim_string<char, 20>("0N");
    }
    else
    {
        return make_shim_string(fastformat::filters::filter_type(val, &val, static_cast<char const*>(0)));
    }
}

std::string BusinessAdapter::insertRecord_ff_fmt_1( const BusinessRecord& r )
{
    std::string result;

    ff::fmt(
        result
    ,   "insert[{0};({1};{2};{3};{4};{5};{6};{7};{8};{9};{10};{11};{12};{13};{14};{15};{16};{17};{18};{19};{20})]"
    ,   m_tablename
    ,   make_slice(r.member_1)
    ,   make_slice(r.member_2)
    ,   make_slice(r.member_3)
    ,   make_slice(r.member_4)
    ,   make_slice(m_id_1)
    ,   make_slice(r.member_5)
    ,   make_slice(r.member_6)
    ,   make_slice(r.member_7)
    ,   make_slice(r.member_8)
    ,   make_slice(r.member_9)
    ,   make_slice(r.member_10)
    ,   make_slice(r.member_11)
    ,   make_slice(r.member_12)
    ,   make_slice(r.member_13)
    ,   make_slice(r.member_14)
    ,   make_slice(r.member_15)
    ,   make_slice(r.member_16)
    ,   make_slice(r.member_17)
    ,   make_slice(r.member_18)
    ,   make_slice(r.member_19)
    );

    return result;
}

std::string BusinessAdapter::insertRecord_ff_fmt_2( const BusinessRecord& r )
{
    std::string result;

    ff::fmt(
        result
    ,   "insert[{1}{0}({2}{0}{3}{0}{4}{0}{5}{0}{6}{0}{7}{0}{8}{0}{9}{0}{10}{0}{11}{0}{12}{0}{13}{0}{14}{0}{15}{0}{16}{0}{17}{0}{18}{0}{19}{0}{20}{0}{21})]"
    ,   ";"
    ,   m_tablename
    ,   make_slice(r.member_1)
    ,   make_slice(r.member_2)
    ,   make_slice(r.member_3)
    ,   make_slice(r.member_4)
    ,   make_slice(m_id_1)
    ,   make_slice(r.member_5)
    ,   make_slice(r.member_6)
    ,   make_slice(r.member_7)
    ,   make_slice(r.member_8)
    ,   make_slice(r.member_9)
    ,   make_slice(r.member_10)
    ,   make_slice(r.member_11)
    ,   make_slice(r.member_12)
    ,   make_slice(r.member_13)
    ,   make_slice(r.member_14)
    ,   make_slice(r.member_15)
    ,   make_slice(r.member_16)
    ,   make_slice(r.member_17)
    ,   make_slice(r.member_18)
    ,   make_slice(r.member_19)
    );

    return result;
}

std::string BusinessAdapter::insertRecord_ff_write( const BusinessRecord& r )
{
    std::string result;

    ff::write(
        result
    ,   "insert[",      m_tablename
    ,   ";(",           make_slice(r.member_1)
    ,   ";",            make_slice(r.member_2)
    ,   ";",            make_slice(r.member_3)
    ,   ";",            make_slice(r.member_4)
    ,   ";",            make_slice(m_id_1)
    ,   ";",            make_slice(r.member_5)
    ,   ";",            make_slice(r.member_6)
    ,   ";",            make_slice(r.member_7)
    ,   ";",            make_slice(r.member_8)
    ,   ";",            make_slice(r.member_9)
    ,   ";",            make_slice(r.member_10)
    ,   ";",            make_slice(r.member_11)
    ,   ";",            make_slice(r.member_12)
    ,   ";",            make_slice(r.member_13)
    ,   ";",            make_slice(r.member_14)
    ,   ";",            make_slice(r.member_15)
    ,   ";",            make_slice(r.member_16)
    ,   ";",            make_slice(r.member_17)
    ,   ";",            make_slice(r.member_18)
    ,   ";",            make_slice(r.member_19)
    ,   ")]"
    );

    return result;
}


/* ////////////////////////////////////////////////////////////////////// */

#ifdef _DEBUG
const size_t ITERATIONS =   1;
#else /* ? _DEBUG */
const size_t ITERATIONS =   100000;
#endif /* _DEBUG */

static int main_(int /* argc */, char** /*argv*/)
{
    platformstl::performance_counter                counter;
    platformstl::performance_counter::interval_type tm;
    platformstl::performance_counter::interval_type tm_ff_fmt_1;
    platformstl::performance_counter::interval_type tm_ff_fmt_2;
    platformstl::performance_counter::interval_type tm_ff_write;

    BusinessRecord  record;
    BusinessAdapter adapter;
    std::string     result;
    std::string     result_ff_fmt_1;
    std::string     result_ff_fmt_2;
    std::string     result_ff_write;

    { for(size_t i = 0; i != 2; ++i)
    {
        counter.start();
        { for(size_t i = 0; i != ITERATIONS; ++i)
        {
            result = adapter.insertRecord(record);
        }}
        counter.stop();
        tm = counter.get_milliseconds();
    }}

    { for(size_t i = 0; i != 2; ++i)
    {
        counter.start();
        { for(size_t i = 0; i != ITERATIONS; ++i)
        {
            result_ff_fmt_1 = adapter.insertRecord_ff_fmt_1(record);
        }}
        counter.stop();
        tm_ff_fmt_1 = counter.get_milliseconds();
    }}

    { for(size_t i = 0; i != 2; ++i)
    {
        counter.start();
        { for(size_t i = 0; i != ITERATIONS; ++i)
        {
            result_ff_fmt_2 = adapter.insertRecord_ff_fmt_2(record);
        }}
        counter.stop();
        tm_ff_fmt_2 = counter.get_milliseconds();
    }}

    { for(size_t i = 0; i != 2; ++i)
    {
        counter.start();
        { for(size_t i = 0; i != ITERATIONS; ++i)
        {
            result_ff_write = adapter.insertRecord_ff_write(record);
        }}
        counter.stop();
        tm_ff_write = counter.get_milliseconds();
    }}


    ff::fmtln(std::cerr, "IOStreams:\t{0}", tm);
    ff::fmtln(std::cerr, "FastFormat.Format(1):\t{0}", tm_ff_fmt_1);
    ff::fmtln(std::cerr, "FastFormat.Format(2):\t{0}", tm_ff_fmt_2);
    ff::fmtln(std::cerr, "FastFormat.Write:\t{0}", tm_ff_write);

    if(result_ff_fmt_1 != result)
    {
        ff::fmtln(std::cout, "source strings do not match\nIOStreams:\n[{0}]\nFastFormat.Format(1):\n[{1}]\n", result, result_ff_fmt_1);

        { for(size_t i = 0; ; ++i)
        {
            if(i == result.size())
            {
                ff::fmtln(std::cout, "result exhausted; len={0}", i);
                break;
            }
            else if(i == result_ff_fmt_1.size())
            {
                ff::fmtln(std::cout, "result_ff_fmt_1 exhausted; len={0}", i);
                break;
            }
            else
            {
                if(result[i] != result_ff_fmt_1[i])
                {
                    ff::fmtln(std::cout, "different characters at index {0}", i);
                    break;
                }
            }
        }}
    }

    if(result_ff_fmt_2 != result)
    {
        ff::fmtln(std::cout, "source strings do not match\nIOStreams:\n[{0}]\nFastFormat.Format(2):\n[{1}]\n", result, result_ff_fmt_2);

        { for(size_t i = 0; ; ++i)
        {
            if(i == result.size())
            {
                ff::fmtln(std::cout, "result exhausted; len={0}", i);
                break;
            }
            else if(i == result_ff_fmt_2.size())
            {
                ff::fmtln(std::cout, "result_ff_fmt_2 exhausted; len={0}", i);
                break;
            }
            else
            {
                if(result[i] != result_ff_fmt_2[i])
                {
                    ff::fmtln(std::cout, "different characters at index {0}", i);
                    break;
                }
            }
        }}
    }

    if(result_ff_write != result)
    {
        ff::fmtln(std::cout, "source strings do not match\nIOStreams:\n[{0}]\nFastFormat.Write:\n[{1}]\n", result, result_ff_write);

        { for(size_t i = 0; ; ++i)
        {
            if(i == result.size())
            {
                ff::fmtln(std::cout, "result exhausted; len={0}", i);
                break;
            }
            else if(i == result_ff_write.size())
            {
                ff::fmtln(std::cout, "result_ff_write exhausted; len={0}", i);
                break;
            }
            else
            {
                if(result[i] != result_ff_write[i])
                {
                    ff::fmtln(std::cout, "different characters at index {0}", i);
                    break;
                }
            }
        }}
    }

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

#if 0
    { for(size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
#endif /* debug */

        res = main_(argc, argv);
    }
    catch(std::exception& x)
    {
        std::cerr << "Unexpected exception: " << x.what() << std::endl;

        res = EXIT_FAILURE;
    }
    catch(...)
    {

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* ///////////////////////////// end of file //////////////////////////// */

