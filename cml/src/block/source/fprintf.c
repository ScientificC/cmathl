#if defined USES_LONGDOUBLE && !USES_LONGDOUBLE

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
                                        CML_ERROR("putc failed", CML_EFAILED);
                                }
                        }
                        status = fprintf(stream,
                                         format,
                                         data[MULTIPLICITY *i + k]);
                        if (status < 0)
                        {
                                CML_ERROR("fprintf failed", CML_EFAILED);
                        }
                }

                status = putc('\n', stream);

                if (status == EOF)
                {
                        CML_ERROR("putc failed", CML_EFAILED);
                }
        }

        return 0;
}

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
                                CML_ERROR("fscanf failed", CML_EFAILED);
                        }
                }
        }

        return CML_SUCCESS;
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
                                        CML_ERROR("putc failed", CML_EFAILED);
                                }
                        }
                        status = fprintf(stream,
                                         format,
                                         data[MULTIPLICITY * i * stride + k]);
                        if (status < 0)
                        {
                                CML_ERROR("fprintf failed", CML_EFAILED);
                        }
                }

                status = putc('\n', stream);

                if (status == EOF)
                {
                        CML_ERROR("putc failed", CML_EFAILED);
                }
        }

        return 0;
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
                                CML_ERROR("fscanf failed", CML_EFAILED);
                        }
                }
        }

        return CML_SUCCESS;
}

#endif
