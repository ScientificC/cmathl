#ifndef CML_QUATERNION_BASIC_FUNC_H
#define CML_QUATERNION_BASIC_FUNC_H

__CML_BEGIN_DECLS

void quaternion_inplace_add_scalar(quaternion_t*, real_t);
void quaternion_inplace_add(quaternion_t*, quaternion_t);
void quaternion_inplace_divide_scalar(quaternion_t*, real_t);
void quaternion_inplace_divide(quaternion_t*, quaternion_t);
void quaternion_inplace_multiply_scalar(quaternion_t*, real_t);
void quaternion_inplace_multiply(quaternion_t*, quaternion_t);
void quaternion_inplace_scalar_multiply(real_t, quaternion_t*);
void quaternion_inplace_scalar_add(real_t, quaternion_t*);
void quaternion_inplace_subtract_scalar(quaternion_t*, real_t);
void quaternion_inplace_subtract(quaternion_t*, quaternion_t);

quaternion_t quaternion_add_scalar(quaternion_t, real_t);
quaternion_t quaternion_add(quaternion_t, quaternion_t);
quaternion_t quaternion_conj(quaternion_t);
quaternion_t quaternion_divide_scalar(quaternion_t, real_t);
quaternion_t quaternion_divide(quaternion_t, quaternion_t);
quaternion_t quaternion_inverse(quaternion_t);
quaternion_t quaternion_multiply_scalar(quaternion_t, real_t);
quaternion_t quaternion_multiply(quaternion_t, quaternion_t);
quaternion_t quaternion_normalized(quaternion_t);
quaternion_t quaternion_opposite(quaternion_t);
quaternion_t quaternion_scalar_add(real_t, quaternion_t);
quaternion_t quaternion_scalar_divide(real_t, quaternion_t);
quaternion_t quaternion_scalar_multiply(real_t, quaternion_t q);
quaternion_t quaternion_scalar_subtract(real_t, quaternion_t);
quaternion_t quaternion_subtract_scalar(quaternion_t, real_t);
quaternion_t quaternion_subtract(quaternion_t, quaternion_t);

real_t quaternion_norm(quaternion_t);
real_t quaternion_abs(quaternion_t);
real_t quaternion_angle(quaternion_t);

__CML_END_DECLS

#endif
