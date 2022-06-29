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
#include "complex.h"
#include "math.h"
#include "endian.h"

#define CREAL(z) (__real__ z)
#define CIMAG(z) (__imag__ z)

static inline double complex __complex_helper_a(double complex x, const char mode) {
    double complex one = __builtin_complex(1.0, 0.0);
    double complex d =__builtin_complex(0.0, -1.0);
    double complex c = ( one - csqr(x) );
    
    c = csqrt(c);
    c = (mode == 0) ? (c + x * d) : (x + c * d);
    
    CIMAG(d) = 1;
    return clog(c) * d;
}

static inline double complex __complex_helper_h(double complex x, const char mode){
    double complex c = csqr(x);

    c = (mode == 0) ? c + 1 : c - 1;
    
    c = ( (x + csqrt(c)) );
    return clog(c);
}

static inline double complex __complex_helper_af(double complex x, const char mode) {
    float complex one = __builtin_complex(1.0f, 0.0f);
    double complex d = __builtin_complex(0.0f, -1.0f);
    double complex c = ( one - csqrf(x) );
    
    c = csqrtf(c);

    if (mode == 0) c = c + x * d;
    else  c = x + c * d;
    
    CIMAG(d) = 1;
    return clogf(c) * d;
}
static inline float complex __complex_helper_hf(float complex x, const char mode){
    double complex c = csqrf(x);

    c = (mode == 0) ? c + 1 : c - 1;
    
    c = ( (x + csqrtf(c)) );
    return clog(c);
}


double complex csqr(double complex x )  {
    double complex res =  __builtin_complex(CREAL(x) * CREAL(x) - CIMAG(x) * CIMAG(x),
                                            2 * CREAL(x) * CIMAG(x));
    return res;
}


float complex csqrf(float complex x )  {
    float complex res =  __builtin_complex(CREAL(x) * CREAL(x) - CIMAG(x) * CIMAG(x),
                                            2 * CREAL(x) * CIMAG(x));
    return res;
}

double complex csqrt( double complex x ) {
    double complex res;

    double m = hypot(CREAL(x), CIMAG(x));

    CREAL(res) = sqrt(0.5 * (m + CREAL(x)));

    if (CIMAG(x) >= 0)
        CIMAG(res) = sqrt(0.5 * (m - CREAL(x)));
    else
        CIMAG(res) = -( sqrt(0.5 * (m - CREAL(x))) );

    return res;
}
float complex csqrtf( float complex x ) {
    float complex res;

    float m = hypotf(CREAL(x), CIMAG(x));

    CREAL(res) = sqrtf(0.5 * (m + CREAL(x)));

    if (CIMAG(x) >= 0)
        CIMAG(res) = sqrtf(0.5 * (m - CREAL(x)));
    else
        CIMAG(res) = -( sqrtf(0.5 * (m - CREAL(x))) );

    return res;
}

double complex cexp(double complex x)  {
    double e = expf(CREAL(x));

   double complex res = __builtin_complex(e * cos(CIMAG(x)), e * sin(CIMAG(x)) );
   return res;
}

float complex cexpf(float complex x)  {
    float e = expf(CREAL(x));

    float complex res = __builtin_complex(e * cos(CIMAG(x)), e * sin(CIMAG(x)) );
    return res;
}

double complex clog(double complex x) {
    double m = hypot(CREAL(x), CIMAG(x));
    double p = atan2(CIMAG(x), CREAL(x));

    if (p > M_PI) p -= 2 * M_PI;

    double complex res = __builtin_complex(log(m), p);

    return res;
}

float complex clogf(float complex x) {
    float m = hypot(CREAL(x), CIMAG(x));
    float p = atan2(CIMAG(x), CREAL(x));

    if (p > M_PI) p -= 2 * M_PI;

    float complex res = __builtin_complex(logf(m), p);

    return res;
}

double complex cpow(double complex b, double complex p) {
    double complex t = clog(b);

    t = __builtin_complex(CREAL(t) * CREAL(p), CIMAG(t) * CIMAG(p));

    return cexp(t);
}
float complex cpowf(float complex b, float complex p) {
    float complex t = clogf(b);

    t = __builtin_complex(CREAL(t) * CREAL(p), CIMAG(t) * CIMAG(p));

    return cexpf(t);
}
double complex clogn( double complex b, double complex c ) {
    double complex t =  c;

     return clog(b) / clog(t);
}

float complex clognf( float complex b, float complex c ) {
    float complex t =  c;

     return clogf(b) / clogf(t);
}

double complex clog10( double complex x) {
    return clogn(x, 10);
}
float complex clog10f( float complex x) {
    return clognf(x, 10);
}

double complex csin(double complex x) {
    double complex res = __builtin_complex(sin(CREAL(x)) * cosh(CIMAG(x)), 
                                           cos(CREAL(x)) * sinh(CIMAG(x)) );

    return res;
}
float complex csinf(float complex x) {
    float complex res = __builtin_complex(sinf(CREAL(x)) * coshf(CIMAG(x)), 
                                           cosf(CREAL(x)) * sinhf(CIMAG(x)) );

    return res;
}

