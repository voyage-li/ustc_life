#ifndef __TASKSJF_H_
#define __TASKSJF_H_

#include "schedulerSJF.h"
#include "task.h"

int length_SJF;
myTCB *SJF_data[20];
void heap_init_SJF();
void swim_SJF(int k);             //上浮
void sink_SJF(int k);             //下沉
void SJF_push(myTCB *e);          //入堆
myTCB *SJF_pop();                 //出堆
myTCB *SJF_top();                 //返回堆顶元素
int SJF_empty();                  //判断是否为空
int SJF_size();                   //返回大小
void swap_heap_SJF(int a, int b); //交换元素
int bigger_SJF(myTCB *a, myTCB *b);
int smaller_SJF(myTCB *a, myTCB *b);

#endif