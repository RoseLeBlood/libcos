#ifndef __STD_ENDIAN_H__
#define __STD_ENDIAN_H__

#include "types.h"

#define	__LITTLE_ENDIAN	1234
#define	__BIG_ENDIAN	4321
#define	__PDP_ENDIAN	3412

#ifdef __ARMEB__
#define	__BYTE_ORDER	__BIG_ENDIAN
#else
#define	__BYTE_ORDER	__LITTLE_ENDIAN
#endif

#define __FLOAT_WORD_ORDER	__BYTE_ORDER

#if __BYTE_ORDER == __LITTLE_ENDIAN
    #define __LONG_LONG_PAIR(HI, LO) LO, HI

    #define	__QUAD_HIGHWORD	1
    #define	__QUAD_LOWWORD	0

    #define	__htonl(_x)	__bswap32(_x)
    #define	__htons(_x)	__bswap16(_x)
    #define	__ntohl(_x)	__bswap32(_x)
    #define	__ntohs(_x)	__bswap16(_x)
#elif __BYTE_ORDER == __BIG_ENDIAN
    #define __LONG_LONG_PAIR(HI, LO) HI, LO
    #define	__QUAD_HIGHWORD	0
    #define	__QUAD_LOWWORD	1 

    #define	__htonl(_x)	((uint32_t)(_x))
    #define	__htons(_x)	((uint16_t)(_x))
    #define	__ntohl(_x)	((uint32_t)(_x))
    #define	__ntohs(_x)	((uint16_t)(_x))  
#endif

#define __WORDSIZE 32

#ifdef __GNUC__
    #define	__bswap16(_x)	__builtin_bswap16(_x)
    #define	__bswap32(_x)	__builtin_bswap32(_x)
    #define	__bswap64(_x)	__builtin_bswap64(_x)
#else /* __GNUC__ */
    static inline uint16_t __bswap16(uint16_t _x) {
	    return ((uint16_t)((_x >> 8) | ((_x << 8) & 0xff00)));
    }
    static inline uint32_t __bswap32(uint32_t _x) {
        return ((uint32_t)((_x >> 24) | ((_x >> 8) & 0xff00) |
            ((_x << 8) & 0xff0000) | ((_x << 24) & 0xff000000)));
    }

    static inline uint64_t __bswap64(uint64_t _x) {
        return ((uint64_t)((_x >> 56) | ((_x >> 40) & 0xff00) |
            ((_x >> 24) & 0xff0000) | ((_x >> 8) & 0xff000000) |
            ((_x << 8) & ((uint64_t)0xff << 32)) |
            ((_x << 24) & ((uint64_t)0xff << 40)) |
            ((_x << 40) & ((uint64_t)0xff << 48)) | ((_x << 56))));
    }
#endif


#endif