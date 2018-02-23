.. index:: complex numbers

***************
Complex Numbers
***************

The functions described in this chapter provide support for complex
numbers.  The algorithms take care to avoid unnecessary intermediate
underflows and overflows, allowing the functions to be evaluated over
as much of the complex plane as possible.

.. FIXME: this still needs to be
.. done for the csc, sec, cot, csch, sech, coth functions

.. index::
   single: representations of complex numbers
   single: polar form of complex numbers
   single: complex_t

Representation of complex numbers
=================================

Complex numbers are represented using the type :code:`complex_t`. The
internal representation of this type may vary across platforms and
should not be accessed directly. The functions and macros described
below allow complex numbers to be manipulated in a portable way.

For reference, the default form of the :code:`complex_t` type is
given by the following struct::

    typedef struct _complex
    {
            union
            {
                    double p[2];
                    double parts[2];
                    struct
                    {
                            double re;
                            double im;
                    };
                    struct
                    {
                            double real;
                            double imaginary;
                    };
            };
    } complex_t;

The real and imaginary part are stored in contiguous elements of a two
element array. This eliminates any padding between the real and
imaginary parts, :code:`parts[0]` and :code:`parts[1]`, allowing the struct to
be mapped correctly onto packed complex arrays.

.. function:: complex_t complex (double x, double y)

   This function uses the rectangular Cartesian components
   :math:`(x,y)` to return the complex number :math:`z = x + y i`.
   An inline version of this function is used when :macro:`HAVE_INLINE`
   is defined.

.. function:: complex_t complex_polar (double r, double theta)

   This function returns the complex number :math:`z = r \exp(i \theta) = r
   (\cos(\theta) + i \sin(\theta))` from the polar representation
   (:data:`r`, :data:`theta`).

.. macro::
   creal (z)
   cimag (z)

   These macros return the real and imaginary parts of the complex number
   :data:`z`.

Properties of complex numbers
=============================

.. index:: argument of complex number

.. function:: double complex_arg (complex_t z)

   This function returns the argument of the complex number :data:`z`,
   :math:`\arg(z)`, where :math:`-\pi < \arg(z) <= \pi`.

.. index:: magnitude of complex number

.. function:: double complex_abs (complex_t z)

   This function returns the magnitude of the complex number :data:`z`, :math:`|z|`.

.. function:: double complex_abs2 (complex_t z)

   This function returns the squared magnitude of the complex number
   :data:`z`, :math:`|z|^2`.

.. function:: double complex_logabs (complex_t z)

   This function returns the natural logarithm of the magnitude of the
   complex number :data:`z`, :math:`\log|z|`.  It allows an accurate
   evaluation of :math:`\log|z|` when :math:`|z|` is close to one. The direct
   evaluation of :code:`log(complex_abs(z))` would lead to a loss of
   precision in this case.

.. index:: complex arithmetic

Complex arithmetic operators
============================

.. function:: complex_t complex_add (complex_t a, complex_t b)

   This function returns the sum of the complex numbers :data:`a` and
   :data:`b`, :math:`z=a+b`.

.. function:: complex_t complex_sub (complex_t a, complex_t b)

   This function returns the difference of the complex numbers :data:`a` and
   :data:`b`, :math:`z=a-b`.

.. function:: complex_t complex_mul (complex_t a, complex_t b)

   This function returns the product of the complex numbers :data:`a` and
   :data:`b`, :math:`z=ab`.

.. function:: complex_t complex_div (complex_t a, complex_t b)

   This function returns the quotient of the complex numbers :data:`a` and
   :data:`b`, :math:`z=a/b`.

.. function:: complex_t complex_add_real (complex_t a, double x)

   This function returns the sum of the complex number :data:`a` and the
   real number :data:`x`, :math:`z=a+x`.

.. function:: complex_t complex_sub_real (complex_t a, double x)

   This function returns the difference of the complex number :data:`a` and the
   real number :data:`x`, :math:`z=a-x`.

.. function:: complex_t complex_mul_real (complex_t a, double x)

   This function returns the product of the complex number :data:`a` and the
   real number :data:`x`, :math:`z=ax`.

