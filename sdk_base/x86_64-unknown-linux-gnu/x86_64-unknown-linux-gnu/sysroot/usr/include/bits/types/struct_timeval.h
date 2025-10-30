#ifndef __timeval_defined
#define __timeval_defined 1

#include <bits/types.h>

#ifndef _STRUCT_TIMEVAL
#define _STRUCT_TIMEVAL
/* A time value that is accurate to the nearest
   microsecond but also has a range of years.  */
struct timeval
{
  __time_t tv_sec;		/* Seconds.  */
  __suseconds_t tv_usec;	/* Microseconds.  */
};
#endif // _STRUCT_TIMEVAL

#endif
