#ifndef __timespec_defined
#define __timespec_defined 1

#include <bits/types.h>

#ifndef _STRUCT_TIMESPEC
#define _STRUCT_TIMESPEC
/* POSIX.1b structure for a time value.  This is like a `struct timeval' but
   has nanoseconds instead of microseconds.  */
struct timespec
{
  __time_t tv_sec;		/* Seconds.  */
  __syscall_slong_t tv_nsec;	/* Nanoseconds.  */
};
#endif // _STRUCT_TIMESPEC

#endif
