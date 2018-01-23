#ifndef CML_H
#error "Never use <structures/include/types/matrix3.h> directly; include <cml.h> instead."
#endif

#ifndef CML_TYPES_MATRIX3_H
#define CML_TYPES_MATRIX3_H

typedef struct _matrix3
{
        union
        {
                real m[9]; /* row-major numbering */
                struct
                {
                        /* reference the matrix [row][column] */
                        real m33[3][3];
                };
                struct
                {
                        /* indexed (column-major numbering) */
                        real i00, i03, i06;
                        real i01, i04, i07;
                        real i02, i05, i08;
                };
                struct
                {
                        /* col-row */
                        real c00, c10, c20;
                        real c01, c11, c21;
                        real c02, c12, c22;
                };
                struct
                {
                        /* row-col */
                        real r00, r01, r02;
                        real r10, r11, r12;
                        real r20, r21, r22;
                };
        };

} matrix3_t;

typedef matrix3_t* matrix3;

#endif
