#ifndef CML_H
#error "Never use <cml/structures/matrix3.h> directly; include <cml.h> instead."
#endif

#ifndef CML_MATH_TYPES_MATRIX3_H
#define CML_MATH_TYPES_MATRIX3_H

typedef struct
{
        union
        {
                double m[9]; /* row-major numbering */
                struct
                {
                        /* reference the matrix [row][column] */
                        double m33[3][3];
                };
                struct
                {
                        /* indexed (column-major numbering) */
                        double i00, i03, i06;
                        double i01, i04, i07;
                        double i02, i05, i08;
                };
                struct
                {
                        /* col-row */
                        double c00, c10, c20;
                        double c01, c11, c21;
                        double c02, c12, c22;
                };
                struct
                {
                        /* row-col */
                        double r00, r01, r02;
                        double r10, r11, r12;
                        double r20, r21, r22;
                };
        };

} cml_matrix3_t;

#endif
