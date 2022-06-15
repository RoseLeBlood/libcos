#include <time.h>
#include <types.h>
#include <iob.h>
#include <stdio.h>

#define BCD2BIN(bcd) ((((bcd)&15) + ((bcd)>>4)*10))

struct tm *localtime(const time_t *timer)
{
	static struct tm time;
	
	time.tm_sec = BCD2BIN(port_time_read(0x00));
    time.tm_min = BCD2BIN(port_time_read(0x02));
    time.tm_hour = BCD2BIN(port_time_read(0x04));
    time.tm_mday = BCD2BIN(port_time_read(0x07));
    time.tm_mon = BCD2BIN(port_time_read(0x08));
    time.tm_year = BCD2BIN(port_time_read(0x09));
        
    return &time;
}
//=======================================================================
char* asctime(const struct tm *timeptr)
{
	static const char wday_name[][4] = 
	{
    	"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"
  	};
  	static const char mon_name[][4] = 
  	{
    	"Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    	"Jul", "Aug", "Sep", "Oct", "Nov"
  	};
  	static char result[20] = { 0 };
  	sprintf(result, "%s %s %d %d:%d:%d %d",
    	wday_name[timeptr->tm_mday + 1],
    	mon_name[timeptr->tm_mon],
    	timeptr->tm_mday, timeptr->tm_hour,
    	timeptr->tm_min, timeptr->tm_sec,
    	2000 + timeptr->tm_year);
  	return result;
}