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

#define PRIORITY 1
#define EXETIME 2
#define ARRTIME 3

extern int shell_start_flag;

typedef struct tskPara
{
    unsigned int priority;
    unsigned int arrTime;
    unsigned int exeTime;
} tskPara;

typedef struct myTCB
{
    int tid;
    int status;
    unsigned long run_time;
    unsigned long this_time;
    unsigned long *stack_top;
    unsigned long *stack_max;
    tskPara *para;
    void (*function)(void);
    struct myTCB *next;
} myTCB;

myTCB *firstFree;
myTCB *TCB[TCBSIZE];
myTCB *currentTsk;
myTCB *idleTsk;

void TaskManagerInit(void);

int createTsk(void (*tskBody)(void));
void destroyTsk(int tskIndex);
void tskStart(myTCB *tsk);
void tskEnd();

void CTX_SW(void);
void idleTskBody(void);

unsigned long *BspContextBase;
unsigned long *BspContext;
unsigned long **prevTSK_StackPtrAddr;
unsigned long *nextTSK_StackPtr;
void context_switch(unsigned long **prevTskStkAddr, unsigned long *nextTskStk);

void initTskPara(tskPara **buffer);
void setTskPara(unsigned int option, unsigned int value, tskPara *buffer);
unsigned int getTskPara(unsigned int option, tskPara *para);

void task_execute(unsigned int wait_time);

#endif
