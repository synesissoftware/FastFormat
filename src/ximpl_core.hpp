/* /////////////////////////////////////////////////////////////////////////
 * File:        src/ximpl_core.hpp
 *
 * Purpose:     Declarations of internal shared core functions.
 *
 * Created:     3rd February 2012
 * Updated:     11th November 2013
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2012-2013, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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

#include <fastformat/fastformat.h>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
namespace fastformat
{
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Typedefs
 */

#ifndef FASTFORMAT_DOCUMENTATION_SKIP_SECTION

class ximpl_core
{
private: // Types
#ifdef FASTFORMAT_NO_NAMESPACE
    typedef ff_format_element_t                     format_element_t;
#endif /* FASTFORMAT_NO_NAMESPACE */

private:
    ximpl_core();
    ~ximpl_core();

public: // Memory pool - in memory_pool.cpp
    static int      fastformat_impl_memoryPool_init(void** ptoken);
    static void     fastformat_impl_memoryPool_uninit(void* token);
    static void*    fastformat_impl_memoryPool_alloc(void* ptoken, size_t cb);

public: // Format cache - in fmt_cache.cpp
    static int      fastformat_impl_formatCache_init(void **ptoken);
    static void     fastformat_impl_formatCache_uninit(void* token);
    static unsigned fastformat_impl_formatCache_lookupPattern(
                            void*                       token
                        ,   ff_char_t const*            pattern
                        ,   size_t                      cchPattern
                        ,   format_element_t const**    elements
                        );

public: // Replacements - in replacements.cpp
    static int              fastformat_impl_replacements_init(void **ptoken);
    static void             fastformat_impl_replacements_uninit(void* token);
    static ff_char_t const* fastformat_impl_replacements_getSpaces(void* token, size_t len);
    static ff_char_t const* fastformat_impl_replacements_getHashes(void* token, size_t len);

public: // Defect handlers - in fmt_spec_defect_handlers.cpp
    static int      fastformat_impl_handlers_init(void **ptoken);
    static void     fastformat_impl_handlers_uninit(void* token);

    static ff_illformedHandler_info_t fastformat_impl_handlers_getIllformedProcessHandler(void* token);
    static ff_illformedHandler_info_t fastformat_impl_handlers_setIllformedProcessHandler(void* token, ff_illformedHandler_info_t handler_info);
    static ff_illformedHandler_info_t fastformat_impl_handlers_getIllformedThreadHandler(void* token);
    static ff_illformedHandler_info_t fastformat_impl_handlers_setIllformedThreadHandler(void* token, ff_illformedHandler_info_t handler_info);
    static ff_illformedHandler_info_t fastformat_impl_handlers_getDefaultIllformedHandler(void* token);

    static ff_mismatchedHandler_info_t fastformat_impl_handlers_getMismatchedProcessHandler(void* token);
    static ff_mismatchedHandler_info_t fastformat_impl_handlers_setMismatchedProcessHandler(void* token, ff_mismatchedHandler_info_t handler_info);
    static ff_mismatchedHandler_info_t fastformat_impl_handlers_getMismatchedThreadHandler(void* token);
    static ff_mismatchedHandler_info_t fastformat_impl_handlers_setMismatchedThreadHandler(void* token, ff_mismatchedHandler_info_t handler_info);
    static ff_mismatchedHandler_info_t fastformat_impl_handlers_getDefaultMismatchedHandler(void* token);

}; /* class ximpl_core */

#endif /* !FASTFORMAT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(FASTFORMAT_NO_NAMESPACE)
} /* namespace fastformat */
#endif /* !FASTFORMAT_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
