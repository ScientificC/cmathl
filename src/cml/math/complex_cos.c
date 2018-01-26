#include <stdlib.h>
#include <cml.h>

/*
 * cos(Z) = (cos(a) * ((e^b - e^-b) / 2) + (sin(a) * (e^b + e^-b) / 2))i
 * cos(Z) = (cos(a) * sinh(b)) + (sin(a) * cosh(b))i
 *
 * @param complex z
 *
 * @return complex cos(z)
 *
 */

complex_t
complex_cos(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_cos(z.p[0]);
        h = real_sin(z.p[0]);
        a = real_sinh(z.p[1]);
        b = real_cosh(z.p[1]);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}
