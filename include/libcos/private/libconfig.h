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
#ifndef __KLINCOS_LIBCONFIG_H__
#define __KLINCOS_LIBCONFIG_H__

#define KLIBCOS_TRUE                1
#define KLIBCOS_FALSE               0

#define KLIBCOS_NULTICORE_SYSTEM    KLIBCOS_TRUE
#define KLIBCOS_QUEUE_WITH_LOCK     KLIBCOS_FALSE

#define PRINT_BUF_LEN               12

#define SYS_CLK_MHZ                 (3000)
#define SYS_CLK_KHZ                 (SYS_CLK_MHZ * 1000)
#define SYS_CLK_HZ                  (SYS_CLK_KHZ * 1000)

#define PORT_SYS_NAME                "native"
#define PORT_RELEASE_NAME            ""
#define PORT_CC_VERSION              "1.0"
#define PORT_MASCHINE_NAME          "windows"
#define PORT_COMPILER_NAME          "gcc"
#define PORT_COMPILER_VERSION       "12"

#endif