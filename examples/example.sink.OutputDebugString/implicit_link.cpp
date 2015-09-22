/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the example.sinks.OutputDebugString project.
 *
 * Created:     19th April 2009
 * Updated:     11th August 2009
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009, Synesis Software Pty Ltd.
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

/* ///////////////////////////// end of file //////////////////////////// */
