ASFLAGS = -march=armv6zk -mcpu=arm1176jzf-s   -Iinc -Iinc/klibc -nostdlib
CFLAGS = -O3 -march=armv6zk -mcpu=arm1176jzf-s  -fpic -Iinc -Iinc/klibc -nostdlib -ffreestanding -nostartfiles -nostdinc -nodefaultlibs  -fno-stack-protector  -mfloat-abi=hard 
TCC=/opt/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-gcc
TAS=/opt/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-as
TAR=/opt/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-ar

KLIBC = \
	src/malloc.o \
	src/string.o \
	src/stdio.o \
    src/time.o \
    src/typeconv.o \
    src/assert.o \
    src/math_exp.o \
    src/math_misc.o \
    src/math_pow.o \
    src/math_trigo.o \
    src/ctype.o \
    src/errno.o \
    src/stdlib.o \
    src/sys/utsname.o \
    src/libgcc.o \
    src/memclr.o \
    src/getopt.o \
    src/getopt_long.o \
    src/wchar.o\
    src/wctype.o \
    src/sleep.o \
    src/sqrtf.o \
    src/sprintf.o \
	src/assert.o \
	src/libgcc.o

HASH  = src/hash/adler32.o \
 		src/hash/crc.o

PROMPT = " -> "
CD = @echo  $(PROMPT) CD "        " && cd
CC = @echo "   " $(PROMPT) GCC "   " $< && $(TCC)
AS = @echo "   " $(PROMPT) AS "   " $< && $(TAS)
AR = @echo "   " $(PROMPT) AR "   " $< && $(TAR)
RM = @echo "   " $(PROMPT) REM "   " $< && rm
CP = @echo "   " $(PROMPT)  CP && cp

SOURCES=$(KLIBC) $(HASH)

all: $(SOURCES) static
.s.o:
	$(CC) $(CFLAGS) -std=gnu11 -c $< -o $@
.c.o:
	$(CC) $(CFLAGS) -std=gnu11 -c $< -o $@
static:
	$(AR) rcs libcos.a  $(SOURCES) 
clean:
	$(RM) $(SOURCES) libcos.a