#ifndef CML_REAL_EXP_FUNC_H
#define CML_REAL_EXP_FUNC_H

__CML_BEGIN_DECLS

real_t real_exp(real_t);
real_t real_expm1(real_t x);
real_t real_ldexp(real_t x, int e);
real_t real_frexp(real_t x, int *e);
real_t real_log(real_t);
real_t real_log_b(real_t, real_t);
real_t real_log1p(real_t);

__CML_END_DECLS

#endif