.. function:: complex_t complex_div_real (complex_t a, double x)

   This function returns the quotient of the complex number :data:`a` and the
   real number :data:`x`, :math:`z=a/x`.

.. function:: complex_t complex_add_imag (complex_t a, double y)

   This function returns the sum of the complex number :data:`a` and the
   imaginary number :math:`iy`, :math:`z=a+iy`.

.. function:: complex_t complex_sub_imag (complex_t a, double y)

   This function returns the difference of the complex number :data:`a` and the
   imaginary number :math:`iy`, :math:`z=a-iy`.

.. function:: complex_t complex_mul_imag (complex_t a, double y)

   This function returns the product of the complex number :data:`a` and the
   imaginary number :math:`iy`, :math:`z=a*(iy)`.

.. function:: complex_t complex_div_imag (complex_t a, double y)

   This function returns the quotient of the complex number :data:`a` and the
   imaginary number :math:`iy`, :math:`z=a/(iy)`.

.. index:: conjugate of complex number

.. function:: complex_t complex_conj (complex_t z)

   This function returns the complex conjugate of the complex number
   :data:`z`, :math:`z^* = x - y i`.

.. function:: complex_t complex_inverse (complex_t z)

   This function returns the inverse, or reciprocal, of the complex number
   :data:`z`, :math:`1/z = (x - y i)/(x^2 + y^2)`.

.. function:: complex_t complex_negative (complex_t z)

   This function returns the negative of the complex number
   :data:`z`, :math:`-z = (-x) + (-y)i`.


Elementary Complex Functions
============================

.. index:: square root of complex number

.. function:: complex_t complex_sqrt (complex_t z)

   This function returns the square root of the complex number :data:`z`,
   :math:`\sqrt z`. The branch cut is the negative real axis. The result
   always lies in the right half of the complex plane.

.. function:: complex_t complex_sqrt_real (double x)

   This function returns the complex square root of the real number
   :data:`x`, where :data:`x` may be negative.

.. index::
   single: power of complex number
   single: exponentiation of complex number

.. function:: complex_t complex_pow (complex_t z, complex_t a)

   The function returns the complex number :data:`z` raised to the complex
   power :data:`a`, :math:`z^a`. This is computed as :math:`\exp(\log(z)*a)`
   using complex logarithms and complex exponentials.

.. function:: complex_t complex_pow_real (complex_t z, double x)

   This function returns the complex number :data:`z` raised to the real
   power :data:`x`, :math:`z^x`.

.. function:: complex_t complex_exp (complex_t z)

   This function returns the complex exponential of the complex number
   :data:`z`, :math:`\exp(z)`.

.. index:: logarithm of complex number

.. function:: complex_t complex_log (complex_t z)

   This function returns the complex natural logarithm (base :math:`e`) of
   the complex number :data:`z`, :math:`\log(z)`.  The branch cut is the
   negative real axis.

.. function:: complex_t complex_log10 (complex_t z)

   This function returns the complex base-10 logarithm of
   the complex number :data:`z`, :math:`\log_{10} (z)`.

.. function:: complex_t complex_log_b (complex_t z, complex_t b)

   This function returns the complex base-:data:`b` logarithm of the complex
   number :data:`z`, :math:`\log_b(z)`. This quantity is computed as the ratio
   :math:`\log(z)/\log(b)`.

.. index:: trigonometric functions of complex numbers

Complex Trigonometric Functions
===============================

.. index::
   single: sin, of complex number

.. function:: complex_t complex_sin (complex_t z)

   This function returns the complex sine of the complex number :data:`z`,
   :math:`\sin(z) = (\exp(iz) - \exp(-iz))/(2i)`.

.. index:: cosine of complex number

.. function:: complex_t complex_cos (complex_t z)

   This function returns the complex cosine of the complex number :data:`z`,
   :math:`\cos(z) = (\exp(iz) + \exp(-iz))/2`.

.. index:: tangent of complex number

