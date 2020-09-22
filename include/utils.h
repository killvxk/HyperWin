#ifndef __UTILS_H_
#define __UTILS_H_

#include <types.h>

#define ALIGN_UP(x, y) (((x) + ((x) % (y))))
#define ALIGN_DOWN(x, y) (((x) - ((x) % (y))))

#define INF (0xffffffffffffffffULL)
#define NEG_INF (-0xffff)

VOID CopyMemory(OUT QWORD_PTR dest, IN QWORD_PTR src, IN QWORD count);
CHAR ConvertHalfByteToHexChar(IN BYTE halfByte);
QWORD pow(IN QWORD base, IN QWORD power);
QWORD NumberOfDigits(IN QWORD number);
QWORD StringLength(IN PCHAR str);

#endif