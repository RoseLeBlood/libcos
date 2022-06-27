#ifndef KLIBC_RAND_H
#define KLIBC_RAND_H

#include "storage.h"
#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif

int rand_xorshift(uint32_t seed);
int rand_lfsr(uint32_t seed);

int rand_xorshift_s(uint32_t min, uint32_t max);
int rand_lfsr_s(uint32_t min, uint32_t max);

#ifdef __cplusplus
}
#endif

#endif