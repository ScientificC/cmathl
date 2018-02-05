#include <stdlib.h>
#include <cml.h>

real_t
real_pow_int(real_t x, int n)
{
        unsigned int un;

        if(n < 0) {
                x = 1.0/x;
                un = -n;
        } else {
                un = n;
        }

        return real_pow_uint(x, un);
}


real_t
real_pow_uint(real_t x, unsigned int n)
{
        real_t value = 1.0;

        /* repeated squaring method
         * returns 0.0^0 = 1.0, so continuous in x
         */
        do {
                if (n & 1) value *= x; /* for n odd */
                n >>= 1;
                x *= x;
        } while (n);

        return value;
}


/*
 * Computes real power function developed by using the exponentiation process
 * --| pow(x, n) = sgn(x)e^(nlog(|x|))
 *
 * @param real_t x
 * @param real_t n
 * @return real_t pow(x, n)
 */

real_t
real_pow(real_t x, real_t n)
{
        /* Domain check */
        if (real_isnull(x)) {
                return real_isnull(n) ?
                       real_nan() :
                       x;
        }

        if (real_isinteger(n)) {
                return real_pow_int(x, (int) n);
        }

        /* Declaration of variables and structures */
        real_t s, y, z, w, k, h;

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
 * @param real_t x
 * @param real_t n: exponent
 * @return real_t
 */

real_t
real_root(real_t x, real_t n)
{
        /* Declaration of variables and structures */
        real_t y, z;

        /* Mathematical algorithm */
        y = real_div(1.0, n);
        z = real_pow(x, y);

        /* Return */
        return z;
}


/**
 * Computes real square root function developed by using the exponentiation process
 *
 * @param real_t x
 * @return real_t
 */

real_t
real_sqrt(real_t x)
{
        return real_root(x, 2.0);
}
