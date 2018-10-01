#ifndef CML_COMPLEX_EXP_FUNC_H
#define CML_COMPLEX_EXP_FUNC_H

__CML_BEGIN_DECLS

cml_complex_t cml_complex_exp(cml_complex_t z);
cml_complex_t cml_complex_log_b(cml_complex_t z, cml_complex_t b);
cml_complex_t cml_complex_log(cml_complex_t z);
cml_complex_t cml_complex_sqrt(cml_complex_t a);
cml_complex_t cml_complex_sqrt_real(double x);
cml_complex_t cml_complex_pow(cml_complex_t a, cml_complex_t b);
cml_complex_t cml_complex_pow_real(cml_complex_t a, double b);

__CML_END_DECLS

#endif
