#include "../../include/task.h"
#include "../../include/kmalloc.h"
#include "../../include/myPrintk.h"
#include "../../include/scheduler.h"
#include "../../include/taskarrv.h"
#include "../../include/tick.h"

int prosess[100];
int last_prosess;
int now_pid;

void task_execute(unsigned int wait_time)
{
    while (currentTsk->run_time < getTskPara(EXETIME, currentTsk->para))
    {
    }
}

void stack_init(unsigned long **stk, void (*task)(void))
{
    *(*stk)-- = (unsigned long)tskEnd; // CS
    *(*stk)-- = (unsigned long)task;   // eip
    // pushf
    *(*stk)-- = (unsigned long)0x0202; // flag registers
    // pusha
    *(*stk)-- = (unsigned long)0xAAAAAAAA; // eax
    *(*stk)-- = (unsigned long)0xCCCCCCCC; // ecx
    *(*stk)-- = (unsigned long)0xDDDDDDDD; // edx
    *(*stk)-- = (unsigned long)0xBBBBBBBB; // ebx
    *(*stk)-- = (unsigned long)0x44444444; // esp
    *(*stk)-- = (unsigned long)0x55555555; // ebp
    *(*stk)-- = (unsigned long)0x66666666; // esi
    **stk = (unsigned long)0x77777777;     // edi
}

void context_switch(unsigned long **prevTskStkAddr, unsigned long *nextTskStk)
{
    prevTSK_StackPtrAddr = prevTskStkAddr;
    nextTSK_StackPtr = nextTskStk;
    CTX_SW();
}

int createTsk(void (*tskBody)(void))
{
    if (!firstFree)
        return -1;
    myTCB *newTsk = firstFree;
    firstFree = firstFree->next;

    newTsk->function = tskBody;
    newTsk->stack_max = (unsigned long *)kmalloc(STACK_SIZE);
    if (!newTsk->stack_max)
        return -1;
    newTsk->stack_top = newTsk->stack_max + STACK_SIZE - 1;
    initTskPara(&newTsk->para);
    stack_init(&newTsk->stack_top, tskBody);

    return newTsk->tid;
}
void destroyTsk(int tskIndex)
{
    kfree((unsigned long)TCB[tskIndex]->stack_max);
    kfree((unsigned long)TCB[tskIndex]->para);
    TCB[tskIndex]->status = BLANK;
    TCB[tskIndex]->stack_max = 0;
    TCB[tskIndex]->stack_top = 0;
    TCB[tskIndex]->run_time = 0;
    TCB[tskIndex]->this_time = 0;
    TCB[tskIndex]->function = NULL;
    TCB[tskIndex]->next = firstFree;
    TCB[tskIndex]->para = NULL;
    firstFree = TCB[tskIndex];
}
void tskStart(myTCB *tsk)
{
    //等待被执行
    tsk->status = WAITING;
    //进入队列
    sch.enqueueTsk_func(tsk);
}
void tskEnd()
{
    //上下文切换
    context_switch(&currentTsk->stack_top, BspContext);
}

void startMultitask(void)
{
    BspContextBase = (unsigned long *)kmalloc(10 * STACK_SIZE);
    BspContext = BspContextBase + STACK_SIZE - 1;
    currentTsk = NULL;
    sch.schedule();
}

void idleTskBody(void)
{

    myPrintk(0xa, "*********************************\n");
    myPrintk(0xa, "*          Idle task            *\n");
    myPrintk(0xa, "*     waiting for scheduler     *\n");
    myPrintk(0xa, "*********************************\n");
    myPrintk(0x7, "*********************************\n");
    myPrintk(0x7, "current order:\n");
    for (int i = 0; i < 100; i++)
    {
        if (prosess[i] == -1)
            break;
        else
            myPrintk(0x7, "%d", prosess[i]);
    }
    myPrintk(0x7, "\n");

    // while (1)
    //     sch.schedule();
}

void add_runntime()
{
    if (get_tick_times() % 100 != 0 || shell_start_flag)
        return;
    currentTsk->run_time++;
}

void print_info()
{
    if (get_tick_times() % 100 != 0 || shell_start_flag)
        return;

    if (currentTsk == idleTsk)
        return;

    if (currentTsk->tid != last_prosess)
    {
        prosess[now_pid++] = currentTsk->tid;
        last_prosess = currentTsk->tid;
    }
    myPrintk(0x7, "*********************************\n");
    myPrintk(0x7, "*  Current task tid : %-2d        *\n", currentTsk->tid);
    myPrintk(0x7, "*  Priority         : %-2d        *\n", getTskPara(PRIORITY, currentTsk->para));
    myPrintk(0x7, "*  Arrive time      : %-2d        *\n", getTskPara(ARRTIME, currentTsk->para));
    myPrintk(0x7, "*  Execute time     : %-2d / %2d   *\n", currentTsk->run_time, getTskPara(EXETIME, currentTsk->para));
    myPrintk(0x7, "*********************************\n");
}

void TaskManagerInit(void)
{
    myTCB *preTCB = NULL;
    for (int i = 0; i < TCBSIZE; i++)
    {
        TCB[i] = (myTCB *)kmalloc(sizeof(myTCB));
        TCB[i]->tid = i;
        TCB[i]->status = BLANK;
        TCB[i]->run_time = 0;
        TCB[i]->this_time = 0;
        TCB[i]->stack_max = NULL;
        TCB[i]->stack_top = NULL;
        TCB[i]->function = NULL;
        TCB[i]->next = NULL;
        if (preTCB)
            preTCB->next = TCB[i];
        preTCB = TCB[i];
    }

    last_prosess = 0;
    for (int i = 0; i < 100; i++)
        prosess[i] = -1;
    now_pid = 0;

    append2HookList(add_runntime);
    append2HookList(print_info);

    heap_init_arrv();

    init_sch();
    sch.schedulerInit_func();

    firstFree = TCB[0];
    int initTid = createTsk(initTskBody);
    tskStart(TCB[initTid]);

    startMultitask();
}

void initTskPara(tskPara **buffer)
{
    (*buffer) = (tskPara *)kmalloc(sizeof(tskPara));
    (*buffer)->priority = 0;
    (*buffer)->arrTime = 0;
    (*buffer)->exeTime = 0;
}
void setTskPara(unsigned int option, unsigned int value, tskPara *buffer)
{
    if (option == PRIORITY)
        buffer->priority = value;
    else if (option == ARRTIME)
        buffer->arrTime = value;
    else if (option == EXETIME)
        buffer->exeTime = value;
}
unsigned int getTskPara(unsigned int option, tskPara *para)
{
    if (option == PRIORITY)
        return para->priority;
    else if (option == ARRTIME)
        return para->arrTime;
    else if (option == EXETIME)
        return para->exeTime;
}
