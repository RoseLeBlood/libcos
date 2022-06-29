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
#ifndef KLIBCOS_WCTYPE_H
#define KLIBCOS_WCTYPE_H

#include "wchar.h"
#include "types.h"

typedef const int* wctrans_t;
#ifdef __cplusplus
extern "C" 
{
#endif

int iswalnum(wint_t); //
int iswalpha(wint_t); //
int iswblank(wint_t); //
int iswcntrl(wint_t); //
int iswdigit(wint_t); //
int iswgraph(wint_t); //
int iswlower(wint_t); //
int iswprint(wint_t); //
int iswpunct(wint_t); //
int iswspace(wint_t); //
int iswupper(wint_t); //
int iswxdigit(wint_t); //

wchar_t towlower(wchar_t); //
wchar_t towupper(wchar_t); //

int iswctype(wint_t , wctype_t); //
wctype_t wctype(const char *) ; //

wctrans_t wctrans(const char *); //
wint_t towctrans(wint_t , wctrans_t); //


#ifdef __cplusplus
};
#endif

#endif