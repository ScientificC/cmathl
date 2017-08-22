#ifndef COMPLEX_FUNC_H
#define COMPLEX_FUNC_H

real complex_abs(complex);
real complex_arg(complex);

complex complex_add(complex, complex);
complex complex_prod(complex, complex);
complex complex_scalar_prod(complex, real);
complex complex_sub(complex, complex);
complex complex_div(complex, complex);
complex complex_inverse(complex);
complex complex_conjugate(complex);
complex complex_exp(complex);
complex complex_log(complex);
complex complex_log_b(complex, complex);
complex complex_sin(complex);
complex complex_cos(complex);
complex complex_tan(complex);
complex complex_sec(complex);
complex complex_csc(complex);
complex complex_cot(complex);
complex complex_sinh(complex);
complex complex_cosh(complex);
complex complex_tanh(complex);

#endif
