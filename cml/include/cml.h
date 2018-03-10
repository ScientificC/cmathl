#ifndef _CML_H_
#define _CML_H_

#define _CML_COMMON_H_
#include <cml/_common/default.h>
#include <cml/_common/inline.h>
#include <cml/_common/machine.h>
#undef _CML_COMMON_H_

#include <cml/config.h>
#include <cml/errno.h>
#include <cml/ieee.h>
#include <cml/minmax.h>

#if defined CML_NO_ALIASES || defined __CML_NO_GENERIC
        #include <cml/math.h>
#else
        #include <cml/tgmath.h>
#endif

#include <cml/block.h>
#include <cml/const.h>
#include <cml/complex.h>
#include <cml/deriv.h>
#include <cml/diff.h>
#include <cml/easings.h>
#include <cml/quaternion.h>
#include <cml/specfunc.h>

#endif
