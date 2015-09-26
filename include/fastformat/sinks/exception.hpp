/* /////////////////////////////////////////////////////////////////////////
 * File:        fastformat/sinks/exception.hpp
 *
 * Purpose:     A FastFormat sink for exceptions.
 *
 * Created:     12th November 2012
 * Updated:     7th June 2014
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2012-2014, Matthew Wilson and Synesis Software
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


/** \file fastformat/sinks/exception.hpp
 *
 * [C++ only] A FastFormat sink for exceptions.
 */

#ifndef FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_EXCEPTION
#define FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_EXCEPTION

/* /////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_EXCEPTION_MAJOR     0
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_EXCEPTION_MINOR     1
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_EXCEPTION_REVISION  3
# define FASTFORMAT_VER_FASTFORMAT_SINK_HPP_EXCEPTION_EDIT      3
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

#include <exception>
#include <string>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
namespace sinks
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

#if !defined(STLSOFT_COMPILER_IS_MSVC) || \
    _MSC_VER < 1500

    struct exception_sink
    {
    private:
        struct exception_creator
        {
        public:
            virtual void throw_with(char const* message) = 0;
        };

        template <typename X>
        struct exception_creator_X
            : public exception_creator
        {
            /* virtual */ void throw_with(char const* message)
            {
                throw X(message);
            }
        };

    public: // Construction
        template <typename X>
        exception_sink(X const volatile*)
            : m_creator(new (get_placement_()) exception_creator_X<X>())
        {}
    private:
        exception_sink& operator =(exception_sink const&);

    public:
        template <typename S>
        void
        throw_with_message(
            S const& s
        )
        {
            m_creator->throw_with(::stlsoft::c_str_ptr_a(s));
        }

    private:
        void*
        get_placement_()
        {
            return &u.xc[0];
        }

    private:
        typedef exception_creator_X<std::exception>     exception_creator_default;

        union
        {
            void*       size_of_vptr;
            long double spare_for_surety;
            char        xc[sizeof(exception_creator_default) + sizeof(long double)];
        } u;
        exception_creator* const    m_creator;
    };

    template <typename X>
    inline
    exception_sink
    x()
    {
        return exception_sink(static_cast<X*>(0));
    };

    inline
    exception_sink&
    fmt_slices(
        exception_sink&             sink
    ,   int                         /* flags */
    ,   size_t                      cchTotal
    ,   size_t                      numResults
    ,   ff_string_slice_t const*    results
    )

#else /* ? compiler */

    template <typename X>
    struct X_sink
    {
    public:
        void
        throw_with_message(
            char const* message
        )
        {
            throw X(message);
        }
    };

    template <typename X>
    inline
    X_sink<X>&
    x()
    {
        typedef X_sink<X>   sink_type_t;

        return *static_cast<sink_type_t*>(0);
    };

    template <typename X>
    inline
    X_sink<X>&
    fmt_slices(
        X_sink<X>&                  sink
    ,   int                         /* flags */
    ,   size_t                      cchTotal
    ,   size_t                      numResults
    ,   ff_string_slice_t const*    results
    )
#endif /* compiler */
    {
        std::basic_string<ff_char_t> msg;

        msg.reserve(cchTotal);

        { for(size_t i = 0; i != numResults; ++i)
        {
            ff_string_slice_t const& slice = results[i];

            if(0u != slice.len) // This test required by 21.3.5.2/6 => 21.3.1/6
            {
                msg.append(slice.ptr, slice.len);
            }
        }}

        if(0 != cchTotal)
        {
            sink.throw_with_message(msg.c_str());
        }

        return sink;
    }

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace sinks */
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Inclusion control
 */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# pragma once
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* FASTFORMAT_INCL_FASTFORMAT_SINK_HPP_EXCEPTION */

/* ///////////////////////////// end of file //////////////////////////// */
