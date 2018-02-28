#include <stdlib.h>
#include <cml/math.h>
#include <cml/quaternion.h>


double
cml_quaternion_rotor_intrinsic_distance(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return 2.0*cml_quaternion_abs(cml_quaternion_log(cml_quaternion_divide(q1,q2)));
}


double
cml_quaternion_rotor_chordal_distance(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return cml_quaternion_abs(cml_quaternion_subtract(q1,q2));
}


double
cml_quaternion_rotation_intrinsic_distance(cml_quaternion_t q1, cml_quaternion_t q2)
{
        if (cml_quaternion_rotor_chordal_distance(q1,q2) <= 1.414213562373096)
        {
                return 2.0*cml_quaternion_abs(
                        cml_quaternion_log(
                                cml_quaternion_divide(q1,q2)
                                )
                        );
        }
        else
        {
                return 2.0*cml_quaternion_abs(
                        cml_quaternion_log(
                                cml_quaternion_divide(
                                        q1,
                                        cml_quaternion_opposite(q2)
                                        )
                                )
                        );
        }
}


double
cml_quaternion_rotation_chordal_distance(cml_quaternion_t q1, cml_quaternion_t q2)
{
        if (cml_quaternion_rotor_chordal_distance(q1,q2) <= 1.414213562373096)
        {
                return cml_quaternion_abs(cml_quaternion_subtract(q1,q2));
        }
        else
        {
                return cml_quaternion_abs(cml_quaternion_add(q1,q2));
        }
}
