#include <stdlib.h>
#include <cml/math.h>
#include <cml/structures.h>


bool
cml_quaternion_isnan(cml_quaternion_t q)
{
        return cml_isnan(q.w) || cml_isnan(q.x) || cml_isnan(q.y) || cml_isnan(q.z);
}


bool
cml_quaternion_nonzero(cml_quaternion_t q)
{
        if(cml_quaternion_isnan(q)) {
                return true;
        }

        return !(cml_isnull(q.w)
                 && cml_isnull(q.x)
                 && cml_isnull(q.y)
                 && cml_isnull(q.z));
}


bool
cml_quaternion_isinf(cml_quaternion_t q)
{
        return cml_isinf(q.w) || cml_isinf(q.x) || cml_isinf(q.y) || cml_isinf(q.z);
}


bool
cml_quaternion_isfinite(cml_quaternion_t q)
{
        return cml_isfinite(q.w) && cml_isfinite(q.x) && cml_isfinite(q.y) && cml_isfinite(q.z);
}


bool
cml_quaternion_equal(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return
                !cml_quaternion_isnan(q1) &&
                !cml_quaternion_isnan(q2) &&
                q1.w == q2.w &&
                q1.x == q2.x &&
                q1.y == q2.y &&
                q1.z == q2.z;
}


bool
cml_quaternion_isless(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return
                (!cml_quaternion_isnan(q1) && !cml_quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w < q2.w :
                 q1.x != q2.x ? q1.x < q2.x :
                 q1.y != q2.y ? q1.y < q2.y :
                 q1.z != q2.z ? q1.z < q2.z : false);
}


bool
cml_quaternion_isgreater(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return
                (!cml_quaternion_isnan(q1) && !cml_quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w > q2.w :
                 q1.x != q2.x ? q1.x > q2.x :
                 q1.y != q2.y ? q1.y > q2.y :
                 q1.z != q2.z ? q1.z > q2.z : false);
}
bool
cml_quaternion_islessequal(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return
                (!cml_quaternion_isnan(q1) && !cml_quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w < q2.w :
                 q1.x != q2.x ? q1.x < q2.x :
                 q1.y != q2.y ? q1.y < q2.y :
                 q1.z != q2.z ? q1.z < q2.z : true);
        /* Note that the final possibility __is 1, whereas in
           `cml_quaternion_isless` it was 0.  This distinction correctly
           accounts for equality. */
}


bool
cml_quaternion_isgreaterequal(cml_quaternion_t q1, cml_quaternion_t q2)
{
        return
                (!cml_quaternion_isnan(q1) && !cml_quaternion_isnan(q2))
                &&
                (q1.w != q2.w ? q1.w > q2.w :
                 q1.x != q2.x ? q1.x > q2.x :
                 q1.y != q2.y ? q1.y > q2.y :
                 q1.z != q2.z ? q1.z > q2.z : true);
        /* Note that the final possibility __is 1, whereas in
           `cml_quaternion_isgreater` it was 0.  This distinction correctly
           accounts for equality. */
}
