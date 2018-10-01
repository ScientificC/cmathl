#include <stdlib.h>
#undef CML_NO_ALIASES
#define CML_NO_ALIASES
#include <cml/math.h>


#ifdef CML_NO_MATH
long double
__cml_exp(long double x, int n_max)
{
        int n;
        long double term, oldsum, newsum;

        n = 0;
        oldsum = 0.0L;
        newsum = 1.0L;
        term = 1.0L;

        /* terminates when the new sum is no different from the old sum */
        for (n = 0; n < n_max;)
        {
                if (cml_equal(newsum, oldsum))
                {
                        break;
                }

                oldsum = newsum;
                n++;
                term = term*x/n; /* term has the value (x~n)/(n!) */
                newsum = newsum + term; /* approximates exp(x) */
        }

        return newsum;
}
#else
        #include <math.h>
        #define __cml_exp(x, ...) __CML_MATH_NAME(exp)(x)
#endif

/*
 * Returns e raised to the given power
 *
 * @param double x: Exponent of the function
 * @return double
 */

double
cml_exp(double x)
{
        return (double) __cml_exp(x, 33);
}


double
cml_expm1(double x)
{
        /* FIXME: this should be improved */

        if (cml_abs(x) < M_LN2)
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
                } while (cml_abs(term) > cml_abs(sum) * CML_DBL_EPSILON);

                return (double) sum;
        }
        else
        {
                return cml_exp(x) - 1.0;
        }
}


double
cml_ldexp(double x, int e)
{
        int ex;

        if (cml_isnull(x))
        {
                return x;
        }
        else
        {
                long double y = cml_frexp(x, &ex);
                long double e2 = e + ex, p2;

                if (e2 >= DBL_MAX_EXP)
                {
                        y *= cml_pow(2.0, e2 - DBL_MAX_EXP + 1);
                        e2 = DBL_MAX_EXP - 1;
                }
                else if (e2 <= DBL_MIN_EXP)
                {
                        y *= cml_pow(2.0, e2 - DBL_MIN_EXP - 1);
                        e2 = DBL_MIN_EXP + 1;
                }

                p2 = cml_pow(2.0, e2);
                return y * p2;
        }
}

double
cml_frexp(double x, int *e)
{
        if (cml_isnull(x))
        {
                *e = 0;
                return 0.0;
        }
        else if (!cml_isfinite(x))
        {
                *e = 0;
                return x;
        }
        else if (cml_abs(x) >= 0.5 && cml_abs(x) < 1) /* Handle the common case */
        {
                *e = 0;
                return x;
        }
        else
        {
                long double ex = cml_ceil(cml_log(cml_abs(x)) / M_LN2);
                int ei = (int) ex;
                long double f;

                /* Prevent underflow and overflow of 2**(-ei) */
                if (ei < DBL_MIN_EXP)
                        ei = DBL_MIN_EXP;

                if (ei > -DBL_MIN_EXP)
                        ei = -DBL_MIN_EXP;

                f = x * cml_pow(2.0, -ei);

                if (!cml_isfinite(f))
                {
                        /* This should not happen */
                        *e = 0;
                        return f;
                }

                while (cml_abs(f) >= 1.0)
                {
                        ei++;
                        f /= 2.0;
                }

                while (cml_abs(f) > 0 && cml_abs(f) < 0.5)
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
cml_log_b(double x, double b)
{
        double y, z;

        y = cml_log(x);
        z = cml_log(b);

        return y/z;
}


/*
 * Computes real natural logarithm function by using hyperbolic definition
 * --| log(x) = arctanh((x^2 - 1)/(x^2 + 1))
 *
 * @param double x
 * @return double
 */

double
cml_log(double x)
{
        if (x <= 0)
                return cml_nan();

        double y, z, w, k;

        y = x*x;
        z = y - 1.0;
        w = y + 1.0;
        k = z/w;

        return cml_atanh(k);
}


double
cml_log1p(double x)
{
        volatile double y, z;

        y = 1 + x;
        z = y - 1;

        return cml_log(y) - (z-x)/y; /* cancels errors with IEEE arithmetic */
}
