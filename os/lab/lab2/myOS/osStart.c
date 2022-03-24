#include "myPrintk.h"
#include "vga.h"

/* 此文件无需修改 */

// 用户程序入口
void myMain(void);

void osStart(void)
{
    clear_screen();
    myPrintk(0x2, "Starting the OS...\n");
    myMain();
    // extern unsigned long _end;
    // unsigned long _end_addr = (unsigned long)&_end;
    // myPrintk(0x2, "_end: %d\n", _end_addr);
    myPrintk(0x2, "Stop running... shutdown\n");
    while (1)
        ;
}
