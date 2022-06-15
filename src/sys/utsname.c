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