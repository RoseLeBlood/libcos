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
#include <wctype.h>
#include <string.h>

#define WCTYPE_ALNUM  1
#define WCTYPE_ALPHA  2
#define WCTYPE_BLANK  3
#define WCTYPE_CNTRL  4
#define WCTYPE_DIGIT  5
#define WCTYPE_GRAPH  6
#define WCTYPE_LOWER  7
#define WCTYPE_PRINT  8
#define WCTYPE_PUNCT  9
#define WCTYPE_SPACE  10
#define WCTYPE_UPPER  11
#define WCTYPE_XDIGIT 12
#define CASEMAP(u1,u2,l) { (u1), (l)-(u1), (u2)-(u1)+1 }
#define CASELACE(u1,u2) CASEMAP((u1),(u2),(u1)+1)

static const struct {
        unsigned short upper;
        signed char lower;
        unsigned char len;
} casemaps[] = {
        CASEMAP('A','Z','a'),
        CASEMAP(0xc0,0xde,0xe0),

        CASELACE(0x0100,0x012e),
        CASELACE(0x0132,0x0136),
        CASELACE(0x0139,0x0147),
        CASELACE(0x014a,0x0176),
        CASELACE(0x0179,0x017d),

        CASELACE(0x370,0x372),
        CASEMAP(0x391,0x3a1,0x3b1),
        CASEMAP(0x3a3,0x3ab,0x3c3),
        CASEMAP(0x400,0x40f,0x450),
        CASEMAP(0x410,0x42f,0x430),

        CASELACE(0x460,0x480),
        CASELACE(0x48a,0x4be),
        CASELACE(0x4c1,0x4cd),
        CASELACE(0x4d0,0x50e),

        CASELACE(0x514,0x526),
        CASEMAP(0x531,0x556,0x561),

        CASELACE(0x01a0,0x01a4),
        CASELACE(0x01b3,0x01b5),
        CASELACE(0x01cd,0x01db),
        CASELACE(0x01de,0x01ee),
        CASELACE(0x01f8,0x021e),
        CASELACE(0x0222,0x0232),
        CASELACE(0x03d8,0x03ee),

        CASELACE(0x1e00,0x1e94),
        CASELACE(0x1ea0,0x1efe),

        CASEMAP(0x1f08,0x1f0f,0x1f00),
        CASEMAP(0x1f18,0x1f1d,0x1f10),
        CASEMAP(0x1f28,0x1f2f,0x1f20),
        CASEMAP(0x1f38,0x1f3f,0x1f30),
        CASEMAP(0x1f48,0x1f4d,0x1f40),

        CASEMAP(0x1f68,0x1f6f,0x1f60),
        CASEMAP(0x1f88,0x1f8f,0x1f80),
        CASEMAP(0x1f98,0x1f9f,0x1f90),
        CASEMAP(0x1fa8,0x1faf,0x1fa0),
        CASEMAP(0x1fb8,0x1fb9,0x1fb0),
        CASEMAP(0x1fba,0x1fbb,0x1f70),
        CASEMAP(0x1fc8,0x1fcb,0x1f72),
        CASEMAP(0x1fd8,0x1fd9,0x1fd0),
        CASEMAP(0x1fda,0x1fdb,0x1f76),
        CASEMAP(0x1fe8,0x1fe9,0x1fe0),
        CASEMAP(0x1fea,0x1feb,0x1f7a),
        CASEMAP(0x1ff8,0x1ff9,0x1f78),
        CASEMAP(0x1ffa,0x1ffb,0x1f7c),

        CASELACE(0x246,0x24e),
        CASELACE(0x510,0x512),
        CASEMAP(0x2160,0x216f,0x2170),
        CASEMAP(0x2c00,0x2c2e,0x2c30),
        CASELACE(0x2c67,0x2c6b),
        CASELACE(0x2c80,0x2ce2),
        CASELACE(0x2ceb,0x2ced),

        CASELACE(0xa640,0xa66c),
        CASELACE(0xa680,0xa696),

        CASELACE(0xa722,0xa72e),
        CASELACE(0xa732,0xa76e),
        CASELACE(0xa779,0xa77b),
        CASELACE(0xa77e,0xa786),

        CASELACE(0xa790,0xa792),
        CASELACE(0xa7a0,0xa7a8),

        CASEMAP(0xff21,0xff3a,0xff41),
        { 0,0,0 }
};

