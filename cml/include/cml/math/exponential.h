#ifndef CML_REAL_EXP_FUNC_H
#define CML_REAL_EXP_FUNC_H

__CML_BEGIN_DECLS

double real_exp(double);
double real_expm1(double x);
double real_ldexp(double x, int e);
double real_frexp(double x, int *e);
double real_log(double);
double real_log_b(double, double);
double real_log1p(double);

__CML_END_DECLS

#endif
