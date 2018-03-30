#include <stdlib.h>
#include <cml/math.h>
#include <cml/quaternion.h>


cml_quaternion_t
cml_quaternion_lerp(cml_quaternion_t start, cml_quaternion_t end, double tau)
{
        /* if tau is 0, return start */
        if (cml_isnull(tau))
        {
                return cml_quaternion_clone(start);
        }

        /* if tau is 1 return end */
        if (cml_equal(tau, 1.0))
        {
                return cml_quaternion_clone(end);
        }

        cml_quaternion_t qR;
        double f1, f2;

        f1 = 1.0 - tau;
        f2 = tau;

        /* this expanded form avoids calling cml_quaternion_multiply and
         * cml_quaternion_add
         */
        qR.w = f1 * start.w + f2 * end.w;
        qR.x = f1 * start.x + f2 * end.x;
        qR.y = f1 * start.y + f2 * end.y;
        qR.z = f1 * start.z + f2 * end.z;

        return qR;
}


cml_quaternion_t
cml_quaternion_nlerp(cml_quaternion_t start, cml_quaternion_t end, double tau)
{
        cml_quaternion_t qR = cml_quaternion_lerp(start, end, tau);
        return cml_quaternion_normalized(qR);
}


cml_quaternion_t
cml_quaternion_slerp(cml_quaternion_t start, cml_quaternion_t end, double tau)
{
        if (cml_quaternion_rotor_chordal_distance(start, end) <= M_SQRT2)
        {
                return cml_quaternion_multiply(
                        cml_quaternion_pow_scalar(
                                cml_quaternion_divide(end, start), tau
                                ), start
                        );
        }
        else
        {
                return cml_quaternion_multiply(
                        cml_quaternion_pow_scalar(
                                cml_quaternion_divide(
                                        cml_quaternion_opposite(end),
                                        start
                                        ),
                                tau
                                ), start
                        );
        }
}


cml_quaternion_t
cml_quaternion_squad(
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
