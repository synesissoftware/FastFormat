/* /////////////////////////////////////////////////////////////////////////
 * File:        src/api.cpp
 *
 * Purpose:     Implementation file for FastFormat core API: API init.
 *
 * Created:     20th November 2007
 * Updated:     3rd February 2012
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2007-2012, Matthew Wilson and Synesis Software
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



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "ximpl_core.hpp"
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif
#include <fastformat/internal/threading.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#ifdef FASTFORMAT_MT
# ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS
#  include <platformstl/synch/atomic_functions.h>
#  include <platformstl/synch/spin_mutex.hpp>
# else /* ? PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
#  if defined(PLATFORMSTL_OS_IS_UNIX)
#   include <pthread.h>
#   include <platformstl/synch/thread_mutex.hpp>
#  else /* ? OS */
#   error FastFormat does not currently support non-UNIX operating systems that do not have support for atomic_preincrement operations. If you have information that will facilitate support for your operation, please contact the Pantheios project members.
#  endif /* OS */
# endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
#else /* ? FASTFORMAT_MT */
# include <stlsoft/synch/null_mutex.hpp>
#endif /* FASTFORMAT_MT */

#include <stlsoft/smartptr/scoped_handle.hpp>
#include <stlsoft/synch/lock_scope.hpp>

#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Function declarations
 */

namespace
{

    int fastformat_init_onetime();
    void fastformat_uninit_onetime();

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

namespace
{

#ifdef FASTFORMAT_MT
# ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS
    typedef ::platformstl::spin_mutex                       api_mutex_t;
# else /* ? PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
    typedef ::platformstl::thread_mutex                     api_mutex_t;
# endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
#else /* ? FASTFORMAT_MT */
    typedef ::stlsoft::null_mutex                           api_mutex_t;
#endif /* FASTFORMAT_MT */

    //////////////////////////////////////////////////////////////////
    // API initialisation control variables

    // The API initialisation count
    platformstl::sint32_t                       s_apiInit;

#ifdef FASTFORMAT_MT
# ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS

    // A spin mutex, that is used to guard the API init count
    //
    // See section 10.2.2 of Imperfect C++ (http://imperfectcplusplus.com/)
    //
    // When using spin-mutexes, the API initialisation itself can be
    // safely invoked by multiple concurrently contending threads.
    ::platformstl::spin_mutex::atomic_int_type  s_mx;

# else /* ? PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

    // When the architecture does not support atomic integer
    // operations, we have to use a bona-fide mutex. Naturally,
    // the question is how to ensure that the mutex itself is
    // (un)initialised.
    //
    // When not using spin-mutexes, the API initialisation itself cannot
    // be safely invoked by multiple concurrently contending threads.
    // Only a single thread can be allowed (by the user) to invoke
    // application initialisation (via fastformat_init()) for the first
    // time. Any number of subsequent initialisation attempts (calls to
    // fastformat_init()) may then be allowed.
    //

    // A pointer to the API mutex instance. Also serves as a Boolean
    // indicator as to whether the API is initialised.
    api_mutex_t*                                s_pmxApi    =   NULL;

    // Memory used for the mutexes
    union mx_union_t
    {
        double          d;
        long double     ld;
        stlsoft::byte_t bytes[sizeof(api_mutex_t)];

    }                                           s_mx1_;

# endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
#endif /* FASTFORMAT_MT */

    // The token for the memory pool API
    void*                                       s_stateMemoryPool       =   NULL;

    // The token for the format cache API
    void*                                       s_stateFormatCache      =   NULL;

    // The token for the replacements API
    void*                                       s_stateReplacements     =   NULL;

    // The token for the defect handlers API
    void*                                       s_stateDefectHandlers   =   NULL;

    // The value of the first API initialisation return
    int                                         s_init                  =   0;

    // A Boolean that indicates whether the application is
    // currently undergoing its (first) initialisation.
    int                                         s_isInitialising        =   0;

