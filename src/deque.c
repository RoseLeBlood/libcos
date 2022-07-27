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
#include "deque.h"
#include "malloc.h"
#include "lock.h"
#include "private/port.h"

typedef struct deque {
    node_t *head;  
    node_t *tail;
    size_t maxSize;
    size_t entries; 
#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    lock_t lock;
#endif
} deque_t;

size_t deque_get_nentries(deque_t* q) {
    if ((q == NULL)) return 0;
    return q->entries;
}

size_t deque_get_size(deque_t* q) {
    if ((q == NULL)) return 0;
    return q->maxSize;
}

_Bool deque_is_full(deque_t* q) {
    if ((q == NULL)) return 0;

    return (q->maxSize == q->entries) ;
}
_Bool deque_is_empty(deque_t* q) {
    return (q->head == NULL) ;
}

deque_t* deque_create(uint32_t sQueSize) {
    
    deque_t* _newQueue = (deque_t*) malloc (sizeof(deque_t));
    if (_newQueue == NULL)  return NULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_create(_newQueue->lock);
    section_enter(_newQueue->lock); {
#endif
    _newQueue->head = 0;
    _newQueue->tail = 0;
    _newQueue->entries = 0;
    _newQueue->maxSize = sQueSize;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    }
    section_leave(_newQueue->lock);
#endif
    return _newQueue;
}
void queue_delete(deque_t* q) {
    if(q == NULL) return ;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); {
#endif
    free(q); q = NULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    }
    section_leave(q->lock);
#endif
}

int deque_insert_head(deque_t* q, void* pInsert) {
    if(q == NULL) return 4;
    if( deque_is_full(q) ) return DEQUE_ERROR_ISFULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); {
#endif

    node_t *_newHead = (node_t*)malloc(sizeof(node_t*));
    if (_newHead == NULL)  return DEQUE_ERROR_OUTOFMEM;

    _newHead->value = pInsert;
    

    if (q->head == NULL) {
        q->head = q->tail = _newHead;
        _newHead->next = _newHead->prev = NULL;
    }
    else {
        q->head->prev = _newHead;
        _newHead->next = q->head;
        _newHead->prev = NULL;
        q->head = _newHead;
    }

    q->entries++;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    }
    section_leave(q->lock);
#endif

    return DEQUE_NO_ERROR;
}

int deque_insert_tail(deque_t* q, void* pInsert) {
    if(q == NULL) return 4;
    
    if( deque_is_full(q) ) return DEQUE_ERROR_ISFULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); {
#endif
    node_t *_newTail = (node_t*)malloc(sizeof(node_t*));
    if (_newTail == NULL)  return DEQUE_ERROR_OUTOFMEM;

    _newTail->value = pInsert;

    if (q->head == NULL) {
        q->head = q->tail = _newTail;
        _newTail->next = _newTail->prev = NULL;
    }
    else {
        q->tail->next = _newTail;
        _newTail->next = NULL;
        _newTail->prev = q->tail;
        q->tail = _newTail;
    }
    q->entries++;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    }
    section_leave(q->lock);
#endif

    return DEQUE_NO_ERROR;
}

void* deque_remove_head(deque_t* q, void** pValue) {
    if (q == NULL || q->head == NULL) return NULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); {
#endif
    node_t* oldHead = q->head;
    void* value = oldHead->value;
    

    if (pValue != NULL) *pValue = value;

    q->head = oldHead->next;
    if(q->head) q->head->prev = NULL;

    free(oldHead);

    if(q->head == NULL) q->tail = NULL;

    q->entries--;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    }
    section_leave(q->lock);
#endif

    return value;
}

void* deque_remove_tail(deque_t* q, void** pValue) {
    if (q == NULL || q->head == NULL) return NULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); {
#endif
    node_t* oldTail = q->tail;
    void* value = oldTail->value;

    q->tail = oldTail->prev;

    if (pValue != NULL) *pValue = value;

    if(q->tail) q->tail->next = NULL;

    free(oldTail);

    if(q->tail == NULL) q->head = NULL;

    q->entries--;
#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    }
    section_leave(q->lock);
#endif

    return value;
}