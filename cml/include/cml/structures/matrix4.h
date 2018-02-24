#ifndef CML_H
#error "Never use <cml/structures/matrix4.h> directly; include <cml.h> instead."
#endif

#ifndef CML_STRUCTURES_TYPES_MATRIX4_H
#define CML_STRUCTURES_TYPES_MATRIX4_H

typedef struct _matrix4
{
        union
        {
                double m[16]; /* row-major numbering */
                struct
                {
                        /* reference the matrix [row][column] */
                        double m44[4][4];
                };
                struct
                {
                        /* indexed (column-major numbering) */
                        double i00, i04, i08, i12;
                        double i01, i05, i09, i13;
                        double i02, i06, i10, i14;
                        double i03, i07, i11, i15;
                };
                struct
                {
                        /* col-row */
                        double c00, c10, c20, c30;
                        double c01, c11, c21, c31;
                        double c02, c12, c22, c32;
                        double c03, c13, c23, c33;
                };
                struct
                {
                        /* row-col */
                        double r00, r01, r02, r03;
                        double r10, r11, r12, r13;
                        double r20, r21, r22, r23;
                        double r30, r31, r32, r33;
                };
        };
} cml_matrix4_t;

#endif
