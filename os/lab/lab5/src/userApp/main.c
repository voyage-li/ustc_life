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
    initShell();
    memTestCaseInit();
    startShell();
}

void myMain(void)
{
    int shell_tid = createTsk(shell);
    tskStart(TCB[shell_tid]);
}