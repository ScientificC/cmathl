.. index::
   single: standards conformance, ANSI C
   single: ANSI C, use of
   single: C extensions, compatible use of
   single: compatibility

*****************
Using the Library
*****************

This chapter describes how to compile programs that use CML, and
introduces its conventions.

An Example Program
==================

The following short program demonstrates the use of the library

.. include:: examples/intro.c
   :code:

The steps needed to compile this program are described
in the following sections.

.. index::
   single: compiling programs, include paths
   single: including CML header files
   single: header files, including

Compiling and Linking
=====================

The library header files are installed in their own :file:`cml`
directory.  You should write any preprocessor include statements with a
:file:`cml/` directory prefix thus::

    #include <cml/math.h>

or simply requiring all the modules in the following way::

    #include <cml.h>

If the directory is not installed on the standard search path of your
compiler you will also need to provide its location to the preprocessor
as a command line flag.  The default location of the main header file
:file:`cml.h` and the :file:`cml` directory is :file:`/usr/local/include`.
A typical compilation command for a source file :file:`example.c` with
the GNU C compiler :code:`gcc` is::

    $ gcc -Wall -I/usr/local/include -c example.c

This results in an object file :file:`example.o`. The default
include path for :code:`gcc` searches :file:`/usr/local/include` automatically so
the :code:`-I` option can actually be omitted when CML is installed
in its default location.

.. index::
   single: compiling programs, library paths
   single: linking with CML libraries
   single: libraries, linking with

Linking programs with the library
---------------------------------

The library is installed as a single file, :file:`libcml.a`.  A shared
version of the library :file:`libcml.so` is also installed on systems
that support shared libraries.  The default location of these files is
:file:`/usr/local/lib`.  If this directory is not on the standard search
path of your linker you will also need to provide its location as a
command line flag. The following example shows how to link an application
with the library::

    $ gcc -L/usr/local/lib example.o -lcml

The default library path for :code:`gcc` searches :file:`/usr/local/lib`
automatically so the :code:`-L` option can be omitted when CML is
installed in its default location.

For a tutorial introduction to the GNU C Compiler and related programs,
see "An Introduction to GCC" (ISBN 0954161793). [#f1]_

Shared Libraries
================

To run a program linked with the shared version of the library the
operating system must be able to locate the corresponding :file:`.so`
file at runtime.  If the library cannot be found, the following error
will occur::

    $ ./a.out
    ./a.out: error while loading shared libraries:
    libcml.so.0: cannot open shared object file: No such file or directory

To avoid this error, either modify the system dynamic linker
configuration [#f2]_ or
define the shell variable :code:`LD_LIBRARY_PATH` to include the
directory where the library is installed.

For example, in the Bourne shell (:code:`/bin/sh` or :code:`/bin/bash`),
the library search path can be set with the following commands::

    $ LD_LIBRARY_PATH=/usr/local/lib
    $ export LD_LIBRARY_PATH
    $ ./example

In the C-shell (:code:`/bin/csh` or :code:`/bin/tcsh`) the equivalent
command is::

    % setenv LD_LIBRARY_PATH /usr/local/lib

The standard prompt for the C-shell in the example above is the percent
character %, and should not be typed as part of the command.

To save retyping these commands each session they can be placed in an
individual or system-wide login file.

To compile a statically linked version of the program, use the
:code:`-static` flag in :code:`gcc`::

    $ gcc -static example.o -lcml

ANSI C Compliance
=================

The library is written in ANSI C and is intended to conform to the ANSI
C standard (C89).  It should be portable to any system with a working
ANSI C compiler.

The library does not rely on any non-ANSI extensions in the interface it
exports to the user.  Programs you write using CML can be ANSI
compliant.  Extensions which can be used in a way compatible with pure
ANSI C are supported, however, via conditional compilation.  This allows
the library to take advantage of compiler extensions on those platforms
which support them.

When an ANSI C feature is known to be broken on a particular system the
library will exclude any related functions at compile-time.  This should
make it impossible to link a program that would use these functions and
give incorrect results.

To avoid namespace conflicts all exported function names and variables
have the prefix :code:`cml_`, while exported macros have the prefix
:code:`CML_`.

.. index::
   single: inline functions
   single: CML_EXTERN_INLINE
   single: C99, inline keyword
   single: extern inline

.. _sec_inline-functions:

Inline functions
================

The :code:`inline` keyword is not part of the original ANSI C standard (C89)
so the library does not export any inline function definitions by default.
Inline functions were introduced officially in the newer C99 standard but
most C89 compilers have also included :code:`inline` as an extension for a
long time.

To allow the use of inline functions, the library provides optional inline
versions of performance-critical routines by conditional compilation in the
exported header files.

By default, the actual form of the inline keyword is :code:`extern inline`,
which is a :code:`gcc` extension that eliminates unnecessary function
definitions.

When compiling with gcc in C99 mode (`gcc -std=c99`) the header files
automatically switch to C99-compatible inline function declarations instead
of extern inline.

Long double
===========
.. index:
   long double

In general, the algorithms in the library are written for double
precision only.  The :code:`long double` type is not supported for
every computation.

One reason for this choice is that the precision of :code:`long double`
is platform dependent.  The IEEE standard only specifies the minimum
precision of extended precision numbers, while the precision of
:code:`double` is the same on all platforms.

However, it is sometimes necessary to interact with external data in
long-double format, so the structures datatypes include
long-double versions.

It should be noted that in some system libraries the :code:`stdio.h`
formatted input/output functions :code:`printf` and :code:`scanf` are
not implemented correctly for :code:`long double`.  Undefined or
incorrect results are avoided by testing these functions during the
:code:`configure` stage of library compilation and eliminating certain
CML functions which depend on them if necessary.  The corresponding
line in the :code:`configure` output looks like this::

    checking whether printf works with long double... no

Consequently when :code:`long double` formatted input/output does not
work on a given system it should be impossible to link a program which
uses CML functions dependent on this.

If it is necessary to work on a system which does not support formatted
:code:`long double` input/output then the options are to use binary
formats or to convert :code:`long double` results into :code:`double` for
reading and writing.

Compatibility with C++
======================

The library header files automatically define functions to have
:code:`extern "C"` linkage when included in C++ programs.  This allows
the functions to be called directly from C++.

Thread-safety
=============

The library can be used in multi-threaded programs.  All the functions
are thread-safe, in the sense that they do not use static variables.
Memory is always associated with objects and not with functions.  For
functions which use *workspace* objects as temporary storage the
workspaces should be allocated on a per-thread basis.  For functions
which use *table* objects as read-only memory the tables can be used
by multiple threads simultaneously.

.. rubric:: Footnotes

.. [#f1] http://www.network-theory.co.uk/gcc/intro/
.. [#f2] :file:`/etc/ld.so.conf` on GNU/Linux systems
