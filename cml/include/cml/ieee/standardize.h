#ifndef CML_H
#error "Never use <cml/ieee/standardize.h> directly; include <cml/ieee.h> instead."
#endif

#ifndef CML_IEEE754_STAN_H
#define CML_IEEE754_STAN_H

__CML_BEGIN_DECLS

void cml_make_float_bigendian(float *x);
void cml_make_double_bigendian(double *x);

__CML_END_DECLS

#endif
