#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "task.h"

#define FCFS 0
#define PRIO 1
#define RR 2
#define SJF 3

typedef struct scheduler
{
    unsigned int type;

    myTCB *(*nextTsk_func)(void);
    void (*enqueueTsk_func)(myTCB *tsk);
    myTCB *(*dequeueTsk_func)(void);
    void (*schedulerInit_func)(void);
    void (*schedule)(void);
    void (*tick_hook)(void);
} scheduler;

scheduler sch;

void init_sch(void);
void schedule(void);

#endif