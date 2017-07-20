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

        bool (*equals)(struct _real *, struct _real *);
        bool (*isNull)(struct _real *);
        bool (*isGreater)(struct _real *, struct _real *);
        bool (*isLess)(struct _real *, struct _real *);
        bool (*isGreaterOrEquals)(struct _real *, struct _real *);
        bool (*isLessOrEquals)(struct _real *, struct _real *);
        bool (*isNatural)(struct _real *);
        bool (*isInteger)(struct _real *);
        bool (*isMult)(struct _real *, struct _real *);

        struct _real * (*add)(struct _real *, struct _real *);
        struct _real * (*prod)(struct _real *, struct _real *);
        struct _real * (*sgn)(struct _real *);
        struct _real * (*abs)(struct _real *);
        struct _real * (*sub)(struct _real *, struct _real *);
        struct _real * (*div)(struct _real *, struct _real *);
        struct _real * (*divE)(struct _real *, struct _real *);
        struct _real * (*mod)(struct _real *, struct _real *);
        struct _real * (*inverse)(struct _real *);
        struct _real * (*opposite)(struct _real *);
        struct _real * (*ared)(struct _real *);
        struct _real * (*fact)(struct _real *);
        struct _real * (*ceil)(struct _real *);
        struct _real * (*floor)(struct _real *);

        struct _real * (*exp)(struct _real *);
        struct _real * (*ln)(struct _real *);
        struct _real * (*logE)(struct _real *);
        struct _real * (*logB)(struct _real *, struct _real *);
        struct _real * (*pow)(struct _real *, struct _real *);
        struct _real * (*root)(struct _real *, struct _real *);
        struct _real * (*sqrt)(struct _real *);

        struct _real * (*sin)(struct _real *);
        struct _real * (*cos)(struct _real *);
        struct _real * (*tan)(struct _real *);
        struct _real * (*sec)(struct _real *);
        struct _real * (*csc)(struct _real *);
        struct _real * (*cot)(struct _real *);
        struct _real * (*atan)(struct _real *);
        struct _real * (*atan2)(struct _real *);

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

typedef Real* real;

// Construct & destruct
real real_new(double);
void real_free(real);

// Initialization
void __real_init__(real);

// getters
double real_value(real);

// setters
void real_set_value(real, double);

// Methods
char * real_as_string(real);
char * real_as_complex(real);

#endif
