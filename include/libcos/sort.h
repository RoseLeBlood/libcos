#ifndef KLIBCOS_SORT_H
#define KLIBCOS_SORT_H

#include "ctype.h"
#include "stddef.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define COMPARE_LESS        -1
#define COMPARE_GRATER       1
#define COMPARE_EQUIVALENT   0

typedef int (*cmpfunc_t) (const void*, const void*, void*);

static inline int compare_less(const void* pa, const void* pb, void* args) {
    if( PTV(int32_t, pa) == PTV(int32_t, pb) ) return COMPARE_EQUIVALENT;
    return ( PTV(int32_t, pa) < PTV(int32_t, pb) ) ? COMPARE_LESS : COMPARE_GRATER; 
}
static inline int compare_graeter(const void* pa, const void* pb, void* args) {
    if( PTV(int32_t, pa) == PTV(int32_t, pb) ) return COMPARE_EQUIVALENT;
    return ( PTV(int32_t, pa) > PTV(int32_t, pb) ) ? COMPARE_GRATER : COMPARE_LESS; 
}

static inline int compare_sub(const void* pa, const void* pb, void* args) {
    if( PTV(int32_t, pa) == PTV(int32_t, pb) ) return COMPARE_EQUIVALENT;
    return ( PTV(int32_t, pa) - PTV(int32_t, pb) ); 
}
static inline int compare_add(const void* pa, const void* pb, void* args) {
    if( PTV(int32_t, pa) == PTV(int32_t, pb) ) return COMPARE_EQUIVALENT;
    return (PTV(int32_t, pa) + PTV(int32_t, pb) ); 
}

void quick_sort_s(void* begin, void* end, cmpfunc_t compar, void* args);
void quick_sort(void* begin, void* end);

void shell_sort_s(void* begin, void* end, cmpfunc_t compar, void* args);
void shell_sort(void* begin, void* end);

void insertion_sort_s(void* begin, void* end, cmpfunc_t compar, void* args) ;
void insertion_sort(void* begin, void* end);

void heap_sort_s(void* begin, void* end, cmpfunc_t compar, void* args) ;
void heap_sort(void* begin, void* end);


#ifdef	__cplusplus
}
#endif

#endif