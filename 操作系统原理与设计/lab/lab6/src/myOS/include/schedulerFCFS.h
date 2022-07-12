#ifndef __SCHEDULERFCFS_H__
#define __SCHEDULERFCFS_H__

#include "scheduler.h"
#include "task.h"
#include "taskQueueFIFO.h"

myTCB *nextTskFCFS(void);
void enqueueTskFCFS(myTCB *tsk);
myTCB *dequeueTskFCFS(void);
void schedulerInitFCFS(void);
void scheduleFCFS(void);

#endif