#ifndef KLIBC_TIME_H
#define KLIBC_TIME_H

#include <types.h>

#define CLOCKS_PER_SEC 1000000L
#define TIME_UTC 1

#ifdef __cplusplus
extern "C" {
#endif



#define _STRUCT_TIMESPEC
struct timespec {
	time_t tv_sec;
	long tv_nsec;
};

#define _STRUCT_TIMEVAL
struct timeval {
        time_t tv_sec;
	suseconds_t tv_usec;
};


struct tm
{
        int tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec;
};

struct tm *localtime ( const time_t * timer);
char*      asctime(const struct tm *timeptr);

#ifdef __cplusplus
};
#endif

#endif