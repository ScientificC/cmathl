#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml.h>

#ifdef CML_NO_MATH
long double
__atan(long double value)
{
        long double sign = 1.0L;
        long double x = value;
        long double y = 0.0L;

        if (real_isnull(value))
        {
                return 0;
        }
        else if (x < 0)
        {
                sign = (-1.0L);
                x *= (-1.0L);
        }

        x = (x-1.0L)/(x+1.0L);
        y = x*x;
        x = ((((((((.0028662257L*y - .0161657367L)*y + .0429096138L)*y -
                  .0752896400L)*y + .1065626393L)*y - .1420889944L)*y +
               .1999355085L)*y - .3333314528L)*y + 1)*x;
        x = .785398163397L + sign*x;

        return x;
}


__CML_EXTERN_INLINE long double
__cos(long double x)
{
        long double ai, newsum, oldsum;
        mint_t i;

        ai = 1.0;
        newsum = 1.0;
        i = 1;

        do
        {
                oldsum = newsum;
                ai = -ai*(x)*(x)/(i*(i + 1.0));
                newsum = newsum + ai;
                i += 2;
        } while (!real_equal(newsum, oldsum));

        return newsum;
}


__CML_EXTERN_INLINE long double
__sin(long double x)
{
        long double ai, newsum, oldsum;
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
        #define __atan(x) __CML_MATH_NAME(atan)(x)
        #define __cos(x) __CML_MATH_NAME(cos)(x)
        #define __sin(x) __CML_MATH_NAME(sin)(x)
#endif

/*
 * Computes real arc cosine
 *
 * @param double x
 * @return double
 */

double
real_acos(double x)
{
        /* Declaration of variables and structures */
        double h, y;

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
 * @param double x
 * @return double
 */

double
real_asin(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, k, h;

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
 * @param double x
 * @return double
 */

double
real_atan(double x)
{
        /* Declaration of variables and structures */
        double s, w, a;

        /* Mathematical algorithm */
        a = real_abs(x);
        s = real_sgn(x);
        w = real_mul(s, (double) __atan(a));

        /* Return */
        return w;
}


/*
 * Computes real arc tangent, using signs to determinate cuadrants
 * --| atan2(y, x) = M_PI_2*sgn(y) - atan(x/y)
 *
 * @param double y
 * @param double x
 * @return double
 */

double
real_atan2(double y, double x)
{
        /* Declaration of variables and structures */
        double s, k, j, z, w;

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
 * @param double x
 * @return real cos(x)
 */

double
real_cos(double x)
{
        /* Declaration of variables and structures */
        double y, h;

        /* Mathematical algorithm */
        y = real_abs(x); /* cos(x) = cos(-x) = cos(|x|) */
        h = (double) __cos(real_ared(y));

        /* Return */
        return h;
}


/*
 * Computes real cotangent
 *
 * @param double x
 * @return double
 */

double
real_cot(double x)
{
        /* Declaration of variables and structures */
        double y, h;

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
 * @param double x
 * @return double
 */

double
real_csc(double x)
{
        /* Declaration of variables and structures */
        double y, h;

        /* Mathematical algorithm */
        y = real_sin(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real secant function by using trigonometric identities
 *
 * @param double x
 * @return double
 */

double
real_sec(double x)
{
        /* Declaration of variables and structures */
        double y, h;

        /* Mathematical algorithm */
        y = real_cos(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real sine function by using Taylor Series
 *
 * @param double x
 * @return double
 */

double
real_sin(double x)
{
        /* Domain check */
        if (real_ismult(x, M_PI))
        {
                return 0.0;
        }

        /* Declaration of variables and structures */
        double s, y, z, w, h;

        /* Mathematical algorithm */
        s = real_sgn(x); /* sin(-x) = -sin(x) */
        y = real_abs(x);
        z = real_ared(y);
        w = (double) __sin(z);
        h = real_mul(w, s);

        /* Return */
        return h;
}


/*
 * Computes real tangent
 * --| tan(x) = sin(x) / cos(x)
 *
 * @param double x
 * @return double
 */

double
doublean(double x)
{
        /* Declaration of variables and structures */
        double y;

        /* Mathematical algorithm */
        y = real_cos(x);

        return real_isnull(y) ?
               real_nan() :
               real_div(real_sin(x), y);
}
