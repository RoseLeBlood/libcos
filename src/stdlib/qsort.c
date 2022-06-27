
#include <stddef.h>
#include <stdlib.h>

void qsort (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
	quick_sort(base, base[nitems -1], compar, args);
}
void qsort_r(void* base, size_t nmemb, size_t size, cmpfunc_t compar) {
    quick_sort(base, base[nitems -1], compar, NULL);
}