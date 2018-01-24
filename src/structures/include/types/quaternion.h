#ifndef CML_H
#error "Never use <structures/include/types/quaternion.h> directly; include <cml.h> instead."
#endif

#ifndef CML_TYPES_QUATERNION_H
#define CML_TYPES_QUATERNION_H

typedef struct _quaternion
{
        union
        {
                real_t q[4];
                struct
                {
                        real_t x, y, z, w;
                };
                struct
                {
                        real_t i, j, k, a;
                };
        };
} quaternion_t;

typedef quaternion_t* quaternion;

#endif
