/* /////////////////////////////////////////////////////////////////////////
 * File:        src/memory_pool.cpp
 *
 * Purpose:     Implementation file for FastFormat core API: memory pool.
 *
 * Created:     1st September 2008
 * Updated:     5th November 2013
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



/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include "ximpl_core.hpp"
#ifndef UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
# define UNIXSTL_NO_ATOMIC_INTEGER_OPERATIONS_ON_WINDOWS
#endif
#include <fastformat/internal/threading.h>
#include <fastformat/init_codes.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#include <stlsoft/synch/lock_scope.hpp>
#ifdef FASTFORMAT_MT
# ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS
#  include <platformstl/synch/atomic_functions.h>
#  include <platformstl/synch/spin_mutex.hpp>
# endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
# include <platformstl/synch/thread_mutex.hpp>
# include <platformstl/synch/tss_index.hpp>
#else /* ? FASTFORMAT_MT */
# include <stlsoft/synch/null_mutex.hpp>
#endif /* FASTFORMAT_MT */

#include <new>

#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Types & Non-local variables
 */

namespace
{

    // The memory pool
    struct memory_pool_entry_t;
    struct memory_pool_entry_t
    {
        memory_pool_entry_t*    next;
        size_t                  cbEntry;
        long double             padding;
        stlsoft::byte_t         bytes[1];

        static memory_pool_entry_t* alloc(size_t cb, memory_pool_entry_t* next)
        {
            size_t cbActual = offsetof(memory_pool_entry_t, bytes) + cb;

            cbActual = (cbActual + 15) & ~(15);

#if defined(_DEBUG) && \
    defined(PLATFORMSTL_OS_IS_WINDOWS)
            memory_pool_entry_t*  entry = static_cast<memory_pool_entry_t*>(::HeapAlloc(::GetProcessHeap(), 0, cbActual));
#else /* ? VC++ _DEBUG */
            memory_pool_entry_t*  entry = static_cast<memory_pool_entry_t*>(::malloc(cbActual));
#endif /* VC++ _DEBUG */

            if(NULL != entry)
            {
                entry->next     =   next;
                entry->cbEntry  =   cb;

                ::memset(&entry->bytes[0], 0, cb);
            }

            return entry;
        }
        static void free(void* pv)
        {
#if defined(_DEBUG) && \
    defined(PLATFORMSTL_OS_IS_WINDOWS)
            ::HeapFree(::GetProcessHeap(), 0, pv);
#else /* ? VC++ _DEBUG */
            ::free(pv);
#endif /* VC++ _DEBUG */
        }
    };

    class memory_pool_t
    {
    private: /// Member Types
#ifdef FASTFORMAT_MT
        typedef platformstl::thread_mutex   mx_type_;
#else /* ? FASTFORMAT_MT */
        typedef stlsoft::null_mutex         mx_type_;
#endif /* FASTFORMAT_MT */

    public: /// Construction
        memory_pool_t();
        ~memory_pool_t() stlsoft_throw_0();
    private:
        memory_pool_t(memory_pool_t const&);
        memory_pool_t& operator =(memory_pool_t const&);

    public: /// Operations
        void* alloc(size_t cb);

    private:
#if defined(FASTFORMAT_MT) && \
    defined(PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS)
        platformstl::spin_mutex::atomic_int_type    m_mxCount;
#else /* ? FASTFORMAT_MT && PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
        mx_type_                                    m_mx;
#endif /* FASTFORMAT_MT && PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
        memory_pool_entry_t*                        m_head;
    };

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Implementation Functions
 */

int ximpl_core::fastformat_impl_memoryPool_init(void** ptoken)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != ptoken, "memory pool state pointer must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    try
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        memory_pool_t* ctxt = new memory_pool_t();

        if(NULL == ctxt)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            return -2;
        }

        *ptoken = ctxt;

        return 0;
    }
    catch(std::bad_alloc&)
    {
        return FASTFORMAT_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        return FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
    catch(...)
    {
        return FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR;
    }
}

void ximpl_core::fastformat_impl_memoryPool_uninit(void* token)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != token, "memory pool state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    memory_pool_t* const ctxt = static_cast<memory_pool_t*>(token);

    delete ctxt;
}

void* ximpl_core::fastformat_impl_memoryPool_alloc(void* token, size_t cb)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != token, "memory pool state must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    memory_pool_t* ctxt = static_cast<memory_pool_t*>(token);

    return ctxt->alloc(cb);
}


namespace
{

    memory_pool_t::memory_pool_t()
#if defined(FASTFORMAT_MT) && \
    defined(PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS)
        : m_mxCount(0)
#else /* ? FASTFORMAT_MT && PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
        : m_mx()
#endif /* FASTFORMAT_MT && PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */
        , m_head(NULL)
    {}

    memory_pool_t::~memory_pool_t() stlsoft_throw_0()
    {
        // 0. Deallocate all entries in memory pool
        { for(memory_pool_entry_t* entry = m_head; NULL != entry; )
        {
            void* pv = entry;

            entry = entry->next;

            memory_pool_entry_t::free(pv);
        }}
        m_head = NULL;
    }

    void* memory_pool_t::alloc(size_t cb)
    {
        // There are three permuations here:
        //
        // 1. not-multithreading
        // 2. multithreading on a platform that has atomic integer operations
        // 3. multithreading on a platform that does not have atomic integer operations

#if defined(FASTFORMAT_MT) && \
    defined(PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS)

        // 2.

        platformstl::spin_mutex                         mx(&m_mxCount);
        stlsoft::lock_scope<platformstl::spin_mutex>    lock(mx);

#else /* ? FASTFORMAT_MT && PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

        // 1. & 3.

        stlsoft::lock_scope<mx_type_>                   lock(m_mx);

#endif /* FASTFORMAT_MT && PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */

        memory_pool_entry_t* entry = memory_pool_entry_t::alloc(cb, m_head);

        if(NULL != entry)
        {
            m_head = entry;

            return &entry->bytes[0];
        }

        return NULL;
    }

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
