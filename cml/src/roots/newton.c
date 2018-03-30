#include <stdlib.h>
#include <cml/errno.h>
#include <cml/math.h>
#include <cml/roots.h>

/**
 * Find the root of a function using Newton's algorithm with the Armijo line
 * search to ensure the absolute value of the function decreases along the
 * iterations.  The descent direction at step k is given by
 *
 *     \f[ d_k = f(x_k) / f'(x_k) \f]
 *
 * Determine \f$ \alpha_k = \max\{2^{-j}, j \ge 0\} \f$ s.t.
 *
 *   \f[  f(x_k + \alpha_k d_k) \le f(x_k) (1 - \omega \alpha_k) \f]
 *
 * where in this implementation \f$ \omega = 10^{-4} \f$.
 *
 * @param cml_function_fdf_t pointer
 * @param x0 initial guess
 * @param x_eps if the relative improvement over the root is less than this value,
 * then stop;
 * @param fx_eps if |f(x)| < fx_eps * then stop;
 * @param n_max maximum number of iterations
 * @param res contains the root on exit
 * @return CML_SUCCESS or CML_FAILURE if n_max reached
 */
int
cml_root_newton(cml_function_fdf_t *func, double x0,
                double x_eps, double fx_eps,
                int n_max, double *res)
{
        int i;
        double omega, gamma;
        double f, df, root;

        omega = 1E-4;
        gamma = 0.5;
        root = x0;

        CML_FN_FDF_EVAL_F_DF(func, root, &f, &df);

        for (i = 0; i < n_max; i++)
        {
                double dx, t;
                double norm0, norm;

                t = 1.0;

                if (df == 0.0)
                {
                        CML_ERROR("div by zero", CML_EZERODIV);
                }

                dx = f / df;
                norm0 = cml_abs(f);

                /* Armijo line search */
                while (t > CML_DBL_EPSILON)
                {
                        double x_linesearch;
                        x_linesearch = root - t * dx;

                        CML_FN_FDF_EVAL_F_DF(func, x_linesearch, &f, &df);

                        norm = cml_abs(f);

                        if (norm < norm0 * (1.0 - omega * t))
                        {
                                root = x_linesearch;
                                break;
                        }

                        t *= gamma;
                }

                if (cml_abs(dx) < x_eps * cml_abs(root) || norm < fx_eps)
                {
                        break;
                }
        }

        *res = root;

        /* maximum number of iterations reached */
        if (i == n_max)
        {
                return CML_FAILURE;
        }

        return CML_SUCCESS;
}
