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
#include <ctype.h>
#include <malloc.h>
#include <string.h>

uint32_t allocindex;

extern void* port_malloc(size_t size);
extern void port_free(void* addr);

/* alloc and full with zeros */
void *calloc(size_t num, size_t size)
{
        size_t x;
        char *adr = (char *) port_malloc(size);
        char *j = adr;

        for(x = 0; x < size; x++)
        {
                *j = 0;
                j++;
        }
        return (void *) adr;
}


/* alloc */
void *malloc(size_t size)
{
       allocindex++;

        return (void *) port_malloc(size);
}
void **malloc2d(int row, int col, size_t size)
{
	void **a;
	a=(void **) malloc(row * size);

	for(int i=0;i < row; i++)
	    a[i]=(void *) malloc(col * size);
	return a;
}

/* realloc */
void *realloc(void *adr, size_t size)
{
        void *new = (void *) port_malloc(size);
        memcpy(new, adr, size);
        free(adr);

        return (void *) new;
}


/* free memory */
void free(void *adr)
{
        allocindex--;
        
        port_free(adr);
}
void free2d(void** array, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
   		free(array[i]);
	}
	free(array);
}