#ifndef CML_H
#error "Never use <structures/include/types/matrix4.h> directly; include <cml.h> instead."
#endif

#ifndef CML_TYPES_MATRIX4_H
#define CML_TYPES_MATRIX4_H

typedef struct _matrix4
{
        union
        {
                real_t m[16]; /* row-major numbering */
                struct
                {
                        /* reference the matrix [row][column] */
                        real_t m44[4][4];
                };
                struct
                {
                        /* indexed (column-major numbering) */
                        real_t i00, i04, i08, i12;
                        real_t i01, i05, i09, i13;
                        real_t i02, i06, i10, i14;
                        real_t i03, i07, i11, i15;
                };
                struct
                {
                        /* col-row */
                        real_t c00, c10, c20, c30;
                        real_t c01, c11, c21, c31;
                        real_t c02, c12, c22, c32;
                        real_t c03, c13, c23, c33;
                };
                struct
                {
                        /* row-col */
                        real_t r00, r01, r02, r03;
                        real_t r10, r11, r12, r13;
                        real_t r20, r21, r22, r23;
                        real_t r30, r31, r32, r33;
                };
        };
} matrix4_t;

typedef matrix4_t* matrix4;

#endif
