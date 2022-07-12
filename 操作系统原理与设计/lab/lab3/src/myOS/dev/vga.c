#include "vga.h"
#include "io.h"
#include "uart.h"

#define VGA_BASE 0xB8000     // vga 显存起始地址
#define VGA_SCREEN_WIDTH 80  // vga 屏幕宽度（可容纳字符数）
#define VGA_SCREEN_HEIGHT 24 // vga 屏幕高度

#define CURSOR_LINE_REG 0xE     // 行号寄存器
#define CURSOR_COL_REG 0xF      // 列号寄存器
#define CURSOR_INDEX_PORT 0x3D4 // 光标行列索引端口号
#define CURSOR_DATA_PORT 0x3D5  // 光标数据端口号

/* ========= 以下函数仅供参考，可以根据自己的需求进行修改，甚至删除 ========= */

/* 将光标设定到特定位置
 * 提示：使用 outb */
void set_cursor_pos(unsigned short int pos)
{
    /* todo */
    unsigned char row = (pos & 0xff00) >> 8;
    unsigned char col = pos & 0xff;
    outb(CURSOR_INDEX_PORT, CURSOR_LINE_REG);
    outb(CURSOR_DATA_PORT, row);
    outb(CURSOR_INDEX_PORT, CURSOR_COL_REG);
    outb(CURSOR_DATA_PORT, col);
}

/* 获取光标当前所在位置
 * 提示：使用 inb */
unsigned short int get_cursor_pos(void)
{
    /* todo */
    unsigned short int pos = 0;
    unsigned short int row, col;
    outb(CURSOR_INDEX_PORT, CURSOR_LINE_REG);
    row = inb(CURSOR_DATA_PORT);
    outb(CURSOR_INDEX_PORT, CURSOR_COL_REG);
    col = inb(CURSOR_DATA_PORT);
    pos += col;
    pos += (row) << 8;
    return pos;
}

/* 滚屏，vga 屏幕满时使用。丢弃第一行内容，将剩余行整体向上滚动一行
 * 提示：使用指针修改显存 */
void scroll_screen(void)
{
    /* todo */
    for (int i = 0; i < VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH - VGA_SCREEN_WIDTH; i++)
    {
        unsigned short int *p, *q;
        p = (unsigned short int *)(i * 2 + VGA_BASE);
        q = (unsigned short int *)((i + 80) * 2 + VGA_BASE);
        *p = *q;
    }
    for (int i = VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH - VGA_SCREEN_WIDTH; i < VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH; i++)
    {
        unsigned short int *p;
        p = (unsigned short int *)(i * 2 + VGA_BASE);
        unsigned char blank = ' ';
        int color = 7;
        unsigned short int data = 0;
        data += color << 8;
        data += blank;
        *p = data;
    }
    set_cursor_pos(VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH - VGA_SCREEN_WIDTH);
}

/* 向 vga 的特定光标位置 pos 输出一个字符
 * 提示：使用指针修改显存 */
void put_char2pos(unsigned char c, int color, unsigned short int pos)
{
    /* todo */
    if (c == '\b')
    {
        set_cursor_pos(pos - 1);
    }
    else
    {

        unsigned short int data = 0;
        data += color << 8;
        data += c;
        unsigned short int *p;
        p = (unsigned short int *)(pos * 2 + VGA_BASE);
        *p = data;
        set_cursor_pos(pos + 1);
    }
}

/* ========= 以下函数接口禁止修改 ========= */

/* 清除屏幕上所有字符，并将光标位置重置到顶格
 * 提示：使用指针修改显存 */
void clear_screen(void)
{
    /* todo */
    for (int i = 0; i < VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH; i++)
    {
        unsigned short int *p;
        p = (unsigned short int *)(i * 2 + VGA_BASE);
        unsigned char blank = ' ';
        int color = 7;
        unsigned short int data = 0;
        data += color << 8;
        data += blank;
        *p = data;
    }
    set_cursor_pos(0);
}

/* 向 vga 的当前光标位置输出一个字符串，并移动光标位置到串末尾字符的下一位
 * 如果超出了屏幕范围，则需要滚屏
 * 需要能够处理转义字符 \n */

int strlen(char *str)
{
    int len = 0;
    while (*(str + len) != '\0')
        len++;
    return len;
}

void append2screen(char *str, int color)
{
    /* todo */
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        unsigned short int pos = get_cursor_pos();
        if (pos >= VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH)
        {
            scroll_screen();
            pos = get_cursor_pos();
        }
        if (*(str + i) == '\n')
            set_cursor_pos((pos / 80 + 1) * 80);
        else
            put_char2pos(*(str + i), color, pos);
    }
    unsigned short int pos = get_cursor_pos();
    if (pos >= VGA_SCREEN_HEIGHT * VGA_SCREEN_WIDTH)
        scroll_screen();
}