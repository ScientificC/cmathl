#ifndef _CML_COMMON_H_
#error "Never use <cml/_common/default.h> directly; include <cml.h> instead."
#endif

#ifndef CML_DEFAULT_H
#define CML_DEFAULT_H

/* Check C standard */
#ifdef __STDC__
        #define PREDEF_STANDARD_C89
        #ifdef __STDC_VERSION__
                #if __STDC_VERSION__ >= 199901L
                        #define PREDEF_STANDARD_C99
                        #if __STDC_VERSION__ >= 201112L
                                #define PREDEF_STANDARD_C11
                        #endif
                #endif
        #endif
#endif

#define __CML_BEGIN_DECLS
#define __CML_END_DECLS

#ifdef __cplusplus
        #undef __CML_BEGIN_DECLS
        #undef __CML_END_DECLS

        #define __CML_BEGIN_DECLS extern "C" {
        #define __CML_END_DECLS }

        #if __cplusplus >= 199901L
                #define PREDEF_STANDARD_CPP99
                #if __cplusplus >= 201112L
                        #define PREDEF_STANDARD_CPP11
                #endif
        #endif
#endif

/*
 * Macro to test if we're using a GNU C compiler of a specific vintage
 * or later, for e.g. features that appeared in a particular version
 * of GNU C.  Usage:
 *
 *	#if __GNUC_PREREQ__(major, minor)
 *	...cool feature...
 *	#else
 *	...delete feature...
 *	#endif
 */
#ifdef __GNUC__
#define	__GNUC_PREREQ__(x, y)						\
	((__GNUC__ == (x) && __GNUC_MINOR__ >= (y)) ||			\
	 (__GNUC__ > (x)))
#else
#define	__GNUC_PREREQ__(x, y)	0
#endif

#ifndef PREDEF_STANDARD_C11
        #undef __CML_NO_GENERIC
        #define __CML_NO_GENERIC
#endif

#define __CML_ARGS_FIRST(A, ...) A

#ifndef __CML_TYPE
        #define __CML_TYPE(__e, __t) \
        __builtin_types_compatible_p(__typeof(__e), __t)
#endif

#ifndef __CML_SAME_TYPE
        #define __CML_SAME_TYPE(__a, __b) \
        __builtin_types_compatible_p(__typeof(__a), __typeof(__b))
#endif

#if defined(CML_RANGE_CHECK_OFF) || !defined(CML_RANGE_CHECK)
#define CML_RANGE_CHECK 0  /* turn off range checking by default internally */
#endif

#define RETURN_IF_NULL(x) do { if (!(x)) return; } while (0)

/* Quick boolean definition */
#include <cml/_common/bool.h>

#endif
