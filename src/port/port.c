
#include "libcos/private/port.h"

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

int port_create_process(void (*main)(void*), const char* name, uint32_t stackSize) {
     return 1;
}
int port_start_process(int pid, void* userdata) {

}
int port_get_process_state(int pid) {
     return 1;
}
void port_set_process_state(int pid, uint8_t state) {
    
}

int port_get_process_id() {
     return 1;
}
int port_terminate_process(int pid) {
     return 0;
}


// ---------------- IO
void 			port_outb( unsigned short port, unsigned char val )  {

}

void 			port_outi(uint32_t reg, uint32_t data)  {

}

void 			port_outd(uint16_t port, uint32_t value)  {

}

void 			port_outw(unsigned short port, unsigned short data)  {

}

void 			port_outl(unsigned short port, unsigned int data)  {

}

void 			port_outsb(unsigned short port, unsigned char *data, unsigned int count)  {

}

void 			port_outsw(short port, unsigned short *data, unsigned count)  {

}

void 			port_outsdw(unsigned short port, unsigned int *data, unsigned int count)  {

}


unsigned char  	port_inb( unsigned short port )  {
     return 0;
}

uint32_t		     port_ini(uint32_t reg)  {
     return 0;
}

uint32_t 		     port_ind(uint16_t port)  {
     return 0;
}

unsigned short 	port_inw(unsigned short port)  {
     return 0;
}    

unsigned int 	     port_inl(unsigned short port)  {
     return 0;
}

void 			port_insb(unsigned short port, unsigned char *data, unsigned int count)  {

}

void 			port_insw(short port, unsigned short *data, unsigned count)  {

}

void 			port_insdw(unsigned short port, unsigned int *data, unsigned int count)  {

}



void 			port_io_wait( void )  {

}

void 			port_iodelay(int count)  { 
    unsigned nloops = (count * (SYS_CLK_KHZ / 1000) + 7) >> 3;

    do {
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
            asm volatile ("nop");
    } while (--nloops);
}


void 			port_intr_enable()  {

}

void 			port_intr_disable()   {

}

void 			port_halt()  {

}
