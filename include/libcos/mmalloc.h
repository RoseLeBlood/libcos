#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED

#include "malloc.h"
#include "errno.h"

static __inline__ void* _align_alloc (size_t size, size_t align)
{
	void * _malloc;
	void * _maligned;

	if ((align & (align - 1)) ||  size == 0) return ((void*) 0);
	if (align < 2 * sizeof (void *)) align = 2 * sizeof (void *);

	_malloc = malloc (size + align);
	if (!_malloc) return ((void *) 0);

	_maligned = (void *) (((size_t) _malloc + align) & ~((size_t) (align) - 1));
  
	((void **) _maligned) [-1] = _malloc;

	return _maligned;
}

static __inline__ void _align_free (void * aligned) {
  if (aligned) free (((void **) aligned) [-1]);
}

#endif 