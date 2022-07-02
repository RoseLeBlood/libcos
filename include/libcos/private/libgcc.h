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
#ifndef _LIBGCC_H
#define _LIBGCC_H

#include "../stdint.h"
#include "../stddef.h"

#define __libgcc

extern __libgcc uint64_t __udivmoddi4 ( uint64_t num, uint64_t den, uint64_t *rem );
extern __libgcc uint64_t __udivdi3  (uint64_t num, uint64_t den );
extern __libgcc uint64_t __umoddi3 ( uint64_t num, uint64_t den );
extern __libgcc int64_t __divdi3 ( int64_t num, int64_t den );
extern __libgcc int64_t __moddi3 ( int64_t num, int64_t den );

#endif /* _LIBGCC_H */