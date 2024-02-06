
#include <fastformat/implicit_link.h>

#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* operating system */

#include <xtests/implicit_link.h>


/* ///////////////////////////// end of file //////////////////////////// */

