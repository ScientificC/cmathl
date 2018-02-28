#ifndef CML_DIFF_H
#define CML_DIFF_H

#define CML_H
#include <cml/default.h>
#include <cml/inline.h>
#include <cml/machine.h>
#include <cml/math.h>


__CML_BEGIN_DECLS

int cml_diff_central(const cml_function_t *f,
                     double x,
                     double *result, double *abserr);

int cml_diff_backward(const cml_function_t *f,
                      double x,
                      double *result, double *abserr);

int cml_diff_forward(const cml_function_t *f,
                     double x,
                     double *result, double *abserr);

__CML_END_DECLS

#endif
