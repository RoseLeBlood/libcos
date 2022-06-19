#ifndef STDC_ATOMIC_LOCK_H
#define STDC_ATOMIC_LOCK_H

#include <atomic.h>

#ifdef  __cplusplus
extern "C" {
#endif

#define xATOMIC_LOCKED          0
#define xATOMIC_UNLOCKED        1
#define xATOMIC_ERROR           2

typedef struct atomic_spinlock atomic_spinlock_t;

atomic_spinlock_t* pAtomicSpinLockCreate();

int xAtomicSpinlockGive(atomic_spinlock_t* lock);
int xAtomicSpinlockTake(atomic_spinlock_t* lock);
int xAtomicSpinlockTryLock(atomic_spinlock_t* lock);
int xAtomicSpinlockIsLoked(atomic_spinlock_t*  lock);

#ifdef  __cplusplus
}
#endif

#endif