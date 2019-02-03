#ifndef CML_MATH_GEN_FUNC_H
#define CML_MATH_GEN_FUNC_H

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

#include <cml/complex.h>
#include <cml/math.h>

#ifndef __CML_MATH_FUNC
        #define __CML_MATH_FUNC(_type, _func) cml_ ## _type ## _ ## _func
#endif

#ifndef __CML_NO_GENERIC
        #define __CML_REAL_GENERIC_FUNC(_func, ...)                      \
                _Generic((__CML_ARGS_FIRST(__VA_ARGS__)),                \
                default : __CML_MATH_FUNC(, _func),                      \
                        double : __CML_MATH_FUNC(, _func)                \
                        )(__VA_ARGS__)

        #define __CML_COMPLEX_GENERIC_FUNC(_func, ...)                   \
                _Generic((__CML_ARGS_FIRST(__VA_ARGS__)),                \
                        cml_complex_t : __CML_MATH_FUNC(complex, _func)  \
                        )(__VA_ARGS__)

        #define __CML_BOTH_GENERIC_FUNC(_func, ...)                      \
                _Generic((__CML_ARGS_FIRST(__VA_ARGS__)),                \
                default : __CML_MATH_FUNC(, _func),                      \
                        cml_complex_t : __CML_MATH_FUNC(complex, _func), \
                        double : __CML_MATH_FUNC(, _func)                \
                        )(__VA_ARGS__)

        #define equal(X, Y) __CML_BOTH_GENERIC_FUNC(equal, X, Y)
        #define isnull(X) __CML_BOTH_GENERIC_FUNC(isnull, X)
        #define isnatural(X) __CML_REAL_GENERIC_FUNC(isnatural, X)
        #define isinteger(X) __CML_REAL_GENERIC_FUNC(isinteger, X)
        #define isgreater(X, Y) __CML_REAL_GENERIC_FUNC(isgreater, X, Y)
        #define isless(X, Y) __CML_REAL_GENERIC_FUNC(isless, X, Y)
        #define isgreaterequal(X, Y) __CML_REAL_GENERIC_FUNC( \
                isgreaterequal, \
                X, Y \
                )
        #define islessequal(X, Y) __CML_REAL_GENERIC_FUNC( \
                islessequal, \
                X, Y \
                )
        #define ismult(X, Y) __CML_REAL_GENERIC_FUNC(ismult, X, Y)
        #define add(X, Y) __CML_BOTH_GENERIC_FUNC(add, X, Y)
        #define prod(X, Y) __CML_BOTH_GENERIC_FUNC(prod, X, Y)
        #define sub(X, Y) __CML_BOTH_GENERIC_FUNC(sub, X, Y)
        #define div(X, Y) __CML_BOTH_GENERIC_FUNC(div, X, Y)
        #define sgn(X, Y) __CML_REAL_GENERIC_FUNC(sgn, X, Y)
        #define abs(X) __CML_REAL_GENERIC_FUNC(abs, X)
        #define floor(X) __CML_REAL_GENERIC_FUNC(floor, X)
        #define ceil(X) __CML_REAL_GENERIC_FUNC(ceil, X)
        #define div_e(X) __CML_REAL_GENERIC_FUNC(div_e, X)
        #define mod(X) __CML_REAL_GENERIC_FUNC(mod, X)
        #define inverse(X) __CML_BOTH_GENERIC_FUNC(inverse, X)
        #define opposite(X) __CML_BOTH_GENERIC_FUNC(opposite, X)
        #define ared(X) __CML_REAL_GENERIC_FUNC(ared, X)
        #define fact(X) __CML_REAL_GENERIC_FUNC(fact, X)
        #define exp(X) __CML_BOTH_GENERIC_FUNC(exp, X)
        #define ln(X) __CML_BOTH_GENERIC_FUNC(ln, X)
        #define log(X) __CML_BOTH_GENERIC_FUNC(log, X)
        #define log_b(X, Y) __CML_BOTH_GENERIC_FUNC(log_b, X, Y)
        #define pow(X, Y) __CML_REAL_GENERIC_FUNC(pow, X, Y)
        #define root(X) __CML_REAL_GENERIC_FUNC(root, X)
        #define sqrt(X) __CML_REAL_GENERIC_FUNC(sqrt, X)
        #define sin(X) __CML_BOTH_GENERIC_FUNC(sin, X)
        #define cos(X) __CML_BOTH_GENERIC_FUNC(cos, X)
        #define tan(X) __CML_BOTH_GENERIC_FUNC(tan, X)
        #define sec(X) __CML_BOTH_GENERIC_FUNC(sec, X)
        #define csc(X) __CML_BOTH_GENERIC_FUNC(csc, X)
        #define cot(X) __CML_BOTH_GENERIC_FUNC(cot, X)
        #define asin(X) __CML_BOTH_GENERIC_FUNC(asin, X)
        #define acos(X) __CML_BOTH_GENERIC_FUNC(acos, X)
        #define atan(X) __CML_BOTH_GENERIC_FUNC(atan, X)
        #define atan2(X, Y) __CML_BOTH_GENERIC_FUNC(atan2, X, Y)
        #define sinh(X) __CML_BOTH_GENERIC_FUNC(sinh, X)
        #define cosh(X) __CML_BOTH_GENERIC_FUNC(cosh, X)
        #define tanh(X) __CML_BOTH_GENERIC_FUNC(tanh, X)
        #define sech(X) __CML_BOTH_GENERIC_FUNC(sech, X)
        #define csch(X) __CML_BOTH_GENERIC_FUNC(csch, X)
        #define coth(X) __CML_BOTH_GENERIC_FUNC(coth, X)
        #define asinh(X) __CML_BOTH_GENERIC_FUNC(asinh, X)
        #define acosh(X) __CML_BOTH_GENERIC_FUNC(acosh, X)
        #define atanh(X) __CML_BOTH_GENERIC_FUNC(atanh, X)
        #define as_string(X) __CML_BOTH_GENERIC_FUNC(as_string)

