#ifndef CML_STRUCTURES_TYPES_QUATERNION_H
#define CML_STRUCTURES_TYPES_QUATERNION_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

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

#include <cml/quaternion/basic.h>
#include <cml/quaternion/classification.h>
#include <cml/quaternion/exponentiation.h>
#include <cml/quaternion/interpolation.h>
#include <cml/quaternion/parity.h>
#include <cml/quaternion/rotation.h>

#endif
