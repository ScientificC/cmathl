#ifndef CML_REAL_EXP_FUNC_H
#define CML_REAL_EXP_FUNC_H

__CML_BEGIN_DECLS

double cml_exp(double);
double cml_expm1(double x);
double cml_ldexp(double x, int e);
double cml_frexp(double x, int *e);
double cml_log(double);
double cml_log_b(double, double);
double cml_log1p(double);

__CML_END_DECLS

#endif
