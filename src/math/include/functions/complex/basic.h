#ifndef CML_COMPLEX_BASIC_FUNC_H
#define CML_COMPLEX_BASIC_FUNC_H

real_t complex_abs(complex);
real_t complex_arg(complex);

complex complex_add(complex, complex);
complex complex_prod(complex, complex);
complex complex_scalar_prod(complex, real_t);
complex complex_sub(complex, complex);
complex complex_div(complex, complex);
complex complex_inverse(complex);
complex complex_conjugate(complex);

#endif
