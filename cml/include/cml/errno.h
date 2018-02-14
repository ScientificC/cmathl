#ifndef CML_H
#error "Never use <cml/errno.h> directly; include <cml.h> instead."
#endif

#ifndef CML_ERRNO_H
#define CML_ERRNO_H

enum {
        CML_SUCCESS  = 0,
        CML_FAILURE  = -1,
        CML_CONTINUE = -2, /* iteration has not converged */
        CML_EDOM     = 1, /* input domain error, e.g sqrt(-1) */
        CML_ERANGE   = 2, /* output range error, e.g. exp(1e100) */
        CML_EFAULT   = 3, /* invalid pointer */
        CML_EINVAL   = 4, /* invalid argument supplied by user */
        CML_EFAILED  = 5, /* generic failure */
        CML_EFACTOR  = 6, /* factorization failed */
        CML_ESANITY  = 7, /* sanity check failed - shouldn't happen */
        CML_ENOMEM   = 8, /* malloc failed */
        CML_EBADFUNC = 9, /* problem with user-supplied function */
        CML_ERUNAWAY = 10, /* iterative process is out of control */
        CML_EMAXITER = 11, /* exceeded max number of iterations */
        CML_EZERODIV = 12, /* tried to divide by zero */
        CML_EBADTOL  = 13, /* user specified an invalid tolerance */
        CML_ETOL     = 14, /* failed to reach the specified tolerance */
        CML_EUNDRFLW = 15, /* underflow */
        CML_EOVRFLW  = 16, /* overflow  */
        CML_ELOSS    = 17, /* loss of accuracy */
        CML_EROUND   = 18, /* failed because of roundoff error */
        CML_EBADLEN  = 19, /* matrix, vector lengths are not conformant */
        CML_ENOTSQR  = 20, /* matrix not square */
        CML_ESING    = 21, /* apparent singularity detected */
        CML_EDIVERGE = 22, /* integral or series is divergent */
        CML_EUNSUP   = 23, /* requested feature is not supported by the hardware */
        CML_EUNIMPL  = 24, /* requested feature not (yet) implemented */
        CML_ECACHE   = 25, /* cache limit exceeded */
        CML_ETABLE   = 26, /* table limit exceeded */
        CML_ENOPROG  = 27, /* iteration is not making progress towards solution */
        CML_ENOPROGJ = 28, /* jacobian evaluations are not improving the solution */
        CML_ETOLF    = 29, /* cannot reach the specified tolerance in F */
        CML_ETOLX    = 30, /* cannot reach the specified tolerance in X */
        CML_ETOLG    = 31, /* cannot reach the specified tolerance in gradient */
        CML_EOF      = 32/* end of file */
};

#endif
