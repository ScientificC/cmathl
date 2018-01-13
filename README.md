# cml

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)
![Version: v1.7](https://img.shields.io/badge/Version-v1.7-blue.svg)


## Introduction

CML is a compact C library with a great variety of mathematical functions.

## Details

Each of the functions of the library is developed using efficient mathematical definitions and this is one of the most important characteristics.

## Configuration Macros

The float type used by CML is defined by the macro `cml_t`, which is by default `float`.

If the macro `CML_NO_STDBOOL` is defined, the library will not include `stdbool.h` and will define a macro `bool` of type `int` to represent boolean values. This is useful for platforms where `stdbool.h` is not available.

If the macro `CML_DOUBLE_PRECISION` is defined, the math constants macros will be defined with double precision and the library will use internally the math functions for double types. Otherwise, the math constants macros will be defined with float precision and the library will use internally the math functions for float types.

You can define these macros during compilation time with flags:

```
-DCML_NO_STDBOOL=ON -Dcml_t=double -DCML_DOUBLE_PRECISION=ON
```

Or include `cml.h` in a source or header. This second approach is useful, because you can define `cml_t` as a different type other than the built-in types `float` or `double`, such as `GLfloat`:

```c
/* In a *.c file */
#include <GL.h>
#define cml_t GLfloat
#include <cml.h>
```
