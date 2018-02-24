#ifndef CML_DERIV_H
#define CML_DERIV_H

#define CML_H
#include <cml/default.h>
#include <cml/inline.h>
#include <cml/machine.h>
#include <cml/math.h>

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
