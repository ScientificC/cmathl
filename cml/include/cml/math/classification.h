#ifndef CML_REAL_CLA_FUNC_H
#define CML_REAL_CLA_FUNC_H

__CML_BEGIN_DECLS

int cml_cmp(double x1, double x2, double epsilon);
bool cml_equal(double x, double y);
bool cml_nearequal(double x, double y, double epsilon);
bool cml_isfinite(double x);
bool cml_isgreaterequal(double x, double y);
bool cml_isgreater(double x, double y);
bool cml_isinf(double x);
bool cml_isinteger(double x);
bool cml_islessequal(double x, double y);
bool cml_isless(double x, double y);
bool cml_ismult(double x, double y);
bool cml_isnatural(double x);
bool cml_isnan(double x);
bool cml_isnull(double x);

__CML_END_DECLS

#endif
