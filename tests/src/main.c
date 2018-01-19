/* Copyright (C) 2017 CMATHL

   This file is part of CML.

   CML is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   CML is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with CML. If not, see <http://www.gnu.org/licenses/>.     */


#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <GL/gl.h>

#define CML_SERIES_RESOLVER 1
#define mfloat_t double

#include <cml.h>

/*
   static double was = 0.0;

   double *f(int *i, double **argv)
   {
        return argv[0];
   }

   void __series_test__()
   {
        double x = 2.0;
        double *a = &x;
        double *argv[1];
        argv[0] = a;
        block_t block = block_create(&f, argv);
        block.response = &was;
        series_resolver(&block, 100000, 10);
        printf("%g\n", was);
   }
 */

void __cml_test__()
{
        real n = real_new((mfloat_t) -1.0); // For testing you should use a number between -HALFPI and HALFPI
        printf("%s%s\n\n", "The following tests are performed with x = ", as_string(n));

        // Basic trigonometric identities
        printf("%s\n", "The following trigonometric identities are verified:");
        printf("%s%s\n","   |--> cos^2(x)+sin^2(x) = ", as_string(add(pow(cos(n), real_new(2.0)), pow(sin(n), real_new(2.0)))));
        printf("%s%s%s%s\n","   |--> sin(x) = ", as_string(sin(n)), " <==> sin(x + 2pi) = ", as_string(sin(add(n, real_new(TWOPI)))));
        printf("%s%s%s%s\n","   |--> cos(x) = ", as_string(cos(n)), " <==> cos(x + 2pi) = ", as_string(cos(add(n, real_new(TWOPI)))));
        printf("%s%s%s%s\n","   |--> tan(x) = ", as_string(tan(n)), " <==> tan(x + pi) = ", as_string(tan(add(n, real_new(PI)))));
        printf("%s%s%s%s\n","   |--> sin(-x) = ", as_string(sin(opposite(n))), " <==> sin(x + pi) = ", as_string(sin(add(n, real_new(PI)))));
        printf("%s%s%s%s\n","   |--> cos(-x) = ", as_string(cos(opposite(n))), " <==> -cos(x + pi) = ", as_string(opposite(cos(add(n, real_new(PI))))));
        printf("%s%s%s%s\n","   |--> tan(-x) = ", as_string(tan(opposite(n))), " <==> -tan(x) = ", as_string(opposite(tan(n))));
        printf("%s%s%s%s\n","   |--> cot(-x) = ", as_string(cot(opposite(n))), " <==> -cot(x) = ", as_string(opposite(cot(n))));
        printf("%s%s%s%s\n","   |--> sin(x) = ", as_string(sin(n)), " <==> cos(PI/2 - x) = ", as_string(cos(sub(real_new(HALFPI), n))));
        printf("%s%s%s%s\n","   |--> cos(x) = ", as_string(cos(n)), " <==> sin(PI/2 - x) = ", as_string(sin(sub(real_new(HALFPI), n))));
        printf("%s%s%s%s\n","   |--> tan(x) = ", as_string(tan(n)), " <==> cot(PI/2 - x) = ", as_string(cot(sub(real_new(HALFPI), n))));

        // Hyperbolic trigonometric identities
        printf("\n");
        printf("%s\n", "The following hyperbolic trigonometric identities are verified:");
        printf("%s%s\n","   |--> cosh^2(x)-sinh^2(x) = ", as_string(sub(pow(cosh(n), real_new(2.0)), pow(sinh(n), real_new(2.0)))));
}

int main(int argc, char const *argv[])
{
        clock_t cl = clock();
        __cml_test__();
        // __series_test__();
        printf("%Lg%s\n", (long double)(clock()-cl)/CLOCKS_PER_SEC, "s");
        return 0;
}
