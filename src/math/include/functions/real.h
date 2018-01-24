#ifndef CML_REAL_FUNC_H
#define CML_REAL_FUNC_H

bool real_equals(real_t, real_t);
bool real_is_null(real_t);
bool real_is_natural(real_t);
bool real_is_integer(real_t);
bool real_is_greater(real_t, real_t);
bool real_is_less(real_t, real_t);
bool real_is_greater_or_equals(real_t, real_t);
bool real_is_less_or_equals(real_t, real_t);
bool real_is_mult(real_t, real_t);

real_t real_add(real_t, real_t);
real_t real_prod(real_t, real_t);
real_t real_sub(real_t, real_t);
real_t real_div(real_t, real_t);
real_t real_sgn(real_t);
real_t real_abs(real_t);
real_t real_floor(real_t);
real_t real_ceil(real_t);
real_t real_div_e(real_t, real_t);
real_t real_mod(real_t, real_t);
real_t real_inverse(real_t);
real_t real_opposite(real_t);
real_t real_ared(real_t);
real_t real_fact(real_t);
real_t real_exp(real_t);
real_t real_ln(real_t);
real_t real_log_b(real_t, real_t);
real_t real_pow(real_t, real_t);
real_t real_root(real_t, real_t);
real_t real_sqrt(real_t);
real_t real_sin(real_t);
real_t real_cos(real_t);
real_t real_tan(real_t);
real_t real_sec(real_t);
real_t real_csc(real_t);
real_t real_cot(real_t);
real_t real_asin(real_t);
real_t real_acos(real_t);
real_t real_atan(real_t);
real_t real_atan2(real_t, real_t);
real_t real_sinh(real_t);
real_t real_cosh(real_t);
real_t real_tanh(real_t);
real_t real_sech(real_t);
real_t real_csch(real_t);
real_t real_coth(real_t);
real_t real_asinh(real_t);
real_t real_acosh(real_t);
real_t real_atanh(real_t);

#endif
