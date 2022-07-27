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
#include <crypt/adler32.h>
#include <types.h>
#include <string.h>

#define BASE 65521
#define MAX  5552

uint32_t adler32ex (uint32_t initial,const char* data, uint32_t start, size_t length)
{
	uint32_t s1 = (uint32_t)(initial & 0xffff);
	uint32_t s2 = (uint32_t)((initial >> 16) & 0xffff);

	int index=start;
	int len = length;

	int k;
	while (len > 0)
	{
		k = (len < MAX) ? len : MAX;
		len -= k;

		for (uint32_t i=0; i < k; i++)
		{
			s1 += (uint32_t)(data[index++]);
			s2 += s1;
		}
		s1 %= BASE;
		s2 %= BASE;
	}

	return (int)((s2<<16) | s1);
}


uint32_t adler32 (uint32_t initial,const char* data, size_t length)
{
	if (data == NULL)
		return -1;
	
	return adler32ex(initial, data, 0, length);
}