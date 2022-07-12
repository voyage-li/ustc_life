#include "io.h"

void init8253(void)
{
    //你需要填写它
    unsigned short fre = 1193180 / 100;

    outb(0x43, 0x34);
    outb(0x40, (unsigned char)(fre & 0xff));
    outb(0x40, (unsigned char)((fre >> 8) & 0xff));

    outb(0x21, (unsigned char)(inb(0x21) & 0xfe));
}
