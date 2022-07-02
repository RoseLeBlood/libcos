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
#ifndef KLIBCOS_STACK_H
#define KLIBCOS_STACK_H

#include "deque.h"
#include "priority_deque.h"

typedef deque_t stack_t;

#define stack_create(size)      deque_create(size);

#define stack_push(q, v)        queue_insert_tail(q, v)
#define stack_pop(q, v)         deque_remove_tail(q, v)

#define stack_get_nentries(q)   deque_get_nentries(q)
#define stack_get_size(q)       deque_get_size(q)
#define stack_is_full(q)        deque_is_full(q)
#define stack_is_empty(q)       deque_is_empty(q)

typedef prio_deque_t    prio_stack_t;

#define prio_stack_create(size)      prio_deque_create(size);

#define prio_stack_push(q,p, v)      prio_queue_insert_tail(q,p,v)
#define prio_stack_pop(q, v)         prio_deque_remove_tail(q, v)

#define prio_stack_get_nentries(q)   prio_deque_get_nentries(q)
#define prio_stack_get_size(q)       prio_deque_get_size(q)
#define prio_stack_is_full(q)        prio_deque_is_full(q)
#define prio_stack_is_empty(q)       prio_deque_is_empty(q)

#endif