    //////////////////////////////////////////////////////////////////


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Implementation Functions
 */

namespace
{
    // 1. Memory Pool
    // 2. Format Cache
    // 3. Replacements
    // 4. Defect Handlers


    int fastformat_init_onetime()
    {
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL == s_stateMemoryPool, "memory pool state must be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL == s_stateFormatCache, "format cache state must be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL == s_stateReplacements, "replacements state must be null");
        FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL == s_stateDefectHandlers, "defect handlers state must be null");

        FASTFORMAT_COVER_MARK_ENTRY();

    // 1. Memory Pool
        int res = ximpl_core::fastformat_impl_memoryPool_init(&s_stateMemoryPool);

        if(res >= 0)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            stlsoft::scoped_handle<void*>   rollbackMemoryPool(s_stateMemoryPool, ximpl_core::fastformat_impl_memoryPool_uninit);

    // 2. Format Cache
            res = ximpl_core::fastformat_impl_formatCache_init(&s_stateFormatCache);

            if(res >= 0)
            {
                FASTFORMAT_COVER_MARK_ENTRY();

                stlsoft::scoped_handle<void*>   rollbackFormatCache(s_stateFormatCache, ximpl_core::fastformat_impl_formatCache_uninit);

    // 3. Replacements
                res = ximpl_core::fastformat_impl_replacements_init(&s_stateReplacements);

                if(res >= 0)
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

                    stlsoft::scoped_handle<void*>   rollbackReplacements(s_stateReplacements, ximpl_core::fastformat_impl_replacements_uninit);

    // 4. Defect Handlers
                    res = ximpl_core::fastformat_impl_handlers_init(&s_stateDefectHandlers);

                    if(res >= 0)
                    {
                        FASTFORMAT_COVER_MARK_ENTRY();

                        rollbackReplacements.detach();
                        rollbackFormatCache.detach();
                        rollbackMemoryPool.detach();
                    }
                }
            }
        }

        return res;
    }
    void fastformat_uninit_onetime()
    {
        FASTFORMAT_COVER_MARK_ENTRY();

    // 4. Defect Handlers
        ximpl_core::fastformat_impl_handlers_uninit(s_stateDefectHandlers);
        s_stateDefectHandlers = NULL;

    // 3. Replacements
        ximpl_core::fastformat_impl_replacements_uninit(s_stateReplacements);
        s_stateReplacements = NULL;

    // 2. Format Cache
        ximpl_core::fastformat_impl_formatCache_uninit(s_stateFormatCache);
        s_stateFormatCache = NULL;

    // 1. Memory Pool
        ximpl_core::fastformat_impl_memoryPool_uninit(s_stateMemoryPool);
        s_stateMemoryPool = NULL;
    }

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * API Functions
 */

FASTFORMAT_CALL(int) fastformat_init()
{
    FASTFORMAT_COVER_MARK_ENTRY();

    STLSOFT_SUPPRESS_UNUSED(s_isInitialising);

#ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS

    FASTFORMAT_COVER_MARK_ENTRY();

# ifdef FASTFORMAT_MT

    FASTFORMAT_COVER_MARK_ENTRY();

    // If we can make the initialisation thread-safe, without 
    // expense, then we do so.
    platformstl::spin_mutex                         mx(&s_mx);
    stlsoft::lock_scope<platformstl::spin_mutex>    lock(mx);

# endif /* FASTFORMAT_MT */

    FASTFORMAT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_API(!s_isInitialising, "can only have one thread through the initialisation sequence");

    if(1 == ++s_apiInit)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        s_init = fastformat_init_onetime();
    }

    FASTFORMAT_COVER_MARK_ENTRY();

    return s_init;

#else /* ? PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_API(!s_isInitialising, "can only have one thread through the initialisation sequence");

# ifdef FASTFORMAT_MT
    if(NULL == s_pmxApi)
# else /* ? FASTFORMAT_MT */
    if(0 == s_apiInit)
