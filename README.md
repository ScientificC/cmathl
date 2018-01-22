# cml

[![Build Status](https://travis-ci.org/CMATHL/cml.svg?branch=development)](https://travis-ci.org/CMATHL/cml) [![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0) ![Version: v1.8.1](https://img.shields.io/badge/Version-v1.8.1-blue.svg)

## Introduction

CML is a compact C library with a great variety of mathematical functions.

## Using the CMATHL

Currently, CMATHL (or CML) does not have a make install option. As it is header-only, it is simple enough to copy the src header directory into your project, and setup your build to reference it.

In other words, you can include the repository in the `lib` directory and reference it in the following way:

```
gcc ... -I./lib/cml/src
```

## Configuration Macros

CML can be configured with the following preprocessors (described in the following sections of this document):

- `CML_DOUBLE_PRECISION`
- `CML_NO_EASING_FUNCTIONS`
- `CML_NO_STDBOOL`
- `CML_NO_STDINT`
- `mfloat_t`
- `mint_t`

You can define these macros during compilation time with flags:

```
gcc -DCML_NO_STDBOOL=ON -Dmfloat_t=double -DCML_DOUBLE_PRECISION=ON
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

### Math Precision

By default, CML will use single-precision internally. This can be changed by predefining `CML_DOUBLE_PRECISION`. If the macro `CML_DOUBLE_PRECISION` is defined, the math constants macros will be defined with double precision and the library will use internally the math functions for double types. Otherwise, the math constants macros will be defined with float precision and the library will internally use the math functions for float types.

## Types

CML offers at the moment two types, `real_t` and `complex_t`, both corresponding to structures. In the same way, it is recommended to work with the `real` and `complex` types, these being `real_t *` and `complex_t *` respectively.

### Real

CML defines a large number of operations for the set of real numbers. For this, the type `real` (alias of `real_t*`) is provided. Here is an example on how to work with this type of data:

```c
real x = real(2.0);
```

Another way to do the same can be the following:

```c
real x = real_new(2.0);
```

Now, let's see an example of how to apply an operation between two reals. Suppose we have a `pow` function which accepts two reals x and y, then the code would be as follows:

```c
real x, y, z;

x = real(3.0);
y = real(2.0);
z = pow(x, y);
```

### Complex

CML defines a large number of operations for the set of complex numbers. For this, the type `complex` (alias of `complex_t*`) is provided. Here is an example on how to work with this type of data:

```c
complex z = complex(1.0, 4.0);
```

Another way to do the same can be the following:

```c
complex z = complex_new(1.0, 4.0);
```

Now, let's see an example of how to apply an operation to any complex numbers. Suppose we have a `exp` function which accepts one complex z, then the code would be as follows:

```c
complex z, w;

z = complex(1.0, 4.0);
w = exp(z);
```
