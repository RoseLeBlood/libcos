#ifndef	_HASH_ADLER_H
#define	_HASH_ADLER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../types.h"
#include "../stdio.h"
#include "../string.h"

unsigned int adler32ex (unsigned int initial,const char* data, unsigned int start, size_t length);
unsigned int adler32 (unsigned int initial,const char* data, size_t length);

#ifdef	__cplusplus
}
#endif

#endif	