# endif /* FASTFORMAT_MT */
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        STLSOFT_ASSERT(0 == s_apiInit);

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        try
        {
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

            FASTFORMAT_COVER_MARK_ENTRY();

# ifdef FASTFORMAT_MT
            s_pmxApi = new(&s_mx1_.bytes[0]) ::platformstl::thread_mutex(false);

            if(NULL == s_pmxApi)
            {
                FASTFORMAT_COVER_MARK_ENTRY();

                return -1;
            }
            else
# endif /* FASTFORMAT_MT */
            {
                FASTFORMAT_COVER_MARK_ENTRY();

# ifdef FASTFORMAT_MT
                stlsoft::lock_scope< ::platformstl::thread_mutex>  lock(*s_pmxApi);
# endif /* FASTFORMAT_MT */

                s_init = fastformat_init_onetime();

                if(s_init < 0)
                {
                    FASTFORMAT_COVER_MARK_ENTRY();

# ifdef FASTFORMAT_MT
                    using ::platformstl::thread_mutex;

                    s_pmxApi->~thread_mutex();
                    s_pmxApi = NULL;
# endif /* FASTFORMAT_MT */

                    return s_init;
                }

                STLSOFT_ASSERT(0 == s_apiInit);

                ++s_apiInit;

                return s_init;
            }

# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        }
        catch(...)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

# ifdef FASTFORMAT_MT
            if(NULL != s_pmxApi)
            {
                FASTFORMAT_COVER_MARK_ENTRY();

                using ::platformstl::thread_mutex;

                s_pmxApi->~thread_mutex();
                s_pmxApi = NULL;
            }
# endif /* FASTFORMAT_MT */

            return -1;
        }
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    }

    STLSOFT_ASSERT(0 != s_apiInit);
# ifdef FASTFORMAT_MT
    FASTFORMAT_COVER_MARK_ENTRY();

    STLSOFT_ASSERT(NULL != s_pmxApi);

    stlsoft::lock_scope< ::platformstl::thread_mutex>  lock(*s_pmxApi);

# endif /* FASTFORMAT_MT */

    ++s_apiInit;

    FASTFORMAT_COVER_MARK_ENTRY();

    return s_init;

#endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
}

FASTFORMAT_CALL(void) fastformat_uninit()
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_GLOBAL_INVARIANT_API(0 != s_apiInit, "API is not initialised");

#ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS

# ifdef FASTFORMAT_MT

    FASTFORMAT_COVER_MARK_ENTRY();

    // If we can make the (un)initialisation thread-safe, without 
    // expense, then we do so.
    platformstl::spin_mutex                         mx(&s_mx);
    stlsoft::lock_scope<platformstl::spin_mutex>    lock(mx);
# endif /* FASTFORMAT_MT */

    if(0 == --s_apiInit)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        fastformat_uninit_onetime();
    }

#else /* ? PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

    bool    bLast = false;

# ifdef FASTFORMAT_MT
    STLSOFT_MESSAGE_ASSERT("API mutex (un)initialisation not balanced", NULL != s_pmxApi);
# endif /* FASTFORMAT_MT */

    {
        FASTFORMAT_COVER_MARK_ENTRY();

# ifdef FASTFORMAT_MT
        stlsoft::lock_scope< ::platformstl::thread_mutex>  lock(*s_pmxApi);
# endif /* FASTFORMAT_MT */

        if(0 == --s_apiInit)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            bLast = true;
        }
    }

    if(bLast)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        STLSOFT_ASSERT(0 == s_apiInit);

# ifdef FASTFORMAT_MT
        using ::platformstl::thread_mutex;

        s_pmxApi->~thread_mutex();
        s_pmxApi = NULL;

        STLSOFT_ASSERT(NULL == s_pmxApi);
# endif /* FASTFORMAT_MT */

        fastformat_uninit_onetime();
    }

#endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
}

