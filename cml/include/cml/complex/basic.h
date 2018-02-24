#ifndef CML_COMPLEX_BASIC_FUNC_H
#define CML_COMPLEX_BASIC_FUNC_H

__CML_BEGIN_DECLS

double complex_abs(complex_t);
double complex_arg(complex_t);
double complex_logabs(complex_t);

complex_t complex_add(complex_t, complex_t);
complex_t complex_conj(complex_t);
complex_t complex_div(complex_t, complex_t);
complex_t complex_inverse(complex_t);
complex_t complex_mul(complex_t, complex_t);
complex_t complex_scalar_mul(complex_t, double);
complex_t complex_sub(complex_t, complex_t);

complex_t complex_add_real(complex_t, double);  /* r=a+x */
complex_t complex_sub_real(complex_t, double);  /* r=a-x */
complex_t complex_mul_real(complex_t, double);  /* r=a*x */
complex_t complex_div_real(complex_t, double);  /* r=a/x */

complex_t complex_add_imag(complex_t, double);  /* r=a+iy */
complex_t complex_sub_imag(complex_t, double);  /* r=a-iy */
complex_t complex_mul_imag(complex_t, double);  /* r=a*iy */
complex_t complex_div_imag(complex_t, double);  /* r=a/iy */

__CML_END_DECLS

#endif
