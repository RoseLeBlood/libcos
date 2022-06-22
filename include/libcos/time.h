#ifndef KLIBC_TIME_H
#define KLIBC_TIME_H

#define CLOCKS_PER_SEC 1000000L
#define TIME_UTC 1

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(_BSD_SOURCE) || defined(_GNU_SOURCE)
#define __tm_gmtoff tm_gmtoff
#define __tm_zone tm_zone
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

typedef long int        clock_t;
typedef long int        time_t;
typedef unsigned long   clock_t;
typedef unsigned int    useconds_t;

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