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
 * @param double x: Exponent of the function
 * @return double
 */

double
real_exp(double x)
{
        return (double) __exp(x);
}


double
real_expm1(double x)
{
        /* FIXME: this should be improved */

        if (real_abs(x) < M_LN2)
        {
                /* Compute the taylor series S = x + (1/2!) x^2 + (1/3!) x^3 + ... */

                long double i = 1.0;
                long double sum = x;
                long double term = x / 1.0;

                do
                {
                        i++;
                        term *= x/i;
                        sum += term;
                }
                while (real_abs(term) > real_abs(sum) * CML_DBL_EPSILON);

                return (double) sum;
        }
        else
        {
                return real_exp(x) - 1.0;
        }
}


double
real_ldexp(double x, int e)
{
        int ex;

        if (real_isnull(x))
        {
                return x;
        }
        else
        {
                long double y = real_frexp(x, &ex);
                long double e2 = e + ex, p2;

                if (e2 >= DBL_MAX_EXP)
                {
                        y *= real_pow(2.0, e2 - DBL_MAX_EXP + 1);
                        e2 = DBL_MAX_EXP - 1;
                }
                else if (e2 <= DBL_MIN_EXP)
                {
                        y *= real_pow(2.0, e2 - DBL_MIN_EXP - 1);
                        e2 = DBL_MIN_EXP + 1;
                }

                p2 = real_pow(2.0, e2);
                return y * p2;
        }
}

double
real_frexp(double x, int *e)
{
        if (real_isnull(x))
        {
                *e = 0;
                return 0.0;
        }
        else if (!real_isfinite(x))
        {
                *e = 0;
                return x;
        }
        else if (real_abs(x) >= 0.5 && real_abs(x) < 1) /* Handle the common case */
        {
                *e = 0;
                return x;
        }
        else
        {
                long double ex = real_ceil(real_log(real_abs(x)) / M_LN2);
                int ei = (int) ex;
                long double f;

                /* Prevent underflow and overflow of 2**(-ei) */
                if (ei < DBL_MIN_EXP)
                        ei = DBL_MIN_EXP;

                if (ei > -DBL_MIN_EXP)
                        ei = -DBL_MIN_EXP;

                f = x * real_pow(2.0, -ei);

                if (!real_isfinite(f))
                {
                        /* This should not happen */
                        *e = 0;
                        return f;
                }

                while (real_abs(f) >= 1.0)
                {
                        ei++;
                        f /= 2.0;
                }

                while (real_abs(f) > 0 && real_abs(f) < 0.5)
                {
                        ei--;
                        f *= 2.0;
                }

                *e = ei;
                return f;
        }
}


/*
 * The logarithm logb(x) can be computed from the logarithms of x and b with
 * respect to an arbitrary base k using the following formula,
 * --| log_b(x) = log_k(x) / log_k(b)
 *
 * @param double x
 * @param double b
 * @return double
 */

double
real_log_b(double x, double b)
{
        /* Declaration of variables and structures */
        double y, z, w;

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
 * @param double x
 * @return double
 */

double
real_log(double x)
{
        /* Domain check */
        if (x <= 0) {
                return real_nan();
        }

        /* Declaration of variables and structures */
        double y, z, w, k, h;

        /* Mathematical algorithm */
        y = real_mul(x, x);
        z = y - 1.0;
        w = y + 1.0;
        k = real_div(z, w);
        h = real_atanh(k);

        /* Return */
        return h;

}


double
real_log1p(double x)
{
        volatile double y, z;

        y = 1 + x;
        z = y - 1;

        return real_log(y) - (z-x)/y; /* cancels errors with IEEE arithmetic */
}
