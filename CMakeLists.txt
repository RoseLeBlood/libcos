cmake_minimum_required(VERSION 3.16)
SET(PROJ_NAME "libcos")
PROJECT(${PROJ_NAME} LANGUAGES C)

set(CMAKE_C_STANDARD 99)

# Configuration types
SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
IF(DEFINED CMAKE_BUILD_TYPE AND CMAKE_VERSION VERSION_GREATER "2.8")
  SET_PROPERTY(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS  ${CMAKE_CONFIGURATION_TYPES})
ENDIF()

SET(${PROJ_NAME}_PATH_INSTALL "/opt/project" CACHE PATH "This directory contains installation Path")
SET(CMAKE_DEBUG_POSTFIX "d")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib  -ffreestanding -nostartfiles -nostdinc -nodefaultlibs  -fno-stack-protector  -Iinclude/libcos")

include_directories( ${PROJECT_SOURCE_DIR}/include/libcos)

# Configure ARCH
SET(CARCH, ARM)

add_library(${PROJ_NAME} STATIC  
        src/adler32.c
        src/crc.c
        src/stdlib/bsearch.c
        src/stdlib/sorts.c
        src/stdlib/stdlib.c
        src/stdlib/strtod.c
        src/stdlib/strof.c
        src/stdlib/strol.c
        src/stdlib/stroll.c
        src/stdlib/stroul.c
        src/stdlib/stroull.c
        src/sys/utsname.c
        src/utils/atomic_counter.c
        src/utils/atomic_spinlock.c
        src/alignment.c
        src/assert.c
        src/complex.c
        src/ctype.c
        src/deque.c 
        src/erno.c 
        src/getop_long.c 
        src/getop.c 
        src/langinfo.c 
        src/libgcc.c 
        src/malloc.c 
        src/math_exp.c 
        src/math_misc.c 
        src/math_pow.c 
        src/math_trigo.c 
        src/memclr.c 
        src/node.c 
        src/pair.c 
        src/priority_deque.c
        src/queue.c 
        src/ringbuffer.c 
        src/sleep.c 
        src/sort.c 
        src/sprintf.c 
        src/sqrtf.c 
        src/stdatomic.c 
        src/stdio.c 
        src/storage.c 
        src/string.c 
        src/tgmath.c 
        src/timer.c 
        src/wchar.c 
        src/wctype.c

        src/arch/${CARCH}/longjmp.s 
        src/arch/${CARCH}/setjmp.s 
)

# Install
#---------------------------------------------------#
INSTALL(TARGETS ${PROJ_NAME}
    DESTINATION  "${${PROJ_NAME}_PATH_INSTALL}/lib/${CMAKE_BUILD_TYPE}/"
)