#include <stdlib.h>
#include <cml.h>

_CML_EXTERN_INLINE cml_math_t
__atanh__(cml_math_t x)
{
        cml_math_t ai_n, p;
        mint_t i;

        ai_n = x;
        p = ai_n;

        for (i = 1; i <= CML_SERIES_TOP_IT_L; i += 2) {
                ai_n = ai_n*x*x;
                p = p + ai_n/(i+2);
        }

        return p;
}


/*
 * Computes real hyperbolic arc cosine
 * --| acosh(x) = log(x + sqrt(x² - 1))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_acosh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, b, c, h;

        /* Mathematical algorithm */
        b = (2.0);
        c = (1.0);
        y = real_pow(x, b);
        z = real_sub(y, c);
        w = real_sqrt(z);
        k = real_add(x, w);
        h = real_log(k);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic arc sine
 * --| asinh(x) = log(x + sqrt(x² + 1))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_asinh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_pow(x, 2.0);
        z = real_add(y, 1.0);
        w = real_sqrt(z);
        k = real_add(x, w);
        h = real_log(k);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic arc tangent
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_atanh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, c, h;

        /* Mathematical algorithm */
        y = real_abs(x);
        c = (1.0);
        h = real_is_greater(c, y) ?
            ((real_t) __atanh__(x)) :
            (real_nan());

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic cosine
 * --| cosh(x) = 1/2 * (exp(x) + exp(−x))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_cosh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_opposite(x);
        z = real_exp(x);
        w = real_exp(y);
        k = real_add(z, w);
        h = real_div(k, 2.0);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic cotangent
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_coth(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        z = real_sinh(x);
        w = real_inverse(z);
        h = real_prod(y, w);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic cosecant
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_csch(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic secant function by using Euler relationships
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sech(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic sine
 * --| sinh(x) = 1/2 * (exp(x) − exp(−x))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sinh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_opposite(x);
        z = real_exp(x);
        w = real_exp(y);
        k = real_sub(z, w);
        h = real_div(k, 2.0);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic tangent
 * --| tanh(x) = sinh(x) / cosh(x)
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_tanh(real_t x)
{
        /* Declaration of variables and structures */
        real_t y, z, w, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        z = real_cosh(x);
        w = real_inverse(z);
        h = real_prod(y, w);

        /* Return */
        return h;
}
