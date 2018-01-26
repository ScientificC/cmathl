#ifndef CML_H
#error "Never use <structures/include/types/matrix3.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_TYPES_MATRIX3_H
#define CML_MATH_TYPES_MATRIX3_H

typedef struct _matrix3
{
        union
        {
                real_t m[9]; /* row-major numbering */
                struct
                {
                        /* reference the matrix [row][column] */
                        real_t m33[3][3];
                };
                struct
                {
                        /* indexed (column-major numbering) */
                        real_t i00, i03, i06;
                        real_t i01, i04, i07;
                        real_t i02, i05, i08;
                };
                struct
                {
                        /* col-row */
                        real_t c00, c10, c20;
                        real_t c01, c11, c21;
                        real_t c02, c12, c22;
                };
                struct
                {
                        /* row-col */
                        real_t r00, r01, r02;
                        real_t r10, r11, r12;
                        real_t r20, r21, r22;
                };
        };

} matrix3_t;

typedef matrix3_t* matrix3;

#endif
