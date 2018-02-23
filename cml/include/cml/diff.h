#ifndef CML_H
#error "Never use <cml/diff.h> directly; include <cml.h> instead."
#endif

#ifndef CML_DIFF_H
#define CML_DIFF_H

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
