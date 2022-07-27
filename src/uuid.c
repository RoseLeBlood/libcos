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
#include "uuid.h"
#include "stdlib.h"
#include "string.h"

struct _private_uuid {
	uint32_t	first;
	uint16_t	sec;
	uint16_t	ver;
	uint16_t	clock;
	uint8_t	    node[6];
};

uint8_t* uuid_generate(uuid_t uuid) {
    uuid_t	                buf;
	struct _private_uuid    uu;
    uint32_t	            tmp;

    const int8_t* pbuf = rand_bytes(buf, 16);

    tmp = *pbuf++;
    tmp = (tmp << 8) | *pbuf++;
    tmp = (tmp << 8) | *pbuf++;
    uu.first = (tmp << 8) | *pbuf++;

    uu.sec = *pbuf++; tmp = (tmp << 8) | *pbuf++;
    uu.ver = *pbuf++; tmp = (tmp << 8) | *pbuf++;
    uu.clock = *pbuf++; tmp = (tmp << 8) | *pbuf++;

    memcpy(uu.node, pbuf, 6);

    uu.clock = (uu.clock & 0x3FFF) | 0x8000;
    uu.ver = (uu.ver & 0x0FFF) | 0x4000;

    tmp = uu.first;
    uuid[3] = (uint8_t) tmp; tmp >>= 8;
    uuid[2] = (uint8_t) tmp; tmp >>= 8;
    uuid[1] = (uint8_t) tmp; tmp >>= 8;
    uuid[0] = (uint8_t) tmp;

    tmp = uu.sec;
    uuid[5] = (uint8_t) tmp; tmp >>= 8;
    uuid[4] = (uint8_t) tmp;

    tmp = uu.ver;
    uuid[7] = (uint8_t) tmp; tmp >>= 8;
    uuid[6] = (uint8_t) tmp;

    tmp = uu.clock;
    uuid[9] = (uint8_t) tmp; tmp >>= 8;
    uuid[8] = (uint8_t) tmp;

    memcpy(uuid + 10, uu.node, 6);

    uuid += 16;

    return uuid;
}

int uuid_is_nil(const uuid_t uu) {
    int ret = 0;

    for(char i = 0; i < UUID_SIZE; i++ ) {
        if(uu[i] != 0) {  ret = -1; break;}
    }

    return ret;
}
