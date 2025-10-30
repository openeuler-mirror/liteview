#ifndef __itimerspec_defined
#define __itimerspec_defined 1

#include <bits/types.h>
#include <bits/types/struct_timespec.h>

#ifndef _STRUCT_ITIMERSPEC
#define _STRUCT_ITIMERSPEC
/* POSIX.1b structure for timer start values and intervals.  */
struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
};
#endif

#endif
