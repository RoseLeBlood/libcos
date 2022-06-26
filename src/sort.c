#include "libcos/sort.h"


void __private_quick_sort(int32_t* data, long low, long high, compar_t compar, void* args) {
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

                    compar(args, (void*)&data[i], &data[j]);
                }
                ++i;
                --j;
            }
        } while (i <= j);

        if (low < j) __private_quick_sort(data, low, j, compar, NULL);
        if (i < high) low = i;
        else break;
    }
}

void __private_down_heap(int32_t* data, size_t k, size_t n) {
    const int32_t temp = data[k - 1];

    while (k <= n / 2) {
        size_t child = 2 * k;
        if (child < n && (data[child - 1] < data[child]))
            ++child;
        if ((temp < data[child - 1])) {
            data[k - 1] = data[child - 1];
            k = child;
        } else break;
    }
    data[k - 1] = temp;
}

void __private_shell_sort(int32_t* data, size_t n) {
    size_t temp, j;

    for (size_t gap = n/2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; i += 1) {
            temp = data[i];

            for (j = i; j >= gap && (data[j - gap] < temp); j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

void quick_sort(void* begin, void* end, compar_t compar, void* args) {
    if (end - begin > 1)
	    __private_quick_sort(begin, 0, (size_t)(end - begin - 1), compar, args);
}
void quick_sort_r(void* begin, void* end, compar_t compar)  {
    if (end - begin > 1)
	    __private_quick_sort(begin, 0, (size_t)(end - begin - 1), compar, NULL);
}

void heap_sort(void* begin, void* end, compar_t compar, void* args) {
    size_t n = end - begin;
    int32_t *_b = begin;

    for (size_t k = n / 2; k != 0; --k)
        __private_down_heap(_b, k, n);

    while (n >= 1) {
        const int32_t temp = _b[0];
        _b[0] = _b[n - 1];
        _b[n - 1] = temp;

        --n;
        __private_down_heap(_b, 1, n);
    }
}
void heap_sort_r(void* begin, void* end, compar_t compar) {
    size_t n = end - begin;
    int32_t *_b = begin;

    for (size_t k = n / 2; k != 0; --k)
        __private_down_heap(_b, k, n);

    while (n >= 1) {
        const int32_t temp = _b[0];
        _b[0] = _b[n - 1];
        _b[n - 1] = temp;

        --n;
        __private_down_heap(_b, 1, n);
    }
}

 void insertion_sort(void* begin, void* end, compar_t compar, void* args) {
	const size_t num = end - begin;
    int32_t* _b = begin;

    for (size_t i = 0; i < num; ++i) {
        const int32_t t = _b[i];
        size_t j = i;

        while (j > 0 && (t < _b[j - 1])) {
            _b[j] = _b[j - 1];
            --j;
        }
        _b[j] = t;
    }
}

 void insertion_sort_r(void* begin, void* end, compar_t compar) {
	const size_t num = end - begin;
    int32_t* _b = begin;

    for (size_t i = 0; i < num; ++i) {
        const int32_t t = _b[i];
        size_t j = i;

        while (j > 0 && (t < _b[j - 1])) {
            _b[j] = _b[j - 1];
            --j;
        }
        _b[j] = t;
    }
}