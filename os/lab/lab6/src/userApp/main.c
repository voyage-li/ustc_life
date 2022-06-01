#include "../myOS/userInterface.h" //interface from kernel

#include "../myOS/include/scheduler.h"
#include "../myOS/include/task.h"
#include "../myOS/include/tick.h"
#include "FCFSTestCase.h"
#include "PRIOTestCase.h"
// #include "RRTestCase.h"
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

void init_time(void)
{
    setWallClock(00, 00, 00); // set time 18:59:59
    append2HookList(wallClock_hook_main);
}

void shell()
{
    myPrintf(0xb, "*********************************\n");
    myPrintf(0xb, "*        schedule task3         *\n");
    myPrintf(0xb, "*      this is shell task       *\n");
    myPrintf(0xb, "*********************************\n");
    initShell();
    memTestCaseInit();
    startShell();
}

void test1()
{
    myPrintf(0x1, "*********************************\n");
    myPrintf(0x1, "*        schedule task1         *\n");
    myPrintf(0x1, "*      this is test1 task       *\n");
    myPrintf(0x1, "*********************************\n");
}
void test2()
{
    myPrintf(0x5, "*********************************\n");
    myPrintf(0x5, "*        schedule task2         *\n");
    myPrintf(0x5, "*      this is test2 task       *\n");
    myPrintf(0x5, "*********************************\n");
}

void myMain(void)
{
    init_time();
    extern int shell_start_flag;
    myPrintf(0x6, "*********************************\n");
    myPrintf(0x6, "*        schedule task0         *\n");
    myPrintf(0x6, "*      this is mymain task      *\n");
    myPrintf(0x6, "*********************************\n");
    if (shell_start_flag)
    {
        int test1_tid = createTsk(test1);
        setTskPara(PRIORITY, 3, TCB[test1_tid]->para);
        int test2_tid = createTsk(test2);
        setTskPara(PRIORITY, 2, TCB[test2_tid]->para);
        int shell_tid = createTsk(shell);
        setTskPara(PRIORITY, 1, TCB[shell_tid]->para);
        tskStart(TCB[test1_tid]);
        tskStart(TCB[test2_tid]);
        tskStart(TCB[shell_tid]);
    }
    else
    {
        heap_init_arrv();
        if (sch.type == FCFS)
        {
            FCFS_TEST();
        }
        else if (sch.type == PRIO)
        {
            PRIO_TEST();
        }
        // else if (sch.type == RR)
        // {
        //     RR_TEST();
        // }
    }
}