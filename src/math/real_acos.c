#include <stdlib.h>
#include <cml.h>

/* acosh(x) = log(x + sqrt(x² - 1)) */

real
real_acos(real x)
{
        // Declaration of variables and structures
        real y, c, h;

        // Mathematic algorithm
        c = real_new(HALFPI);
        y = real_asin(x);
        h = real_sub(c, x);

        // Free structures
        free(y);
        free(c);

        // Return
        return h;
}
