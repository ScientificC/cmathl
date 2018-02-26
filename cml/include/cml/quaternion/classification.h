#ifndef CML_QUATERNION_CLAS_FUNC_H
#define CML_QUATERNION_CLAS_FUNC_H

__CML_BEGIN_DECLS

bool cml_quaternion_isnan(cml_quaternion_t q);
bool cml_quaternion_nonzero(cml_quaternion_t q);
bool cml_quaternion_isinf(cml_quaternion_t q);
bool cml_quaternion_isfinite(cml_quaternion_t q);
bool cml_quaternion_equal(cml_quaternion_t q1, cml_quaternion_t q2);
bool cml_quaternion_isless(cml_quaternion_t q1, cml_quaternion_t q2);
bool cml_quaternion_isgreater(cml_quaternion_t q1, cml_quaternion_t q2);
bool cml_quaternion_islessequal(cml_quaternion_t q1, cml_quaternion_t q2);
bool cml_quaternion_isgreaterequal(cml_quaternion_t q1, cml_quaternion_t q2);

__CML_END_DECLS

#endif
