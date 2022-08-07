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

void        vec3_set(vec3_t* v, float x, float y, float z) {
    if(v == NULL) return;

    v->x = x;
    v->y = y;
    v->z = z;
}

void      vec3_add(vec3_t* x, const vec3_t a, const vec3_t b) {
    if(x == NULL) return;

    x->x = a.x + b.x;
    x->y = a.y + b.y;
    x->z = a.z + b.z;
}
void      vec3_sub(vec3_t* x, const vec3_t a, const vec3_t b) {
    if(x == NULL) return;

    x->x = a.x - b.x;
    x->y = a.y - b.y;
    x->z = a.z - b.z;
}
void      vec3_div(vec3_t* x, const vec3_t a, const vec3_t b); {
    if(x == NULL) return;

    x->x = a.x / b.x;
    x->y = a.y / b.y;
    x->z = a.z / b.z;
}
void      vec3_mul(vec3_t* x, const vec3_t a, const vec3_t b) {
    if(x == NULL) return;

    x->x = a.x * b.x;
    x->y = a.y * b.y;
    x->z = a.z * b.z;
}

void      vec3_add_f(vec3_t* x, const vec3_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x + b;
    x->y = a.y + b;
    x->z = a.z + b;
}
void      vec3_sub_f(vec3_t* x, const vec3_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x - b;
    x->y = a.y - b;
    x->z = a.z - b;
}
void      vec3_div_f(vec3_t* x, const vec3_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x / b;
    x->y = a.y / b;
    x->z = a.z / b;
}
void      vec3_mul_f(vec3_t* x, const vec3_t a, const float b) {
    if(x == NULL) return;

    x->x = a.x * b;
    x->y = a.y * b;
    x->z = a.z * b;
}

void        vec3_sub_fr(vec3_t* x, const float a, const vec3_t b) {
    if(x == NULL) return;

    x->x = a - b.x;
    x->y = a - b.y;
    x->z = a - b.z;
}
void        vec3_div_fr(vec3_t* x, const float a, const vec3_t b) {
    if(x == NULL) return;

    x->x = a / b.x;
    x->y = a / b.y;
    x->z = a / b.z;
}

int         vec3_equal(const vec3_t a, const vec3_t b) {
    return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z)) ? 0 : -1;
}
int         vec3_inequal(const vec3_t a, const vec3_t b) {
    return ((a.x != b.x) && (a.y != b.y) && (a.z != b.z)) ? 0 : -1;
}
int         vec3_less(const vec3_t a, const vec3_t b) {
    return ((a.x < b.x) && (a.y < b.y) && (a.z < b.z)) ? 0 : -1;
}
int         vec3_greater(const vec3_t a, const vec3_t b) {
    return ((a.x > b.x) && (a.y > b.y) && (a.z > b.z)) ? 0 : -1;
}
int         vec3_less_equel(const vec3_t a, const vec3_t b) {
    return ((a.x <= b.x) && (a.y <= b.y) && (a.z <= b.z)) ? 0 : -1;
}
int         vec3_greater_equel(const vec3_t a, const vec3_t b) {
    return ((a.x >= b.x) && (a.y >= b.y) && (a.z >= b.z)) ? 0 : -1;
}

float       vec3_lenght_sq(const vec3_t v) {
    return sqrtf(v.x * v.x + v.y * v.y  + v.z * v.z ); 
}
float       vec3_lenght(const vec3_t v) {
    return (v.x * v.x + v.y * v.y  + v.z * v.z );
}

void       vec3_normalize(vec3_t* x, const vec3_t v) {
    if(x == NULL) return;

    float _vs = vec3_lenght_sq(v);
    *x = vec3_div_f(&v, v, sqrtf(_vs) );
}
float       vec3_normalize_ex(const vec3_t v) {
    float _vs = vec3_lenght_sq(v);
    *x = vec3_div_f(&v, v, (sqrtf(_vs) + 0.0001f) );
}
float       vec3_dot(const vec3_t v1, const vec3_t v2) {
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
float       vec3_angle(const vec3_t v1, const vec3_t v2) {
    float acV = acosf( v1.x * v2.x + v1.y * v2.y + v1.z * v2.z );
    float sqV = sqrtf( (v1.x * v1.x + v1.y * v1.y + v1.z * v1.z) * (v2.x * v2.x + v2.y * v2.y + v2.z * v2.z));

    return acV / sqV;
}

void       vec3_interpolate_coords(vec3_t* x, const vec3_t v1, const vec3_t v2, const float p) {
    if(x == NULL) return;

   // return v1 + p * (v2 - v1); 

   vec3_t v21; 
   vec3_sub(&v21, v2, v1);      // (v2 - v1)
   vec3_mul_f(&v21, v21, p);    // (v2 - v1) * p
   vec3_add(x, v1, v21);        // x = v1 + (v2 - v1) * p
}
void       vec3_interpolate_normal(vec3_t* x, const vec3_t v1, const vec3_t v2, const float p) {
    if(x == NULL) return;

    // return vec3_normalize(v1 + p * (v2 - v1)); 

    vec3_t v21; 
    vec3_interpolate_coords(&v21, v1, v2, p);   // v21 = v1 + (v2 - v1) * p
    vec3_normalize(x, v21);                     // x = vec3_normalize(v1 + p * (v2 - v1));
}
float       vec3_near_equel(const vec3_t v1, const vec3_t v2, const vec3_t epsilon) {
    //return (( (float)abs( (v1.x - v2.x ) ) <= epsilon) && ( (float)abs( (v1.y - v2.y) ) <= epsilon)); 
    float x = (float)abs( (v1.x - v2.x ) ) ;
    float y = (float)abs( (v1.y - v2.y) );
    float z = (float)abs( (v1.z - v2.z) );

    return ( ( x <= epsilon.x && x <= epsilon.y) && 
             ( y <= epsilon.x && y <= epsilon.y) && 
             ( z <= epsilon.x && z <= epsilon.y) );
}