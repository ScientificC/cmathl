#ifndef CML_REAL_EXP_FUNC_H
#define CML_REAL_EXP_FUNC_H

__CML_BEGIN_DECLS

double cml_exp(double x);
double cml_expm1(double x);
double cml_ldexp(double x, int e);
double cml_frexp(double x, int *e);
double cml_log(double x);
double cml_log_b(double x, double b);
double cml_log1p(double x);

__CML_END_DECLS

#endif
