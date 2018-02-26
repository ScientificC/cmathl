#include <stdlib.h>
#include <cml/math.h>
#include <cml/quaternion.h>

/**
 * @ingroup quaternion
 * @brief Initializes the vector portion of the quaternion with 0.0 and the
 * scalar portion with 1.0.
 * The resulting quaternion has a norm of 1.0
 *
 * While CML as well as other math libraries call this the 'identity'
 * quaternion, this is not an accurate term.  Since the principle of a
 * quaternion with no rotation works similar to an identity matrix, we let
 * the term pass.
 *
 */
cml_quaternion_t
cml_quaternion_identity()
{
        return (cml_quaternion_t) {1.0, 0.0, 0.0, 0.0};
}


/**
 * @ingroup quaternion
 * @brief initializes the quaternion with the passed in w, x, y, z
 */
cml_quaternion_t
quaternion(double w, double x, double y, double z)
{
        return (cml_quaternion_t) {w, x, y, z};
}


/**
 * @ingroup quaternion
 * @brief initializes the quaternion by copying the data from q.  This is
 * effectively a copy function.
 */
cml_quaternion_t
cml_quaternion_clone(cml_quaternion_t q)
{
        return quaternion(q.x, q.y, q.z, q.w);
}


/**
 * @ingroup quaternion
 * @brief Sets the values in the quaternion, in place, based on the axis and
 * angle.
 *
 * @param q the quaternion that will become initialized with the values of
 * the axis and angle
 * @param x the x axis
 * @param y the y axis
 * @param z the z axis
 * @param angle the angle is in radians
 *
 * q = cos(a/2) + i ( x * sin(a/2)) + j (y * sin(a/2)) + k ( z * sin(a/2))
 *
 */
cml_quaternion_t
cml_quaternion_from_axis_anglef3(double angle, double x, double y, double z)
{
        double s = cml_sin(angle / 2.0f);
        double c = cml_cos(angle / 2.0f);

        cml_quaternion_t q;

        q.x = x * s;
        q.y = y * s;
        q.z = z * s;
        q.w = c;

        /* reduce rounding errors caused by sin/cos */
        return cml_quaternion_normalized(q);
}


cml_quaternion_t
cml_quaternion_from_spherical_coords(double vartheta, double varphi)
{
        double ct = cml_cos(vartheta/2.),
               cp = cml_cos(varphi/2.),
               st = cml_sin(vartheta/2.),
               sp = cml_sin(varphi/2.);

        return (cml_quaternion_t) { cp*ct, -sp*st, st*cp, sp*ct };
}

cml_quaternion_t
cml_quaternion_from_euler_angles(double alpha, double beta, double gamma)
{
        double ca = cml_cos(alpha/2.),
               cb = cml_cos(beta/2.),
               cc = cml_cos(gamma/2.),
               sa = cml_sin(alpha/2.),
               sb = cml_sin(beta/2.),
               sc = cml_sin(gamma/2.);

        return (cml_quaternion_t) {
                       ca*cb*cc-sa*cb*sc,
                            ca*sb*sc-sa*sb*cc,
                            ca*sb*cc + sa*sb*sc,
                            sa*cb*cc + ca*cb*sc
        };
}
