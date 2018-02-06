#include <stdlib.h>
#include <math.h>

#define CML_NO_ALIASES

#include <cml.h>

#ifndef PREDEF_STANDARD_C99
/* FIXME: classification functions are not ANSI C complaint, should be compatible
   with c89 and c99. */

        #ifndef isnan
                #define isnan(X) __isnan(X)
        #endif

        #ifndef isinf
                #define isinf(X) __isinf(X)
        #endif

        #ifndef isfinite
                #define isfinite(X) __finite(X)
        #endif
#endif

bool
quaternion_isnan(quaternion_t q)
{
        return isnan(q.w) || isnan(q.x) || isnan(q.y) || isnan(q.z);
}


bool
quaternion_nonzero(quaternion_t q)
{
        if(quaternion_isnan(q)) {
                return true;
        }

        return !(real_isnull(q.w)
                 && real_isnull(q.x)
                 && real_isnull(q.y)
                 && real_isnull(q.z));
}


bool
quaternion_isinf(quaternion_t q)
{
        return isinf(q.w) || isinf(q.x) || isinf(q.y) || isinf(q.z);
}


bool
quaternion_isfinite(quaternion_t q)
{
        return isfinite(q.w) && isfinite(q.x) && isfinite(q.y) && isfinite(q.z);
}


bool
quaternion_equal(quaternion_t q1, quaternion_t q2)
{
        return
                !quaternion_isnan(q1) &&
                !quaternion_isnan(q2) &&
                q1.w == q2.w &&
                q1.x == q2.x &&
                q1.y == q2.y &&
                q1.z == q2.z;
}


bool
quaternion_isless(quaternion_t q1, quaternion_t q2)
{
        return
                (!quaternion_isnan(q1) && !quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w < q2.w :
                 q1.x != q2.x ? q1.x < q2.x :
                 q1.y != q2.y ? q1.y < q2.y :
                 q1.z != q2.z ? q1.z < q2.z : false);
}


bool
quaternion_isgreater(quaternion_t q1, quaternion_t q2)
{
        return
                (!quaternion_isnan(q1) && !quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w > q2.w :
                 q1.x != q2.x ? q1.x > q2.x :
                 q1.y != q2.y ? q1.y > q2.y :
                 q1.z != q2.z ? q1.z > q2.z : false);
}
bool
quaternion_islessequal(quaternion_t q1, quaternion_t q2)
{
        return
                (!quaternion_isnan(q1) && !quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w < q2.w :
                 q1.x != q2.x ? q1.x < q2.x :
                 q1.y != q2.y ? q1.y < q2.y :
                 q1.z != q2.z ? q1.z < q2.z : true);
        /* Note that the final possibility __is 1, whereas in
           `quaternion_isless` it was 0.  This distinction correctly
           accounts for equality. */
}


bool
quaternion_isgreaterequal(quaternion_t q1, quaternion_t q2)
{
        return
                (!quaternion_isnan(q1) && !quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w > q2.w :
                 q1.x != q2.x ? q1.x > q2.x :
                 q1.y != q2.y ? q1.y > q2.y :
                 q1.z != q2.z ? q1.z > q2.z : true);
        /* Note that the final possibility __is 1, whereas in
           `quaternion_isgreater` it was 0.  This distinction correctly
           accounts for equality. */
}
