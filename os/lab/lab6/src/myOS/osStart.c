#include "include/i8253.h"
#include "include/i8259.h"
#include "include/irq.h"
#include "include/mem.h"
#include "include/myPrintk.h"
#include "include/scheduler.h"
#include "include/task.h"
#include "include/uart.h"
#include "include/vga.h"

int shell_start_flag = 0;

void pressAnyKeyToStart(void)
{
    clear_screen();
    myPrintk(0x7, "\nPlease prepare your uart device\n");
    myPrintk(0x7, "\nThen, enter a number to choose the mode you want to enter\n");
    myPrintk(0x7, "\nNote: In scheduling algorithm testing mode, we will not start the shell\n\n");
    myPrintk(0x6, "[0] - FCFS scheduling test\n");
    myPrintk(0x5, "[1] - PRIO scheduling test\n");
    myPrintk(0x1, "[2] - SJF  scheduling test\n");
    myPrintk(0x3, "[3] - RR   scheduling test - time slice %d seconds\n", 2);
    myPrintk(0x2, "[4] - Shell\n", 3);

    unsigned char input;

    while (1)
    {
        input = uart_get_char();
        if (input <= '4' && input >= '0')
            break;
    }
    switch (input)
    {
    case '0':
        sch.type = FCFS;
        break;
    case '1':
        sch.type = PRIO;
        break;
    case '2':
        sch.type = SJF;
        break;
    case '3':
        sch.type = RR;
        break;
    case '4':
        sch.type = PRIO;
        shell_start_flag = 1;
        break;
    }
}

void osStart(void)
{
    pressAnyKeyToStart(); // prepare for uart device
    init8259A();
    init8253();
    enable_interrupt();

    clear_screen();

    pMemInit();

    myPrintk(0x2, "START RUNNING......\n");
    TaskManagerInit();

    myPrintk(0x2, "STOP RUNNING......ShutDown\n");
    while (1)
        ;
}
