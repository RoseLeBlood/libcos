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

void        vec4_set(vec4_t* v, float x, float y, float z, float w) {
    if(v == NULL) return;

    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}
void        vec4_copy(vec4_t* dest, const vec4_t src) {
    if(!dest) return;
   
	dest->x = src.x;
    dest->y = src.y;
    dest->z = src.z;
    dest->w = src.w;
}
void      vec4_add(vec4_t* x, const vec4_t a, const vec4_t b) {
    if(x == NULL) return;

    x->x = a.x + b.x;
    x->y = a.y + b.y;
    x->z = a.z + b.z;
    x->w = a.w + b.w;
}
void      vec4_sub(vec4_t* x, const vec4_t a, const vec4_t b) {
    if(x == NULL) return;

    x->x = a.x - b.x;
    x->y = a.y - b.y;
    x->z = a.z - b.z;
    x->w = a.w - b.w;
}
void      vec4_div(vec4_t* x, const vec4_t a, const vec4_t b) {
    if(x == NULL) return;

    x->x = a.x / b.x;
    x->y = a.y / b.y;
    x->z = a.z / b.z;
    x->w = a.w / b.w;
}
void      vec4_mul(vec4_t* x, const vec4_t a, const vec4_t b) {
    if(x == NULL) return;

    x->x = a.x * b.x;
    x->y = a.y * b.y;
    x->z = a.z * b.z;
    x->w = a.w * b.w;
}

void      vec4_add_f(vec4_t* x, const vec4_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x + b;
    x->y = a.y + b;
    x->z = a.z + b;
    x->w = a.w + b;
}
void      vec4_sub_f(vec4_t* x, const vec4_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x - b;
    x->y = a.y - b;
    x->z = a.z - b;
    x->w = a.w - b;
}
void      vec4_div_f(vec4_t* x, const vec4_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x / b;
    x->y = a.y / b;
    x->z = a.z / b;
    x->w = a.w / b;
}
void      vec4_mul_f(vec4_t* x, const vec4_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x * b;
    x->y = a.y * b;
    x->z = a.z * b;
    x->w = a.w * b;
}

void        vec4_sub_fr(vec4_t* x, const float a, const vec4_t b) {
    if(x == NULL) return;

    x->x = a - b.x;
    x->y = a - b.y;
    x->z = a - b.z;
    x->w = a - b.w;
}
void        vec4_div_fr(vec4_t* x, const float a, const vec4_t b) {
    if(x == NULL) return;

    x->x = a / b.x;
    x->y = a / b.y;
    x->z = a / b.z;
    x->w = a / b.w;
}

int         vec4_equal(const vec4_t a, const vec4_t b) {
    return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w)) ? 0 : -1;
}
int         vec4_inequal(const vec4_t a, const vec4_t b) {
    return ((a.x != b.x) && (a.y != b.y) && (a.z != b.z) && (a.w != b.w)) ? 0 : -1;
}
int         vec4_less(const vec4_t a, const vec4_t b) {
    return ((a.x < b.x) && (a.y < b.y) && (a.z < b.z) && (a.w < b.w)) ? 0 : -1;
}
int         vec4_greater(const vec4_t a, const vec4_t b) {
    return ((a.x > b.x) && (a.y > b.y) && (a.z > b.z) && (a.w > b.w)) ? 0 : -1;
}
int         vec4_less_equel(const vec4_t a, const vec4_t b) {
    return ((a.x <= b.x) && (a.y <= b.y) && (a.z <= b.z) && (a.w <= b.w)) ? 0 : -1;
}
int         vec4_greater_equel(const vec4_t a, const vec4_t b) {
    return ((a.x >= b.x) && (a.y >= b.y) && (a.z >= b.z) && (a.w >= b.w)) ? 0 : -1;
}

float       vec4_lenght_sq(const vec4_t v) {
    return sqrtf(v.x * v.x + v.y * v.y  + v.z * v.z + v.w * v.w); 
}
float       vec4_lenght(const vec4_t v) {
    return (v.x * v.x + v.y * v.y  + v.z * v.z + v.w * v.w);
}

void       vec4_normalize(vec4_t* x, const vec4_t v) {
    if(x == NULL) return;

    float _vs = vec4_lenght_sq(v);
    vec4_div_f(x, v, sqrtf(_vs) );
}
void       vec4_normalize_ex(vec4_t* x, const vec4_t v) {
    float _vs = vec4_lenght_sq(v);
    vec4_div_f(x, v, (sqrtf(_vs) + 0.0001f) );
}
float       vec4_dot(const vec4_t v1, const vec4_t v2) {
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w + v2.w);
}
float       vec4_angle(const vec4_t v1, const vec4_t v2) {
    float acV = acosf( (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w + v2.w));
    float sqV = sqrtf( (v1.x * v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w) * (v2.x * v2.x + v2.y * v2.y + v2.z * v2.z + v2.w * v2.w));

    return acV / sqV;
}

void       vec4_interpolate_coords(vec4_t* x, const vec4_t v1, const vec4_t v2, const float p) {
    if(x == NULL) return;

   // return v1 + p * (v2 - v1); 

   vec4_t v21; 
   vec4_sub(&v21, v2, v1);      // (v2 - v1)
   vec4_mul_f(&v21, v21, p);    // (v2 - v1) * p
   vec4_add(x, v1, v21);        // x = v1 + (v2 - v1) * p
}
void       vec4_interpolate_normal(vec4_t* x, const vec4_t v1, const vec4_t v2, const float p) {
    if(x == NULL) return;

    // return vec4_normalize(v1 + p * (v2 - v1)); 

    vec4_t v21; 
    vec4_interpolate_coords(&v21, v1, v2, p);   // v21 = v1 + (v2 - v1) * p
    vec4_normalize(x, v21);                     // x = vec4_normalize(v1 + p * (v2 - v1));
}
float       vec4_near_equel(const vec4_t v1, const vec4_t v2, const vec4_t epsilon) {
    //return (( (float)abs( (v1.x - v2.x ) ) <= epsilon) && ( (float)abs( (v1.y - v2.y) ) <= epsilon)); 
    float x = (float)abs( (v1.x - v2.x) );
    float y = (float)abs( (v1.y - v2.y) );
    float z = (float)abs( (v1.z - v2.z) );
    float w = (float)abs( (v1.w - v2.w) );

    return ( ( x <= epsilon.x && x <= epsilon.y) && 
             ( y <= epsilon.x && y <= epsilon.y) && 
             ( z <= epsilon.x && z <= epsilon.y) && 
             ( w <= epsilon.x && w <= epsilon.y) );
}