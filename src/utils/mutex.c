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
#include "utils/mutex.h"
#include "assert.h"
#include "utils/schedular.h"
#include "utils/event_synce.h"

typedef struct mutex_type {
    task_t* origin_task;
    uint32_t count;
    event_t event;
} mutex_t;

mutex_t xMutexCreate() {
    register mutex_t _res;

    _res.origin_task = NULL;
    _res.count = 0;
    _res.event = xEventCreate(false);

    return _res;
}
int xMutexTake(atomic_spinlock_t* lock) {
    task_t* _curTask = pSchedularGetCurrentTask();

    while(true) {
        if(lock->origin_task == NULL) {
            lock->origin_task = _curTask;
            lock->count = 1;

            break;
        } else if(lock->origin_task == _curTask) {
            lock->count++;
            break;
        }
        xEventWait(&lock->event);
    }
    return KLIBCOS_NOERROR;
}

int xMutexkGive(mutex_t* lock) {
    assert(lock != NULL);

    if(lock->origin_task == pSchedularGetCurrentTask()) {
        lock->count--;

        if(lock->count == 0) {
            lock->origin_task = NULL;

            xEventSet(&lock->event);
            xEventClear(&lock->event);

            xSchedulerYield();
        }
    } else {
        return KLIBCOS_ERRROR;
    }
    return KLIBCOS_NOERROR;
}
int xMutexTryTake(atomic_spinlock_t* lock) {
    task_t* _curTask = pSchedularGetCurrentTask();


    if(lock->origin_task == NULL) {
        lock->origin_task = _curTask;
        lock->count = 1;

        break;
    } else if(lock->origin_task == _curTask) {
        lock->count++;
        break;
    } else {
        return KLIBCOS_ERRROR;
    }
    
    return KLIBCOS_NOERROR;
}

int xMutexIsLoked(atomic_spinlock_t*  lock) {
    if(lock->origin_task != NULL && lock->count >= 0)
        return KLIBCOS_STATE_LOCK;
    else
        return KLIBCOS_STATE_UNLOCK;
}

int xMutexkDestroy(atomic_spinlock_t*  lock) {

    if(lock->origin_task == NULL) {
        xEventDestroy(lock->event);

        return KLIBCOS_NOERROR;
    }
    return KLIBCOS_ERRROR;
}