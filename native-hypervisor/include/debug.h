#ifndef __DEBUG_H_
#define __DEBUG_H_

#include <types.h>

/* COM ports related data */
#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8
#define DEBUG_PORT COM3

/* debug.c constants */
#define BUFF_MAX_SIZE 0x700

/* Debug levels related data */
#define DEBUG_LVL_DEBUG 3
#define DEBUG_LVL_WARNING 2
#define DEBUG_LVL_INFO 1
#define DEBUG_LVL DEBUG_LVL_DEBUG

// #define DEBUG_ADDRESS_TRANSLATION
// #define DEBUG_EPT_TRANSLATION
// #define DEBUG_XSETBV
// #define DEBUG_KPP_COMMANDS
// #define DEBUG_ALL_VM_EXIT
// #define DEBUG_HANDLE_TRANSLATION_FAILURE

VOID DbgPrintBuffer(IN PCHAR buffer, IN QWORD length);
VOID DbgPrintNullTerminatedBuffer(IN PCHAR buffer);
VOID DbgPrint(IN PCHAR fmt, ...);
VOID DbgPrintDebugLevelDebug(IN PCHAR fmt, ...);
VOID DbgPrintDebugLevelWarning(IN PCHAR fmt, ...);
VOID DbgPrintDebugLevelInfo(IN PCHAR fmt, ...);

#define Print DbgPrint
#define PrintDebugLevelDebug DbgPrintDebugLevelDebug

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define NOP if(TRUE) 5;

#define ASSERT(condition) \
        do \
        { \
            if(!(condition)) \
            { \
                Print("\n\n\nASSERTION FAILED AT: " STR(__FILE__) ", line: " STR(__LINE__) ", condition: [[[ " STR(condition) " ]]]" "\n\n\n"); \
                for(;;); \
            } \
        } while(FALSE)


#endif