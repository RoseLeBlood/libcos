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
#ifndef KLIBCOS_VECTORMATH_H
#define KLIBCOS_VECTORMATH_H

#include "types.h"

#ifdef __cplusplus
extern "C" 
{
#endif

typedef struct vec2_t {
    union {
        struct {
            float x;
            float y;
        };
        float c[2];
    };
} vec2_t;

typedef struct vec3_t {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float c[3];
    };
} vec3_t;

typedef struct vec4_t {
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float c[3];
    };
} vec4_t;

typedef struct quaternion {
    union {
        struct {
            float x;
            float y;
            float z;
            float s;
        };
        float q[4];
    };
}quater_t;

void        vec2_set(vec2_t* v, float x, float y);
void        vec3_set(vec3_t* v, float x, float y, float z);
void        vec4_set(vec4_t* v, float x, float y, float z, float w);
void        quater_set(quater_t* q, const float fs, const float fx, const float fy, const float fz);

void        vec2_copy(vec2_t* dest, const vec2_t src);
void        vec3_copy(vec3_t* dest, const vec3_t src);
void        vec4_copy(vec4_t* dest, const vec4_t src);
void        quater_copy(quater_t* dest, const quater_t src);

void        quater_from_angel(quater_t* q, const vec3_t angel);
void        quater_from_axis(quater_t* q, const float angel, const vec3_t axis);

void        quater_conjugate(quater_t* q);
void        quater_identy(quater_t* q);
void        quater_invert(quater_t* q);

void        quater_power(const quater_t* q, float degree, quater_t* pOut);
void        quater_sin(const quater_t* q, quater_t* pOut);
void        quater_cos(const quater_t* q, quater_t* pOut);
void        quater_tan(const quater_t* q, quater_t* pOut);
void        quater_ctan(const quater_t* q, quater_t* pOut);

void        quater_get_rotation_axis(const quater_t* q, vec3_t* pOut);
void        quater_get_rotation_angle(const quater_t* q, float* pOut); 

