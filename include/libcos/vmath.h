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

#define VEC2(V)         vec2_set(&V, 0.0f, 0.0f)
#define VEC2(V,a)       vec2_set(&V, a, a)
#define VEC2(V, x, y)   vec2_set(&V, x, y)

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
        float c[4];
    };
} vec4_t;

void        vec2_set(vec2_t* v, float x, float y);

void        vec2_add(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec2_sub(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec2_div(vec2_t* x, const vec2_t a, const vec2_t b);
void        vec2_mul(vec2_t* x, const vec2_t a, const vec2_t b);

void        vec2_add_f(vec2_t* x, const vec2_t a, const float b);
void        vec2_sub_f(vec2_t* x, const vec2_t a, const float b);
void        vec2_div_f(vec2_t* x, const vec2_t a, const float b);
void        vec2_sub_fr(vec2_t* x, const float a, const vec2_t b);
void        vec2_div_fr(vec2_t* x, const float a, const vec2_t b);
void        vec2_mul_f(vec2_t* x, const vec2_t a, const float b);

int         vec2_equal(const vec2_t a, const vec2_t b);
int         vec2_inequal(const vec2_t a, const vec2_t b);
int         vec2_less(const vec2_t a, const vec2_t b);
int         vec2_greater(const vec2_t a, const vec2_t b);

float       vec2_lenght_sq(const vec2_t v);
float       vec2_lenght(const vec2_t v);

void        vec2_normalize(vec2_t* x, const vec2_t v);
void        vec2_normalize_ex(vec2_t* x, const vec2_t v);
float       vec2_dot(const vec2_t a, const vec2_t b);
float       vec2_angle(const vec2_t a, const vec2_t b);

void        vec2_interpolate_coords(vec2_t* x, const vec2_t a, const vec2_t b, const float e);
void        vec2_interpolate_normal(vec2_t* x, const vec2_t a, const vec2_t b, const float e);
float       vec2_near_equel(const vec2_t a, const vec2_t b, const vec2_t e);




void        vec3_set(vec3_t* v, float x, float y);

void        vec3_add(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec3_sub(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec3_div(vec3_t* x, const vec3_t a, const vec3_t b);
void        vec3_mul(vec3_t* x, const vec3_t a, const vec3_t b);

void        vec3_add_f(vec3_t* x, const vec3_t a, const float b);
void        vec3_sub_f(vec3_t* x, const vec3_t a, const float b);
void        vec3_div_f(vec3_t* x, const vec3_t a, const float b);
void        vec3_sub_fr(vec3_t* x, const float a, const vec3_t b);
void        vec3_div_fr(vec3_t* x, const float a, const vec3_t b);
void        vec3_mul_f(vec3_t* x, const vec3_t a, const float b);

int         vec3_equal(const vec3_t a, const vec3_t b);
int         vec3_inequal(const vec3_t a, const vec3_t b);
int         vec3_less(const vec3_t a, const vec3_t b);
int         vec3_greater(const vec3_t a, const vec3_t b);

float       vec3_lenght_sq(const vec3_t v);
float       vec3_lenght(const vec3_t v);

void        vec3_normalize(vec3_t* x, const vec3_t v);
void        vec3_normalize_ex(vec3_t* x, const vec3_t v);
float       vec3_dot(const vec3_t a, const vec3_t b);
float       vec3_angle(const vec3_t a, const vec3_t b);

void        vec3_interpolate_coords(vec3_t* x, const vec3_t a, const vec3_t b, const float e);
void        vec3_interpolate_normal(vec3_t* x, const vec3_t a, const vec3_t b, const float e);
float       vec3_near_equel(const vec3_t a, const vec3_t b, const vec3_t e);

#ifdef __cplusplus
}
#endif

#endif