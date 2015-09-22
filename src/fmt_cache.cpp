/* /////////////////////////////////////////////////////////////////////////
 * File:        src/fmt_cache.cpp
 *
 * Purpose:     Implementation file for FastFormat core API: format cache.
 *
 * Created:     18th September 2006
 * Updated:     7th August 2015
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2006-2015, Matthew Wilson and Synesis Software
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
#include <fastformat/internal/format_element.h>
#include <fastformat/internal/threading.h>
#include <fastformat/init_codes.h>
#include <fastformat/quality/contract.h>
#include <fastformat/quality/cover.h>

#ifdef FASTFORMAT_MT
# include <platformstl/synch/thread_mutex.hpp>
#else /* ? FASTFORMAT_MT */
# include <stlsoft/synch/null_mutex.hpp>
#endif /* FASTFORMAT_MT */

#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>
#include <stlsoft/smartptr/shared_ptr.hpp>
#include <stlsoft/string/string_view.hpp>
#include <stlsoft/synch/lock_scope.hpp>

#if defined(_DEBUG) && \
    defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/memory/processheap_allocator.hpp>
#endif /* VC++ _DEBUG */

#if defined(STLSOFT_COMPILER_IS_MSVC)
# pragma warning(disable : 4702) // suppresses "unreachable code"
#endif /* compiler */


#include <map>
#include <new>

#include <ctype.h>

#if defined(_DEBUG) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
# include <crtdbg.h>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * Implementation selection
 */

//#define _FASTFORMAT_USE_TSS_CACHE
//#define _FASTFORMAT_USE_1PHASE_CACHE
#define _FASTFORMAT_USE_2PHASE_CACHE

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
    void* operator_new(size_t cb)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

#if defined(_DEBUG) && \
    defined(PLATFORMSTL_OS_IS_WINDOWS)
        return ::HeapAlloc(::GetProcessHeap(), 0, cb);
#else /* ? VC++ _DEBUG */
        return ::operator new(cb);
#endif /* VC++ _DEBUG */
    }

    void operator_delete(void* pv)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

#if defined(_DEBUG) && \
    defined(PLATFORMSTL_OS_IS_WINDOWS)
        ::HeapFree(::GetProcessHeap(), 0, pv);
#else /* ? VC++ _DEBUG */
        ::operator delete(pv);
#endif /* VC++ _DEBUG */
    }


    struct pattern_record_base_t
    {
        unsigned                numFormatElements;
        unsigned                numResultElements;
        size_t                  cchPattern;
        format_element_t const* elements;
        format_element_t        elements_[2];   // Two, so can test packing
    };

/* That weird linker defect with VC++ 8+ raises its ugly head again
 * here, so we have to specialise in more details. Super-boring
 */
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1400
    typedef stlsoft::basic_string_view<
        ff_char_t
    ,   std::char_traits<ff_char_t>
    ,   std::allocator<ff_char_t>
    >                                               pattern_t;
#else /* ? compiler */
# ifdef FASTFORMAT_USE_WIDE_STRINGS
    typedef stlsoft::wstring_view                   pattern_t;
# else /* ? FASTFORMAT_USE_WIDE_STRINGS */
    typedef stlsoft::string_view                    pattern_t;
