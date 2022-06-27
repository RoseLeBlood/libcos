#ifndef STDLIB_H
#define STDLIB_H



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
int										rand_m(unsigned int min, unsigned int max);


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