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

double acos(double x) 
{
	return __builtin_acos(x);
}

float acosf(float x) 
{
	return __builtin_acosf(x);
}

long double acosl(long double x) 
{
		return __builtin_acosl(x);
}

double asin(double x) {
	return __builtin_asin(x);
}

float asinf(float x) {
        return __builtin_asinf(x);
}

long double asinl(long double x) {
        return __builtin_asinl(x);
}

double atan(double x) {
	return __builtin_atan(x);
}

float atanf(float x) {
	return __builtin_atanf(x);
}

long double atanl(long double x) {
	return __builtin_atanl(x);
}

double atan2(double y, double x) 
{
		return __builtin_atan2(y,x);
}

float atan2f(float y, float x) 
{
      return __builtin_atan2f(y,x);
}

long double atan2l(long double y, long double x)
{
      return __builtin_atan2l(y,x);
}

double cos(double x) 
{
	return __builtin_cos(x);
}

float cosf(float x) 
{
	return __builtin_cosf(x);
}

long double cosl(long double x) 
{
	return __builtin_cosl(x);
}

double sin(double x) 
{
	return __builtin_sin(x);
}

float sinf(float x) 
{
	return __builtin_sinf(x);
}

long double sinl(long double x) 
{
	return __builtin_sinl(x);
}

double tan(double x) 
{
        return sin(x) / cos(x);
}

float tanf(float x) 
{
        return sinf(x) / cosf(x);
}

long double tanl(long double x) 
{
        return sinl(x) / cosl(x);
}

double acosh(double x) 
{
        return log(x + sqrt(x * x - 1));
}

float acoshf(float x) 
{
        return logf(x + sqrtf(x * x - 1));
}

long double acoshl(long double x) 
{
        return logl(x + sqrtl(x * x - 1));
}

double asinh(double x) 
{
        return log(x + sqrt(x * x + 1));
}

float asinhf(float x) 
{
        return logf(x + sqrtf(x * x + 1));
}

long double asinhl(long double x) 
{
        return logl(x + sqrtl(x * x + 1));
}

double atanh(double x) 
{
        return 0.5 * log((1. + x) / (1. - x));
}

float atanhf(float x) 
{
        return 0.5 * logf((1. + x) / (1. - x));
}

long double atanhl(long double x) 
{
        return 0.5 * logl((1. + x) / (1. - x));
}

double cosh(double x) 
{
        return (exp(x) + exp(-x)) * 0.5;
}

float coshf(float x) 
{
        return (exp(x) + exp(-x)) * 0.5;
}

long double coshl(long double x) 
{
        return (exp(x) + exp(-x)) * 0.5;
}

double sinh(double x) 
{
        return (exp(x) - exp(-x)) * 0.5;
}

float sinhf(float x) 
{
        return (exp(x) - exp(-x)) * 0.5;
}

long double sinhl(long double x) 
{
        return (exp(x) - exp(-x)) * 0.5;
}

double tanh(double x) 
{
        return sinh(x) / cosh(x);
}

float tanhf(float x) 
{
        return sinhf(x) / coshf(x);
}

long double tanhl(long double x) 
{
        return sinhl(x) / coshl(x);
}