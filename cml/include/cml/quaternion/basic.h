#ifndef CML_QUATERNION_BASIC_FUNC_H
#define CML_QUATERNION_BASIC_FUNC_H

__CML_BEGIN_DECLS

void cml_quaternion_inplace_add_scalar(cml_quaternion_t *q, double s);
void cml_quaternion_inplace_add(cml_quaternion_t *q1a, cml_quaternion_t q2);
void cml_quaternion_inplace_divide_scalar(cml_quaternion_t *q, double s);
void cml_quaternion_inplace_divide(cml_quaternion_t *q1a, cml_quaternion_t q2);
void cml_quaternion_inplace_multiply_scalar(cml_quaternion_t *q, double s);
void cml_quaternion_inplace_multiply(cml_quaternion_t *q1a, cml_quaternion_t q2);
void cml_quaternion_inplace_scalar_multiply(double s, cml_quaternion_t *q);
void cml_quaternion_inplace_scalar_add(double s, cml_quaternion_t *q);
void cml_quaternion_inplace_subtract_scalar(cml_quaternion_t *q, double s);
void cml_quaternion_inplace_subtract(cml_quaternion_t *q1a, cml_quaternion_t q2);

cml_quaternion_t cml_quaternion_add_scalar(cml_quaternion_t q, double s);
cml_quaternion_t cml_quaternion_add(cml_quaternion_t q1, cml_quaternion_t q2);
cml_quaternion_t cml_quaternion_conj(cml_quaternion_t q);
cml_quaternion_t cml_quaternion_divide_scalar(cml_quaternion_t q, double s);
cml_quaternion_t cml_quaternion_divide(cml_quaternion_t q1, cml_quaternion_t q2);
cml_quaternion_t cml_quaternion_inverse(cml_quaternion_t q);
cml_quaternion_t cml_quaternion_multiply_scalar(cml_quaternion_t q, double s);
cml_quaternion_t cml_quaternion_multiply(cml_quaternion_t q1, cml_quaternion_t q2);
cml_quaternion_t cml_quaternion_normalized(cml_quaternion_t q);
cml_quaternion_t cml_quaternion_opposite(cml_quaternion_t q);
cml_quaternion_t cml_quaternion_scalar_add(double s, cml_quaternion_t q);
cml_quaternion_t cml_quaternion_scalar_divide(double s, cml_quaternion_t q);
cml_quaternion_t cml_quaternion_scalar_multiply(double s, cml_quaternion_t q);
cml_quaternion_t cml_quaternion_scalar_subtract(double s, cml_quaternion_t q);
cml_quaternion_t cml_quaternion_subtract_scalar(cml_quaternion_t q, double s);
cml_quaternion_t cml_quaternion_subtract(cml_quaternion_t q1, cml_quaternion_t q2);

double cml_quaternion_norm(cml_quaternion_t q);
double cml_quaternion_abs(cml_quaternion_t q);
double cml_quaternion_angle(cml_quaternion_t q);

__CML_END_DECLS

#endif
