#include "../../include/schedulerRR.h"
#include "../../include/myPrintk.h"

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

void schedulerInitRR(void)
{
    RR_init();
    append2HookList(RR_hook);
}

void RR_hook(void)
{
    if (currentTsk == idleTsk)
        return;
    if (get_tick_times() % 100 != 0)
        return;
    currentTsk->this_time++;
    // myPrintk(0x6, "current this run: %d\n", currentTsk->this_time);
    if (currentTsk->this_time >= 2)
    {
        currentTsk->this_time = 0;
        if (currentTsk->run_time < getTskPara(EXETIME, currentTsk->para))
            sch.enqueueTsk_func(currentTsk);
        context_switch(&currentTsk->stack_top, BspContext); //直接调用上下文切换返回
    }
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