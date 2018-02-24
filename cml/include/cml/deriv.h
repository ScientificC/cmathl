#ifndef CML_DERIV_H
#define CML_DERIV_H

#define CML_H
#include "default.h"
#include "inline.h"
#include "machine.h"
#include "math.h"

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
