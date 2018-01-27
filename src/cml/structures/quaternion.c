#include <stdlib.h>
#include <cml.h>

quaternion_t
quaternion_create_from_spherical_coords(real_t vartheta, real_t varphi) {
        real_t ct = real_cos(vartheta/2.),
               cp = real_cos(varphi/2.),
               st = real_sin(vartheta/2.),
               sp = real_sin(varphi/2.);

        return (quaternion_t) { cp*ct, -sp*st, st*cp, sp*ct };
}

quaternion_t
quaternion_create_from_euler_angles(real_t alpha, real_t beta, real_t gamma) {
        real_t ca = real_cos(alpha/2.),
               cb = real_cos(beta/2.),
               cc = real_cos(gamma/2.),
               sa = real_sin(alpha/2.),
               sb = real_sin(beta/2.),
               sc = real_sin(gamma/2.);

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

        if(real_abs(1 + q.w/absolute) < _CML_QUATERNION_EPS*absolute) {
                r = {0.0, 1.0, 0.0, 0.0};
        } else {
                real_t c = real_sqrt(absolute/(2 + 2*q.w/absolute));
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
        quaternion_t r;
        real_t b = real_sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);

        if(real_abs(b) <= _CML_QUATERNION_EPS*real_abs(q.w)) {
                if(q.w < 0.0) {
                        /* fprintf(stderr, "Input quaternion(%.15g, %.15g, %.15g, %.15g)
                           has no unique logarithm; returning one arbitrarily.",
                           q.w, q.x, q.y, q.z);*/
                        if(real_abs(q.w + 1)>_CML_QUATERNION_EPS) {
                                r = { real_log(-q.w), PI, 0., 0. };
                        } else {
                                r = {0., PI, 0., 0.};
                        }
                } else {
                        r = {real_log(q.w), 0., 0., 0.};
                }
        } else {
                real_t v = real_atan2(b, q.w),
                       f = v/b;

                r = { real_log(q.w*q.w + b*b)/2.0, f*q.x, f*q.y, f*q.z };
        }

        return r;
}

real_t
_quaternion_scalar_real_log(real_t s) {
        return real_log(s);
}

quaternion_t
quaternion_scalar_power(real_t s, quaternion_t q)
{
        /* Unlike the quaternion^quaternion power, this is unambiguous.*/
        if(is_null(s)) { /*real_log(s)=-inf */
                quaternion_t r;

                if(!quaternion_nonzero(q)) {
                        r = {1.0, 0.0, 0.0, 0.0};
                } else {
                        r = {0.0, 0.0, 0.0, 0.0};
                }

                return r;
        } else if(s < 0.0) {               /* real_log(s)=nan */
                // fprintf(stderr, "Input scalar (%.15g) has no unique logarithm; returning one arbitrarily.", s);
                quaternion_t t = {real_log(-s), PI, 0, 0};
                return quaternion_exp(quaternion_multiply(q, t));
        }
        return quaternion_exp(quaternion_multiply_scalar(q, real_log(s)));
}

quaternion_t
quaternion_exp(quaternion_t q)
{
        quaternion_t r;
        real_t vnorm = real_sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);

        if (vnorm > _CML_QUATERNION_EPS) {
                real_t s = real_sin(vnorm) / vnorm,
                       e = real_exp(q.w);

                r = {e*real_cos(vnorm), e*s*q.x, e*s*q.y, e*s*q.z};
        } else {
                r = { real_exp(q.w), 0, 0, 0 };
        }

        return r;
}
