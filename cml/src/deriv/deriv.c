#include <stdlib.h>
#include <cml/deriv.h>
#include <cml/errno.h>
#include <cml/math.h>

static void
central_deriv(const cml_function_t *f, double x, double h,
              double *result, double *abserr_round, double *abserr_trunc)
{
        /* Compute the derivative using the 5-point rule (x-h, x-h/2, x,
           x+h/2, x+h). Note that the central point is not used.
           Compute the error using the difference between the 5-point and
           the 3-point rule (x-h,x,x+h). Again the central point is not
           used. */

        double fm1 = FN_EVAL(f, x - h);
        double fp1 = FN_EVAL(f, x + h);

        double fmh = FN_EVAL(f, x - h / 2);
        double fph = FN_EVAL(f, x + h / 2);

        double r3 = 0.5 * (fp1 - fm1);
        double r5 = (4.0 / 3.0) * (fph - fmh) - (1.0 / 3.0) * r3;

        double e3 = (cml_abs(fp1) + cml_abs(fm1)) * CML_DBL_EPSILON;
        double e5 = 2.0 * (cml_abs(fph) + cml_abs(fmh)) * CML_DBL_EPSILON + e3;

        /* The next term is due to finite precision in x+h = O (eps * x) */

        double dy = CML_MAX(cml_abs(r3 / h), cml_abs(r5 / h)) *(cml_abs(x) / h) * CML_DBL_EPSILON;

        /* The truncation error in the r5 approximation itself is O(h^4).
           However, for safety, we estimate the error from r5-r3, which is
           O(h^2).  By scaling h we will minimise this estimated error, not
           the actual truncation error in r5. */

        *result = r5 / h;
        *abserr_trunc = cml_abs((r5 - r3) / h); /* Estimated truncation error O(h^2) */
        *abserr_round = cml_abs(e5 / h) + dy; /* Rounding error (cancellations) */
}

__CML_EXTERN_INLINE int
cml_deriv_central(const cml_function_t *f, double x, double h,
                  double *result, double *abserr)
{
        double r_0, round, trunc, error;
        central_deriv(f, x, h, &r_0, &round, &trunc);
        error = round + trunc;

        if (round < trunc && (round > 0 && trunc > 0))
        {
                double r_opt, round_opt, trunc_opt, error_opt;

                /* Compute an optimised stepsize to minimize the total error,
                   using the scaling of the truncation error (O(h^2)) and
                   rounding error (O(1/h)). */

                double h_opt = h * cml_pow(round / (2.0 * trunc), 1.0 / 3.0);
                central_deriv(f, x, h_opt, &r_opt, &round_opt, &trunc_opt);
                error_opt = round_opt + trunc_opt;

                /* Check that the new error is smaller, and that the new derivative
                   is consistent with the error bounds of the original estimate. */

                if (error_opt < error && cml_abs(r_opt - r_0) < 4.0 * error)
                {
                        r_0 = r_opt;
                        error = error_opt;
                }
        }

        *result = r_0;
        *abserr = error;

        return CML_SUCCESS;
}


static void
forward_deriv(const cml_function_t *f, double x, double h,
              double *result, double *abserr_round, double *abserr_trunc)
{
        /* Compute the derivative using the 4-point rule (x+h/4, x+h/2,
           x+3h/4, x+h).
           Compute the error using the difference between the 4-point and
           the 2-point rule (x+h/2,x+h).  */

        double f1 = FN_EVAL(f, x + h / 4.0);
        double f2 = FN_EVAL(f, x + h / 2.0);
        double f3 = FN_EVAL(f, x + (3.0 / 4.0) * h);
        double f4 = FN_EVAL(f, x + h);

        double r2 = 2.0*(f4 - f2);
        double r4 = (22.0 / 3.0) * (f4 - f3) - (62.0 / 3.0) * (f3 - f2) +
                    (52.0 / 3.0) * (f2 - f1);

        /* Estimate the rounding error for r4 */

        double e4 = 2 * 20.67 * (cml_abs(f4) + cml_abs(f3) + cml_abs(f2) + cml_abs(f1)) * CML_DBL_EPSILON;

        /* The next term is due to finite precision in x+h = O (eps * x) */

        double dy = CML_MAX (cml_abs(r2 / h), cml_abs(r4 / h)) * cml_abs(x / h) * CML_DBL_EPSILON;

        /* The truncation error in the r4 approximation itself is O(h^3).
           However, for safety, we estimate the error from r4-r2, which is
           O(h).  By scaling h we will minimise this estimated error, not
           the actual truncation error in r4. */

        *result = r4 / h;
        *abserr_trunc = cml_abs((r4 - r2) / h); /* Estimated truncation error O(h) */
        *abserr_round = cml_abs(e4 / h) + dy;
}

__CML_EXTERN_INLINE int
cml_deriv_forward(const cml_function_t *f, double x, double h,
                  double *result, double *abserr)
{
        double r_0, round, trunc, error;
        forward_deriv(f, x, h, &r_0, &round, &trunc);
        error = round + trunc;

        if (round < trunc && (round > 0 && trunc > 0))
        {
                double r_opt, round_opt, trunc_opt, error_opt;

                /* Compute an optimised stepsize to minimize the total error,
                   using the scaling of the estimated truncation error (O(h)) and
                   rounding error (O(1/h)). */

                double h_opt = h * cml_pow(round / (trunc), 1.0 / 2.0);
                forward_deriv(f, x, h_opt, &r_opt, &round_opt, &trunc_opt);
                error_opt = round_opt + trunc_opt;

                /* Check that the new error is smaller, and that the new derivative
                   is consistent with the error bounds of the original estimate. */

                if (error_opt < error && cml_abs(r_opt - r_0) < 4.0 * error)
                {
                        r_0 = r_opt;
                        error = error_opt;
                }
        }

        *result = r_0;
        *abserr = error;

        return CML_SUCCESS;
}


__CML_EXTERN_INLINE int
cml_deriv_backward(const cml_function_t *f, double x, double h,
                   double *result, double *abserr)
{
        return cml_deriv_forward(f, x, -h, result, abserr);
}
