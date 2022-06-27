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

#define ALIGN_DOWN(addr, size)              ((addr) / (size) * (size))
#define ALIGN_UP(addr, size)                ALIGN_DOWN((addr) + (size) - 1, (size))

#define ALIGN_PTR_DOWN(ptr, size)           ((typeof(p))ALIGN_DOWN((uintptr_t)(ptr), (size)))
#define ALIGN_PTR_UP(ptr, size)             ((typeof(p))ALIGN_UP((uintptr_t)(ptr), (size)))

#define IS_ALIGNED(addr, size)              (((addr) % (size)) == 0)
#define PTR_IS_ALIGNED(ptr, size)           IS_ALIGNED((uintptr_t)(ptr), (size))

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





#ifdef	__cplusplus
}
#endif

#endif