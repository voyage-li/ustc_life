#include "../../include/taskarrv.h"
#include "../../include/myPrintk.h"
#include "../../include/tick.h"

void arr_hook(void)
{
    if (arrv_empty())
        return;

    myTCB *nextTask = arrv_top();
    // if (get_tick_times() % 100 == 0)
    //     myPrintk(0x6, "nextsk_arrive: %d\n", getTskPara(ARRTIME, nextTask->para));
    if (get_tick_times() / 100 >= getTskPara(ARRTIME, nextTask->para))
    {
        tskStart(TCB[nextTask->tid]);
        arrv_pop();
    }
}

void heap_init_arrv()
{
    length_arrv = 0;
    for (int i = 0; i < 20; i++)
        arr_data[i] = NULL;
    append2HookList(arr_hook);
}

void swap_heap_arrv(int a, int b)
{
    myTCB *temp = arr_data[a];
    arr_data[a] = arr_data[b];
    arr_data[b] = temp;
}

int arrv_empty()
{
    return (length_arrv == 0);
}

int arrv_size()
{
    return length_arrv;
}

void arrv_push(myTCB *e)
{
    arr_data[++length_arrv] = e;
    swim_arrv(length_arrv);
}

myTCB *arrv_pop()
{
    swap_heap_arrv(1, length_arrv--);
    sink_arrv(1);
    return arr_data[length_arrv + 1];
}

myTCB *arrv_top()
{
    if (!arrv_empty())
        return arr_data[1];
    return arr_data[0];
}

int bigger_arrv(myTCB *a, myTCB *b)
{
    return getTskPara(ARRTIME, a->para) < getTskPara(ARRTIME, b->para);
}
int smaller_arrv(myTCB *a, myTCB *b)
{
    return getTskPara(ARRTIME, a->para) > getTskPara(ARRTIME, b->para);
}

void swim_arrv(int k) //上浮
{
    while (k > 1 && bigger_arrv(arr_data[k], arr_data[k / 2]))
    {
        swap_heap_arrv(k, k / 2);
        k /= 2;
    }
}

void sink_arrv(int k) //下沉
{
    while (k * 2 <= length_arrv)
    {
        int j = 2 * k;
        if (j < length_arrv && smaller_arrv(arr_data[j], arr_data[j + 1])) //找到左右子树中更大的
            j++;
        if (bigger_arrv(arr_data[k], arr_data[j]))
            break;
        swap_heap_arrv(k, j);
        k = j;
    }
}

void add_task(int tid)
{
    // myPrintk(0x6, "addtask: %d\n", tid);
    if (TCB[tid]->para->arrTime == 0)
        tskStart(TCB[tid]);
    else
        arrv_push(TCB[tid]);
}