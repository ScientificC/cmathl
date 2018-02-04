#include <stdlib.h>
#include <cml.h>

quaternion_t
quaternion_scalar_pow(real_t s, quaternion_t q)
{
        /* Unlike the quaternion^quaternion power, this is unambiguous.*/
        if (s) { /*real_log(s)=-inf */
                quaternion_t r;

                if(!quaternion_nonzero(q)) {
                        r = (quaternion_t) { 1.0, 0.0, 0.0, 0.0 };
                } else {
                        r = (quaternion_t) { 0.0, 0.0, 0.0, 0.0 };
                }

                return r;
        } else if(s < 0.0) {               /* real_log(s)=nan */
                /* fprintf(stderr, "Input scalar (%.15g) has no unique logarithm; returning one arbitrarily.", s); */
                quaternion_t t = (quaternion_t) {real_log(-s), PI, 0.0, 0.0};
                return quaternion_exp(quaternion_multiply(q, t));
        }

        return quaternion_exp(quaternion_multiply_scalar(q, real_log(s)));
}


quaternion_t
quaternion_pow(quaternion_t q, quaternion_t p)
{
        /* Note that the following is just my chosen definition of the power. */
        /* Other definitions may disagree due to non-commutativity. */
        if(!quaternion_nonzero(q)) { /* log(q)=-inf */
                quaternion_t r;

                if(!quaternion_nonzero(p)) {
                        r = (quaternion_t) {1.0, 0.0, 0.0, 0.0};
                } else {
                        r = (quaternion_t) {0.0, 0.0, 0.0, 0.0};
                }

                return r;
        }
        return quaternion_exp(quaternion_multiply(quaternion_log(q), p));
}


void
quaternion_inplace_pow(quaternion_t* q1, quaternion_t q2)
{
        /* Not overly useful as an in-place operator, but here for completeness. */
        quaternion_t q3 = quaternion_pow(*q1,q2);
        *q1 = q3;
        return;
}


void
quaternion_inplace_scalar_pow(real_t s, quaternion_t* q)
{
        /* Not overly useful as an in-place operator, but here for completeness. */
        quaternion_t q2 = quaternion_scalar_pow(s, *q);
        *q = q2;
        return;
}


quaternion_t
quaternion_pow_scalar(quaternion_t q, real_t s)
{
        /* Unlike the quaternion^quaternion power, this is unambiguous. */
        if(!quaternion_nonzero(q)) { /* log(q)=-inf */
                quaternion_t r;

                if(real_isnull(s)) {
                        r = (quaternion_t) {1.0, 0.0, 0.0, 0.0};
                } else {
                        r = (quaternion_t) {0.0, 0.0, 0.0, 0.0};
                }

                return r;
        }

        return quaternion_exp(quaternion_multiply_scalar(quaternion_log(q), s));
}


void
quaternion_inplace_pow_scalar(quaternion_t* q, real_t s)
{
        /* Not overly useful as an in-place operator, but here for completeness. */
        quaternion_t q2 = quaternion_pow_scalar(*q, s);
        *q = q2;
        return;
}


quaternion_t
quaternion_exp(quaternion_t q)
{
        quaternion_t r;
        real_t vnorm = real_sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);

        if (vnorm > _CML_QUATERNION_EPS) {
                real_t s = real_sin(vnorm) / vnorm,
                       e = real_exp(q.w);

                r = (quaternion_t) {e*real_cos(vnorm), e*s*q.x, e*s*q.y, e*s*q.z};
        } else {
                r = (quaternion_t) { real_exp(q.w), 0.0, 0.0, 0.0 };
        }

        return r;
}


quaternion_t
quaternion_log(quaternion_t q)
{
        quaternion_t r;
        real_t b = real_sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);

        if(real_abs(b) <= _CML_QUATERNION_EPS*real_abs(q.w)) {
                if(q.w < 0.0) {
                        /* fprintf(stderr, "Input quaternion(%.15g, %.15g, %.15g, %.15g)
                           has no unique logarithm; returning one arbitrarily.",
                           q.w, q.x, q.y, q.z);*/
                        if(real_abs(q.w + 1)>_CML_QUATERNION_EPS) {
                                r = (quaternion_t) { real_log(-q.w), PI, 0., 0. };
                        } else {
                                r = (quaternion_t) {0., PI, 0., 0.};
                        }
                } else {
                        r = (quaternion_t) {real_log(q.w), 0., 0., 0.};
                }
        } else {
                real_t v = real_atan2(b, q.w),
                       f = v/b;

                r = (quaternion_t) { real_log(q.w*q.w + b*b)/2.0, f*q.x, f*q.y, f*q.z };
        }

        return r;
}


quaternion_t
quaternion_sqrt(quaternion_t q)
{
        real_t absolute = quaternion_abs(q);
        quaternion_t r;

        if(real_abs(1 + q.w/absolute) < _CML_QUATERNION_EPS*absolute) {
                r = (quaternion_t) {0.0, 1.0, 0.0, 0.0};
        } else {
                real_t c = real_sqrt(absolute/(2 + 2*q.w/absolute));
                r = (quaternion_t) {
                        (1.0 + q.w/absolute)*c,
                        q.x*c/absolute,
                        q.y*c/absolute,
                        q.z*c/absolute
                };
        }

        return r;
}
