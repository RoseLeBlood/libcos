#ifndef STDC_SHEDULAR_H
#define STDC_SHEDULAR_H

#include "task.h"
#include "atomic_spinlock.h"
#include "event_synce.h"

#ifdef  __cplusplus
extern "C" {
#endif

#define MAX_TASKS 32

typedef struct schedular {
    task_t* taskarray[MAX_TASKS];
    task_t* current_task;
    uint32_t current_index;

    atomic_spinlock_t spin_lock;

    int (* switch_task)(unsigned int ticks, struct schedular* pSehed);
    int (* addnew_task_callback)(task_t* pNewTask);
    int (* remove_task_callback)(task_t* pTask);
    
    event_t handle_taskswith;
    event_t handle_taskterm;

    
} schedular_t;

void xSchedulerWakeTasks(task_t** tasks);
void xSchedulerBlockTask(task_t** tasks, uint32_t msec);

void xSchedulerYield();

task_t* pSchedularGetCurrentTask();



#ifdef  __cplusplus
}
#endif

#endif