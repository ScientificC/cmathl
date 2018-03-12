#ifndef CML_REAL_CLA_FUNC_H
#define CML_REAL_CLA_FUNC_H

__CML_BEGIN_DECLS

bool cml_equal(double, double);
bool cml_nearequal(double x, double y, double epsilon);
bool cml_isfinite(double);
bool cml_isgreaterequal(double, double);
bool cml_isgreater(double, double);
bool cml_isinf(double);
bool cml_isinteger(double);
bool cml_islessequal(double, double);
bool cml_isless(double, double);
bool cml_ismult(double, double);
bool cml_isnatural(double);
bool cml_isnan(double);
bool cml_isnull(double);

__CML_END_DECLS

#endif
