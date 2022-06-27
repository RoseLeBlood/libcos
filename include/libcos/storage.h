#ifndef KLIBC_EBOSTORAGE_H
#define KLIBC_EBOSTORAGE_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STOREGET(S)     S.data
#define STOREGETV(S, V)  void* V = S.data

typedef struct storage {
    void* data;
    size_t size;
} storage_t;

int storeit(storage_t* storage, const void* pDate, const size_t size);



#ifdef __cplusplus
}
#endif
#endif