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
#include "ringbuffer.h"
#include "malloc.h"

typedef struct ringbuffer {
    uint8_t* buffer;
    int head; 
    int tail; 

    size_t size;
} ringbuf_t;

int32_t     ringbuf_read_pos(ringbuf_t* rngb) {
    if(rngb == NULL) return -1;

    return rngb->tail;
}
int32_t     ringbuf_write_pos(ringbuf_t* rngb) {
    if(rngb == NULL) return -1;

    return rngb->head;
}
_Bool ringbuf_is_full(ringbuf_t* rngb) {
    if(rngb == NULL) return false;

     return ((rngb->head == 0 && rngb->tail == rngb->size-1) ||
             (rngb->tail == (rngb->head-1)%(rngb->size-1))) ;
}
_Bool ringbuf_is_empty(ringbuf_t* rngb) {
    if(rngb == NULL) return false;

    return (rngb->head == -1);
}

ringbuf_t* ringbuf_create(size_t size) {
    ringbuf_t* _newBuffer = (ringbuf_t*) malloc(sizeof(ringbuf_t));
    if(_newBuffer == NULL) return NULL;

    _newBuffer->buffer = malloc(sizeof(uint8_t) * size);
    if(_newBuffer == NULL) return NULL;

    _newBuffer->size = size;
    _newBuffer->head = _newBuffer->tail = -1;

    return _newBuffer;
}
int ringbuf_create_static(ringbuf_t* rngb, uint8_t* buffer, size_t size) {
    if(rngb == NULL || buffer == NULL) return -1;
    if(size == 0) return -1;

    rngb->buffer = buffer;
    rngb->size = size;
    rngb->head = rngb->tail = -1;

    return 0;
}

int ringbuf_enqueue(ringbuf_t* rngb, uint8_t data) {
    if(rngb == NULL) return 1;

    if(ringbuf_is_full(rngb)) return 2;

    if (rngb->head == -1) {
        rngb->head = rngb->tail = 0;
        rngb->buffer[rngb->tail] = data;
    }  else if (rngb->tail  == rngb->size-1 && rngb->head != 0) {
        rngb->tail = 0;
        rngb->buffer[rngb->tail] = data;
    } else  {
        rngb->tail++;
        rngb->buffer[rngb->tail] = data;
    }
    return 0;
}

uint8_t     ringbuf_peek(ringbuf_t* rngb) {
    if(ringbuf_is_empty(rngb)) return 0;

    return rngb->buffer[rngb->head];
}

uint8_t ringbuf_dequeue(ringbuf_t* rngb) {
    if(ringbuf_is_empty(rngb)) return 0;

    uint8_t _ret = rngb->buffer[rngb->head];

    rngb->buffer[rngb->head] = -1;

    if (rngb->head == rngb->tail)   {
        rngb->head = -1;
        rngb->tail = -1;
    } else if (rngb->head == rngb->size-1)
        rngb->head = 0;
    else
        rngb->head++;
 
    return _ret;
}

size_t ringbuf_dequeue_ptr(ringbuf_t* rngb, uint8_t* readPtr, size_t offset, size_t size) {
    if(ringbuf_is_empty(rngb)) return 0;

    size_t _readed = 0;

    for(_readed = 0; _readed < size; _readed++) { 
        if(ringbuf_is_empty(rngb)) break; 
        readPtr[_readed] = ringbuf_dequeue(rngb); 
    }

    return _readed;
}

size_t      ringbuf_enqueue_ptr(ringbuf_t* rngb, uint8_t* toWrite, size_t offset, size_t size) {
    size_t _written = 0;

    for(_written = 0; _written < (size - offset); _written++) {
        if(ringbuf_enqueue(rngb, toWrite[_written + offset]) != 0)
            break;
    }
    return _written;
}