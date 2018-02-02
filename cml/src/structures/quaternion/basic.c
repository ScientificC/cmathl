#include <stdlib.h>
#include <cml.h>

quaternion_t
quaternion_add(quaternion_t q1, quaternion_t q2)
{
        return (quaternion_t)
               {
                       q1.w+q2.w,
                       q1.x+q2.x,
                       q1.y+q2.y,
                       q1.z+q2.z,
               };
}


void
quaternion_inplace_add(quaternion_t* q1, quaternion_t q2)
{
        q1->w += q2.w;
        q1->x += q2.x;
        q1->y += q2.y;
        q1->z += q2.z;
        return;
}


quaternion_t
quaternion_scalar_add(real_t s, quaternion_t q)
{
        quaternion_t r = { s+q.w, q.x, q.y, q.z };
        return r;
}


void
quaternion_inplace_scalar_add(real_t s, quaternion_t* q)
{
        q->w += s;
        return;
}


quaternion_t
quaternion_add_scalar(quaternion_t q, real_t s)
{
        quaternion_t r = { s+q.w, q.x, q.y, q.z };
        return r;
}


void
quaternion_inplace_add_scalar(quaternion_t* q, real_t s)
{
        q->w += s;
        return;
}


quaternion_t
quaternion_subtract(quaternion_t q1, quaternion_t q2)
{
        quaternion_t r = {
                q1.w-q2.w,
                q1.x-q2.x,
                q1.y-q2.y,
                q1.z-q2.z,
        };
        return r;
}


void
quaternion_inplace_subtract(quaternion_t* q1, quaternion_t q2)
{
        q1->w -= q2.w;
        q1->x -= q2.x;
        q1->y -= q2.y;
        q1->z -= q2.z;
        return;
}


quaternion_t
quaternion_scalar_subtract(real_t s, quaternion_t q)
{
        quaternion_t r = {s-q.w, -q.x, -q.y, -q.z};
        return r;
}


quaternion_t
quaternion_subtract_scalar(quaternion_t q, real_t s)
{
        quaternion_t r = {q.w-s, q.x, q.y, q.z};
        return r;
}


void
quaternion_inplace_subtract_scalar(quaternion_t* q, real_t s)
{
        q->w -= s;
        return;
}


quaternion_t
quaternion_multiply(quaternion_t q1, quaternion_t q2)
{
        quaternion_t r = {
                q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z,
                q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y,
                q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x,
                q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w,
        };
        return r;
}


void
quaternion_inplace_multiply(quaternion_t* q1a, quaternion_t q2)
{
        quaternion_t q1 = {q1a->w, q1a->x, q1a->y, q1a->z};
        q1a->w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
        q1a->x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
        q1a->y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x;
        q1a->z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w;
        return;
}


quaternion_t
quaternion_scalar_multiply(real_t s, quaternion_t q)
{
        quaternion_t r = {s*q.w, s*q.x, s*q.y, s*q.z};
        return r;
}


void
quaternion_inplace_scalar_multiply(real_t s, quaternion_t* q)
{
        q->w *= s;
        q->x *= s;
        q->y *= s;
        q->z *= s;
        return;
}


quaternion_t
quaternion_multiply_scalar(quaternion_t q, real_t s)
{
        quaternion_t r = {s*q.w, s*q.x, s*q.y, s*q.z};
        return r;
}


void
quaternion_inplace_multiply_scalar(quaternion_t* q, real_t s)
{
        q->w *= s;
        q->x *= s;
        q->y *= s;
        q->z *= s;
        return;
}


quaternion_t
quaternion_divide(quaternion_t q1, quaternion_t q2)
{
        real_t q2norm = q2.w*q2.w + q2.x*q2.x + q2.y*q2.y + q2.z*q2.z;
        quaternion_t r = {
                (  q1.w*q2.w + q1.x*q2.x + q1.y*q2.y + q1.z*q2.z) / q2norm,
                (-q1.w*q2.x + q1.x*q2.w - q1.y*q2.z + q1.z*q2.y) / q2norm,
                (-q1.w*q2.y + q1.x*q2.z + q1.y*q2.w - q1.z*q2.x) / q2norm,
                (-q1.w*q2.z - q1.x*q2.y + q1.y*q2.x + q1.z*q2.w) / q2norm
        };
        return r;
}


void
quaternion_inplace_divide(quaternion_t* q1a, quaternion_t q2)
{
        real_t q2norm;
        quaternion_t q1 = *q1a;
        q2norm = q2.w*q2.w + q2.x*q2.x + q2.y*q2.y + q2.z*q2.z;
        q1a->w = ( q1.w*q2.w + q1.x*q2.x + q1.y*q2.y + q1.z*q2.z)/q2norm;
        q1a->x = (-q1.w*q2.x + q1.x*q2.w - q1.y*q2.z + q1.z*q2.y)/q2norm;
        q1a->y = (-q1.w*q2.y + q1.x*q2.z + q1.y*q2.w - q1.z*q2.x)/q2norm;
        q1a->z = (-q1.w*q2.z - q1.x*q2.y + q1.y*q2.x + q1.z*q2.w)/q2norm;
        return;
}


quaternion_t
quaternion_scalar_divide(real_t s, quaternion_t q)
{
        real_t qnorm = q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
        quaternion_t r = {
                ( s*q.w) / qnorm,
                (-s*q.x) / qnorm,
                (-s*q.y) / qnorm,
                (-s*q.z) / qnorm
        };
        return r;
}


/* The following function is impossible, but listed for completeness: */
/* void quaternion_inplace_scalar_divide(real_t* sa, quaternion_t q2) { } */
quaternion_t
quaternion_divide_scalar(quaternion_t q, real_t s)
{
        quaternion_t r = { q.w/s, q.x/s, q.y/s, q.z/s };
        return r;
}


void
quaternion_inplace_divide_scalar(quaternion_t* q, real_t s)
{
        q->w /= s;
        q->x /= s;
        q->y /= s;
        q->z /= s;
        return;
}

quaternion_t
quaternion_opposite(quaternion_t q)
{
        quaternion_t r = {-q.w, -q.x, -q.y, -q.z};
        return r;
}


quaternion_t
quaternion_conj(quaternion_t q)
{
        quaternion_t r = {q.w, -q.x, -q.y, -q.z};
        return r;
}


quaternion_t
quaternion_inverse(quaternion_t q)
{
        real_t norm = quaternion_norm(q);
        quaternion_t r = {q.w/norm, -q.x/norm, -q.y/norm, -q.z/norm};
        return r;
}


real_t
quaternion_norm(quaternion_t q)
{
        return q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
}


real_t
quaternion_abs(quaternion_t q)
{
        return real_sqrt(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}


real_t
quaternion_angle(quaternion_t q)
{
        return 2*quaternion_abs(quaternion_log( q ));
}
