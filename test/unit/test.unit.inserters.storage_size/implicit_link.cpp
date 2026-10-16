/* /////////////////////////////////////////////////////////////////////////
 * File:    implicit_link.cpp
 *
 * Purpose: Implicit link file for the test.unit.inserters.storage_size project.
 *
 * Created: 23rd July 2015
 * Updated: 16th July 2024
 *
 * Status:  Wizard-generated
 *
 * License: (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2019-2024, Synesis Information Systems Pty Ltd.
 *              Copyright (c) 2015-2019, Synesis Software Pty Ltd.
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


