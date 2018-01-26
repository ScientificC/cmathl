#include <stdlib.h>
#include <cml.h>

/*
 * It can be shown that, let z = a + bi a complex number, the multiplicative inverse of z (w), with a⋅b ≠ 0, is
 * W = conjugate(z) / abs(z)^2
 *
 */

complex_t
complex_inverse(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w, h;
        real_t a, b, m, n;


        /* Mathematical algorithm */
        w = complex_conjugate(z);
        a = complex_abs(z);
        b = real_pow(a, 2.0);
        n = real_div(w.p[0], b);
        m = real_div(w.p[1], b);

        h = complex(n, m);

        /* Return */
        return h;
}
