#include "../../include/schedulerFCFS.h"
#include "../../include/myPrintk.h"

taskQueueFIFO *queueFCFS;

myTCB *nextTskFCFS(void)
{
    return taskQueueFIFONext(queueFCFS);
}

void enqueueTskFCFS(myTCB *tsk)
{
    taskQueueFIFOEnqueue(queueFCFS, tsk);
}

myTCB *dequeueTskFCFS(void)
{
    return taskQueueFIFODequeue(queueFCFS);
}

void schedulerInitFCFS(void)
{
    taskQueueFIFOInit(queueFCFS);
}

void print_fcfs()
{
    myPrintk(0x6, "%d\n", fifo_length);
}

void scheduleFCFS()
{
    while (1)
    {
        myTCB *nextTsk;
        int idleTid;
        if (taskQueueFIFOEmpty(queueFCFS))
        {
            if (!idleTsk)
                idleTid = createTsk(idleTskBody);

            nextTsk = idleTsk = TCB[idleTid];
        }
        else
            nextTsk = dequeueTskFCFS();
        if (nextTsk == idleTsk && currentTsk == idleTsk)
            continue;

        if (currentTsk && currentTsk == idleTsk)
        {
            destroyTsk(currentTsk->tid);
            idleTsk = NULL;
        }

        nextTsk->status = RUNNING;
        currentTsk = nextTsk;
        context_switch(&BspContext, currentTsk->stack_top);
        // print_fcfs();
    }
}