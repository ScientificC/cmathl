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


#include "../../includes/cml.h"

void __cml_test()
{
        real x, y, h, a, b;
        complex z, w, k;

        x = real_new(2.0);
        y = real_new(4.0);
        h = real_new(2.0);

        a = y->pow(y, h);
        b = h->sqrt(h);

        z = complex_new(x, y);
        w = complex_new(y, h);

        k = z->add(z, w);

        printf("%s\n", b->asString(b));

        free(x);
        free(y);
        free(h);
        free(a);
        free(b);
        free(z);
        free(w);
        free(k);
}

int main(int argc, char const *argv[])
{
        __cml_test();
        return 0;
}
