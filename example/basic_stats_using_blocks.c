#include <stdio.h>
#include <cml/block.h>
#include <cml/statistics.h>

int
main(void)
{
        cml_block_t *b = cml_block_alloc(5);

        printf("length of block = %zu\n", b->size);
        printf("block data address = %p\n", b->data);

        cml_block_fscanf(stdin, b);
        cml_block_fprintf(stdout, b, "%g");

        double mean, variance, largest, smallest;

        mean = cml_stats_mean(b->data, 1, 5);
        variance = cml_stats_variance(b->data, 1, 5);

        printf("The dataset is %g, %g, %g, %g, %g\n",
               b->data[0], b->data[1], b->data[2], b->data[3], b->data[4]);

        printf("The sample mean is %g\n", mean);
        printf("The estimated variance is %g\n", variance);

        cml_block_free(b);

        return 0;
}
