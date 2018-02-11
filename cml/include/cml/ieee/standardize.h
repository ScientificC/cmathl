#ifndef CML_H
#error "Never use <cml/ieee/standardize.h> directly; include <cml.h> instead."
#endif

#ifndef CML_IEEE_STAN_H
#define CML_IEEE_STAN_H

__CML_BEGIN_DECLS

void make_float_bigendian(float *x);
void make_double_bigendian(double *x);

__CML_END_DECLS

#endif
