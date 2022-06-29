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

double cbrt(double x) 
{
        return pow(x, 1. / 3.);
}

float cbrtf(float x) 
{
        return powf(x, 1. / 3.);
}

long double cbrtl(long double x) 
{
        return powl(x, 1. / 3.);
}

double fabs(double x)
{
	return __builtin_fabs(x);
}

float fabsf(float x) 
{
	return __builtin_fabsf(x);
}

long double fabsl(long double x)
{
	return __builtin_fabsl(x);
}

double hypot(double x, double y) 
{
        return sqrt(x*x + y*y);
}

float hypotf(float x, float y) 
{
        return sqrt(x*x + y*y);
}

long double hypotl(long double x, long double y) 
{
        return sqrt(x*x + y*y);
}

double pow(double x, double y) 
{
        return exp(y * log(x));
}

float powf(float x, float y) 
{
        return exp(y * log(x));
}

long double powl(long double x, long double y) 
{
        return exp(y * log(x));
}

double sqrt(double x) 
{
     return __builtin_sqrt(x);
}
long double sqrtl(long double x) 
{
     return __builtin_sqrtl(x);
}
float sqrtf(float x)
{
	return __builtin_sqrtf(x);
}