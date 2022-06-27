#ifndef __KLIBCOS_ALIGNMENT_H__
#define __KLIBCOS_ALIGNMENT_H__

#include <stddef.h>
#include "types.h"
#include "assert.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define CHECK_TYPE_IS_ALIGNMENT(TYPE)       sizeof(TYPE) > 0

#define TYPE_WITH_ALIGNMENT_CHAR            sizeof(char),
#define TYPE_WITH_ALIGNMENT_SHORT           sizeof(short),
#define TYPE_WITH_ALIGNMENT_INT             sizeof(int),
#define TYPE_WITH_ALIGNMENT_LONG            sizeof(long),
#define TYPE_WITH_ALIGNMENT_llong           sizeof(long long),
#define TYPE_WITH_ALIGNMENT_FLOAT           sizeof(float),
#define TYPE_WITH_ALIGNMENT_DOUBLE          sizeof(double)

#define ALIGMMENT_OF_VOID                   0
#define ALIGMMENT_OF_CONST_VOID             0
#define ALIGNMENT_OF_CONST_VOLATILE_VOID    0
#define ALIGNMENT_OF_VOLATILE_VOID          0

#define ALIGNMENT_OF_TYPE(TYPE)             sizeof(TYPE)  

#define LONG_DOUBLE_ALIGNMENT_TYPE          max_align_t
#define DOUBLE_ALIGNNMENT_TYPE              double
#define LLONG_ALIGNMENT_TYPE                long long
#define LONG_ALIGNMENT_TYPE                 long
#define INT_ALIGNMENT_TYPE                  int
#define SHORT_ALIGNMENT_TYPE                short
#define CHAR_ALIGNMENT_TYPE                 char

typedef struct __attribute__ ((aligned (1)))  aligned1 	{  uint8_t member; } aligned1_t;
typedef struct __attribute__ ((aligned (2)))  aligned2 	{ uint16_t member; } aligned2_t;
typedef struct __attribute__ ((aligned (4)))  aligned4 	{ uint32_t member; } aligned4_t;
typedef struct __attribute__ ((aligned (8)))  aligned8 	{ uint64_t member; } aligned8_t;
typedef struct __attribute__ ((aligned (16))) aligned16 { uint64_t member[2]; } aligned16_t;
typedef struct __attribute__ ((aligned (32))) aligned32 { uint64_t member[4]; } aligned32_t;
typedef struct __attribute__ ((aligned (64))) aligned64 { uint64_t member[8]; } aligned64_t;

typedef union max_align {
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
}max_align_t;

#define MAX_ALIGNMENT sizeof(max_align_t)

static inline _Bool is_aligned(void* p, size_t a) {
    return (uintptr_t)p % a == 0;
}

static inline size_t alignment_for(const size_t size) {
    if(size >= MAX_ALIGNMENT ) return MAX_ALIGNMENT;

    size_t _t = 1;
    unsigned long long value = size;
    return (_t<< NLZ(value) );
}

static inline _Bool is_alignment_valid(size_t alignment) {
    return alignment && (alignment & (alignment - 1)) == 0u;
}

static inline size_t alignment_offset(void* address, size_t alignment) {
    if(!is_alignment_valid(alignment)) return 0;
    
    char* buf = (char*)address;
    return alignment - ( ((size_t)buf) % alignment );
}





static inline void* align_up(void* address, size_t align)  {
    assert(align > 0 && (align & (align - 1)) == 0); /* Power of 2 */
    assert(address != 0);

    uintptr_t addr  = (uintptr_t)address;
    if (addr % align != 0)
        addr += align - addr % align;
    assert(addr >= (uintptr_t)address);

    return (uint8_t *)addr;
}

static inline void* align_down(void* address, size_t align))
{
    assert(align > 0 && (align & (align - 1)) == 0); /* Power of 2 */
    assert(stack != 0);

    uintptr_t addr  = (uintptr_t)address;
    addr &= -align;                         // Round down to align-byte boundary
    assert(addr <= (uintptr_t)address);

    return (uint8_t *)addr;
}

#ifdef	__cplusplus
}
#endif

#endif