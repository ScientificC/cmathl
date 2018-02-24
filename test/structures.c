#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml/math.h>
#include <cml/structures.h>
#include "include/test.h"


int
run_struct_tests()
{
        CATEGORY_BEGIN(Quaternion)
        {
                TEST_BEGIN(Identity)
                {
                        quaternion_t q = quaternion_identity();

                        EXPECT_FLOAT_EQ(q.w, 1.0);
                        EXPECT_FLOAT_EQ(q.x, 0.0);
                        EXPECT_FLOAT_EQ(q.y, 0.0);
                        EXPECT_FLOAT_EQ(q.z, 0.0);
                        EXPECT_FLOAT_EQ(quaternion_norm(q), 1.0);
                        EXPECT_FLOAT_EQ(quaternion_abs(q), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Conjugate)
                {
                        quaternion_t qA = quaternion_from_axis_anglef3(M_TAU / 4.0, 1.0, 1.0, 1.0),
                                     qB = quaternion_from_axis_anglef3(M_TAU / 4.0, -1.0, -1.0, -1.0);

                        EXPECT_TRUE(quaternion_equal(qA, quaternion_conj(qB)));
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
