#include "../myOS/userInterface.h" //interface from kernel

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

void shell()
{
    myPrintf(0xb, "***************************\n");
    myPrintf(0xb, "*   this is shell task    *\n");
    myPrintf(0xb, "***************************\n");
    doSomeTestBefore();
    initShell();
    memTestCaseInit();
    startShell();
}

void test1()
{
    myPrintf(0x1, "***************************\n");
    myPrintf(0x1, "*  this is test1 task     *\n");
    myPrintf(0x1, "***************************\n");
}
void test2()
{
    myPrintf(0x5, "***************************\n");
    myPrintf(0x5, "*  this is test2 task     *\n");
    myPrintf(0x5, "***************************\n");
}

void myMain(void)
{
    myPrintf(0x6, "***************************\n");
    myPrintf(0x6, "*  this is mymain task    *\n");
    myPrintf(0x6, "***************************\n");
    int test1_tid = createTsk(test1);
    int test2_tid = createTsk(test2);
    int shell_tid = createTsk(shell);
    tskStart(TCB[test1_tid]);
    tskStart(TCB[test2_tid]);
    tskStart(TCB[shell_tid]);
}