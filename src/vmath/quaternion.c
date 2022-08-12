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
#include "assert.h"

void quater_set(quater_t* q, const float fs, const float fx, const float fy, const float fz) {
    if(!q) return;
    q->s = fs;
	q->x = fx;
    q->y = fy;
    q->z = fz;
}
void        quater_copy(quater_t* dest, const quater_t src) {
	if(!dest) return;
    dest->s = src.s;
	dest->x = src.x;
    dest->y = src.y;
    dest->z = src.z;
}

void quater_from_angel(quater_t* q, const vec3_t angel) {
    if(!q) return;

    float cos_z_2 = cosf(0.5f*(float)angel.z);
	float cos_y_2 = cosf(0.5f*(float)angel.y);
	float cos_x_2 = cosf(0.5f*(float)angel.x);

	float sin_z_2 = sinf(0.5f*(float)angel.z);
	float sin_y_2 = sinf(0.5f*(float)angel.y);
	float sin_x_2 = sinf(0.5f*(float)angel.x);

	// and now compute quaternion
	q->s   = cos_z_2*cos_y_2*cos_x_2 + sin_z_2*sin_y_2*sin_x_2;
	q->x = cos_z_2*cos_y_2*sin_x_2 - sin_z_2*sin_y_2*cos_x_2;
	q->y = cos_z_2*sin_y_2*cos_x_2 + sin_z_2*cos_y_2*sin_x_2;
	q->z = sin_z_2*cos_y_2*cos_x_2 - cos_z_2*sin_y_2*sin_x_2;
}
void quater_from_axis(quater_t* q, const float angel, const vec3_t axis) {
    if(!q) return;

    register float omega, s, c;
	quater_t norm;

	s = vec3_lenght(axis);

	if (fabs(s) > FLT_EPSILON) {
		c = 1.0f / s;
        
        omega = -0.5f * angel;
		s = sinf(omega);

		q->x = axis.x * c * s;
		q->y = axis.y * c * s;
		q->z = axis.z * c * s;

        q->s = cosf(omega);
	} else {
		quater_identy(q);
	}

    quater_normalize(q, norm);

	q->s = norm.s;
	q->x = norm.x;
	q->y = norm.y;
	q->z = norm.z;
}
void        quater_mul(quater_t* x, const quater_t a, const quater_t b) {
	x->s = ((a.s * b.s) - (a.x * b.x) - (a.y * b.z) - (a.z * b.z));
	x->x = ((a.s * b.x) + (a.x * b.s) + (a.y * b.y) - (a.z * b.y));
	x->y = ((a.s * b.y) - (a.x * b.z) + (a.y * b.s) + (a.z * b.x));
	x->z = ((a.s * b.z) + (a.x * b.y) - (a.y * b.x) + (a.z * b.s));
}
void        quater_div(quater_t* x, const quater_t a, const quater_t b) {
	/*raQuaternion temp = q;
	(* this) *= raQuaternionInvert(temp);
    return *this;*/
	quater_t inv; inv.s = b.s; inv.x = b.x; inv.y =b.y; inv.z = b.z;

	quater_invert(&inv);
	quater_mul(x, a, inv);
}
void quater_div_f(quater_t* x, const quater_t a, const float b) { 
	quater_set(x, a.s / b, 
				  a.x / b, 
				  a.y / b, 
				  a.z / b
			  );
}
void quater_add_f(quater_t* x, const quater_t a, const float b) { 
	quater_set(x, a.s + b, 
				  a.x + b, 
				  a.y + b, 
				  a.z + b
			  );
}
void quater_sub_f(quater_t* x, const quater_t a, const float b) { 
	quater_set(x, a.s - b, 
				  a.x - b, 
				  a.y - b, 
				  a.z - b
			  );
}
void        quater_div_fr(quater_t* x, const float a, const quater_t b) {
	quater_set(x, a / b.s, 
				  a / b.x, 
				  a / b.y, 
				  a / b.z
			  );
}
void        quater_sub_fr(quater_t* x, const float a, const quater_t b) {
	quater_set(x, a - b.s, 
				  a - b.x, 
				  a - b.y, 
				  a - b.z
			  );
}
void        quater_mul_f(quater_t* x, const quater_t a, const float b) {
	x->s = a.s * b;
	x->x = a.x * b;
	x->y = a.y * b;
	x->z = a.z * b;
}
void        quater_add(quater_t* x, const quater_t a, const quater_t b) {
	x->s = a.s + b.s;
	x->x = a.x + b.x;
	x->y = a.y + b.y;
	x->z = a.z + b.z;
}
void        quater_sub(quater_t* x, const quater_t a, const quater_t b) {
	x->s = a.s - b.s;
	x->x = a.x - b.x;
	x->y = a.y - b.y;
	x->z = a.z - b.z;
}

