#include "vsprintf.h"

/* 将 printf 格式串转化成可直接输出的字符串，存储在 buf 中
 * 可以移植或自编，自编至少需要支持 %d （建议移植）
 */

unsigned char hex_tab[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

int outc(const char c, char *buf, int index)
{
    *(buf + index) = c;
    index++;
    return index;
}

int outs(const char *s, char *buf, int index) //输出字符串
{
    while (*s != '\0')
    {
        *(buf + index) = *s;
        index++;
        s++;
    }
    return index;
}

int out_num(long n, int base, char lead, int maxwidth, char *buff, int index)
{
    unsigned long m = 0;
    char buf[500], *s = buf + sizeof(buf); // sizeof算结束符'\0' ，strlen不算
    int count = 0, i = 0;                  //注意这里s指向buf的末端，至于为什么继续往下看

    *--s = '\0'; //先--，在赋值结束符，因为sizeof算结束符在内的长度

    if (n < 0)
        m = -n; //如果是输出的是负数就取反
    else
        m = n;
    do
    {
        *--s = hex_tab[m % base];
        count++;
    } while ((m /= base) != 0); //将要打印的数字从个位开始一位一位存储在数组buf中，如果上面不是指向buf末端，
    if (n < 0)
        *--s = '-'; //负数的话加负号

    return outs(s, buff, index);
}

int vsprintf(char *buf, const char *fmt, va_list args)
{
    /* todo */
    char lead = ' '; // printf输出前导字符
    int maxwidth = 0;
    int index = 0;

    int argv = 0;

    for (; *fmt != '\0'; fmt++)
    {
        if (*fmt != '%')
        {
            *(buf + index) = *fmt;
            index++;
            continue;
        }

        fmt++;
        argv++;

        if (*fmt == '0') //前导字符是否是0
        {
            lead = '0';
            fmt++;
        }

        while (*fmt >= '0' && *fmt <= '9')
        { //输出的位宽
            maxwidth *= 10;
            maxwidth += (*fmt - '0');
            fmt++;
        }

        switch (*fmt)
        { //判断格式输出
        case 'd':
            index = out_num(va_arg(args, int), 10, lead, maxwidth, buf, index);
            break;
        case 'o':
            index = out_num(va_arg(args, unsigned int), 8, lead, maxwidth, buf, index);
            break;
        case 'u':
            index = out_num(va_arg(args, unsigned int), 10, lead, maxwidth, buf, index);
            break;
        case 'x':
            index = out_num(va_arg(args, unsigned int), 16, lead, maxwidth, buf, index);
            break;
        case 'c':
            index = outc(va_arg(args, int), buf, index);
            break;
        case 's':
            index = outs(va_arg(args, char *), buf, index);
            break;

        default:
            index = outc(*fmt, buf, index);
            break;
        }
    }
    *(buf + index) = '\0';
    return argv;
}
