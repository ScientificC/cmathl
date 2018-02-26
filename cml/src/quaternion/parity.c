#include <stdlib.h>
#include <cml/math.h>
#include <cml/quaternion.h>

cml_quaternion_t
cml_quaternion_parity_conj(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, q.x, q.y, q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_parity_symmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, q.x, q.y, q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_parity_antisymmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = q;
        r = (cml_quaternion_t) {0.0, 0.0, 0.0, 0.0};
        return r;
}


cml_quaternion_t
cml_quaternion_x_parity_conj(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, q.x, -q.y, -q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_x_parity_symmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, q.x, 0.0, 0.0};
        return r;
}


cml_quaternion_t
cml_quaternion_x_parity_antisymmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {0.0, 0.0, q.y, q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_y_parity_conj(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, -q.x, q.y, -q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_y_parity_symmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, 0.0, q.y, 0.0};
        return r;
}


cml_quaternion_t
cml_quaternion_y_parity_antisymmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {0.0, q.x, 0.0, q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_z_parity_conj(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, -q.x, -q.y, q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_z_parity_symmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, 0.0, 0.0, q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_z_parity_antisymmetric_part(cml_quaternion_t q)
{
        cml_quaternion_t r = {0.0, q.x, q.y, 0.0};
        return r;
}
