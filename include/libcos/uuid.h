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
#ifndef KLIBCOS_UUID_H
#define KLIBCOS_UUID_H

#include "types.h"

#define UUID_SIZE  16

#define uuid4_string_upper(buffer, uuid) uuid4_string(buffer, uuid, 1)
#define uuid4_string_lower(buffer, uuid) uuid4_string(buffer, uuid, 0)

#ifdef __cplusplus
extern "C" {
#endif

typedef struct uuid_t {
    uint32_t time_low;
    uint16_t time_mid;

    union {
        struct  {
            uint8_t time_hi;
            uint8_t version;
        };
        uint16_t time_hi_and_version;
    };

    union {
        struct {
            uint8_t clock_seq_high;
            uint8_t clock_seq_low;
        };
        uint16_t clock_seq;
    };
    uint8_t node[6];

    uint8_t raw_uuid[UUID_SIZE];
}uuid_t;

/**
 * @brief Generate a version 4 UUID
 * 
 * @param uuid [out] contained the generated uuid 
 * @param seed [in] The random seed 
 */
void     uuid4_generate(uuid_t* uuid, uint32_t seed);
/**
 * @brief Create a uuid from a raw uuid array 
 * @param uuid The raw uuid array
 * @param out [out] contained the created uuid_t struct. 
 */
void     uuid4_from_raw(const int8_t uuid[UUID_SIZE], uuid_t* out);

/**
 * @brief Creates
 * 
 * @param nil 
 */
void     uuid4_nil(uuid_t* nil);
void     uuid4_clear(uuid_t* uuid);

string_t uuid4_string(char* buffer, uuid_t uuid, uint8_t upper);



#ifdef __cplusplus
}
#endif


#endif