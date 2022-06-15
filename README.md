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

void 			port_outb( unsigned short port, unsigned char val ) {

}

void 			port_outi(uint32_t reg, uint32_t data) {

}

DWORD 			port_farpeekl( WORD sel, void * off ) {
    return 0;
}

void 			port_farpokeb( WORD sel, void *off, BYTE v ) {

}

unsigned char 	port_inb( unsigned short port ) {
     return 0;
}

uint32_t		port_ini(uint32_t reg) {
     return 0;
}

void 			port_io_wait( void ) {

}


void 			port_lidt( void * base, unsigned short size ) {

}
 
unsigned 		port_read_cr0( void ) {
     return 0;
}

void 			port_rdtsc( DWORD * upper, DWORD * lower ) {

}


void 			port_intr_enable() {

}

void 			port_intr_disable() {

}

void 			port_halt() {

}


unsigned short 	port_inw(unsigned short port) {
     return 0;
}

void 			port_outw(unsigned short port, unsigned short data) {

}

unsigned int 	port_inl(unsigned short port) {
     return 0;
}

void 			port_outl(unsigned short port, unsigned int data) {

}

void 			port_insb(unsigned short port, unsigned char *data, unsigned int count) {

}

void 			port_insw(short port, unsigned short *data, unsigned count) {

}

void 			port_insdw(unsigned short port, unsigned int *data, unsigned int count) {

}

void 			port_outsb(unsigned short port, unsigned char *data, unsigned int count) {

}

void 			port_outsw(short port, unsigned short *data, unsigned count) {

}

void 			port_outsdw(unsigned short port, unsigned int *data, unsigned int count) {

}

void 			port_iodelay(int count) {

}

	
void 			port_outd(uint16_t port, uint32_t value) {

}

uint32_t 		port_ind(uint16_t port) {
     return 0;
}