FASTFORMAT_CALL(void) fastformat_exitProcess(int code)
{
    FASTFORMAT_COVER_MARK_ENTRY();

#if defined(WIN32)

    // By rights, Windows programs should use exit() to close down. However,
    // fastformat_exitProcess() is not a general substitute for exit(). It is
    // specifically intended to Get-Out-Of-Dodge asap, in the rare case where
    // FastFormat cannot be initialised.

    ::ExitProcess(static_cast<DWORD>(code));

#else /* ? operating system */

     ::exit(code);

#endif /* operating system */
}

FASTFORMAT_CALL(ff_string_slice_t) fastformat_getNewlineForPlatform(void)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    static const ff_char_t crlf[] =
    {
#if defined(PLATFORMSTL_OS_IS_UNIX)
# if defined(UNIXSTL_OS_IS_MACOSX)
            '\r'
# else /* ? UNIXSTL_OS_IS_MACOSX */
            '\n'
# endif /* UNIXSTL_OS_IS_MACOSX */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
            '\r'
        ,   '\n'
#else /* ? 0 */
# error Platform not discriminated
#endif /* 0 */
        ,   '\0'
    };

    ff_string_slice_t   slice;

    slice.len   =   STLSOFT_NUM_ELEMENTS(crlf) - 1;
    slice.ptr   =   crlf;

    return slice;
}

FASTFORMAT_CALL(void*) fastformat_malloc(size_t cb)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateMemoryPool, "memory pool state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_memoryPool_alloc(s_stateMemoryPool, cb);
}

FASTFORMAT_CALL(unsigned) fastformat_lookupPattern(
    ff_char_t const*            pattern
,   size_t                      cchPattern
,   ff_format_element_t const** elements
)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateFormatCache, "format cache state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_formatCache_lookupPattern(s_stateFormatCache, pattern, cchPattern, elements);
}


FASTFORMAT_CALL(ff_illformed_handler_info_t) fastformat_getProcessIllformedHandler(void)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_getIllformedProcessHandler(s_stateDefectHandlers);
}

FASTFORMAT_CALL(ff_illformed_handler_info_t) fastformat_setProcessIllformedHandler(fastformat_illformedHandler_t handler, void* param)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_setIllformedProcessHandler(s_stateDefectHandlers, handler, param);
}

FASTFORMAT_CALL(ff_illformed_handler_info_t) fastformat_getThreadIllformedHandler(void)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_getIllformedThreadHandler(s_stateDefectHandlers);
}

FASTFORMAT_CALL(ff_illformed_handler_info_t) fastformat_setThreadIllformedHandler(fastformat_illformedHandler_t handler, void* param)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_setIllformedThreadHandler(s_stateDefectHandlers, handler, param);
}


FASTFORMAT_CALL(ff_mismatched_handler_info_t) fastformat_getProcessMismatchedHandler(void)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_getMismatchedProcessHandler(s_stateDefectHandlers);
}

FASTFORMAT_CALL(ff_mismatched_handler_info_t) fastformat_setProcessMismatchedHandler(fastformat_mismatchedHandler_t handler, void* param)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_setMismatchedProcessHandler(s_stateDefectHandlers, handler, param);
}

FASTFORMAT_CALL(ff_mismatched_handler_info_t) fastformat_getThreadMismatchedHandler(void)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_getMismatchedThreadHandler(s_stateDefectHandlers);
}

FASTFORMAT_CALL(ff_mismatched_handler_info_t) fastformat_setThreadMismatchedHandler(fastformat_mismatchedHandler_t handler, void* param)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "defect handlers state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_handlers_setMismatchedThreadHandler(s_stateDefectHandlers, handler, param);
}

FASTFORMAT_CALL(ff_char_t const*) fastformat_getSpacesSlice(size_t len)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "replacements state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_replacements_getSpaces(s_stateReplacements, len);
}

FASTFORMAT_CALL(ff_char_t const*) fastformat_getHashesSlice(size_t len)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != s_stateDefectHandlers, "replacements state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    return ximpl_core::fastformat_impl_replacements_getHashes(s_stateReplacements, len);
}

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
