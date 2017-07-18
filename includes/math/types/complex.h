#ifndef COMPLEX_H
#define COMPLEX_H

typedef struct _complex
{
        // Variables
        Real * real_part;
        Real * imaginary_part;
        // Methods
        Real * (*real)(struct _complex *);
        Real * (*imaginary)(struct _complex *);
        void (*setReal)(struct _complex *, double);
        void (*setImaginary)(struct _complex *, double);
        Real ** (*parts)(struct _complex *);
        char * (*asString)(struct _complex *);

        // Functions
        // Composition laws
        struct _complex * (*add)(struct _complex *, struct _complex *);
        struct _complex * (*prod)(struct _complex *, struct _complex *);
        // ---> Usefull Functions <---
        Real * (*abs)(struct _complex *);
        struct _complex * (*conj)(struct _complex *);

        // ---> Basic Functions <---
        struct _complex * (*sub)(struct _complex *, struct _complex *);
        struct _complex * (*div)(struct _complex *, struct _complex *);
        // ---> Euler definitions <---
        struct _complex * (*exp)(struct _complex *);

        // ---> Usefull functions
        struct _complex * (*ln)(struct _complex *);
        struct _complex * (*logE)(struct _complex *);
        struct _complex * (*logB)(struct _complex *, Real *);
        struct _complex * (*log)(struct _complex *);
        struct _complex * (*pow)(struct _complex *, Real *);
        struct _complex * (*root)(struct _complex *, Real *);
        struct _complex * (*sqrt)(struct _complex *);
        struct _complex * (*inverse)(struct _complex *);
        void (*rotate)(struct _complex *, Real *);

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

// getters
Real * complex_get_real(Complex *);
Real * complex_get_imaginary(Complex *);

// setters
void complex_set_real(Complex *, Real *);
void complex_set_imaginary(Complex *, Real *);

// Methods
char * complex_as_string(Complex *);

#endif
