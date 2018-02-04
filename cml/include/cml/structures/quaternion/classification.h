#ifndef CML_QUATERNION_CLAS_FUNC_H
#define CML_QUATERNION_CLAS_FUNC_H

bool quaternion_isnan(quaternion_t q);
bool quaternion_nonzero(quaternion_t q);
bool quaternion_isinf(quaternion_t q);
bool quaternion_isfinite(quaternion_t q);
bool quaternion_equal(quaternion_t q1, quaternion_t q2);
bool quaternion_isless(quaternion_t q1, quaternion_t q2);
bool quaternion_isgreater(quaternion_t q1, quaternion_t q2);
bool quaternion_islessequal(quaternion_t q1, quaternion_t q2);
bool quaternion_isgreaterequal(quaternion_t q1, quaternion_t q2);

#endif
