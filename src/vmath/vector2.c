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
#include "vmath.h"
#include "math.h"
#include "stdlib.h"

void        vec2_set(vec2_t* v, float x, float y) {
    if(v == NULL) return;

    v->x = x;
    v->y = y;
}

void      vec2_add(vec2_t* x, const vec2_t a, const vec2_t b) {
    if(x == NULL) return;

    x->x = a.x + b.x;
    x->y = a.y + b.y;
}
void      vec2_sub(vec2_t* x, const vec2_t a, const vec2_t b) {
    if(x == NULL) return;

    x->x = a.x - b.x;
    x->y = a.y - b.y;
}
void      vec2_div(vec2_t* x, const vec2_t a, const vec2_t b) {
    if(x == NULL) return;

    x->x = a.x / b.x;
    x->y = a.y / b.y;
}
void      vec2_mul(vec2_t* x, const vec2_t a, const vec2_t b) {
    if(x == NULL) return;

    x->x = a.x * b.x;
    x->y = a.y * b.y;
}

void      vec2_add_f(vec2_t* x, const vec2_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x + b;
    x->y = a.y + b;
}
void      vec2_sub_f(vec2_t* x, const vec2_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x - b;
    x->y = a.y - b;
}
void      vec2_div_f(vec2_t* x, const vec2_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x / b;
    x->y = a.y / b;
}
void      vec2_mul_f(vec2_t* x, const vec2_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x * b;
    x->y = a.y * b;
}

void        vec2_sub_fr(vec2_t* x, const float a, const vec2_t b) {
    if(x == NULL) return;

    x->x = a - b.x;
    x->y = a - b.y;
}
void        vec2_div_fr(vec2_t* x, const float a, const vec2_t b) {
    if(x == NULL) return;

    x->x = a / b.x;
    x->y = a / b.y;
}

int         vec2_equal(const vec2_t a, const vec2_t b) {
    return ((a.x == b.x) && (a.y == b.y)) ? 0 : -1;
}
int         vec2_inequal(const vec2_t a, const vec2_t b) {
    return ((a.x != b.x) && (a.y != b.y)) ? 0 : -1;
}
int         vec2_less(const vec2_t a, const vec2_t b) {
    return ((a.x < b.x) && (a.y < b.y)) ? 0 : -1;
}
int         vec2_greater(const vec2_t a, const vec2_t b) {
    return ((a.x > b.x) && (a.y > b.y)) ? 0 : -1;
}
int         vec2_less_equel(const vec2_t a, const vec2_t b) {
    return ((a.x <= b.x) && (a.y <= b.y)) ? 0 : -1;
}
int         vec2_greater_equel(const vec2_t a, const vec2_t b) {
    return ((a.x >= b.x) && (a.y >= b.y)) ? 0 : -1;
}

float       vec2_lenght_sq(const vec2_t v) {
    return sqrtf(v.x * v.x + v.y * v.y ); 
}
float       vec2_lenght(const vec2_t v) {
    return (v.x * v.x + v.y * v.y );
}

void       vec2_normalize(vec2_t* x, const vec2_t v) {
    if(x == NULL) return;

    // return v / sqrtf(v.x * v.x + v.y * v.y );
    float _vs = vec2_lenght_sq(v);
    vec2_div_f(x, v, sqrtf(_vs) );
}
void vec2_normalize_ex(vec2_t* x, const vec2_t v) {
    // return v / sqrtf( (v.x * v.x + v.y * v.y ) + 0.0001f );

    float _vs = vec2_lenght_sq(v);
    vec2_div_f(x, v, (sqrtf(_vs) + 0.0001f) );
}
float       vec2_dot(const vec2_t v1, const vec2_t v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}
float       vec2_angle(const vec2_t v1, const vec2_t v2) {
    float acV = acosf( (v1.x * v2.x + v1.y * v2.y ) );
    float sqV = sqrtf( (v1.x * v1.x + v1.y * v1.y ) * (v2.x * v2.x + v2.y * v2.y) );

    return acV / sqV;
}

void       vec2_interpolate_coords(vec2_t* x, const vec2_t v1, const vec2_t v2, const float p) {
    if(x == NULL) return;

   // return v1 + p * (v2 - v1); 

   vec2_t v21; 
   vec2_sub(&v21, v2, v1);      // (v2 - v1)
   vec2_mul_f(&v21, v21, p);    // (v2 - v1) * p
   vec2_add(x, v1, v21);        // x = v1 + (v2 - v1) * p
}
void       vec2_interpolate_normal(vec2_t* x, const vec2_t v1, const vec2_t v2, const float p) {
    if(x == NULL) return;

    // return vec2_normalize(v1 + p * (v2 - v1)); 

    vec2_t v21; 
    vec2_interpolate_coords(&v21, v1, v2, p);   // v21 = v1 + (v2 - v1) * p
    vec2_normalize(x, v21);                     // x = vec2_normalize(v1 + p * (v2 - v1));
}
float       vec2_near_equel(const vec2_t v1, const vec2_t v2, const vec2_t epsilon) {
    //return (( (float)abs( (v1.x - v2.x ) ) <= epsilon) && ( (float)abs( (v1.y - v2.y) ) <= epsilon)); 
    float x = (float)abs( (v1.x - v2.x ) ) ;
    float y = (float)abs( (v1.y - v2.y) );

    return ( ( x <= epsilon.x && x <= epsilon.y) && ( y <= epsilon.x && y <= epsilon.y) );
}