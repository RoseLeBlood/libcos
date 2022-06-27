#ifndef KLIBC_PAIR_H
#define KLIBC_PAIR_H

#include "storage.h"
#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pair {
    storage_t first;
    storage_t second;
} pair_t;

int pairit(pair_t* pair, const void* first, const size_t sfirst, const void* second, const size_t ssecond);

static inline void* pair_first(pair_t* pair) {
    if(pair == NULL) { errno = EINVAL; return NULL; }
    return STOREGET(pair->first);
}

static inline size_t pair_fsize(pair_t* pair) {
    if(pair == NULL) { errno = EINVAL; return NULL; }
    return pair->first.size;
}

static inline void* pair_second(pair_t* pair) {
    if(pair == NULL) { errno = EINVAL; return NULL; }
    return STOREGET(pair->second);
}

static inline size_t pair_ssize(pair_t* pair) {
    if(pair == NULL) { errno = EINVAL; return NULL; }
    return pair->second.size;
}

#ifdef __cplusplus
}
#endif
#endif