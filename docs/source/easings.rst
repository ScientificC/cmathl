.. index:: easings functions

*****************
Easings Functions
*****************

The functions described in this chapter are declared in the header
file :file:`cml/easings.h`.

The easing functions are an implementation of the functions presented in
http://easings.net/, useful particularly for animations.
Easing is a method of distorting time to control apparent motion in animation.
It is most commonly used for slow-in, slow-out. By easing time, animated
transitions are smoother and exhibit more plausible motion.

Easing functions take a value inside the range :code:`[0.0, 1.0]` and usually will
return a value inside that same range. However, in some of the easing
functions, the returned value extrapolate that range
http://easings.net/ to see those functions).

The following types of easing functions are supported::

  Linear
  Quadratic
  Cubic
  Quartic
  Quintic
  Sine
  Circular
  Exponential
  Elastic
  Bounce
  Back

The core easing functions are implemented as C functions that take a time
parameter and return a progress parameter, which can subsequently be used
to interpolate any quantity.
