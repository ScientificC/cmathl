#ifndef CML_H
#error "Never use <cml/math/consts.h> directly; include <cml/math.h> instead."
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

/* Positive infinity. */
#ifndef CML_POSINF
#define CML_POSINF 1.0/0.0
#endif

/* Negative infinity. */
#ifndef CML_NEGINF
#define CML_NEGINF -1.0/0.0
#endif

/* Not a number. */
#ifndef CML_NAN
#define CML_NAN 0.0/0.0
#endif

/* Maximum possible finite value of log x */
#ifndef MAXLOG
#define MAXLOG 709.782712893384
#endif

/* Logarithm of smallest normalized double ('TINY') */
#ifndef MINLOG
#define MINLOG -708.3964185322641
#endif


/*
 * IEEE754 constants
 *
 * cml makes use of IEEE standards for the definition of its mathematical constants
 *
 */

#ifndef M_E
#define M_E        2.71828182845904523536028747135      /* e */
#endif

#ifndef M_LOG2E
#define M_LOG2E    1.44269504088896340735992468100      /* log_2 (e) */
#endif

#ifndef M_LOG10E
#define M_LOG10E   0.43429448190325182765112891892      /* log_10 (e) */
#endif

#ifndef M_SQRT2
#define M_SQRT2    1.41421356237309504880168872421      /* sqrt(2) */
#endif

#ifndef M_SQRT1_2
#define M_SQRT1_2  0.70710678118654752440084436210      /* sqrt(1/2) */
#endif


#ifndef M_SQRT3
#define M_SQRT3    1.73205080756887729352744634151      /* sqrt(3) */
#endif

#ifndef M_PI
#define M_PI       3.14159265358979323846264338328      /* pi */
#endif

#ifndef M_PI_2
#define M_PI_2     1.57079632679489661923132169164      /* pi/2 */
#endif

#ifndef M_PI_4
#define M_PI_4     0.78539816339744830961566084582     /* pi/4 */
#endif

#ifndef M_SQRTPI
#define M_SQRTPI   1.77245385090551602729816748334      /* sqrt(pi) */
#endif

#ifndef M_2_SQRTPI
#define M_2_SQRTPI 1.12837916709551257389615890312      /* 2/sqrt(pi) */
#endif

#ifndef M_1_PI
#define M_1_PI     0.31830988618379067153776752675      /* 1/pi */
#endif

#ifndef M_2_PI
#define M_2_PI     0.63661977236758134307553505349      /* 2/pi */
#endif

#ifndef M_LN10
#define M_LN10     2.30258509299404568401799145468      /* ln(10) */
#endif

#ifndef M_LN2
#define M_LN2      0.69314718055994530941723212146      /* ln(2) */
#endif

#ifndef M_LNPI
#define M_LNPI     1.14472988584940017414342735135      /* ln(pi) */
#endif

#ifndef M_EULER
#define M_EULER    0.57721566490153286060651209008      /* Euler constant */
#endif

#ifndef M_TAU
#define M_TAU      (2.0*M_PI)
#endif

/*
 * The above constants are not adequate for computation using `long double's.
 * Therefore we provide as an extension constants with similar names as a
 * GNU extension.  Provide enough digits for the 128-bit IEEE quad.
 *
 */
#ifdef __USE_GNU

#ifndef M_El
#define M_El           2.718281828459045235360287471352662498L /* e */
#endif

#ifndef M_LOG2El
#define M_LOG2El       1.442695040888963407359924681001892137L /* log_2 e */
#endif

#ifndef M_LOG10El
#define M_LOG10El      0.434294481903251827651128918916605082L /* log_10 e */
#endif

#ifndef M_LN2l
#define M_LN2l         0.693147180559945309417232121458176568L /* log_e 2 */
#endif

#ifndef M_LN10l
#define M_LN10l        2.302585092994045684017991454684364208L /* log_e 10 */
#endif

#ifndef M_PIl
#define M_PIl          3.141592653589793238462643383279502884L /* pi */
#endif

#ifndef M_PI_2l
#define M_PI_2l        1.570796326794896619231321691639751442L /* pi/2 */
#endif

#ifndef M_PI_4l
#define M_PI_4l        0.785398163397448309615660845819875721L /* pi/4 */
#endif

#ifndef M_1_PIl
#define M_1_PIl        0.318309886183790671537767526745028724L /* 1/pi */
#endif

#ifndef M_2_PIl
#define M_2_PIl        0.636619772367581343075535053490057448L /* 2/pi */
#endif

#ifndef M_2_SQRTPIl
#define M_2_SQRTPIl    1.128379167095512573896158903121545172L /* 2/sqrt(pi) */
#endif

#ifndef M_SQRT2l
#define M_SQRT2l       1.414213562373095048801688724209698079L /* sqrt(2) */
#endif

#ifndef M_SQRT1_2l
#define M_SQRT1_2l     0.707106781186547524400844362104849039L /* 1/sqrt(2) */
#endif

#endif
#endif
