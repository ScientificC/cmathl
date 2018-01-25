#include <stdlib.h>
#include <cml.h>

quaternion_t
quaternion_create_from_spherical_coords(double vartheta, double varphi) {
        double ct = cos(vartheta/2.);
        double cp = cos(varphi/2.);
        double st = sin(vartheta/2.);
        double sp = sin(varphi/2.);

        return (quaternion_t) { cp*ct, -sp*st, st*cp, sp*ct };
}

quaternion_t
quaternion_create_from_euler_angles(double alpha, double beta, double gamma) {
        double ca = cos(alpha/2.);
        double cb = cos(beta/2.);
        double cc = cos(gamma/2.);
        double sa = sin(alpha/2.);
        double sb = sin(beta/2.);
        double sc = sin(gamma/2.);
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
        double absolute = quaternion_absolute(q);
        quaternion_t r;

        if(abs(1 + q.w/absolute) < _QUATERNION_EPS*absolute) {
                r = {0.0, 1.0, 0.0, 0.0};
        } else {
                double c = sqrt(absolute/(2 + 2*q.w/absolute));
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
        double b = sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);
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
                double v = atan2(b, q.w);
                double f = v/b;
                r = { log(q.w*q.w + b*b)/2.0, f*q.x, f*q.y, f*q.z };
        }

        return r;
}

double
_quaternion_scalar_log(double s) {
        return log(s);
}

quaternion_t
quaternion_scalar_power(double s, quaternion_t q)
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
        double vnorm = sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);
        quaternion_t r;

        if (vnorm > _QUATERNION_EPS) {
                double s = sin(vnorm) / vnorm;
                double e = exp(q.w);
                r = {e*cos(vnorm), e*s*q.x, e*s*q.y, e*s*q.z};
        } else {
                r = { exp(q.w), 0, 0, 0 };
        }

        return r;
}
