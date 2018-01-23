#ifndef CML_H
#error "Never use <structures/include/types/matrix4.h> directly; include <cml.h> instead."
#endif

#ifndef CML_TYPES_MATRIX4_H
#define CML_TYPES_MATRIX4_H

typedef struct _matrix4
{
        union
        {
                real m[16]; /* row-major numbering */
                struct
                {
                        /* reference the matrix [row][column] */
                        real m44[4][4];
                };
                struct
                {
                        /* indexed (column-major numbering) */
                        real i00, i04, i08, i12;
                        real i01, i05, i09, i13;
                        real i02, i06, i10, i14;
                        real i03, i07, i11, i15;
                };
                struct
                {
                        /* col-row */
                        real c00, c10, c20, c30;
                        real c01, c11, c21, c31;
                        real c02, c12, c22, c32;
                        real c03, c13, c23, c33;
                };
                struct
                {
                        /* row-col */
                        real r00, r01, r02, r03;
                        real r10, r11, r12, r13;
                        real r20, r21, r22, r23;
                        real r30, r31, r32, r33;
                };
        };
} matrix4_t;

typedef matrix4_t* matrix4;

#endif
