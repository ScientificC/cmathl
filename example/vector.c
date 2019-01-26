#include <stdio.h>
#include <cml/vector.h>
#include <scic/vector.h>

int
main(int argc, const char *argv[])
{
        vector_t vector;
        int x, y;

        /* Choose initial capacity */
        /* Specify the size of the elements you want to store once */
        vector_setup(&vector, 10, sizeof(int));

        x = 6, y = 9;
        vector_push_back(&vector, &x);
        vector_insert(&vector, 1, &y);

        printf("Min element: %d\n", cml_vector_min_as(int, &vector, &cml_sort_int_cmp));
        printf("Max element: %d\n", cml_vector_max_as(int, &vector, &cml_sort_int_cmp));

        /* or */

        printf("Min element: %d\n", cml_vector_min_as_int(&vector, &cml_sort_int_cmp));
        printf("Max element: %d\n", cml_vector_max_as_int(&vector, &cml_sort_int_cmp));
        
        vector_clear(&vector);
        vector_destroy(&vector);
}
