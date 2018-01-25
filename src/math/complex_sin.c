#include <stdlib.h>
#include <cml.h>

/*
 * sin(Z) = (sin(a) * ((e^b + e^-b) / 2) + (Cos(a) * (e^b - e^-b) / 2))i
 * sin(Z) = (sin(a) * cosh(b)) + (cos(a) * sinh(b))i
 *
 * @param complex z
 *
 * @return complex sin(z)
 *
 */

complex_t
complex_sin(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_sin(z.re);
        h = real_cos(z.re);
        a = real_cosh(z.im);
        b = real_sinh(z.im);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}
