#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml.h>

#ifdef CML_NO_MATH
real_t
__atan__(real_t value)
{
        real_t sign = 1.;
        real_t x = value;
        real_t y = 0.;

        if (real_isnull(value))
        {
                return 0;
        }
        else if (x < 0)
        {
                sign = (-1.);
                x *= (-1.);
        }

        x = (x-1.)/(x+1.);
        y = x*x;
        x = ((((((((.0028662257*y - .0161657367)*y + .0429096138)*y -
                  .0752896400)*y + .1065626393)*y - .1420889944)*y +
               .1999355085)*y - .3333314528)*y + 1)*x;
        x = .785398163397 + sign*x;

        return x;
}


__CML_EXTERN_INLINE real_t
__sin__(real_t x)
{
        real_t ai, newsum, oldsum;
        mint_t i;

        ai = x;
        newsum = ai;
        i = 1;

        do
        {
                oldsum = newsum;
                ai = -ai*(x)*(x)/(2*i*(2*i+1));
                newsum = newsum + ai;
                ++i;
        } while (!real_equal(newsum, oldsum));

        return newsum;
}
#else
        #include <math.h>
        #define __atan__(x) atan(x)
        #define __sin__(x) sin(x)
#endif

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
        h = real_sub(M_PI_2, y);

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
        w = real_mul(s, __atan__(a));

        /* Return */
        return w;
}


/*
 * Computes real arc tangent, using signs to determinate cuadrants
 * --| atan2(y, x) = M_PI_2*sgn(y) - atan(x/y)
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
        z = real_mul(M_PI_2, s);
        w = real_sub(z, j);

        /* Return */
        return w;
}


/*
 * Computes real cosine
 * --| cos(x) = sin(x + M_PI_2)
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
        z = real_add(y, M_PI_2);
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
        if (real_ismult(x, M_PI))
        {
                return 0.0;
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, h;

        /* Mathematical algorithm */
        s = real_sgn(x); /* sin(-x) = -sin(x) */
        y = real_abs(x);
        z = real_ared(y);
        w = ((mfloat_t) __sin__(z));
        h = real_mul(w, s);

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
               real_div(real_sin(x), y);
}
