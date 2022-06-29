
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