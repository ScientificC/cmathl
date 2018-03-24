#include <stdio.h>
#include <cml/block.h>

int
main(void)
{
        cml_block_t *b = cml_block_alloc(100);

        printf("length of block = %zu\n", b->size);
        printf("block data address = %p\n", b->data);

        cml_block_free(b);

        return 0;
}
