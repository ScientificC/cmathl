#ifndef CML_QUATERNION_EXP_FUNC_H
#define CML_QUATERNION_EXP_FUNC_H

__CML_BEGIN_DECLS

void cml_quaternion_inplace_pow_scalar(cml_quaternion_t*, double);
void cml_quaternion_inplace_pow(cml_quaternion_t*, cml_quaternion_t);
void cml_quaternion_inplace_scalar_pow(double, cml_quaternion_t*);

cml_quaternion_t cml_quaternion_exp(cml_quaternion_t);
cml_quaternion_t cml_quaternion_log(cml_quaternion_t);
cml_quaternion_t cml_quaternion_pow_scalar(cml_quaternion_t, double);
cml_quaternion_t cml_quaternion_pow(cml_quaternion_t, cml_quaternion_t);
cml_quaternion_t cml_quaternion_scalar_pow(double, cml_quaternion_t);
cml_quaternion_t cml_quaternion_sqrt(cml_quaternion_t);

__CML_END_DECLS

#endif
