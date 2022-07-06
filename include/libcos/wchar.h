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
#ifndef KLIBCOS_WSTRING_H
#define KLIBCOS_WSTRING_H

#include "stddef.h"
#include "stdarg.h"
#include "stdio.h"

#if defined(__WINT_TYPE__)
typedef __WINT_TYPE__ wint_t;
#else
typedef unsigned int wint_t;
#endif

typedef const int * wctrans_t;

typedef unsigned long wctype_t;


#ifndef WCHAR_MIN
#define WCHAR_MIN (-2147483647 - 1)
#define WCHAR_MAX (2147483647)
#endif
#ifndef WEOF
#define WEOF 0xffffffffu
#endif

#ifdef __cplusplus
extern "C" 
{
#endif


wchar_t*   	wcsccpy  (wchar_t* s1, const wchar_t* s2);
wchar_t*   	wcscncpy (wchar_t* dst, const wchar_t* src, size_t n);
wchar_t*   	wcsccat  (wchar_t* s1, const wchar_t* s2);
wchar_t*	wcsncat(wchar_t *  s1, const wchar_t *  s2, size_t n);

int 		wcscmp(const wchar_t *s1, const wchar_t *s2);
int  		wcsncmp (const wchar_t* s1, const wchar_t* s2, size_t n);

wchar_t *	wcschr(const wchar_t *s, wchar_t c);
size_t 		wcsspn(const wchar_t *s, const wchar_t *set);
wchar_t *	wcspbrk(const wchar_t *s, const wchar_t *set);
wchar_t *	wcsrchr(const wchar_t *s, wchar_t c);
size_t  	wcscspn  (const wchar_t *s, const wchar_t *set);
wchar_t *	wcsstr(const wchar_t *  s, const wchar_t *  find);
wchar_t*   	wcstok(wchar_t *  s, const wchar_t *  delim,  wchar_t **  last);
size_t  	wcslen  (const wchar_t* s);
size_t 		wcsnlen(const wchar_t *s, size_t maxlen);
wchar_t *	wcsdup (const wchar_t *s);

size_t 		wcslcat(wchar_t *dst, const wchar_t *src, size_t siz);
size_t 		wcslcpy(wchar_t *dst, const wchar_t *src, size_t siz);

wchar_t	*	wmemchr(const wchar_t *s, wchar_t c, size_t n);
int 		wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n);
wchar_t *	wmemcpy(wchar_t *destination, const wchar_t *source, size_t num);
wchar_t *	wmemmove(wchar_t *destination, const wchar_t *source, size_t num);
wchar_t *	wmemset(wchar_t *s, wchar_t c, size_t n);


#ifdef __cplusplus
};
#endif

#endif