TYPE(cml_block) *
FUNCTION(cml_block, alloc)(const size_t n)
{
        TYPE(cml_block) *b;

        b =(TYPE(cml_block) *)malloc(sizeof(TYPE(cml_block)));

        if (b == 0)
        {
                CML_ERROR_VAL("failed to allocate space for block struct",
                              CML_ENOMEM, 0);
        }

        b->data = (ATOMIC *) malloc(MULTIPLICITY * n * sizeof(ATOMIC));

        if (b->data == 0 && n > 0) /* malloc may return NULL when n == 0 */
        {
                free(b); /* exception in constructor, avoid memory leak */

                CML_ERROR_VAL("failed to allocate space for block data",
                              CML_ENOMEM, 0);
        }

        b->size = n;

        return b;
}

TYPE(cml_block) *
FUNCTION(cml_block, calloc)(const size_t n)
{
        size_t i;

        TYPE(cml_block) *b = FUNCTION(cml_block, alloc)(n);

        if (b == 0)
        {
                return 0;
        }

        /* initialize block to zero; the memset call takes care of padding bytes */
        memset(b->data, 0, MULTIPLICITY * n * sizeof(ATOMIC));

        for(i = 0; i < MULTIPLICITY * n; i++)
        {
                b->data[i] = 0;
        }

        return b;
}

void
FUNCTION(cml_block, free)(TYPE(cml_block) * b)
{
        RETURN_IF_NULL(b);
        free(b->data);
        free(b);
}
