#include <stdlib.h>
#include <cml.h>

static void
make_float_bigendian(float *x)
{
        union {
                float f;
                unsigned char b[4];
        } u,v;

        u.f = *x;

        v.b[0] = u.b[3];
        v.b[1] = u.b[2];
        v.b[2] = u.b[1];
        v.b[3] = u.b[0];

        *x = v.f;
}


static void
make_double_bigendian(double *x)
{
        union {
                double d;
                unsigned char b[8];
        } u,v;

        u.d = *x;

        v.b[0] = u.b[7];
        v.b[1] = u.b[6];
        v.b[2] = u.b[5];
        v.b[3] = u.b[4];
        v.b[4] = u.b[3];
        v.b[5] = u.b[2];
        v.b[6] = u.b[1];
        v.b[7] = u.b[0];

        *x = v.d;
}
