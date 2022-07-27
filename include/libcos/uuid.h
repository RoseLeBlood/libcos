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

#ifdef __cplusplus
extern "C" {
#endif

typedef uint8_t uuid_t[16];

static const uuid_t UUID_NIL = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

uint8_t* uuid4_generate(uuid_t uuid, uint32_t seed);
int      uuid4_is_nil(const uuid_t uuid);;
void     uuid4_clear(uuid_t uuid);

const char* uuid4_string(char* buffer, uuid_t uuid, uint8_t upper);
const char* uuid4_string_upper(char* buffer, uuid_t uuid);
const char* uuid4_string_lower(char* buffer, uuid_t uuid);

#ifdef __cplusplus
}
#endif


#endif