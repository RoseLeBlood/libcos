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
#include <time.h>
#include <types.h>
#include <stdio.h>
#include "typeconv.h"

#include "private/port.h"



struct tm *localtime(const time_t *timer)
{
	static struct tm time;
	
	time.tm_sec = bcd2bin(port_time_read(0x00));
    time.tm_min = bcd2bin(port_time_read(0x02));
    time.tm_hour = bcd2bin(port_time_read(0x04));
    time.tm_mday = bcd2bin(port_time_read(0x07));
    time.tm_mon = bcd2bin(port_time_read(0x08));
    time.tm_year = bcd2bin(port_time_read(0x09));
        
    return &time;
}
//=======================================================================
char* asctime_r(const struct tm* restrict timeptr, char* restrict buf) {
	static const char wday_name[][4] = 
	{
    	"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
  	};
  	static const char mon_name[][4] = 
  	{
    	"Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    	"Jul", "Aug", "Sep", "Oct", "Nov"
  	};
  	//static char result[20] = { 0 };
  	sprintf(buf, "%s %s %d %d:%d:%d %d",
    	wday_name[timeptr->tm_mday + 1],
    	mon_name[timeptr->tm_mon],
    	timeptr->tm_mday, timeptr->tm_hour,
    	timeptr->tm_min, timeptr->tm_sec,
    	2000 + timeptr->tm_year);
  	return buf;
}

char* asctime(const struct tm *timeptr) {
	static char buf[26];
	return asctime_r(timeptr, buf);
}


clock_t clock(void) { 
	return port_clock(); 
}
