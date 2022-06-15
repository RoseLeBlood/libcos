#include "libcos/types.h"

#ifndef PORT_SYS_NAME
#define PORT_SYS_NAME           "native"
#endif

#ifndef PORT_RELEASE_NAME
#define PORT_RELEASE_NAME       ""
#endif

#ifndef PORT_CC_VERSION
#define PORT_CC_VERSION         "1.0"
#endif

#ifndef PORT_MASCHINE_NAME
#define PORT_MASCHINE_NAME      "windows"
#endif

#ifndef PORT_COMPILER_NAME
#define PORT_COMPILER_NAME      "gcc"
#endif

#ifndef PORT_COMPILER_VERSION
#define PORT_COMPILER_VERSION   itoa(__VERSION__)
#endif

#ifdef __cplusplus
extern "C" {
#endif


void port_halt();

#define PRINT_BUF_LEN 12
void port_putchar(const char c);

void port_delay(int usec);

void* port_malloc(size_t size);
void port_free(void* addr);

typedef enum PORTTIMESEC {
    TIME_READ_ADDR_SEC = 0x00,
    TIME_READ_ADDR_MIN = 0x02,
    TIME_READ_ADDR_HOUR = 0x04,
    TIME_READ_ADDR_DAY = 0x07,
    TIME_READ_ADDR_MONTH = 0x08,
    TIME_READ_ADDR_YEAR = 0x09,
} port_time_sec_t;

uint8_t port_time_read(port_time_sec_t addr);


void 			port_outb( unsigned short port, unsigned char val );
void 			port_outi(uint32_t reg, uint32_t data);
DWORD 			port_farpeekl( WORD sel, void * off );
void 			port_farpokeb( WORD sel, void *off, BYTE v );
unsigned char 	port_inb( unsigned short port );
uint32_t		port_ini(uint32_t reg);
void 			port_io_wait( void );

void 			port_lidt( void * base, unsigned short size ); 
unsigned 		port_read_cr0( void );
void 			port_rdtsc( DWORD * upper, DWORD * lower );

void 			port_intr_enable();
void 			port_intr_disable() ;
void 			port_halt();

unsigned short 	port_inw(unsigned short port);
void 			port_outw(unsigned short port, unsigned short data);
unsigned int 	port_inl(unsigned short port);
void 			port_outl(unsigned short port, unsigned int data);
void 			port_insb(unsigned short port, unsigned char *data, unsigned int count);
void 			port_insw(short port, unsigned short *data, unsigned count);
void 			port_insdw(unsigned short port, unsigned int *data, unsigned int count);
void 			port_outsb(unsigned short port, unsigned char *data, unsigned int count);
void 			port_outsw(short port, unsigned short *data, unsigned count);
void 			port_outsdw(unsigned short port, unsigned int *data, unsigned int count);
void 			port_iodelay(int count);
	
void 			port_outd(uint16_t port, uint32_t value);
uint32_t 		port_ind(uint16_t port);

#ifdef __cplusplus
}
#endif
