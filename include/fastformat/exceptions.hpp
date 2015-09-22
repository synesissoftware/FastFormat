/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/exceptions.hpp
 *
 * Purpose:     FastFormat API exception classes.
 *
 * Created:     23rd October 2008
 * Updated:     28th October 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2008-2013, Matthew Wilson and Synesis Software
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


/** \file fastformat/exceptions.hpp
 *
 * [C++ only] FastFormat API exception classes.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_HPP_EXCEPTIONS
#define FASTFORMAT_INCL_FASTFORMAT_HPP_EXCEPTIONS

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_HPP_EXCEPTIONS_MAJOR     1
# define FASTFORMAT_VER_FASTFORMAT_HPP_EXCEPTIONS_MINOR     2
# define FASTFORMAT_VER_FASTFORMAT_HPP_EXCEPTIONS_REVISION  2
# define FASTFORMAT_VER_FASTFORMAT_HPP_EXCEPTIONS_EDIT      12
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

#include <fastformat/fastformat.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#include <fastformat/internal/stlsoft.h>
#include <platformstl/platformstl.h>
//#include <platformstl/system/system_traits.hpp>

#include <exception>
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

#if 0

    /* Taxonomy: */

    [std::runtime_error]
        |
        + - fastformat_exception
                |
                + - bundle_exception
                |
                + - format_parsing_exception
                |       |
                |       + - illformed_format_exception
                |
                + - mismatched_replacements_exception
                |       |
                |       + - missing_argument_exception
                |       |
                |       + - unreferenced_argument_exception
                |
                + - sink_exception
                        |
                        + - sink_output_exception
                                |
                                .
                                .
                                .
                                . . . sink-specific exception classes
#endif



#if 0
/** Helper class for handling numeric status codes.
 *
 * \ingroup group__contingent
 *
 */
class status_code
{
public:
    typedef status_code     class_type;
    typedef int             standard_status_code_type;
#if defined(PLATFORMSTL_OS_IS_UNIX)
    typedef int             os_status_code_type;
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
    typedef DWORD           os_status_code_type;
#else /* ? OS */
# error Operating system not discriminated
#endif /* OS */
};
#endif /* 0 */

/** Root class for all FastFormat exception.
 *
 * \ingroup group__exceptions
 *
 * \note This class is abstract
 */
class fastformat_exception
    : public std::runtime_error
{
public: // Member Types
    /// The parent exception class type
    typedef std::runtime_error              parent_class_type;
    /// This type
    typedef fastformat_exception            class_type;
    /// The multibyte string type
    typedef std::string                     multibyte_string_type;
    /// The string type
    typedef std::basic_string<ff_char_t>    string_type;

public: // Construction
    /** Constructs an exception with the given message.
     *
     * \param message The message. May not be NULL
     */
    explicit fastformat_exception(char const* message)
        : parent_class_type(validate_message_(message))
    {
        FASTFORMAT_COVER_MARK_ENTRY();
    }
    virtual ~fastformat_exception() stlsoft_throw_0() = 0;

private:
    /// Not assignment-copyable
    class_type& operator =(class_type const&);

protected: // Implementation
#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
    static ff_char_t const* validate_format_(ff_char_t const* format)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(NULL != format, "format parameter may not be null");

        FASTFORMAT_COVER_MARK_ENTRY();

        return format;
    }
    static ff_char_t const* validate_format_(ff_char_t const* format, size_t cchFormat)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER((NULL != format || 0 == cchFormat), "format string pointer may not be null unless length is zero");
        STLSOFT_SUPPRESS_UNUSED(cchFormat);

        FASTFORMAT_COVER_MARK_ENTRY();

        return format;
    }
    static char const* validate_message_(char const* message)
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_APPL_LAYER(NULL != message, "message parameter may not be null");

        FASTFORMAT_COVER_MARK_ENTRY();

        return message;
    }
