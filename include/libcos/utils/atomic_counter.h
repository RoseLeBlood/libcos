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

/// \brief implements a simple counter, whit atomic operations for use in a multithreaded environment. 

#ifndef STDC_ATOMIC_COUNTER_H
#define STDC_ATOMIC_COUNTER_H

#include "libcos/stdatomic.h"
#include "assert.h"
#include "libcos/malloc.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct  atomic_counter {
    /// \brief The counter value
    uint32_t count;
} atomic_counter_t;

/// \brief Construct a new atomic_counter and initializes it with the given value.
/// \param startCount The start value for this the counter.
atomic_counter_t* xAtomicCounterCreate(int startCount);

/// \brief Increments the counter.
/// \return The result of the increment.
static inline uint32_t xAtomicCounterIncrement(atomic_counter_t* counter) {
    assert(counter != 0);
    atomic_increment(&counter->count, memory_order_seq_cst);

    return atomic_load(&counter->count, memory_order_seq_cst);
}

/// \brief Decrements the counter.
/// \return The result of the decrement.
static inline uint32_t xAtomicCounterDecrement(atomic_counter_t* counter) {
    assert(counter != 0);
    atomic_decrement(&counter->count, memory_order_seq_cst);

    return atomic_load(&counter->count, memory_order_seq_cst);
} 
/// \brief Reset the counter
static inline void xAtomicCounterReset(atomic_counter_t* counter) {
    assert(counter != 0);
    atomic_store(&counter->count, 0, memory_order_release);
}

/// \brief If the counter zero?
/// \return If true the counter is zero and if false otherwise.
static inline _Bool bAtomicCounterIsZero(atomic_counter_t* counter) {
    assert(counter != 0);
    return (atomic_load(&counter->count, memory_order_seq_cst) == 0 );
}

/// \brief Get the value of the counter.
/// \return The value of the counter.
static inline uint32_t xAtomicCounterValue(atomic_counter_t* counter) {
    assert(counter != 0);

    return atomic_load(&counter->count, memory_order_seq_cst);
}

#ifdef  __cplusplus
}
#endif


#endif