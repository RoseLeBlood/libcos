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