#include <stdlib.h>
#include <cml/math.h>

double
cml_frexp(double x, int *e)
{
        union
        {
                double v;
                struct
                {
			unsigned u_mant2: 32;
			unsigned u_mant1: 20;
			unsigned u_exp: 11;
                        unsigned u_sign: 1;
                } s;
        } u;

	if (x)
        {
		u.v = x;
		*e = u.s.u_exp - 1022;
		u.s.u_exp = 1022;

		return u.v;
	}
        else
        {
		*e = 0;

		return 0.0;
	}
}