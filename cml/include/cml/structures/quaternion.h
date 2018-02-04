#ifndef CML_H
#error "Never use <cml/structures/quaternion.h> directly; include <cml.h> instead."
#endif

#ifndef CML_STRUCTURES_TYPES_QUATERNION_H
#define CML_STRUCTURES_TYPES_QUATERNION_H

typedef struct _quaternion
{
        union
        {
                real_t q[4];
                struct
                {
                        real_t w, x, y, z;
                };
                struct
                {
                        real_t a, i, j, k;
                };
        };
} quaternion_t;

#define _CML_QUATERNION_EPS 1e-14

quaternion_t quaternion_identity();
quaternion_t quaternion(real_t, real_t, real_t, real_t);
quaternion_t quaternion_clone(quaternion_t);
quaternion_t quaternion_from_axis_anglef3(real_t, real_t, real_t, real_t);
quaternion_t quaternion_from_spherical_coords(real_t, real_t);
quaternion_t quaternion_from_euler_angles(real_t, real_t, real_t);

#include "quaternion/basic.h"
#include "quaternion/classification.h"
#include "quaternion/exponentiation.h"
#include "quaternion/parity.h"

#endif
