/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/bundles/properties_bundle.hpp
 *
 * Purpose:     .properties file bundle.
 *
 * Created:     19th September 2006
 * Updated:     19th January 2011
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2011, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file fastformat/bundles/properties_bundle.hpp
 *
 * [C++ only] .properties file bundle.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE
#define FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE_MINOR      2
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE_REVISION   1
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE_EDIT       19
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

/* FastFormat header files */
#include <fastformat/fastformat.h>
//#include <fastformat/exceptions.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#if _STLSOFT_VER >= 0x010101ff && \
    (   defined(_STLSOFT_1_10_VER) && \
        _STLSOFT_1_10_VER >= 0x010a0101)
# define FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE
#endif /* STLSoft 1.10a1+ */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

/* STLSoft header files */
#ifdef FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE
# include <platformstl/filesystem/properties_file.hpp>
#endif /* FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */

#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/string/split_functions.hpp>
#include <stlsoft/string/trim_functions.hpp>

/* C++ Standard header files */
#include <fstream>
#include <map>
#include <stdexcept>
#include <string>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** A resource bundle that reads properties files
 *
 * \ingroup group__bundles
 */
class properties_bundle
{
/// \name Member Types
/// @{
public:
    typedef std::string                     string_type;
    typedef properties_bundle               class_type;
private:
#ifdef FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE
    typedef platformstl::properties_file    map_type_;
    typedef char const*                     map_init_type_;
#else /* ? FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */
    typedef std::map<
        string_type
    ,   string_type
    >                                       map_type_;
    typedef map_type_ const                 map_init_type_;
#endif /* FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */
/// @}

/// \name Constants
/// @{
public:
    enum
    {
            ignoreCaseOnLookup  =   0x01
        ,   treatSourceAsMemory =   0x02
    };
/// @}

/// \name Construction
/// @{
public:
    explicit properties_bundle(char const *source);

    template <typename S>
    explicit properties_bundle(S const& source)
        : m_properties(open_ns_(source))
    {}

    ~properties_bundle() throw();
/// @}

/// \name Accessors
/// @{
public:
    string_type operator [](char const* name) const throw(std::out_of_range);
    template <typename S>
    string_type operator [](S const& name) const throw(std::out_of_range)
    {
        FASTFORMAT_DECLARE_c_str_ptr_();

        return operator [](FASTFORMAT_INVOKE_c_str_ptr_(FASTFORMAT_INVOKE_c_str_ptr_(name)));
    }
/// @}

/// \name Implementation
/// @{
private:
    // We have to have this funky level of indirection due to DMC++ and GCC compilers'
    // weird behaviour wrt handling shims' fully qualified names in templates.
    template <typename S>
    static map_init_type_ open_ns_(S const& source)
    {
        FASTFORMAT_DECLARE_c_str_ptr_();

        return open_(FASTFORMAT_INVOKE_c_str_ptr_(source));
    }

    static map_init_type_ const open_(char const *name);
/// @}

/// \name Members
/// @{
private:
    map_type_ const m_properties;
/// @}

/// \name Not to be implemented
/// @{
private:
    properties_bundle(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

inline /* static */ properties_bundle::map_init_type_ const properties_bundle::open_(char const *name)
{
# ifdef FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE

    return name;

# else /* ? FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */

    std::string     line;
    std::ifstream   stm(name);
    map_type_       map;

    if(!stm)
    {
// TODO: Define (and thoroughly unit-test) a FastFormat-specific exception, and use that instead

        throw std::runtime_error("properties file not found");
    }

    for(; std::getline(stm, line); )
    {
        std::string name;
        std::string value;

        stlsoft::trim_all(line);

        if(stlsoft::split(line, '=', name, value))
        {
            stlsoft::trim_all(name);
            stlsoft::trim_left(value);

            map[name] = value;
        }
    }

    return map;

# endif /* FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */
}

inline properties_bundle::properties_bundle(char const *source)
    : m_properties(open_(source))
{}

inline properties_bundle::~properties_bundle() throw()
{}

inline properties_bundle::string_type properties_bundle::operator [](char const *name) const throw(std::out_of_range)
{
# ifdef FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE

    map_type_::view_type const value = m_properties[name];

    return string_type(value.data(), value.size());

# else /* ? FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */

    map_type_::const_iterator it = m_properties.find(name);

    if(it == m_properties.end())
    {
        throw std::out_of_range("format string not found");
    }

    return (*it).second;

# endif /* FASTFORMAT_PROPERTIES_BUNDLE_USE_STLSOFT_1_10_PROPERTIES_FILE */
}

#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_PROPERTIES_BUNDLE */

/* ///////////////////////////// end of file //////////////////////////// */
