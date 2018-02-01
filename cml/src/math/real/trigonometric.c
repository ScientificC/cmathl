#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE real_t
__atan__(real_t x)
{
        mint_t i;
        real_t ai_n = x,
               p = ai_n;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; i += 2) {
                ai_n = -ai_n*x*x;
                p += ai_n/((real_t) i + 2.0);
        }

        return p;
}


_CML_EXTERN_INLINE real_t
__sin__(real_t x)
{
        real_t ai, p;
        mint_t i;

        ai = x;
        p = ai;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; ++i) {
                ai = -ai*(x)*(x)/(2*i*(2*i+1));
                p = p + ai;
        }

        return p;
}

/*
 * Computes real arc cosine
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_acos(real_t x)
{
        /* Declaration of variables and structures */
        real_t h, y;

        /* Mathematical algorithm */
        y = real_asin(x);
        h = real_sub(HALFPI, y);

        /* Return */
        return h;
}


/*
 * Computes real arc sine
 * --| asin(x) = atan(x / sqrt(1 − x²))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_asin(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_pow(x, 2.0);
        z = real_sub(1.0, y);
        w = real_sqrt(z);
        k = real_div(x, w);
        h = real_atan(k);

        /* Return */
        return h;
}


/*
 * Computes real arc tangent
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_atan(real_t x)
{
        /* Declaration of variables and structures */
        real_t s, w, a;

        /* Mathematical algorithm */
        a = real_abs(x);
        s = real_sgn(x);
        w = real_prod(s, __atan__(a));

        /* Return */
        return w;
}


/*
 * Computes real arc tangent, using signs to determinate cuadrants
 * --| atan2(y, x) = HALFPI*sgn(y) - atan(x/y)
 *
 * @param real_t y
 * @param real_t x
 * @return real_t
 */

real_t
real_atan2(real_t y, real_t x)
{
        /* Declaration of variables and structures */
        real_t s, k, j, z, w;

        /* Mathematical algorithm */
        s = real_sgn(y);
        k = real_div(x, y);
        j = real_atan(k);
        z = real_prod(HALFPI, s);
        w = real_sub(z, j);

        /* Return */
        return w;
}


/*
 * Computes real cosine
 * --| cos(x) = sin(x + HALFPI)
 * --| cos(x) = cos(-x) = cos(|x|)
 *
 * @param real_t x
 * @return real cos(x)
 */

real_t
real_cos(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, h;

        /* Mathematical algorithm */
        y = real_abs(x); /* cos(x) = cos(-x) = cos(|x|) */
        z = real_add(y, HALFPI);
        h = real_sin(z);

        /* Return */
        return h;
}


/*
 * Computes real cotangent
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_cot(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_isnull(y) ?
            real_nan() :
            real_div(real_cos(x), y);

        /* Return */
        return h;
}


/*
 * Computes real cosecant
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_csc(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real secant function by using trigonometric identities
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sec(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_cos(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real sine function by using Taylor Series
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sin(real_t x)
{
        /* Domain check */
        if (real_ismult(x, (PI))) {
                return 0.0;
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, h;

        /* Mathematical algorithm */
        s = real_sgn(x); /* sin(-x) = -sin(x) */
        y = real_abs(x);
        z = real_ared(y);
        w = ((mfloat_t) __sin__(z));
        h = real_prod(w, s);

        /* Return */
        return h;
}


/*
 * Computes real tangent
 * --| tan(x) = sin(x) / cos(x)
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_tan(real_t x)
{
        /* Declaration of variables and structures */
        real_t y;

        /* Mathematical algorithm */
        y = real_cos(x);

        return real_isnull(y) ?
               real_nan() :
               real_div(real_sin(x), y);;
}
