#include "deque.h"
#include "malloc.h"

typedef struct deque {
    node_t *head;  
    node_t *tail;
    size_t maxSize;
    size_t entries; 
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

    _newQueue->head = 0;
    _newQueue->tail = 0;
    _newQueue->entries = 0;
    _newQueue->maxSize = sQueSize;

    return _newQueue;
}

int deque_insert_head(deque_t* q, void* pInsert) {
    if(q == NULL) return 4;

    if( deque_is_full(q) ) return DEQUE_ERROR_ISFULL;

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

    return DEQUE_NO_ERROR;
}

int deque_insert_tail(deque_t* q, void* pInsert) {
    if(q == NULL) return 4;
    
    if( deque_is_full(q) ) return DEQUE_ERROR_ISFULL;

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

    return DEQUE_NO_ERROR;
}

void* deque_remove_head(deque_t* q, void** pValue) {
    if (q == NULL || q->head == NULL) return NULL;

    node_t* oldHead = q->head;
    void* value = oldHead->value;
    
    if (pValue != NULL) *pValue = value;

    q->head = oldHead->next;
    if(q->head) q->head->prev = NULL;

    free(oldHead);

    if(q->head == NULL) q->tail = NULL;

    q->entries--;
    return value;
}

void* deque_remove_tail(deque_t* q, void** pValue) {
    if (q == NULL || q->head == NULL) return NULL;

    node_t* oldTail = q->tail;
    void* value = oldTail->value;

    q->tail = oldTail->prev;

    if (pValue != NULL) *pValue = value;

    if(q->tail) q->tail->next = NULL;

    free(oldTail);

    if(q->tail == NULL) q->head = NULL;

    q->entries--;
    return value;
}