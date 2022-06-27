#include <stdlib.h>
#include <ctype.h>

void* bsearch_s (const void* key, const void* base, size_t nmemb, size_t size, cmpfunc_t compar, void* args) {
    const char* ptr = base;
    size_t lim;
    int cmp;
    const void* p;
    void* result =  NULL;

	for(lim = nmemb; lim != 0; lim >>= 1) {
		p = ptr + (lim >> 1) * size;
		cmp = (*compar)( key, p, args);
		
		if(cmp == COMPARE_LESS) {
			result = ((void*)(uintptr_t)p);
            break;
		}
		if(cmp == COMPARE_GRATER) { 
			ptr = (const char*)p + size;
			lim--;
		} 
	}
	return result;
}

void*  bsearch(const void* key, const void* base, size_t nmemb, size_t size, cmpfunc_t compar) {
    return bsearch_s(key, base, nmemb, size, compar, NULL);
}
