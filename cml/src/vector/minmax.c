#include <stdlib.h>
#include <string.h>
#include <scic/errno.h>
#include <scic/vector.h>
#include <cml/math.h>
#include <cml/sort.h>
#include <cml/vector.h>

void *
cml_vector_min(vector_t *vector, cml_comparison_fn_t cmp)
{
        if (vector_is_empty(vector))
        {
                SCIC_ERROR_NULL(                            
                        "failed access to empty array",
                        SCIC_EINVAL
                );
        }

        void *aux, *min = vector_get(vector, 0);

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
        if (vector_is_empty(vector))
        {
                SCIC_ERROR_NULL(                            
                        "failed access to empty array",
                        SCIC_EINVAL
                );
        }

        void *aux, *max = vector_get(vector, 0);

        VECTOR_FOR_EACH(vector, i, {
		aux = iterator_get(&i);
	
                if (cmp(aux, max) >= 1)
                {
                        max = aux;
                }
        });

        return max;
}


vector_t
cml_vector_minmax(vector_t *vector, cml_comparison_fn_t cmp)
{
        double min_def = CML_NEGINF, max_def = CML_POSINF;
        
        vector_t minmax;    
        
        vector_setup(&minmax, 2, vector->element_size);

        if (vector_is_empty(vector))
        {
                vector_push_back(&minmax, (void *) &min_def);
                vector_push_back(&minmax, (void *) &max_def);

                return minmax;
        }

        min_def = CML_POSINF;
        max_def = CML_NEGINF;

        void *aux, *max = (void *) &max_def, *min = (void *) &min_def;

        VECTOR_FOR_EACH(vector, i, {
		aux = iterator_get(&i);
	
                if (cmp(aux, max) >= 1)
                {
                        max = aux;
                }

                if (cmp(aux, min) <= -1)
                {
                        min = aux;
                }
        });

        vector_push_back(&minmax, min);
        vector_push_back(&minmax, max);

        return minmax;
}