.. function:: complex_t complex_tan (complex_t z)

   This function returns the complex tangent of the complex number :data:`z`,
   :math:`\tan(z) = \sin(z)/\cos(z)`.

.. function:: complex_t complex_sec (complex_t z)

   This function returns the complex secant of the complex number :data:`z`,
   :math:`\sec(z) = 1/\cos(z)`.

.. function:: complex_t complex_csc (complex_t z)

   This function returns the complex cosecant of the complex number :data:`z`,
   :math:`\csc(z) = 1/\sin(z)`.

.. function:: complex_t complex_cot (complex_t z)

   This function returns the complex cotangent of the complex number :data:`z`,
   :math:`\cot(z) = 1/\tan(z)`.

.. index:: inverse complex trigonometric functions

Inverse Complex Trigonometric Functions
=======================================

.. function:: complex_t complex_asin (complex_t z)

   This function returns the complex arcsine of the complex number :data:`z`,
   :math:`\arcsin(z)`. The branch cuts are on the real axis, less than :math:`-1`
   and greater than :math:`1`.

.. function:: complex_t complex_asin_real (double z)

   This function returns the complex arcsine of the real number :data:`z`,
   :math:`\arcsin(z)`. For :math:`z` between :math:`-1` and :math:`1`, the
   function returns a real value in the range :math:`[-\pi/2,\pi/2]`. For
   :math:`z` less than :math:`-1` the result has a real part of :math:`-\pi/2`
   and a positive imaginary part.  For :math:`z` greater than :math:`1` the
   result has a real part of :math:`\pi/2` and a negative imaginary part.

.. function:: complex_t complex_acos (complex_t z)

   This function returns the complex arccosine of the complex number :data:`z`,
   :math:`\arccos(z)`. The branch cuts are on the real axis, less than :math:`-1`
   and greater than :math:`1`.

.. function:: complex_t complex_acos_real (double z)

   This function returns the complex arccosine of the real number :data:`z`,
   :math:`\arccos(z)`. For :math:`z` between :math:`-1` and :math:`1`, the
   function returns a real value in the range :math:`[0,\pi]`. For :math:`z`
   less than :math:`-1` the result has a real part of :math:`\pi` and a
   negative imaginary part.  For :math:`z` greater than :math:`1` the result
   is purely imaginary and positive.

.. function:: complex_t complex_atan (complex_t z)

   This function returns the complex arctangent of the complex number
   :data:`z`, :math:`\arctan(z)`. The branch cuts are on the imaginary axis,
   below :math:`-i` and above :math:`i`.

.. function:: complex_t complex_asec (complex_t z)

   This function returns the complex arcsecant of the complex number :data:`z`,
   :math:`\arcsec(z) = \arccos(1/z)`.

.. function:: complex_t complex_asec_real (double z)

   This function returns the complex arcsecant of the real number :data:`z`,
   :math:`\arcsec(z) = \arccos(1/z)`.

.. function:: complex_t complex_acsc (complex_t z)

   This function returns the complex arccosecant of the complex number :data:`z`,
   :math:`\arccsc(z) = \arcsin(1/z)`.

.. function:: complex_t complex_acsc_real (double z)

   This function returns the complex arccosecant of the real number :data:`z`,
   :math:`\arccsc(z) = \arcsin(1/z)`.

.. function:: complex_t complex_acot (complex_t z)

   This function returns the complex arccotangent of the complex number :data:`z`,
   :math:`\arccot(z) = \arctan(1/z)`.

.. index::
   single: hyperbolic functions, complex numbers

Complex Hyperbolic Functions
============================

.. function:: complex_t complex_sinh (complex_t z)

   This function returns the complex hyperbolic sine of the complex number
   :data:`z`, :math:`\sinh(z) = (\exp(z) - \exp(-z))/2`.

.. function:: complex_t complex_cosh (complex_t z)

   This function returns the complex hyperbolic cosine of the complex number
   :data:`z`, :math:`\cosh(z) = (\exp(z) + \exp(-z))/2`.

