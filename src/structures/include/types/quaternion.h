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

bool quaternion_equals(const quaternion_t* self, const quaternion_t* vT);

quaternion_t* quaternion_identity(quaternion_t* self);
quaternion_t* quaternion_setf4(quaternion_t* self, real_t x, real_t y, real_t z, real_t w);
quaternion_t* quaternion_set(quaternion_t* self, const quaternion_t* qT);
quaternion_t* quaternion_add(quaternion_t* self, const quaternion_t* qT);
quaternion_t* quaternion_multiply(quaternion_t* self, const quaternion_t* qT);
quaternion_t* quaternion_multiplyv3(quaternion_t* self, const struct vector3 *vT);
quaternion_t* quaternion_multiplyf(quaternion_t* self, real_t f);
quaternion_t* quaternion_subtract(quaternion_t* self, const quaternion_t* qT);
quaternion_t* quaternion_negate(quaternion_t* self);
quaternion_t* quaternion_conjugate(quaternion_t* self);
quaternion_t* quaternion_inverse(quaternion_t* self);

bool quaternion_is_unit(quaternion_t* self);
bool quaternion_is_pure(quaternion_t* self);

real_t quaternion_norm(const quaternion_t* self);
real_t quaternion_magnitude(const quaternion_t* self);
quaternion_t* quaternion_normalize(quaternion_t* self);
real_t quaternion_dot_product(const quaternion_t* self, const quaternion_t* qT);

quaternion_t* quaternion_lerp(const quaternion_t* start, const quaternion_t* end, real_t percent, quaternion_t* qR);
quaternion_t* quaternion_nlerp(const quaternion_t* start, const quaternion_t* end, real_t percent, quaternion_t* qR);
quaternion_t* quaternion_slerp(const quaternion_t* start, const quaternion_t* end, real_t percent, quaternion_t* qR);

void quaternion_get_axis_anglev3(const quaternion_t* self, struct vector3 *vR, real_t *angle);

quaternion_t* quaternion_set_from_axis_anglev3(quaternion_t* self, const struct vector3 *axis, real_t angle);
quaternion_t* quaternion_set_from_axis_anglef3(quaternion_t* self, real_t x, real_t y, real_t z, real_t angle);

quaternion_t* quaternion_get_rotation_tov3(const struct vector3 *from, const struct vector3 *to, quaternion_t* qR);

#endif
