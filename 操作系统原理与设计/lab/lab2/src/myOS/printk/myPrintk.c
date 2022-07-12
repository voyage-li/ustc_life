#include "uart.h"
#include "vga.h"
#include "vsprintf.h"

/* 内核 print 函数
 * 调用已经完成的 vga 和 串口 输出接口，补全此函数
 * 禁止修改此函数接口 */
char kBuf[400];
int myPrintk(int color, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    int cnt = vsprintf(kBuf, format, args);
    va_end(args);

    /* todo */

    uart_put_chars(kBuf);
    append2screen(kBuf, color);

    return cnt;
}

/* 用户 print 函数
 * 调用已经完成的 vga 和 串口 输出接口，补全此函数
 * 禁止修改此函数接口 */
char uBuf[400];
int myPrintf(int color, const char *format, ...)
{
    va_list args;

    va_start(args, format);
    int cnt = vsprintf(uBuf, format, args);
    va_end(args);

    /* todo */
    uart_put_chars(uBuf);
    append2screen(uBuf, color);

    return cnt;
}
