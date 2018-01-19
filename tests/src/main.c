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
// #define mfloat_t GLfloat

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
        real x = new(real, 25.0);
        printf("%s%s\n\n", "The following tests are performed with x = ", as_string(x));
        printf("%s\n", as_string(sin(x)));
        printf("%s\n", as_string(pow(x, x)));
        printf("%s\n", as_string(sinh(x)));
}

int main(int argc, char const *argv[])
{
        clock_t cl = clock();
        __cml_test__();
        // __series_test__();
        printf("%Lg%s\n", (long double)(clock()-cl)/CLOCKS_PER_SEC, "s");
        return 0;
}