# endif /* FASTFORMAT_USE_WIDE_STRINGS */
#endif /* compiler */

    struct pattern_record_t
        : public pattern_record_base_t
    {
    public: /// Member Types
        typedef pattern_record_t    class_type;
        typedef ff_char_t           char_type;

    public: /// Construction
        pattern_record_t(
            pattern_t               pattern
        ,   format_element_t const* elements
        ,   unsigned                numFormatElements
        ,   unsigned                numResultElements
        );

        void* operator new(size_t, size_t numFormatElements, size_t cchPattern);
#if !defined(STLSOFT_COMPILER_IS_BORLAND) || \
    __BORLANDC__ > 0x0582
        void operator delete(void*, size_t numFormatElements, size_t cchPattern);
#endif /* compiler */
        void operator delete(void*);

    public: /// Accessors
        pattern_t pattern() const;

    private: /// Implementation
        ff_char_t* get_pattern_memory_() const;
    };

    // A comparison function class that avoids any strcmp/memcmp
    // when the lengths are different
    struct pattern_fast_less_t
    {
        bool operator ()(pattern_t const& lhs, pattern_t const& rhs) const
        {
            size_t  lhsLen  =   lhs.size();
            size_t  rhsLen  =   rhs.size();

            if(lhsLen != rhsLen)
            {
                return lhsLen < rhsLen;
            }
            else
            {
                return lhs < rhs;
            }
        }

    };

    class format_cache
    {
    private: /// Member Types
#ifdef FASTFORMAT_MT
        typedef ::platformstl::thread_mutex             mutex_type_;
#else /* ? FASTFORMAT_MT */
        typedef ::stlsoft::null_mutex                   mutex_type_;
#endif /* FASTFORMAT_MT */
        typedef stlsoft::shared_ptr<pattern_record_t>   record_ptr_type_;
        typedef std::map<   pattern_t
                        ,   record_ptr_type_
#if !defined(UNIXSTL_OS_IS_MACOSX)
# if 1
                        ,   std::less<pattern_t>
# else /* ? 0 */
                        ,   pattern_fast_less_t
# endif /* 0 */

# if !defined(STLSOFT_COMPILER_IS_MWERKS)
#  if defined(_DEBUG) && \
      defined(PLATFORMSTL_OS_IS_WINDOWS) && \
      (  !defined(STLSOFT_COMPILER_IS_MSVC) || \
         _MSC_VER < 1400)
                        ,   winstl::processheap_allocator<pattern_t>
#  else /* ? VC++ _DEBUG */
                        ,   std::allocator<pattern_t>
#  endif /* VC++ _DEBUG */
# endif /* compiler */
#endif /* UNIXSTL_OS_IS_MACOSX */
                        >                               map_type_;
        typedef stlsoft::auto_buffer<format_element_t>  format_elements_type_;

    public: /// Construction
        void* operator new(size_t cb);
        void operator delete(void* pv);

    public:
        unsigned lookup_pattern(
            pattern_t                   pattern
        ,   format_element_t const**    elements
        );
        unsigned lookup_pattern_tss(
            pattern_t                   pattern
        ,   format_element_t const**    elements
        );
        unsigned lookup_pattern_1phase(
            pattern_t                   pattern
        ,   format_element_t const**    elements
        );
        unsigned lookup_pattern_2phase(
            pattern_t                   pattern
        ,   format_element_t const**    elements
        );

    private:
        mutex_type_     m_mx;
        map_type_       m_map;
    };

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Implementation Functions
 */

// class ximpl_core

int ximpl_core::fastformat_impl_formatCache_init(void** ptoken)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != ptoken, "token pointer must not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    try
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        format_cache* cache = new format_cache();

        if(NULL == cache)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            return FASTFORMAT_INIT_RC_OUT_OF_MEMORY;
        }

        *ptoken = cache;

        return FASTFORMAT_INIT_RC_SUCCESS;
    }
    catch(std::bad_alloc&)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return FASTFORMAT_INIT_RC_OUT_OF_MEMORY;
    }
    catch(std::exception&)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return FASTFORMAT_INIT_RC_UNSPECIFIED_EXCEPTION;
    }
    catch(...)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return FASTFORMAT_INIT_RC_UNSPECIFIED_ERROR;
    }
}

void ximpl_core::fastformat_impl_formatCache_uninit(void* token)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_STATE_INTERNAL(NULL != token, "token must not be null");

    delete static_cast<format_cache*>(token);
}

unsigned ximpl_core::fastformat_impl_formatCache_lookupPattern(
    void*                       token
,   ff_char_t const*            pattern
,   size_t                      cchPattern
,   format_element_t const**    elements
)
{
    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != token, "state pointer must be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    format_cache* cache = static_cast<format_cache*>(token);

    if(0 == cchPattern)
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        return 0;
    }
    else
    {
        FASTFORMAT_COVER_MARK_ENTRY();

        pattern_t   p(pattern, cchPattern);

        return cache->lookup_pattern(p, elements);
    }
}


namespace
{

void* format_cache::operator new(size_t cb)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    return operator_new(cb);
}

void format_cache::operator delete(void* pv)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    operator_delete(pv);
}


unsigned format_cache::lookup_pattern(
    pattern_t                   pattern
,   format_element_t const**    elements
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

#if defined(_FASTFORMAT_USE_TSS_CACHE)
    return this->lookup_pattern_tss(pattern, elements);
#elif defined(_FASTFORMAT_USE_1PHASE_CACHE)
    return this->lookup_pattern_1phase(pattern, elements);
#elif defined(_FASTFORMAT_USE_2PHASE_CACHE)
    return this->lookup_pattern_2phase(pattern, elements);
#else /* ? cache */
# error Implementation not discriminated
#endif /* cache */
}

