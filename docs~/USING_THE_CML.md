# cml

[![Build Status](https://travis-ci.org/CMATHL/cml.svg?branch=development)](https://travis-ci.org/CMATHL/cml) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT) ![Version: v1.9.7](https://img.shields.io/badge/Version-v1.9.7-blue.svg)

## Table of Contents

- [**A simple example**](#a-simple-example)
- [**Compiling and Linking**](#compiling-and-linking)

  - [Linking programs with the library](#linking-programs-with-the-library)

- [**Shared Libraries**](#shared-libraries)

- [**ANSI C Compliance**](#ansi-c-complaince)
- [**Inline functions**](#inline-functions)
- [**Compatibility with C++**](#-compatibility-with-c)

  - [An example](#an-example)

- [**Thread-safety**](#thread-safety)

## A simple example

```c
#include <stdlib.h>
#include <stdio.h>
#include <cml.h>

int
main(int argc, char const *argv[])
{
        complex_t z, w;

        z = complex(1.0, 2.0);
        w = csin(z);

        printf("%g\n", sin(2.0));
        printf("%g\n", atan2(2.0, 3.0));
        printf("%g\n", creal(w));
        printf("%g\n", cimag(w));

        return 0;
}
```

The steps needed to compile this program are described in the following sections.

## Compiling and Linking

You should include the main header file as follow:

```c
#include <cml.h>
```

If the header file is not installed on the standard search path of your compiler you will also need to provide its location to the preprocessor as a command line flag. The default location of the `cml` directory is `/usr/local/include`. A typical compilation command for a source file `example.c` with the GNU C compiler `gcc` is:

```shell
$ gcc -Wall -I/usr/local/include -c example.c
```

This results in an object file `example.o`. The default include path for gcc searches `/usr/local/include` automatically so the `-I` option can actually be omitted when CML is installed in its default location.

### Linking programs with the library

The library is installed as a single file, `libcml.a`. A shared version of the library `libcml.so` is also installed on systems that support shared libraries. The default location of these files is `/usr/local/lib`. If this directory is not on the standard search path of your linker you will also need to provide its location as a command line flag. The following example shows how to link an application with the library:

```shell
$ gcc -L/usr/local/lib example.o -lcml
```

The default library path for gcc searches `/usr/local/lib` automatically so the `-L` option can be omitted when CML is installed in its default location.

For a tutorial introduction to the GNU C Compiler and related programs, see ["An Introduction to GCC" (ISBN 0954161793)](http://www.network-theory.co.uk/gcc/intro/).

## Shared Libraries

To run a program linked with the shared version of the library the operating system must be able to locate the corresponding .so file at runtime. If the library cannot be found, the following error will occur:

```
$ ./a.out
./a.out: error while loading shared libraries:
libcml.so.0: cannot open shared object file: No such file or directory
```

To avoid this error, either modify the system dynamic linker configuration or define the shell variable `LD_LIBRARY_PATH` to include the directory where the library is installed.

For example, in the Bourne shell (`/bin/sh` or `/bin/bash`), the library search path can be set with the following commands:

```shell
$ LD_LIBRARY_PATH=/usr/local/lib
$ export LD_LIBRARY_PATH
$ ./example
```

In the C-shell (`/bin/csh` or `/bin/tcsh`) the equivalent command is:

```shell
% setenv LD_LIBRARY_PATH /usr/local/lib
```

The standard prompt for the C-shell in the example above is the percent character %, and should not be typed as part of the command.

To save retyping these commands each session they can be placed in an individual or system-wide login file.

To compile a statically linked version of the program, use the `-static` flag in `gcc`:

```shell
$ gcc -static example.o -lcml
```

## ANSI C Compliance

The library is written in ANSI C and is intended to conform to the ANSI C standard (C89). It should be portable to any system with a working ANSI C compiler.

The library does not rely on any non-ANSI extensions in the interface it exports to the user. Programs you write using CML can be ANSI compliant. Extensions which can be used in a way compatible with pure ANSI C are supported, however, via conditional compilation. This allows the library to take advantage of compiler extensions on those platforms which support them.

When an ANSI C feature is known to be broken on a particular system the library will exclude any related functions at compile-time. This should make it impossible to link a program that would use these functions and give incorrect results.

## Inline functions

The `inline` keyword is not part of the original ANSI C standard (C89) so the library does not export any inline function definitions by default. Inline functions were introduced officially in the newer C99 standard but most C89 compilers have also included `inline` as an extension for a long time.

To allow the use of inline functions, the library provides optional inline versions of performance-critical routines by conditional compilation in the exported header files.

By default, the actual form of the inline keyword is `extern inline`, which is a `gcc` extension that eliminates unnecessary function definitions.

When compiling with gcc in C99 mode (`gcc -std=c99`) the header files automatically switch to C99-compatible inline function declarations instead of extern inline.

## Compatibility with C++

The library header files automatically define functions to have `extern "C"` linkage when included in C++ programs. This allows the functions to be called directly from C++.

### An example

```c++
#include <iostream>
#include <cml.hpp>

using namespace std;
using namespace cml;

int
main(int argc, char const *argv[])
{
        complex_t z, w;

        z = complex(1.0, 2.0);
        w = csin(z);

        cout << sin(2.0) << endl;
        cout << log(3.0) << endl;
        cout << creal(w) << endl;
        cout << cimag(w) << endl;

        return 0;
}
```

## Thread-safety

The library can be used in multi-threaded programs. All the functions are thread-safe, in the sense that they do not use static variables. Memory is always associated with objects and not with functions. For functions which use workspace objects as temporary storage the workspaces should be allocated on a per-thread basis. For functions which use table objects as read-only memory the tables can be used by multiple threads simultaneously.
