#include <stdlib.h>
#include <cml/math.h>

double
cml_pow_int(double x, int n)
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

        return cml_pow_uint(x, un);
}


double
cml_pow_uint(double x, unsigned int n)
{
        long double value = 1.0L;
        long double y = (long double) x;

        if (cml_isnull(x) && (cml_isnull(n) || n < 0.0))
        {
                return cml_nan();
        }

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
cml_pow(double x, double n)
{
        /* Domain check */
        if (cml_isnull(x))
        {
                return cml_isnull(n) || n < 0.0 ?
                       cml_nan() :
                       x;
        }

        if (cml_isinteger(n))
        {
                return cml_pow_int(x, (int) n);
        }

        /* Declaration of variables and structures */
        double s, y, z, w, k, h;

        /* Mathematical algorithm */
        s = cml_sgn(x);
        y = cml_abs(x);
        z = cml_log(y);
        w = cml_mul(n, z);
        k = cml_exp(w);
        h = cml_mul(s, k);

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
cml_root(double x, double n)
{
        /* Declaration of variables and structures */
        double y, z;

        /* Mathematical algorithm */
        y = cml_div(1.0, n);
        z = cml_pow(x, y);

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
cml_sqrt(double x)
{
        return cml_root(x, 2.0);
}
