#include "../../include/taskRR.h"

//构造循环队列的数据结构
void RR_init()
{
    RR_head = RR_tail = full_flag = 0;
    for (int i = 0; i < 20; i++)
        RR_data[i] = NULL;
}
void RR_push(myTCB *e)
{
    if (!full_flag)
    {
        RR_data[(RR_tail++) % 20] = e;
        if (RR_head == RR_tail)
            full_flag = 1;
    }
}
myTCB *RR_pop()
{
    if (!RR_empty())
    {
        myTCB *temp = RR_data[RR_head];
        RR_head = (RR_head + 1) % 20;
        full_flag = 0;
        return temp;
    }
    return NULL;
}
myTCB *RR_top()
{
    if (!RR_empty())
        return RR_data[RR_head];
    else
        return NULL;
}
int RR_empty()
{
    return (!full_flag && RR_head == RR_tail);
}