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
#ifndef KLIBCOS_LIMITS_H
#define KLIBCOS_LIMITS_H

#include "_sizes.h"

#define CHAR_BIT                __CHAR_BIT__

#ifndef MB_LEN_MAX
#define MB_LEN_MAX 1
#endif

#ifndef __LLONG_MAX__
#define __LLONG_MAX__       9223372036854775807
#endif

#ifndef __LLONG_MIN__
#define __LLONG_MIN__       -9223372036854775807
#endif

#define SCHAR_MIN               (-__SCHAR_MAX__ - 1)
#define SCHAR_MAX               __SCHAR_MAX__
#define UCHAR_MAX               ((1 << CHAR_BIT) - 1)

#define SHRT_MIN                (-__SHRT_MAX__ - 1)
#define SHRT_MAX                __SHRT_MAX__
#define USHRT_MAX               ((1 << (CHAR_BIT * __SIZEOF_SHORT__)) - 1)

#define INT_MIN                 (-__INT_MAX__ - 1)
#define INT_MAX                 __INT_MAX__
#define UINT_MAX                ((1 << (CHAR_BIT * __SIZEOF_INT__)) - 1)

#define LONG_MIN                (-__LONG_MAX__ - 1)
#define LONG_MAX                __LONG_MAX__
#define ULONG_MAX               ((1 << (CHAR_BIT * __SIZEOF_LONG__)) - 1)

#define LLONG_MIN               __LLONG_MIN__
#define LLONG_MAX               __LLONG_MAX__
#define ULLONG_MAX              ((1 << (CHAR_BIT * __SIZEOF_LONG_LONG__)) - 1)

#define INT8_MAX (127)
#define INT16_MAX (32767)
#define INT32_MAX (2147483647)
#define INT64_MAX (9223372036854775807ll)

#define INT8_MIN (-1 - INT8_MAX)
#define INT16_MIN (-1 - INT16_MAX)
#define INT32_MIN (-1 - INT32_MAX)
#define INT64_MIN (-1 - INT64_MAX)

#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST8_MIN INT8_MIN
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MAX INT64_MAX
#define INT_LEAST64_MIN INT64_MIN

#define UINT8_MAX 0xff
#define UINT16_MAX 0xffff
#define UINT32_MAX 0xfffffffful
#define UINT64_MAX 0xffffffffffffffffull

#define UINT_LEAST8_MAX UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#if __WORDSIZE == 64
#define INTPTR_MIN INT64_MIN
#define INTPTR_MAX INT64_MAX
#define UINTPTR_MAX UINT64_MAX
#else
#define INTPTR_MIN INT32_MIN
#define INTPTR_MAX INT32_MAX
#define UINTPTR_MAX UINT32_MAX
#endif

#define SIZE_MAX UINTPTR_MAX
#define PTRDIFF_MIN INTPTR_MIN
#define PTRDIFF_MAX INTPTR_MAX

#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX

#define INT_FAST8_MIN INT8_MIN
#define INT_FAST8_MAX INT8_MAX
#define INT_FAST64_MIN INT64_MIN
#define INT_FAST64_MAX INT64_MAX

#define UINT_FAST8_MAX UINT8_MAX
#define UINT_FAST64_MAX UINT64_MAX

#define INT_FAST16_MIN INTPTR_MIN
#define INT_FAST16_MAX INTPTR_MAX
#define UINT_FAST16_MAX UINTPTR_MAX

#define INT_FAST32_MIN INTPTR_MIN
#define INT_FAST32_MAX INTPTR_MAX
#define UINT_FAST32_MAX UINTPTR_MAX

#define SIG_ATOMIC_MAX ((int)(~0u << sizeof(int)*8-1))
#define SIG_ATOMIC_MIN ((int)((~0u << sizeof(int)*8-1)-1))

#ifndef WCHAR_MIN
#define WCHAR_MIN ((int)(~0u << sizeof(int)*8-1))
#define WCHAR_MAX ((int)((~0u << sizeof(int)*8-1)-1))
#endif

#define WINT_MIN 0
#define WINT_MAX (~(wint_t)0)

#define NLZ(X) ( (sizeof(X) * CHAR_BIT - __builtin_clzll(X) ) - 1)

#endif