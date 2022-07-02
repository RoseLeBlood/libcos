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