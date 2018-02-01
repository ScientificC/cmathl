#include <stdlib.h>
#include <cml.h>

quaternion_t
quaternion_create_from_spherical_coords(real_t vartheta, real_t varphi)
{
        real_t ct = real_cos(vartheta/2.),
               cp = real_cos(varphi/2.),
               st = real_sin(vartheta/2.),
               sp = real_sin(varphi/2.);

        return (quaternion_t) { cp*ct, -sp*st, st*cp, sp*ct };
}

quaternion_t
quaternion_create_from_euler_angles(real_t alpha, real_t beta, real_t gamma)
{
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