int         quater_equel(const quater_t a, const quater_t b) {
	return ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.s == b.s)) ? 0 : -1;
}
int         quater_inequel(const quater_t a, const quater_t b) {
	return ((a.x != b.x) && (a.y != b.y) && (a.z != b.z) && (a.s != b.s)) ? 0 : -1;
}
int         quater_less_equel(const quater_t a, const quater_t b) {
	return ((a.x <= b.x) && (a.y <= b.y) && (a.z <= b.z) && (a.s <= b.s)) ? 0 : -1;
}
int         quater_greater_equel(const quater_t a, const quater_t b) {
	return ((a.x >= b.x) && (a.y >= b.y) && (a.z >= b.z) && (a.s >= b.s)) ? 0 : -1;
}
int         quater_less(const quater_t a, const quater_t b) {
	return ((a.x < b.x) && (a.y < b.y) && (a.z < b.z) && (a.s < b.s)) ? 0 : -1;
}
int         quater_greater(const quater_t a, const quater_t b) {
	return ((a.x > b.x) && (a.y > b.y) && (a.z > b.z) && (a.s > b.s)) ? 0 : -1;
}

void  quater_normalize(quater_t* x, const quater_t q) {
    register float norme = quater_lenght(q);

    if (norme == 0.0) {
		quater_identy(x);
	} else {
		float recip = 1.0f/norme;

		x->s    = q.s * recip;
		x->x  = q.x * recip;
		x->y  = q.y * recip;
		x->z  = q.z * recip;
	}
}
void quater_identy(quater_t* q) { 
    if(!q) return;
    
    q->x = 0.0f;
    q->y = 0.0f;
    q->z = 0.0f;

    q->s = 1.0f;
}
float quater_lenght(const quater_t q) {
    return sqrtf(q.s * q.s + q.x * q.x + q.y * q.y + q.z * q.z); 
}
float quater_lenght_sq(const quater_t q) {
    return (q.s * q.s + q.x * q.x + q.y * q.y + q.z * q.z);
}

void  qquater_conjugate(quater_t* q) {
    if(!q) return;
    q->s = -q->s;
	q->x = -q->x;
    q->y = -q->y;
    q->z = -q->z;
}

void quater_get_rotation_axis(const quater_t* q, vec3_t* pOut) {
	if(!q || !pOut) return;

	float sinThetaOver2Sq = 1.0f - q->s*q->s;

    if (sinThetaOver2Sq <= 0.0f) {
		pOut->x = 1.0f;
		pOut->y = 0.0f;
		pOut->z = 0.0f;

		return;
    }

    // Compute 1 / sin(theta/2)

    float   oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Sq);

    // Return axis of rotation
	pOut->x = q->x * oneOverSinThetaOver2;
	pOut->y = q->y * oneOverSinThetaOver2;
    pOut->z = q->z * oneOverSinThetaOver2;
}
void quater_get_rotation_angle(const quater_t* q, float* pOut) {
	if(!q || !pOut) return;

	float thetaOver2 = acos(q->s);
    *pOut = thetaOver2 * 2.0f;
}

void        quater_exp(const quater_t* q, quater_t* pOut) {
	if(!q || !pOut) return;

	float vlength = (q->x * q->x + q->y * q->y  + q->z * q->z );
	float mul = (vlength > 1.0e-4) ? ( sinf(vlength)/vlength ) : 1.0f;

	pOut->s = cos(vlength);

	pOut->x = q->x * mul;
	pOut->y = q->y * mul;
	pOut->z = q->z * mul;
}
void        quater_log(const quater_t* q, quater_t* pOut) {
	if(!q || !pOut) return;


	float vlength = (q->x * q->x + q->y * q->y  + q->z * q->z );
	vlength = atanf(vlength/q->s);

	pOut->s = 0.0;
	pOut->x = q->x * vlength;
	pOut->y = q->y * vlength;
	pOut->z = q->z * vlength;

}
void quater_pow(const quater_t* q, float exp, quater_t* pOut) {
	if(!q || !pOut) return;

	if (fabsf(q->s) > .9999f) {
        pOut->s = q->s;
		pOut->x = q->x;
		pOut->y = q->y;
		pOut->z = q->z;
		return ;
    }
	// Erhalte halbe angle alpha (alpha = theta/2)
    float   alpha = acosf(q->s);

    // Berechne neuen alpha Wert
    float   newAlpha = alpha * exp;

    // Berechne neuen s wert
    pOut->s = cosf(newAlpha);

    // Berechne neue xyz Werte

    float   mult = sinf(newAlpha) / sinf(alpha);
    pOut->x = q->x * mult;
    pOut->y = q->y * mult;
    pOut->z = q->z * mult;
}

float       quater_dot(const quater_t a, const quater_t b) {
	return a.s*b.s + a.x*b.x + a.y*b.y + a.z*b.z;
}

void quater_invert(quater_t* q) {
	if(!q ) return;

	float temp = quater_lenght_sq(*q);

	q->s = q->s / temp;
	q->x = q->x /-temp;
	q->y = q->y /-temp;
	q->z = q->z /-temp;
}

