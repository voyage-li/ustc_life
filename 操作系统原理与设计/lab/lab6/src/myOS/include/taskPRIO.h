#ifndef __TASKPRIO_H_
#define __TASKPRIO_H_

#include "schedulerPRIO.h"
#include "task.h"

int length;
myTCB *prio_data[20];
void heap_init();
void swim(int k);             //上浮
void sink(int k);             //下沉
void prio_push(myTCB *e);     //入堆
myTCB *prio_pop();            //出堆
myTCB *prio_top();            //返回堆顶元素
int prio_empty();             //判断是否为空
int prio_size();              //返回大小
void swap_heap(int a, int b); //交换元素
int bigger(myTCB *a, myTCB *b);
int smaller(myTCB *a, myTCB *b);

#endif