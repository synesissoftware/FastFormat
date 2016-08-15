/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/bundles/openrj_bundle.hpp
 *
 * Purpose:     Open-RJ bundle.
 *
 * Created:     19th September 2006
 * Updated:     26th September 2015
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2015, Matthew Wilson and Synesis Software
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


/** \file fastformat/bundles/openrj_bundle.hpp
 *
 * [C++ only] Open-RJ bundle.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE
#define FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE_MINOR      0
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE_REVISION   9
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE_EDIT       15
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Language
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* FastFormat header files */
#include <fastformat/fastformat.h>
//#include <fastformat/bundles/common.hpp>

/* Open-RJ header files */
#include <openrj/openrj.h>          // Open-RJ C API
#include <openrj/cpp/openrj.hpp>    // Open-RJ C++ API

/* STLSoft header files */
#include <stlsoft/shims/access/string.hpp>

/* C++ Standard header files */
#include <stdexcept>

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

/** A resource bundle that reads Open-RJ Jar files
 *
 * \ingroup group__bundles
 */
class openrj_bundle
{
/// \name Member Types
/// @{
public:
    typedef ::openrj::ORJString     string_type;
    typedef openrj_bundle           class_type;
/// @}

/// \name Constants
/// @{
public:
    enum
    {
            ignoreCaseOnLookup  =   0x01    //!< Causes case to be ignored when looking up fields
        ,   treatSourceAsMemory =   0x02    //!< Causes the constructor's <code>source</code> parameter to be interpreted as database text
    };
/// @}

/// \name Construction
/// @{
public:
    explicit openrj_bundle(char const *source, unsigned flags = 0);

    template <typename S>
    explicit openrj_bundle(S const &source, unsigned flags = 0)
        : m_database(open_ns_(source, flags))
    {}

    ~openrj_bundle() throw();
/// @}

/// \name Accessors
/// @{
public:
    string_type operator [](char const *name) const throw(std::out_of_range);
    template <typename S>
    string_type operator [](S const& name) const throw(std::out_of_range)
    {
        FASTFORMAT_DECLARE_c_str_ptr_();

        return operator [](FASTFORMAT_INVOKE_c_str_ptr_(FASTFORMAT_INVOKE_c_str_ptr_(source)));
    }
/// @}

/// \name Implementation
/// @{
private:
    // We have to have this funky level of indirection due to DMC++ and GCC compilers'
    // weird behaviour wrt handling shims' fully qualified names in templates.
    template <typename S>
    static ::openrj::ORJDatabase const* open_ns_(S const &source, unsigned flags)
    {
        FASTFORMAT_DECLARE_c_str_ptr_();

        return open_(FASTFORMAT_INVOKE_c_str_ptr_(source), flags);
    }
    static ::openrj::ORJDatabase const *open_(char const *source, unsigned flags);
/// @}

/// \name Members
/// @{
private:
    ::openrj::ORJDatabase const *m_database;
/// @}

/// \name Not to be implemented
/// @{
private:
    openrj_bundle(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

inline /* static */ ::openrj::ORJDatabase const *openrj_bundle::open_(char const *source, unsigned flags)
{
#if !defined(ORJ_NO_NAMESPACE)
    using namespace openrj;
    using namespace openrj::cpp;
#endif /* !ORJ_NO_NAMESPACE */

    unsigned    orjFlags    =   0
                            |   ORDER_FIELDS
                            |   ELIDE_BLANK_RECORDS
                            |   FORCE_ALL_FIELDS_INTO_1_RECORD
                            ;

    if(ignoreCaseOnLookup & flags)
    {
        orjFlags |= IGNORE_CASE_ON_LOOKUP;
    }

    ORJError            error;
    ORJRC               rc;
    ORJDatabase const   *database;

    if(treatSourceAsMemory & flags)
    {
        rc = ORJ_CreateDatabaseFromMemory(source, ::strlen(source), NULL, orjFlags, &database, &error);
    }
    else
    {
        rc = ORJ_ReadDatabase(source, NULL, orjFlags, &database, &error);
    }

    if(ORJ_RC_SUCCESS != rc)
    {
        throw DatabaseException(rc, error);
    }

    return database;
}

inline openrj_bundle::openrj_bundle(char const *source, unsigned flags)
    : m_database(open_ns_(source, flags))
{}

inline openrj_bundle::~openrj_bundle() throw()
{
#if !defined(ORJ_NO_NAMESPACE)
    using namespace openrj;
#endif /* !ORJ_NO_NAMESPACE */

    if(NULL != m_database)
    {
        ORJ_FreeDatabase(m_database);
    }
}

inline openrj_bundle::string_type openrj_bundle::operator [](char const *name) const throw(std::out_of_range)
{
#if !defined(ORJ_NO_NAMESPACE)
    using namespace openrj;
#endif /* !ORJ_NO_NAMESPACE */

    FASTFORMAT_CONTRACT_ENFORCE_CLASS_INVARIANT_APPL_LAYER(NULL != m_database, "underlying database cannot be null");

    ORJField const  *field  =   ORJ_Record_FindFieldByNameA(&m_database->records[0], name, NULL);

    if(NULL == field)
    {
        throw std::out_of_range("format string not found");
    }

    return field->value;
}

#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_OPENRJ_BUNDLE */

/* ///////////////////////////// end of file //////////////////////////// */
