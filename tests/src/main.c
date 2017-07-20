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
        real x, y, z, c, h;
        x = real_new(2.0);
        z = real_new(2.0);
        y = x->pow(x, z);
        c = real_new(1.0);
        h = c->sin(c);
        printf("%g\n", y->value(y));
        printf("%g\n", h->value(h));
}

int main(int argc, char const *argv[])
{
        __cml_test();
        return 0;
}
