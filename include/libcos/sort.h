#ifndef KLIBCOS_SORT_H
#define KLIBCOS_SORT_H

#include "stdlib.h"
#include "ctype.h"

#ifdef	__cplusplus
extern "C" {
#endif

void quick_sort(void* begin, void* end, compar_t compar, void* args);
void quick_sort_r(void* begin, void* end, compar_t compar);

void shell_sort(void* begin, void* end, compar_t compar, void* args);
void shell_sort_r(void* begin, void* end, compar_t compar);

void insertion_sort(void* begin, void* end, compar_t compar, void* args) ;
void insertion_sort_r(void* begin, void* end, compar_t compar);

void heap_sort(void* begin, void* end, compar_t compar, void* args) ;
void heap_sort_r(void* begin, void* end, compar_t compar);

#ifdef	__cplusplus
}
#endif

#endif