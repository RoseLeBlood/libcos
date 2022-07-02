#ifndef _STDC_LOCK_H_
#define _STDC_LOCK_H_

#include <types.h>
#include "utils/atomic_spinlock.h"

typedef atomic_spinlock_t lock_t;
/**
 * @brief create a atomic spinlock
 * lock_t lock = section_create();
 * if(lock != NULL) {
 * 		// spinlock created
 * 		section_enter(lock);
 * 		// locked
 * 		section_leave(lock);
 *		// not locked
 *		
 * }
 * section_destroy(lock);
 */
#define section_create 		pAtomicSpinLockCreate()
/**
 * @brief enter a section
 */
#define section_enter(l) 	xAtomicSpinlockTake(l)
/**
 * @brief leave a section
 */
#define section_leave(l)	xAtomicSpinlockGive(l)
/**
 * @brief destroy a section
 */
#define section_destroy(l)	xAtomicSpinlockDestroy(l)


#endif