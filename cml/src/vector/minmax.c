#include <stdlib.h>
#include <scic/errno.h>
#include <scic/vector.h>
#include <cml/math.h>
#include <cml/statistics.h>
#include <cml/sort.h>
#include <cml/vector.h>

void *
cml_vector_min(vector_t *vector, cml_comparison_fn_t cmp)
{
        static double def = CML_NEGINF;

        if (vector_is_empty(vector))
                return (void *) &def;

        def = CML_POSINF;
        void *aux, *min = (void *) &def;

        VECTOR_FOR_EACH(vector, i, {
		aux = iterator_get(&i);
	
                if (cmp(aux, min) <= -1)
                {
                        min = aux;
                }
        });

        return min;
}


void *
cml_vector_max(vector_t *vector, cml_comparison_fn_t cmp)
{
        static double def = CML_NEGINF;

        if (vector_is_empty(vector))
                return (void *) &def;

        def = CML_POSINF;
        void *aux, *max = (void *) &def;

        VECTOR_FOR_EACH(vector, i, {
		aux = iterator_get(&i);
	
                if (cmp(aux, max) >= 1)
                {
                        max = aux;
                }
        });

        return max;
}
