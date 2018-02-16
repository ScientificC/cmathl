#ifndef CML_H
#error "Never use <cml/deriv.h> directly; include <cml.h> instead."
#endif

#ifndef CML_DERIV_H
#define CML_DERIV_H

__CML_BEGIN_DECLS

int deriv_central(const function_t *f,
                  real_t x, real_t h,
                  real_t *result, real_t *abserr);

int deriv_backward(const function_t *f,
                   real_t x, real_t h,
                   real_t *result, real_t *abserr);

int deriv_forward(const function_t *f,
                  real_t x, real_t h,
                  real_t *result, real_t *abserr);

__CML_END_DECLS

#endif
