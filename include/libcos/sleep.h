#ifndef _STDC_SLEEP_H_
#define _STDC_SLEEP_H_

#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

void udelay(uint32_t usec);
void mdelay (unsigned msec);

#define delay(sec)  mdelay((sec)*1000)


#ifdef __cplusplus
}
#endif


#endif