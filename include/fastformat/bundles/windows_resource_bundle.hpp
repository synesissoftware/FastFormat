/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/bundles/windows_resource_bundle.hpp
 *
 * Purpose:     Windows resource bundle.
 *
 * Created:     24th April 2009
 * Updated:     15th August 2016
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2009-2016, Matthew Wilson and Synesis Software
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


/** \file fastformat/bundles/windows_resource_bundle.hpp
 *
 * [C++ only] Windows resource bundle.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE
#define FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE_MAJOR    1
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE_MINOR    0
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE_REVISION 3
# define FASTFORMAT_VER_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE_EDIT     7
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
#include <fastformat/exceptions.hpp>
#include <fastformat/util/bundle/windows_replacement_translation_functions.hpp>

/* WinSTL header files */
#include <winstl/winstl.h>

/* STLSoft header files */
#include <stlsoft/conversion/integer_to_string.hpp>
#include <stlsoft/shims/access/string.hpp>
#include <stlsoft/util/minmax.hpp>
#include <winstl/error/error_desc.hpp>
#include <winstl/string/resource_string.hpp>

/* C++ Standard header files */
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

/** A resource bundle that reads Windows INI files
 *
 * \ingroup group__bundles
 */
class windows_resource_bundle
{
/// \name Member Types
/// @{
public:
    /// The character type
    typedef ff_char_t                       char_type;
    /// The string type
    typedef std::basic_string<char_type>    string_type;
    /// This type
    typedef windows_resource_bundle         class_type;
    /// The exception type
    class missing_resource_id_exception
        : public bundle_exception
    {
    public: // Member Types
        /// The parent exception class type
        typedef bundle_exception                    parent_class_type;
        /// This type
        typedef missing_resource_id_exception       class_type;
        ///  The string type
        typedef parent_class_type::string_type      string_type;

    public: // Construction
        /** Constructs an exception with the given message
         *
         * \param id The identifier of the resource that could not be loaded
         */
        explicit missing_resource_id_exception(int id)
            : parent_class_type(create_message_(NULL, 0u, id, NULL).c_str())
            , id(id)
            , code(-1)
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        /** Constructs an exception with the given message, Windows error
         * code, resource id and resource type
         *
         * \param msg The message associated with the exception at the throw
         *   site
         * \param code The Windows error code associated with the condition
         *   that resulted in the throwing of the exception
         * \param id The identifier of the resource that could not be loaded
         * \param resourceType The type of the resource that could not be
         *   loaded
         */
        missing_resource_id_exception(char const* msg, DWORD code, ff_char_t const* id, ff_char_t const* resourceType)
            : parent_class_type(create_message_(msg, code, reinterpret_cast<int>(id), resourceType).c_str())
            , id(reinterpret_cast<int>(id))
            , code(code)
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        /** Constructs an exception with the given message, Windows error
         * code, resource id and resource type
         *
         * \param msg The message associated with the exception at the throw
         *   site
         * \param code The Windows error code associated with the condition
         *   that resulted in the throwing of the exception
         * \param id The identifier of the resource that could not be loaded
         * \param resourceType The type of the resource that could not be
         *   loaded
         */
        missing_resource_id_exception(char const* msg, DWORD code, int id, ff_char_t const* resourceType)
            : parent_class_type(create_message_(msg, code, id, resourceType).c_str())
            , id(id)
            , code(code)
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }

    private:
        /// Not assignment-copyable
        class_type& operator =(class_type const&);

    public: // Attributes
        /// The identifier of the resource that could not be loaded
        const int   id;
        /// The windows error code associated with the load failure
        const DWORD code;

    private:
        static multibyte_string_type create_message_(char const* msg, DWORD code, int id, ff_char_t const* resourceType)
        {
            static const char       string0[]   =   "could not load bundle resource corresponding to identifier ";
            static const char       string1[]   =   ": ";
            char                    num_[21];
            char const*             num         =   stlsoft::integer_to_string(&num_[0], STLSOFT_NUM_ELEMENTS(num_), id);
            winstl::error_desc_a    reason(code);
            multibyte_string_type   message;

            if(0 != code)
            {
                message.reserve(STLSOFT_NUM_ELEMENTS(string0) + 21 + STLSOFT_NUM_ELEMENTS(string1) + reason.size());
            }
            else
            {
                message.reserve(STLSOFT_NUM_ELEMENTS(string0) + 21);
            }

            message += string0;
            message += num;

            if(0 != code)
            {
                message += string1;
                message += reason;
            }

            return message;
        }
    };
    typedef missing_resource_id_exception   exception_type;
private:
    typedef winstl::basic_resource_string<
        string_type
    ,   stlsoft::throw_exception_policy<exception_type>
    >                                       resource_string_type_;
/// @}

/// \name Construction
/// @{
public:
    explicit windows_resource_bundle(HINSTANCE hinst);
    ~windows_resource_bundle() ss_noexcept_k;
private:
    windows_resource_bundle(class_type const&);
    class_type& operator =(class_type const&);
/// @}

/// \name Accessors
/// @{
public:
    string_type operator [](int id) const /* throw(missing_resource_id_exception) */;
/// @}

/// \name Implementation
/// @{
private:
/// @}

/// \name Members
/// @{
private:
    HINSTANCE   m_instance;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

inline /* explicit */ windows_resource_bundle::windows_resource_bundle(HINSTANCE hinst)
    : m_instance(hinst)
{}

inline windows_resource_bundle::~windows_resource_bundle() ss_noexcept_k
{
    ::FreeLibrary(m_instance);
}

inline windows_resource_bundle::string_type windows_resource_bundle::operator [](int id) const /* throw(windows_resource_bundle::missing_resource_id_exception) */
{
    resource_string_type_   str(m_instance, id);
    string_type             s2 = str;

    // Now we attempt some "smarts" by looking to see if
    //
    // 1. it contains no {D} replacement parameters, where D is a digit
    // 2. it contains one or more %D replacement parameters, where D is a digit
    //
    // If BOTH of these conditions are true, then it assumes that this is an
    // MFC / message resource file, and to do the following transformations:
    //
    // a. all { instances are to be replaced with {{
    // b. all %D parameters are to be replaced with {D}

    if( 0 == fastformat::util::calculate_number_of_fastformat_replacement_parameters(s2.data(), s2.length()) &&
        0 != fastformat::util::calculate_number_of_windows_replacement_parameters(s2.data(), s2.length()))
    {
        s2 = fastformat::util::escape_fastformat_replacement_parameters(s2);

        s2 = fastformat::util::change_windows_replacement_parameters_to_fastformat(s2);
    }

    return s2;
}

#endif /* FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_BUNDLES_HPP_WINDOWS_RESOURCE_BUNDLE */

/* ///////////////////////////// end of file //////////////////////////// */
