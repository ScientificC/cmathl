#include <stdlib.h>
#include <cml.h>

/*
 * (a + bi) · (c + di) = (ac − bd) + (ad + bc)i
 *
 */

complex
complex_prod(complex z, complex k)
{
        /* Declaration of variables and structures */
        complex w;
        real_t a, b, c, d;

        /* Mathematical algorithm */
        a = z->p[0];
        b = z->p[1];
        c = k->p[0];
        d = k->p[1];

        w = complex_new(a*c - b*d, a*d + b*c);

        /* Return */
        return w;
}
