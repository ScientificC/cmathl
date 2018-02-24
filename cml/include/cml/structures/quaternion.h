#ifndef CML_H
#error "Never use <cml/structures/quaternion.h> directly; include <cml.h> instead."
#endif

#ifndef CML_STRUCTURES_TYPES_QUATERNION_H
#define CML_STRUCTURES_TYPES_QUATERNION_H

typedef struct
{
        union
        {
                double q[4];
                struct
                {
                        double w, x, y, z;
                };
                struct
                {
                        double a, i, j, k;
                };
        };
} cml_quaternion_t;

#define __CML_QUATERNION_EPS 1e-14

__CML_BEGIN_DECLS

cml_quaternion_t quaternion(double, double, double, double);
cml_quaternion_t cml_quaternion_clone(cml_quaternion_t);
cml_quaternion_t cml_quaternion_identity();
cml_quaternion_t cml_quaternion_from_axis_anglef3(double, double, double, double);
cml_quaternion_t cml_quaternion_from_spherical_coords(double, double);
cml_quaternion_t cml_quaternion_from_euler_angles(double, double, double);

__CML_END_DECLS

#include <cml/structures/quaternion/basic.h>
#include <cml/structures/quaternion/classification.h>
#include <cml/structures/quaternion/exponentiation.h>
#include <cml/structures/quaternion/parity.h>

#endif
