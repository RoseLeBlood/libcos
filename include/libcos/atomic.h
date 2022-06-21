#ifndef STDC_ATOMIC_H
#define STDC_ATOMIC_H

#include <types.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef volatile int32_t* atomic_t;
typedef uint32_t atomic_memorder_t;

#define ATOMIC_MO_RELAXED   __ATOMIC_RELAXED
#define ATOMIC_MO_CONSUM    __ATOMIC_CONSUME
#define ATOMIC_MO_ACQUIRE   __ATOMIC_ACQUIRE
#define ATOMIC_MO_RELEASE   __ATOMIC_RELEASE
#define ATOMIC_MO_ACQREL    __ATOMIC_ACQ_REL
#define ATOMIC_MO_SEQCST    __ATOMIC_SEQ_CST

// MOM = memory_order_modifier
#define ATOMIC_MOM_MASK             0x0ffff
#define ATOMIC_MOM_MODIFIER_MASK    0xffff0000
#define ATOMIC_MOM_HLE_ACQUIRE      0x10000
#define ATOMIC_MOM_HLE_RELEASE      0x20000

#define ATOMIC_MOM_OR(ATMOIC_MO_FLAG, ATOMIC_MOM_FLAG)    (int(ATMOIC_MO_FLAG) | int(ATOMIC_MOM_FLAG))
#define ATOMIC_MOM_AND(ATMOIC_MO_FLAG, ATOMIC_MOM_FLAG)   (int(ATMOIC_MO_FLAG) & int(ATOMIC_MOM_FLAG))

static inline int32_t atomic_load (atomic_t pVar, atomic_memorder_t memorder) {
	return __atomic_load_n (pVar, memorder);
}
static inline int32_t atomic_store(atomic_t pVar ,uint32_t nValue, atomic_memorder_t memorder ) {
     __atomic_store_n (pVar, nValue,  memorder);

     return nValue;
}
static inline int32_t atomic_exchange(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder) {
    return __atomic_exchange_n (pVar, nValue, memorder);
}

static inline int32_t atomic_add(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder) {
    return __atomic_add_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_sub(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder) {
    return __atomic_sub_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_and(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder) {
    return __atomic_and_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_xor(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder) {
    return __atomic_xor_fetch (pVar, nValue, memorder);
}
static inline int32_t atomic_or(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder ) {
    return __atomic_or_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_nand(atomic_t pVar, uint32_t nValue, atomic_memorder_t memorder ) {
    return __atomic_nand_fetch (pVar, nValue, memorder);
}

static inline int32_t  atomic_increment(atomic_t pVar, atomic_memorder_t memorder) {
    return atomic_add(pVar, 1, memorder);
}
static inline int32_t  atomic_decrement(atomic_t pVar, atomic_memorder_t memorder ) {
    return atomic_sub(pVar, 1, memorder);
}

static inline bool atomic_compare_exchange_t(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, atomic_memorder_t memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, true,
				                 memorder, memorder);
}

static inline bool atomic_compare_exchange_f(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, atomic_memorder_t memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, false,
				                 memorder, memorder);
}

#ifdef  __cplusplus
}
#endif

#endif