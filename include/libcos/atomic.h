#ifndef STDC_ATOMIC_H
#define STDC_ATOMIC_H

#include <types.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef volatile void* atomic_t;

static inline uint32_t atomic_load (atomic_t pVar, int32_t memorder) {
	return __atomic_load_n (pVar, memorder);
}
static inline uint32_t atomic_store(atomic_t pVar ,uint32_t nValue, int32_t memorder ) {
     __atomic_store_n (pVar, nValue,  memorder);

     return nValue;
}
static inline uint32_t  atomic_exchange(atomic_t pVar, uint32_t nValue, int32_t memorder) {
    return __atomic_exchange_n (pVar, nValue, memorder);
}

static inline uint32_t atomic_add(atomic_t pVar, uint32_t nValue, int32_t memorder) {
    return __atomic_add_fetch (pVar, nValue, memorder);
}

static inline uint32_t atomic_sub(atomic_t pVar, uint32_t nValue, int32_t memorder) {
    return __atomic_sub_fetch (pVar, nValue, memorder);
}

static inline uint32_t atomic_and(atomic_t pVar, uint32_t nValue, int32_t memorder) {
    return __atomic_and_fetch (pVar, nValue, memorder);
}

static inline uint32_t atomic_xor(atomic_t pVar, uint32_t nValue, int32_t memorder) {
    return __atomic_xor_fetch (pVar, nValue, memorder);
}
static inline uint32_t atomic_or(atomic_t pVar, uint32_t nValue, int32_t memorder ) {
    return __atomic_or_fetch (pVar, nValue, memorder);
}

static inline uint32_t atomic_nand(atomic_t pVar, uint32_t nValue, int32_t memorder ) {
    return __atomic_nand_fetch (pVar, nValue, memorder);
}

static inline uint32_t  atomic_increment(atomic_t pVar, int32_t memorder) {
    return atomic_add(pVar, 1, memorder);
}
static inline uint32_t  atomic_decrement(atomic_t pVar, int32_t memorder ) {
    return atomic_sub(pVar, 1, memorder);
}

static inline bool atomic_compare_exchange(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, bool t, int32_t memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, t,
				                 memorder, memorder);
}

static inline bool atomic_compare_exchange_t(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, int32_t memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, true,
				                 memorder, memorder);
}

static inline bool atomic_compare_exchange_f(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, int32_t memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, false,
				                 memorder, memorder);
}

#ifdef  __cplusplus
}
#endif

#endif