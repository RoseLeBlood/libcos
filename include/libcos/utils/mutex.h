#ifndef KLIBCOS_MUTEX_H
#define KLIBCOS_MUTEX_H

#include  <types.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct mutex_type  mutex_t;

mutex_t xMutexCreate();

int xMutexkGive(atomic_spinlock_t* lock);
int xMutexTake(atomic_spinlock_t* lock);
int xMutexTryTake(atomic_spinlock_t* lock);
int xMutexIsLoked(atomic_spinlock_t*  lock);
int xMutexkDestroy(atomic_spinlock_t*  lock);

#ifdef  __cplusplus
}
#endif

#endif