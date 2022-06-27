#include "libcos/sort.h"


void __private_quick_sort(int32_t* data, long low, long high, cmpfunc_t compar, void* args) {
    while (true) {
        long i = low;
        long j = high;
        const int32_t pivot = data[(low + high) >> 1];

        do {
            while (data[i] < pivot) ++i;
            while (pivot < data[j]) --j;

            // Anything to swap?
            if (j >= i) {
                if (i != j) {
                    int32_t tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
                ++i;
                --j;
            }
        } while (i <= j);

        if (low < j) __private_quick_sort(data, low, j, compar, args);
        if (i < high) low = i;
        else break;
    }
}

void __private_down_heap(int32_t* data, size_t k, size_t n, cmpfunc_t compar, void* args) {
    const int32_t temp = data[k - 1];

    while (k <= n / 2) {
        size_t child = 2 * k;
        if (child < n && (compar( &data[child - 1], &data[child], args) == COMPARE_LESS) )
            ++child;
        if ( (compar(&temp, &data[child - 1], args) == COMPARE_LESS) ) {
            data[k - 1] = data[child - 1];
            k = child;
        } else break;
    }
    data[k - 1] = temp;
}

void __private_shell_sort(int32_t* data, size_t n, cmpfunc_t compar, void* args) {
    size_t temp, j, cmp;

    for (size_t gap = n/2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; i += 1) {
            temp = data[i];

            
            for (j = i; j >= gap; j -= gap) {
                cmp = (compar( &data[j - gap], &temp, args) == COMPARE_LESS);

                if(cmp == COMPARE_LESS)
                    data[j] = data[j - gap];
                else
                    continue;
            }
            data[j] = temp;
        }
    }
}

void quick_sort_s(void* begin, void* end, cmpfunc_t compar, void* args) {
    if (end - begin > 1)
	    __private_quick_sort(begin, 0, (size_t)(end - begin - 1), compar, args);
}
void quick_sort(void* begin, void* end)  {
    if (end - begin > 1)
	    __private_quick_sort(begin, 0, (size_t)(end - begin - 1), compare_less, NULL);
}

void heap_sort_s(void* begin, void* end, cmpfunc_t compar, void* args) {
    size_t n = end - begin;
    int32_t *_b = begin;

    for (size_t k = n / 2; k != 0; --k)
        __private_down_heap(_b, k, n, compar, args);

    while (n >= 1) {
        const int32_t temp = _b[0];
        _b[0] = _b[n - 1];
        _b[n - 1] = temp;

        --n;
        __private_down_heap(_b, 1, n, compar,args);
    }
}
void heap_sort(void* begin, void* end) {
    size_t n = end - begin;
    int32_t *_b = begin;

    for (size_t k = n / 2; k != 0; --k)
        __private_down_heap(_b, k, n, compare_less, NULL);

    while (n >= 1) {
        const int32_t temp = _b[0];
        _b[0] = _b[n - 1];
        _b[n - 1] = temp;

        --n;
        __private_down_heap(_b, 1, n, compare_less, NULL);
    }
}

 void insertion_sort_s(void* begin, void* end, cmpfunc_t compar, void* args) {
	const size_t num = end - begin;
    int32_t* _b = begin;

    for (size_t i = 0; i < num; ++i) {
        const int32_t t = _b[i];
        size_t j = i;

        while (j > 0 && (compar(t , _b[j - 1] , args ) == COMPARE_LESS) ) {
            _b[j] = _b[j - 1];
            --j;
        }
        _b[j] = t;
    }
}

 void insertion_sort(void* begin, void* end) {
	insertion_sort(begin, end, compare_less, NULL);
}

void shell_sort_s(void* begin, void* end, cmpfunc_t compar, void* args) {
    if (end - begin > 1)
			__private_shell_sort(begin, (size_t)(end - begin), compar, args);
}
void shell_sort(void* begin, void* end) {
    if (end - begin > 1)
			__private_shell_sort(begin, (size_t)(end - begin), compare_less, NULL);
}