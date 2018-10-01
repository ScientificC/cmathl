/*-
 * Copyright (c) 1992, 1993
 *  The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *  This product includes software developed by the University of
 *  California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * This file has been modified by Ulises Jeremias Cornejo Fandos
 * in order to make the code compatible with the library.
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>

#include <scic/errno.h>
#include <cml/math.h>
#include <cml/sort.h>

/*
 * Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
 */

static __CML_INLINE char  *med3(char *, char *, char *, cml_comparison_fn_t);
static __CML_INLINE void   swapfunc(char *, char *, size_t, int);

/*
 * Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
 */
#define swapcode(TYPE, parmi, parmj, n) {     \
                size_t i = (n) / sizeof (TYPE);       \
                TYPE *pi = (TYPE *) (parmi);    \
                TYPE *pj = (TYPE *) (parmj);    \
                do {            \
                        TYPE t = *pi;    \
                        *pi++ = *pj;        \
                        *pj++ = t;        \
                } while (--i > 0);        \
}

#define SWAPINIT(a, es) do {                                                    \
        swaptype = ((char *)(a) - (char *)0) % sizeof(long) ||                  \
                   (es) % sizeof(long) ? 2 : (es) == sizeof(long) ? 0 : 1;      \
} while (0)

static __CML_INLINE void
swapfunc(char *a, char *b, size_t n, int swaptype)
{
        if(swaptype <= 1)
        {
                swapcode(long, a, b, n);
        }
        else
        {
                swapcode(char, a, b, n);
        }
}

#define swap(a, b)                              \
        if (swaptype == 0) {                    \
                long t = *(long *)(a);          \
                *(long *)(a) = *(long *)(b);    \
                *(long *)(b) = t;               \
        } else                                  \
                swapfunc(a, b, es, swaptype)

#define vecswap(a, b, n)  if ((n) > 0) swapfunc(a, b, n, swaptype)

static __CML_INLINE char *
med3(char *a, char *b, char *c, cml_comparison_fn_t cmp )
{
        return cmp(a, b) < 0 ?
               (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a ))
               : (cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c ));
}

/*  The qsort function sorts an array of nmemb objects, the initial element of
    which is pointed to by base.  The size of each object is specified by size.

    The contents of the array are sorted into ascending order according to a
    comparison function pointed to by compar, which is called with two
    arguments that point to the objects being compared. The function shall
    return an integer less than, equal to, or greater than zero if the first
    argument is considered to be respectively less than, equal to, or greater
    than the second.

    If two elements compare as equal, their order in the resulting sorted array
    is unspecified.
 */
void
cml_qsort(void *a, size_t n, size_t es, cml_comparison_fn_t cmp)
{
        char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
        size_t d, r;
        int cmp_result;
        int swaptype, swap_cnt;

loop:   SWAPINIT(a, es);
        swap_cnt = 0;
        if (n < 7) {
                for (pm = (char *)a + es; pm < (char *)a + n * es; pm += es)
                        for (pl = pm;
                             pl > (char *)a && cmp(pl - es, pl) > 0;
                             pl -= es)
                                swap(pl, pl - es);
                return;
        }
        pm = (char *)a + (n / 2) * es;
        if (n > 7) {
                pl = a;
                pn = (char *)a + (n - 1) * es;
                if (n > 40) {
                        d = (n / 8) * es;
                        pl = med3(pl, pl + d, pl + 2 * d, cmp);
                        pm = med3(pm - d, pm, pm + d, cmp);
                        pn = med3(pn - 2 * d, pn - d, pn, cmp);
                }
                pm = med3(pl, pm, pn, cmp);
        }
        swap(a, pm);
        pa = pb = (char *)a + es;

        pc = pd = (char *)a + (n - 1) * es;
        for (;;) {
                while (pb <= pc && (cmp_result = cmp(pb, a)) <= 0) {
                        if (cmp_result == 0) {
                                swap_cnt = 1;
                                swap(pa, pb);
                                pa += es;
                        }
                        pb += es;
                }
                while (pb <= pc && (cmp_result = cmp(pc, a)) >= 0) {
                        if (cmp_result == 0) {
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
        if (swap_cnt == 0) { /* Switch to insertion sort */
                for (pm = (char *)a + es; pm < (char *)a + n * es; pm += es)
                        for (pl = pm;
                             pl > (char *)a && cmp(pl - es, pl) > 0;
                             pl -= es)
                                swap(pl, pl - es);
                return;
        }

        pn = (char *)a + n * es;
        r = CML_MIN(pa - (char *)a, pb - pa);
        vecswap(a, pb - r, r);
        r = CML_MIN((size_t)(pd - pc), ((size_t)(pn - pd)) - es);
        vecswap(pb, pn - r, r);
        if ((size_t)(r = pb - pa) > es)
                cml_qsort(a, r / es, es, cmp);
        if ((size_t)(r = pd - pc) > es) {
                /* Iterate rather than recurse to save stack space */
                a = pn - r;
                n = r / es;
                goto loop;
        }
/*    cml_qsort(pn - r, r / es, es, cmp);*/
}
