/*
* MIT License
*
* Copyright (c) 2022 Amber-Sophia Schröck

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "libcos/utils/atomic_spinlock.h"
#include "libcos/malloc.h"
#include "assert.h"

atomic_spinlock_t*  pAtomicSpinLockCreate() {
    atomic_spinlock_t*  _newType = malloc(sizeof(atomic_spinlock_t)); 
    
    if(_newType != 0)
        atomic_store(_newType, 0, __ATOMIC_RELEASE);

    return _newType;
}

int xAtomicSpinlockTake(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    while(! atomic_compare_exchange_t(lock, 0, 1,  __ATOMIC_ACQUIRE) ) 
    { }

    return KLIBCOS_NOERROR;
}

int xAtomicSpinlockGive(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    atomic_store(lock, 0, __ATOMIC_RELEASE);
    return KLIBCOS_NOERROR;
}

int xAtomicSpinlockTryTake(atomic_spinlock_t* lock) {
    assert(lock != NULL);

    if(atomic_compare_exchange_t(lock, 0, 1,  __ATOMIC_ACQUIRE))
        return KLIBCOS_ERRROR;
    else 
        xAtomicSpinlockTake(lock);

    return KLIBCOS_NOERROR;
}

int xAtomicSpinlockIsLoked(atomic_spinlock_t*  lock) {
    assert(lock != NULL);

    return __atomic_load_n(lock, __ATOMIC_SEQ_CST) == 1 ? 
        KLIBCOS_STATE_LOCK : KLIBCOS_STATE_UNLOCK;
}

int xAtomicSpinlockDestroy(atomic_spinlock_t*  lock) {
    assert(lock != NULL);

    if(xAtomicSpinlockIsLoked(lock) == KLIBCOS_STATE_LOCK) return KLIBCOS_ERRROR;

    free(lock); lock = NULL;

    return KLIBCOS_NOERROR;
}