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
#ifndef KLIBC_STDIO_H
#define KLIBC_STDIO_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "stddef.h"
#include "stdarg.h"

#define 	EOF   (-1)

char 			*itoa				(int);
char 			*_itoa(char* result, int base, int value);
int 			atoi				(const char *);
int 			printf				(const char *, ...);
int 			scanf				(const char *, ...);
int 			getchar				();
int 			getch				();
char 			*gets				(char *);
char 			*itox				(int);
void 			cls					();
void			gotoxy				(int x, int y);

int             snprintf            (char* s, size_t n, const char* format, ...);
int             sprintf         	(char* s, const char* format, ...);
int             sscanf          	(const char* s, const char* format, ...);
int             vsnprintf           (char* s, size_t n, const char* format, va_list arg);
int             vsprintf            (char* s, const char* format, va_list arg);
int             vsscanf         	(const char* s, const char* format, va_list arg);

char** 			make_args(char *str, unsigned int* size);
#ifdef __cplusplus
};
#endif

#endif