#ifndef KLIBCOS_SORT_H
#define KLIBCOS_SORT_H

#include "ctype.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define COMPARE_TRUE        0
#define COMPARE_FALSE       1

typedef int (*cmpfunc_t) (const int32_t a, const int32_t b, void* args);

inline int compare_less(const int32_t a, const int32_t b, void* args) {
    return (a < b) ? COMPARE_TRUE : COMPARE_FALSE; 
}
inline int compare_graeter(const int32_t a, const int32_t b, void* args) {
    return (a > b) ? COMPARE_TRUE : COMPARE_FALSE; 
}

void quick_sort(void* begin, void* end, cmpfunc_t compar, void* args);
void quick_sort_r(void* begin, void* end);

void shell_sort(void* begin, void* end, cmpfunc_t compar, void* args);
void shell_sort_r(void* begin, void* end);

void insertion_sort(void* begin, void* end, cmpfunc_t compar, void* args) ;
void insertion_sort_r(void* begin, void* end);

void heap_sort(void* begin, void* end, cmpfunc_t compar, void* args) ;
void heap_sort_r(void* begin, void* end);


#ifdef	__cplusplus
}
#endif

#endif