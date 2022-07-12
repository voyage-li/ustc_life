#ifndef __SCHEDULERPRIO_H__
#define __SCHEDULERPRIO_H__

#include "scheduler.h"
#include "task.h"
#include "taskPRIO.h"

myTCB *nextTskPRIO(void);
void enqueueTskPRIO(myTCB *tsk);
myTCB *dequeueTskPRIO(void);
void schedulerInitPRIO(void);
void schedulePRIO(void);

#endif