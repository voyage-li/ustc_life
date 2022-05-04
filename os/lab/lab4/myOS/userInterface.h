#ifndef __USERINTERFACE_H__
#define __USERINTERFACE_H__

// general for both kernel and userApp
#include "include/mem.h"
#include "include/string.h"
#include "include/uart.h"
#include "include/vga.h"
#include "include/vsprintf.h"
#include "include/wallClock.h"

// only for userApp
#include "include/malloc.h"

void clear_the_screen();
int myPrintf(int color, const char *format, ...);
int myPrintk_only_vga(int color, const char *format, ...);

#endif