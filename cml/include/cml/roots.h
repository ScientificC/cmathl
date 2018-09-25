#ifndef CML_ROOTS_H
#define CML_ROOTS_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

#include <stddef.h>
#include <cml/math.h>

__CML_BEGIN_DECLS

double cml_root_brent(cml_function_t *func, double x1, double x2, double *tol);

int cml_root_newton_bisection(cml_function_fdf_t *func, double x_min,
                              double x_max, double tol, int n_max,
                              double *res);

int cml_root_newton(cml_function_fdf_t *func, double x0,
                    double epsrel, double epsabs,
                    int n_max, double *res);

int cml_root_bisection(cml_function_t *funcunc, double xmin, double xmax,
                       double epsrel, double epsabs, size_t n_max,
                       double *res);

int cml_multiroot_newton(cml_function_vec_t *funcunc, const double *x0,
                         double x_eps, double fx_eps, int n_max,
                         bool verbose, double *res);

int cml_root_fsolve(cml_function_vec_t *func, double *x, double *fx,
                    double xtol, int maxfev, int *nfev,
                    double *scale, int error_msg);

int cml_root_fsolve_lsq(cml_function_vec_t *func, double *x, int m,
                        double *fx,  double xtol, double ftol,
                        double gtol, int maxfev, int *nfev,
                        double *scale, int error_msg);

__CML_END_DECLS

/* Call the pointed-to function with argument x, put its result in y, and
 * return an error if the function value is Inf/Nan.
 */

#define CML_SAFE_FN_CALL(_f, _x, _yp)                                   \
        do {                                                            \
                *(_yp) = CML_FN_EVAL(_f, _x);                           \
                if (!cml_isfinite(*(_yp)))                              \
                        SCIC_ERROR("function value is not finite",      \
                                   SCIC_EBADFUNC);                      \
        } while (0)

#endif
