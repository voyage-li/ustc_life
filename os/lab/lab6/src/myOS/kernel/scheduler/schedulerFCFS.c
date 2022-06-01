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
    // FCFS调度，空闲时执行idle，否则释放正在运行的，进入下一个
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
        if (currentTsk)
        {
            if (currentTsk == idleTsk)
                destroyTsk(currentTsk->tid);
            if (currentTsk == idleTsk)
                idleTsk = NULL;
        }

        nextTsk->status = RUNNING;
        currentTsk = nextTsk;
        context_switch(&BspContext, currentTsk->stack_top);
        // print_fcfs();
    }
}