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



void uuid4_from_raw(const int8_t uuid[UUID_SIZE], uuid_t* out) {
    uint32_t		tmp;
    const uint8_t *ptr = uuid;

    tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	tmp = (tmp << 8) | *ptr++;
	tmp = (tmp << 8) | *ptr++;
	out->time_low = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	out->time_mid = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	out->time_hi_and_version = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	out->clock_seq = tmp;

	memcpy(out->node, ptr, 6);
	memcpy(out->raw_uuid, uuid, UUID_SIZE);
    
}

void uuid4_to_raw(uuid_t* uu, uint8_t ptr[UUID_SIZE]) {
    uint32_t	tmp;
	unsigned char	*out = ptr;

	tmp = uu->time_low;
	out[3] = (unsigned char) tmp; tmp >>= 8;
	out[2] = (unsigned char) tmp; tmp >>= 8;
	out[1] = (unsigned char) tmp; tmp >>= 8;
	out[0] = (unsigned char) tmp;

	out[5] = (unsigned char) uu->time_mid;
	out[4] = (unsigned char) uu->time_mid >> 8;
	
	out[7] = (unsigned char) uu->time_hi_and_version;
	out[6] = (unsigned char) uu->time_hi_and_version >> 8;

	out[9] = (unsigned char) uu->clock_seq;
	out[8] = (unsigned char) uu->clock_seq >> 8;

	memcpy(out+10, uu->node, 6);
}


void  uuid4_generate(uuid_t* uuid, uint32_t seed) {
    uint8_t   buf[16];

    srand(seed);
    const int8_t* pbuf = rand_chars(buf, 16);

    uuid4_from_raw(pbuf, uuid);

    uuid->clock_seq = (uuid->clock_seq & 0x3FFF) | 0x8000;
    uuid->time_hi_and_version = (uuid->time_hi_and_version & 0x0FFF) | 0x4000;

    uuid4_to_raw(uuid, uuid->raw_uuid);
}

void  uuid4_nil(uuid_t* nil) {
    nil->time_low = 0;
    nil->time_mid = 0;
    nil->time_hi_and_version = 0;
    nil->clock_seq = 0;
    nil->node[0] =  0;
    nil->node[1] =  0;
    nil->node[2] =  0;
    nil->node[3] =  0;
    nil->node[4] =  0;
    nil->node[5] =  0;
    
    for(char i = 0; i < UUID_SIZE; i++)
        nil->raw_uuid[i] = 0;
}

void     uuid4_clear(uuid_t* uuid) {
    uuid4_nil(uuid);
}

int uuid4_is_nil(const uuid_t uuid) {
    int ret = 0;

    for(char i = 0; i < UUID_SIZE; i++ ) {
        if(uuid.raw_uuid[i] != 0) { ret = -1; break; }
    }

    return ret;
}



string_t uuid4_string(char* buffer, uuid_t uuid, uint8_t upper) {
    char* fmt ;
    
    if(upper) {
        fmt = "%08X-%04X-%02X%02X-%02X%02X-%02X%02X%02X%02X%02X%02X";
    }  else {
        fmt = "%08x-%04x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x";
    }
    sprintf(buffer, fmt, uuid.time_low, 
                         uuid.time_mid, 
                         uuid.version, uuid.time_hi,
                         uuid.clock_seq_low, uuid.clock_seq_high ,
                         uuid.node[0],
                         uuid.node[1],
                         uuid.node[2],
                         uuid.node[3],
                         uuid.node[4],
                         uuid.node[5]
            );
		
    return buffer;
}
