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
#ifndef KLIBCOS_TYPES_H
#define KLIBCOS_TYPES_H

#include "stddef.h"
#include "stdbool.h"
#include "stdint.h"
#include "endian.h"
#include "limits.h"

#ifdef __cplusplus
extern "C" {
#endif



#define HIGHBYTE(w) (BYTE)(((w) >> 8) & 0xFF) //Das oberer BYTE eines WORDs
#define  LOWBYTE(w) (BYTE)((w) & 0xFF)        //Das untere BYTE eines WORDs

#define HIGHWORD(d) (WORD)(((d) >> 16) & 0xFFFF) //Das oberer WORD eines DWORDs
#define  LOWWORD(d) (WORD)((d) & 0xFFFF)        //Das untere WORD eines DWORDs
  
typedef unsigned int        ino_t;
typedef unsigned int        dev_t;
typedef unsigned int        uid_t;
typedef unsigned int        gid_t;
typedef unsigned int        off_t;

typedef int                 nl_item;
typedef void*               nl_catd;

typedef unsigned int        mode_t;
typedef int                 ssize_t;

typedef int		            suseconds_t;
typedef long int            clock_t;
typedef long int            time_t;
typedef unsigned int        useconds_t;



typedef unsigned long       DWORD;
typedef unsigned short      WORD;
typedef unsigned char 	    BYTE;

typedef signed char         CHAR;  //  8-1 Bit
typedef signed short        SHORT; // 16-1 Bit
typedef signed long         INT;   // 32-1 Bit

typedef unsigned char       UCHAR;  //  8 Bit
typedef unsigned short      USHORT; // 16 Bit
typedef unsigned long       UINT;   // 32 Bit

typedef const char*         string_t;
#ifdef __cplusplus
}
#endif

#endif