#include <stdio.h>
#include <cml/vector.h>
#include <scic/vector.h>

int
main(int argc, const char *argv[])
{
        vector_t vector;
        vector_t minmax;

        double x, y;

        /* Choose initial capacity */
        /* Specify the size of the elements you want to store once */
        vector_setup(&vector, 10, sizeof(double));

        x = 6.0, y = 9.0;
        vector_push_back(&vector, &x);
        vector_insert(&vector, 1, &y);

        printf("Min element: %g\n", cml_vector_min_as(double, &vector, &cml_sort_cmp));
        printf("Max element: %g\n", cml_vector_max_as(double, &vector, &cml_sort_cmp));

        /* or */

        printf("Min element: %g\n", cml_vector_min_as_double(&vector));
        printf("Max element: %g\n", cml_vector_max_as_double(&vector));

        minmax = cml_vector_minmax(&vector, &cml_sort_cmp);

        printf("Min element: %g\n", VECTOR_GET_AS(double, &minmax, 0));
        printf("Max element: %g\n", VECTOR_GET_AS(double, &minmax, 1));

        vector_clear(&vector);
        vector_destroy(&vector);
}
