cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER "gcc" )
set(CMAKE_C_STANDARD 99)


SET(CARCH "x64")



PROJECT(${PROJ_NAME} LANGUAGES C)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdlib  -ffreestanding -nostartfiles -nostdinc -nodefaultlibs  -fno-stack-protector  -Iinclude/libcos")
SET(CMAKE_DEBUG_POSTFIX "d")

include_directories( ${PROJECT_SOURCE_DIR}/include/libcos  ${PROJECT_SOURCE_DIR}/include/)

# Configure ARCH
IF( ${CARCH} STREQUAL "ARM" )
    SET(CARCH_FILES  ${PROJECT_SOURCE_DIR}/src/arch/arm/longjmp.s 
                     ${PROJECT_SOURCE_DIR}/src/arch/arm/setjmp.s)
                     SET(PROJ_NAME "cos_arm")
elseif ( ${CARCH} STREQUAL "i386" )
    SET(CARCH_FILES  ${PROJECT_SOURCE_DIR}/src/arch/i386/longjmp.s 
                     ${PROJECT_SOURCE_DIR}/src/arch/i386/setjmp.s)
                     SET(PROJ_NAME "cos_i386")
elseif ( ${CARCH} STREQUAL "x64" )
    SET(CARCH_FILES  ${PROJECT_SOURCE_DIR}/src/arch/x86_64/longjmp.s 
                     ${PROJECT_SOURCE_DIR}/src/arch/x86_64/setjmp.s)
                     SET(PROJ_NAME "cos_x64")
elseif ( ${CARCH} STREQUAL "aarch64" )
    SET(CARCH_FILES  ${PROJECT_SOURCE_DIR}/src/arch/aarch64/longjmp.s 
                     ${PROJECT_SOURCE_DIR}/src/arch/aarch64/setjmp.s)
                     SET(PROJ_NAME "cos_aarch64")
else()
    SET(CARCH_FILES  ${PROJECT_SOURCE_DIR}/src/arch/user/port.c 
                     ${PROJECT_SOURCE_DIR}/src/arch/user/longjmp.s 
                     ${PROJECT_SOURCE_DIR}/src/arch/user/setjmp.s)
                     SET(PROJ_NAME "cos_user")
ENDIF()

add_library(${PROJ_NAME} STATIC  
${PROJECT_SOURCE_DIR}/src/hash/adler32.c
${PROJECT_SOURCE_DIR}/src/hash/crc.c
${PROJECT_SOURCE_DIR}/src/stdlib/bsearch.c
${PROJECT_SOURCE_DIR}/src/stdlib/sorts.c
${PROJECT_SOURCE_DIR}/src/stdlib/stdlib.c
${PROJECT_SOURCE_DIR}/src/stdlib/strtod.c
${PROJECT_SOURCE_DIR}/src/stdlib/strtof.c
${PROJECT_SOURCE_DIR}/src/stdlib/strtol.c
${PROJECT_SOURCE_DIR}/src/stdlib/strtoll.c
${PROJECT_SOURCE_DIR}/src/stdlib/strtoul.c
${PROJECT_SOURCE_DIR}/src/stdlib/strtoull.c
${PROJECT_SOURCE_DIR}/src/sys/utsname.c
${PROJECT_SOURCE_DIR}/src/utils/atomic_counter.c
${PROJECT_SOURCE_DIR}/src/utils/atomic_spinlock.c
${PROJECT_SOURCE_DIR}/src/alignment.c
${PROJECT_SOURCE_DIR}/src/assert.c
${PROJECT_SOURCE_DIR}/src/complex.c
${PROJECT_SOURCE_DIR}/src/ctype.c
${PROJECT_SOURCE_DIR}/src/deque.c 
${PROJECT_SOURCE_DIR}/src/errno.c 
${PROJECT_SOURCE_DIR}/src/getopt_long.c 
${PROJECT_SOURCE_DIR}/src/getopt.c 
${PROJECT_SOURCE_DIR}/src/langinfo.c 
${PROJECT_SOURCE_DIR}/src/libgcc.c 
${PROJECT_SOURCE_DIR}/src/malloc.c 
${PROJECT_SOURCE_DIR}/src/math_exp.c 
${PROJECT_SOURCE_DIR}/src/math_misc.c 
${PROJECT_SOURCE_DIR}/src/math_pow.c 
${PROJECT_SOURCE_DIR}/src/math_trigo.c 
${PROJECT_SOURCE_DIR}/src/memclr.c 
${PROJECT_SOURCE_DIR}/src/node.c 
${PROJECT_SOURCE_DIR}/src/pair.c 
${PROJECT_SOURCE_DIR}/src/priority_deque.c
${PROJECT_SOURCE_DIR}/src/queue.c 
${PROJECT_SOURCE_DIR}/src/ringbuffer.c 
${PROJECT_SOURCE_DIR}/src/sleep.c 
${PROJECT_SOURCE_DIR}/src/sort.c 
${PROJECT_SOURCE_DIR}/src/sprintf.c 
${PROJECT_SOURCE_DIR}/src/sqrtf.c 
${PROJECT_SOURCE_DIR}/src/stdatomic.c 
${PROJECT_SOURCE_DIR}/src/stdio.c 
${PROJECT_SOURCE_DIR}/src/storage.c 
${PROJECT_SOURCE_DIR}/src/string.c 
${PROJECT_SOURCE_DIR}/src/tgmath.c 
${PROJECT_SOURCE_DIR}/src/time.c 
${PROJECT_SOURCE_DIR}/src/wchar.c 
${PROJECT_SOURCE_DIR}/src/wctype.c

${CARCH_FILES}
)

# Install
#-------------------------------------- -------------#
INSTALL(TARGETS ${PROJ_NAME}
    DESTINATION  "${${PROJ_NAME}_PATH_INSTALL}/lib/${CMAKE_BUILD_TYPE}/"
)