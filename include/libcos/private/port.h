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

#include "types.h"
#include "libconfig.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__aarch64__) || defined(_M_ARM64)
    typedef unsigned long jmp_buf_type[22];
#elif defined(__x86_64__) || defined(_M_X64)
    typedef unsigned long jmp_buf_type[8];
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    typedef unsigned long long jmp_buf_type[8];
#else
    // Your type for jmp_buf_type
#endif

typedef struct _jmp_tag {
	jmp_buf_type __jb;
	unsigned long __fl;
	unsigned long __ss[128 / sizeof(long)];
} jmp_buf_t[1];

typedef jmp_buf_t sigjmp_buf;

typedef enum PORTTIMESEC {
    TIME_READ_ADDR_SEC = 0x00,
    TIME_READ_ADDR_MIN = 0x02,
    TIME_READ_ADDR_HOUR = 0x04,
    TIME_READ_ADDR_DAY = 0x07,
    TIME_READ_ADDR_MONTH = 0x08,
    TIME_READ_ADDR_YEAR = 0x09,
} port_time_sec_t;

void            port_putchar(const char c);
int             port_getchar();

void*           port_malloc(size_t size);
void            port_free(void* addr);

uint8_t         port_time_read(port_time_sec_t addr);

void 			port_io_wait( void );
void 			port_iodelay(int count);

void 			port_intr_enable();
void 			port_intr_disable() ;
void 			port_halt();

void*           port_get_curr_stack_pointer();

#ifdef __cplusplus
}
#endif


#endif