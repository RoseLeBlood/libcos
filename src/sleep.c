
#include "libcos/types.h"
#include "libcos/private/port.h"

void udelay(uint32_t usec)
{
	port_iodelay(usec);
}
void mdelay (unsigned msec)
{
        while (msec-- > 0) {
                udelay (1000);
        }
}