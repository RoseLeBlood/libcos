#ifndef LIBKC_STDATOMIC_H_
#define	LIBKC_STDATOMIC_H_

#include <types.h>


#ifdef  __cplusplus
extern "C" {
#endif

#ifdef __GCC_ATOMIC_BOOL_LOCK_FREE
#define	ATOMIC_BOOL_LOCK_FREE		__GCC_ATOMIC_BOOL_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_CHAR_LOCK_FREE
#define	ATOMIC_CHAR_LOCK_FREE		__GCC_ATOMIC_CHAR_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_CHAR16_T_LOCK_FREE
#define	ATOMIC_CHAR16_T_LOCK_FREE	__GCC_ATOMIC_CHAR16_T_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_CHAR32_T_LOCK_FREE
#define	ATOMIC_CHAR32_T_LOCK_FREE	__GCC_ATOMIC_CHAR32_T_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_WCHAR_T_LOCK_FREE
#define	ATOMIC_WCHAR_T_LOCK_FREE	__GCC_ATOMIC_WCHAR_T_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_SHORT_LOCK_FREE
#define	ATOMIC_SHORT_LOCK_FREE		__GCC_ATOMIC_SHORT_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_INT_LOCK_FREE
#define	ATOMIC_INT_LOCK_FREE		__GCC_ATOMIC_INT_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_LONG_LOCK_FREE
#define	ATOMIC_LONG_LOCK_FREE		__GCC_ATOMIC_LONG_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_LLONG_LOCK_FREE
#define	ATOMIC_LLONG_LOCK_FREE		__GCC_ATOMIC_LLONG_LOCK_FREE
#endif
#ifdef __GCC_ATOMIC_POINTER_LOCK_FREE
#define	ATOMIC_POINTER_LOCK_FREE	__GCC_ATOMIC_POINTER_LOCK_FREE
#endif

#define	ATOMIC_VAR_INIT(value)		{ .__val = (value) }
#define	atomic_init(obj, value)		((void)((obj)->__val = (value)))


#ifndef __ATOMIC_RELAXED
#define __ATOMIC_RELAXED		0
#endif
#ifndef __ATOMIC_CONSUME
#define __ATOMIC_CONSUME		1
#endif
#ifndef __ATOMIC_ACQUIRE
#define __ATOMIC_ACQUIRE		2
#endif
#ifndef __ATOMIC_RELEASE
#define __ATOMIC_RELEASE		3
#endif
#ifndef __ATOMIC_ACQ_REL
#define __ATOMIC_ACQ_REL		4
#endif
#ifndef __ATOMIC_SEQ_CST
#define __ATOMIC_SEQ_CST		5
#endif

#define	atomic_is_lock_free(obj)  __atomic_is_lock_free(sizeof((obj)->__val), &(obj)->__val)

#define	ATOMIC_FLAG_INIT		{ ATOMIC_VAR_INIT(0) }



typedef enum {
	memory_order_relaxed = __ATOMIC_RELAXED,
	memory_order_consume = __ATOMIC_CONSUME,
	memory_order_acquire = __ATOMIC_ACQUIRE,
	memory_order_release = __ATOMIC_RELEASE,
	memory_order_acq_rel = __ATOMIC_ACQ_REL,
	memory_order_seq_cst = __ATOMIC_SEQ_CST
} memory_order;

typedef _Atomic(_Bool)			    atomic_bool;
typedef _Atomic(char)			    atomic_char;
typedef _Atomic(signed char)		atomic_schar;
typedef _Atomic(unsigned char)		atomic_uchar;
typedef _Atomic(short)			    atomic_short;
typedef _Atomic(unsigned short)		atomic_ushort;
typedef _Atomic(int)			    atomic_int;
typedef _Atomic(unsigned int)		atomic_uint;
typedef _Atomic(long)			    atomic_long;
typedef _Atomic(unsigned long)		atomic_ulong;
typedef _Atomic(long long)		    atomic_llong;
typedef _Atomic(unsigned long long)	atomic_ullong;

typedef _Atomic(wchar_t)		    atomic_wchar_t;
typedef _Atomic(int_least8_t)		atomic_int_least8_t;
typedef _Atomic(uint_least8_t)		atomic_uint_least8_t;
typedef _Atomic(int_least16_t)		atomic_int_least16_t;
typedef _Atomic(uint_least16_t)		atomic_uint_least16_t;
typedef _Atomic(int_least32_t)		atomic_int_least32_t;
typedef _Atomic(uint_least32_t)		atomic_uint_least32_t;
typedef _Atomic(int_least64_t)		atomic_int_least64_t;
typedef _Atomic(uint_least64_t)		atomic_uint_least64_t;
typedef _Atomic(int_fast8_t)		atomic_int_fast8_t;
typedef _Atomic(uint_fast8_t)		atomic_uint_fast8_t;
typedef _Atomic(int_fast16_t)		atomic_int_fast16_t;
typedef _Atomic(uint_fast16_t)		atomic_uint_fast16_t;
typedef _Atomic(int_fast32_t)		atomic_int_fast32_t;
typedef _Atomic(uint_fast32_t)		atomic_uint_fast32_t;
typedef _Atomic(int_fast64_t)		atomic_int_fast64_t;
typedef _Atomic(uint_fast64_t)		atomic_uint_fast64_t;
typedef _Atomic(intptr_t)		    atomic_intptr_t;
typedef _Atomic(uintptr_t)		    atomic_uintptr_t;
typedef _Atomic(size_t)			    atomic_size_t;
typedef _Atomic(ptrdiff_t)		    atomic_ptrdiff_t;

typedef volatile int32_t* 			atomic_t;

typedef struct {
	atomic_bool	flag;
} atomic_flag;

// MOM = memory_order_modifier
#define ATOMIC_MOM_MASK             0x0ffff
#define ATOMIC_MOM_MODIFIER_MASK    0xffff0000
#define ATOMIC_MOM_HLE_ACQUIRE      0x10000
#define ATOMIC_MOM_HLE_RELEASE      0x20000

#define ATOMIC_MOM_OR(ATMOIC_MO_FLAG, ATOMIC_MOM_FLAG)    (int(ATMOIC_MO_FLAG) | int(ATOMIC_MOM_FLAG))
#define ATOMIC_MOM_AND(ATMOIC_MO_FLAG, ATOMIC_MOM_FLAG)   (int(ATMOIC_MO_FLAG) & int(ATOMIC_MOM_FLAG))

static inline bool atomic_flag_test_and_set_explicit(volatile atomic_flag *pObj, memory_order order)
{
	return (__atomic_exchange_n(&pObj->flag, 1, order));
}

static inline void atomic_flag_clear_explicit(volatile atomic_flag *pObj, memory_order order)
{

	__atomic_store_n(&pObj->flag, 0, order);
}

static inline void atomic_thread_fence(memory_order order) {
	__atomic_thread_fence(order);
}

static inline void atomic_signal_fence(memory_order order) {
	__atomic_signal_fence(order);
}

static inline int32_t atomic_load (atomic_t pVar, memory_order memorder) {
	return __atomic_load_n (pVar, memorder);
}
static inline int32_t atomic_store(atomic_t pVar ,uint32_t nValue, memory_order memorder ) {
     __atomic_store_n (pVar, nValue,  memorder);

     return nValue;
}
static inline int32_t atomic_exchange(atomic_t pVar, uint32_t nValue, memory_order memorder) {
    return __atomic_exchange_n (pVar, nValue, memorder);
}

static inline int32_t atomic_add(atomic_t pVar, uint32_t nValue, memory_order memorder) {
    return __atomic_add_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_sub(atomic_t pVar, uint32_t nValue, memory_order memorder) {
    return __atomic_sub_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_and(atomic_t pVar, uint32_t nValue, memory_order memorder) {
    return __atomic_and_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_xor(atomic_t pVar, uint32_t nValue, memory_order memorder) {
    return __atomic_xor_fetch (pVar, nValue, memorder);
}
static inline int32_t atomic_or(atomic_t pVar, uint32_t nValue, memory_order memorder ) {
    return __atomic_or_fetch (pVar, nValue, memorder);
}

static inline int32_t atomic_nand(atomic_t pVar, uint32_t nValue, memory_order memorder ) {
    return __atomic_nand_fetch (pVar, nValue, memorder);
}

static inline int32_t  atomic_increment(atomic_t pVar, memory_order memorder) {
    return atomic_add(pVar, 1, memorder);
}
static inline int32_t  atomic_decrement(atomic_t pVar, memory_order memorder ) {
    return atomic_sub(pVar, 1, memorder);
}

static inline bool atomic_compare_exchange_t(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, memory_order memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, true,
				                 memorder, memorder);
}

static inline bool atomic_compare_exchange_f(atomic_t pVar, uint32_t nComperand, uint32_t nExchange, memory_order memorder) {
    return __atomic_compare_exchange_n (pVar, &nComperand, &nExchange, false,
				                 memorder, memorder);
}

#ifdef  __cplusplus
}
#endif

#endif