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

complex
complex_sin(complex z)
{
        /* Declaration of variables and structures */
        complex w;
        real_t k, h, a, b, n, m;

        /* Mathematical algorithm */
        k = real_sin(z->re);
        h = real_cos(z->re);
        a = real_cosh(z->im);
        b = real_sinh(z->im);

        n = real_prod(k, a);
        m = real_prod(h, b);

        w = complex_new(n, m);

        /* Return */
        return w;
}
