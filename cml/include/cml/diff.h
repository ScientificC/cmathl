#ifndef CML_DIFF_H
#define CML_DIFF_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#include <cml/math.h>
#undef _CML_COMMON_H_

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
