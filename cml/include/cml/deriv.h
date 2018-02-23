#ifndef CML_H
#error "Never use <cml/deriv.h> directly; include <cml.h> instead."
#endif

#ifndef CML_DERIV_H
#define CML_DERIV_H

__CML_BEGIN_DECLS

int deriv_central(const function_t *f,
                  double x, double h,
                  double *result, double *abserr);

int deriv_backward(const function_t *f,
                   double x, double h,
                   double *result, double *abserr);

int deriv_forward(const function_t *f,
                  double x, double h,
                  double *result, double *abserr);

__CML_END_DECLS

#endif
