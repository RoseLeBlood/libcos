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