#include <stdlib.h>
#include <cml/math.h>
#include <cml/quaternion.h>


cml_quaternion_t
cml_quaternion_slerp(cml_quaternion_t q1, cml_quaternion_t q2, double tau)
{
        if (cml_quaternion_rotor_chordal_distance(q1,q2) <= 1.414213562373096)
        {
                return cml_quaternion_multiply(
                        cml_quaternion_pow_scalar(
                                cml_quaternion_divide(q2,q1), tau
                                ), q1
                        );
        }
        else
        {
                return cml_quaternion_multiply(
                        cml_quaternion_pow_scalar(
                                cml_quaternion_divide(
                                        cml_quaternion_opposite(q2),
                                        q1
                                        ),
                                tau
                                ), q1
                        );
        }
}


cml_quaternion_t
cml_quaternion_squad_evaluate(
        double tau_i,
        cml_quaternion_t q_i,
        cml_quaternion_t a_i,
        cml_quaternion_t b_ip1,
        cml_quaternion_t q_ip1
        )
{
        return cml_quaternion_slerp(cml_quaternion_slerp(q_i, q_ip1, tau_i),
                                    cml_quaternion_slerp(a_i, b_ip1, tau_i),
                                    2.0*tau_i*(1.0 - tau_i));
}
