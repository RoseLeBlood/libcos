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
#ifndef KLIBCOS_RNGBUFFER_H
#define KLIBCOS_RNGBUFFER_H

#include "node.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ringbuffer ringbuf_t;

ringbuf_t*  ringbuf_create(size_t size);
int         ringbuf_create_static(ringbuf_t* rngb, uint8_t* buffer, size_t size);

int         ringbuf_enqueue(ringbuf_t* rngb, uint8_t data);
uint8_t     ringbuf_dequeue(ringbuf_t* rngb);

size_t      ringbuf_enqueue_ptr(ringbuf_t* rngb, uint8_t* toWrite, size_t offset, size_t size);
size_t      ringbuf_dequeue_ptr(ringbuf_t* rngb, uint8_t* readPtr, size_t offset, size_t size);

uint8_t     ringbuf_peek(ringbuf_t* rngb);

_Bool       ringbuf_is_full(ringbuf_t* rngb);
_Bool       ringbuf_is_empty(ringbuf_t* rngb);

int32_t     ringbuf_read_pos(ringbuf_t* rngb);
int32_t     ringbuf_write_pos(ringbuf_t* rngb);


#ifdef __cplusplus
}
#endif

#endif 