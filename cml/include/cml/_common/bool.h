#ifndef _CML_COMMON_H_
#error "Never use <cml/_common/bool.h> directly; include <cml.h> instead."
#endif

#ifndef CML_BOOL_H
#define CML_BOOL_H

#ifndef __cplusplus

/* For compilers that don't have the builtin _Bool type. */
#if ((defined(_MSC_VER) && _MSC_VER < 1800) || \
        (defined __GNUC__ && defined __STDC_VERSION__ && \
         __STDC_VERSION__ < 199901L && __GNUC__ < 3)) && \
         !defined(_lint)
typedef unsigned char _Bool;
#endif

#if defined __STDC__ && defined PREDEF_STANDARD_C99
#define bool  _Bool
#define true  1
#define false 0

#else   /* not C99 */

typedef enum {
        false,
        true
} bool;

#endif /* not C99 */

#else /* __cplusplus */

/* Supporting <stdbool.h> in C++ is a GCC extension.  */
#define _Bool bool
#define bool  bool
#define false false
#define true  true

#endif /* __cplusplus */

/* Signal that all the definitions are present.  */
#define __bool_true_false_are_defined 1

#endif
