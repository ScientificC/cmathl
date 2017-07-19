#ifndef REAL_H
#define REAL_H


typedef struct _real
{
        // Variables
        double real_value;
        // Methods
        double (*value)(struct _real *);
        void (*setValue)(struct _real *, double);
        char * (*asString)(struct _real *);

        // Composition laws
        struct _real * (*add)(struct _real *, struct _real *);
        struct _real * (*prod)(struct _real *, struct _real *);
        // ---> Usefull Functions <---
        struct _real * (*sgn)(struct _real *);
        struct _real * (*abs)(struct _real *);

        // ---> Basic Functions <---
        struct _real * (*sub)(struct _real *, struct _real *);
        struct _real * (*div)(struct _real *, struct _real *);
        struct _real * (*divE)(struct _real *, struct _real *);
        struct _real * (*mod)(struct _real *, struct _real *);
        struct _real * (*ared)(struct _real *);
        struct _real * (*fact)(struct _real *);
        struct _real * (*ceil)(struct _real *);
        struct _real * (*floor)(struct _real *);
        // ---> Euler definitions <---
        struct _real * (*exp)(struct _real *);

        // ---> Usefull functions
        struct _real * (*ln)(struct _real *);
        struct _real * (*logE)(struct _real *);
        struct _real * (*logB)(struct _real *, struct _real *);
        struct _real * (*log)(struct _real *);
        struct _real * (*pow)(struct _real *, struct _real *);
        struct _real * (*root)(struct _real *, struct _real *);
        struct _real * (*sqrt)(struct _real *);

        // ---> Basic trigonometric functions <---
        struct _real * (*sin)(struct _real *);
        struct _real * (*cos)(struct _real *);
        struct _real * (*tan)(struct _real *);
        struct _real * (*sec)(struct _real *);
        struct _real * (*csc)(struct _real *);
        struct _real * (*cot)(struct _real *);
        struct _real * (*atan)(struct _real *);
        struct _real * (*atan2)(struct _real *);
        // ---> Hyperbolic functions
        struct _real * (*sinh)(struct _real *);
        struct _real * (*cosh)(struct _real *);
        struct _real * (*tanh)(struct _real *);
        struct _real * (*sech)(struct _real *);
        struct _real * (*csch)(struct _real *);
        struct _real * (*coth)(struct _real *);
        struct _real * (*atanh)(struct _real *);

        // Destructor
        void (*free)(struct _real *);

} Real;


// Construct & destruct
Real * real_new(double);
void real_free(Real *);

// Initialization
void __real_init__(Real *);

// getters
double real_value(Real *);

// setters
void real_set_value(Real *, double);

// Methods
char * real_as_string(Real *);
char * real_as_complex(Real *);

#endif
