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
 * to store the permutation vector resulting from the sorting
 * and to sort array with non contiguous cells,
 * typically a column of matrix sorted row-wise.
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>

#include <cml/errno.h>
#include <cml/math.h>
#include <cml/sort.h>

/*
 * Qsort routine from Bentley & McIlroy's "Engineering a Sort Function".
 */

/* this function takes care of a possible leading dimension. This means to
 * between two cells in a, we have to jump of lda * es
 * es is the size of one cell of a
 * n is the length of a
 * lda the leading dimension
 */
static __CML_INLINE void
swapfunc(char *a, char *b, int es, int n, int lda)
{
        long i = n, atomic_size;
        register char *pi = a;
        register char *pj = b;

        do
        {
                atomic_size = es;
                do
                {
                        register char temp = *pi;
                        *pi = *pj;
                        *pj = temp;
                        pi++;
                        pj++;
                }
                while (--atomic_size > 0);
                pi--;
                pj--;
                pi += lda;
                pj += lda;
        }
        while (--i > 0);
}


static __CML_INLINE void
swapfunc_double(double *a, double *b, int n, int lda)
{
        register double *pi = a;
        register double *pj = b;
        do
        {
                register double temp = *pi;
                *pi = *pj;
                *pj = temp;
                pi += lda;
                pj += lda;
        }
        while (--n > 0);
}


static __CML_INLINE void
swapfunc_int(int *a, int *b, int n, int lda)
{
        register int *pi = a;
        register int *pj = b;
        do
        {
                register int temp = *pi;
                *pi = *pj;
                *pj = temp;
                pi += lda;
                pj += lda;
        }
        while (--n > 0);
}


#define swap2(a, b, TYPE) {register TYPE temp; temp = *((TYPE *)(a));   \
                           *((TYPE *)(a)) = *((TYPE *)(b)); *((TYPE *)(b)) = temp; }

#define swap(a, b) if (es==sizeof(int)) swap2(a, b, int)    \
                else if (es==sizeof(double)) swap2 (a, b, double)       \
                        else swapfunc(a, b, es, 1, 1);

#define swapindex(a,b) if (index_flag==true) {register int temp; temp = *(a); *(a) = *(b); *(b) = temp; }


#define vecswap(a, b, n, lda)    if ((n) > 0) {                         \
                es==sizeof(int) ? swapfunc_int((int *)(a), (int *)(b), (n)/es, lda) : \
                (es==sizeof(double) ? swapfunc_double((double *)(a), (double *)(b), (n)/es, lda) : \
                 swapfunc(a, b, es, n/es, lda));                                  \
}

/* #define vecswap(a, b, n, lda)    if ((n) > 0) { swapfunc(a, b, es, n/es, lda); } */

#define vecswapindex(a, b, n, lda)    if ((n) > 0 && index_flag==true) swapfunc_int(a, b, n, lda)

/* static __CML_INLINE char *med3(char *a, char *b, char *c, int (*cmp)(const void*, const void *)) */
/* { */
/*   return cmp(a, b) < 0 ? */
/*     (cmp(b, c) < 0 ? b : (cmp(a, c) < 0 ? c : a )) */
/*     :(cmp(b, c) > 0 ? b : (cmp(a, c) < 0 ? a : c )); */
/* } */


static __CML_INLINE void
med3withindex(char *ans, int *i_ans, char *a, char *b, char *c,
              int *i_a, int *i_b, int *i_c, cml_comparison_fn_t cmp)
{
        cmp(a, b) < 0 ?
        (cmp(b, c) < 0 ? (ans = b, i_ans = i_b) :
         (cmp(a, c) < 0 ? (ans = c, i_ans = i_c) :
          (ans = a, i_ans = i_a)))
        : (cmp(b, c) > 0 ? (ans = b, i_ans = i_b) :
           (cmp(a, c) < 0 ? (ans = a, i_ans = i_a) :
            (ans = c, i_ans = i_c)));

        (void) ans;
}


static __CML_INLINE void
med3noindex(char *ans, int *i_ans, char *a, char *b, char *c,
            int *i_a, int *i_b, int *i_c, cml_comparison_fn_t cmp)
{
        cmp(a, b) < 0 ? (cmp(b, c) < 0 ? (ans = b) : (cmp(a, c) < 0 ? (ans = c) : (ans = a)))
        : (cmp(b, c) > 0 ? (ans = b) : (cmp(a, c) < 0 ? (ans = a) : (ans = c)));

        (void) ans;
        (void) i_ans;
        (void) i_a;
        (void) i_b;
        (void) i_c;
}

#define med3index (index_flag==true ? med3withindex : med3noindex)

