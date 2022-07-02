/*
* MIT License
*
* Copyright (c) 2022 Amber-Sophia Schröck

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#ifndef KLIBCOS_FLOAT_H
#define	KLIBCOS_FLOAT_H

#include "stddef.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define FLT_ROUNDS 1

#define FLT_RADIX	    __FLT_RADIX__

#define FLT_MANT_DIG	__FLT_MANT_DIG__
#define DBL_MANT_DIG	__DBL_MANT_DIG__
#define LDBL_MANT_DIG	__LDBL_MANT_DIG__

#define FLT_DIG		    __FLT_DIG__
#define DBL_DIG		    __DBL_DIG__
#define LDBL_DIG	    __LDBL_DIG__
#define FLT_MIN_EXP	    __FLT_MIN_EXP__
#define DBL_MIN_EXP	    __DBL_MIN_EXP__
#define LDBL_MIN_EXP	__LDBL_MIN_EXP__
#define FLT_MIN_10_EXP	__FLT_MIN_10_EXP__
#define DBL_MIN_10_EXP	__DBL_MIN_10_EXP__
#define LDBL_MIN_10_EXP	__LDBL_MIN_10_EXP__
#define FLT_MAX_EXP	    __FLT_MAX_EXP__
#define DBL_MAX_EXP	    __DBL_MAX_EXP__
#define LDBL_MAX_EXP	__LDBL_MAX_EXP__
#define FLT_MAX_10_EXP	__FLT_MAX_10_EXP__
#define DBL_MAX_10_EXP	__DBL_MAX_10_EXP__
#define LDBL_MAX_10_EXP	__LDBL_MAX_10_EXP__
#define FLT_MAX		    __FLT_MAX__
#define DBL_MAX		    __DBL_MAX__
#define LDBL_MAX	    __LDBL_MAX__
#define FLT_EPSILON	    __FLT_EPSILON__
#define DBL_EPSILON	    __DBL_EPSILON__
#define LDBL_EPSILON	__LDBL_EPSILON__
#define FLT_MIN		    __FLT_MIN__
#define DBL_MIN		    __DBL_MIN__
#define LDBL_MIN	    __LDBL_MIN__
#define DECIMAL_DIG	    __DECIMAL_DIG__
#define FLT_DECIMAL_DIG	__FLT_DECIMAL_DIG__
#define DBL_DECIMAL_DIG	__DBL_DECIMAL_DIG__
#define LDBL_DECIMAL_DIG __LDBL_DECIMAL_DIG__

#define FLT_HAS_SUBNORM		__FLT_HAS_DENORM__
#define DBL_HAS_SUBNORM		__DBL_HAS_DENORM__
#define LDBL_HAS_SUBNORM	__LDBL_HAS_DENORM__

#define FLT_TRUE_MIN	__FLT_DENORM_MIN__
#define DBL_TRUE_MIN	__DBL_DENORM_MIN__
#define LDBL_TRUE_MIN	__LDBL_DENORM_MIN__

#define FLT_NORM_MAX	__FLT_NORM_MAX__
#define DBL_NORM_MAX	__DBL_NORM_MAX__
#define LDBL_NORM_MAX	__LDBL_NORM_MAX__
#define FLT_IS_IEC_60559	__FLT_IS_IEC_60559__
#define DBL_IS_IEC_60559	__DBL_IS_IEC_60559__
#define LDBL_IS_IEC_60559	__LDBL_IS_IEC_60559__

#define FLT_EVAL_METHOD	__FLT_EVAL_METHOD__

#define FLT_SNAN	(__builtin_nansf (""))
#define DBL_SNAN	(__builtin_nans (""))
#define LDBL_SNAN	(__builtin_nansl (""))


#ifdef	__cplusplus
}
#endif

#endif