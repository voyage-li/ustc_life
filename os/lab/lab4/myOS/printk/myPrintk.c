#define KERNEL     // needed by vsprintf.c
#include "types.h" //needed by vsprintf.c
#include "vsprintf.c"

#include "../include/uart.h"
#include "../include/vga.h"

// extern void getTimeStamp(unsigned char *buffer);
// char timestamp[20];

char buf[400]; // TODO: fix me
int myPrintk(int color, const char *format, ...)
{
    va_list args;
    int n;

    // getTimeStamp(timestamp);
    // append2screen(timestamp,color);
    // uart_put_chars(timestamp);

    va_start(args, format);
    n = vsprintf(buf, format, args);
    // if (n>400) while(1);
    append2screen(buf, color);
    uart_put_chars(buf);
    va_end(args);

    return n;
}

char user_buf[400]; // TODO: fix me
int myPrintf(int color, const char *format, ...)
{
    va_list args;
    int n;

    va_start(args, format);
    n = vsprintf(user_buf, format, args);
    // if (n>400) while(1);
    append2screen(user_buf, color);
    uart_put_chars(user_buf);
    va_end(args);

    return n;
}

char vga_Buf[400];
int myPrintk_only_vga(int color, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = vsprintf(vga_Buf, format, args);
    va_end(args);
    append2screen(vga_Buf, color);
    return count;
}

void clear_the_screen()
{
    clear_screen();
}