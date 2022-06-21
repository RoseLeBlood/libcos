#include "libcos/utils/atomic_spinlock.h"
#include "libcos/malloc.h"
#include "assert.h"

typedef struct atomic_spinlock {
    uint32_t locked;
}atomic_spinlock_t;

atomic_spinlock_t*  pAtomicSpinLockCreate() {
    atomic_spinlock_t*  _newType = malloc(sizeof(atomic_spinlock_t));
    assert(_newType != NULL);

    atomic_store(&_newType->locked, 0, __ATOMIC_RELEASE);

    return _newType;
}

int xAtomicSpinlockTake(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    while(! atomic_compare_exchange_t(&lock->locked, 0, 1,  __ATOMIC_ACQUIRE) ) 
    { }

    return xATOMIC_LOCKED;
}

int xAtomicSpinlockGive(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    atomic_store(&lock->locked, 0, __ATOMIC_RELEASE);
    return xATOMIC_LOCKED;
}

int xAtomicSpinlockTryLock(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    if(atomic_compare_exchange_t(&lock->locked, 0, 1,  __ATOMIC_ACQUIRE))
        return xATOMIC_ERROR;
    else 
        xAtomicSpinlockTake(lock);

    return xATOMIC_LOCKED;
}

int xAtomicSpinlockIsLoked(atomic_spinlock_t*  lock) {
    assert(lock != NULL);

    return __atomic_load_n(&lock->locked, __ATOMIC_SEQ_CST) == 1 ? 
        xATOMIC_LOCKED : xATOMIC_UNLOCKED;
}

int xAtomicSpinlockDestroy(atomic_spinlock_t*  lock) {
    assert(lock != NULL);

    if(xAtomicSpinlockIsLoked(lock) == xATOMIC_LOCKED) return xATOMIC_ERROR;

    free(lock); lock = NULL;

    return 0;
}