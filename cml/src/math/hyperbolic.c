#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml/math.h>

#if defined CML_NO_MATH
__CML_EXTERN_INLINE long double
__atanh(long double x)
{
        long double ai_n, sum;
        mint_t i;

        ai_n = x;
        sum = ai_n;
        i = 1;

        while (real_abs(ai_n) >= CML_FLT_EPSILON  && i < 1e4)
        {
                ai_n = ai_n*x*x;
                sum = sum + ai_n/(i+=2);
        }

        return sum;
}
#else
        #include <math.h>
        #if !(defined PREDEF_STANDARD_C99 || defined PREDEF_STANDARD_CPP99)
double
__log1p(double x)
{
        volatile double y, z;

        y = 1 + x;
        z = y - 1;

        return log(y) - (z-x)/y;     /* cancels errors with IEEE arithmetic */
}

double
__atanh(const double x)
{
        double a = fabs(x);
        double s = (x < 0) ? -1 : 1;

        if (a > 1)
        {
                return NAN;
        }
        else if (a == 1)
        {
                return (x < 0) ? NEGINF : POSINF;
        }
        else if (a >= 0.5)
        {
                return s * 0.5 * __log1p(2 * a / (1 - a));
        }
        else if (a > CML_DBL_EPSILON)
        {
                return s * 0.5 * __log1p(2 * a + 2 * a * a / (1 - a));
        }
        else
        {
                return x;
        }
}
        #else
        #define __atanh(x) __CML_MATH_NAME(atanh)(x)
        #endif
#endif

/*
 * Computes real hyperbolic arc cosine
 * --| acosh(x) = log(x + sqrt(x² - 1))
 *
 * @param double x
 * @return double
 */

double
real_acosh(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_pow(x, 2.0);
        z = real_sub(y, 1.0);
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
 * @param double x
 * @return double
 */

double
real_asinh(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, k, h;

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
 * @param double x
 * @return double
 */

double
real_atanh(double x)
{
        /* Declaration of variables and structures */
        double y, h;

        /* Mathematical algorithm */
        y = real_abs(x);
        h = real_isgreater(1.0, y) ?
            (double) __atanh(x) :
            real_nan();

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic cosine
 * --| cosh(x) = 1/2 * (exp(x) + exp(−x))
 *
 * @param double x
 * @return double
 */

double
real_cosh(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, k, h;

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
 * @param double x
 * @return double
 */

double
real_coth(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, h;

        /* Mathematical algorithm */
        y = real_cosh(x);
        z = real_sinh(x);
        w = real_inverse(z);
        h = real_mul(y, w);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic cosecant
 *
 * @param double x
 * @return double
 */

double
real_csch(double x)
{
        /* Declaration of variables and structures */
        double y, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        h = real_inverse(y);

        /* Return */
        return h;
}


/*
 * Computes real hyperbolic secant function by using Euler relationships
 *
 * @param double x
 * @return double
 */

double
real_sech(double x)
{
        /* Declaration of variables and structures */
        double y, h;

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
 * @param double x
 * @return double
 */

double
real_sinh(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, k, h;

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
 * @param double x
 * @return double
 */

double
doubleanh(double x)
{
        /* Declaration of variables and structures */
        double y, z, w, h;

        /* Mathematical algorithm */
        y = real_sinh(x);
        z = real_cosh(x);
        w = real_inverse(z);
        h = real_mul(y, w);

        /* Return */
        return h;
}
