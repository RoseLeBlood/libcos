#ifndef KLIBC_TGMATH_H
#define KLIBC_TGMATH_H

#include <math.h>
#include "complex.h"

#ifndef __cplusplus

#define __TGMATH1_COMPLEX(z,R,C)          __builtin_tgmath (R##f, R, R##l, C##f, C, C##l, (z))
#define __TGMATH2_COMPLEX(z,z1,R,C)        __builtin_tgmath (R##f, R, R##l, C##f, C, C##l, (z), (z1))

#define __REALFUNC1_TGMATH(x,R)         __builtin_tgmath (R##f, R, R##l, (x))
#define __REALFUNC2_TGMATH(x,y,R)       __builtin_tgmath (R##f, R, R##l, (x), (y))
#define __REALFUNC3_TGMATH(x,y,z,R)     __builtin_tgmath (R##f, R, R##l, (x), (y), (z))
#define __COMPLEX_TGMATH(z,C)           __builtin_tgmath (C##f, C, C##l, (z))

#define acos(z)          __TGMATH1_COMPLEX(z, acos, cacos)
#define asin(z)          __TGMATH1_COMPLEX(z, asin, casin)
#define atan(z)          __TGMATH1_COMPLEX(z, atan, catan)
#define acosh(z)         __TGMATH1_COMPLEX(z, acosh, cacosh)
#define asinh(z)         __TGMATH1_COMPLEX(z, asinh, casinh)
#define atanh(z)         __TGMATH1_COMPLEX(z, atanh, catanh)
#define cos(z)           __TGMATH1_COMPLEX(z, cos, ccos)
#define sin(z)           __TGMATH1_COMPLEX(z, sin, csin)
#define tan(z)           __TGMATH1_COMPLEX(z, tan, ctan)
#define cosh(z)          __TGMATH1_COMPLEX(z, cosh, ccosh)
#define sinh(z)          __TGMATH1_COMPLEX(z, sinh, csinh)
#define tanh(z)          __TGMATH1_COMPLEX(z, tanh, ctanh)
#define exp(z)           __TGMATH1_COMPLEX(z, exp, cexp)
#define log(z)           __TGMATH1_COMPLEX(z, log, clog)
#define pow(z1,z2)       __TGMATH2_COMPLEX(z1, z2, pow, cpow)
#define sqrt(z)          __TGMATH1_COMPLEX(z, sqrt, csqrt)
#define fabs(z)          __TGMATH1_COMPLEX(z, fabs, cabs)

#define atan2(x,y)       __REALFUNC2_TGMATH(x, y, atan2)
#define cbrt(x)          __REALFUNC1_TGMATH(x, cbrt)
#define ceil(x)          __REALFUNC1_TGMATH(x, ceil)
#define copysign(x,y)    __REALFUNC2_TGMATH(x, y, copysign)
#define erf(x)           __REALFUNC1_TGMATH(x, erf)
#define erfc(x)          __REALFUNC1_TGMATH(x, erfc)
#define exp2(x)          __REALFUNC1_TGMATH(x, exp2)
#define expm1(x)         __REALFUNC1_TGMATH(x, expm1)
#define fdim(x,y)        __REALFUNC2_TGMATH(x, y, fdim)
#define floor(x)         __REALFUNC1_TGMATH(x, floor)
#define fma(x,y,z)       __REALFUNC1_TGMATH(x, y, z, fma)
#define fmax(x,y)        __REALFUNC2_TGMATH(x, y, fmax)
#define fmin(x,y)        __REALFUNC2_TGMATH(x, y, fmin)
#define fmod(x,y)        __REALFUNC2_TGMATH(x, y, fmod)
#define frexp(x,y)       __REALFUNC2_TGMATH(x, y, frexp)
#define hypot(x,y)       __REALFUNC2_TGMATH(x, y, hypot)
#define ilogb(x)         __REALFUNC1_TGMATH(x, ilogb)
#define ldexp(x,y)       __REALFUNC2_TGMATH(x, y, ldexp)
#define lgamma(x)        __REALFUNC1_TGMATH(x, lgamma)
#define llrint(x)        __REALFUNC1_TGMATH(x, llrint)
#define llround(x)       __REALFUNC1_TGMATH(x, llround)
#define log10(x)         __REALFUNC1_TGMATH(x, log10)
#define log1p(x)         __REALFUNC1_TGMATH(x, log1p)
#define log2(x)          __REALFUNC1_TGMATH(x, log2)
#define logb(x)          __REALFUNC1_TGMATH(x, logb)
#define lrint(x)         __REALFUNC1_TGMATH(x, lrint)
#define lround(x)        __REALFUNC1_TGMATH(x, lround)
#define nearbyint(x)     __REALFUNC1_TGMATH(x, nearbyint)
#define nextafter(x,y)   __REALFUNC2_TGMATH(x, y, nextafter)
#define nexttoward(x,y)  __REALFUNC2_TGMATH(x, y, nexttoward)
#define remainder(x,y)   __REALFUNC2_TGMATH(x, y, remainder)
#define remquo(x,y,z)    __REALFUNC3_TGMATH(x, y, z, remquo)
#define rint(x)          __REALFUNC1_TGMATH(x, rint)
#define round(x)         __REALFUNC1_TGMATH(x, round)
#define scalbn(x,y)      __REALFUNC2_TGMATH(x, y, scalbn)
#define scalbln(x,y)     __REALFUNC2_TGMATH(x, y, scalbln)
#define tgamma(x)        __REALFUNC1_TGMATH(x, tgamma)
#define trunc(x)         __REALFUNC1_TGMATH(x, trunc)

#define carg(z)          __COMPLEX_TGMATH(z, carg)
#define conj(z)          __COMPLEX_TGMATH(z, conj)
#define cproj(z)         __COMPLEX_TGMATH(z, cproj)

#endif

#endif