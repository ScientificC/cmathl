# CMathL

[![Mentioned in Awesome C](https://awesome.re/mentioned-badge.svg)](https://github.com/aleksandar-todorovic/awesome-c#numerical)
[![Build Status](https://travis-ci.org/ScientificC/cmathl.svg?branch=master)](https://travis-ci.org/ScientificC/cmathl) [![Documentation Status](https://readthedocs.org/projects/cml/badge/?version=latest)](http://cml.readthedocs.io/en/latest/?badge=latest) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

CMathL _(CML)_ is a pure-C math library with a great variety of mathematical functions. It is almost 100% C89/C90 compliant.

You can read the [documentation](http://cml.readthedocs.io/) to learn more about CML.

## Table of Contents

- [CMathL](#cmathl)
  - [Table of Contents](#table-of-contents)
  - [Using the CML](#using-the-cml)
  - [Running Tests](#running-tests)
  - [Configuration Macros](#configuration-macros)
    - [Bool Type](#bool-type)
    - [Integer Type](#integer-type)
    - [Float Point Type](#float-point-type)
    - [Math Functions Aliases](#math-functions-aliases)
    - [Math Library](#math-library)
  - [Build Options](#build-options)
  - [Documentation](#documentation)
  - [Can I trust this math library?](#can-i-trust-this-math-library)

      - [Bool Type](#bool-type)
      - [Integer Type](#integer-type)
      - [Float Point Type](#float-point-type)
      - [Math Functions Aliases](#math-functions-aliases)
      - [Math Library](#math-library)

  - [Build Options](#build-options)
  - [Documentation](#documentation)
  - [Can I trust this math library?](#can-i-trust-this-math-library)

## Using the CML

NOTE: This will install in /usr/local. You probably don't want that. But this is a quick start. The best thing to do is to combine this library with your other code into a larger CMake project/solution.

Install the last release with [clib](https://github.com/clibs/clib):

```shell
$ clib install ScientificC/cmathl
```

or,

install from source code: First install the libs [ScientificC/errno](https://github.com/ScientificC/errno) and [ScientificC/vector](https://github.com/ScientificC/vector). [_How to install the dependencies_](#install-dependencies)?

Then, execute the following commands on the cli:

```shell
$ git clone https://github.com/ScientificC/cmathl.git
$ cd cml
$ mkdir build
$ cd build
$ cmake .. <build options>
$ make && make install
```

[_Build Options_](#build-options)

You can read more about in the following [chapter](http://cml.readthedocs.io/en/latest/usage.html) of the documentation.

#### Install Dependencies

To install `ScientificC/errno` and `Scientific/vector` you can run the following commands on the cli:

```sh
$ cd /tmp

# to install scic/errno

$ git clone https://github.com/ScientificC/errno.git
$ cd errno
$ mkdir build && cd build
$ cmake ..
$ make && sudo make install
$ cd ..

# and to install scic/vector

$ git clone https://github.com/ScientificC/vector.git
$ cd vector
$ mkdir build && cd build
$ cmake ..
$ make && sudo make install
$ cd ..
```

## Running Tests

To run the test suite from a command prompt, using a Makefile-like generator, execute the following:

```shell
$ git clone https://github.com/ScientificC/cmathl.git
$ cd cml
$ mkdir build
$ cd build
$ cmake .. <build options>
$ make && ctest
```

[_Build Options_](#build-options)

## Configuration Macros

CML can be configured with the following preprocessors (described in the following sections of this document):

-   `CML_NO_ALIASES`
-   `CML_NO_MATH`
-   `CML_NO_STDBOOL`
-   `CML_NO_STDINT`

You can define these macros during compilation time with flags:

    cmake .. -DCML_NO_STDBOOL=ON -DCML_NO_MATH=ON

### Bool Type

If the macro `CML_NO_STDBOOL` is defined, the library will not include `stdbool.h` and will define a type or macro `bool` of type `int`, `int32_t`, `unsigned char` or something like to represent boolean values. This is useful for platforms where `stdbool.h` is not available.

### Integer Type

By default, `mint_t` is a `int32_t` if the header `stdint.h` is available. If the header `stdint.h` is not avaliable, disabled by defining `CML_NO_STDINT`, `mint_t` is a `int`. This can be changed by predefining `mint_t` as a desired type.

### Float Point Type

The float type used by CML is by default `double`.

### Math Functions Aliases

Currently, all functions defined in cml have an alias which allows greater readability when working with the library. These aliases allow, for example, functions such as `cml_sin` and`cml_complex_cosh` to have aliases that are much more readable, such as `sin` and`ccosh` respectively. Then, this could bring certain incompatibilities with libraries like `math.h`, since these aliases will be defined as long as they are not indicated otherwise, and this may not be compatible with math definitions.

By defining `CML_NO_ALIASES`, these aliases will not be defined, leaving only the original functions names and, thus, allowing greater compatibility.

### Math Library

By default, cml will use some math functions from the header `math.h` if it is available. If the header `math.h` is not avaliable, disabled by defining `CML_NO_MATH`, cml will use its own definition of them.

## Build Options

-   CML_BUILD_SHARED: (Default ON) Controls if the shared library is built

```shell
$ cmake .. -DCML_BUILD_SHARED=ON
$ cmake .. -DCML_BUILD_SHARED=OFF
```

-   CML_BUILD_STATIC: (Default ON) Controls if the static library is built

```shell
$ cmake .. -DCML_BUILD_STATIC=ON
$ cmake .. -DCML_BUILD_STATIC=OFF
```

-   CML_BUILD_TESTS: (Default ON) Build the unit tests

```shell
$ cmake .. -DCML_BUILD_TESTS=ON
$ cmake .. -DCML_BUILD_TESTS=OFF
```

-   CMAKE_BUILD_TYPE: (Default Release) Set this to 'Release' or 'Debug'

```shell
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake .. -DCMAKE_BUILD_TYPE=Debug
```

-   CMAKE_INSTALL_PREFIX: (Default /usr/local) Allows you to specify where `make install` sends the output.

```shell
$ cmake .. -DCMAKE_INSTALL_PREFIX=~/cml/
$ cmake .. -DCMAKE_INSTALL_PREFIX=~/Projects/myproject/
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/
```

## Documentation

A great way to learn how to use the library is to review the [unit tests](./test/), [examples](./example) and [documentation](http://cml.readthedocs.io/).

## Can I trust this math library?

A goal of the unit tests is to test each function against `CML_FLT_EPSILON` and `CML_DBL_EPSILON` which are defined in cml.h, currently as `1.1920928955078125e-07` and `0.2204460492503131e-16`, respectively. A number of functions do not yet have unit tests proving epsilon, but more are coming.
