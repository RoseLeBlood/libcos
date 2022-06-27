#include "storage.h"
#include "errno.h"
#include "string.h"

int storeit(storage_t* storage, const void* pDate, const size_t size) {
    if(storage == NULL) { errno = EINVAL; return -1; }

    storage->data = malloc(size);
    if(storage->data == NULL) { errno = ENOMEM; return -2; }

    memcpy(storage->data, pDate, size);
    storage->size = size;

    return 0;
}