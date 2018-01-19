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
#define HUGE 3.40282347e+38F

/* The smallest representable positive normalized value. */
#define TINY 2.2250738585072014e-308

/*
 * The largest 'Int' /x/ such that 2**(/x/-1) is approximately
 * representable as a 'Double'.
 */
#define MAXEXP 1024

/* Positive infinity. */
#define INF 1/0

/* Negative infinity. */
#define NINF -1.0/0.0

/* Not a number. */
#define NAN 0.0/0.0

/* Maximum possible finite value of log x */
#define MAXLOG 709.782712893384

/* Logarithm of smallest normalized double ('TINY') */
#define MINLOG -708.3964185322641


/*
 * IEEE754 constants
 *
 * cml makes use of IEEE standards for the definition of its mathematical constants
 *
 */

/* pi */
#define PI 3.141592653589793238462643

/* two pi */
#define TWOPI 6.28318530717958647692

/* half pi */
#define HALFPI 1.57079632679489661923

/* quart pi */
#define QUARTPI 0.78539816339744830962

/* sqrt 2 */
#define SQRT2 1.41421356237309504880

/* sqrt (2 * pi) */
#define SQRT2PI 2.5066282746310005024157652848110452530069867406099383166299

/* Euler constant (e 2.71828182...) */
#define E 2.7182818284590452354

/* log_2 e */
#define LOG2E        1.4426950408889634074

/* log_10 e */
#define LOG10E       0.43429448190325182765

/* log(sqrt((2*pi)) */
#define LNSQRT2PI 0.9189385332046727417803297364056176398613974736377834128171




/*
 * The above constants are not adequate for computation using `long double's.
 * Therefore we provide as an extension constants with similar names as a
 * GNU extension.  Provide enough digits for the 128-bit IEEE quad.
 *
 */

#ifdef __USE_GNU
/* e */
#define El           2.718281828459045235360287471352662498L

/* log_2 e */
#define LOG2El       1.442695040888963407359924681001892137L

/* log_10 e */
#define LOG10El      0.434294481903251827651128918916605082L

/* log_e 2 */
#define LN2l         0.693147180559945309417232121458176568L

/* log_e 10 */
#define LN10l        2.302585092994045684017991454684364208L

/* pi */
#define PIl          3.141592653589793238462643383279502884L

/* pi/2 */
#define HALFPIl        1.570796326794896619231321691639751442L

/* pi/4 */
#define QUARTPIl        0.785398163397448309615660845819875721L

/* 2/pi */
#define HALFPIl        0.636619772367581343075535053490057448L

/* 2/sqrt(pi) */
#define HALFSQRTPIl    1.128379167095512573896158903121545172L

/* sqrt(2) */
#define SQRT2l       1.414213562373095048801688724209698079L

/* 1/sqrt(2) */
#define SQRT1_2l     0.707106781186547524400844362104849039L
#endif

#endif
