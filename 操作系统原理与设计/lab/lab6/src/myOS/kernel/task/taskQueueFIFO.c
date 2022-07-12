#include "../../include/taskQueueFIFO.h"
#include "../../include/kmalloc.h"

void taskQueueFIFOInit(taskQueueFIFO *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    fifo_length = 0;
}
int taskQueueFIFOEmpty(taskQueueFIFO *queue)
{
    return (queue->head == NULL && queue->tail == NULL);
}

myTCB *taskQueueFIFONext(taskQueueFIFO *queue)
{
    if (taskQueueFIFOEmpty(queue))
        return NULL;
    else
        return queue->head->TCB;
}
void taskQueueFIFOEnqueue(taskQueueFIFO *queue, myTCB *tsk)
{
    queueNodeFIFO *newNode = (queueNodeFIFO *)kmalloc(sizeof(queueNodeFIFO));
    if (!newNode)
        return;

    newNode->TCB = tsk;
    newNode->next = NULL;

    if (taskQueueFIFOEmpty(queue))
        queue->head = queue->tail = newNode;
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    fifo_length++;
}

myTCB *taskQueueFIFODequeue(taskQueueFIFO *queue)
{
    if (taskQueueFIFOEmpty(queue))
        return NULL;

    queueNodeFIFO *node = queue->head;
    myTCB *task = node->TCB;

    if (queue->head == queue->tail)
        queue->head = queue->tail = NULL;
    else
        queue->head = node->next;

    kfree((unsigned long)node);

    fifo_length--;

    return task;
}