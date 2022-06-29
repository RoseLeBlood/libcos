#ifndef STDC_ATOMIC_LOCK_H
#define STDC_ATOMIC_LOCK_H

#include <stdatomic.h>

#include "error.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef uint32_t atomic_spinlock_t;

atomic_spinlock_t pAtomicSpinLockCreate();

int xAtomicSpinlockGive(atomic_spinlock_t* lock);
int xAtomicSpinlockTake(atomic_spinlock_t* lock);
int xAtomicSpinlockTryTake(atomic_spinlock_t* lock);
int xAtomicSpinlockIsLoked(atomic_spinlock_t*  lock);
int xAtomicSpinlockDestroy(atomic_spinlock_t*  lock);

#ifdef  __cplusplus
}
#endif

#endif