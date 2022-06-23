/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#include <stddef.h>
#include <stdlib.h>

/*
 * Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
 */
#define swapcode(TYPE, parmi, parmj, n) { 		\
	long i = (n) / sizeof (TYPE); 			\
	register TYPE *pi = (TYPE *) (parmi); 		\
	register TYPE *pj = (TYPE *) (parmj); 		\
	do { 						\
		register TYPE	t = *pi;		\
		*pi++ = *pj;				\
		*pj++ = t;				\
        } while (--i > 0);				\
}

#define SWAPINIT(a, es) swaptype = ((char *)a - (char *)0) % sizeof(long) || \
	es % sizeof(long) ? 2 : es == sizeof(long)? 0 : 1;

static inline void swapfunc(char* a,char* b, int n, int swaptype) {
	if(swaptype <= 1) 
		swapcode(long, a, b, n)
	else
		swapcode(char, a, b, n)
}

#define swap(a, b)					    \
	if (swaptype == 0) {				\
		long t = *(long *)(a);			\
		*(long *)(a) = *(long *)(b);    \
		*(long *)(b) = t;			    \
	} else						        \
		swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n) 	if ((n) > 0) swapfunc(a, b, n, swaptype)

static inline char* med3(char* a, char* b, char* c, compar_t cmp, void* args) {
	return cmp(args, a, b) < 0 ?
	       (cmp(args, b, c) < 0 ? b : (cmp(args, a, c) < 0 ? c : a )) :
           (cmp(args, b, c) > 0 ? b : (cmp(args, a, c) < 0 ? a : c ));
}

void qsort(void* a, size_t n, size_t es, compar_t cmp, void* args) {
    char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
    int d, r, swaptype, swap_cnt;

loop:	
    SWAPINIT(a, es);
	swap_cnt = 0;

	if (n < 7) {
		for (pm = a + es; pm < (char *) a + n * es; pm += es)
			for (pl = pm; pl > (char *) a && cmp(args, pl - es, pl) > 0;
			     pl -= es)
				swap(pl, pl - es);
		return;
	}
	pm = a + (n / 2) * es;

	if (n > 7) {
		pl = a;
		pn = a + (n - 1) * es;
		if (n > 40) {
			d = (n / 8) * es;
			pl = med3(pl, pl + d, pl + 2 * d, cmp, args);
			pm = med3(pm - d, pm, pm + d, cmp, args);
			pn = med3(pn - 2 * d, pn - d, pn, cmp, args);
		}
		pm = med3(pl, pm, pn, cmp, args);
	}
	swap(a, pm);
	pa = pb = a + es;

	pc = pd = a + (n - 1) * es;
	for (;;) {
		while (pb <= pc && (r = cmp(args, pb, a)) <= 0) {
			if (r == 0) {
				swap_cnt = 1;
				swap(pa, pb);
				pa += es;
			}
			pb += es;
		}

		while (pb <= pc && (r = cmp(args, pc, a)) >= 0) {
			if (r == 0) {
				swap_cnt = 1;
				swap(pc, pd);
				pd -= es;
			}
			pc -= es;
		}
		if (pb > pc)
			break;
		swap(pb, pc);
		swap_cnt = 1;
		pb += es;
		pc -= es;
	}

	if (swap_cnt == 0) {  /* Switch to insertion sort */
		for (pm = a + es; pm < (char *) a + n * es; pm += es)
			for (pl = pm; pl > (char *) a && cmp(args, pl - es, pl) > 0; 
			     pl -= es)
				swap(pl, pl - es);
		return;
	}

	pn = a + n * es;
	r = min(pa - (char *)a, pb - pa);
	vecswap(a, pb - r, r);
	r = min(pd - pc, pn - pd - es);
	vecswap(pb, pn - r, r);

	if ((r = pb - pa) > es)
		qsort(a, r / es, es, cmp, args);
	if ((r = pd - pc) > es) { 
		a = pn - r;
		n = r / es;
		goto loop;
	}
}
void qsort_r(void* base, size_t nmemb, size_t size, compar_t compar) {
    return qsort(base, nmemb, size, compar, NULL);
}