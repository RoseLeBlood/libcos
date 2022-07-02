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
#include "libcos/stdlib.h"
#include "libcos/errno.h"
#include "private/port.h"

#define _ERRNO_ENTRIES_COUNT    16

struct ee 
{
        void*   stack;
        int             value;
} _errno_entries[_ERRNO_ENTRIES_COUNT];

int _errno_entries_oldest = 0;



int* _get_errno() 
{
        void* currentStack = port_get_curr_stack_pointer();

       // asm("mov %%esp, %0" : "=r"(currentStack));
        
        // now we search the table for a similar stack
        int i;
        for (i = 0; i < _ERRNO_ENTRIES_COUNT; i++) 
        {
                // two stacks are similar <=> diff less than 0x500
                if (abs(currentStack - _errno_entries[i].stack) < 0x500)
                        return &_errno_entries[i].value;
        }
        
        // there was no table entry, so we create one
        int* returnValue = &_errno_entries[_errno_entries_oldest].value;
        _errno_entries[_errno_entries_oldest].stack = currentStack;
        _errno_entries[_errno_entries_oldest].value = 0;
        _errno_entries_oldest++;
        _errno_entries_oldest %= _ERRNO_ENTRIES_COUNT;
        return returnValue;
}