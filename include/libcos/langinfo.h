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
#ifndef KLIBCOS_LANGINFO_H
#define KLIBCOS_LANGINFO_H

#include <types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NL_SETD 1
#define NL_CAT_LOCALE 1



#define CODESET 14

#define _NL_LOCALE_NAME(cat) (((cat) << 16) | 0xffff)

#define ABDAY_1         0x20000
#define ABDAY_2         0x20001
#define ABDAY_3         0x20002
#define ABDAY_4         0x20003
#define ABDAY_5         0x20004
#define ABDAY_6         0x20005
#define ABDAY_7         0x20006

#define DAY_1           0x20007
#define DAY_2           0x20008
#define DAY_3           0x20009
#define DAY_4           0x2000A
#define DAY_5           0x2000B
#define DAY_6           0x2000C
#define DAY_7           0x2000D

#define ABMON_1         0x2000E
#define ABMON_2         0x2000F
#define ABMON_3         0x20010
#define ABMON_4         0x20011
#define ABMON_5         0x20012
#define ABMON_6         0x20013
#define ABMON_7         0x20014
#define ABMON_8         0x20015
#define ABMON_9         0x20016
#define ABMON_10        0x20017
#define ABMON_11        0x20018
#define ABMON_12        0x20019

#define MON_1           0x2001A
#define MON_2           0x2001B
#define MON_3           0x2001C
#define MON_4           0x2001D
#define MON_5           0x2001E
#define MON_6           0x2001F
#define MON_7           0x20020
#define MON_8           0x20021
#define MON_9           0x20022
#define MON_10          0x20023
#define MON_11          0x20024
#define MON_12          0x20025

#define AM_STR          0x20026
#define PM_STR          0x20027

#define D_T_FMT         0x20028
#define D_FMT           0x20029
#define T_FMT           0x2002A
#define T_FMT_AMPM      0x2002B

#define ERA             0x2002C
#define ERA_D_FMT       0x2002E
#define ALT_DIGITS      0x2002F
#define ERA_D_T_FMT     0x20030
#define ERA_T_FMT       0x20031

#define CRNCYSTR        0x4000F

#define RADIXCHAR       0x10000
#define THOUSEP         0x10001
#define YESEXPR         0x50000
#define NOEXPR          0x50001



char* nl_langinfo(nl_item item);

#ifdef __cplusplus
}
#endif

#endif 