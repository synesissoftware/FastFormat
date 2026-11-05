/* /////////////////////////////////////////////////////////////////////////
 * File:    implicit_link.cpp
 *
 * Purpose: Implicit link file for the test.component.illformed_handlers project.
 *
 * Created: 11th November 2013
 * Updated: 16th July 2024
 *
 * Status:  Wizard-generated
 *
 * License: (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2019-2024, Synesis Information Systems Pty Ltd.
 *              Copyright (c) 2013-2019, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* FastFormat header files */
#include <fastformat/implicit_link.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* operating system */

/* xTests header files */
#include <xtests/implicit_link.h>

/* ///////////////////////////// end of file //////////////////////////// */


