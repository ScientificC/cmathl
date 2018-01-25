#include <stdlib.h>
#include <cml.h>

quaternion_t
quaternion_create_from_spherical_coords(real_t vartheta, real_t varphi) {
        real_t ct = cos(vartheta/2.);
        real_t cp = cos(varphi/2.);
        real_t st = sin(vartheta/2.);
        real_t sp = sin(varphi/2.);

        return (quaternion_t) { cp*ct, -sp*st, st*cp, sp*ct };
}

quaternion_t
quaternion_create_from_euler_angles(real_t alpha, real_t beta, real_t gamma) {
        real_t ca = cos(alpha/2.);
        real_t cb = cos(beta/2.);
        real_t cc = cos(gamma/2.);
        real_t sa = sin(alpha/2.);
        real_t sb = sin(beta/2.);
        real_t sc = sin(gamma/2.);
        return (quaternion_t) {
                       ca*cb*cc-sa*cb*sc,
                            ca*sb*sc-sa*sb*cc,
                            ca*sb*cc + sa*sb*sc,
                            sa*cb*cc + ca*cb*sc
        };
}

quaternion_t
quaternion_sqrt(quaternion_t q)
{
        real_t absolute = quaternion_absolute(q);
        quaternion_t r;

        if(abs(1 + q.w/absolute) < _QUATERNION_EPS*absolute) {
                r = {0.0, 1.0, 0.0, 0.0};
        } else {
                real_t c = sqrt(absolute/(2 + 2*q.w/absolute));
                r = {
                        (1.0 + q.w/absolute)*c,
                        q.x*c/absolute,
                        q.y*c/absolute,
                        q.z*c/absolute
                };
        }

        return r;
}

quaternion_t
quaternion_log(quaternion_t q)
{
        real_t b = sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);
        quaternion_t r;

        if(abs(b) <= _QUATERNION_EPS*abs(q.w)) {
                if(q.w < 0.0) {
                        /* fprintf(stderr, "Input quaternion(%.15g, %.15g, %.15g, %.15g)
                           has no unique logarithm; returning one arbitrarily.",
                           q.w, q.x, q.y, q.z);*/
                        if(abs(q.w + 1)>_QUATERNION_EPS) {
                                r = { log(-q.w), PI, 0., 0. };
                        } else {
                                r = {0., PI, 0., 0.};
                        }
                } else {
                        r = {log(q.w), 0., 0., 0.};
                }
        } else {
                real_t v = atan2(b, q.w);
                real_t f = v/b;
                r = { log(q.w*q.w + b*b)/2.0, f*q.x, f*q.y, f*q.z };
        }

        return r;
}

real_t
_quaternion_scalar_log(real_t s) {
        return log(s);
}

quaternion_t
quaternion_scalar_power(real_t s, quaternion_t q)
{
        /* Unlike the quaternion^quaternion power, this is unambiguous.*/
        if(is_null(s)) { /*log(s)=-inf */
                if(!quaternion_nonzero(q)) {
                        quaternion_t r = {1.0, 0.0, 0.0, 0.0};      /* consistent with python */
                        return r;
                } else {
                        quaternion_t r = {0.0, 0.0, 0.0, 0.0};      /* consistent with python */
                        return r;
                }
        } else if(s < 0.0) {               /* log(s)=nan */
                // fprintf(stderr, "Input scalar (%.15g) has no unique logarithm; returning one arbitrarily.", s);
                quaternion_t t = {log(-s), PI, 0, 0};
                return quaternion_exp(quaternion_multiply(q, t));
        }
        return quaternion_exp(quaternion_multiply_scalar(q, log(s)));
}

quaternion_t
quaternion_exp(quaternion_t q)
{
        real_t vnorm = sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);
        quaternion_t r;

        if (vnorm > _QUATERNION_EPS) {
                real_t s = sin(vnorm) / vnorm;
                real_t e = exp(q.w);
                r = {e*cos(vnorm), e*s*q.x, e*s*q.y, e*s*q.z};
        } else {
                r = { exp(q.w), 0, 0, 0 };
        }

        return r;
}
