#ifndef __TASK_H__
#define __TASK_H__

extern void myMain(void);

#define STACK_SIZE 0x1000
#define TCBSIZE 10
#define NULL (void *)0
#define initTskBody myMain

#define BLANK 0
#define WAITING 1
#define RUNNING 2

typedef struct myTCB
{
    int tid;
    int status;
    unsigned long *stack_top;
    unsigned long *stack_max;
    void (*function)(void);
    struct myTCB *next;
} myTCB;

myTCB *firstFree;
myTCB *TCB[TCBSIZE];
myTCB *currentTsk;
myTCB *idleTsk;

void TaskManagerInit(void);

int createTsk(void (*tskBody)(void));
void destoryTsk(int tskIndex);
void tskStart(myTCB *tsk);
void tskEnd();

void CTX_SW(void);

unsigned long *BspContextBase;
unsigned long *BspContext;
unsigned long **prevTSK_StackPtrAddr;
unsigned long *nextTSK_StackPtr;
void context_switch(unsigned long **prevTskStkAddr, unsigned long *nextTskStk);

#endif
