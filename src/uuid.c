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
#include "stdio.h"

uint8_t* uuid4_generate(uuid_t uuid, uint32_t seed) {
    uuid_t   buf;
    uint32_t tmp;
    uint32_t first;
    uint16_t sec;
    uint16_t ver;
    uint16_t clock;
    uint8_t node[6];

    srand(seed);
    const int8_t* pbuf = rand_chars(buf, 16);

    tmp = *pbuf++;
    tmp = (tmp << 8) | *pbuf++;
    tmp = (tmp << 8) | *pbuf++;
    first = (tmp << 8) | *pbuf++;

    sec = *pbuf++; tmp = (tmp << 8) | *pbuf++;
    ver = *pbuf++; tmp = (tmp << 8) | *pbuf++;
    clock = *pbuf++; tmp = (tmp << 8) | *pbuf++;
    memcpy(node, pbuf, 6);

    clock = (clock & 0x3FFF) | 0x8000;
    ver = (ver & 0x0FFF) | 0x4000;

    uuid[3] = (uint8_t) first; first >>= 8;
    uuid[2] = (uint8_t) first; first >>= 8;
    uuid[1] = (uint8_t) first; first >>= 8;
    uuid[0] = (uint8_t) first;
    uuid[5] = (uint8_t) sec; sec >>= 8;
    uuid[4] = (uint8_t) sec;
    uuid[7] = (uint8_t) ver; ver >>= 8;
    uuid[6] = (uint8_t) ver;
    uuid[9] = (uint8_t) clock; clock >>= 8;
    uuid[8] = (uint8_t) clock;
    memcpy(uuid + 10, node, 6);

    uuid += 16;

    return uuid;
}

int uuid4_is_nil(const uuid_t uuid) {
    int ret = 0;

    for(char i = 0; i < UUID_SIZE; i++ ) {
        if(uuid[i] != 0) { ret = -1; break; }
    }

    return ret;
}

void uuid4_clear(uuid_t uuid) {
    ZeroMemory(uuid, 16);
}
string_t uuid4_string_upper(char* buffer, uuid_t uuid)  {
    return uuid4_string(buffer, uuid, 1);
}

string_t uuid4_string_lower(char* buffer, uuid_t uuid) {
    return uuid4_string(buffer, uuid, 0);
}

string_t uuid4_string(char* buffer, uuid_t uuid, uint8_t upper) {

    const uint8_t	*ptr = uuid;

    uint32_t first;
    uint16_t sec;
    uint16_t ver;
    uint16_t clock;
    uint8_t node[6];

    char* fmt ;

    uint32_t tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	tmp = (tmp << 8) | *ptr++;
	tmp = (tmp << 8) | *ptr++;
	first = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	sec = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	ver = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	clock = tmp;

	memcpy(node, ptr, 6);
    
    
    if(upper) {
        fmt = "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X";
    }  else {
        fmt = "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x";
    }
    sprintf(buffer, fmt, first, sec, ver, clock >> 8, clock & 0xFF,
		node[0], node[1], node[2], node[3], node[4], node[5]);
		
    return buffer;
}