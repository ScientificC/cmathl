#include <stdlib.h>
#include <cml.h>

/*
 * Development of the Taylor series of the function e^x
 *
 * @param real x: Exponent of the function
 *
 * @return real e^x
 */

real_t
real_exp(real_t x)
{
        /* Declaration of variables and structures */
        mint_t i;
        cml_math_t ai, ex;

        /* Mathematical algorithm */
        ai = 1.0;
        ex = ai;

        for (i = 1; i < CML_SERIES_TOP_IT_L; ++i) {
                ai = ai*(x)/i;
                ex = ex + ai;
        }

        /* Return */
        return (real_t) ex;
}
