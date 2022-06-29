#include "libcos/utils/atomic_spinlock.h"
#include "libcos/malloc.h"
#include "assert.h"

atomic_spinlock_t  pAtomicSpinLockCreate() {
    register atomic_spinlock_t  _newType; 

    atomic_store(&_newType, 0, __ATOMIC_RELEASE);

    return _newType;
}

int xAtomicSpinlockTake(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    while(! atomic_compare_exchange_t(&lock, 0, 1,  __ATOMIC_ACQUIRE) ) 
    { }

    return KLIBCOS_NOERROR;
}

int xAtomicSpinlockGive(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    atomic_store(&lock, 0, __ATOMIC_RELEASE);
    return KLIBCOS_NOERROR;
}

int xAtomicSpinlockTryTake(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    if(atomic_compare_exchange_t(&lock, 0, 1,  __ATOMIC_ACQUIRE))
        return KLIBCOS_ERRROR;
    else 
        xAtomicSpinlockTake(lock);

    return KLIBCOS_NOERROR;
}

int xAtomicSpinlockIsLoked(atomic_spinlock_t*  lock) {
    assert(lock != NULL);

    return __atomic_load_n(&lock, __ATOMIC_SEQ_CST) == 1 ? 
        KLIBCOS_STATE_LOCK : KLIBCOS_STATE_UNLOCK;
}

int xAtomicSpinlockDestroy(atomic_spinlock_t*  lock) {
    assert(lock != NULL);

    if(xAtomicSpinlockIsLoked(lock) == KLIBCOS_STATE_LOCK) return KLIBCOS_ERRROR;

    free(lock); lock = NULL;

    return KLIBCOS_NOERROR;
}