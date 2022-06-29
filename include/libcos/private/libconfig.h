#ifndef __KLINCOS_LIBCONFIG_H__
#define __KLINCOS_LIBCONFIG_H__

#define KLIBCOS_TRUE                1
#define KLIBCOS_FALSE               0

#define KLIBCOS_NULTICORE_SYSTEM    KLIBCOS_TRUE


#define PRINT_BUF_LEN               12

#define SYS_CLK_MHZ                 (3000)
#define SYS_CLK_KHZ                 (SYS_CLK_MHZ * 1000)
#define SYS_CLK_HZ                  (SYS_CLK_KHZ * 1000)

#define PORT_SYS_NAME                "native"
#define PORT_RELEASE_NAME            ""
#define PORT_CC_VERSION              "1.0"
#define PORT_MASCHINE_NAME          "windows"
#define PORT_COMPILER_NAME          "gcc"
#define PORT_COMPILER_VERSION       "12"

//For task.h
#define TASK_NAME_MAX_LENGHT    32

#define TASK_STATE_NEW          0
#define TASK_STATE_READY        1
#define TASK_STATE_BLOCKED      2
#define TASK_STATE_SUSPEND      3
#define TASK_STATE_TERMINATED   4
#define TASK_STATE_UNKNOWN      5






#endif