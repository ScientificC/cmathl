#ifndef CONSTS_H
#define CONSTS_H

/*
* IEE754 constants
*
* cml makes use of IEEE standards for the definition of its constants
*
*/

/* Largest representable finite value. */
#define HUGE = 1.7976931348623157e308

/* The smallest representable positive normalized value. */
#define TINY = 2.2250738585072014e-308

/*
* The largest 'Int' /x/ such that 2**(/x/-1) is approximately
* representable as a 'Double'.
*/
#define MAXEXP = 1024

/* Positive infinity. */
#define INF = 1/0

/* Negative infinity. */
#define NINF = -1/0

/* Not a number. */
#define NaN = 0/0

/* Maximum possible finite value of @log x@ */
#define MAXLOG = 709.782712893384

/* Logarithm of smallest normalized double ('TINY') */
#define MINLOG = -708.3964185322641


/*
* IEE754 constants
*
* cml makes use of IEEE standards for the definition of its mathematical constants
*
*/

/* @pi@ */
#define PI = 3.141592653589793238462643

/* @two pi@ */
#define TWOPI = 6.28318530717958647692

/* @half pi@ */
#define HALFPI = 1.57079632679489661923

/* @quart pi@ */
#define QUARTPI = 0.78539816339744830962

/* @sqrt 2@ */
#define SQRT2 = 1.4142135623730950488016887242096980785696718753769480731766

/* @sqrt (2 * pi)@ */
#define SQRT2PI = 2.5066282746310005024157652848110452530069867406099383166299

/* Euler constant (e = 2.71828182...) */
#define E = 2.71828182845904523536

/* @log(sqrt((2*pi))@ */
#define LNSQRT2PI = 0.9189385332046727417803297364056176398613974736377834128171

/* Euler–Mascheroni constant (γ = 0.57721...) */
#define EM = 0.5772156649015328606065121


#endif
