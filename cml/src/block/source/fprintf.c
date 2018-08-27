#ifndef USES_LONGDOUBLE

int
FUNCTION(cml_block, fprintf)(FILE *stream, const TYPE(cml_block) *b, const char *format)
{
        size_t n = b->size;

        ATOMIC *data = b->data;

        size_t i;

        for (i = 0; i < n; i++)
        {
                int k;
                int status;

                for (k = 0; k < MULTIPLICITY; k++)
                {
                        if (k > 0)
                        {
                                status = putc(' ', stream);

                                if (status == EOF)
                                {
                                        SCIC_ERROR("putc failed", SCIC_EFAILED);
                                }
                        }
                        status = fprintf(stream,
                                         format,
                                         data[MULTIPLICITY *i + k]);
                        if (status < 0)
                        {
                                SCIC_ERROR("fprintf failed", SCIC_EFAILED);
                        }
                }

                status = putc('\n', stream);

                if (status == EOF)
                {
                        SCIC_ERROR("putc failed", SCIC_EFAILED);
                }
        }

        return 0;
}


int
FUNCTION(cml_block, raw_fprintf)(FILE *stream,
                                 const ATOMIC *data,
                                 const size_t n,
                                 const size_t stride,
                                 const char *format)
{
        size_t i;

        for (i = 0; i < n; i++)
        {
                int k;
                int status;

                for (k = 0; k < MULTIPLICITY; k++)
                {
                        if (k > 0)
                        {
                                status = putc(' ', stream);

                                if (status == EOF)
                                {
                                        SCIC_ERROR("putc failed", SCIC_EFAILED);
                                }
                        }
                        status = fprintf(stream,
                                         format,
                                         data[MULTIPLICITY * i * stride + k]);
                        if (status < 0)
                        {
                                SCIC_ERROR("fprintf failed", SCIC_EFAILED);
                        }
                }

                status = putc('\n', stream);

                if (status == EOF)
                {
                        SCIC_ERROR("putc failed", SCIC_EFAILED);
                }
        }

        return 0;
}


#endif