static const unsigned short pairs[][2] = {
        { 'I',    0x0131 },
        { 'S',    0x017f },
        { 0x0130, 'i'    },
        { 0x0178, 0x00ff },
        { 0x0181, 0x0253 },
        { 0x0182, 0x0183 },
        { 0x0184, 0x0185 },
        { 0x0186, 0x0254 },
        { 0x0187, 0x0188 },
        { 0x0189, 0x0256 },
        { 0x018a, 0x0257 },
        { 0x018b, 0x018c },
        { 0x018e, 0x01dd },
        { 0x018f, 0x0259 },
        { 0x0190, 0x025b },
        { 0x0191, 0x0192 },
        { 0x0193, 0x0260 },
        { 0x0194, 0x0263 },
        { 0x0196, 0x0269 },
        { 0x0197, 0x0268 },
        { 0x0198, 0x0199 },
        { 0x019c, 0x026f },
        { 0x019d, 0x0272 },
        { 0x019f, 0x0275 },
        { 0x01a6, 0x0280 },
        { 0x01a7, 0x01a8 },
        { 0x01a9, 0x0283 },
        { 0x01ac, 0x01ad },
        { 0x01ae, 0x0288 },
        { 0x01af, 0x01b0 },
        { 0x01b1, 0x028a },
        { 0x01b2, 0x028b },
        { 0x01b7, 0x0292 },
        { 0x01b8, 0x01b9 },
        { 0x01bc, 0x01bd },
        { 0x01c4, 0x01c6 },
        { 0x01c4, 0x01c5 },
        { 0x01c5, 0x01c6 },
        { 0x01c7, 0x01c9 },
        { 0x01c7, 0x01c8 },
        { 0x01c8, 0x01c9 },
        { 0x01ca, 0x01cc },
        { 0x01ca, 0x01cb },
        { 0x01cb, 0x01cc },
        { 0x01f1, 0x01f3 },
        { 0x01f1, 0x01f2 },
        { 0x01f2, 0x01f3 },
        { 0x01f4, 0x01f5 },
        { 0x01f6, 0x0195 },
        { 0x01f7, 0x01bf },
        { 0x0220, 0x019e },
        { 0x0386, 0x03ac },
        { 0x0388, 0x03ad },
        { 0x0389, 0x03ae },
        { 0x038a, 0x03af },
        { 0x038c, 0x03cc },
        { 0x038e, 0x03cd },
        { 0x038f, 0x03ce },
        { 0x0399, 0x0345 },
        { 0x0399, 0x1fbe },
        { 0x03a3, 0x03c2 },
        { 0x03f7, 0x03f8 },
        { 0x03fa, 0x03fb },
        { 0x1e60, 0x1e9b },
        { 0xdf, 0xdf },
        { 0x1e9e, 0xdf },

        { 0x1f59, 0x1f51 },
        { 0x1f5b, 0x1f53 },
        { 0x1f5d, 0x1f55 },
        { 0x1f5f, 0x1f57 },
        { 0x1fbc, 0x1fb3 },
        { 0x1fcc, 0x1fc3 },
        { 0x1fec, 0x1fe5 },
        { 0x1ffc, 0x1ff3 },

        { 0x23a, 0x2c65 },
        { 0x23b, 0x23c },
        { 0x23d, 0x19a },
        { 0x23e, 0x2c66 },
        { 0x241, 0x242 },
        { 0x243, 0x180 },
        { 0x244, 0x289 },
        { 0x245, 0x28c },
        { 0x3f4, 0x3b8 },
        { 0x3f9, 0x3f2 },
        { 0x3fd, 0x37b },
        { 0x3fe, 0x37c },
        { 0x3ff, 0x37d },
        { 0x4c0, 0x4cf },

        { 0x2126, 0x3c9 },
        { 0x212a, 'k' },
        { 0x212b, 0xe5 },
        { 0x2132, 0x214e },
        { 0x2183, 0x2184 },
        { 0x2c60, 0x2c61 },
        { 0x2c62, 0x26b },
        { 0x2c63, 0x1d7d },
        { 0x2c64, 0x27d },
        { 0x2c6d, 0x251 },
        { 0x2c6e, 0x271 },
        { 0x2c6f, 0x250 },
        { 0x2c70, 0x252 },
        { 0x2c72, 0x2c73 },
        { 0x2c75, 0x2c76 },
        { 0x2c7e, 0x23f },
        { 0x2c7f, 0x240 },
        { 0x2cf2, 0x2cf3 },

        { 0xa77d, 0x1d79 },
        { 0xa78b, 0xa78c },
        { 0xa78d, 0x265 },
        { 0xa7aa, 0x266 },

        { 0x10c7, 0x2d27 },
        { 0x10cd, 0x2d2d },

        /* bogus greek 'symbol' letters */
        { 0x376, 0x377 },
        { 0x39c, 0xb5 },
        { 0x392, 0x3d0 },
        { 0x398, 0x3d1 },
        { 0x3a6, 0x3d5 },
        { 0x3a0, 0x3d6 },
        { 0x39a, 0x3f0 },
        { 0x3a1, 0x3f1 },
        { 0x395, 0x3f5 },
        { 0x3cf, 0x3d7 },

        { 0,0 }
};
static const unsigned char table[] = 
{
	18,17,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,17,34,35,36,17,37,38,39,40,
	41,42,43,44,17,45,46,47,16,16,48,16,16,16,16,16,16,16,49,50,51,16,52,53,16,16,
	17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,54,
	17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
	17,17,17,55,17,17,17,17,56,17,57,58,59,60,61,62,17,17,17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,
	17,17,17,17,17,17,17,63,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,17,64,65,17,66,67,68,69,70,71,72,
	73,16,16,16,74,75,76,77,78,16,16,16,79,80,16,16,16,16,81,16,16,16,16,16,16,16,
	16,16,17,17,17,82,83,16,16,16,16,16,16,16,16,16,16,16,17,17,17,17,84,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,17,17,85,16,
	16,16,16,86,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,87,16,16,16,16,16,16,16,16,16,
	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	88,89,90,91,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
	92,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,0,0,0,0,0,0,0,0,254,255,255,7,254,255,255,7,0,0,0,0,0,4,32,4,
	255,255,127,255,255,255,127,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,195,255,3,0,31,80,0,0,0,0,
	0,0,0,0,0,0,32,0,0,0,0,0,223,60,64,215,255,255,251,255,255,255,255,255,255,
	255,255,255,191,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,3,252,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,0,254,255,255,255,127,2,254,255,255,255,255,0,0,0,0,0,255,191,182,
	0,255,255,255,7,7,0,0,0,255,7,255,255,255,255,255,255,255,254,255,195,255,255,
	255,255,255,255,255,255,255,255,255,255,239,31,254,225,255,159,0,0,255,255,
	255,255,255,255,0,224,255,255,255,255,255,255,255,255,255,255,255,255,3,0,255,
	255,255,255,255,7,48,4,255,255,255,252,255,31,0,0,255,255,255,1,0,0,0,0,0,0,0,
	0,253,31,0,0,0,0,0,0,240,3,255,127,255,255,255,255,255,255,255,239,255,223,
	225,255,207,255,254,254,238,159,249,255,255,253,197,227,159,89,128,176,207,
	255,3,0,238,135,249,255,255,253,109,195,135,25,2,94,192,255,63,0,238,191,251,
	255,255,253,237,227,191,27,1,0,207,255,0,0,238,159,249,255,255,253,237,227,
	159,25,192,176,207,255,2,0,236,199,61,214,24,199,255,195,199,29,129,0,192,255,
	0,0,238,223,253,255,255,253,239,227,223,29,96,3,207,255,0,0,236,223,253,255,
	255,253,239,227,223,29,96,64,207,255,6,0,236,223,253,255,255,255,255,231,223,
	93,128,0,207,255,0,252,236,255,127,252,255,255,251,47,127,128,95,255,0,0,12,0,
	254,255,255,255,255,127,255,7,63,32,255,3,0,0,0,0,150,37,240,254,174,236,255,
	59,95,32,255,243,0,0,0,0,1,0,0,0,255,3,0,0,255,254,255,255,255,31,254,255,3,
	255,255,254,255,255,255,31,0,0,0,0,0,0,0,0,255,255,255,255,255,255,127,249,
	255,3,255,255,231,193,255,255,127,64,255,51,255,255,255,255,191,32,255,255,
	255,255,255,247,255,255,255,255,255,255,255,255,255,61,127,61,255,255,255,255,
	255,61,255,255,255,255,61,127,61,255,127,255,255,255,255,255,255,255,61,255,
	255,255,255,255,255,255,255,135,0,0,0,0,255,255,0,0,255,255,255,255,255,255,
	255,255,255,255,31,0,254,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,159,255,255,254,255,255,7,255,
	255,255,255,255,255,255,255,255,199,1,0,255,223,15,0,255,255,15,0,255,255,15,
	0,255,223,13,0,255,255,255,255,255,255,207,255,255,1,128,16,255,3,0,0,0,0,255,
	3,255,255,255,255,255,255,255,255,255,255,255,0,255,255,255,255,255,7,255,255,
	255,255,255,255,255,255,63,0,255,255,255,31,255,15,255,1,192,255,255,255,255,
	63,31,0,255,255,255,255,255,15,255,255,255,3,255,3,0,0,0,0,255,255,255,15,255,
	255,255,255,255,255,255,127,254,255,31,0,255,3,255,3,128,0,0,0,0,0,0,0,0,0,0,
	0,255,255,255,255,255,255,239,255,239,15,255,3,0,0,0,0,255,255,255,255,255,
	243,255,255,255,255,255,255,191,255,3,0,255,255,255,255,255,255,63,0,255,227,
	255,255,255,255,255,63,0,0,0,0,0,0,0,0,0,0,0,0,0,222,111,0,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,0,0,0,0,0,0,0,0,255,255,63,63,255,255,255,255,63,63,255,170,255,255,255,
	63,255,255,255,255,255,255,223,95,220,31,207,15,255,31,220,31,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,2,128,0,0,255,31,0,0,0,0,0,0,0,0,0,0,0,0,132,252,47,62,80,189,255,
	243,224,67,0,0,255,255,255,255,255,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,255,255,255,255,255,255,3,0,0,255,255,255,
	255,255,127,255,255,255,255,255,127,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,31,120,12,0,255,255,255,255,191,32,255,255,255,255,
	255,255,255,128,0,0,255,255,127,0,127,127,127,127,127,127,127,127,255,255,255,
	255,0,0,0,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,0,0,
	0,254,3,62,31,254,255,255,255,255,255,255,255,255,255,127,224,254,255,255,255,
	255,255,255,255,255,255,255,247,224,255,255,255,255,63,254,255,255,255,255,
	255,255,255,255,255,255,127,0,0,255,255,255,7,0,0,0,0,0,0,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	63,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,31,0,0,0,0,0,0,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,31,0,0,0,0,0,0,0,0,255,
	255,255,255,255,63,255,31,255,255,255,15,0,0,255,255,255,255,255,127,240,143,
	255,255,255,128,255,255,255,255,255,255,255,255,255,255,0,0,0,0,128,255,252,
	255,255,255,255,255,255,255,255,255,255,255,255,121,15,0,255,7,0,0,0,0,0,0,0,
	0,0,255,187,247,255,255,255,0,0,0,255,255,255,255,255,255,15,0,255,255,255,
	255,255,255,255,255,15,0,255,3,0,0,252,8,255,255,255,255,255,7,255,255,255,
	255,7,0,255,255,255,31,255,255,255,255,255,255,247,255,0,128,255,3,0,0,0,0,
	255,255,255,255,255,255,127,0,255,63,255,3,255,255,127,4,255,255,255,255,255,
	255,255,127,5,0,0,56,255,255,60,0,126,126,126,0,127,127,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,255,255,255,255,255,7,255,3,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,15,0,255,255,127,248,255,255,255,
	255,255,15,255,255,255,255,255,255,255,255,255,255,255,255,255,63,255,255,255,
	255,255,255,255,255,255,255,255,255,255,3,0,0,0,0,127,0,248,224,255,253,127,
	95,219,255,255,255,255,255,255,255,255,255,255,255,255,255,3,0,0,0,248,255,
	255,255,255,255,255,255,255,255,255,255,255,63,0,0,255,255,255,255,255,255,
	255,255,252,255,255,255,255,255,255,0,0,0,0,0,255,15,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,223,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,31,0,
	0,255,3,254,255,255,7,254,255,255,7,192,255,255,255,255,255,255,255,255,255,
	255,127,252,252,252,28,0,0,0,0,255,239,255,255,127,255,255,183,255,63,255,63,
	0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,7,0,0,0,0,
	0,0,0,0,255,255,255,255,255,255,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,31,255,255,255,255,255,255,1,0,0,0,0,0,
	255,255,255,127,0,0,255,255,255,7,0,0,0,0,0,0,255,255,255,63,255,255,255,255,
	15,255,62,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,63,255,3,0,0,0,0,0,0,0,0,0,0,63,253,255,255,255,255,191,
	145,255,255,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,63,0,255,255,
	255,3,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,192,0,0,0,0,0,0,0,0,111,240,
	239,254,255,255,15,0,0,0,0,0,255,255,255,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	255,255,255,255,255,255,63,0,255,255,63,0,255,255,7,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,255,255,255,255,255,255,255,255,255,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,255,255,255,255,255,255,255,255,63,0,0,0,192,255,0,0,252,255,255,
	255,255,255,255,1,0,0,255,255,255,1,255,3,255,255,255,255,255,255,199,255,0,0,
	0,0,0,0,0,0,255,255,255,255,255,255,255,255,30,0,255,3,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,63,0,255,3,0,0,0,0,0,0,255,255,255,
	255,255,255,255,255,255,255,255,255,255,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,255,255,255,255,255,255,255,255,255,255,255,255,7,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,255,255,255,255,255,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,255,255,255,255,255,255,255,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,255,255,255,255,255,255,255,255,31,0,255,255,255,255,255,127,0,0,
	248,255,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,223,255,255,255,255,
	255,255,255,255,223,100,222,255,235,239,255,255,255,255,255,255,255,191,231,
	223,223,255,255,255,123,95,252,253,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
	255,255,255,255,255,255,255,255,255,255,255,255,63,255,255,255,253,255,255,
	247,255,255,255,247,255,255,223,255,255,255,223,255,255,127,255,255,255,127,
	255,255,255,253,255,255,255,253,255,255,247,207,255,255,255,255,255,255,239,
	255,255,255,150,254,247,10,132,234,150,170,150,247,247,94,255,251,255,15,238,
	251,255,15,0,0,0,0,0,0,0,0,
};
static const unsigned char ptable[] = 
{
18,16,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,16,16,34,35,16,36,37,38,39,
40,41,42,43,16,44,45,46,17,47,48,17,17,49,17,17,17,50,51,52,53,54,55,56,57,17,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,58,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,59,16,60,61,62,63,64,65,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,66,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,67,16,16,68,16,69,70,71,16,72,16,73,
16,16,16,16,74,75,76,77,16,16,78,16,79,80,16,16,16,16,81,16,16,16,16,16,16,16,
16,16,16,16,16,16,82,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,83,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,84,85,86,87,
16,16,88,89,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
90,16,91,92,93,94,95,96,97,98,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,0,0,0,0,254,255,0,252,1,0,0,248,1,0,0,120,0,0,0,0,255,251,223,
251,0,0,128,0,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,0,
252,255,224,175,255,255,255,255,255,255,255,255,255,255,223,255,255,255,255,
255,32,64,176,0,0,0,0,0,0,0,0,0,0,0,0,0,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
252,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,252,0,0,0,0,0,134,254,
255,255,255,0,64,73,0,0,0,0,0,24,0,223,255,0,200,0,0,0,0,0,0,0,1,0,60,0,0,0,0,
0,0,0,0,0,0,0,0,16,224,1,30,0,96,255,191,0,0,0,0,0,0,255,7,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,248,207,3,0,0,0,3,0,32,255,127,0,0,0,78,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,252,0,0,0,0,0,0,0,0,0,16,0,32,30,0,48,0,1,0,0,0,0,0,0,0,0,16,
0,32,0,0,0,0,252,15,0,0,0,0,0,0,0,16,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,32,0,
0,0,0,3,0,0,0,0,0,0,0,0,16,0,32,0,0,0,0,253,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,
255,7,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,255,0,0,0,0,0,0,0,16,0,32,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,32,0,0,0,0,63,2,0,0,0,0,0,0,0,0,0,4,0,0,0,0,16,0,0,0,0,0,0,
128,0,128,192,223,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,254,255,255,
255,0,252,255,255,0,0,0,0,0,0,0,0,252,0,0,0,0,0,0,192,255,223,255,7,0,0,0,0,0,
0,0,0,0,0,128,6,0,252,0,0,24,62,0,0,128,191,0,204,0,0,0,0,0,0,0,0,0,0,0,8,0,0,
0,0,0,0,0,0,0,0,0,96,255,255,255,31,0,0,255,3,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,96,0,0,1,0,0,24,0,0,0,0,0,0,0,0,0,56,0,0,0,0,16,0,0,0,112,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,48,0,0,254,127,47,0,0,255,3,255,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,49,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,196,255,255,255,255,0,0,0,192,0,0,0,0,0,0,0,0,1,0,224,159,0,0,0,0,
127,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,16,0,0,252,255,255,255,31,0,0,0,0,
0,12,0,0,0,0,0,0,64,0,12,240,0,0,0,0,0,0,192,248,0,0,0,0,0,0,0,192,0,0,0,0,0,
0,0,0,255,0,255,255,255,33,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,255,255,255,255,127,0,0,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
160,3,224,0,224,0,224,0,96,128,248,255,255,255,252,255,255,255,255,255,127,31,
252,241,127,255,127,0,0,255,255,255,3,0,0,255,255,255,255,1,0,123,3,208,193,
175,66,0,12,31,188,255,255,0,0,0,0,0,2,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,15,0,255,255,
255,255,127,0,0,0,255,7,0,0,255,255,255,255,255,255,255,255,255,255,63,0,0,0,
0,0,0,252,255,255,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,31,255,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,135,3,254,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,1,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,
127,255,15,0,0,0,0,0,0,0,0,255,255,255,251,255,255,255,255,255,255,255,255,
255,255,15,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,63,0,0,0,255,15,30,255,255,255,1,252,
193,224,0,0,0,0,0,0,0,0,0,0,0,30,1,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,255,255,0,0,0,0,255,255,255,255,15,0,0,0,255,255,255,127,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,
255,255,255,255,127,0,0,0,0,0,0,192,0,224,0,0,0,0,0,0,0,0,0,0,0,128,15,112,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,255,0,255,255,127,0,3,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,68,8,0,0,0,15,255,3,0,0,0,0,0,0,240,0,0,0,0,0,0,0,0,0,
16,192,0,0,255,255,3,7,0,0,0,0,0,248,0,0,0,0,8,128,0,0,0,0,0,0,0,0,0,0,8,0,
255,63,0,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,240,0,0,128,11,0,0,0,0,0,0,0,128,2,
0,0,192,0,0,67,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,56,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,0,0,0,0,0,2,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,252,255,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,48,255,255,255,3,127,0,255,255,255,255,247,
255,127,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,254,255,0,252,1,0,0,248,1,0,
0,248,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,127,0,48,135,255,255,255,255,255,
143,255,0,0,0,0,0,0,224,255,255,7,255,15,0,0,0,0,0,0,255,255,255,255,255,63,0,
0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,128,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,143,0,0,0,128,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,255,0,255,1,
0,0,0,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,255,0,0,0,
255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,127,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,63,252,255,63,0,0,0,3,0,0,0,
0,0,0,254,3,0,0,0,0,0,0,0,0,0,0,0,0,0,24,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
225,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,192,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,7,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,63,0,255,255,255,255,127,254,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,63,0,0,0,0,
255,255,255,255,255,255,255,255,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,255,255,255,255,255,255,255,255,255,255,127,0,255,255,3,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,8,0,0,0,
8,0,0,32,0,0,0,32,0,0,128,0,0,0,128,0,0,0,2,0,0,0,2,0,0,8,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,255,255,255,255,255,
15,255,255,255,255,255,255,255,255,255,255,255,255,15,0,255,127,254,127,254,
255,254,255,0,0,0,0,255,7,255,255,255,127,255,255,255,255,255,255,255,15,255,
255,255,255,255,7,0,0,0,0,0,0,0,0,192,255,255,255,7,0,255,255,255,255,255,7,
255,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,1,0,191,255,
255,255,255,255,255,255,255,31,255,255,15,0,255,255,255,255,223,7,0,0,255,255,
1,0,255,255,255,255,255,255,255,127,253,255,255,255,255,255,255,255,255,255,
255,255,255,255,255,255,255,255,255,255,255,255,255,30,255,255,255,255,255,
255,255,63,15,0,255,255,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,248,255,255,
255,255,255,255,255,255,225,255,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
63,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,15,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
int iswalnum(wint_t wc )
{
	 return iswdigit(wc) || iswalpha(wc);
}
int iswalpha(wint_t wc)
{
	if (wc<0x20000U)
     	return (table[table[wc>>8]*32+((wc&255)>>3)]>>(wc&7))&1;
    if (wc<0x2fffeU)
      	return 1;
    return 0;
}
int iswblank(wint_t wc)
{
	 return (wc == ' ' || wc == '\t');
}
int iswcntrl(wint_t wc)
{
	return (unsigned)wc < 32
            || (unsigned)(wc-0x7f) < 33
            || (unsigned)(wc-0x2028) < 2
            || (unsigned)(wc-0xfff9) < 3;
}
int iswdigit(wint_t wc)
{
	return (unsigned)wc-'0' < 10;
}
int iswgraph(wint_t wc)
{
	return !iswspace(wc) && iswprint(wc);
}
int iswlower(wint_t wc)
{
	return towupper(wc) != wc || wc == 0xdf;
}
int iswprint(wint_t wc)
{
	if (wc < 0xffU)
       	return ((wc+1) & 0x7f) >= 0x21;
    if (wc < 0x2028U || wc-0x202aU < 0xd800-0x202a || wc-0xe000U < 0xfff9-0xe000)
   		return 1;
    if (wc-0xfffcU > 0x10ffff-0xfffc || (wc&0xfffe)==0xfffe)
    	return 0;
    return 1;
}
int iswpunct(wint_t wc)
{
	if (wc<0x20000U)
  		return (ptable[table[wc>>8]*32+((wc&255)>>3)]>>(wc&7))&1;
   	return 0;
}
int iswspace(wint_t wc)
{
    static const wchar_t spaces[] = 
    {
            ' ', '\t', '\n', '\r', 11, 12,  0x0085,
            0x2000, 0x2001, 0x2002, 0x2003, 0x2004, 0x2005,
            0x2006, 0x2008, 0x2009, 0x200a,
            0x2028, 0x2029, 0x205f, 0x3000, 0
    };
    if (wcschr(spaces, wc)) return 1;
    return 0;
}
int iswupper(wint_t wc)
{
	 return towlower(wc) != wc;
}
int iswxdigit(wint_t wc)
{
	return (unsigned)(wc-'0') < 10 || (unsigned)((wc|32)-'a') < 6;
}
wctrans_t wctrans(const char *class)
{
        if (!strcmp(class, "toupper")) return (wctrans_t)1;
        if (!strcmp(class, "tolower")) return (wctrans_t)2;
        return 0;
}

wint_t towctrans(wint_t wc, wctrans_t trans)
{
        if (trans == (wctrans_t)1) return towupper(wc);
        if (trans == (wctrans_t)2) return towlower(wc);
        return wc;
}
int iswctype(wint_t wc, wctype_t type) {
        int _type_int = (int)type;

        switch (_type_int) {
        case WCTYPE_ALNUM:
                return iswalnum(wc);
        case WCTYPE_ALPHA:
                return iswalpha(wc);
        case WCTYPE_BLANK:
                return iswblank(wc);
        case WCTYPE_CNTRL:
                return iswcntrl(wc);
        case WCTYPE_DIGIT:
                return iswdigit(wc);
        case WCTYPE_GRAPH:
                return iswgraph(wc);
        case WCTYPE_LOWER:
                return iswlower(wc);
        case WCTYPE_PRINT:
                return iswprint(wc);
        case WCTYPE_PUNCT:
                return iswpunct(wc);
        case WCTYPE_SPACE:
                return iswspace(wc);
        case WCTYPE_UPPER:
                return iswupper(wc);
        case WCTYPE_XDIGIT:
                return iswxdigit(wc);
        }
        return 0;
}

wctype_t wctype(const char * s) 
{
	wctype_t i;
    const char *p;

    static const char names[] =
            "alnum\0" "alpha\0" "blank\0"
            "cntrl\0" "digit\0" "graph\0"
            "lower\0" "print\0" "punct\0"
            "space\0" "upper\0" "xdigit";
    for (i=(wctype_t)1, p=names; *p; i++, p+=6)
            if (*s == *p && !strcmp(s, p))
                    return i;
    return 0;
}



static wchar_t __towcase(wchar_t wc, int lower)
{
        int i;
        int lmul = 2*lower-1;
        int lmask = lower-1;

        if (!iswalpha(wc)
         || (unsigned)wc - 0x0600 <= 0x0fff-0x0600
         || (unsigned)wc - 0x2e00 <= 0xa63f-0x2e00
         || (unsigned)wc - 0xa800 <= 0xfeff-0xa800)
                return wc;
                
        if (lower && (unsigned)wc - 0x10a0 < 0x2e) 
        {
                if (wc>0x10c5 && wc != 0x10c7 && wc != 0x10cd) return wc;
                else return wc + 0x2d00 - 0x10a0;
        }
        if (!lower && (unsigned)wc - 0x2d00 < 0x26) 
        {
                if (wc>0x2d25 && wc != 0x2d27 && wc != 0x2d2d) return wc;
                else return wc + 0x10a0 - 0x2d00;
        }
        for (i=0; casemaps[i].len; i++) 
        {
                int base = casemaps[i].upper + (lmask & casemaps[i].lower);
                if ((unsigned)wc-base < casemaps[i].len)
                {
                        if (casemaps[i].lower == 1)
                                return wc + lower - ((wc-casemaps[i].upper)&1);
                        return wc + lmul*casemaps[i].lower;
                }
        }
        for (i=0; pairs[i][1-lower]; i++) 
        {
                if (pairs[i][1-lower] == wc)
                        return pairs[i][lower];
        }
        if ((unsigned)wc - (0x10428 - 0x28*lower) < 0x28)
                return wc - 0x28 + 0x50*lower;
        return wc;
}



wchar_t  towlower(wchar_t wc)
{
	 return __towcase(wc, 0);
}

wchar_t  towupper(wchar_t wc)
{
	return __towcase(wc, 1);
}