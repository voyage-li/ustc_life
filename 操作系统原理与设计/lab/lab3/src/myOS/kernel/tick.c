#include "wallClock.h"
int system_ticks;
int HH, MM, SS;

void tick(void)
{
    system_ticks++;
    //你需要填写这里
    int temp = system_ticks / 100;
    HH = temp / (60 * 60);
    MM = temp / 60 - HH * 60;
    SS = temp % 60;
    oneTickUpdateWallClock(HH, MM, SS);
    return;
}
