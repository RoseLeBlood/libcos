#include "assert.h"
#include "libcos/types.h"
#include "libcos/stdio.h"
#include "private/port.h"

void __assert(const char *ext, const char *file, int line) {
	printf("assertion failed in file %s, line %d:\n", file, line);
	printf("%s\n", ext);
	
	port_halt();
	for(;;) ;
}
void __panic(const char *message, const char *file, int line) {
	printf("panic: %s at %s : %d\n", message, file, line);

	port_halt();
    for(;;) ;
}