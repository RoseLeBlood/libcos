
#include "libcos/types.h"

extern void port_delay(int usec);

void udelay(uint32_t usec)
{
	port_delay(usec);
}
void mdelay (unsigned msec)
{
        while (msec-- > 0) {
                udelay (1000);
        }
}