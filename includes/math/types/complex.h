#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct _complex
{
        // Variables
        real real_part;
        real imaginary_part;
        // Methods
        real (*real)(struct _complex *);
        real (*imaginary)(struct _complex *);
        void (*setReal)(struct _complex *, real);
        void (*setImaginary)(struct _complex *, real);
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
        struct _complex * (*exp)(struct _complex *);

        struct _complex * (*ln)(struct _complex *);
        struct _complex * (*logE)(struct _complex *);
        struct _complex * (*logB)(struct _complex *, real);
        struct _complex * (*log)(struct _complex *);
        struct _complex * (*pow)(struct _complex *, real);
        struct _complex * (*root)(struct _complex *, real);
        struct _complex * (*sqrt)(struct _complex *);

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

} Complex;

typedef Complex* complex;

// Construct & destruct
complex complex_new(real, real);
void complex_free(complex);

// Initialization
void init_complex(complex);

// getters
real complex_get_real(complex);
real complex_get_imaginary(complex);

// setters
void complex_set_real(complex, real);
void complex_set_imaginary(complex, real);

// Methods
char * complex_as_string(complex);

#endif
