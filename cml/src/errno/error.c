#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <cml/errno.h>

cml_error_handler_t * cml_error_handler = NULL;

static void no_error_handler(const char *reason, const char *file, int line, int cml_errno);

void
cml_error(const char *reason, const char *file, int line, int cml_errno)
{
        if (cml_error_handler)
        {
                (*cml_error_handler)(reason, file, line, cml_errno);
                return;
        }

        cml_stream_printf ("ERROR", file, line, reason);

        fflush(stdout);
        fprintf(stderr, "Default CML error handler invoked.\n");
        fflush(stderr);

        abort();
}

cml_error_handler_t *
cml_set_error_handler(cml_error_handler_t *new_handler)
{
        cml_error_handler_t *previous_handler = cml_error_handler;
        cml_error_handler = new_handler;

        return previous_handler;
}


cml_error_handler_t *
cml_set_error_handler_off()
{
        cml_error_handler_t *previous_handler = cml_error_handler;
        cml_error_handler = no_error_handler;

        return previous_handler;
}

static void
no_error_handler(const char *reason, const char *file, int line, int cml_errno)
{
        /* do nothing */
        reason = 0;
        file = 0;
        line = 0;
        cml_errno = 0;

        (void) reason;
        (void) file;
        (void) line;
        (void) cml_errno;

        return;
}
