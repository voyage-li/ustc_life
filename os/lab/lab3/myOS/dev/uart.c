#include "uart.h"
#include "io.h"

#define UART_PORT 0x3F8 // 串口端口号

/* 向串口输出一个字符
 * 使用封装好的 outb 函数 */
void uart_put_char(unsigned char ch)
{
    /* todo */
    outb(UART_PORT, ch);
}

/* 向串口输出一个字符串
 * 此函数接口禁止修改 */
void uart_put_chars(char *str)
{
    /* todo */
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        uart_put_char(*(str + i));
}
