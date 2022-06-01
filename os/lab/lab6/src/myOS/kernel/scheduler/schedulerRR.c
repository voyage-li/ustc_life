#include "../../include/schedulerRR.h"
#include "../../include/myPrintk.h"
#include "../../include/tick.h"

myTCB *nextTskRR(void)
{
    return RR_top();
}

void enqueueTskRR(myTCB *tsk)
{
    RR_push(tsk);
}

myTCB *dequeueTskRR(void)
{
    return RR_pop();
}

void RR_hook()
{
    if (currentTsk == idleTsk)
        return;
    currentTsk->this_time++;
    if (currentTsk->this_time >= 2)
    {
        currentTsk->this_time = 0;
        enqueueTskRR(currentTsk);
        context_switch(&currentTsk->stack_top, BspContext); //直接调用上下文切换返回
    }
}

void schedulerInitRR(void)
{
    RR_init();
    append2HookList(RR_hook);
}

void scheduleRR()
{
    while (1)
    {
        myTCB *nextTsk;
        int idleTid;
        if (RR_empty())
        {
            if (!idleTsk)
                idleTid = createTsk(idleTskBody);

            nextTsk = idleTsk = TCB[idleTid];
        }
        else
            nextTsk = dequeueTskRR();
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
    }
}