void        vec2_add(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec3_add(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec4_add(vec4_t* x, const vec4_t a, const vec4_t b);
void        quater_add(quater_t* x, const quater_t a, const quater_t b);

void        vec2_sub(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec3_sub(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec4_sub(vec4_t* x, const vec4_t a, const vec4_t b);
void        quater_sub(quater_t* x, const quater_t a, const quater_t b);

void        vec2_div(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec3_div(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec4_div(vec4_t* x, const vec4_t a, const vec4_t b);
void        quater_div(quater_t* x, const quater_t a, const quater_t b);

void        vec2_mul(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec3_mul(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec4_mul(vec4_t* x, const vec4_t a, const vec4_t b);
void        quater_mul(quater_t* x, const quater_t a, const quater_t b);

void        vec2_add_f(vec2_t* x, const vec2_t a, const float b);
void        vec3_add_f(vec3_t* x, const vec3_t a, const float b);
void        vec4_add_f(vec4_t* x, const vec4_t a, const float b);
void        quater_add_f(quater_t* x, const quater_t a, const float b);

void        vec2_sub_f(vec2_t* x, const vec2_t a, const float b);
void        vec3_sub_f(vec3_t* x, const vec3_t a, const float b);
void        vec4_sub_f(vec4_t* x, const vec4_t a, const float b);
void        quater_sub_f(quater_t* x, const quater_t a, const float b);

void        vec2_div_f(vec2_t* x, const vec2_t a, const float b);
void        vec3_div_f(vec3_t* x, const vec3_t a, const float b);
void        vec4_div_f(vec4_t* x, const vec4_t a, const float b);
void        quater_div_f(quater_t* x, const quater_t a, const float b);

void        vec2_mul_f(vec2_t* x, const vec2_t a, const float b);
void        vec3_mul_f(vec3_t* x, const vec3_t a, const float b);
void        vec4_mul_f(vec4_t* x, const vec4_t a, const float b);
void        quater_mul_f(quater_t* x, const quater_t a, const float b);

void        vec2_sub_fr(vec2_t* x, const float a, const vec2_t b);
void        vec3_sub_fr(vec3_t* x, const float a, const vec3_t b);
void        vec4_sub_fr(vec4_t* x, const float a, const vec4_t b);
void        quater_sub_fr(quater_t* x, const float a, const quater_t b);

void        vec2_div_fr(vec2_t* x, const float a, const vec2_t b) ;
void        vec3_div_fr(vec3_t* x, const float a, const vec3_t b) ;
void        vec4_div_fr(vec4_t* x, const float a, const vec4_t b) ;
void        quater_div_fr(quater_t* x, const float a, const quater_t b);


int         vec2_equal(const vec2_t a, const vec2_t b);
int         vec3_equal(const vec3_t a, const vec3_t b);
int         vec4_equal(const vec4_t a, const vec4_t b);
int         quater_equel(const quater_t a, const quater_t b);

int         vec2_inequal(const vec2_t a, const vec2_t b);
int         vec3_inequal(const vec3_t a, const vec3_t b);
int         vec4_inequal(const vec4_t a, const vec4_t b);
int         quater_inequel(const quater_t a, const quater_t b);

int         vec2_less(const vec2_t a, const vec2_t b);
int         vec3_less(const vec3_t a, const vec3_t b);
int         vec4_less(const vec4_t a, const vec4_t b);
int         quater_less(const quater_t a, const quater_t b);

int         vec2_greater(const vec2_t a, const vec2_t b);
int         vec3_greater(const vec3_t a, const vec3_t b);
int         vec4_greater(const vec4_t a, const vec4_t b);
int         quater_greater(const quater_t a, const quater_t b);

int         vec2_less_equel(const vec2_t a, const vec2_t b);
int         vec3_less_equel(const vec3_t a, const vec3_t b);
int         vec4_less_equel(const vec4_t a, const vec4_t b);
int         quater_less_equel(const quater_t a, const quater_t b);

int         vec2_greater_equel(const vec2_t a, const vec2_t b);
int         vec3_greater_equel(const vec3_t a, const vec3_t b);
int         vec4_greater_equel(const vec4_t a, const vec4_t b);

float       vec2_lenght_sq(const vec2_t v);
float       vec3_lenght_sq(const vec3_t v);
float       vec4_lenght_sq(const vec4_t v);
float       quater_lenght_sq(const quater_t q);
float       vec2_lenght(const vec2_t v);
float       vec3_lenght(const vec3_t v);
float       vec4_lenght(const vec4_t v);
float       quater_lenght(const quater_t q);

void        vec2_normalize(vec2_t* x, const vec2_t v);
void        vec3_normalize(vec3_t* x, const vec3_t v);
void        vec4_normalize(vec4_t* x, const vec4_t v);
void        quater_normalize(quater_t* x, const quater_t q);

void        vec2_normalize_ex(vec2_t* x, const vec2_t v);
void        vec3_normalize_ex(vec3_t* x, const vec3_t v);
void        vec4_normalize_ex(vec4_t* x, const vec4_t v);
float       vec2_dot(const vec2_t a, const vec2_t b);
float       vec3_dot(const vec3_t a, const vec3_t b);
float       vec4_dot(const vec4_t a, const vec4_t b);
float       quater_dot(const quater_t a, const quater_t b);
float       vec2_angle(const vec2_t a, const vec2_t b);
float       vec3_angle(const vec3_t a, const vec3_t b);
float       vec4_angle(const vec4_t a, const vec4_t b);

void        vec2_interpolate_coords(vec2_t* x, const vec2_t a, const vec2_t b, const float e);
void        vec3_interpolate_coords(vec3_t* x, const vec3_t a, const vec3_t b, const float e);
void        vec4_interpolate_coords(vec4_t* x, const vec4_t a, const vec4_t b, const float e);
void        vec2_interpolate_normal(vec2_t* x, const vec2_t a, const vec2_t b, const float e);
void        vec3_interpolate_normal(vec3_t* x, const vec3_t a, const vec3_t b, const float e);
void        vec4_interpolate_normal(vec4_t* x, const vec4_t a, const vec4_t b, const float e);
void        quater_interpolate_linear(quater_t* pOut, const quater_t a, const quater_t b, const float e); 

float       vec2_near_equel(const vec2_t a, const vec2_t b, const vec2_t e);
float       vec3_near_equel(const vec3_t a, const vec3_t b, const vec3_t e);
float       vec4_near_equel(const vec4_t a, const vec4_t b, const vec4_t e);

void        quater_exp(const quater_t* q, quater_t* pOut);
void        quater_log(const quater_t* q, quater_t* pOut);
void        quater_pow(const quater_t* q, float exp, quater_t* pOut);
void        quater_sin(const quater_t* q, quater_t* pOut);
void        quater_cos(const quater_t* q, quater_t* pOut);
void        quater_tan(const quater_t* q, quater_t* pOut);
void        quater_ctan(const quater_t* q, quater_t* pOut);

#ifdef __cplusplus
}
#endif

#endif