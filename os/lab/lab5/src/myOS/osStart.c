#include "include/i8253.h"
#include "include/i8259.h"
#include "include/irq.h"
#include "include/mem.h"
#include "include/myPrintk.h"
#include "include/task.h"
#include "include/uart.h"
#include "include/vga.h"

void pressAnyKeyToStart(void)
{
    myPrintk(0x5, "Prepare uart device\n");
    myPrintk(0x5, "Then, press any key to start ...\n");

    uart_get_char();
}

void osStart(void)
{
    pressAnyKeyToStart(); // prepare for uart device
    init8259A();
    init8253();
    enable_interrupt();

    clear_screen();

    pMemInit(); // after this, we can use kmalloc/kfree and malloc/free
    // {
    //     dPartitionWalkByAddr(pMemHandler);
    //     unsigned long tmp = dPartitionAlloc(pMemHandler, 100);
    //     dPartitionWalkByAddr(pMemHandler);
    //     dPartitionFree(pMemHandler, tmp);
    //     dPartitionWalkByAddr(pMemHandler);
    // }

    myPrintk(0x2, "START RUNNING......\n");
    TaskManagerInit();

    myPrintk(0x2, "STOP RUNNING......ShutDown\n");
    while (1)
        ;
}
