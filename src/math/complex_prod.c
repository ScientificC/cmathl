#include <stdlib.h>
#include <cml.h>

/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex_t
complex_prod(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t a, b, c, d;

        /* Mathematical algorithm */
        a = z.p[0];
        b = z.p[1];
        c = k.p[0];
        d = k.p[1];

        w = complex(a*c - b*d, a*d + b*c);

        /* Return */
        return w;
}