void quater_power(const quater_t* q, float degree, quater_t* pOut) {
	int i = 0;
	if ( degree == 0 ) {
		quater_set(pOut, 1.0f, 0.0f,0.0f, 0.0f); 
		return;
	}
	pOut->s = q->s;
	pOut->x = q->x;
	pOut->y = q->y;
	pOut->z = q->z;

	while( (i < abs(degree)) ) {

		pOut->s *= q->s;
		pOut->x *= q->x;
		pOut->y *= q->y;
		pOut->z *= q->z;

		i++;
	}
	if ( degree < 0 )  {
		pOut->s = q->s;
		pOut->x = q->x;
		pOut->y = q->y;
		pOut->z = q->z;

		quater_div_fr(pOut, 1.0f, *pOut);
	} 
}
void quater_sin(const quater_t* q, quater_t* pOut) {
	quater_t qpower, qmul, qdiv;

	for( float n = 0; n < 6.0f; n++ ) {
		quater_power( q , 2.0f * n + 1.0f, &qpower); 

		//s += powf( -1.0f ,n ) * (quater_power( q , 2.0f * n + 1.0f ) ) / ( factf( 2.0f * n + 1.0f ) );

		quater_mul_f(&qmul, qpower, powf( -1.0f, n )); // qmul = powf( -1.0f ,n ) * (quater_power( q , 2.0f * n + 1.0f ) )
		quater_div_f(&qdiv, qmul,   factf( 2.0f * n + 1.0f ) ); // qdiv = qmul / ( factf( 2.0f * n + 1.0f )
		quater_add(pOut, *pOut, qdiv);
	}
}
void quater_cos(const quater_t* q, quater_t* pOut) {
	quater_t qpower, qmul, qdiv;

	for( float n = 1.0f; n <= 6.0f; n++ ) {
		//s += pow( -1.0f ,n ) * raQuaternionPower( q , 2.0f * n ) / factf( 2.0f * n ) ;

		quater_power( q , 2.0f * n, &qpower); 

		quater_mul_f(&qmul, qpower, powf( -1.0f, n ) ); // qmul = powf( -1.0f ,n ) * (quater_power( q , 2.0f * n + 1.0f ) )
		quater_div_f(&qdiv, qmul,   factf( 2.0f * n) ); // qdiv = qmul / ( factf( 2.0f * n + 1.0f )
		quater_add(pOut, *pOut, qdiv);
	}
}
void quater_tan(const quater_t* q, quater_t* pOut)
{
	if ( quater_lenght_sq(*q) == 0.0 ) {
		quater_set(pOut, 1.0f, 0.0f, 0.0f,	0.0f);
		return;
	} 

	quater_t qsin, qcos;

	quater_sin(q, &qsin);
	quater_cos(q, &qcos);

	quater_div(pOut, qsin, qcos);
	
}
void quater_ctan(const quater_t* q, quater_t* pOut) {
	if ( quater_lenght_sq(*q) == 0.0 ) {
		quater_set(pOut, 1.0f, 0.0f, 0.0f,	0.0f);
		return;
	} 

	quater_t qsin, qcos;

	quater_sin(q, &qsin);
	quater_cos(q, &qcos);

	quater_div(pOut, qcos, qsin);
}

void quater_interpolate_linear(quater_t* pOut, const quater_t a, const quater_t b, const float e)
{
    if (e <= 0.0f) {
		pOut->s = a.s;
		pOut->x = a.x;
		pOut->y = a.y;
		pOut->z = a.z;
	} else if (e >= 1.0f) {
		pOut->s = b.s;
		pOut->x = b.x;
		pOut->y = b.y;
		pOut->z = b.z;
	} else {

		float cosOmega = quater_dot(a, b);

		float bw = b.s;
		float bx = b.x;
		float by = b.y;
		float bz = b.z;

		if (cosOmega < 0.0f) {
			bw = -bw;
			bx = -bx;
			by = -by;
			bz = -bz;
			cosOmega = -cosOmega;
		}

		assert(cosOmega < 1.1f);

		// Compute interpolation fraction, checking for quaternions
		// almost exactly the same

		float k0, k1;
		if (cosOmega > 0.9999f) {
			k0 = 1.0f-e;
			k1 = e;
		} else {
			// Compute the sin of the angle using the
			// trig identity sin^2(omega) + cos^2(omega) = 1

			float sinOmega = sqrtf(1.0f - cosOmega*cosOmega);

			// Compute the angle from its sin and cosine

			float omega = atan2f(sinOmega, cosOmega);

			// Compute inverse of denominator, so we only have
			// to divide once

			float oneOverSinOmega = 1.0f / sinOmega;

			// Compute interpolation parameters

			k0 = sinf((1.0f - e) * omega) * oneOverSinOmega;
			k1 = sinf(e * omega) * oneOverSinOmega;
		}

		pOut->x = k0 * a.x + k1 * bx;
		pOut->y = k0 * a.y + k1 * by;
		pOut->z = k0 * a.z + k1 * bz;
		pOut->s = k0 * a.s + k1 * bw;
	}
}

