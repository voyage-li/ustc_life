#ifndef __TASKQUEUEFIFO_H__
#define __TASKQUEUEFIFO_H__

#include "../include/task.h"

typedef struct taskQueueNode
{
    myTCB *task;
    struct taskQueueNode *next;
} taskQueueNode;

typedef struct FIFO
{
    taskQueueNode *head;
    taskQueueNode *tail;
} FIFO;

FIFO taskfifo;

void fifo_init();
int fifo_empty();
myTCB *next_tsk();
void tskenqueue(myTCB *tsk);
void tskdequeue();
void FCFS();

#endif