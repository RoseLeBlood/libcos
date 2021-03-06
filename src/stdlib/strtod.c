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
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

#define ISINF(p) ((p[0] == 'i' || p[0] == 'I') && (p[1] == 'n' || p[1] == 'N')  && (p[2] == 'f' || p[2] == 'F'))

#define ISINFINITY(p) ((p[3] == 'i' || p[3] == 'I')  && (p[4] == 'n' || p[4] == 'N') && (p[5] == 'i' || p[5] == 'I') \
         && (p[6] == 't' || p[6] == 'T')  && (p[7] == 'y' || p[7] == 'Y'))

#define ISNAN(p)  ((p[0] == 'n' || p[0] == 'N') && (p[1] == 'a' || p[1] == 'A') && (p[2] == 'n' || p[2] == 'N')) 

double strtod  (const char* nptr, char** endptr) {
	if (nptr == 0) {
			return 0.0;
	}

	char *p = nptr;
	int _dot = 0;
	int _index = 1;

  	while (isspace (*p))  ++p;
  
  	if (*p == '+' || *p == '-') ++p;

  	if (ISINF(p)) {
		if(*endptr != 0) *endptr = p + 3; return atof (nptr);
    }

	if (ISINFINITY(p)) {
		if(*endptr != 0)*endptr = p + 8; return  atof (nptr);
	} 
 
  	if (ISNAN(p))  {
      	if(*endptr != 0)*endptr = p + 3; return  atof (nptr);
    }

  	if (isdigit (*p) || ispoint(*p)) {
      	
      	while (isdigit (*p) || (!_dot && ispoint(*p)))  {
          if (*p == '.')  _dot = 1; ++p;
        }

      	if (isexponent(*p))  {

          if (p[_index] == '+' || p[_index] == '-')  ++_index;
          if (isdigit (p[_index]))  {
            while (isdigit (p[_index])) ++_index;
              	if(*endptr != 0) *endptr = p + _index;
              	return atof (nptr);
            }
        }
      	if(*endptr != 0)*endptr = p;
      	return atof (nptr);
    }

  if(*endptr != 0)	strcpy(*endptr, nptr);
  	return 0.0;
}