#include "../include/taskQueueFIFO.h"
#include "../include/kmalloc.h"
#include "../include/myPrintk.h"

void fifo_init()
{
    taskfifo.head = NULL;
    taskfifo.tail = NULL;
}
int fifo_empty()
{
    return (taskfifo.head == NULL) && (taskfifo.tail == NULL);
}
myTCB *next_tsk()
{
    if (fifo_empty())
        return idleTsk;
    else
        return taskfifo.head->task;
}
void tskenqueue(myTCB *tsk)
{
    //将 tsk 进入队列
    taskQueueNode *node = (taskQueueNode *)kmalloc(sizeof(taskQueueNode));
    if (!node)
        return;
    node->task = tsk;
    node->next = NULL;
    if (fifo_empty())
    {
        taskfifo.head = node;
        taskfifo.tail = node;
    }
    else
    {
        taskfifo.tail->next = node;
        taskfifo.tail = node;
    }
}

void tskdequeue()
{
    if (fifo_empty())
        return;
    taskQueueNode *node = taskfifo.head;
    if (taskfifo.head == taskfifo.tail)
    {
        taskfifo.head = NULL;
        taskfifo.tail = NULL;
    }
    else
        taskfifo.head = node->next;
    kfree((unsigned long)node);
}

void FCFS()
{
    // FCFS调度，空闲时执行idle，否则释放正在运行的，进入下一个
    // myPrintk(0x6, "begin to FCFS\n");
    while (1)
    {
        myTCB *nextsk = next_tsk();
        if (nextsk == idleTsk && currentTsk == idleTsk)
            return;
        if (currentTsk)
            destoryTsk(currentTsk->tid);

        // myPrintk(0x6, "do a task\n");
        nextsk->status = RUNNING;
        currentTsk = nextsk;
        context_switch(&BspContext, currentTsk->stack_top);
    }
}