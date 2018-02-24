#ifndef CML_MINMAX_H
#define CML_MINMAX_H

#define CML_H
#include "default.h"
#include "inline.h"
#include "machine.h"

__CML_BEGIN_DECLS

/* Define MAX and MIN macros/functions if they don't exist. */

/* plain old macros for general use */
#define CML_MAX(a,b) ((a) > (b) ? (a) : (b))
#define CML_MIN(a,b) ((a) < (b) ? (a) : (b))

__CML_END_DECLS

#endif
