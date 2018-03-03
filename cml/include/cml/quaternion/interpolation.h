#ifndef CML_QUATERNION_INT_H
#define CML_QUATERNION_INT_H

__BEGIN_DECLS

cml_quaternion_t cml_quaternion_slerp(cml_quaternion_t q1, cml_quaternion_t q2, double tau);
cml_quaternion_t cml_quaternion_squad(
        double tau_i,
        cml_quaternion_t q_i,
        cml_quaternion_t a_i,
        cml_quaternion_t b_ip1,
        cml_quaternion_t q_ip1);

__END_DECLS

#endif
