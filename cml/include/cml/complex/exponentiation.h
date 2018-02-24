#ifndef CML_COMPLEX_EXP_FUNC_H
#define CML_COMPLEX_EXP_FUNC_H

__CML_BEGIN_DECLS

complex_t complex_exp(complex_t);
complex_t complex_log_b(complex_t, complex_t);
complex_t complex_log(complex_t);
complex_t complex_sqrt(complex_t);
complex_t complex_sqrt_real(double);
complex_t complex_pow(complex_t, complex_t);
complex_t complex_pow_real(complex_t, double);

__CML_END_DECLS

#endif