#elif __GNUC_PREREQ__(3, 1)

#define	__tg_type(e, t)	__builtin_types_compatible_p(__typeof__(e), t)
#define	__tg_type3(e1, e2, e3, t)					\
	(__tg_type(e1, t) || __tg_type(e2, t) || __tg_type(e3, t))
#define	__tg_type_corr(e1, e2, e3, t)					\
	(__tg_type3(e1, e2, e3, t) || __tg_type3(e1, e2, e3, cml_complex_t))
#define	__tg_integer(e1, e2, e3)					\
	(((__typeof__(e1))1.5 == 1) || ((__typeof__(e2))1.5 == 1) ||	\
	    ((__typeof__(e3))1.5 == 1))
#define	__tg_is_complex(e1, e2, e3)					\
	(__tg_type3(e1, e2, e3, cml_complex_float_t) ||			\
	    __tg_type3(e1, e2, e3, cml_complex_t) ||			\
	    __tg_type3(e1, e2, e3, cml_complex_long_double_t)

#define	__tg_impl_simple(x, y, z, fn, fnf, fnl, ...)			\
	__builtin_choose_expr(__tg_type_corr(x, y, z, long double),	\
	    fnl(__VA_ARGS__), __builtin_choose_expr(			\
		__tg_type_corr(x, y, z, double) || __tg_integer(x, y, z),\
		fn(__VA_ARGS__), fnf(__VA_ARGS__)))

#define	__tg_impl_full(x, y, z, fn, fnf, fnl, cfn, cfnf, cfnl, ...)	\
	__builtin_choose_expr(__tg_is_complex(x, y, z),			\
	    __tg_impl_simple(x, y, z, cfn, cfnf, cfnl, __VA_ARGS__),	\
	    __tg_impl_simple(x, y, z, fn, fnf, fnl, __VA_ARGS__))

/* Macros to save lots of repetition below */
#define	__tg_simple(x, fn)						\
	__tg_impl_simple(x, x, x, cml_##fn, cml_##fn, cml_##fn, x)
#define	__tg_simple2(x, y, fn)						\
	__tg_impl_simple(x, x, y, cml_##fn, cml_##fn, cml_##fn, x, y)
#define	__tg_simplev(x, fn, ...)					\
	__tg_impl_simple(x, x, x, cml_##fn, cml_##fn, cml_##fn, __VA_ARGS__)
#define	__tg_full(x, fn)						\
	__tg_impl_full(x, x, x, cml_##fn, cml_##fn, cml_##fn, cml_complex_##fn, cml_complex_##fn, cml_complex_##fn, x)

/* 7.22#4 -- These macros expand to real or complex functions, depending on
 * the type of their arguments. */
#define	cml_acos(x)		__tg_full(x, acos)
#define	cml_asin(x)		__tg_full(x, asin)
#define	cml_atan(x)		__tg_full(x, atan)
#define	cml_acosh(x)	        __tg_full(x, acosh)
#define	cml_asinh(x)	        __tg_full(x, asinh)
#define	cml_atanh(x)	        __tg_full(x, atanh)
#define	cml_cos(x)		__tg_full(x, cos)
#define	cml_sin(x)		__tg_full(x, sin)
#define	cml_tan(x)		__tg_full(x, tan)
#define	cml_cosh(x)		__tg_full(x, cosh)
#define	cml_sinh(x)		__tg_full(x, sinh)
#define	cml_tanh(x)		__tg_full(x, tanh)
#define	cml_exp(x)		__tg_full(x, exp)
#define	cml_log(x)		__tg_full(x, log)
#define	cml_pow(x, y)	        __tg_impl_full(x, x, y, pow, pow, pow,	\
			                       pow, pow, pow, x, y)
#define	cml_sqrt(x)		        __tg_full(x, sqrt)

/* "The corresponding type-generic macro for abs and cabs is abs." */
#define	cml_abs(x)		__tg_impl_full(x, x, x, abs, abs, abs,	\
    			                       abs, abs, abs, x)

/* 7.22#5 -- These macros are only defined for arguments with real type. */
#define	cml_atan2(x, y)	        __tg_simple2(x, y, atan2)
#define	cml_ceil(x)		__tg_simple(x, ceil)
#define	cml_copysign(x, y)	__tg_simple2(x,cml_ y, copysign)
#define	cml_exp2(x)		__tg_simple(x, exp2)
#define	cml_expm1(x)	        __tg_simple(x, expm1)
#define	cml_floor(x)	        __tg_simple(x, floor)
#define	cml_mod(x, y)	        __tg_simple2(x,cml_ y, mod)
#define	cml_hypot(x, y)	        __tg_simple2(x,cml_ y, hypot)
#define	cml_ldexp(x, y)	        __tg_simplev(x, ldexp, x, y)
#define	cml_lgamma(x)	        __tg_simple(x, lgamma)
#define	cml_log10(x)	        __tg_simple(x, log10)
#define	cml_log1p(x)	        __tg_simple(x, log1p)
#define	cml_log2(x)		__tg_simple(x, log2)
#define	cml_logb(x)		__tg_simple(x, logb)
#define	cml_tgamma(x)	        __tg_simple(x, tgamma)

#else /* !_TGMATH_H_ */

        #error "<cml/tgmath.h> not implemented for this compiler"
#endif

#endif
