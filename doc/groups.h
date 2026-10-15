/* /////////////////////////////////////////////////////////////////////////
 * File:        doc/groups.h
 *
 * Purpose:     Documentation-only Doxygen group declarations for FastFormat.
 *              Public headers historically use \ingroup without always
 *              declaring a matching \defgroup; this file supplies the
 *              missing group definitions so Doxygen (WARN_AS_ERROR) can run.
 *
 * Created:     16th October 2026
 * Updated:     16th October 2026
 *
 * Home:        http://www.fastformat.org/
 *
 * Copyright (c) 2019-2026, Matthew Wilson and Synesis Information Systems
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
 * - Neither the names of Matthew Wilson and Synesis Information Systems nor
 *   the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
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


/** \file doc/groups.h
 *
 * [Documentation only] Top-level Doxygen group declarations.
 */


/** \defgroup group__core_library Core Library
 *
 * Core FastFormat types, constants, and C API entry points.
 */

/** \defgroup group__application_layer Application Layer
 *
 * C++ application-layer API built on the core library.
 */

/** \defgroup group__init Initialisation
 *
 * Library initialisation and uninitialisation.
 */

/** \defgroup group__utility Utility
 *
 * Utility helpers used by the core and application layers.
 */

/** \defgroup group__rigging Rigging
 *
 * Internal/public rigging constructs used to wire sinks and formats.
 */

/** \defgroup group__format_specification_defect_handling Format Specification Defect Handling
 *
 * Handlers and scopes for ill-formed formats and mismatched arguments.
 */

/** \defgroup group__inserters Inserters
 *
 * Typed inserters for integers, reals, characters, and related forms.
 */

/** \defgroup group__sinks Sinks
 *
 * Output sinks (streams, buffers, platform-specific destinations).
 */

/** \defgroup group__bundles Bundles
 *
 * Resource / properties bundles for localised format strings.
 */

/** \defgroup group__exceptions Exceptions
 *
 * Exception types raised by FastFormat.
 */

/** \defgroup group__quality Quality
 *
 * Quality / contract-enforcement constructs.
 */

/** \defgroup group__contingent Contingent
 *
 * Contingent / optional support components.
 */


/* ///////////////////////////// end of file //////////////////////////// */
