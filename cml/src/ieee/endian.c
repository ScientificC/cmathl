#include <stdlib.h>
#include <cml/ieee.h>

__CML_EXTERN_INLINE int
little_endian_p()
{
        /* Are we little or big endian?  From Harbison & Steele.  */
        union
        {
                long l;
                char c[sizeof (long)];
        } u;

        u.l = 1;

        return (u.c[sizeof (long) - 1] == 1);
}
