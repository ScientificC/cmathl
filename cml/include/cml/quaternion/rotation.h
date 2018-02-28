#ifndef CML_QUATERNION_ROT_H
#define CML_QUATERNION_ROT_H

__BEGIN_DECLS

double cml_quaternion_rotor_intrinsic_distance(cml_quaternion_t q1, cml_quaternion_t q2);
double cml_quaternion_rotor_chordal_distance(cml_quaternion_t q1, cml_quaternion_t q2);
double cml_quaternion_rotation_intrinsic_distance(cml_quaternion_t q1, cml_quaternion_t q2);
double cml_quaternion_rotation_chordal_distance(cml_quaternion_t q1, cml_quaternion_t q2);

__END_DECLS

#endif