#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */
};

    /** Root class for all format parsing exceptions.
     *
     * \ingroup group__exceptions
     *
     * \note This class is abstract
     */
    class format_parsing_exception
        : public fastformat_exception
    {
    public: // Member Types
        /// The parent exception class type
        typedef fastformat_exception                        parent_class_type;
        /// This type
        typedef format_parsing_exception                    class_type;
        ///  The multibyte string type
        typedef parent_class_type::multibyte_string_type    message_string_type;
        ///  The string type
        typedef parent_class_type::string_type              string_type;

    public: // Construction
        /** Constructs an exception with the given message, code and format.
         *
         * \param message The message. May not be NULL
         * \param code The code associated with the condition
         * \param format The format that caused the condition
         */
        format_parsing_exception(char const* message, ff_parse_code_t code, ff_char_t const* format)
            : parent_class_type(validate_message_(message))
            , code(code)
            , format(validate_format_(format))
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        /** Constructs an exception with the given message, code and format.
         *
         * \param message The message. May not be NULL
         * \param code The code associated with the condition
         * \param format The format that caused the condition
         * \param cchFormat The number of characters in the format
         */
        format_parsing_exception(char const* message, ff_parse_code_t code, ff_char_t const* format, size_t cchFormat)
            : parent_class_type(validate_message_(message))
            , code(code)
            , format(validate_format_(format, cchFormat), cchFormat)
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        virtual ~format_parsing_exception() stlsoft_throw_0() = 0;
    private:
        /// Not assignment-copyable
        class_type& operator =(class_type const&);

    public: // Attributes
        /// The code indicating the cause of the problem
        const ff_parse_code_t   code;
        /// The defective format
        const string_type       format;
    };

        /** Exception class that represents an illformed format string.
         *
         * \ingroup group__exceptions
         */
        class illformed_format_exception
            : public format_parsing_exception
        {
        public: // Member Types
            /// The parent exception class type
            typedef format_parsing_exception        parent_class_type;
            /// This type
            typedef illformed_format_exception      class_type;
            ///  The string type
            typedef parent_class_type::string_type  string_type;

        public: // Construction
            /** Constructs an exception with the given message.
             *
             * \param message The message. May not be NULL
             * \param code The code associated with the condition
             * \param format The format that caused the condition
             */
            illformed_format_exception(char const* message, ff_parse_code_t code, ff_char_t const* format)
                : parent_class_type(message, code, format)
            {
                FASTFORMAT_COVER_MARK_ENTRY();
            }
            /** Constructs an exception with the given message.
             *
             * \param message The message. May not be NULL
             * \param code The code associated with the condition
             * \param format The format that caused the condition
             * \param cchFormat The number of characters in the format
             */
            illformed_format_exception(char const* message, ff_parse_code_t code, ff_char_t const* format, size_t cchFormat)
                : parent_class_type(message, code, format, cchFormat)
            {
                FASTFORMAT_COVER_MARK_ENTRY();
            }
        private:
            /// Not assignment-copyable
            class_type& operator =(class_type const&);
        };

    /** Root class for all parameter replacement exceptions.
     *
     * \ingroup group__exceptions
     *
     * This exception class represents a mismatch between the replacements
     * specified in a format and the arguments presented to the formatting
     * function.
     *
     * \note This class is abstract
     */
    class mismatched_replacements_exception
        : public fastformat_exception
    {
    public: // Member Types
        /// The parent exception class type
        typedef fastformat_exception                parent_class_type;
        /// This type
        typedef mismatched_replacements_exception   class_type;
        ///  The string type
        typedef parent_class_type::string_type      string_type;

    public: // Construction
        /** Constructs an exception with the given message.
         *
         * \param message The message. May not be NULL
         * \param code The code associated with the condition
         * \param numberOfReplacements The number of replacement elements
         * \param firstMismatchedReplacementIndex The index of the first mismatched replacement element
         */
        explicit mismatched_replacements_exception(char const* message, ff_replacement_code_t code, int numberOfReplacements, int firstMismatchedReplacementIndex)
            : parent_class_type(validate_message_(message))
            , code(code)
            , numberOfReplacements(numberOfReplacements)
            , firstMismatchedReplacementIndex(firstMismatchedReplacementIndex)
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        virtual ~mismatched_replacements_exception() stlsoft_throw_0() = 0;
    private:
        /// Not assignment-copyable
        class_type& operator =(class_type const&);

    public: // Attributes
        /// The code indicating the cause of the problem
        const ff_replacement_code_t     code;
        /// The number of replacement parameters in the format
        const int                       numberOfReplacements;
        /// The index of the first mismatched replacement parameter
        const int                       firstMismatchedReplacementIndex;
    };

        /** Exception class that represents the case where one or more replacement
         * parameters are specified in the format string but no matching arguments
         * are presented in the argument list.
         *
         * \ingroup group__exceptions
         */
        class missing_argument_exception
            : public mismatched_replacements_exception
        {
        public: // Member Types
            /// The parent exception class type
            typedef mismatched_replacements_exception   parent_class_type;
            /// This type
            typedef missing_argument_exception          class_type;
            ///  The string type
            typedef parent_class_type::string_type      string_type;

        public: // Construction
            /** Constructs an exception with the given message.
             *
             * \param message The message. May not be NULL
             * \param code The code associated with the condition
             * \param numberOfReplacements The number of replacement elements
             * \param firstMismatchedReplacementIndex The index of the first mismatched replacement element
             */
            missing_argument_exception(char const* message, ff_replacement_code_t code, int numberOfReplacements, int firstMismatchedReplacementIndex)
                : parent_class_type(validate_message_(message), code, numberOfReplacements, firstMismatchedReplacementIndex)
            {
                FASTFORMAT_COVER_MARK_ENTRY();
            }
        private:
            /// Not assignment-copyable
            class_type& operator =(class_type const&);
        };

        /** Exception class that represents the case where one or more arguments in
         * the argument list are unreferenced in the format.
         *
         * \ingroup group__exceptions
         *
         * \note By default, FastFormat does not designate the presence of excess
         *  arguments as a defective statement. To cause such a designation, you
         *  need to TODO: FILL THIS OUT
         */
        class unreferenced_argument_exception
            : public mismatched_replacements_exception
        {
        public: // Member Types
            /// The parent exception class type
            typedef mismatched_replacements_exception   parent_class_type;
            /// This type
            typedef unreferenced_argument_exception     class_type;
            ///  The string type
            typedef parent_class_type::string_type      string_type;

        public: // Construction
            /** Constructs an exception with the given message.
             *
             * \param message The message. May not be NULL
             * \param code The code associated with the condition
             * \param numberOfReplacements The number of replacement elements
             * \param firstMismatchedReplacementIndex The index of the first mismatched replacement element
             */
            unreferenced_argument_exception(char const* message, ff_replacement_code_t code, int numberOfReplacements, int firstMismatchedReplacementIndex)
                : parent_class_type(validate_message_(message), code, numberOfReplacements, firstMismatchedReplacementIndex)
            {
                FASTFORMAT_COVER_MARK_ENTRY();
            }
        private:
            /// Not assignment-copyable
            class_type& operator =(class_type const&);
        };

    /** Root class for all bundle exceptions.
     *
     * \ingroup group__exceptions
     *
     * This exception class represents a mismatch between the replacements
     * specified in a format and the arguments presented to the formatting
     * function.
     *
     * \note This class is abstract
     */
    class bundle_exception
        : public fastformat_exception
    {
    public: // Member Types
        /// The parent exception class type
        typedef fastformat_exception                parent_class_type;
        /// This type
        typedef bundle_exception                    class_type;
        ///  The string type
        typedef parent_class_type::string_type      string_type;

    public: // Construction
        /** Constructs an exception with the given message.
         *
         * \param message The message. May not be NULL
         */
        explicit bundle_exception(char const* message)
            : parent_class_type(validate_message_(message))
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        virtual ~bundle_exception() stlsoft_throw_0() = 0;
    private:
        /// Not assignment-copyable
        class_type& operator =(class_type const&);
    };

    /** Root class for all sink exceptions.
     *
     * \ingroup group__exceptions
     *
     * \note This class is abstract
     */
    class sink_exception
        : public fastformat_exception
    {
    public: // Member Types
        /// The parent exception class type
        typedef fastformat_exception                parent_class_type;
        /// This type
        typedef sink_exception                      class_type;
        ///  The string type
        typedef parent_class_type::string_type      string_type;

    public: // Construction
        /** Constructs an exception with the given message.
         *
         * \param message The message. May not be NULL
         */
        explicit sink_exception(char const* message)
            : parent_class_type(validate_message_(message))
        {
            FASTFORMAT_COVER_MARK_ENTRY();
        }
        virtual ~sink_exception() stlsoft_throw_0() = 0;
    private:
        /// Not assignment-copyable
        class_type& operator =(class_type const&);

    public: // Attributes
    };

        /** Exception class that represents the case where a sink has failed
         * to write its output.
         *
         * \ingroup group__exceptions
         */
        class sink_output_exception
            : public sink_exception
        {
        public: // Member Types
            /// The parent exception class type
            typedef sink_exception                      parent_class_type;
            /// This type
            typedef sink_output_exception               class_type;
            ///  The string type
            typedef parent_class_type::string_type      string_type;

        public: // Construction
            /** Constructs an exception with the given message.
             *
             * \param message The message. May not be NULL
             */
            sink_output_exception(char const* message)
                : parent_class_type(validate_message_(message))
            {
                FASTFORMAT_COVER_MARK_ENTRY();
            }
        private:
            /// Not assignment-copyable
            class_type& operator =(class_type const&);
        };

/* /////////////////////////////////////////////////////////////////////////
 * Implementation
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

inline /* virtual */ fastformat_exception::~fastformat_exception() stlsoft_throw_0() /* = 0 */
{}

inline /* virtual */ format_parsing_exception::~format_parsing_exception() stlsoft_throw_0() /* = 0 */
{}

inline /* virtual */ mismatched_replacements_exception::~mismatched_replacements_exception() stlsoft_throw_0() /* = 0 */
{}

inline /* virtual */ bundle_exception::~bundle_exception() stlsoft_throw_0() /* = 0 */
{}

inline /* virtual */ sink_exception::~sink_exception() stlsoft_throw_0() /* = 0 */
{}

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
