#include <cml/errno.h>


FILE *cml_stream = NULL;
cml_stream_handler_t *cml_stream_handler = NULL;


void
cml_stream_printf(const char *label, const char *file, int line,
                  const char *reason)
{
        if (cml_stream == NULL)
        {
                cml_stream = stderr;
        }

        if (cml_stream_handler)
        {
                (*cml_stream_handler)(label, file, line, reason);
                return;
        }

        fprintf (cml_stream, "cml: %s:%d: %s: %s\n", file, line, label, reason);
}


cml_stream_handler_t *
cml_set_stream_handler(cml_stream_handler_t *new_handler)
{
        cml_stream_handler_t *previous_handler = cml_stream_handler;
        cml_stream_handler = new_handler;
        return previous_handler;
}


FILE *
cml_set_stream(FILE *new_stream)
{
        FILE *previous_stream;

        if (cml_stream == NULL) {
                cml_stream = stderr;
        }

        previous_stream = cml_stream;
        cml_stream = new_stream;
        return previous_stream;
}
