#include <stdlib.h>
#include <cml.h>

/*
 * (a + bi) + (c + di) = (a+c) + (b+d)i
 *
 */

complex
complex_add(complex z, complex k)
{
        /* Declaration of variables and structures */
        complex w;
        real_t n, m;

        /* Mathematical algorithm */
        n = real_add(creal(z), creal(k));
        m = real_add(cimag(z), cimag(k));
        w = complex_new(n, m);

        /* Return */
        return w;
}
