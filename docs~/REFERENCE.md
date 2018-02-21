# CML REFERENCE

[![Build Status](https://travis-ci.org/CMATHL/cml.svg?branch=development)](https://travis-ci.org/CMATHL/cml) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT) ![Version: v1.9.7](https://img.shields.io/badge/Version-v1.9.7-blue.svg)

## Table of Contents

- [**Easing Functions**](#easing-functions)
- [**Math**](#math)

  - [Real](#real)

    - [Basic Functions](#basic-functions)
    - [Exponential Functions](#exponential-functions)
    - [Power Functions](#power-functions)
    - [Trigonometric Functions](#trigonometric-functions)
    - [Hyperbolic Functions](#hyperbolic-functions)
    - [Error and Gamma Functions](#error-and-gamma-functions)
    - [Nearest Integer Floating Point Operations](#nearest-integer-floating-point-operations)
    - [Classification Functions](#classification-functions)

  - [Complex](#complex)

    - [Basic Functions](#basic-functions-1)
    - [Exponentiation Functions](#exponentiation-functions)
    - [Trigonometric Functions](#trigonometric-functions-1)
    - [Hyperbolic Functions](#hyperbolic-functions-1)
    - [Error and Gamma Functions](#error-and-gamma-functions-1)

## Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/), useful particularly for animations. Easing is a method of distorting time to control apparent motion in animation. It is most commonly used for slow-in, slow-out. By easing time, animated transitions are smoother and exhibit more plausible motion.

Easing functions take a value inside the range `[0.0, 1.0]` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range (Check the [easings.net](http://easings.net/) to see those functions).

The following types of easing functions are supported:

- Linear
- Quadratic
- Cubic
- Quartic
- Quintic
- Sine
- Circular
- Exponential
- Elastic
- Bounce
- Back

The core easing functions are implemented as C functions that take a time parameter and return a progress parameter, which can subsequently be used to interpolate any quantity.

### Goals

The design goals of easings are:

- To be as fast as conceivably possible while maintaining human readability
- To elucidate the mathematical underpinnings of common easing functions

## Math

CML provides a large number of mathematical functions for general purposes offering at the moment two types, `real_t` and `complex_t`. `real_t` corresponds to the type defined in the `mfloat_t` macro. On the other hand, `complex_t` being a structure.

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

--------------------------------------------------------------------------------

Below are the prototypes of the functions provided for this type of data.

#### Basic Functions

```c
real_t real_abs(real_t);
real_t real_add(real_t, real_t);
real_t real_ared(real_t);
real_t real_div_e(real_t, real_t);
real_t real_div(real_t, real_t);
real_t real_inverse(real_t);
real_t real_hypot(real_t x, real_t y);
real_t real_mod(real_t, real_t);
real_t real_opposite(real_t);
real_t real_mul(real_t, real_t);
real_t real_sgn(real_t);
real_t real_sub(real_t, real_t);
```

#### Exponential Functions

```c
real_t real_exp(real_t);
real_t real_log(real_t);
real_t real_log_b(real_t, real_t);
real_t real_log1p(real_t x);
```

#### Power Functions

```c
real_t real_pow_int(real_t, int);
real_t real_pow_uint(real_t, unsigned int);
real_t real_pow(real_t, real_t);
real_t real_root(real_t, real_t);
real_t real_sqrt(real_t);
```

#### Trigonometric Functions

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

#### Hyperbolic Functions

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

#### Error and Gamma Functions

```c
real_t real_gamma(real_t);
real_t real_error(real_t);
```

#### Nearest Integer Floating Point Operations

```c
real_t real_ceil(real_t);
real_t real_floor(real_t);
```

#### Classification Functions

```c
bool real_equal(real_t, real_t);
bool real_isfinite(real_t);
bool real_isgreaterequal(real_t, real_t);
bool real_isgreater(real_t, real_t);
bool real_isinf(real_t);
bool real_isinteger(real_t);
bool real_islessequal(real_t, real_t);
bool real_isless(real_t, real_t);
bool real_ismult(real_t, real_t);
bool real_isnatural(real_t);
bool real_isnan(real_t);
bool real_isnull(real_t);
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

--------------------------------------------------------------------------------

Below are the prototypes of the functions provided for this type of data.

#### Basic Functions

```c
real_t complex_abs(complex_t);
real_t complex_arg(complex_t);
real_t complex_logabs(complex_t);

complex_t complex_add(complex_t, complex_t);
complex_t complex_conj(complex_t);
complex_t complex_div(complex_t, complex_t);
complex_t complex_inverse(complex_t);
complex_t complex_mul(complex_t, complex_t);
complex_t complex_scalar_mul(complex_t, real_t);
complex_t complex_sub(complex_t, complex_t);

complex_t complex_add_real(complex_t, real_t);
complex_t complex_sub_real(complex_t, real_t);
complex_t complex_mul_real(complex_t, real_t);
complex_t complex_div_real(complex_t, real_t);

complex_t complex_add_imag(complex_t, real_t);
complex_t complex_sub_imag(complex_t, real_t);
complex_t complex_mul_imag(complex_t, real_t);
complex_t complex_div_imag(complex_t, real_t);
```

#### Exponentiation Functions

```c
complex_t complex_exp(complex_t);
complex_t complex_log_b(complex_t, complex_t);
complex_t complex_log(complex_t);
complex_t complex_sqrt(complex_t);
complex_t complex_sqrt_real(real_t);
complex_t complex_pow(complex_t, complex_t);
complex_t complex_pow_real(complex_t, real_t);
```

#### Trigonometric Functions

```c
complex_t complex_cos(complex_t);
complex_t complex_cot(complex_t);
complex_t complex_csc(complex_t);
complex_t complex_sec(complex_t);
complex_t complex_sin(complex_t);
complex_t complex_tan(complex_t);

complex_t complex_asin(complex_t);
complex_t complex_asin_real(real_t);
complex_t complex_acos(complex_t);
complex_t complex_acos_real(real_t);
complex_t complex_atan(complex_t);
complex_t complex_asec(complex_t);
complex_t complex_asec_real(real_t);
complex_t complex_acsc(complex_t);
complex_t complex_acsc_real(real_t);
complex_t complex_acot(complex_t);
```

#### Hyperbolic Functions

```c
complex_t complex_cosh(complex_t);
complex_t complex_sinh(complex_t);
complex_t complex_tanh(complex_t);
complex_t complex_sech(complex_t);
complex_t complex_csch(complex_t);
complex_t complex_coth(complex_t);
complex_t complex_asinh(complex_t);
complex_t complex_acosh(complex_t);
complex_t complex_acosh_real(real_t);
complex_t complex_atanh(complex_t);
complex_t complex_atanh_real(real_t);
complex_t complex_asech(complex_t);
complex_t complex_acsch(complex_t);
complex_t complex_acoth(complex_t);
```

#### Error and Gamma Functions

```c
complex_t complex_error(complex_t);
```

### A simple example

```c
#include <stdlib.h>
#include <stdio.h>
#include <cml.h>

int
main(int argc, char const *argv[])
{
        real_t x, y;
        complex_t z, w;

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
