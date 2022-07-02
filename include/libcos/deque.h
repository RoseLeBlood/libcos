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
#ifndef KLIBCOS_DEQUE_H
#define KLIBCOS_DEQUE_H

#include "node.h"

#define DEQUE_ERROR_ISFULL 2
#define DEQUE_ERROR_OUTOFMEM 1
#define DEQUE_NO_ERROR 0

#if __cplusplus 
extern "C" {
#endif

typedef struct deque deque_t;

/**
 * @brief Create a deque
 * 
 * @param sQueSize maximal entries of the deque
 * @return deque_t* Handler of the created deque, NULL on error
 */
deque_t*    deque_create(uint32_t sQueSize);
/**
 * @brief Destroy the deque
 * 
 * @param q Handler of the deque
 */
void        queue_delete(deque_t* q);

/**
 * @brief Insert a new item to the head (first)
 * 
 * @param q Deque handler
 * @param pInsert The new element to add
 * @return int If 0 then okay , if >0 on error 
 */
int         deque_insert_head(deque_t* q, void* pInsert); 
/**
 * @brief Insert a new item to the tail (first)
 * 
 * @param q  Deque handler
 * @param pInsert The new element to add
 * @return int If 0 then okay , if >0 on error  
 */
int         deque_insert_tail(deque_t* q, void* pInsert); // last

/**
 * @brief Remove an element from the head - start
 * 
 * @param q Deque handler
 * @param pValue When not NULL , return value from removed element
 * @return void* value from removed element
 */
void*       deque_remove_head(deque_t* q, void** pValue) ;
/**
 * @brief Remove an element from the tail - end
 * 
 * @param q Deque handler
 * @param pValue When not NULL , return value from removed element
 * @return void* value from removed element
 */
void*       deque_remove_tail(deque_t* q, void** pValue);

/**
 * @brief Get the number of elements in the deque
 * 
 * @param q Deque handler
 * @return size_t Number of elements in the deque
 */
size_t      deque_get_nentries(deque_t* q);
/**
 * @brief Get the number of maxium elements they can handle in the deque
 * 
 * @param q Deque handler
 * @return size_t The number of maxium elements they can handle in the deque
 */
size_t      deque_get_size(deque_t* q);
/**
 * @brief Is the deque full?
 * 
 * @param q Deque handler
 * @return _Bool when true then is the deque full and when not then not
 */
_Bool       deque_is_full(deque_t* q);
/**
 * @brief Is the deque empty?
 * 
 * @param q Deque handler
 * @return _Bool when true then is the deque empty and when not then not
 */
_Bool       deque_is_empty(deque_t* q);

#if __cplusplus
}
#endif

#endif