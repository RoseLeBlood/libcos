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
#ifndef	KLIBCOS_ASSERT_H
#define	KLIBCOS_ASSERT_H

#ifdef	__cplusplus
extern "C" {
#endif


#undef	assert

#ifdef	NDEBUG
	#define	assert(EX) ((void)0)
	#define pannic(msg) ((void)0)
#else
	void __assert(const char *, const char *, int);
	void __panic(const char *, const char *, int);
	
	#define assert(exp) ( (exp) ? (void) 0 : __assert(#exp, __FILE__, __LINE__))
	#define panic(msg) __panic(msg, __FILE__, __LINE__);
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* _ASSERT_H */