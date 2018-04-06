#ifndef CML_ERRNO_H
#define CML_ERRNO_H

#include <stdio.h>

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

#include <cml/errno/message.h>

__CML_BEGIN_DECLS

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
        CML_EOF      = 32 /* end of file */
};

void cml_error(const char *reason, const char *file, int line,
               int cml_errno);

void cml_stream_printf(const char *label, const char *file,
                       int line, const char *reason);

const char *cml_strerror(const int cml_errno);

typedef void cml_error_handler_t (const char *reason, const char *file,
                                  int line, int cml_errno);

typedef void cml_stream_handler_t (const char *label, const char *file,
                                   int line, const char *reason);

cml_error_handler_t *
cml_set_error_handler(cml_error_handler_t * new_handler);

cml_error_handler_t *
cml_set_error_handler_off(void);

cml_stream_handler_t *
cml_set_stream_handler(cml_stream_handler_t * new_handler);

FILE *cml_set_stream(FILE *new_stream);

/* CML_ERROR: call the error handler, and return the error code */

#define CML_ERROR(reason, cml_errno) \
        do { \
                cml_error(reason, __FILE__, __LINE__, cml_errno); \
                return cml_errno; \
        } while (0)

/* CML_ERROR_VAL: call the error handler, and return the given value */

#define CML_ERROR_VAL(reason, cml_errno, value) \
        do { \
                cml_error(reason, __FILE__, __LINE__, cml_errno); \
                return value; \
        } while (0)

/* CML_ERROR_VOID: call the error handler, and then return
   (for void functions which still need to generate an error) */

#define CML_ERROR_VOID(reason, cml_errno) \
        do { \
                cml_error(reason, __FILE__, __LINE__, cml_errno); \
                return; \
        } while (0)

/* CML_ERROR_NULL suitable for out-of-memory conditions */

#define CML_ERROR_NULL(reason, cml_errno) CML_ERROR_VAL(reason, cml_errno, 0)

/* Sometimes you have several status results returned from
 * function calls and you want to combine them in some sensible
 * way. You cannot produce a "total" status condition, but you can
 * pick one from a set of conditions based on an implied hierarchy.
 *
 * In other words:
 *    you have: status_a, status_b, ...
 *    you want: status = (status_a if it is bad, or status_b if it is bad,...)
 *
 * In this example you consider status_a to be more important and
 * it is checked first, followed by the others in the order specified.
 *
 * Here are some dumb macros to do this.
 */

#define CML_ERROR_SELECT_2(a,b) ((a) != CML_SUCCESS ? (a) : ((b) != CML_SUCCESS ? (b) : CML_SUCCESS))
#define CML_ERROR_SELECT_3(a,b,c) ((a) != CML_SUCCESS ? (a) : CML_ERROR_SELECT_2(b,c))
#define CML_ERROR_SELECT_4(a,b,c,d) ((a) != CML_SUCCESS ? (a) : CML_ERROR_SELECT_3(b,c,d))
#define CML_ERROR_SELECT_5(a,b,c,d,e) ((a) != CML_SUCCESS ? (a) : CML_ERROR_SELECT_4(b,c,d,e))

#define CML_STATUS_UPDATE(sp, s) do { if((s) != CML_SUCCESS) *(sp) =(s); } while (0)

__CML_END_DECLS

#endif
