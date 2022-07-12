#include "../../include/taskPRIO.h"

void heap_init()
{
    length = 0;
    for (int i = 0; i < 20; i++)
        prio_data[i] = NULL;
}

void swap_heap(int a, int b)
{
    myTCB *temp = prio_data[a];
    prio_data[a] = prio_data[b];
    prio_data[b] = temp;
}

int prio_empty()
{
    return (length == 0);
}

int prio_size()
{
    return length;
}

void prio_push(myTCB *e)
{
    prio_data[++length] = e;
    swim(length);
}

myTCB *prio_pop()
{
    swap_heap(1, length--);
    sink(1);
    return prio_data[length + 1];
}

myTCB *prio_top()
{
    if (!prio_empty())
        return prio_data[1];
    return prio_data[0];
}

int bigger(myTCB *a, myTCB *b)
{
    return getTskPara(PRIORITY, a->para) > getTskPara(PRIORITY, b->para);
}
int smaller(myTCB *a, myTCB *b)
{
    return getTskPara(PRIORITY, a->para) < getTskPara(PRIORITY, b->para);
}

void swim(int k) //上浮
{
    while (k > 1 && bigger(prio_data[k], prio_data[k / 2]))
    {
        swap_heap(k, k / 2);
        k /= 2;
    }
}

void sink(int k) //下沉
{
    while (k * 2 <= length)
    {
        int j = 2 * k;
        if (j < length && smaller(prio_data[j], prio_data[j + 1])) //找到左右子树中更大的
            j++;
        if (bigger(prio_data[k], prio_data[j]))
            break;
        swap_heap(k, j);
        k = j;
    }
}