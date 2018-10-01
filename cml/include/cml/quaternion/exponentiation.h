#ifndef CML_QUATERNION_EXP_FUNC_H
#define CML_QUATERNION_EXP_FUNC_H

__CML_BEGIN_DECLS

void cml_quaternion_inplace_pow_scalar(cml_quaternion_t *q, double s);
void cml_quaternion_inplace_pow(cml_quaternion_t *q, cml_quaternion_t q);
void cml_quaternion_inplace_scalar_pow(double s, cml_quaternion_t *q);

cml_quaternion_t cml_quaternion_exp(cml_quaternion_t q);
cml_quaternion_t cml_quaternion_log(cml_quaternion_t q);
cml_quaternion_t cml_quaternion_pow_scalar(cml_quaternion_t q, double s);
cml_quaternion_t cml_quaternion_pow(cml_quaternion_t q, cml_quaternion_t q);
cml_quaternion_t cml_quaternion_scalar_pow(double s, cml_quaternion_t q);
cml_quaternion_t cml_quaternion_sqrt(cml_quaternion_t q);

__CML_END_DECLS

#endif
