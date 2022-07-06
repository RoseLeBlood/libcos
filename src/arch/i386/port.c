
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
#include "private/port.h"

#ifdef LIBCOS_ARCH_I386 

// ----------------- malloc.h
void* port_malloc(size_t size) {
    return NULL;
}
void port_free(void* addr) {

}

uint8_t port_time_read(port_time_sec_t addr) {
        return 0;
}

void port_putchar(const char c) {

}
/* port_getchar */
int port_getchar() {
     char c = ' '; 
     
     //while((c = getch()) == 0);
     
     return c;
}

void 			port_io_wait( void )  {
    asm("pause");
}

clock_t 		port_clock() { 
    
}


void 			port_intr_enable()  {
    asm volatile ("sti" : : : "memory")
}

void 			port_intr_disable()   {
    asm volatile ("cli" : : : "memory")
}

void 			port_halt()  {

}

void* port_get_curr_stack_pointer() {
    int *_esp;
    asm volatile ("movl %esp, _esp");

    return _esp;
}


#endif