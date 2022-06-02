#ifndef __SCHEDULERSJF_H__
#define __SCHEDULERSJF_H__

#include "scheduler.h"
#include "task.h"
#include "taskSJF.h"
#include "tick.h"

myTCB *nextTskSJF(void);
void enqueueTskSJF(myTCB *tsk);
myTCB *dequeueTskSJF(void);
void schedulerInitSJF(void);
void scheduleSJF(void);

#endif