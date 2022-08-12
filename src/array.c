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
#include "array.h"
#include "errno.h"
#include "malloc.h"
#include "stdlib.h"
#include "limits.h"
#include "string.h"

typedef struct array_item {
    void*   data;
    size_t  item_size;
}array_item_t;

typedef struct array_t {
    array_item_t* pdata;
    size_t        size;
    size_t        max_size;
} array_t;


int array_internal_set_size(array_t* a, size_t new_size) {
    if( new_size < 0 || ( new_size > INT_MAX / sizeof( void* ) ) ) {
        return EINVAL;
    }
    if( new_size == 0 ) {
        if( a->pdata ) {
            free( a->pdata );
            a->pdata = NULL;
        }
        a->max_size = 0;
        a->size = 0;
    } else if( a->pdata == NULL || new_size > a->max_size  ) {
        size_t nGrowBy = ( a->max_size == 0 ) ? 16 : a->max_size;

        if( ( UINT )a->max_size + ( UINT )nGrowBy > ( UINT )INT_MAX )
            nGrowBy = INT_MAX - a->max_size;

        new_size = MAX( new_size, a->max_size + nGrowBy );

        if( sizeof( void* ) > UINT_MAX / ( UINT )new_size )
            return EINVAL;

        array_item_t* pDataNew = ( array_item_t* )realloc( a->pdata, new_size * sizeof( array_item_t ) );
        if( pDataNew == NULL )
            return ENOMEM;

        a->pdata = pDataNew;
        a->max_size = new_size;
    }
    return 0;
}

int array_create(array_t* a, size_t size) {
    if(!a) return -1;

    a->max_size = 0;
    a->size = 0;


    return array_internal_set_size(a, size);
}
int array_set_size(array_t* a, size_t new_size) {
    if(!a) return -1;

    int nOldSize = a->size;

    if( nOldSize > new_size ) {
        if( a->pdata ) {
            for( int i = new_size; i < nOldSize; ++i ) {
                if(a->pdata[i].data) free(a->pdata[i].data);
            }
        }
    }
    return array_internal_set_size( a, new_size );
}
int array_add(array_t* a, void* pdata, size_t size) {
    if(!a) return -1;

    int _ret = array_internal_set_size( a, a->size + 1 );
    if(_ret != 0) return _ret;

    size_t nsize = MAX(size, sizeof(pdata));

    if(a->pdata[a->size].data  != NULL) { 
        free(a->pdata[a->size].data);
    }
    a->pdata[a->size].data = malloc(MAX(size, nsize));
    if(a->pdata[a->size].data == NULL)
        return ENOMEM;

    memcpy(a->pdata[a->size].data, pdata, size);
    a->pdata[a->size].item_size = nsize;
    ++(a->size);

    return 0;
}

int array_set_at(array_t* a, size_t index, void* pdata, size_t size) {
    if(!a) return -1;

    if( index < 0 || (index > a->max_size ) ) {
		return EINVAL;
    }
    size_t nsize = MAX(size, sizeof(pdata));

    if(a->pdata[a->size].data  == NULL) {
        a->pdata[a->size].data = malloc(nsize);
        if(a->pdata[a->size].data == NULL)
            return ENOMEM;
    }

    memcpy(a->pdata[a->size].data, pdata, size);
    a->pdata[a->size].item_size = nsize;
    
    return 0;
}

size_t array_index_of_ex(array_t* a, const void* data, size_t istart, size_t num_elements) {
    if( istart < 0 || istart >= a->size || num_elements < 0 || istart + num_elements > a->size )
		 return -1;

    // Search
    for( int i = istart; i < ( istart + num_elements ); i++ ) {
        if( !memcmp(a->pdata[i].data, data, a->pdata[i].item_size))
                return i;
    }
    // Not found
    return -1;
}
size_t array_index_of(array_t* a, const void* data) {
    return array_index_of_ex(a, data, 0, a->size);
}

size_t array_last_index_of_ex(array_t* a, const void* data, size_t iend, size_t num_elements) {
    if( iend < 0 || iend >= a->size || num_elements < 0 || iend - num_elements < 0 ) {
        return -1;
    }

		// Search
    for( int i = iend; i > ( iend - num_elements ); i-- ) {
        if( !memcmp(a->pdata[i].data, data, a->pdata[i].item_size))
            return i;
    }

    // Not found
    return -1;
}
size_t array_last_index_of(array_t* a, const void* data) {
     return array_last_index_of_ex(a, data, a->size-1, a->size);
}

int array_remove(array_t* a, size_t index) {
    if( index < 0 || index >= a->size ) {
        return EINVAL;
    }

    if(a->pdata[index].data) {
        free(a->pdata[index].data);
        a->pdata[index].data = NULL;
        a->pdata[index].item_size = 0;
    }
    memmove(&a->pdata[index], &a->pdata[index+1], sizeof( void* ) * ( a->size - ( (index) + 1 ) ) );

}
size_t array_nelements(array_t* a) {
    return a->size;
}