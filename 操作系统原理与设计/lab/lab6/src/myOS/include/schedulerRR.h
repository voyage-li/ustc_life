#ifndef __SCHEDULERRR_H__
#define __SCHEDULERRR_H__

#include "scheduler.h"
#include "task.h"
#include "taskRR.h"
#include "tick.h"

myTCB *nextTskRR(void);
void enqueueTskRR(myTCB *tsk);
myTCB *dequeueTskRR(void);
void schedulerInitRR(void);
void scheduleRR(void);
void RR_hook(void);

#endif