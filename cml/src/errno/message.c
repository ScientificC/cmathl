#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <cml.h>

unsigned int cml_message_mask = CML_MESSAGE_MASK;

void
cml_message(const char *reason, const char *file, int line,
            unsigned int mask)
{
        if (mask & cml_message_mask)
        {
                cml_stream_printf ("MESSAGE", file, line, reason);
        }
}
