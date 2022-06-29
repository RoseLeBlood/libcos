/*
* MIT License
*
* Copyright (c) 2022 Amber-Sophia Schröck

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef KLIBCOS_TIME_H
#define KLIBCOS_TIME_H

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