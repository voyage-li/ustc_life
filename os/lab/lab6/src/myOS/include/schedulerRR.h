#ifndef __SCHEDULERRR_H__
#define __SCHEDULERRR_H__

#include "scheduler.h"
#include "task.h"
#include "taskRR.h"

myTCB *nextTskRR(void);
void enqueueTskRR(myTCB *tsk);
myTCB *dequeueTskRR(void);
void schedulerInitRR(void);
void scheduleRR(void);

#endif