#ifndef CML_QUATERNION_INT_H
#define CML_QUATERNION_INT_H

__CML_BEGIN_DECLS

cml_quaternion_t cml_quaternion_lerp(cml_quaternion_t start, cml_quaternion_t end, double tau);
cml_quaternion_t cml_quaternion_nlerp(cml_quaternion_t start, cml_quaternion_t end, double tau);
cml_quaternion_t cml_quaternion_slerp(cml_quaternion_t start, cml_quaternion_t end, double tau);
cml_quaternion_t cml_quaternion_squad(
        double tau_i,
        cml_quaternion_t q_i,
        cml_quaternion_t a_i,
        cml_quaternion_t b_ip1,
        cml_quaternion_t q_ip1);

__CML_END_DECLS

#endif
