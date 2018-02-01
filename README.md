# cml

[![Build Status](https://travis-ci.org/CMATHL/cml.svg?branch=master)](https://travis-ci.org/CMATHL/cml) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT) ![Version: v1.9.3](https://img.shields.io/badge/Version-v1.9.3-blue.svg)

## Introduction

CML is a pure-C math library with a great variety of mathematical functions. It is almost 100% C89/C90 compliant.

You can read the following [file](./docs/CML.md) to learn more about CML.

## Using the CMATHL

NOTE: This will install in /usr. You probably don't want that. But this is a quick start. The best thing to do is to combine this library with your other code into a larger CMake project/solution.

```shell
$ git clone https://github.com/CMATHL/cml.git
$ cd cml
$ mkdir build
$ cd build
$ cmake .. <build options>
$ make && make install
```

[_Build Options_](#build-options)

## Configuration Macros

CML can be configured with the following preprocessors (described in the following sections of this document):

- `CML_NO_ALIASES`
- `CML_NO_EASING_FUNCTIONS`
- `CML_NO_STDBOOL`
- `CML_NO_STDINT`
- `CML_SINGLE_PRECISION`
- `mfloat_t`
- `mint_t`

You can define these macros during compilation time with flags:

```
cmake .. -DCML_NO_STDBOOL=ON -Dmfloat_t=float -DCML_SINGLE_PRECISION=ON
```

### Bool Type

If the macro `CML_NO_STDBOOL` is defined, the library will not include `stdbool.h` and will define a type or macro `bool` of type `int`, `int32_t` or something like to represent boolean values. This is useful for platforms where `stdbool.h` is not available.

### Integer Type

By default, `mint_t` is a `int32_t` if the header `stdint.h` is available. If the header `stdint.h` is not avaliable, disabled by defining `CML_NO_STDINT`, `mint_t` is a `int`. This can be changed by predefining `mint_t` as a desired type.

### Float-Point Type

The float type used by CML is defined by the macro `mfloat_t`, which is by default `double`.

### Easing Functions

The easing functions are an implementation of the functions presented in [easings.net](http://easings.net/), useful particularly for animations. Easing is a method of distorting time to control apparent motion in animation. It is most commonly used for slow-in, slow-out. By easing time, animated transitions are smoother and exhibit more plausible motion.

Easing functions take a value inside the range `[0.0, 1.0]` and usually will return a value inside that same range. However, in some of the easing functions, the returned value extrapolate that range (Check the [easings.net](http://easings.net/) to see those functions).

By defining `CML_NO_EASING_FUNCTIONS`, the easing functions will not be defined.

### Math functions aliases

Currently, all functions defined in cml have an alias which allows greater readability when working with the library. These aliases allow, for example, functions such as `real_sin` and`complex_cosh` to have aliases that are much more readable, such as `sin` and`ccosh` respectively. Then, this could bring certain incompatibilities with libraries like `math.h`, since these aliases will be defined as long as they are not indicated otherwise, and this may not be compatible with math definitions.

By defining `CML_NO_ALIASES`, these aliases will not be defined, leaving only the original functions names and, thus, allowing greater compatibility.

### Math Precision

By default, CML will use double-precision internally. This can be changed by predefining `CML_SINGLE_PRECISION`. If the macro `CML_SINGLE_PRECISION` is defined, the math constants macros will be defined with single precision and the library will use internally the math functions for float types. Otherwise, the math constants macros will be defined with double precision and the library will internally use the math functions for double types.

## Build Options

- CML_BUILD_SHARED: (Default ON) Controls if the shared library is built

```shell
$ cmake .. -DCML_BUILD_SHARED=ON
$ cmake .. -DCML_BUILD_SHARED=OFF
```

- CML_BUILD_STATIC: (Default ON) Controls if the static library is built

```shell
$ cmake .. -DCML_BUILD_STATIC=ON
$ cmake .. -DCML_BUILD_STATIC=OFF
```

- CML_BUILD_TESTS: (Default ON) Build the unit tests

```shell
$ cmake .. -DCML_BUILD_TESTS=ON
$ cmake .. -DCML_BUILD_TESTS=OFF
```

- CMAKE_BUILD_TYPE: (Default Release) Set this to 'Release' or 'Debug'

```shell
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
```

- CMAKE_INSTALL_PREFIX: (Default /usr) Allows you to specify where `make install` sends the output.

```shell
$ cmake .. -DCMAKE_INSTALL_PREFIX=~/cml/
$ cmake .. -DCMAKE_INSTALL_PREFIX=~/Projects/myproject/
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/
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

Compile and run

```shell
$ gcc -lcml main.c -o main && ./main
```

or using C++,

```c++
#include <iostream>
#include <cml.hpp>

using namespace std;
using namespace cml;

int
main(int argc, char const *argv[])
{
        real_t x, y;
        complex_t z, w;

        x = 2.0;
        y = 3.0;
        z = complex(1.0, 2.0);
        w = csin(z);

        cout << sin(x) << endl;
        cout <<  log(y) << endl;
        cout <<  creal(w) << endl;
        cout <<  cimag(w) << endl;

        return 0;
}
```

Compile and run

```shell
$ g++ -lcml main.cpp -o main && ./main
```
