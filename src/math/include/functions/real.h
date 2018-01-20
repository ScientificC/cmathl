#ifndef CML_REAL_FUNC_H
#define CML_REAL_FUNC_H

bool __isgreater(mfloat_t, mfloat_t);
bool __isless(mfloat_t, mfloat_t);
bool __isinteger(mfloat_t);
bool __isnatural(mfloat_t);
bool __ismult(mfloat_t, mfloat_t);

bool real_equals(real, real);
bool real_isnull(real);
bool real_isnatural(real);
bool real_isinteger(real);
bool real_isgreater(real, real);
bool real_isless(real, real);
bool real_isgreater_or_equals(real, real);
bool real_isless_or_equals(real, real);
bool real_ismult(real, real);

real real_add(real, real);
real real_prod(real, real);
real real_sub(real, real);
real real_div(real, real);
real real_sgn(real);
real real_abs(real);
real real_floor(real);
real real_ceil(real);
real real_div_e(real, real);
real real_mod(real, real);
real real_inverse(real);
real real_opposite(real);
real real_ared(real);
real real_fact(real);
real real_exp(real);
real real_ln(real);
real real_log_b(real, real);
real real_pow(real, real);
real real_root(real, real);
real real_sqrt(real);
real real_sin(real);
real real_cos(real);
real real_tan(real);
real real_sec(real);
real real_csc(real);
real real_cot(real);
real real_asin(real);
real real_acos(real);
real real_atan(real);
real real_atan2(real, real);
real real_sinh(real);
real real_cosh(real);
real real_tanh(real);
real real_sech(real);
real real_csch(real);
real real_coth(real);
real real_asinh(real);
real real_acosh(real);
real real_atanh(real);

#endif
