#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

typedef struct _complex
{
        union
        {
                mfloat_t p[2];
                struct
                {
                        mfloat_t re;
                        mfloat_t im;
                };
        };
} complex_t;

typedef complex_t* complex;

complex complex_new(mfloat_t, mfloat_t);
void complex_free(complex);
complex complex_clone(complex);
char * complex_as_string(complex);

#endif
