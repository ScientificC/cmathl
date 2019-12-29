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

#if defined(__GNUC__) || \
	(defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901)
/* Support for C99: type _Bool is already built-in. */
#define false	0
#define true	1

#else
/* `_Bool' type must promote to `int' or `unsigned int'. */
typedef enum {
	false = 0,
	true = 1
} _Bool;

/* And those constants must also be available as macros. */
#define	false	false
#define	true	true

#endif

/* User visible type `bool' is provided as a macro which may be redefined */
#define bool _Bool

#else /* __cplusplus */
#define _Bool 	bool
#define bool 	bool
#define false 	false
#define true 	true
#endif /* __cplusplus */

/* Inform that everything is fine */
#define __bool_true_false_are_defined 1

#endif
