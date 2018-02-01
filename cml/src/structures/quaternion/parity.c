#include <stdlib.h>
#include <cml.h>


quaternion_t
quaternion_x_parity_conjugate(quaternion_t q)
{
        quaternion r = {q.w, q.x, -q.y, -q.z};
        return r;
}


quaternion_t
quaternion_x_parity_symmetric_part(quaternion_t q)
{
        quaternion r = {q.w, q.x, 0.0, 0.0};
        return r;
}


quaternion_t
quaternion_x_parity_antisymmetric_part(quaternion_t q)
{
        quaternion r = {0.0, 0.0, q.y, q.z};
        return r;
}


quaternion_t
quaternion_y_parity_conjugate(quaternion_t q)
{
        quaternion r = {q.w, -q.x, q.y, -q.z};
        return r;
}


quaternion_t
quaternion_y_parity_symmetric_part(quaternion_t q)
{
        quaternion r = {q.w, 0.0, q.y, 0.0};
        return r;
}


quaternion_t
quaternion_y_parity_antisymmetric_part(quaternion_t q)
{
        quaternion r = {0.0, q.x, 0.0, q.z};
        return r;
}


quaternion_t
quaternion_z_parity_conjugate(quaternion_t q)
{
        quaternion r = {q.w, -q.x, -q.y, q.z};
        return r;
}


quaternion_t
quaternion_z_parity_symmetric_part(quaternion_t q)
{
        quaternion r = {q.w, 0.0, 0.0, q.z};
        return r;
}


quaternion_t
quaternion_z_parity_antisymmetric_part(quaternion_t q)
{
        quaternion r = {0.0, q.x, q.y, 0.0};
        return r;
}


quaternion_t
quaternion_parity_conjugate(quaternion_t q)
{
        quaternion r = {q.w, q.x, q.y, q.z};
        return r;
}


quaternion_t
quaternion_parity_symmetric_part(quaternion_t q)
{
        quaternion r = {q.w, q.x, q.y, q.z};
        return r;
}


quaternion_t
quaternion_parity_antisymmetric_part(quaternion_t q)
{
        quaternion r = {0.0, 0.0, 0.0, 0.0};
        return r;
}
