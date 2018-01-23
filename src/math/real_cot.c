#include <stdlib.h>
#include <cml.h>

/*
 * cot(x) function developed by using trigonometric identities
 *
 * @param real x
 *
 * @return real cot(x)
 */

real
real_cot(real x)
{
        /* Declaration of structures */
        real y, z, h;

        /* Mathematical algorithm */
        z = real_cos(x);
        y = real_sin(x);
        h = real_isnull(y) ?
            real_new(NAN) :
            real_div(z, y);

        /* Free structures */
        free(z);
        free(y);

        /* Return */
        return h;
}
