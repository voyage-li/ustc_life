#ifndef __TASKARRV_H_
#define __TASKARRV_H_

#include "task.h"

void add_task(int tid);

int length_arrv;
myTCB *arr_data[20];
void heap_init_arrv();
void swim_arrv(int k);             //上浮
void sink_arrv(int k);             //下沉
void arrv_push(myTCB *e);          //入堆
myTCB *arrv_pop();                 //出堆
myTCB *arrv_top();                 //返回堆顶元素
int arrv_empty();                  //判断是否为空
int arrv_size();                   //返回大小
void swap_heap_arrv(int a, int b); //交换元素
int bigger_arrv(myTCB *a, myTCB *b);
int smaller_arrv(myTCB *a, myTCB *b);

#endif