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
#include <sys/utsname.h>
#include <string.h>
#include <stdio.h>
#include "private/port.h"
                               
int uname(struct utsname* os_infos)
{ 
  strcpy(os_infos->sysname, PORT_SYS_NAME);
  strcpy(os_infos->release, PORT_RELEASE_NAME);
  strcpy(os_infos->version, PORT_CC_VERSION);
  strcpy(os_infos->nodename, "");
  strcpy(os_infos->machine, PORT_MASCHINE_NAME);
  strcpy(os_infos->cmpversion, PORT_COMPILER_VERSION);
  strcpy(os_infos->cmpname, PORT_COMPILER_NAME);
  
  return 0;
}