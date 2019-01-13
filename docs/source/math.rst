.. index::
   single: elementary functions
   single: mathematical functions, elementary

**********************
Mathematical Functions
**********************

For the development of this module, the functions present in many of the system 
libraries are taken as reference with the idea of offering them in CML as an 
option for when they are not present.

This chapter describes basic mathematical functions.

The functions and macros described in this chapter are defined in the
header file :file:`cml/math.h`.

.. index::
   single: mathematical constants, defined as macros
   single: numerical constants, defined as macros
   single: constants, mathematical (defined as macros)
   single: macros for mathematical constants

Mathematical Constants
======================

The library ensures that the standard BSD mathematical constants
are defined. For reference, here is a list of the constants:

.. index::
   single: e, defined as a macro
   single: pi, defined as a macro
   single: Euler's constant, defined as a macro

===================== ===================================
:macro:`M_E`          The base of exponentials, :math:`e`
:macro:`M_LOG2E`      The base-2 logarithm of :math:`e`, :math:`\log_2 (e)`
:macro:`M_LOG10E`     The base-10 logarithm of :math:`e`, :math:`\log_{10} (e)`
:macro:`M_SQRT2`      The square root of two, :math:`\sqrt 2`
:macro:`M_SQRT1_2`    The square root of one-half, :math:`\sqrt{1/2}`
:macro:`M_SQRT3`      The square root of three, :math:`\sqrt 3`
:macro:`M_PI`         The constant pi, :math:`\pi`
:macro:`M_PI_2`       Pi divided by two, :math:`\pi/2`
:macro:`M_PI_4`       Pi divided by four, :math:`\pi/4`
:macro:`M_SQRTPI`     The square root of pi, :math:`\sqrt\pi`
:macro:`M_2_SQRTPI`   Two divided by the square root of pi, :math:`2/\sqrt\pi`
:macro:`M_1_PI`       The reciprocal of pi, :math:`1/\pi`
:macro:`M_2_PI`       Twice the reciprocal of pi, :math:`2/\pi`
:macro:`M_LN10`       The natural logarithm of ten, :math:`\ln(10)`
:macro:`M_LN2`        The natural logarithm of two, :math:`\ln(2)`
:macro:`M_LNPI`       The natural logarithm of pi, :math:`\ln(\pi)`
:macro:`M_EULER`      Euler's constant, :math:`\gamma`
===================== ===================================

.. index::
   single: infinity, defined as a macro
   single: IEEE infinity, defined as a macro

Infinities and Not-a-number
===========================

.. macro:: CML_POSINF

   This macro contains the IEEE representation of positive infinity,
   :math:`+\infty`. It is computed from the expression :code:`+1.0/0.0`.

.. macro:: CML_NEGINF

   This macro contains the IEEE representation of negative infinity,
   :math:`-\infty`. It is computed from the expression :code:`-1.0/0.0`.

.. index::
   single: NaN, defined as a macro
   single: Not-a-number, defined as a macro
   single: IEEE NaN, defined as a macro

.. macro:: CML_NAN

   This macro contains the IEEE representation of the Not-a-Number symbol,
   :code:`NaN`. It is computed from the ratio :code:`0.0/0.0`.

.. function:: bool cml_isnan (double x)

   This function returns 1 if :data:`x` is not-a-number.

