#ifndef KLIBC_RAND_H
#define KLIBC_RAND_H

#include "storage.h"
#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif

int  rand_xorshift();
void srand_xorshift (unsigned int seed);


#ifdef __cplusplus
}
#endif

#endif