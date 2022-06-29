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