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
#ifndef __KLINCOS_PORT_H__
#define __KLINCOS_PORT_H__

#include "libcos/types.h"
#include "libconfig.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef enum PORTTIMESEC {
    TIME_READ_ADDR_SEC = 0x00,
    TIME_READ_ADDR_MIN = 0x02,
    TIME_READ_ADDR_HOUR = 0x04,
    TIME_READ_ADDR_DAY = 0x07,
    TIME_READ_ADDR_MONTH = 0x08,
    TIME_READ_ADDR_YEAR = 0x09,
} port_time_sec_t;

void            port_putchar(const char c);

void*           port_malloc(size_t size);
void            port_free(void* addr);

uint8_t         port_time_read(port_time_sec_t addr);

int             port_create_process(void (*main)(void*), const char* name, uint32_t stackSize);
int             port_start_process(int pid, void* userdata);
int             port_get_process_state(int pid);
void            port_set_process_state(int pid, uint8_t state);
int             port_get_process_id();
int             port_terminate_process(int pid);
void*           port_get_process_regs(int pid);

void            port_shedular_task_switch(void* pOldRegs, void* pNewRegs);

void 			port_io_wait( void );
void 			port_iodelay(int count);

void 			port_intr_enable();
void 			port_intr_disable() ;
void 			port_halt();

void*           port_get_curr_stack_pointer() { return NULL; }

#if KLIBCOS_NULTICORE_SYSTEM == KLIBCOS_TRUE
    void            port_data_barriere();
    void            port_mem_barriere();
#else
    #define         port_data_barriere() 
    #define         port_mem_barriere()
#endif

#ifdef __cplusplus
}
#endif


#endif