.. function:: bool cml_isinf (double x)

   This function returns :math:`+1` if :data:`x` is positive infinity,
   :math:`-1` if :data:`x` is negative infinity and 0
   otherwise. [#f1]_

.. function:: bool cml_isfinite (double x)

   This function returns 1 if :data:`x` is a real number, and 0 if it is
   infinite or not-a-number.

Elementary Functions
====================

The following routines provide portable implementations of functions
found in the BSD math library, e.g.  When native versions are not available
the functions described here can be used instead.  The substitution can
be made automatically if you use :code:`autoconf` to compile your
application (see :ref:`portability-functions`).

.. index::
   single: log1p
   single: logarithm, computed accurately near 1

.. function:: double cml_log1p (double x)

   This function computes the value of :math:`\log(1+x)` in a way that is
   accurate for small :data:`x`. It provides an alternative to the BSD math
   function :code:`log1p(x)`.

.. index::
   single: expm1
   single: exponential, difference from 1 computed accurately

.. function:: double cml_expm1 (double x)

   This function computes the value of :math:`\exp(x)-1` in a way that is
   accurate for small :data:`x`. It provides an alternative to the BSD math
   function :code:`expm1(x)`.

.. index::
   single: hypot
   single: euclidean distance function, hypot
   single: length, computed accurately using hypot

.. function:: double cml_hypot (double x, double y)

   This function computes the value of
   :math:`\sqrt{x^2 + y^2}` in a way that avoids overflow. It provides an
   alternative to the BSD math function :code:`hypot(x,y)`.

.. index::
   single: euclidean distance function, hypot3
   single: length, computed accurately using hypot3

.. function:: double cml_hypot3 (double x, double y, double cml_x)

   This function computes the value of
   :math:`\sqrt{x^2 + y^2 + x^2}` in a way that avoids overflow.

.. index::
   single: acosh
   single: hyperbolic cosine, inverse
   single: inverse hyperbolic cosine

.. function:: double cml_acosh (double x)

   This function computes the value of :math:`\arccosh{(x)}`. It provides an
   alternative to the standard math function :code:`acosh(x)`.

.. index::
   single: asinh
   single: hyperbolic sine, inverse
   single: inverse hyperbolic sine

.. function:: double cml_asinh (double x)

   This function computes the value of :math:`\arcsinh{(x)}`. It provides an
   alternative to the standard math function :code:`asinh(x)`.

.. index::
   single: atanh
   single: hyperbolic tangent, inverse
   single: inverse hyperbolic tangent

.. function:: double cml_atanh (double x)

   This function computes the value of :math:`\arctanh{(x)}`. It provides an
   alternative to the standard math function :code:`atanh(x)`.

.. index:: ldexp

.. function:: double cml_ldexp (double x, int e)

   This function computes the value of :math:`x * 2^e`. It provides an
   alternative to the standard math function :code:`ldexp(x,e)`.

.. index:: frexp

.. function:: double cml_frexp (double x, int *e)

   This function splits the number :data:`x` into its normalized fraction
   :math:`f` and exponent :math:`e`, such that :math:`x = f * 2^e` and
   :math:`0.5 <= f < 1`. The function returns :math:`f` and stores the
   exponent in :math:`e`. If :math:`x` is zero, both :math:`f` and :math:`e`
   are set to zero. This function provides an alternative to the standard
   math function :code:`frexp(x, e)`.

.. index:: sqrt

.. function:: double cml_sqrt (double x)

  This function returns the square root of the number :data:`x`,
  :math:`\sqrt z`. The branch cut is the negative real axis. The result
  always lies in the right half of the plane.

.. index::
  single: pow
  single: exp

.. function:: double cml_pow (double x, double a)

  The function returns the number :data:`x` raised to the double-precision
  power :data:`a`, :math:`x^a`. This is computed as :math:`\exp(\log(x)*a)`
  using logarithms and exponentials.

.. function:: double cml_exp (double x)

  This function returns the exponential of the number
  :data:`x`, :math:`\exp(x)`.

.. index:: log

.. function:: double cml_log (double x)

  This function returns the natural logarithm (base :math:`e`) of
  the number :data:`x`, :math:`\log(x)`.  The branch cut is the
  negative real axis.

.. function:: double cml_log10 (double x)

  This function returns the base-10 logarithm of
  the number :data:`x`, :math:`\log_{10} (x)`.

.. function:: double cml_log_b (double x, double b)

  This function returns the base-:data:`b` logarithm of the double-precision
  number :data:`x`, :math:`\log_b(x)`. This quantity is computed as the ratio
  :math:`\log(x)/\log(b)`.

.. index:: trigonometric functions

Trigonometric Functions
=======================

.. index::
  single: sine

.. function:: double cml_sin (double x)

  This function returns the sine of the number :data:`x`, :math:`\sin(x)`.

.. index:: cosine

.. function:: double cml_cos (double x)

  This function returns the cosine of the number :data:`x`, :math:`\cos(x)`.

.. index:: tangent

.. function:: double doublean (double x)

  This function returns the tangent of the number :data:`x`, :math:`\tan(x)`.

.. function:: double cml_sec (double x)

  This function returns the secant of the number :data:`x`,
  :math:`\sec(x) = 1/\cos(x)`.

.. function:: double cml_csc (double x)

  This function returns the cosecant of the number :data:`x`,
  :math:`\csc(x) = 1/\sin(x)`.

.. function:: double cml_cot (double x)

  This function returns the cotangent of the number :data:`x`,
  :math:`\cot(x) = 1/\tan(x)`.

.. index:: inverse trigonometric functions

Inverse Trigonometric Functions
=======================================

.. function:: double cml_asin (double x)

  This function returns the arcsine of the number :data:`x`, :math:`\arcsin(x)`.

.. function:: double cml_acos (double x)

  This function returns the arccosine of the number :data:`x`,
  :math:`\arccos(x)`.

.. function:: double cml_atan (double x)

  This function returns the arctangent of the number
  :data:`x`, :math:`\arctan(x)`.

.. function:: double cml_asec (double x)

  This function returns the arcsecant of the number :data:`x`,
  :math:`\arcsec(x) = \arccos(1/x)`.

.. function:: double cml_acsc (double x)

  This function returns the arccosecant of the number :data:`x`,
  :math:`\arccsc(x) = \arcsin(1/x)`.

.. function:: double cml_acot (double x)

  This function returns the arccotangent of the number :data:`x`,
  :math:`\arccot(x) = \arctan(1/x)`.

.. index::
  single: hyperbolic functions

Hyperbolic Functions
====================

.. function:: double cml_sinh (double x)

  This function returns the hyperbolic sine of the number
  :data:`x`, :math:`\sinh(x) = (\exp(x) - \exp(-x))/2`.

.. function:: double cml_cosh (double x)

  This function returns the hyperbolic cosine of the number
  :data:`x`, :math:`\cosh(x) = (\exp(x) + \exp(-x))/2`.

.. function:: double doubleanh (double x)

  This function returns the hyperbolic tangent of the number
  :data:`x`, :math:`\tanh(x) = \sinh(x)/\cosh(x)`.

.. function:: double cml_sech (double x)

  This function returns the hyperbolic secant of the double-precision
  number :data:`x`, :math:`\sech(x) = 1/\cosh(x)`.

.. function:: double cml_csch (double x)

  This function returns the hyperbolic cosecant of the double-precision
  number :data:`x`, :math:`\csch(x) = 1/\sinh(x)`.

.. function:: double cml_coth (double x)

  This function returns the hyperbolic cotangent of the double-precision
  number :data:`x`, :math:`\coth(x) = 1/\tanh(x)`.

.. index::
  single: inverse hyperbolic functions

Inverse Hyperbolic Functions
============================

.. function:: double cml_asinh (double x)

  This function returns the hyperbolic arcsine of the
  number :data:`x`, :math:`\arcsinh(x)`.

.. function:: double cml_acosh (double x)

  This function returns the hyperbolic arccosine of the double-precision
  number :data:`x`, :math:`\arccosh(x)`.

.. function:: double cml_atanh (double x)

  This function returns the hyperbolic arctangent of the double-precision
  number :data:`x`, :math:`\arctanh(x)`.

.. function:: double cml_asech (double x)

  This function returns the hyperbolic arcsecant of the double-precision
  number :data:`x`, :math:`\arcsech(x) = \arccosh(1/x)`.

.. function:: double cml_acsch (double x)

  This function returns the hyperbolic arccosecant of the double-precision
  number :data:`x`, :math:`\arccsch(x) = \arcsinh(1/x)`.

.. function:: double cml_acoth (double x)

  This function returns the hyperbolic arccotangent of the double-precision
  number :data:`x`, :math:`\arccoth(x) = \arctanh(1/x)`.

Small integer powers
====================

A common complaint about the standard C library is its lack of a
function for calculating (small) integer powers.  CML provides some simple
functions to fill this gap.  For reasons of efficiency, these functions
do not check for overflow or underflow conditions.

.. function::
   double cml_pow_int (double x, int n)
   double cml_pow_uint (double x, unsigned int n)

   These routines computes the power :math:`x^n` for integer :data:`n`.  The
   power is computed efficiently---for example, :math:`x^8` is computed as
   :math:`((x^2)^2)^2`, requiring only 3 multiplications.

.. function::
   double cml_pow_2 (double x)
   double cml_pow_3 (double x)
   double cml_pow_4 (double x)
   double cml_pow_5 (double x)
   double cml_pow_6 (double x)
   double cml_pow_7 (double x)
   double cml_pow_8 (double x)
   double cml_pow_9 (double x)

   These functions can be used to compute small integer powers :math:`x^2`,
   :math:`x^3`, etc. efficiently. The functions will be inlined when
   :macro:`HAVE_INLINE` is defined, so that use of these functions
   should be as efficient as explicitly writing the corresponding
   product expression::

     #include <cml/math.h>
     [...]
     double y = pow_4(3.141);  /* compute 3.141**4 */

Testing the Sign of Numbers
===========================

.. function:: double cml_sgn (double x)

   This macro returns the sign of :data:`x`. It is defined as :code:`((x) >= 0
   ? 1 : -1)`. Note that with this definition the sign of zero is positive
   (regardless of its IEEE sign bit).

Maximum and Minimum functions
=============================

Note that the following macros perform multiple evaluations of their
arguments, so they should not be used with arguments that have side
effects (such as a call to a random number generator).

.. index:: maximum of two numbers

.. macro:: CML_MAX(a, b)

   This macro returns the maximum of :data:`a` and :data:`b`. It is defined
   as :code:`((a) > (b) ? (a):(b))`.

.. index:: minimum of two numbers

.. macro:: CML_MIN(a, b)

   This macro returns the minimum of :data:`a` and :data:`b`. It is defined as
   :code:`((a) < (b) ? (a):(b))`.

Approximate Comparison of Floating Point Numbers
================================================

It is sometimes useful to be able to compare two floating point numbers
approximately, to allow for rounding and truncation errors.  The following
function implements the approximate floating-point comparison algorithm
proposed by D.E. Knuth in Section 4.2.2 of "Seminumerical
Algorithms" (3rd edition).

.. index::
   single: approximate comparison of floating point numbers
   single: safe comparison of floating point numbers
   single: floating point numbers, approximate comparison

.. function:: bool cml_cmp (double x, double y, double epsilon)

   This function determines whether :data:`x` and :data:`y` are approximately
   equal to a relative accuracy :data:`epsilon`.

   The relative accuracy is measured using an interval of size :math:`2
   \delta`, where :math:`\delta = 2^k \epsilon` and :math:`k` is the
   maximum base-2 exponent of :math:`x` and :math:`y` as computed by the
   function :func:`frexp`.

   If :math:`x` and :math:`y` lie within this interval, they are considered
   approximately equal and the function returns 0. Otherwise if :math:`x <
   y`, the function returns :math:`-1`, or if :math:`x > y`, the function returns
   :math:`+1`.

   Note that :math:`x` and :math:`y` are compared to relative accuracy, so
   this function is not suitable for testing whether a value is
   approximately zero.

   The implementation is based on the package :code:`fcmp` by T.C. Belding.

.. rubric:: Footnotes

.. [#f1] Note that the C99 standard only requires the
   system :func:`isinf` function to return a non-zero value, without the
   sign of the infinity.  The implementation in some earlier versions of
   CML used the system :func:`isinf` function and may have this behavior
   on some platforms.  Therefore, it is advisable to test the sign of
   :data:`x` separately, if needed, rather than relying the sign of the
   return value from :func:`isinf()`.
