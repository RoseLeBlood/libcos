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

