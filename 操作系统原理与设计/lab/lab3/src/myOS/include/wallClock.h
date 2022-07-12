#ifndef __WALLCLOCK_H__
#define __WALLCLOCK_H__

#include "vga.h"

void oneTickUpdateWallClock(int HH, int MM, int SS);
void setWallClockHook(void (*func)(int, int, int));
void setWallClock(int HH, int MM, int SS);
void getWallClock(int *HH, int *MM, int *SS);

#endif
