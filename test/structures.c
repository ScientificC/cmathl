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
                        cml_quaternion_t q = cml_quaternion_identity();

                        EXPECT_FLOAT_EQ(q.w, 1.0);
                        EXPECT_FLOAT_EQ(q.x, 0.0);
                        EXPECT_FLOAT_EQ(q.y, 0.0);
                        EXPECT_FLOAT_EQ(q.z, 0.0);
                        EXPECT_FLOAT_EQ(cml_quaternion_norm(q), 1.0);
                        EXPECT_FLOAT_EQ(cml_quaternion_abs(q), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Conjugate)
                {
                        cml_quaternion_t qA = cml_quaternion_from_axis_anglef3(M_TAU / 4.0, 1.0, 1.0, 1.0),
                                     qB = cml_quaternion_from_axis_anglef3(M_TAU / 4.0, -1.0, -1.0, -1.0);

                        EXPECT_TRUE(cml_quaternion_equal(qA, cml_quaternion_conj(qB)));
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