unsigned format_cache::lookup_pattern_1phase(
    pattern_t                   pattern
,   format_element_t const**    elements
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != elements, "elements parameter may not be null");

    FASTFORMAT_COVER_MARK_ENTRY();

    stlsoft::lock_scope<mutex_type_>    lock(m_mx);
    map_type_::const_iterator           it = m_map.find(pattern);

    if(it == m_map.end())
    {
        FASTFORMAT_COVER_MARK_ENTRY();

/*                                                  (1 + len) / 2

    " "                     1   =>  1           1
    "{0}"                   3   =>  1           2
    " {0}"                  4   =>  2           2
    " {0} "                 5   =>  3           3
    "{0} {0} "              8   =>  4           4
    " {0} {0} "             9   =>  5           5
    " {0} {0} {0}"          12  =>  6           6
    "{0} {0} {0} {0}"       15  =>  7           8
    "{0} {0} {0} {0} "      16  =>  8           8
    " {0} {0} {0} {0}"      16  =>  8           8
    " {0} {0} {0} {0} "     17  =>  9           9

    "{0,2}"                 5   =>  2           3
    " {0,2}"                6   =>  3           3
    "{0,2} "                6   =>  3           3
    " {0,2} "               7   =>  4           4
    " {0,2} {0,2} "         13  =>  7           7
    "{0,2}{0,2}{0,2}"       15  =>  6           8
    "{0,2} {0,2} {0,2} "    18  =>  9           9
    " {0,2} {0,2} {0,2}"    18  =>  9           9
    " {0,2} {0,2} {0,2} "   19  =>  10          10
*/

        format_elements_type_   formatElements(1 + pattern.size() / 2);
        unsigned                numFormatElements;
        unsigned                numResultElements;

        unsigned                n = fastformat_parseFormat(pattern.data(), pattern.size(), &formatElements[0], formatElements.size(), NULL, NULL);

        numFormatElements   =   n & 0xffff;
        numResultElements   =   n >> 16;

        STLSOFT_ASSERT(numFormatElements <= formatElements.size());

#if defined(_DEBUG) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
        // This code ensures that subsequent allocations made in this scope
        // to the MSVCRT heap will not be tracked.
        //
        // This is done because FF's caching can lead to false positivies in
        // leak reporting, which we don't want and you don't want. The
        // possible downside is that if FF has some genuine leaks in this
        // area, they may not be reported. Given the maturity of the project
        // we feel that this is a very low risk, and therfore worth taking.
        int prev = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
        _CrtSetDbgFlag(prev & ~_CRTDBG_ALLOC_MEM_DF);

        stlsoft::scoped_handle<int> scoperCrt(prev, _CrtSetDbgFlag);
#endif

        record_ptr_type_    ptr(new(numFormatElements, pattern.size()) pattern_record_t(pattern, &formatElements[0], numFormatElements, numResultElements));

        it = m_map.insert(std::make_pair(ptr->pattern(), ptr)).first;
    }

    FASTFORMAT_COVER_MARK_ENTRY();

    record_ptr_type_ recptr =   (*it).second;

    *elements               =   recptr->elements;

    FASTFORMAT_COVER_MARK_ENTRY();

    return (recptr->numFormatElements & 0xffff) | ((recptr->numResultElements & 0xffff) << 16);
}

unsigned format_cache::lookup_pattern_2phase(
    pattern_t                   pattern
,   format_element_t const**    elements
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    FASTFORMAT_CONTRACT_ENFORCE_PRECONDITION_PARAMS_INTERNAL(NULL != elements, "elements parameter may not be null");

#ifndef FASTFORMAT_MT

    return this->lookup_pattern_1phase(pattern, elements);

#else /* ? FASTFORMAT_MT */

    FASTFORMAT_COVER_MARK_ENTRY();

    { // Phase 1

        FASTFORMAT_COVER_MARK_ENTRY();

        stlsoft::lock_scope<mutex_type_>    lock(m_mx);
        map_type_::const_iterator           it = m_map.find(pattern);

        if(it != m_map.end())
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            record_ptr_type_ ptr = (*it).second;

            *elements           =   ptr->elements;

            return (ptr->numFormatElements & 0xffff) | ((ptr->numResultElements & 0xffff) << 16);
        }
    }

    FASTFORMAT_COVER_MARK_ENTRY();

    // If we have reached this point, we know that the pattern has not
    // yet been cached. So we parse it, and then attempt to cache it.

    format_elements_type_   formatElements(1 + pattern.size() / 2);
    unsigned                numFormatElements;
    unsigned                numResultElements;

    unsigned                n = fastformat_parseFormat(pattern.data(), pattern.size(), &formatElements[0], formatElements.size(), NULL, NULL);

    numFormatElements   =   n & 0xffff;
    numResultElements   =   n >> 16;

    FASTFORMAT_CONTRACT_ENFORCE_POSTCONDITION_RETURN_INTERNAL(numFormatElements <= formatElements.size(), "number of pattern elements calculated cannot be greater than the number specified available");

