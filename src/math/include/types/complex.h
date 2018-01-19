#ifndef CML_COMPLEX_H
#define CML_COMPLEX_H

typedef struct _complex
{
        // Variables
        mfloat_t real_part;
        mfloat_t imaginary_part;
        // Methods
        real (*getReal)(struct _complex *);
        real (*getImaginary)(struct _complex *);
        void (*setReal)(struct _complex *, mfloat_t);
        void (*setImaginary)(struct _complex *, mfloat_t);
        real* (*parts)(struct _complex *);
        char * (*asString)(struct _complex *);

        // Functions
        struct _complex * (*add)(struct _complex *, struct _complex *);
        struct _complex * (*prod)(struct _complex *, struct _complex *);

        real (*abs)(struct _complex *);
        real (*arg)(struct _complex *);

        struct _complex * (*conjugate)(struct _complex *);
        struct _complex * (*inverse)(struct _complex *);

        struct _complex * (*sub)(struct _complex *, struct _complex *);
        struct _complex * (*div)(struct _complex *, struct _complex *);
        struct _complex * (*scalar)(struct _complex *, real);
        struct _complex * (*exp)(struct _complex *);

        struct _complex * (*log)(struct _complex *);
        struct _complex * (*logB)(struct _complex *, struct _complex *);
        struct _complex * (*pow)(struct _complex *, struct _complex *);
        struct _complex * (*root)(struct _complex *, real);

        struct _complex * (*sin)(struct _complex *);
        struct _complex * (*cos)(struct _complex *);
        struct _complex * (*tan)(struct _complex *);
        struct _complex * (*sec)(struct _complex *);
        struct _complex * (*csc)(struct _complex *);
        struct _complex * (*cot)(struct _complex *);
        struct _complex * (*atan)(struct _complex *);
        struct _complex * (*atan2)(struct _complex *);

        struct _complex * (*sinh)(struct _complex *);
        struct _complex * (*cosh)(struct _complex *);
        struct _complex * (*tanh)(struct _complex *);
        struct _complex * (*sech)(struct _complex *);
        struct _complex * (*csch)(struct _complex *);
        struct _complex * (*coth)(struct _complex *);
        struct _complex * (*atanh)(struct _complex *);

        // Destructor
        void (*free)(struct _complex *);

} complex_t;

typedef complex_t* complex;

complex_t _complex_create(mfloat_t, mfloat_t);

// Construct & destruct
complex _complex_new(mfloat_t, mfloat_t);
complex _complex_new_from_reals(real, real);
void _complex_free(complex);

complex _complex_clone(complex);

// Initialization
void init_complex(complex);

// getters
real complex_get_real(complex);
real complex_get_imaginary(complex);
real * complex_get_parts(complex self);

// setters
void complex_set_real(complex, mfloat_t);
void complex_set_imaginary(complex, mfloat_t);

// Methods
char * complex_as_string(complex);

#endif
