
#include <stddef.h>
#include <stdlib.h>

void qsort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
	quick_sort_s(base, (base + (nitems -1)), compar, args);
}
void qsort(void* base, size_t nitems, size_t size, cmpfunc_t compar) {
    quick_sort_s(base, (base + (nitems -1)), compar, NULL);
}

void ssort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
    shell_sort_s(base, (base + (nitems -1)), compar, args);
}
void ssort (void* base, size_t nitems, size_t size, cmpfunc_t compar) {
    shell_sort_s(base, (base + (nitems -1)), compar, NULL);
}

void isort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
    insertion_sort_s(base, (base + (nitems -1)), compar, args);
}
void isort (void* base, size_t nitems, size_t size, cmpfunc_t compar) {
    insertion_sort_s(base, (base + (nitems -1)), compar, NULL);
}

void hsort_s (void* base, size_t nitems, size_t size, cmpfunc_t compar, void* args) {
    heap_sort_s(base, (base + (nitems -1)), compar, args);
}
void hsort (void* base, size_t nitems, size_t size, cmpfunc_t compar){
    heap_sort_s(base, (base + (nitems -1)), compar, NULL);
}