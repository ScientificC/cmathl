#include <stdlib.h>
#include <scic/errno.h>
#include <cml/math.h>
#include <cml/roots.h>

/**
 * Find the root of a function using a bisection method
 *
 * @param xmin lower bound
 * @param xmax upper bound
 * @param epsrel if the relative improvement over the root is less than this value,
 * then break;
 * @param epsabs if the absolute improvement over the root is less than this value,
 * then break;
 * @param res contains the root on exit
 * @param n_max maximum number of iterations
 * @param func a function pointer
 * @return SCIC_SUCCESS or SCIC_FAILURE if n_max reached
 */
int
cml_root_bisection(cml_function_t *func, double xmin, double xmax,
                   double epsrel, double epsabs,
                   size_t n_max, double *res)
{
        size_t i;
        double a, b, c, fa, fb, fc;

        CML_SAFE_FN_CALL(func, xmin, &fa);
        CML_SAFE_FN_CALL(func, xmax, &fb);

        if ((fa < 0.0 && fb < 0.0) || (fa > 0.0 && fb > 0.0))
        {
                SCIC_ERROR("endpoints do not straddle y=0", SCIC_EINVAL);
        }

        if (fa > 0.0)
        {
                a = xmax;
                b = xmin;
        }
        else
        {
                a = xmin;
                b = xmax;
        }

        CML_SAFE_FN_CALL(func, a, &fa);
        CML_SAFE_FN_CALL(func, b, &fb);

        for (i = 0; i < n_max; i++)
        {
                c = (a + b)/2.0;
                CML_SAFE_FN_CALL(func, c, &fc);

                if (fc < 0.0)
                {
                        a = c;
                        fa = fc;
                }
                else
                {
                        b = c;
                        fb = fc;
                }

                if (cml_abs(b - a) < epsabs + epsrel * cml_abs(a))
                {
                        break;
                }
        }

        *res = (a + b)/2.0;

        if (i == n_max)
        {
                return SCIC_FAILURE;
        }

        return SCIC_SUCCESS;
}
