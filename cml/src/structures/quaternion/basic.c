#include <stdlib.h>
#include <cml/math.h>
#include <cml/structures.h>

cml_quaternion_t
cml_quaternion_add(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return (cml_quaternion_t)
               {
                       q1.w+q2.w,
                       q1.x+q2.x,
                       q1.y+q2.y,
                       q1.z+q2.z,
               };
}


void
cml_quaternion_inplace_add(cml_quaternion_t *q1, cml_quaternion_t q2)
{
        q1->w += q2.w;
        q1->x += q2.x;
        q1->y += q2.y;
        q1->z += q2.z;
        return;
}


cml_quaternion_t
cml_quaternion_scalar_add(double s, cml_quaternion_t q)
{
        cml_quaternion_t r = { s+q.w, q.x, q.y, q.z };
        return r;
}


void
cml_quaternion_inplace_scalar_add(double s, cml_quaternion_t *q)
{
        q->w += s;
        return;
}


cml_quaternion_t
cml_quaternion_add_scalar(cml_quaternion_t q, double s)
{
        cml_quaternion_t r = { s+q.w, q.x, q.y, q.z };
        return r;
}


void
cml_quaternion_inplace_add_scalar(cml_quaternion_t *q, double s)
{
        q->w += s;
        return;
}


cml_quaternion_t
cml_quaternion_subtract(cml_quaternion_t q1, cml_quaternion_t q2)
{
        cml_quaternion_t r = {
                q1.w-q2.w,
                q1.x-q2.x,
                q1.y-q2.y,
                q1.z-q2.z,
        };
        return r;
}


void
cml_quaternion_inplace_subtract(cml_quaternion_t *q1, cml_quaternion_t q2)
{
        q1->w -= q2.w;
        q1->x -= q2.x;
        q1->y -= q2.y;
        q1->z -= q2.z;
        return;
}


cml_quaternion_t
cml_quaternion_scalar_subtract(double s, cml_quaternion_t q)
{
        cml_quaternion_t r = {s-q.w, -q.x, -q.y, -q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_subtract_scalar(cml_quaternion_t q, double s)
{
        cml_quaternion_t r = {q.w-s, q.x, q.y, q.z};
        return r;
}


void
cml_quaternion_inplace_subtract_scalar(cml_quaternion_t *q, double s)
{
        q->w -= s;
        return;
}


cml_quaternion_t
cml_quaternion_multiply(cml_quaternion_t q1, cml_quaternion_t q2)
{
        cml_quaternion_t r = {
                q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z,
                q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y,
                q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x,
                q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w,
        };
        return r;
}


void
cml_quaternion_inplace_multiply(cml_quaternion_t *q1a, cml_quaternion_t q2)
{
        cml_quaternion_t q1 = {q1a->w, q1a->x, q1a->y, q1a->z};
        q1a->w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
        q1a->x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
        q1a->y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x;
        q1a->z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w;
        return;
}


cml_quaternion_t
cml_quaternion_scalar_multiply(double s, cml_quaternion_t q)
{
        cml_quaternion_t r = {s*q.w, s*q.x, s*q.y, s*q.z};
        return r;
}


void
cml_quaternion_inplace_scalar_multiply(double s, cml_quaternion_t *q)
{
        q->w *= s;
        q->x *= s;
        q->y *= s;
        q->z *= s;
        return;
}


cml_quaternion_t
cml_quaternion_multiply_scalar(cml_quaternion_t q, double s)
{
        cml_quaternion_t r = {s*q.w, s*q.x, s*q.y, s*q.z};
        return r;
}


void
cml_quaternion_inplace_multiply_scalar(cml_quaternion_t *q, double s)
{
        q->w *= s;
        q->x *= s;
        q->y *= s;
        q->z *= s;
        return;
}


cml_quaternion_t
cml_quaternion_divide(cml_quaternion_t q1, cml_quaternion_t q2)
{
        double q2norm = q2.w*q2.w + q2.x*q2.x + q2.y*q2.y + q2.z*q2.z;
        cml_quaternion_t r = {
                (  q1.w*q2.w + q1.x*q2.x + q1.y*q2.y + q1.z*q2.z) / q2norm,
                (-q1.w*q2.x + q1.x*q2.w - q1.y*q2.z + q1.z*q2.y) / q2norm,
                (-q1.w*q2.y + q1.x*q2.z + q1.y*q2.w - q1.z*q2.x) / q2norm,
                (-q1.w*q2.z - q1.x*q2.y + q1.y*q2.x + q1.z*q2.w) / q2norm
        };
        return r;
}


void
cml_quaternion_inplace_divide(cml_quaternion_t *q1a, cml_quaternion_t q2)
{
        double q2norm;
        cml_quaternion_t q1 = *q1a;
        q2norm = q2.w*q2.w + q2.x*q2.x + q2.y*q2.y + q2.z*q2.z;
        q1a->w = ( q1.w*q2.w + q1.x*q2.x + q1.y*q2.y + q1.z*q2.z)/q2norm;
        q1a->x = (-q1.w*q2.x + q1.x*q2.w - q1.y*q2.z + q1.z*q2.y)/q2norm;
        q1a->y = (-q1.w*q2.y + q1.x*q2.z + q1.y*q2.w - q1.z*q2.x)/q2norm;
        q1a->z = (-q1.w*q2.z - q1.x*q2.y + q1.y*q2.x + q1.z*q2.w)/q2norm;
        return;
}


cml_quaternion_t
cml_quaternion_scalar_divide(double s, cml_quaternion_t q)
{
        double qnorm = q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
        cml_quaternion_t r = {
                ( s*q.w) / qnorm,
                (-s*q.x) / qnorm,
                (-s*q.y) / qnorm,
                (-s*q.z) / qnorm
        };
        return r;
}


/* The following function is impossible, but listed for completeness: */
/* void cml_quaternion_inplace_scalar_divide(double *sa, cml_quaternion_t q2) { } */
cml_quaternion_t
cml_quaternion_divide_scalar(cml_quaternion_t q, double s)
{
        cml_quaternion_t r = { q.w/s, q.x/s, q.y/s, q.z/s };
        return r;
}


void
cml_quaternion_inplace_divide_scalar(cml_quaternion_t *q, double s)
{
        q->w /= s;
        q->x /= s;
        q->y /= s;
        q->z /= s;
        return;
}

cml_quaternion_t
cml_quaternion_opposite(cml_quaternion_t q)
{
        cml_quaternion_t r = {-q.w, -q.x, -q.y, -q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_conj(cml_quaternion_t q)
{
        cml_quaternion_t r = {q.w, -q.x, -q.y, -q.z};
        return r;
}


cml_quaternion_t
cml_quaternion_inverse(cml_quaternion_t q)
{
        double norm = cml_quaternion_norm(q);
        cml_quaternion_t r = {q.w/norm, -q.x/norm, -q.y/norm, -q.z/norm};
        return r;
}


double
cml_quaternion_norm(cml_quaternion_t q)
{
        return q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z;
}


double
cml_quaternion_abs(cml_quaternion_t q)
{
        return cml_sqrt(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}


double
cml_quaternion_angle(cml_quaternion_t q)
{
        return 2*cml_quaternion_abs(cml_quaternion_log( q ));
}

cml_quaternion_t
cml_quaternion_normalized(cml_quaternion_t q)
{
        double q_abs = cml_quaternion_abs(q);

        if (cml_isnull(q_abs)) {
                return q;
        }

        cml_quaternion_t r = {q.w/q_abs, q.x/q_abs, q.y/q_abs, q.z/q_abs};
        return r;
}
