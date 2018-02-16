#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml.h>


#ifdef CML_NO_MATH
long double
__exp(long double x)
{
        int n;
        long double term, oldsum, newsum;

        n = 0;
        oldsum = 0.0L;
        newsum = 1.0L;
        term = 1.0L;

        /* terminates when the new sum is no different from the old sum */
        while (!real_equal(newsum, oldsum))
        {
                oldsum = newsum;
                n++;
                term = term*x/n; /* term has the value (x~n)/(n!) */
                newsum = newsum + term; /* approximates exp(x) */
        }

        return newsum;
}
#else
        #include <math.h>
        #define __exp(x) __CML_MATH_NAME(exp)(x)
#endif

/*
 * Returns e raised to the given power
 *
 * @param real_t x: Exponent of the function
 * @return real_t
 */

real_t
real_exp(real_t x)
{
        return (real_t) __exp((long double) x);
}


/*
 * The logarithm logb(x) can be computed from the logarithms of x and b with
 * respect to an arbitrary base k using the following formula,
 * --| log_b(x) = log_k(x) / log_k(b)
 *
 * @param real_t x
 * @param real_t b
 * @return real_t
 */

real_t
real_log_b(real_t x, real_t b)
{
        /* Declaration of variables and structures */
        real_t y, z, w;

        /* Mathematical algorithm */
        y = real_log(x);
        z = real_log(b);
        w = real_div(y, z);

        /* Return */
        return w;

}


/*
 * Computes real natural logarithm function by using hyperbolic definition
 * --| log(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_log(real_t x)
{
        /* Domain check */
        if (x <= 0) {
                return real_nan();
        }

        /* Declaration of variables and structures */
        real_t y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_mul(x, x);
        z = y - 1.0;
        w = y + 1.0;
        k = real_div(z, w);
        h = real_atanh(k);

        /* Return */
        return h;

}


real_t
real_log1p(real_t x)
{
        volatile real_t y, z;

        y = 1 + x;
        z = y - 1;

        return real_log(y) - (z-x)/y; /* cancels errors with IEEE arithmetic */
}
