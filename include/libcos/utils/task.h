#ifndef STDC_TASK_H
#define STDC_TASK_H

#include <stdint.h>
#include "libcos/private/port.h"

#ifdef  __cplusplus
extern "C" {
#endif



/// \brief
typedef struct task task_t;

/// \brief The task entry
typedef void (* task_main)(void*);

/// \brief create a  new task
/// \param mainFunc The entry function
/// \param strTaskName Task Name
/// \param nStackSize Stack size, must be > 1024
/// \param bStart When 1 then start the Task
/// \return The new Task
task_t* pxTaskCreate(task_main mainFunc, char strTaskName[TASK_NAME_MAX_LENGHT], uint32_t nStackSize, void* pUserData, int bStart);

/// \brief get the process id from the given task
/// \param task The task
/// \brief The process id
/// \return The process id
int     ixTaskGetPid(task_t* task);

/// \brief get the state from the given task
/// \param task The task
/// \return The state of the given task.
int     ixTaskGetState(task_t* task);

/// \brief Start the given task 
/// \note Only call when in pxTaskCreate param bStart not set to 1
/// \param task The task
void    xTaskStart(task_t* task);

/// \brief Terminate a task
/// \param task The task
int     xTaskTerminate(task_t* task);


/// \brief Get the current handle
/// \return The current handle (process id)
int     ixTaskGetCurrentHandle();
/// \brief Get current task
/// \return The current task

task_t* xTaskGetCurrent();
/// \brief Is the given task the current task
/// \return if 0 then yes and 1 when not
int     bxTaskIsCurrent(task_t* task);


void* pxTaskGetRegs(task_t* task);
void* pxTaskGetCurentRegs();

#ifdef  __cplusplus
}
#endif

#endif