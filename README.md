# cml

[![Build Status](https://travis-ci.org/CMATHL/cml.svg?branch=development)](https://travis-ci.org/CMATHL/cml) [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0) ![Version: v1.9.1b](https://img.shields.io/badge/Version-v1.9.1b-blue.svg)

## Introduction

CML is a pure-C math library with a great variety of mathematical functions. It is almost 100% C89/C90 compliant.

## Using the CMATHL

Currently, CMATHL (or CML) does not have a make install option. As it is header-only, it is simple enough to copy the src header directory into your project, and setup your build to reference it.

In other words, you can include the repository in the `lib` directory and reference it in the following way:

```
cc ... -I./lib/cml/src
```

## Configuration Macros

CML can be configured with the following preprocessors (described in the following sections of this document):

- `CML_DOUBLE_PRECISION`
- `CML_NO_ALIASES`
- `CML_NO_EASING_FUNCTIONS`
- `CML_NO_STDBOOL`
- `CML_NO_STDINT`
- `mfloat_t`
- `mint_t`

You can define these macros during compilation time with flags:

```
cc -DCML_NO_STDBOOL=ON -Dmfloat_t=double -DCML_DOUBLE_PRECISION=ON
```

Or include `cml.h` in a source or header. This second approach is useful, because you can define `mfloat_t` as a different type other than the built-in types `float` or `double`, such as `GLfloat`:

```c
/* In a *.c file */
#include <GL/gl.h>
#define mfloat_t GLfloat
#include <cml.h>
```

### Bool Type

If the macro `CML_NO_STDBOOL` is defined, the library will not include `stdbool.h` and will define a type or macro `bool` of type `int`, `int32_t` or something like to represent boolean values. This is useful for platforms where `stdbool.h` is not available.

### Integer Type

By default, `mint_t` is a `int32_t` if the header `stdint.h` is available. If the header `stdint.h` is not avaliable, disabled by defining `CML_NO_STDINT`, `mint_t` is a `int`. This can be changed by predefining `mint_t` as a desired type.

### Float-point Type

The float type used by CML is defined by the macro `mfloat_t`, which is by default `float`.

### Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/), useful particularly for animations. Easing is a method of distorting time to control apparent motion in animation. It is most commonly used for slow-in, slow-out. By easing time, animated transitions are smoother and exhibit more plausible motion.

Easing functions take a value inside the range `[0.0, 1.0]` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range (Check the [easings.net](http://easings.net/) to see those functions).

By defining `CML_NO_EASING_FUNCTIONS`, the easing functions will not be defined.

### Math functions aliases

Currently, all functions defined in cml have an alias which allows greater readability when working with the library. These aliases allow, for example, functions such as `real_sin` and`complex_cosh` to have aliases that are much more readable, such as `sin` and`ccosh` respectively. Then, this could bring certain incompatibilities with libraries like `math`, since these aliases will be defined as long as they are not indicated otherwise, and this may not be compatible with math definitions.

By defining `CML_NO_ALIASES`, these aliases will not be defined, leaving only the original functions names and, thus, allowing greater compatibility.

### Math Precision

By default, CML will use single-precision internally. This can be changed by predefining `CML_DOUBLE_PRECISION`. If the macro `CML_DOUBLE_PRECISION` is defined, the math constants macros will be defined with double precision and the library will use internally the math functions for double types. Otherwise, the math constants macros will be defined with float precision and the library will internally use the math functions for float types.

## Types

CML offers at the moment two types, `real_t` and `complex_t`. `real_t` corresponds to the type defined in the `mfloat_t` macro. On the other hand, `complex_t` being a structure.

### Real

CML defines a large number of operations for the set of real numbers. For this, the type `real_t` is provided. Here is an example on how to work with this type of data:

```c
real_t x = 2.0;
```

Now, let's see an example of how to apply an operation between two reals. Suppose we have a `pow` function which accepts two reals x and y, then the code would be as follows:

```c
real_t x, y, z;

x = 3.0;
y = 2.0;
z = pow(x, y);
```

#### Functions

##### Basic Functions

```c
real_t real_abs(real_t);
real_t real_add(real_t, real_t);
real_t real_ared(real_t);
real_t real_div_e(real_t, real_t);
real_t real_div(real_t, real_t);
real_t real_inverse(real_t);
real_t real_mod(real_t, real_t);
real_t real_opposite(real_t);
real_t real_prod(real_t, real_t);
real_t real_sgn(real_t);
real_t real_sub(real_t, real_t);
```

##### Exponential Functions

```c
real_t real_exp(real_t);
real_t real_log(real_t);
real_t real_log_b(real_t, real_t);
```

##### Power Functions

```c
real_t real_pow(real_t, real_t);
real_t real_root(real_t, real_t);
real_t real_sqrt(real_t);
```

##### Trigonometric Functions

```c
real_t real_sin(real_t);
real_t real_cos(real_t);
real_t real_tan(real_t);
real_t real_sec(real_t);
real_t real_csc(real_t);
real_t real_cot(real_t);
real_t real_asin(real_t);
real_t real_acos(real_t);
real_t real_atan(real_t);
real_t real_atan2(real_t, real_t);
```

##### Hyperbolic Functions

```c
real_t real_sinh(real_t);
real_t real_cosh(real_t);
real_t real_tanh(real_t);
real_t real_csch(real_t);
real_t real_sech(real_t);
real_t real_coth(real_t);
real_t real_asinh(real_t);
real_t real_acosh(real_t);
real_t real_atanh(real_t);
```

##### Error and Gamma Functions

```c
real_t real_gamma(real_t);
real_t real_error(real_t);
```

##### Nearest Integer Floating Point Operations

```c
real_t real_ceil(real_t);
real_t real_floor(real_t);
```

##### Classification Functions

```c
bool real_equals(real_t, real_t);
bool real_is_greater_or_equals(real_t, real_t);
bool real_is_greater(real_t, real_t);
bool real_is_integer(real_t);
bool real_is_less_or_equals(real_t, real_t);
bool real_is_less(real_t, real_t);
bool real_is_mult(real_t, real_t);
bool real_is_natural(real_t);
bool real_is_null(real_t);
```

### Complex

CML defines a large number of operations for the set of complex numbers. For this, the type `complex_t` is provided. Here is an example on how to work with this type of data:

```c
complex_t z = complex(1.0, 4.0);
```

Another way to do the same can be the following:

```c
complex_t z = { 1.0, 4.0 };
```

Now, let's see an example of how to apply an operation to any complex numbers. Suppose we have a `exp` function which accepts one complex z, then the code would be as follows:

```c
complex_t z, w;

z = complex(1.0, 4.0);
w = cexp(z);
```

## A simple example

```c
#include <stdlib.h>
#include <stdio.h>
#include <cml.h>

int
main(int argc, char const *argv[])
{
        real_t x, y;
        complex_t z;

        x = 2.0;
        y = 3.0;
        z = complex(1.0, 2.0);
        w = csin(z);

        printf("%g\n", sin(x));
        printf("%g\n", atan2(x, y));
        printf("%g\n", creal(w));
        printf("%g\n", cimag(w));

        return 0;
}
```
