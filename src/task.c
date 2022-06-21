#include "libcos/private/port.h"
#include "libcos/task.h"
#include "libcos/malloc.h"
#include "libcos/string.h"


#include "assert.h"

typedef struct task {
    int handle;
    void* userdata;
    task_main mainFunc;
} task_t;

void __process_main_func(void* );

task_t* pxTaskCreate(task_main mainFunc, char strTaskName[TASK_NAME_MAX_LENGHT], uint32_t nStackSize, void* pUserData, int bStart) {
    assert (nStackSize >= 1024);

    int _newHandle =  port_create_process(__process_main_func, strTaskName, nStackSize);
    if(_newHandle < 0) { return 0; }

    task_t* _newTask = malloc(sizeof(task_t));
    assert(_newTask != NULL);

    port_set_process_state(_newHandle, TASK_STATE_NEW);

    _newTask->handle = _newHandle;
    _newTask->userdata = pUserData;
    _newTask->mainFunc = mainFunc;

    if(bStart == 1) xTaskStart(_newTask);

    return _newTask;
}
int ixTaskGetPid(task_t* task) {
    assert(task != NULL);

    return task->handle;
}
int ixTaskGetState(task_t* task) {
    assert(task != NULL);

    return port_get_process_state(task->handle);

}

void xTaskStart(task_t* task) {
    assert(task != NULL);

    if (port_get_process_state(task->handle) == TASK_STATE_NEW)  {
        if(port_start_process(task->handle, task) == 0)
            port_set_process_state(task->handle, TASK_STATE_READY);
        else
            port_set_process_state(task->handle, TASK_STATE_UNKNOWN);
    } else {
        port_set_process_state(task->handle, TASK_STATE_SUSPEND);
    }
}

int xTaskTerminate(task_t* task) {
    assert(task != NULL);

    port_set_process_state(task->handle, TASK_STATE_TERMINATED);

    return port_terminate_process(task->handle);
}

int  xTaskGetCurrentHandle() {
    return port_get_process_id();
}
task_t* xTaskGetCurrent() {
    task_t* _Task = malloc(sizeof(task_t));
    assert(_Task != NULL);

    _Task->handle = xTaskGetCurrentHandle();
    _Task->userdata = NULL;
    _Task->mainFunc = 0;

    return _Task;
}

int bxTaskIsCurrent(task_t* task) {
    return (task->handle == port_get_process_id()) ? 0 : 1;
}

void __process_main_func(void* taskData) {
    assert(taskData != 0);

    task_t* _this = (task_t *) taskData;
    assert (_this != 0);

    _this->mainFunc(_this->userdata);

    port_set_process_state(_this->handle, TASK_STATE_TERMINATED);
    port_terminate_process(_this->handle);
}