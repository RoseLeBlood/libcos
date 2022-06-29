#ifndef STDC_EVENTSYNCE_H
#define STDC_EVENTSYNCE_H

#include "task.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct eventsync event_t;

event_t     xEventCreate(_Bool state);
void        xEventDestroy(event_t* event);

char        bEventGetState(event_t* event);

void        xEventSet(event_t* event);
void        xEventWait(event_t* event);
_Bool       bEventWaitTimeout(uint32_t nMicros);
void        xEventClear(event_t* event);

#ifdef  __cplusplus
}
#endif

#endif