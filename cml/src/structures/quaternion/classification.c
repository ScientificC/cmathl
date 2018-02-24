#include <stdlib.h>
#include <cml/math.h>
#include <cml/structures.h>


bool
quaternion_isnan(quaternion_t q)
{
        return real_isnan(q.w) || real_isnan(q.x) || real_isnan(q.y) || real_isnan(q.z);
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
        return real_isinf(q.w) || real_isinf(q.x) || real_isinf(q.y) || real_isinf(q.z);
}


bool
quaternion_isfinite(quaternion_t q)
{
        return real_isfinite(q.w) && real_isfinite(q.x) && real_isfinite(q.y) && real_isfinite(q.z);
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
