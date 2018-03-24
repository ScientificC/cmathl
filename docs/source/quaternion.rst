.. index:: quaternions

***********
Quaternions
***********

The functions described in this chapter provide support for quaternions.
The algorithms take care to avoid unnecessary intermediate underflows
and overflows, allowing the functions to be evaluated over as much of
the quaternion plane as possible.

The quaternion types, functions and arithmetic operations are defined in
the header file :file:`cml/quaternion.h`.

.. index::
   single: representations of quaternion
   single: cml_quaternion_t


Representation of quaternions
=================================

Quaternions are represented using the type :code:`cml_quaternion_t`. The
internal representation of this type may vary across platforms and
should not be accessed directly. The functions and macros described
below allow quaternions to be manipulated in a portable way.

For reference, the default form of the :code:`cml_quaternion_t` type is
given by the following struct::

  typedef struct
  {
          union
          {
                  double q[4];
                  struct
                  {
                          double w, x, y, z;
                  };
                  struct
                  {
                          double a, i, j, k;
                  };
          };
  } cml_quaternion_t;
