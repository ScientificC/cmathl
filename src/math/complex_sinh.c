#include <stdlib.h>
#include <cml.h>

/*
 * sinh(Z) = (cos(b) * ((e^a - e^-a) / 2) + (sin(b) * (e^a + e^-a) / 2))i
 * sinh(Z) = (cos(b) * cosh(a)) + (sin(b) * sinh(a))i
 *
 * @param complex z
 *
 * @return complex sinh(z)
 *
 */

complex
complex_sinh(complex z)
{
        /* Declaration of variables and structures */
        complex w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_cos(z->im);
        h = real_sin(z->im);
        a = real_sinh(z->re);
        b = real_cosh(z->re);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex_new(n, m);

        /* Return */
        return w;
}
