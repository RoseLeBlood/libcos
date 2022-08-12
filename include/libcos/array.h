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
#ifndef __KLIBCOS_ARRAY_H__
#define __KLIBCOS_ARRAY_H__

#include <stddef.h>
#include "types.h"
#include "assert.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct array_t array_t;

int array_create(array_t* a, size_t size);
int array_add(array_t* a, void* pdata, size_t size);
int array_set_at(array_t* a, size_t index, void* pdata, size_t size);
int array_remove(array_t* a, size_t index);

size_t array_index_of_ex(array_t* a, const void* data, size_t istart, size_t num_elements);
size_t array_index_of(array_t* a, const void* data);

size_t array_last_index_of_ex(array_t* a, const void* data, size_t iend, size_t num_elements);
size_t array_last_index_of(array_t* a, const void* data);

int array_set_size(array_t* a, size_t new_size);

size_t array_nelements(array_t* a);

#ifdef	__cplusplus
}
#endif

#endif