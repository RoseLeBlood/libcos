# libcos
A simple lib C for osdev

libcos is a very simple biblothek for os developers. It contains simple functions that you need in everyday kernel development.

Porting to the required target platform is very easy. All you have to do is fill in the functions in "src/private/port.c" for the corresponding platform.

```
#include "private/port.h"

void port_halt() {
    
}

void* port_malloc(size_t size) {
    return NULL;
}
void port_free(void* addr) {

}

void port_delay(int usec) {
    /*
    
    Raspberry PI example: 
    unsigned nloops = (usec * (SYS_CLK_KHZ / 1000) + 7) >> 3;

    do {
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
    } while (--nloops);*/
}



uint8_t port_time_read(port_time_sec_t addr) {
        return 0;
}

void port_putchar(const char c) {

}
´´´