/**
 * @param a a generic pointer to be sorted
 * @param n the length of the array a
 * @param es the size of an element of a
 * @param lda the leading dimension of a, used to sort columns of matrices
 * stored row-wise
 * @param t an array of integers to store the permutation used to sort a
 * @param ldt the leading dimension of t, used to sort columns of matrices
 * stored row-wise
 * @param index_flag can be true or false. If true the permutation vector is
 * computed. If false the parameter t is not used
 * @param cmp the comparaison function
 */
void
cml_qsort(void *a, int n, int es, int lda, int *t, int ldt, int index_flag,
          cml_comparison_fn_t cmp)
{
        char *pa, *pb, *pc, *pd, *pl, *pm, *pn;
        int d, swap_cnt;
        int *ta, *tb, *tc, *td, *tm, *tl, *tn, d_t;
        int esa, est;
        ptrdiff_t r, r_t;

        esa = es * lda;
        est = ldt;

loop:
        swap_cnt = 0;
        if (n < 7)
        {
                for (pm = ((char *)a) + esa, tm = t + est; pm < ((char *) a) + n * esa; pm += esa, tm += est)
                {
                        for (pl = pm, tl = tm; pl > (char *) a && cmp(pl - esa, pl) > 0; pl -= esa, tl -= est)
                        {
                                swap(pl, pl - esa);
                                swapindex(tl, tl - est);
                        }
                }
                return;
        }
        pm = ((char *) a) + (n / 2) * esa;
        tm = t + (n / 2) * est;
        if (n > 7)
        {
                pl = a;
                tl = t;
                pn = ((char *) a) + (n - 1) * esa;
                tn = t + (n - 1) * est;
                if (n > 40)
                {
                        d = (n / 8) * esa;
                        d_t = (n / 8) * est;
                        med3index(pl, tl, pl, pl + d, pl + 2 * d, tl, tl + d_t, tl + 2 * d_t, cmp);
                        med3index(pm, tm, pm - d, pm, pm + d, tm - d_t, tm, tm + d_t, cmp);
                        med3index(pn, tn, pn - 2 * d, pn - d, pn, tn - 2 * d_t, tn - d_t, tn, cmp);
                }
                med3index(pm, tm, pl, pm, pn, tl, tm, tn, cmp);
        }
        swap(a, pm);
        swapindex(t, tm);

        pa = pb = ((char *) a) + esa;
        pc = pd = ((char *)a) + (n - 1) * esa;

        ta = tb = t + est;
        tc = td = t + (n - 1) * est;

        for (;;)
        {
                while (pb <= pc && (r = cmp(pb, a)) <= 0)
                {
                        if (r == 0)
                        {
                                swap_cnt = 1;
                                swap(pa, pb);
                                pa += esa;
                                swapindex(ta, tb);
                                ta += est;
                        }
                        pb += esa;
                        tb += est;
                }
                while (pb <= pc && (r = cmp(pc, a)) >= 0)
                {
                        if (r == 0)
                        {
                                swap_cnt = 1;
                                swap(pc, pd);
                                pd -= esa;
                                swapindex(tc, td);
                                td -= est;
                        }
                        pc -= esa;
                        tc -= est;
                }
                if (pb > pc)
                        break;
                swap(pb, pc);
                swapindex(tb, tc);
                swap_cnt = 1;
                pb += esa;
                pc -= esa;
                tb += est;
                tc -= est;
        }
        if (swap_cnt == 0) /* Switch to insertion sort */
        {
                for (pm = ((char *)a) + esa, tm = t + est; pm < ((char *) a) + n * esa; pm += esa, tm += est)
                {
                        for (pl = pm, tl = tm; pl > (char *) a && cmp(pl - esa, pl) > 0;
                             pl -= esa, tl -= est)
                        {
                                swap(pl, pl - esa);
                                swapindex(tl, tl - est);
                        }
                }
                return;
        }

        pn = ((char *) a) + n * esa;
        r = CML_MIN(pa - (char *)a, pb - pa);
        vecswap(a, pb - r, r / lda, lda);

        tn = t + n * est;
        r_t = CML_MIN(ta - t, tb - ta);
        vecswapindex(t, tb - r_t, r_t / ldt, ldt);

        r = CML_MIN(pd - pc, pn - pd - esa);
        vecswap(pb, pn - r, r / lda, lda);

        r_t = CML_MIN(td - tc, tn - td - est);
        vecswapindex(tb, tn - r_t, r_t / ldt, ldt);

        if ((r = pb - pa) > esa)
                cml_qsort(a, r / esa, es, lda, t, ldt, index_flag, cmp);
        if ((r = pd - pc) > esa)
        {
                /* Iterate rather than recurse to save stack space */
                a = pn - r;
                t = tn - (td - tc);
                n = r / esa;
                goto loop;
        }
        /* cml_qsort(pn - r, r / esa, es, lda, tn - (td - tc), ldt, cmp); */
}

#undef swapcode
#undef swap
#undef vecswap
#undef SWAPINIT
