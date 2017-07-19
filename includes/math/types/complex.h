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
        void (*setReal)(struct _complex *, double);
        void (*setImaginary)(struct _complex *, double);
        real* (*parts)(struct _complex *);
        char * (*asString)(struct _complex *);

        // Functions
        // Composition laws
        struct _complex * (*add)(struct _complex *, struct _complex *);
        struct _complex * (*prod)(struct _complex *, struct _complex *);
        // ---> Usefull Functions <---
        real (*abs)(struct _complex *);
        struct _complex * (*conj)(struct _complex *);

        // ---> Basic Functions <---
        struct _complex * (*sub)(struct _complex *, struct _complex *);
        struct _complex * (*div)(struct _complex *, struct _complex *);
        // ---> Euler definitions <---
        struct _complex * (*exp)(struct _complex *);

        // ---> Usefull functions
        struct _complex * (*ln)(struct _complex *);
        struct _complex * (*logE)(struct _complex *);
        struct _complex * (*logB)(struct _complex *, real);
        struct _complex * (*log)(struct _complex *);
        struct _complex * (*pow)(struct _complex *, real);
        struct _complex * (*root)(struct _complex *, real);
        struct _complex * (*sqrt)(struct _complex *);
        struct _complex * (*inverse)(struct _complex *);
        void (*rotate)(struct _complex *, real);

        // ---> Basic trigonometric functions <---
        struct _complex * (*sin)(struct _complex *);
        struct _complex * (*cos)(struct _complex *);
        struct _complex * (*tan)(struct _complex *);
        struct _complex * (*sec)(struct _complex *);
        struct _complex * (*csc)(struct _complex *);
        struct _complex * (*cot)(struct _complex *);
        struct _complex * (*atan)(struct _complex *);
        struct _complex * (*atan2)(struct _complex *);
        // ---> Hyperbolic functions
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


// Construct & destruct
Complex * complex(double, ...);
void complex_free(Complex *);

// Initialization
void __complex_init__(Complex *);

// getters
real complex_get_real(Complex *);
real complex_get_imaginary(Complex *);

// setters
void complex_set_real(Complex *, real);
void complex_set_imaginary(Complex *, real);

// Methods
char * complex_as_string(Complex *);

#endif
