#ifndef CML_H
#error "Never use <cml/structures/quaternion.h> directly; include <cml.h> instead."
#endif

#ifndef CML_STRUCTURES_TYPES_QUATERNION_H
#define CML_STRUCTURES_TYPES_QUATERNION_H

typedef struct _quaternion
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
} quaternion_t;

#define __CML_QUATERNION_EPS 1e-14

__CML_BEGIN_DECLS

quaternion_t quaternion(double, double, double, double);
quaternion_t quaternion_clone(quaternion_t);
quaternion_t quaternion_identity();
quaternion_t quaternion_from_axis_anglef3(double, double, double, double);
quaternion_t quaternion_from_spherical_coords(double, double);
quaternion_t quaternion_from_euler_angles(double, double, double);

__CML_END_DECLS

#include "quaternion/basic.h"
#include "quaternion/classification.h"
#include "quaternion/exponentiation.h"
#include "quaternion/parity.h"

#endif