double complex ccos(double complex x) {
    double complex res = __builtin_complex(cos(CREAL(x)) * cosh(CIMAG(x) ), 
                                           -sin(CREAL(x)) * sinh(CIMAG(x) ) );

    return res;
}

float complex ccosf(float complex x) {
    float complex res = __builtin_complex(cosf(CREAL(x)) * coshf(CIMAG(x) ), 
                                         -sinf(CREAL(x)) * sinhf(CIMAG(x) ) );

    return res;
}
double complex ctan(double complex x) {
  return csin(x) / ccos(x);
}
float complex ctanf(float complex x) {
  return csinf(x) / ccosf(x);
}


double complex casin(double complex x) {
  return __complex_helper_a(x, 0);
}
float complex casinf(float complex x) {
  return __complex_helper_af(x, 0);
}

double complex cacos(double complex x) {
  return __complex_helper_a(x, 1);
}
float complex cacosf(float complex x) {
  return __complex_helper_af(x, 1);
}

double complex catan(double complex x) {
    double complex d  = __builtin_complex(0.0, -1.0);
    double complex x1 = __builtin_complex(CREAL(x), CIMAG(x) - 1 );
    double complex m  = __builtin_complex(CREAL(x), -CIMAG(x) - 1) ;

    return clog( (d * (x1 / m)) ) * 0.5;
}
float complex catanf(float complex x) {
    float complex d  = __builtin_complex(0.0f, -1.0f);
    float complex x1 = __builtin_complex(CREAL(x), CIMAG(x) - 1 );
    float complex m  = __builtin_complex(CREAL(x), -CIMAG(x) - 1) ;

    return clog( (d * (x1 / m)) ) * 0.5f;
}

double complex csinh(double complex x) {
    double complex res;

    CREAL(res) = cos(CIMAG(x)) * sinh(CREAL(x));
    CIMAG(res) = sin(CIMAG(x)) * cosh(CREAL(x)); 

    return res;
}

float complex csinhf(float complex x) {
    float complex res;

    CREAL(res) = cosf(CIMAG(x)) * sinhf(CREAL(x));
    CIMAG(res) = sinf(CIMAG(x)) * coshf(CREAL(x)); 

    return res;
}


double complex ccosh(double complex x) {
    double complex res;

    CREAL(res) = cos(CIMAG(x)) * cosh(CREAL(x));
    CIMAG(res) = sin(CIMAG(x)) * sinh(CREAL(x)); 

    return res;
}

float complex ccoshf(float complex x) {
    float complex res;

    CREAL(res) = cosf(CIMAG(x)) * coshf(CREAL(x));
    CIMAG(res) = sinf(CIMAG(x)) * sinhf(CREAL(x)); 

    return res;
}

double complex ctanh(double complex x) {
  return csinh(x) / ccosh(x);
}

float complex ctanhf(float complex x) {
  return csinhf(x) / ccoshf(x);
}

double complex cacosh( double complex x ) {
    return __complex_helper_h(x, 0);
}
float complex cacoshf( float complex x ) {
    return __complex_helper_hf(x, 0);
}

double complex casinh( double complex x) {
    return __complex_helper_h(x, 1);
}
float complex casinhf( float complex x) {
    return __complex_helper_hf(x, 1);
}

double complex catanh( double complex x) {
    double complex one = __builtin_complex(1.0, 0.0);
    double complex c = clog(x + one);

    c = c - (-(x - one));
    c = clog(c);

    return c * 0.5;
}
float complex catanhf( float complex x) {
    float complex one = __builtin_complex(1.0f, 0.0f);
    float complex c = clogf(x + one);

    c = c - (-(x - one));
    c = clogf(c);

    return c * 0.5;
}
double carg( double complex x) {
    return atan2(CIMAG(x), CREAL(x));
}
float cargf( float complex x) {
    return atan2f(CIMAG(x), CREAL(x));
}

double complex cproj( double complex x) {
    register double complex res;
    register double den;

    den = CREAL(x) * CREAL(x) + CIMAG(x) * CIMAG(x) + 1.0;
    res =__builtin_complex( (2.0 * CREAL(x)) / den, (2.0 * CIMAG(x)) / den );

    return res;
}

float complex cprojf( float complex x) {
    register float complex res;
    register float den;

    den = CREAL(x) * CREAL(x) + CIMAG(x) * CIMAG(x) + 1.0;
    res =__builtin_complex( (2.0 * CREAL(x)) / den, (2.0 * CIMAG(x)) / den );

    return res;
}
double cabs( double complex x) {
    register double complex res;

    res = hypot(CREAL(x), CIMAG(x)); 

    return res;
}

float cabsf( float complex x) {
    register float complex res;

    res = hypotf(CREAL(x), CIMAG(x)); 

    return res;
}