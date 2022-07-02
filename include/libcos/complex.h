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
#ifndef KLIBC_COMPLX_H
#define KLIBC_COMPLX_H

#include "stdalign.h"
#include "math.h"

#define complex _Complex

#define creal(z) (__real__ z)
#define cimag(z) (__imag__ z) 
#define conj(x)  (~(x))

#ifdef	__cplusplus
extern "C" {
#endif

double complex cacos( double complex );
double complex casin( double complex );
double complex catan( double complex );
double complex ccos( double complex );
double complex csin( double complex );
double complex ctan( double complex );
double complex cacosh( double complex );
double complex casinh( double complex );
double complex catanh( double complex );
double complex ccosh( double complex );
double complex csinh( double complex );
double complex ctanh( double complex );
double complex cexp( double complex );
double complex cpow( double complex, double complex );
double complex clog( double complex );
double complex clogn( double complex, double complex );
double complex clog10( double complex) ;
double complex csqr(double complex x );
double complex csqrt( double complex );
double carg( double complex );
double complex cproj( double complex );
double cabs( double complex );

float complex cacosf( float complex );
float complex casinf( float complex );
float complex catanf( float complex );
float complex ccosf( float complex );
float complex csinf( float complex );
float complex ctanf( float complex );
float complex cacoshf( float complex );
float complex casinhf( float complex );
float complex catanhf( float complex );
float complex ccoshf( float complex );
float complex csinhf( float complex );
float complex ctanhf( float complex );
float complex cexpf( float complex );
float complex cpowf( float complex, float complex );
float complex clogf( float complex );
float complex clognf( float complex, float complex );
float complex clog10f( float complex) ;
float complex csqrf(float complex x );
float complex csqrtf( float complex );

float cargf( float complex );
float complex cprojf( float complex );
float cabsf( float complex );


#ifdef	__cplusplus
}
#endif

#endif