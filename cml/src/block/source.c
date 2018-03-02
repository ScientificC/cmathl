#include <stdlib.h>
#include <string.h>
#include <cml/block.h>
#include <cml/errno.h>


#define BASE_CML_COMPLEX_LONG
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_CML_COMPLEX_LONG

#define BASE_CML_COMPLEX
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_CML_COMPLEX

#define BASE_CML_COMPLEX_FLOAT
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_CML_COMPLEX_FLOAT

#define BASE_LONG_DOUBLE
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_LONG_DOUBLE

#define BASE_DOUBLE
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_FLOAT

#define BASE_ULONG
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_ULONG

#define BASE_LONG
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_LONG

#define BASE_UINT
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_UINT

#define BASE_INT
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_INT

#define BASE_USHORT
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_USHORT

#define BASE_SHORT
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_SHORT

#define BASE_UCHAR
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_UCHAR

#define BASE_CHAR
#include <cml/_private/templates_on.h>
#include "source/block.c"
#include "source/fprintf.c"
#include "source/fwrite.c"
#include "source/init.c"
#include <cml/_private/templates_off.h>
#undef  BASE_CHAR
