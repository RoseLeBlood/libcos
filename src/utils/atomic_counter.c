#include "libcos/utils/atomic_counter.h"



atomic_counter_t* xAtomicCounterCreate(int startCount) {
    atomic_counter_t* _newCounter = malloc(sizeof(atomic_counter_t));
    assert(_newCounter != 0);

    atomic_store(&_newCounter->count, startCount, memory_order_seq_cst);

    return _newCounter;
}