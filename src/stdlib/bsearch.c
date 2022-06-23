#include <stdlib.h>
#include <ctype.h>

void* bsearch (const void* key, const void* base, size_t nmemb, size_t size, compar_t compar, void* args) {
    const char* ptr = base;
    size_t lim;
    int cmp;
    const void* p;
    void* result =  NULL;

	for(lim = nmemb; lim != 0; lim >>= 1) {
		p = ptr + (lim >> 1) * size;
		cmp = (*compar)(args, key, p);
		if(cmp == 0) {
			result = ((void*)(uintptr_t)p);
            break;
		}
		if(cmp > 0) { 
			ptr = (const char*)p + size;
			lim--;
		} 
	}
	return result;
}

void*  bsearch_r(const void* key, const void* base, size_t nmemb, size_t size, compar_t compar) {
        return bsearch(key, base, nmemb, size, compar, NULL);
}
