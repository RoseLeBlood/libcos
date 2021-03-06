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
#ifndef KLIBCOS_STRING_H
#define KLIBCOS_STRING_H

#include <stddef.h>
#include <stdint.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C" 
{
#endif



#ifndef ZeroMemory
#define ZeroMemory(d, n) memset(d,0,n)
#endif

#ifndef FillMemory
#define FillMemory(d, c, n)	memset(d,c,n)
#endif

#define memlen(type, data) sizeof( data ) / sizeof( type )

void*   memcpy  (void* s1, const void* s2, size_t n);
void*	memcpyn (uint8_t* s1, unsigned int pos1, const uint8_t* s2, unsigned int pos2, size_t n);

void*   memmove (void* s1, const void* s2, size_t n);
char*   strcpy  (char* s1, const char* s2);
char*   strncpy (char* s1, const char* s2, size_t n);
char*   strcat  (char* s1, const char* s2);
char*   strncat (char* s1, const char* s2, size_t n);
int     memcmp  (const void* s1, const void* s2, size_t n)              __attribute__((pure));
int     strcmp  (const char* s1, const char* s2)                                __attribute__((pure));
int     strncmp (const char* s1, const char* s2, size_t n)              __attribute__((pure));
void*   memchr  (const void* s, int c, size_t n);
char*   strchr  (const char* s, int c);
size_t  strcspn (const char* s1, const char* s2);
char*   strpbrk (const char* s1, const char* s2);
char*   strrchr (const char* s, int c);
size_t  strspn  (const char* s1, const char* s2);
char*   strstr          (const char* s1, const char* s2);
char*   strtok  (char* s1, const char* s2);
void*   memset  (void* s, int c, size_t n);
size_t  strlen          (const char* s)                                                 __attribute__((pure));


void * memclr(void * mem, size_t count);

char *strdup (const char *s);

/*#define memcpy(d,s,n)                           __builtin_memcpy(d,s,n)
#define strcpy(d,s)                             __builtin_strcpy(d,s)
#define strncpy(d,s,n)                          __builtin_strncpy(d,s,n);
#define strcat(d,s)                             __builtin_strcat(d,s)
#define strncat(d,s,n)                          __builtin_strncat(d,s,n)
#define memcmp(a,b,n)                           __builtin_memcmp(a,b,n)
#define strcmp(a,b)                             __builtin_strcmp(a,b)
#define strncmp(a,b,n)                          __builtin_strncmp(a,b,n)
#define memchr(s,c,n)                           __builtin_memchr(s,c,n)
#define strchr(s,c)                             __builtin_strchr(s,c)
#define strcspn(a,b)                            __builtin_strcspn(a,b)
#define strpbrk(a,b)                            __builtin_strpbrk(a,b)
#define strrchr(s,c)                            __builtin_strrchr(s,c)
#define strspn(a,b)                             __builtin_strspn(a,b)
#define strstr(a,b)                             __builtin_strstr(a,b)
#define memset(s,c,n)                           __builtin_memset(s,c,n)
#define strlen(s)                               __builtin_strlen(s)
#define strdup(s)                               __builtin_strdup(s)
#define strtol(s,e,b)							__builtin_strtol(s,e,b)
#define memclr(m, c)							__builtin_memclr(m,c)*/

#ifdef __cplusplus
};
#endif


#endif