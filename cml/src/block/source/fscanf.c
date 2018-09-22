#ifndef USES_LONGDOUBLE

int
FUNCTION(cml_block, fscanf)(FILE *stream, TYPE(cml_block) *b)
{
        size_t n = b->size;

        ATOMIC *data = b->data;

        size_t i;

        for (i = 0; i < n; i++)
        {
                int k;
                for (k = 0; k < MULTIPLICITY; k++)
                {
                        ATOMIC_IO tmp;

                        int status = fscanf(stream, IN_FORMAT, &tmp);

                        data[MULTIPLICITY * i + k] = tmp;


                        if (status != 1)
                        {
                                SCIC_ERROR("fscanf failed", SCIC_EFAILED);
                        }
                }
        }

        return SCIC_SUCCESS;
}


int
FUNCTION(cml_block, raw_fscanf)(FILE *stream,
                                ATOMIC *data,
                                const size_t n,
                                const size_t stride)
{
        size_t i;

        for (i = 0; i < n; i++)
        {
                int k;
                for (k = 0; k < MULTIPLICITY; k++)
                {
                        ATOMIC_IO tmp;

                        int status = fscanf(stream, IN_FORMAT, &tmp);

                        data[MULTIPLICITY * i * stride + k] = tmp;

                        if (status != 1)
                        {
                                SCIC_ERROR("fscanf failed", SCIC_EFAILED);
                        }
                }
        }

        return SCIC_SUCCESS;
}

#endif
