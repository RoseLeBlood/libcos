
#include <stddef.h>
#include <stdlib.h>

void qsort (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
	quick_sort(base, base[nitems -1], compar, args);
}
void qsort_r(void* base, size_t nmemb, size_t size, cmpfunc_t compar) {
    quick_sort(base, base[nitems -1], compar, NULL);
}

void ssort (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
    shell_sort(base, base[nitems -1], compar, args);
}
void ssort_r (void* base, size_t nitems, size_t size, cmpfunc_t compar) {
    shell_sort(base, base[nitems -1], compar, NULL);
}

void isort (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
    insertion_sort(base, base[nitems -1], compar, args);
}
void isort_r (void* base, size_t nitems, size_t size, cmpfunc_t compar) {
    insertion_sort(base, base[nitems -1], compar, NULL);
}

void hsort (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
    heap_sort(base, base[nitems -1], compar, args);
}
void hsort_r (void* base, size_t nitems, size_t size, cmpfunc_t compar){
    heap_sort(base, base[nitems -1], compar, NULL);
}