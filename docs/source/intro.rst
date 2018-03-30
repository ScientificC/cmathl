.. index::
   license of CML
   MIT

************
Introduction
************

The C Math Library (CML) is a collection of routines for
numerical computing.  The routines have been written from scratch in C,
and present a modern Applications Programming Interface
(API) for C programmers, allowing wrappers to be written for very
high level languages.  The source code is distributed under the MIT License.

In summary, CML is a pure mathematical C library with a wide variety of
mathematical functions that seeks to be close to complying with
ANSI C for portability.  It is free software under the MIT License.

Routines available in CML
=========================

The library covers a wide range of topics in numerical computing.
Routines are available for the following areas,

===========================  ===========================  ===========================
Mathematical Functions       Complex Numbers              Special Functions
Quaternions                  Differential Equations       Numerical Differentiation
IEEE Floating-Point          Physical Constants           Easing Functions
Statistics                   Blocks                       Vectors and Matrices
===========================  ===========================  ===========================

The use of these routines is described in this manual.  Each chapter
provides detailed definitions of the functions, followed by example
programs and references to the articles on which the algorithms are
based.

Conventions used in this manual
===============================

.. index::
   single: dollar sign $, shell prompt

This manual contains many examples which can be typed at the keyboard.
A command entered at the terminal is shown like this::

   $ command

The first character on the line is the terminal prompt, and should not
be typed.  The dollar sign $ is used as the standard prompt in
this manual, although some systems may use a different character.

The examples assume the use of the GNU operating system.  There may be
minor differences in the output on other systems.  The commands for
setting environment variables use the Bourne shell syntax of the
standard GNU shell (:code:`bash`).
