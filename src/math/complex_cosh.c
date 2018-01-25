#include <stdlib.h>
#include <cml.h>

/*
 * cosh(Z) = (cos(b) * ((e^a + e^-a) / 2) + (sin(b) * (e^a - e^-a) / 2))i
 * cosh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex z
 *
 * @return complex cosh(z)
 *
 */

complex_t
complex_cosh(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_cos(z.p[1]);
        h = real_sin(z.p[1]);
        a = real_cosh(z.p[0]);
        b = real_sinh(z.p[0]);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex(n, m);

        /* Return */
        return w;
}
