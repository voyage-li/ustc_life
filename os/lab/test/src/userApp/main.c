#include "../myOS/userInterface.h" //interface from kernel

#include "../myOS/include/myPrintk.h"
#include "../myOS/include/task.h"
#include "memTestCase.h"
#include "shell.h"

void wallClock_hook_main(void)
{
    int _h, _m, _s;
    char hhmmss[] = "hh:mm:ss\0\0\0\0";

    getWallClock(&_h, &_m, &_s);
    sprintf(hhmmss, "%02d:%02d:%02d", _h, _m, _s);
    put_chars(hhmmss, 0x2, 24, 72);
}

void doSomeTestBefore(void)
{
    setWallClock(18, 59, 59); // set time 18:59:59
    setWallClockHook(&wallClock_hook_main);
}
void myTsk0(void)
{
    myPrintk(0x1, "*********************************\n");
    myPrintk(0x1, "*           New Task 0          *\n");
    myPrintk(0x1, "*          Hello World!         *\n");
    myPrintk(0x1, "*********************************\n");
}

void myTsk1(void)
{
    myPrintk(0x3, "*********************************\n");
    myPrintk(0x3, "*           New Task 1          *\n");
    myPrintk(0x3, "*          Hello World!         *\n");
    myPrintk(0x3, "*********************************\n");
}

void myTsk2(void)
{
    myPrintk(0x5, "*********************************\n");
    myPrintk(0x5, "*           New Task 2          *\n");
    myPrintk(0x5, "*          Hello World!         *\n");
    myPrintk(0x5, "*********************************\n");
}

void shell(void)
{
    myPrintk(0x2, "*********************************\n");
    myPrintk(0x2, "*           Shell Task          *\n");
    myPrintk(0x2, "*         Starting shell...     *\n");
    myPrintk(0x2, "*********************************\n");

    initShell();
    memTestCaseInit();
    startShell();
}

void myMain(void)
{
    int shellTid = createTsk(shell);
    int newTskTid0 = createTsk(myTsk0);
    int newTskTid1 = createTsk(myTsk1);
    int newTskTid2 = createTsk(myTsk2);
    tskStart(newTskTid0);
    tskStart(newTskTid1);
    tskStart(newTskTid2);
    tskStart(shellTid);
}
