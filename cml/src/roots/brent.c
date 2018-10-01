#include <stdio.h>
#include <stdlib.h>
#include <scic/errno.h>
#include <cml/math.h>
#include <cml/roots.h>


/**
 * Search for the root of func in the interval [x1, x2] with a
 * given tolerance
 *
 * @param func a cml_function_t wrapper for the true function under investigation
 * @param x1 lower bound for the root
 * @param x2 upper bound for the root
 * @param tol on input gives the tolerance below with the algorithm stops. On
 * exit contains the maximum error made on the root.
 */

double
cml_root_brent(cml_function_t *func, double x1, double x2, double *tol)
{
        int iter, ITMAX = 100;
        double a, b, c, prev_step, new_step;
        double fa, fb, fc;
        double p, q, r, s, tol1;

        a = x1;
        b = x2;
        c = a;
        fa = CML_FN_EVAL(func, a);
        fb = CML_FN_EVAL(func, b);
        fc = fa;
        prev_step = b - a;

        if ((fa > 0.0 && fb > 0.0) || (fa < 0.0 && fb < 0.0))
        {
                SCIC_ERROR("roots must be bracketed", SCIC_EINVAL);
        }

        /* Test if one the endpoints is the root */
        if (fa == 0.0)
        {
                *tol = 0.0;
                return a;
        }
        if (fb == 0.0)
        {
                *tol = 0.0;
                return b;
        }

        for (iter = 1; iter <= ITMAX; iter++)
        {
                prev_step =  b - a;
                if (cml_abs(fc) < cml_abs(fb))
                {
                        a = b;
                        b = c;
                        c = a;

                        fa = fb;
                        fb = fc;
                        fc = fa;
                }

                tol1 = 2.0 * CML_DBL_EPSILON * cml_abs(b) + 0.5 * (double) *tol;
                new_step = 0.5 * (c - b);

                if (cml_abs(new_step) <= tol1 || fb == 0.0)
                {
                        *tol = cml_abs(c - b);
                        return b;
                }

                /* decide if the interpolation can be tried. if prev_step was
                 * large enough and in the right direction
                 */
                if (cml_abs(prev_step) >= tol1 && cml_abs(fa) > cml_abs(fb))
                {
                        s = fb / fa;

                        if (a == c)
                        {
                                /* if we only have two distinct points, only linear
                                 * interpolation can be applied
                                 */
                                p = 2.0 * new_step * s;
                                q = 1.0 - s;
                        }
                        else
                        {
                                /* Quadratic inverse interpolation */
                                q = fa / fc;
                                r = fb / fc;
                                p = s * (2.0 * new_step * q * (q - r) - (b - a) * (r - 1.0));
                                q = (q - 1.0) * (r - 1.0) * (s - 1.0);
                        }

                        /* p was calculated with the oppposite sign; make p positive and
                         * assign the possible minus to q
                         */
                        if (p > 0.0)
                        {
                                q = -q;
                        }
                        else
                        {
                                p = -p;
                        }

                        /* if b+p/q falls in [b,c] and isn't too large, it is accepted. If
                         * p/q is too large the the bisection procedure can reduce [b,c] more
                         * significantly
                         */
                        if (2.0 * p < 3.0 * new_step * q - cml_abs(tol1 * q) &&
                            2. * p < cml_abs(prev_step * q))
                        {
                                new_step = p / q;
                        }
                        else
                        {
                                new_step = 0.5 * (c - b);
                                prev_step = new_step;
                        }
                }

                /* adjust the step to be not less than tolerance */
                if (cml_abs(new_step) < tol1)
                {
                        new_step = (new_step > 0 ? tol1 : -tol1);
                }

                a = b;
                fa = fb;
                b += new_step;
                fb = CML_FN_EVAL(func, b);

                /* adjust c to have the opposite sign of b */
                if ((fb < 0 && fc < 0) || (fb > 0 && fc > 0))
                {
                        c = a;
                        fc = fa;
                }
        }

        *tol = cml_abs(c - b);
        return b;
}
