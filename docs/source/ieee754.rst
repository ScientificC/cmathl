.. index:: IEEE floating point

.. _chap_ieee:

******************************
IEEE floating-point arithmetic
******************************

This chapter describes functions for examining the representation of
floating point numbers and controlling the floating point environment of
your program.  The functions described in this chapter are declared in
the header file :file:`cml/ieee.h`.

.. index::
   single: IEEE format for floating point numbers
   single: bias, IEEE format
   single: exponent, IEEE format
   single: sign bit, IEEE format
   single: mantissa, IEEE format

Representation of floating point numbers
========================================

The IEEE Standard for Binary Floating-Point Arithmetic defines binary
formats for single and double precision numbers.  Each number is composed
of three parts: a *sign bit* (:math:`s`), an *exponent*
(:math:`E`) and a *fraction* (:math:`f`).  The numerical value of the
combination :math:`(s,E,f)` is given by the following formula,

.. only:: not texinfo

   .. math:: (-1)^s (1 \cdot fffff\dots) 2^E

.. only:: texinfo

   ::

      (-1)^s (1.fffff...) 2^E

.. index::
   single: normalized form, IEEE format
   single: denormalized form, IEEE format

The sign bit is either zero or one.  The exponent ranges from a minimum value
:math:`E_{min}`
to a maximum value
:math:`E_{max}`
depending on the precision.  The exponent is converted to an
unsigned number
:math:`e`, known as the *biased exponent*, for storage by adding a
*bias* parameter,

.. only:: not texinfo

   .. math:: e = E + \hbox{\it bias}

.. only:: texinfo

   ::

      e = E + bias

The sequence :math:`fffff...` represents the digits of the binary
fraction :math:`f`.  The binary digits are stored in *normalized
form*, by adjusting the exponent to give a leading digit of :math:`1`.
Since the leading digit is always 1 for normalized numbers it is
assumed implicitly and does not have to be stored.
Numbers smaller than
:math:`2^{E_{min}}`
are be stored in *denormalized form* with a leading zero,

.. only:: not texinfo

   .. math:: (-1)^s (0 \cdot fffff\dots) 2^{E_{min}}

.. only:: texinfo

   ::

      (-1)^s (0.fffff...) 2^(E_min)

.. index::
   single: zero, IEEE format
   single: infinity, IEEE format

This allows gradual underflow down to
:math:`2^{E_{min} - p}`
for :math:`p` bits of precision.
A zero is encoded with the special exponent of
:math:`2^{E_{min}-1}`
and infinities with the exponent of
:math:`2^{E_{max}+1}`.

.. index::
   single: single precision, IEEE format

The format for single precision numbers uses 32 bits divided in the
following way::

  seeeeeeeefffffffffffffffffffffff

  s = sign bit, 1 bit
  e = exponent, 8 bits  (E_min=-126, E_max=127, bias=127)
  f = fraction, 23 bits

.. index::
   single: double precision, IEEE format

The format for double precision numbers uses 64 bits divided in the
following way::

  seeeeeeeeeeeffffffffffffffffffffffffffffffffffffffffffffffffffff

  s = sign bit, 1 bit
  e = exponent, 11 bits  (E_min=-1022, E_max=1023, bias=1023)
  f = fraction, 52 bits

It is often useful to be able to investigate the behavior of a
calculation at the bit-level and the library provides functions for
printing the IEEE representations in a human-readable form.

.. float vs double vs long double
.. (how many digits are available for each)

.. function:: void ieee_fprintf_float (FILE * stream, const float * x)
              void ieee_fprintf_double (FILE * stream, const double * x)

   These functions output a formatted version of the IEEE floating-point
   number pointed to by :data:`x` to the stream :data:`stream`. A pointer is
   used to pass the number indirectly, to avoid any undesired promotion
   from :code:`float` to :code:`double`.  The output takes one of the
   following forms,

   :code:`NaN`

      the Not-a-Number symbol

   :code:`Inf, -Inf`

      positive or negative infinity

   :code:`1.fffff...*2^E, -1.fffff...*2^E`

      a normalized floating point number

   :code:`0.fffff...*2^E, -0.fffff...*2^E`

      a denormalized floating point number

   :code:`0, -0`

      positive or negative zero

   The output can be used directly in GNU Emacs Calc mode by preceding it
   with :code:`2#` to indicate binary.

.. @item [non-standard IEEE float], [non-standard IEEE double]
.. an unrecognized encoding

.. function:: void ieee_printf_float (const float * x)
              void ieee_printf_double (const double * x)

   These functions output a formatted version of the IEEE floating-point
   number pointed to by :data:`x` to the stream :code:`stdout`.

The following program demonstrates the use of the functions by printing
the single and double precision representations of the fraction
:math:`1/3`.  For comparison the representation of the value promoted from
single to double precision is also printed.

.. include:: examples/ieee.c
   :code:

The binary representation of :math:`1/3` is :math:`0.01010101...`.  The
output below shows that the IEEE format normalizes this fraction to give
a leading digit of 1::

   f = 1.01010101010101010101011*2^-2
  fd = 1.0101010101010101010101100000000000000000000000000000*2^-2
   d = 1.0101010101010101010101010101010101010101010101010101*2^-2

The output also shows that a single-precision number is promoted to
double-precision by adding zeros in the binary representation.

.. importance of using 1.234L in long double calculations

.. @example
.. int main (void)
.. @{
..   long double x = 1.0, y = 1.0;

..   x = x + 0.2;
..   y = y + 0.2L;

..   printf(" d %.20Lf\n",x);
..   printf("ld %.20Lf\n",y);

..   return 1;
.. @}

..  d 1.20000000000000001110
.. ld 1.20000000000000000004
.. @end example

.. index::
   single: IEEE exceptions
   single: precision, IEEE arithmetic
   single: rounding mode
   single: arithmetic exceptions
   single: exceptions, IEEE arithmetic
   single: division by zero, IEEE exceptions
   single: underflow, IEEE exceptions
   single: overflow, IEEE exceptions

References and Further Reading
==============================

The reference for the IEEE standard is,

* ANSI/IEEE Std 754-1985, IEEE Standard for Binary Floating-Point Arithmetic.

A more pedagogical introduction to the standard can be found in the
following paper,

* David Goldberg: What Every Computer Scientist Should Know About
  Floating-Point Arithmetic. *ACM Computing Surveys*, Vol.: 23, No.: 1
  (March 1991), pages 5--48.

* Corrigendum: *ACM Computing Surveys*, Vol.: 23, No.: 3 (September
  1991), page 413. and see also the sections by B. A. Wichmann and Charles
  B. Dunham in Surveyor's Forum: "What Every Computer Scientist Should
  Know About Floating-Point Arithmetic". *ACM Computing Surveys*,
  Vol.: 24, No.: 3 (September 1992), page 319.

A detailed textbook on IEEE arithmetic and its practical use is
available from SIAM Press,

* Michael L. Overton, *Numerical Computing with IEEE Floating Point Arithmetic*,
  SIAM Press, ISBN 0898715717.
