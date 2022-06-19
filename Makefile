ASFLAGS = -march=armv6zk -mcpu=arm1176jzf-s   -Iinc -Iinc/klibc -nostdlib
CFLAGS = -O3 -march=armv6zk -mcpu=arm1176jzf-s  -fpic -Iinc -Iinc/klibc -nostdlib -ffreestanding -nostartfiles -nostdinc -nodefaultlibs  -fno-stack-protector  -mfloat-abi=hard 
TCC=/opt/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-gcc
TAS=/opt/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-as
TAR=/opt/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-ar

PORT = src/libcos/port/port.o 

KLIBC = \
	src/libcos/malloc.o \
	src/libcos/string.o \
	src/libcos/stdio.o \
    src/libcos/time.o \
    src/libcos/typeconv.o \
    src/assert.o \
    src/libcos/math_exp.o \
    src/libcos/math_misc.o \
    src/libcos/math_pow.o \
    src/libcos/math_trigo.o \
    src/libcos/ctype.o \
    src/libcos/errno.o \
    src/libcos/stdlib.o \
    src/libcos/sys/utsname.o \
    src/libcos/memclr.o \
    src/libcos/getopt.o \
    src/libcos/getopt_long.o \
    src/libcos/wchar.o\
    src/libcos/wctype.o \
    src/libcos/sleep.o \
    src/libcos/sqrtf.o \
    src/libcos/sprintf.o \
	src/libcos/libgcc.o \
    src/libcos/atomic_spinlock.o 

HASH  = src/libcos/hash/adler32.o \
 		src/libcos/hash/crc.o

PROMPT = " -> "
CD = @echo  $(PROMPT) CD "        " && cd
CC = @echo "   " $(PROMPT) GCC "   " $< && $(TCC)
AS = @echo "   " $(PROMPT) AS "   " $< && $(TAS)
AR = @echo "   " $(PROMPT) AR "   " $< && $(TAR)
RM = @echo "   " $(PROMPT) REM "   " $< && rm
CP = @echo "   " $(PROMPT)  CP && cp

SOURCES=$(KLIBC) $(HASH) $(PORT)

all: $(SOURCES) static
.s.o:
	$(CC) $(CFLAGS) -std=gnu11 -c $< -o $@
.c.o:
	$(CC) $(CFLAGS) -std=gnu11 -c $< -o $@
static:
	$(AR) rcs libcos.a  $(SOURCES) 
clean:
	$(RM) $(SOURCES) libcos.a