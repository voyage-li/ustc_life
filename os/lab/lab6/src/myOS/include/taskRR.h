#ifndef __TASKRR_H_
#define __TASKRR_H_

#include "schedulerRR.h"
#include "task.h"

myTCB *RR_data[20];
int RR_head;
int RR_tail;
int full_flag;
void RR_init();
void RR_push(myTCB *e);
myTCB *RR_pop();
myTCB *RR_top();
int RR_empty();

#endif