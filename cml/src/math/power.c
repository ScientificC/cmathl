#include <stdlib.h>
#include <cml/math.h>

double
real_pow_int(double x, int n)
{
        unsigned int un;

        if(n < 0)
        {
                x = 1.0/x;
                un = -n;
        }
        else
        {
                un = n;
        }

        return real_pow_uint(x, un);
}


double
real_pow_uint(double x, unsigned int n)
{
        long double value = 1.0L;
        long double y = (long double) x;

        /* repeated squaring method
         * returns 0.0^0 = 1.0, so continuous in x
         */
        do {
                if (n & 1) value *= y; /* for n odd */
                n >>= 1;
                y *= y;
        } while (n);

        return (double) value;
}


/*
 * Computes real power function developed by using the exponentiation process
 * --| pow(x, n) = sgn(x)e^(nlog(|x|))
 *
 * @param double x
 * @param double n
 * @return double pow(x, n)
 */

double
real_pow(double x, double n)
{
        /* Domain check */
        if (real_isnull(x))
        {
                return real_isnull(n) ?
                       real_nan() :
                       x;
        }

        if (real_isinteger(n))
        {
                return real_pow_int(x, (int) n);
        }

        /* Declaration of variables and structures */
        double s, y, z, w, k, h;

        /* Mathematical algorithm */
        s = real_sgn(x);
        y = real_abs(x);
        z = real_log(y);
        w = real_mul(n, z);
        k = real_exp(w);
        h = real_mul(s, k);

        /* Return */
        return h;
}


/**
 * Computes real root function by using the exponentiation process
 *
 * @param double x
 * @param double n: exponent
 * @return double
 */

double
real_root(double x, double n)
{
        /* Declaration of variables and structures */
        double y, z;

        /* Mathematical algorithm */
        y = real_div(1.0, n);
        z = real_pow(x, y);

        /* Return */
        return z;
}


/**
 * Computes real square root function developed by using the exponentiation process
 *
 * @param double x
 * @return double
 */

double
real_sqrt(double x)
{
        return real_root(x, 2.0);
}
