# libcos
A simple lib C for osdev

libcos is a very simple biblothek for os developers. It contains simple functions that you need in everyday kernel development.

Porting to the required target platform is very easy. All you have to do is fill in the functions in "src/private/port.c" for the corresponding platform.

```

void            port_putchar(const char c);

void*           port_malloc(size_t size);
void            port_free(void* addr);

uint8_t         port_time_read(port_time_sec_t addr);

void 			port_outb( unsigned short port, unsigned char val );
void 			port_outi(uint32_t reg, uint32_t data);
void 			port_outd(uint16_t port, uint32_t value);
void 			port_outw(unsigned short port, unsigned short data);
void 			port_outl(unsigned short port, unsigned int data);
void 			port_outsb(unsigned short port, unsigned char *data, unsigned int count);
void 			port_outsw(short port, unsigned short *data, unsigned count);
void 			port_outsdw(unsigned short port, unsigned int *data, unsigned int count);

unsigned char 	port_inb( unsigned short port );
uint32_t		port_ini(uint32_t reg);
uint32_t 		port_ind(uint16_t port);
unsigned short 	port_inw(unsigned short port);
unsigned int 	port_inl(unsigned short port);
void 			port_insb(unsigned short port, unsigned char *data, unsigned int count);
void 			port_insw(short port, unsigned short *data, unsigned count);
void 			port_insdw(unsigned short port, unsigned int *data, unsigned int count);


void 			port_io_wait( void );
void 			port_iodelay(int count);

void 			port_intr_enable();
void 			port_intr_disable() ;
void 			port_halt();