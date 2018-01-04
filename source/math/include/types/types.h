#ifndef CML_TYPES_H
#define CML_TYPES_H

// Quick boolean definition
#ifdef CML_NO_STDBOOL
  #include "cml_bool.h"
#else
  #include <stdbool.h>
#endif

#include "real.h"
#include "rational.h"
#include "complex.h"

#endif
