#include "../../include/taskSJF.h"

#include "../../include/taskPRIO.h"

void heap_init_SJF()
{
    length = 0;
    for (int i = 0; i < 20; i++)
        SJF_data[i] = NULL;
}

void swap_heap_SJF(int a, int b)
{
    myTCB *temp = SJF_data[a];
    SJF_data[a] = SJF_data[b];
    SJF_data[b] = temp;
}

int SJF_empty()
{
    return (length == 0);
}

int SJF_size()
{
    return length;
}

void SJF_push(myTCB *e)
{
    SJF_data[++length] = e;
    swim(length);
}

myTCB *SJF_pop()
{
    swap_heap(1, length--);
    sink(1);
    return SJF_data[length + 1];
}

myTCB *SJF_top()
{
    if (!SJF_empty())
        return SJF_data[1];
    return SJF_data[0];
}

int bigger_SJF(myTCB *a, myTCB *b)
{
    return getTskPara(EXETIME, a->para) < getTskPara(PRIORITY, b->para);
}
int smaller_SJF(myTCB *a, myTCB *b)
{
    return getTskPara(EXETIME, a->para) > getTskPara(PRIORITY, b->para);
}

void swim_SJF(int k) //上浮
{
    while (k > 1 && bigger_SJF(SJF_data[k], SJF_data[k / 2]))
    {
        swap_heap_SJF(k, k / 2);
        k /= 2;
    }
}

void sink_SJF(int k) //下沉
{
    while (k * 2 <= length)
    {
        int j = 2 * k;
        if (j < length && smaller_SJF(SJF_data[j], SJF_data[j + 1])) //找到左右子树中更大的
            j++;
        if (bigger_SJF(SJF_data[k], SJF_data[j]))
            break;
        swap_heap_SJF(k, j);
        k = j;
    }
}