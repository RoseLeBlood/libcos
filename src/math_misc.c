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
#include <math.h>
#include <stdint.h>

double 				remainer(double x, double y) ;
float 				remainerf(float x, float y) ;
long double 		remainerl(long double x, long double y) ;
double 				remquo(double x, double y, int* quo) ;
float 				remquof(float x, float y, int* quo) ;
long double 		remquol(long double x, long double y, int* quo) ;

double                  erf(double x)
{
	return __builtin_erf(x);
}
float                           erff(float x)
{
	return __builtin_erff(x);
}
long double             erfl(long double x)
{
	return __builtin_erfl(x);
}
double                  erfc(double x)
{
	return __builtin_erfc(x);
}
float                           erfcf(float x)
{
	return __builtin_erfcf(x);
}
long double             erfcl(long double x)
{
	return __builtin_erfcl(x);
}
double                  lgamma(double x)
{
	return __builtin_lgamma(x);
}
float                           lgammaf(float x)
{
	return __builtin_lgammaf(x);
}
long double             lgammal(long double x)
{
	return __builtin_lgammal(x);
}
double                  tgamma(double x)
{
	return __builtin_tgamma(x);
}
float                           tgammaf(float x)
{
	return __builtin_tgammaf(x);
}
long double             tgammal(long double x)
{
	return __builtin_tgammal(x);
}

double ceil(double x)
{
	return __builtin_ceil(x);
}

float ceilf(float x) 
{
	return __builtin_ceilf(x);
}

long double ceill(long double x) 
{
	return __builtin_ceill(x);
}

double floor(double x) 
{
	return __builtin_floor(x);
}

float floorf(float x) 
{
	return __builtin_floorf(x);
}

long double floorl(long double x) 
{
		return __builtin_floorl(x);
}

double nearbyint(double x) 
{
		return __builtin_nearbyint(x);
}

float nearbyintf(float x)
{
		return __builtin_nearbyintf(x);
}

long double nearbyintl(long double x) 
{
		return __builtin_nearbyintl(x);
}

double                  rint(double x)
{
		return __builtin_rint(x);
}
float                           rintf(float x)
{
		return __builtin_rintf(x);
}
long double             rintl(long double x)
{
		return __builtin_rintl(x);
}
long int                        lrint(double x)
{
		return __builtin_lrint(x);
}
long int                        lrintf(float x)
{
		return __builtin_lrintf(x);
}
long int                        lrintl(long double x)
{
		return __builtin_lrintl(x);
}
long long int           llrint(double x)
{
		return __builtin_llrint(x);
}
long long int           llrintf(float x)
{
		return __builtin_llrintf(x);
}
long long int           llrintl(long double x)
{
		return __builtin_llrintl(x);
}
double                  round(double x)
{
		return __builtin_round(x);
}
float                           roundf(float x)
{
		return __builtin_roundf(x);
}
long double             roundl(long double x)
{
		return __builtin_roundf(x);
}
long int                        lround(double x)
{
		return __builtin_lround(x);
}
long int                        lroundf(float x)
{
		return __builtin_lroundf(x);
}
long int                        lroundl(long double x)
{
		return __builtin_lroundl(x);
}
long long int           llround(double x)
{
		return __builtin_llround(x);
}
long long int           llroundf(float x)
{
		return __builtin_llroundf(x);
}
long long int           llroundl(long double x)
{
		return __builtin_llroundl(x);
}
double                  trunc(double x)
{
		return __builtin_trunc(x);
}
float                           truncf(float x)
{
		return __builtin_truncf(x);
}
long double             truncl(long double x)
{
		return __builtin_truncl(x);
}
double                  fmod(double x, double y)
{
		return __builtin_fmod(x,y);
}
float                           fmodf(float x, float y)
{
		return __builtin_fmodf(x,y);
}
long double             fmodl(long double x, long double y)
{
		return __builtin_fmodl(x,y);
}



double copysign(double x, double y) {
        double magnitude = fabs(x);
        return signbit(y) ? -magnitude : magnitude;
}

float copysignf(float x, float y) {
        double magnitude = fabsf(x);
        return signbit(y) ? -magnitude : magnitude;
}

long double copysignl(long double x, long double y) {
        double magnitude = fabsl(x);
        return signbit(y) ? -magnitude : magnitude;
}

double                  nan(const char* tagp)
{
		return __builtin_nan(tagp);
}
float                           nanf(const char* tagp)
{
		return __builtin_nanf(tagp);
}
long double             nanl(const char* tagp)
{
		return __builtin_nanl(tagp);
}
double                  nextafter(double x, double y)
{
		return __builtin_nextafter(x,y);
}
float                           nextafterf(float x, float y)
{
		return __builtin_nextafterf(x,y);
}
long double             nextafterl(long double x, long double y)
{
		return __builtin_nextafterl(x,y);
}
double                  nexttoward(double x, long double y)
{
		return __builtin_nexttoward(x,y);
}
float                           nexttowardf(float x, long double y)
{
		return __builtin_nexttowardf(x,y);
}
long double             nexttowardl(long double x, long double y)
{
		return __builtin_nexttowardl(x,y);
}

double fdim(double x, double y) {
        return (x > y) ? (x - y) : 0;
}

float fdimf(float x, float y) {
        return (x > y) ? (x - y) : 0;
}

long double fdiml(long double x, long double y) {
        return (x > y) ? (x - y) : 0;
}

double fmax(double x, double y) {
        return (x > y) ? x : y;
}

float fmaxf(float x, float y) {
        return (x > y) ? x : y;
}

long double fmaxl(long double x, long double y) {
        return (x > y) ? x : y;
}

double fmin(double x, double y) {
        return (x < y) ? x : y;
}

float fminf(float x, float y) {
        return (x < y) ? x : y;
}

long double fminl(long double x, long double y) {
        return (x < y) ? x : y;
}

double fma(double x, double y, double z) {
        return x * y + z;
}

float fmaf(float x, float y, float z) {
        return x * y + z;
}

long double fmal(long double x, long double y, long double z) {
        return x * y + z;
}

double remainder(double x, double y) {
	register double res, ratio, n, two_c;

	ratio = x/y;
	n = round(ratio);

	two_c = fmod(n,2.0);

	if (!(fabs(n-ratio) == 0.5) )  {
		n = n - two_c;
	}
	res = x - n * y;

	return res;
}
float remainderf(float x, float y) {
	register float res, ratio, n, two_c;

	ratio = x/y;
	n = roundf(ratio);

	two_c = fmodf(n,2.0);

	if (!(fabsf(n-ratio) == 0.5f) )  {
		n = n - two_c;
	}
	res = x - n * y;

	return res;
}

float factf(float p) {
	if ( p == 0.0f || p == 1.0f ) return 1.0f;
	else if ( p < 0.0f ) return 0.0f;

	register float f = 1.0f ;

	while( p > 1.0f ) {
		f *= p ;
		p-- ;
	}

	return f;
}