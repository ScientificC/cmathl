#include <stdlib.h>
#include <cml/math.h>
#include <cml/structures.h>

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
quaternion_t
quaternion_identity()
{
        return (quaternion_t) {1.0, 0.0, 0.0, 0.0};
}


/**
 * @ingroup quaternion
 * @brief initializes the quaternion with the passed in w, x, y, z
 */
quaternion_t
quaternion(double w, double x, double y, double z)
{
        return (quaternion_t) {w, x, y, z};
}


/**
 * @ingroup quaternion
 * @brief initializes the quaternion by copying the data from q.  This is
 * effectively a copy function.
 */
quaternion_t
quaternion_clone(quaternion_t q)
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
quaternion_t
quaternion_from_axis_anglef3(double angle, double x, double y, double z)
{
        double s = real_sin(angle / 2.0f);
        double c = real_cos(angle / 2.0f);

        quaternion_t q;

        q.x = x * s;
        q.y = y * s;
        q.z = z * s;
        q.w = c;

        /* reduce rounding errors caused by sin/cos */
        return quaternion_normalized(q);
}


quaternion_t
quaternion_from_spherical_coords(double vartheta, double varphi)
{
        double ct = real_cos(vartheta/2.),
               cp = real_cos(varphi/2.),
               st = real_sin(vartheta/2.),
               sp = real_sin(varphi/2.);

        return (quaternion_t) { cp*ct, -sp*st, st*cp, sp*ct };
}

quaternion_t
quaternion_from_euler_angles(double alpha, double beta, double gamma)
{
        double ca = real_cos(alpha/2.),
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
