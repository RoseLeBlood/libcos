#include <typeconv.h>
#include <string.h>


/** Convert a bcd to binary */
unsigned char bcd2bin(unsigned char bcd)
{
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}