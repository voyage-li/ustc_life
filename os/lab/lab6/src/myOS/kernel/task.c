#include "../include/task.h"
#include "../include/kmalloc.h"
#include "../include/myPrintk.h"
#include "../include/schedule.h"
#include "../include/taskQueueFIFO.h"

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

    stack_init(&newTsk->stack_top, tskBody);

    return newTsk->tid;
}
void destoryTsk(int tskIndex)
{
    kfree((unsigned long)TCB[tskIndex]->stack_max);
    TCB[tskIndex]->status = BLANK;
    TCB[tskIndex]->stack_max = NULL;
    TCB[tskIndex]->stack_top = NULL;
    TCB[tskIndex]->function = NULL;
    TCB[tskIndex]->next = firstFree;
    firstFree = TCB[tskIndex];
}
void tskStart(myTCB *tsk)
{
    //等待被执行
    tsk->status = WAITING;
    //进入队列
    tskenqueue(tsk);
}
void tskEnd()
{
    //释放
    tskdequeue();
    //上下文切换
    context_switch(&currentTsk->stack_top, BspContext);
}

void startMultitask(void)
{
    BspContextBase = (unsigned long *)kmalloc(10 * STACK_SIZE);
    BspContext = BspContextBase + STACK_SIZE - 1;
    currentTsk = NULL;
    while (1)
        schedule();
}

void idle(void)
{
    myPrintk(0xa, "*       waiting...        *\n");
    while (1)
        schedule();
}

void TaskManagerInit(void)
{
    myTCB *preTCB = NULL;
    for (int i = 0; i < TCBSIZE; i++)
    {
        TCB[i] = (myTCB *)kmalloc(sizeof(myTCB));
        TCB[i]->tid = i;
        TCB[i]->status = BLANK;
        TCB[i]->stack_max = NULL;
        TCB[i]->stack_top = NULL;
        TCB[i]->function = NULL;
        TCB[i]->next = NULL;
        if (preTCB)
            preTCB->next = TCB[i];
        preTCB = TCB[i];
    }

    fifo_init();

    firstFree = TCB[0];
    int initTid = createTsk(initTskBody);
    int idleTid = createTsk(idle);
    idleTsk = TCB[idleTid];
    tskStart(TCB[initTid]);
    startMultitask();
}
