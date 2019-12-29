#include <stdlib.h>
#include <cml/sort.h>

#define BASE_LONG_DOUBLE
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_LONG_DOUBLE

#define BASE_DOUBLE
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_DOUBLE

#define BASE_FLOAT
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_FLOAT

#define BASE_ULONG
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_ULONG

#define BASE_LONG
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_LONG

#define BASE_UINT
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_UINT

#define BASE_INT
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_INT

#define BASE_USHORT
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_USHORT

#define BASE_SHORT
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_SHORT

#define BASE_UCHAR
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_UCHAR

#define BASE_CHAR
#include <cml/_private/templates_on.h>
#include "source/cmp.c"
#include <cml/_private/templates_off.h>
#undef  BASE_CHAR
