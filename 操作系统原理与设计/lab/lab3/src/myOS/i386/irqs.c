#include "myPrintk.h"
void ignoreIntBody(void)
{
    char time_str[19] = "Unknown interrupt";

    unsigned short int *p;
    unsigned short int pos = 80 * 24;
    unsigned short int data;
    unsigned short int base = 0xc << 8;
    p = (unsigned short int *)(0xB8000 + pos * 2);
    for (int i = 0; i < 19; i++)
    {
        data = base + time_str[i];
        *p = data;
        p += 1;
    }
}
