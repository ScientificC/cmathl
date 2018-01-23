#ifndef CML_H
#error "Never use <easings/include/functions.h> directly; include <cml.h> instead."
#endif

#ifndef CML_EASINGS_H
#define CML_EASINGS_H

real linear_interpolation(real p);
real quadratic_ease_in(real p);
real quadratic_ease_out(real p);
real quadratic_ease_in_out(real p);
real cubic_ease_in(real p);
real cubic_ease_out(real p);
real cubic_ease_in_out(real p);
real quartic_ease_in(real p);
real quartic_ease_out(real p);
real quartic_ease_in_out(real p);
real quintic_ease_in(real p);
real quintic_ease_out(real p);
real quintic_ease_in_out(real p);
real sine_ease_in(real p);
real sine_ease_out(real p);
real sine_ease_in_out(real p);
real circular_ease_in(real p);
real circular_ease_out(real p);
real circular_ease_in_out(real p);
real exponential_ease_in(real p);
real exponential_ease_out(real p);
real exponential_ease_in_out(real p);
real elastic_ease_in(real p);
real elastic_ease_out(real p);
real elastic_ease_in_out(real p);
real back_ease_in(real p);
real back_ease_out(real p);
real back_ease_in_out(real p);
real bounce_ease_in(real p);
real bounce_ease_out(real p);
real bounce_ease_in_out(real p);

#endif
