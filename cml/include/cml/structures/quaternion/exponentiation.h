#ifndef CML_QUATERNION_EXP_FUNC_H
#define CML_QUATERNION_EXP_FUNC_H

__CML_BEGIN_DECLS

void quaternion_inplace_pow_scalar(quaternion_t*, double);
void quaternion_inplace_pow(quaternion_t*, quaternion_t);
void quaternion_inplace_scalar_pow(double, quaternion_t*);

quaternion_t quaternion_exp(quaternion_t);
quaternion_t quaternion_log(quaternion_t);
quaternion_t quaternion_pow_scalar(quaternion_t, double);
quaternion_t quaternion_pow(quaternion_t, quaternion_t);
quaternion_t quaternion_scalar_pow(double, quaternion_t);
quaternion_t quaternion_sqrt(quaternion_t);

__CML_END_DECLS

#endif
