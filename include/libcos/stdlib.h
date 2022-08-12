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
#ifndef KLIBC_STDLIB_H
#define KLIBC_STDLIB_H

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "sort.h"

typedef struct  { int quot; int rem; }                          div_t;
typedef struct  { long quot; long rem; }                        ldiv_t;
typedef struct  { long long quot; long long rem; }              lldiv_t;

typedef int (searchfunc_t)(const void*, const void*, void*);

double                                  atof            (const char* nptr);
int                                     atoi            (const char* nptr);

long int                                atol            (const char* nptr);
long long int                           atoll           (const char* nptr);
double                                  strtod  (const char* nptr, char** endptr);
float                                   strtof          (const char* nptr, char** endptr);
long double                             strtold (const char* nptr, char** endptr);
long int                                strtol  (const char* nptr, char** endptr, int base);
long long int                           strtoll (const char* nptr, char** endptr, int base);
unsigned long int                       strtoul (const char* nptr, char** endptr, int base);
unsigned long long int  		        strtoull        (const char* nptr, char** endptr, int base); 
   
int                                     rand  ();
void                                    srand (unsigned int seed);
int										rand_m(int32_t min, int32_t max);
uint8_t*                                rand_chars(uint8_t* buf, size_t size);


void*                                   bsearch_s (const void* key, const void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args);
void*                                   bsearch(const void* key, const void* base, size_t nitems, size_t size, cmpfunc_t compar);
                                        //quick_sort
void                                    qsort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args);
void                                    qsort (void* base, size_t nitems, size_t size, cmpfunc_t compar);
                                        //shell sort
void                                    ssort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args);
void                                    ssort (void* base, size_t nitems, size_t size, cmpfunc_t compar);
                                        //insertion_sort
void                                    isort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args);
void                                    isort (void* base, size_t nitems, size_t size, cmpfunc_t compar);
                                        //heap_sort
void                                    hsort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args);
void                                    hsort (void* base, size_t nitems, size_t size, cmpfunc_t compar);

int                                     abs             (int j);
long int                                labs            (long int j);
long long int                           llabs           (long long int j);
div_t                                   div             (int numer, int denom);
ldiv_t                                  ldiv            (long int numer, long int denom);
lldiv_t                                 lldiv   		(long long int numer, long long int denom);
int                                     mblen   		(const char* s, size_t n);
int                                     mbtowc  		(wchar_t* pwc, const char* s, size_t n);
int                                     wctomb  		(char* s, wchar_t wc);
size_t 							        mbstowcs		(register wchar_t *pwcs, register const char *s, size_t n);
size_t  						        wcstombs		(register char *s, register const wchar_t *pwcs, size_t n);


#ifdef __cplusplus
}
#endif


#endif