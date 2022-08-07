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
#ifndef KLIBCOS_LISTEASY_H
#define KLIBCOS_LISTEASY_H

#include "node.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct list_t list_t;

typedef int (* list_callback)(node_t*);

void        list_create(list_t* list);
node_t*     list_add(list_t* list, void* value, size_t size);
int         list_find(list_t* list, void* value, node_t** pOut);
int         list_delete_entry(list_t* list, node_t* entry);
void        list_travers(list_t* list, list_callback callback);
void*       list_get(node_t* entry);
void        list_clear(list_t* list);

node_t*     list_get_head(list_t* list);
node_t*     list_get_end(list_t* list);
size_t      list_get_size(list_t* list);

#ifdef __cplusplus
}
#endif

#endif