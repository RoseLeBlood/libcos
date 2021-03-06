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


_Bool is_sorted(void* begin, void* end);

#ifdef	__cplusplus
}
#endif

#endif