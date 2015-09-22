/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/bundles/winini_bundle.hpp
 *
 * Purpose:     Windows INI file bundle.
 *
 * Created:     19th September 2006
 * Updated:     13th September 2010
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2010, Matthew Wilson and Synesis Software
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


/** \file fastformat/bundles/winini_bundle.hpp
 *
 * [C++ only] Windows INI file bundle.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE
#define FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE_MAJOR      1
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE_MINOR      1
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE_REVISION   3
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE_EDIT       15
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

/* FastFormat Header Files */
#include <fastformat/fastformat.h>

/* WinSTL Header Files */
#include <winstl/winstl.h>

/* STLSoft Header Files */
#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/util/minmax.hpp>

/* C++ Standard Header Files */
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

/** A resource bundle that reads Windows INI files.
 *
 * \ingroup group__bundles
 */
class winini_bundle
{
/// \name Member Types
/// @{
public:
    typedef ff_char_t                       char_type;
    typedef std::basic_string<char_type>    string_type;
    typedef winini_bundle                   class_type;
/// @}

/// \name Construction
/// @{
public:
    explicit winini_bundle(char_type const *source, char_type const *section);

    template <typename S0, typename S1>
    explicit winini_bundle(S0 const& source, S1 const& section)
        : m_iniFileName(::stlsoft::c_str_data(source), ::stlsoft::c_str_len(source))
        , m_iniSection(::stlsoft::c_str_data(section), ::stlsoft::c_str_len(section))
    {}

    ~winini_bundle() throw();
/// @}

/// \name Accessors
/// @{
public:
    string_type operator [](char_type const *name) const throw(std::out_of_range);
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
/// @}

/// \name Members
/// @{
private:
    const string_type   m_iniFileName;
    const string_type   m_iniSection;
/// @}

/// \name Not to be implemented
/// @{
private:
    winini_bundle(class_type const&);
    class_type& operator =(class_type const&);
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

inline winini_bundle::winini_bundle(char_type const *source, char_type const *section)
    : m_iniFileName(source)
    , m_iniSection(section)
{}

inline winini_bundle::~winini_bundle() throw()
{}

inline winini_bundle::string_type winini_bundle::operator [](char_type const *name) const throw(std::out_of_range)
{
    static const char_type sentinel[] = FASTFORMAT_LITERAL_STRING("{5DDAADE5-5134-4734-ACB8-A6D0FA3BD0EA}-{D875F19B-8279-4c44-9517-F16366BC13E3}");

    ::SetLastError(0);

    char_type   result[1001];
    DWORD       dw = ::GetPrivateProfileString(
                                            m_iniSection.c_str()
                                        ,   name
                                        ,   sentinel
                                        ,   &result[0]
                                        ,   STLSOFT_NUM_ELEMENTS(result)
                                        ,   m_iniFileName.c_str());

    if(dw == STLSOFT_NUM_ELEMENTS(sentinel) - 1)    /* element not found */
    {
        if(0 == string_type::traits_type::compare(sentinel, result, stlsoft::minimum(size_t(dw), STLSOFT_NUM_ELEMENTS(sentinel) - 1)))
        {
            throw std::out_of_range("section/key combination does not exist in the given INI file");
        }
    }

    ::GetLastError();

    return string_type(result, dw);
}

#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_WININI_BUNDLE */

/* ///////////////////////////// end of file //////////////////////////// */
