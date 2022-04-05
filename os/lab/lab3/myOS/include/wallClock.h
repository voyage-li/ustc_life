#ifndef __WALLCLOCK_H__
#define __WALLCLOCK_H__

#include "vga.h"

void setWallClock(int HH, int MM, int SS);
void getWallClock(int *HH, int *MM, int *SS);

#endif
