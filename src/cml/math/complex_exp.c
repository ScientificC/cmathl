#include <stdlib.h>
#include <cml.h>

/*
 * exp(Z) = e^Z = (e^a * Cos(b) + e^a * Sin(b)i)
 *
 * @param complex z: Exponent of the function
 *
 * @return complex e^z
 *
 */

complex_t
complex_exp(complex_t z)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t n, m, h, x, y;

        /* Mathematical algorithm */
        h = real_exp(z.p[0]);
        n = real_cos(z.p[1]);
        m = real_sin(z.p[1]);
        x = real_prod(h, n);
        y = real_prod(h, m);

        w = complex(x, y);

        /* Return */
        return w;
}