#if defined(_DEBUG) && \
    defined(STLSOFT_COMPILER_IS_MSVC)
    // This code ensures that subsequent allocations made in this scope
    // to the MSVCRT heap will not be tracked.
    //
    // This is done because FF's caching can lead to false positivies in
    // leak reporting, which we don't want and you don't want. The
    // possible downside is that if FF has some genuine leaks in this
    // area, they may not be reported. Given the maturity of the project
    // we feel that this is a very low risk, and therfore worth taking.
    int prev = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    _CrtSetDbgFlag(prev & ~_CRTDBG_ALLOC_MEM_DF);

    stlsoft::scoped_handle<int> scoperCrt(prev, _CrtSetDbgFlag);
#endif

    record_ptr_type_    ptr(new(numFormatElements, pattern.size()) pattern_record_t(pattern, &formatElements[0], numFormatElements, numResultElements));

    { // Phase 2

        FASTFORMAT_COVER_MARK_ENTRY();

        stlsoft::lock_scope<mutex_type_>    lock(m_mx);

        // We must check again, since another thread might have parsed and
        // inserted in the time between the end of phase 1 and now

        map_type_::const_iterator           it = m_map.find(pattern);

        if(it != m_map.end())
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            // It was inserted by another thread;
        }
        else
        {
            FASTFORMAT_COVER_MARK_ENTRY();

            it = m_map.insert(std::make_pair(ptr->pattern(), ptr)).first;
        }

        record_ptr_type_ recptr =   (*it).second;

        *elements               =   recptr->elements;

        FASTFORMAT_COVER_MARK_ENTRY();

        return (recptr->numFormatElements & 0xffff) | ((recptr->numResultElements & 0xffff) << 16);
    }
#endif /* FASTFORMAT_MT */
}

namespace
{

    const size_t    offsetElement0  =   STLSOFT_RAW_OFFSETOF(pattern_record_base_t, elements_[0]);
    const size_t    offsetElement1  =   STLSOFT_RAW_OFFSETOF(pattern_record_base_t, elements_[1]);
    const size_t    sizeofElement   =   offsetElement1 - offsetElement0;

} // anonymous namespace

void* pattern_record_t::operator new(size_t /* cb */, size_t numFormatElements, size_t cchPattern)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    const size_t size   =   offsetElement0
                        +   ((numFormatElements < 2) ? 2 : numFormatElements) * sizeofElement
                        +   sizeof(ff_char_t) * (cchPattern + 1);

    return operator_new(size);
}

#if !defined(STLSOFT_COMPILER_IS_BORLAND) || \
    __BORLANDC__ > 0x0582
void pattern_record_t::operator delete(void* pv, size_t /* numFormatElements */, size_t /* cchPattern */)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    operator_delete(pv);
}
#endif /* compiler */

void pattern_record_t::operator delete(void* pv)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    operator_delete(pv);
}

inline ff_char_t* pattern_record_t::get_pattern_memory_() const
{
    const size_t    elementsSize    =   offsetElement0
                                    +   ((numFormatElements < 2) ? 2 : numFormatElements) * sizeofElement;

    return reinterpret_cast<char_type*>(const_cast<void*>(stlsoft::ptr_byte_offset(this, ptrdiff_t(elementsSize))));
}


pattern_record_t::pattern_record_t(
    pattern_t                   pattern
,   format_element_t const*     elements
,   unsigned                    numFormatElements
,   unsigned                    numResultElements
)
{
    FASTFORMAT_COVER_MARK_ENTRY();

    this->numFormatElements =   numFormatElements;
    this->numResultElements =   numResultElements;
    this->cchPattern        =   pattern.size();

    char_type* embeddedPattern = get_pattern_memory_();

    ::memcpy(embeddedPattern, pattern.data(), sizeof(char_type) * pattern.size());
    embeddedPattern[pattern.size()] = '\0';

    this->elements = &this->elements_[0];

    {
        FASTFORMAT_COVER_MARK_ENTRY();

        format_element_t*   element =   &this->elements_[0];
        size_t              i       =   0;

        for(; i != numFormatElements; ++i, ++element, ++elements)
        {
            FASTFORMAT_COVER_MARK_ENTRY();

#if 1
            element->len        =   elements->len;
            element->ptr        =   embeddedPattern + (elements->ptr - pattern.data());
            element->index      =   elements->index;
            element->minWidth   =   elements->minWidth;
            element->maxWidth   =   elements->maxWidth;
            element->alignment  =   elements->alignment;
            element->fill       =   elements->fill;
#else /* ? 0 */
            ::memcpy(element, elements, sizeof(*element));
            element->ptr        =   embeddedPattern + (elements->ptr - pattern.data());
#endif /* 0 */

            STLSOFT_ASSERT(0 == ::memcmp(element->ptr, elements->ptr, element->len));
        }
    }
}

pattern_t pattern_record_t::pattern() const
{
    /// TODO: place a length record into the memory, between the elements and
    /// the pattern, and then this invocation will not have to do a strlen.
    return pattern_t(get_pattern_memory_(), cchPattern);
}


} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
