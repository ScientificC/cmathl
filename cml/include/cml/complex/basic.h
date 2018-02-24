#ifndef CML_COMPLEX_BASIC_FUNC_H
#define CML_COMPLEX_BASIC_FUNC_H

__CML_BEGIN_DECLS

double cml_complex_abs(cml_complex_t);
double cml_complex_arg(cml_complex_t);
double cml_complex_logabs(cml_complex_t);

cml_complex_t cml_complex_add(cml_complex_t, cml_complex_t);
cml_complex_t cml_complex_conj(cml_complex_t);
cml_complex_t cml_complex_div(cml_complex_t, cml_complex_t);
cml_complex_t cml_complex_inverse(cml_complex_t);
cml_complex_t cml_complex_mul(cml_complex_t, cml_complex_t);
cml_complex_t cml_complex_scalar_mul(cml_complex_t, double);
cml_complex_t cml_complex_sub(cml_complex_t, cml_complex_t);

cml_complex_t cml_complex_add_real(cml_complex_t, double);  /* r=a+x */
cml_complex_t cml_complex_sub_real(cml_complex_t, double);  /* r=a-x */
cml_complex_t cml_complex_mul_real(cml_complex_t, double);  /* r=a*x */
cml_complex_t cml_complex_div_real(cml_complex_t, double);  /* r=a/x */

cml_complex_t cml_complex_add_imag(cml_complex_t, double);  /* r=a+iy */
cml_complex_t cml_complex_sub_imag(cml_complex_t, double);  /* r=a-iy */
cml_complex_t cml_complex_mul_imag(cml_complex_t, double);  /* r=a*iy */
cml_complex_t cml_complex_div_imag(cml_complex_t, double);  /* r=a/iy */

__CML_END_DECLS

#endif
