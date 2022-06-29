#include "utils/event_synce.h"
#include "assert.h"
#include "utils/schedular.h"

typedef struct eventsync {
    volatile char state;
    task_t* wait_head;
} event_t;


event_t xEventCreate(_Bool state) {
    register event_t _res;

    _res.state = state;
    _res.wait_head = 0;

    return _res;
}

void xEventDestroy(event_t* event) {
    assert (event->wait_head == 0);
}

char bEventGetState(event_t* event) {
    assert(event != 0);

    return event->state;
}

void xEventSet(event_t* event) {
    assert(event != 0);

    if (event->state == false)
	{
		event->state  = true;

        port_data_barriere();

        xSchedulerWakeTasks(&event->wait_head);
	}
}
void xEventWait(event_t* event) {
    if (event->state == false)
	{
        xSchedulerBlockTask(&event->wait_head, 0);
	}
}
_Bool bEventWaitTimeout(uint32_t nMicros) {
     assert(event != 0);

    if (event->state == false)
	{
        xSchedulerBlockTask(&event->wait_head, nMicros);
	}
}
void xEventClear(event_t* event) {
    assert(event != 0);

    event->state  = false;

    port_data_barriere();
}