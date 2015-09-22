/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.api.mismatched_handlers project.
 *
 * Created:     27th May 2008
 * Updated:     11th August 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2009, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* FastFormat Header Files */
#include <fastformat/implicit_link.h>

/* UNIXEm Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* operating system */

/* xTests Header Files */
#include <xtests/implicit_link.h>

/* ///////////////////////////// end of file //////////////////////////// */
