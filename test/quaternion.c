#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <cml/math.h>
#include <cml/quaternion.h>
#include "include/test.h"


#define QUAT_TEST_EQUAL_S(_q, _w, _x, _y, _z) do { \
                EXPECT_FLOAT_EQ(_q.w, _w); \
                EXPECT_FLOAT_EQ(_q.x, _x); \
                EXPECT_FLOAT_EQ(_q.y, _y); \
                EXPECT_FLOAT_EQ(_q.z, _z); \
} while(0);


#define QUAT_TEST_EQUAL(_q, _w) do { \
                EXPECT_TRUE(cml_quaternion_equal(_q, _w)); \
} while(0);


int
run_struct_tests()
{
        CATEGORY_BEGIN(Quaternion)
        {
                TEST_BEGIN(Identity)
                {
                        cml_quaternion_t q = cml_quaternion_identity();

                        QUAT_TEST_EQUAL_S(q, 1.0, 0.0, 0.0, 0.0);
                        EXPECT_FLOAT_EQ(cml_quaternion_norm(q), 1.0);
                        EXPECT_FLOAT_EQ(cml_quaternion_abs(q), 1.0);
                }
                TEST_END()

                TEST_BEGIN(Conjugate)
                {
                        cml_quaternion_t qA = cml_quaternion_from_axis_anglef3(M_TAU / 4.0, 1.0, 1.0, 1.0),
                                         qB = cml_quaternion_from_axis_anglef3(M_TAU / 4.0, -1.0, -1.0, -1.0);

                        QUAT_TEST_EQUAL(qA, cml_quaternion_conj(qB));
                }
                TEST_END()

                TEST_BEGIN(Multipy Identity)
                {
                        cml_quaternion_t qA, qB, qI = cml_quaternion_identity();

                        qA.x = 1;
                        qA.y = 2;
                        qA.z = 3;
                        qA.w = 4;

                        qB = cml_quaternion_multiply(qA, qI);

                        QUAT_TEST_EQUAL(qB, qA);
                }
                TEST_END()
        }
        CATEGORY_END()

        return 0;
}
