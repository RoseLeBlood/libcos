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
#include "priority_deque.h"
#include "private/port.h"

typedef struct prio_deque {
    prio_node_t *head;  
    prio_node_t *tail;
    size_t      maxSize;
    size_t      entries;
#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    lock_t lock;
#endif 
} prio_deque_t;



size_t prio_deque_get_nentries(prio_deque_t* q) {
    if ((q == NULL)) return 0;
    return q->entries;
}

size_t prio_deque_get_size(prio_deque_t* q) {
    if ((q == NULL)) return 0;
    return q->maxSize;
}

_Bool prio_deque_is_full(prio_deque_t* q) {
    if ((q == NULL)) return 0;

    return (q->maxSize == q->entries) ;
}
_Bool prio_deque_is_empty(prio_deque_t* q) {
    return (q->head == NULL) ;
}

prio_deque_t* prio_deque_create(uint32_t sQueSize) {

    prio_deque_t* _newQueue = (prio_deque_t*) malloc (sizeof(prio_deque_t));
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

void prio_queue_delete(deque_t* q) {
    if(q == NULL) return ;

    while(prio_deque_remove_tail(q, NULL) != NULL) { }

    free(q); q = NULL;
}

int prio_deque_insert_head_private(prio_deque_t* q, prio_node_t *_newHead) {
    if(q == NULL) return 4;
    if( prio_deque_is_full(q) ) return PRIO_DEQUE_ERROR_ISFULL;

    if (q->head->priority < _newHead->priority) {

        if (q->head == NULL) {
            q->head = q->tail = _newHead;
            _newHead->next = _newHead->prev = NULL;
        } else {
            q->head->prev = _newHead;
            _newHead->next = q->head;
            _newHead->prev = NULL;
            q->head = _newHead;
        }
        
        return 0;
    } else {
       return prio_deque_insert_head_private(q->head->next, _newHead);
    }
    return 0;
}
int prio_deque_insert_head(prio_deque_t* q, int32_t prio, void* pInsert) {
    if(q == NULL) return 4;

    if( prio_deque_is_full(q) ) return PRIO_DEQUE_ERROR_ISFULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); 
#endif

    prio_node_t *_newHead = (prio_node_t*)malloc(sizeof(prio_node_t));
    if (_newHead == NULL) {
        #if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
            section_leave(q->lock);
        #endif
        
        return PRIO_DEQUE_ERROR_OUTOFMEM;
    }

    _newHead->value = pInsert;
    _newHead->priority = p;

    if(prio_deque_insert_head_private(q, prio, _newHead) == 0) {
        q->entries++;

    #if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
        section_leave(q->lock);
    #endif
        return PRIO_DEQUE_NO_ERROR;
    }
    
#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_leave(q->lock);
#endif
    return PRIO_DEQUE_ERROR_ISFULL;
}


int prio_deque_insert_tail_private(prio_deque_t* q, prio_node_t *_newTail) {
    if(q == NULL) return 4;
    if( prio_deque_is_full(q) ) return PRIO_DEQUE_ERROR_ISFULL;

    if (q->tail->priority > _newHead->priority) {

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
        
        return 0;
    } else {
       return prio_deque_insert_tail_private(q->tail->prev, _newTail);
    }
    return 0;
}
int deque_insert_tail(deque_t* q, void* pInsert) {
    if(q == NULL) return 4;
    
    if( deque_is_full(q) ) return PRIO_DEQUE_ERROR_ISFULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); 
#endif

    node_t *_newTail = (node_t*)malloc(sizeof(node_t*));
    if (_newTail == NULL) {

    #if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
        section_leave(q->lock);
    #endif
        return PRIO_DEQUE_ERROR_OUTOFMEM;
    } 

    _newTail->value = pInsert;
    _newTail->priority = p;

    if(prio_deque_insert_tail_private(q, _newTail) == 0) {
        q->entries++;
    #if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
        section_leave(q->lock);
    #endif
        return PRIO_DEQUE_NO_ERROR;
    }
    
#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_leave(q->lock);
#endif
    return PRIO_DEQUE_ERROR_ISFULL;
}


void* prio_deque_remove_head(prio_deque_t* q, void** pValue) {
    if (q == NULL || q->head == NULL) return NULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); 
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
    section_leave(q->lock);
#endif
    return value;
}

void* prio_deque_remove_tail(prio_deque_t* q, void** pValue) {
    if (q == NULL || q->head == NULL) return NULL;

#if KLIBCOS_QUEUE_WITH_LOCK == KLIBCOS_TRUE
    section_enter(q->lock); 
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
    section_leave(q->lock);
#endif
    return value;
}