#include <stdlib.h>
#include <cml/math.h>
#include <cml/structures.h>

cml_quaternion_t
cml_quaternion_scalar_pow(double s, cml_quaternion_t q)
{
        /* Unlike the quaternion^quaternion power, this is unambiguous.*/
        if (s)
        { /*cml_log(s)=-inf */
                cml_quaternion_t r;

                if(!cml_quaternion_nonzero(q))
                {
                        r = (cml_quaternion_t) { 1.0, 0.0, 0.0, 0.0 };
                }
                else
                {
                        r = (cml_quaternion_t) { 0.0, 0.0, 0.0, 0.0 };
                }

                return r;
        } else if(s < 0.0)
        {               /* cml_log(s)=nan */
                /* fprintf(stderr, "Input scalar (%.15g) has no unique logarithm; returning one arbitrarily.", s); */
                cml_quaternion_t t = (cml_quaternion_t)
                {cml_log(-s), M_PI, 0.0, 0.0};
                return cml_quaternion_exp(cml_quaternion_multiply(q, t));
        }

        return cml_quaternion_exp(cml_quaternion_multiply_scalar(q, cml_log(s)));
}


cml_quaternion_t
cml_quaternion_pow(cml_quaternion_t q, cml_quaternion_t p)
{
        /* Note that the following is just my chosen definition of the power. */
        /* Other definitions may disagree due to non-commutativity. */
        if(!cml_quaternion_nonzero(q))
        { /* log(q)=-inf */
                cml_quaternion_t r;

                if(!cml_quaternion_nonzero(p))
                {
                        r = (cml_quaternion_t) {1.0, 0.0, 0.0, 0.0};
                }
                else
                {
                        r = (cml_quaternion_t) {0.0, 0.0, 0.0, 0.0};
                }

                return r;
        }
        return cml_quaternion_exp(cml_quaternion_multiply(cml_quaternion_log(q), p));
}


void
cml_quaternion_inplace_pow(cml_quaternion_t *q1, cml_quaternion_t q2)
{
        /* Not overly useful as an in-place operator, but here for completeness. */
        cml_quaternion_t q3 = cml_quaternion_pow(*q1,q2);
        *q1 = q3;
        return;
}


void
cml_quaternion_inplace_scalar_pow(double s, cml_quaternion_t *q)
{
        /* Not overly useful as an in-place operator, but here for completeness. */
        cml_quaternion_t q2 = cml_quaternion_scalar_pow(s, *q);
        *q = q2;
        return;
}


cml_quaternion_t
cml_quaternion_pow_scalar(cml_quaternion_t q, double s)
{
        /* Unlike the quaternion^quaternion power, this is unambiguous. */
        if(!cml_quaternion_nonzero(q))
        { /* log(q)=-inf */
                cml_quaternion_t r;

                if(cml_isnull(s))
                {
                        r = (cml_quaternion_t) {1.0, 0.0, 0.0, 0.0};
                }
                else
                {
                        r = (cml_quaternion_t) {0.0, 0.0, 0.0, 0.0};
                }

                return r;
        }

        return cml_quaternion_exp(cml_quaternion_multiply_scalar(cml_quaternion_log(q), s));
}


void
cml_quaternion_inplace_pow_scalar(cml_quaternion_t *q, double s)
{
        /* Not overly useful as an in-place operator, but here for completeness. */
        cml_quaternion_t q2 = cml_quaternion_pow_scalar(*q, s);
        *q = q2;
        return;
}


cml_quaternion_t
cml_quaternion_exp(cml_quaternion_t q)
{
        cml_quaternion_t r;
        double vnorm = cml_sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);

        if (vnorm > __CML_QUATERNION_EPS)
        {
                double s = cml_sin(vnorm) / vnorm,
                       e = cml_exp(q.w);

                r = (cml_quaternion_t)
                {e*cml_cos(vnorm), e*s*q.x, e*s*q.y, e*s*q.z};
        }
        else
        {
                r = (cml_quaternion_t) { cml_exp(q.w), 0.0, 0.0, 0.0 };
        }

        return r;
}


cml_quaternion_t
cml_quaternion_log(cml_quaternion_t q)
{
        cml_quaternion_t r;
        double b = cml_sqrt(q.x*q.x  +  q.y*q.y  +  q.z*q.z);

        if(cml_abs(b) <= __CML_QUATERNION_EPS*cml_abs(q.w))
        {
                if(q.w < 0.0)
                {
                        /* fprintf(stderr, "Input quaternion(%.15g, %.15g, %.15g, %.15g)
                           has no unique logarithm; returning one arbitrarily.",
                           q.w, q.x, q.y, q.z);*/
                        if(cml_abs(q.w + 1)>__CML_QUATERNION_EPS)
                        {
                                r = (cml_quaternion_t)
                                { cml_log(-q.w), M_PI, 0., 0. };
                        }
                        else
                        {
                                r = (cml_quaternion_t)
                                {0., M_PI, 0., 0.};
                        }
                }
                else
                {
                        r = (cml_quaternion_t) {cml_log(q.w), 0., 0., 0.};
                }
        }
        else
        {
                double v = cml_atan2(b, q.w),
                       f = v/b;

                r = (cml_quaternion_t) { cml_log(q.w*q.w + b*b)/2.0, f*q.x, f*q.y, f*q.z };
        }

        return r;
}


cml_quaternion_t
cml_quaternion_sqrt(cml_quaternion_t q)
{
        double absolute = cml_quaternion_abs(q);
        cml_quaternion_t r;

        if(cml_abs(1 + q.w/absolute) < __CML_QUATERNION_EPS*absolute)
        {
                r = (cml_quaternion_t)
                {0.0, 1.0, 0.0, 0.0};
        }
        else
        {
                double c = cml_sqrt(absolute/(2 + 2*q.w/absolute));
                r = (cml_quaternion_t)
                {
                        (1.0 + q.w/absolute)*c,
                        q.x*c/absolute,
                        q.y*c/absolute,
                        q.z*c/absolute
                };
        }

        return r;
}
