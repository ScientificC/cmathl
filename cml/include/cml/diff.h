#ifndef CML_DIFF_H
#define CML_DIFF_H

#define CML_H
#include <cml/default.h>
#include <cml/inline.h>
#include <cml/machine.h>
#include <cml/math.h>


__CML_BEGIN_DECLS

int diff_central(const function_t *f,
                 double x,
                 double *result, double *abserr);

int diff_backward(const function_t *f,
                  double x,
                  double *result, double *abserr);

int diff_forward(const function_t *f,
                 double x,
                 double *result, double *abserr);

__CML_END_DECLS

#endif
