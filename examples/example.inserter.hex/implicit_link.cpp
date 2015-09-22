/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the example.inserter.hex project.
 *
 * Created:     4th February 2010
 * Updated:     4th February 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010, Synesis Software Pty Ltd.
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
