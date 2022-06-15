#ifndef _KLIBC_IOB_H_
#define _KLIBC_IOB_H_

#include "private/port.h"

#define IO_OUTB(PORT, VAL)              port_outb(PORT, VAL)
#define IO_OUTI(PORT, VAL)              port_outi(PORT, VAL)
#define IO_OUTD(PORT, VAL)              port_outd(PORT, VAL)
#define IO_OUTW(PORT, VAL)              port_outw(PORT, VAL)
#define IO_OUTL(PORT, VAL)              port_outl(PORT, VAL)
#define IO_OUTSB(PORT, DATA, COUNT)     port_outsb(PORT, DATA, COUNT)
#define IO_OUTSW(PORT, DATA, COUNT)     port_outsw(PORT, DATA, COUNT)
#define IO_OUTSDW(PORT, DATA, COUNT)    port_outsdw(PORT, DATA, COUNT)

#define IO_INB(PORT)                    port_inb(PORT)
#define IO_INI(PORT)                    port_ini(PORT)
#define IO_IND(PORT)                    port_ind(PORT)
#define IO_INW(PORT)                    port_inw(PORT)
#define IO_INL(PORT)                    port_inl(PORT)
#define IO_INSB(PORT, DATA, COUNT)      port_insb(PORT, DATA, COUNT)
#define IO_INSW(PORT, DATA, COUNT)      port_insw(PORT, DATA, COUNT)
#define IO_INSDW(PORT, DATA, COUNT)     port_insdw(PORT, DATA, COUNT)


#define IO_WAIT                         port_io_wait()
#define IO_DELAY(C)                     port_iodelay(C)

#define IO_INTR_ENABLE                  port_intr_enable()
#define IO_INTR_DISABLE                 port_intr_disable()
#define IO_HALT                         port_halt(); for(;;) 

#endif