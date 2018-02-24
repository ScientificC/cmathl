#include <cml/errno.h>


const char *
cml_strerror(const int cml_errno)
{
        switch (cml_errno)
        {
        case CML_SUCCESS:
                return "success";
        case CML_FAILURE:
                return "failure";
        case CML_CONTINUE:
                return "the iteration has not converged yet";
        case CML_EDOM:
                return "input domain error";
        case CML_ERANGE:
                return "output range error";
        case CML_EFAULT:
                return "invalid pointer";
        case CML_EINVAL:
                return "invalid argument supplied by user";
        case CML_EFAILED:
                return "generic failure";
        case CML_EFACTOR:
                return "factorization failed";
        case CML_ESANITY:
                return "sanity check failed - shouldn't happen";
        case CML_ENOMEM:
                return "malloc failed";
        case CML_EBADFUNC:
                return "problem with user-supplied function";
        case CML_ERUNAWAY:
                return "iterative process is out of control";
        case CML_EMAXITER:
                return "exceeded max number of iterations";
        case CML_EZERODIV:
                return "tried to divide by zero";
        case CML_EBADTOL:
                return "specified tolerance is invalid or theoretically unattainable";
        case CML_ETOL:
                return "failed to reach the specified tolerance";
        case CML_EUNDRFLW:
                return "underflow";
        case CML_EOVRFLW:
                return "overflow";
        case CML_ELOSS:
                return "loss of accuracy";
        case CML_EROUND:
                return "roundoff error";
        case CML_EBADLEN:
                return "matrix/vector sizes are not conformant";
        case CML_ENOTSQR:
                return "matrix not square";
        case CML_ESING:
                return "singularity or extremely bad function behavior detected";
        case CML_EDIVERGE:
                return "integral or series is divergent";
        case CML_EUNSUP:
                return "the required feature is not supported by this hardware platform";
        case CML_EUNIMPL:
                return "the requested feature is not (yet) implemented";
        case CML_ECACHE:
                return "cache limit exceeded";
        case CML_ETABLE:
                return "table limit exceeded";
        case CML_ENOPROG:
                return "iteration is not making progress towards solution";
        case CML_ENOPROGJ:
                return "jacobian evaluations are not improving the solution";
        case CML_ETOLF:
                return "cannot reach the specified tolerance in F";
        case CML_ETOLX:
                return "cannot reach the specified tolerance in X";
        case CML_ETOLG:
                return "cannot reach the specified tolerance in gradient";
        case CML_EOF:
                return "end of file";
        default:
                return "unknown error code";
        }
}