.. function:: complex_t complex_tanh (complex_t z)

   This function returns the complex hyperbolic tangent of the complex number
   :data:`z`, :math:`\tanh(z) = \sinh(z)/\cosh(z)`.

.. function:: complex_t complex_sech (complex_t z)

   This function returns the complex hyperbolic secant of the complex
   number :data:`z`, :math:`\sech(z) = 1/\cosh(z)`.

.. function:: complex_t complex_csch (complex_t z)

   This function returns the complex hyperbolic cosecant of the complex
   number :data:`z`, :math:`\csch(z) = 1/\sinh(z)`.

.. function:: complex_t complex_coth (complex_t z)

   This function returns the complex hyperbolic cotangent of the complex
   number :data:`z`, :math:`\coth(z) = 1/\tanh(z)`.

.. index::
   single: inverse hyperbolic functions, complex numbers

Inverse Complex Hyperbolic Functions
====================================

.. function:: complex_t complex_asinh (complex_t z)

   This function returns the complex hyperbolic arcsine of the
   complex number :data:`z`, :math:`\arcsinh(z)`.  The branch cuts are on the
   imaginary axis, below :math:`-i` and above :math:`i`.

.. function:: complex_t complex_acosh (complex_t z)

   This function returns the complex hyperbolic arccosine of the complex
   number :data:`z`, :math:`\arccosh(z)`.  The branch cut is on the real
   axis, less than :math:`1`.  Note that in this case we use the negative
   square root in formula 4.6.21 of Abramowitz & Stegun giving
   :math:`\arccosh(z)=\log(z-\sqrt{z^2-1})`.

.. function:: complex_t complex_acosh_real (double z)

   This function returns the complex hyperbolic arccosine of
   the real number :data:`z`, :math:`\arccosh(z)`.

.. function:: complex_t complex_atanh (complex_t z)

   This function returns the complex hyperbolic arctangent of the complex
   number :data:`z`, :math:`\arctanh(z)`.  The branch cuts are on the real
   axis, less than :math:`-1` and greater than :math:`1`.

.. function:: complex_t complex_atanh_real (double z)

   This function returns the complex hyperbolic arctangent of the real
   number :data:`z`, :math:`\arctanh(z)`.

.. function:: complex_t complex_asech (complex_t z)

   This function returns the complex hyperbolic arcsecant of the complex
   number :data:`z`, :math:`\arcsech(z) = \arccosh(1/z)`.

.. function:: complex_t complex_acsch (complex_t z)

   This function returns the complex hyperbolic arccosecant of the complex
   number :data:`z`, :math:`\arccsch(z) = \arcsinh(1/z)`.

.. function:: complex_t complex_acoth (complex_t z)

   This function returns the complex hyperbolic arccotangent of the complex
   number :data:`z`, :math:`\arccoth(z) = \arctanh(1/z)`.

References and Further Reading
==============================

The implementations of the elementary and trigonometric functions are
based on the following papers,

* T. E. Hull, Thomas F. Fairgrieve, Ping Tak Peter Tang,
  "Implementing Complex Elementary Functions Using Exception
  Handling", ACM Transactions on Mathematical Software, Volume 20
  (1994), pp 215--244, Corrigenda, p553

* T. E. Hull, Thomas F. Fairgrieve, Ping Tak Peter Tang,
  "Implementing the complex arcsin and arccosine functions using exception
  handling", ACM Transactions on Mathematical Software, Volume 23
  (1997) pp 299--335

The general formulas and details of branch cuts can be found in the
following books,

* Abramowitz and Stegun, Handbook of Mathematical Functions,
  "Circular Functions in Terms of Real and Imaginary Parts", Formulas
  4.3.55--58,
  "Inverse Circular Functions in Terms of Real and Imaginary Parts",
  Formulas 4.4.37--39,
  "Hyperbolic Functions in Terms of Real and Imaginary Parts",
  Formulas 4.5.49--52,
  "Inverse Hyperbolic Functions---relation to Inverse Circular Functions",
  Formulas 4.6.14--19.

* Dave Gillespie, Calc Manual, Free Software Foundation, ISBN
  1-882114-18-3
