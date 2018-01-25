#ifndef CML_H
#error "Never use <math/include/consts.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_CONSTS_H
#define CML_MATH_CONSTS_H

/*
 * IEEE754 constants
 *
 * cml makes use of IEEE standards for the definition of its constants
 *
 */

/* Largest representable finite value. */
#ifndef HUGE
#define HUGE 3.40282347e+38F
#endif

/* The smallest representable positive normalized value. */
#ifndef TINY
#define TINY 2.2250738585072014e-308
#endif

/*
 * The largest 'Int' /x/ such that 2**(/x/-1) is approximately
 * representable as a 'Double'.
 */
#ifndef MAXEXP
#define MAXEXP 1024
#endif

/* Positive infinity. */
#ifndef INF
#define INF 1.0/0.0
#endif

/* Negative infinity. */
#ifndef NINF
#define NINF -1.0/0.0
#endif

/* Not a number. */
#ifndef NAN
#define NAN 0.0/0.0
#endif

/* Maximum possible finite value of log x */
#ifndef MAXLOG
#define MAXLOG 709.782712893384
#endif

/* Logarithm of smallest normalized double ('TINY') */
#ifndef MINLOG
#define MINLOG -708.3964185322641
#endif

#ifndef FLT_EPSILON
        #ifdef CML_DOUBLE_PRECISION
                #define FLT_EPSILON ((mfloat_t)1e-9)
        #else
                #define FLT_EPSILON ((mfloat_t)1e-5)
        #endif
#endif


/*
 * IEEE754 constants
 *
 * cml makes use of IEEE standards for the definition of its mathematical constants
 *
 */

/* pi */
#ifndef PI
#define PI 3.141592653589793238462643
#endif

/* two pi */
#ifndef TWOPI
#define TWOPI 6.28318530717958647692
#endif

/* half pi */
#ifndef HALFPI
#define HALFPI 1.57079632679489661923
#endif

/* quart pi */
#ifndef QUARTPI
#define QUARTPI 0.78539816339744830962
#endif

/* sqrt 2 */
#ifndef SQRT2
#define SQRT2 1.41421356237309504880
#endif

/* sqrt (2 * pi) */
#ifndef SQRT2PI
#define SQRT2PI 2.5066282746310005024157652848110452530069867406099383166299
#endif

/* Euler constant (e 2.71828182...) */
#ifndef E
#define E 2.7182818284590452354
#endif

/* log_2 e */
#ifndef LOG2E
#define LOG2E        1.4426950408889634074
#endif

/* log_10 e */
#ifndef LOG10E
#define LOG10E       0.43429448190325182765
#endif

/* log(sqrt((2*pi)) */
#ifndef LNSQRT2PI
#define LNSQRT2PI 0.9189385332046727417803297364056176398613974736377834128171
#endif

/*
 * The above constants are not adequate for computation using `long double's.
 * Therefore we provide as an extension constants with similar names as a
 * GNU extension.  Provide enough digits for the 128-bit IEEE quad.
 *
 */
#ifdef __USE_GNU
/* e */
#ifndef El
#define El           2.718281828459045235360287471352662498L
#endif

/* log_2 e */
#ifndef LOG2El
#define LOG2El       1.442695040888963407359924681001892137L
#endif

/* log_10 e */
#ifndef LOG10El
#define LOG10El      0.434294481903251827651128918916605082L
#endif

/* log_e 2 */
#ifndef LN2l
#define LN2l         0.693147180559945309417232121458176568L
#endif

/* log_e 10 */
#ifndef LN10l
#define LN10l        2.302585092994045684017991454684364208L
#endif

/* pi */
#ifndef PIl
#define PIl          3.141592653589793238462643383279502884L
#endif

/* pi/2 */
#ifndef HALFPIl
#define HALFPIl        1.570796326794896619231321691639751442L
#endif

/* pi/4 */
#ifndef QUARTPIl
#define QUARTPIl        0.785398163397448309615660845819875721L
#endif

/* 2/pi */
#ifndef HALFPIl
#define HALFPIl        0.636619772367581343075535053490057448L
#endif

/* 2/sqrt(pi) */
#ifndef HALFSQRTPIl
#define HALFSQRTPIl    1.128379167095512573896158903121545172L
#endif

/* sqrt(2) */
#ifndef SQRT2l
#define SQRT2l       1.414213562373095048801688724209698079L
#endif

/* 1/sqrt(2) */
#ifndef SQRT1_2l
#define SQRT1_2l     0.707106781186547524400844362104849039L
#endif

#endif
#endif
