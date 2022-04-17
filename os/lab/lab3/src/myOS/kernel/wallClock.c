#include "wallClock.h"

void (*wallClock_hook)(int, int, int) = 0;
void oneTickUpdateWallClock(int HH, int MM, int SS)
{
    if (wallClock_hook)
        wallClock_hook(HH, MM, SS);
}

void setWallClockHook(void (*func)(int, int, int))
{
    wallClock_hook = func;
}

void setWallClock(int HH, int MM, int SS)
{
    //你需要填写它
    char time_str[9];
    time_str[0] = '0' + HH / 10;
    time_str[1] = '0' + HH % 10;
    time_str[2] = ':';
    time_str[3] = '0' + MM / 10;
    time_str[4] = '0' + MM % 10;
    time_str[5] = ':';
    time_str[6] = '0' + SS / 10;
    time_str[7] = '0' + SS % 10;
    time_str[8] = '\0';

    unsigned short int *p;
    unsigned short int pos = 80 * 25 - 8;
    unsigned short int data;
    unsigned short int base = 0x2 << 8;
    p = (unsigned short int *)(VGA_BASE + pos * 2);
    for (int i = 0; i < 9; i++)
    {
        data = base + time_str[i];
        *p = data;
        p += 1;
    }
    return;
}

void getWallClock(int *HH, int *MM, int *SS)
{
    //你需要填写它
    unsigned short int *p;
    unsigned short int pos = 80 * 25 - 8;
    p = (unsigned short int *)(VGA_BASE + pos * 2);

    char c = (*p) & 0xff;
    *HH = (c - '0') * 10;
    p += 2;
    c = (*p) & 0xff;
    *HH += (c - '0');

    p += 2 * 2;
    c = (*p) & 0xff;
    *MM = (c - '0') * 10;
    p += 2;
    c = (*p) & 0xff;
    *MM += (c - '0');

    p += 2 * 2;
    c = (*p) & 0xff;
    *SS = (c - '0') * 10;
    p += 2;
    c = (*p) & 0xff;
    *SS += (c - '0');
    return;
}
