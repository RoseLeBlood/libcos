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
#ifndef KLIBCOS_PRIORITY_DEQUE_H
#define KLIBCOS_PRIORITY_DEQUE_H

#include "node.h"

#define PRIO_DEQUE_ERROR_ISFULL 2
#define PRIO_DEQUE_ERROR_OUTOFMEM 1
#define PRIO_DEQUE_NO_ERROR 0

#if __cplusplus 
extern "C" {
#endif

typedef struct prio_deque prio_deque_t;

deque_t*    prio_deque_create(uint32_t sQueSize);
void        prio_queue_delete(deque_t* q);

int         prio_deque_insert_head(deque_t* q, int32_t prio, void* pInsert); // first
int         prio_deque_insert_tail(deque_t* q, int32_t prio, void* pInsert); // last

void*       prio_deque_remove_head(deque_t* q, void** pValue);
void*       prio_deque_remove_tail(deque_t* q, void** pValue);

size_t      prio_deque_get_nentries(deque_t* q);
size_t      prio_deque_get_size(deque_t* q);
_Bool       prio_deque_is_full(deque_t* q);
_Bool       prio_deque_is_empty(deque_t* q);


#if __cplusplus 
}
#endif

#endif