#include <stdlib.h>
#include <cml.h>

/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex_t
complex_add(complex_t z, complex_t k)
{
        /* Declaration of variables and structures */
        complex_t w;
        real_t n, m;

        /* Mathematical algorithm */
        n = real_add(creal(z), creal(k));
        m = real_add(cimag(z), cimag(k));
        w = complex(n, m);

        /* Return */
        return w;
}
