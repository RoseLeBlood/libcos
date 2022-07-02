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
#ifndef KLIBCOS_QUEUE_H
#define KLIBCOS_QUEUE_H

#include "deque.h"

typedef deque_t queue_t;

#define queue_create(size)      deque_create(size);
#define queue_enqueue(q, value) queue_insert_tail(q, value)
#define queue_dequeue(q, v)     queue_remove_head(q, v)

#define queue_get_nentries(q)   deque_get_nentries(q)
#define queue_get_size(q)       deque_get_size(q)
#define queue_is_full(q)        deque_is_full(q)
#define queue_is_empty(q)       deque_is_empty(q)

#endif