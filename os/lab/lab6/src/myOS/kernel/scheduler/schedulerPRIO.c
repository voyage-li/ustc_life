#include "../../include/schedulerPRIO.h"
#include "../../include/myPrintk.h"

myTCB *nextTskPRIO(void)
{
    return prio_top();
}

void enqueueTskPRIO(myTCB *tsk)
{
    prio_push(tsk);
}

myTCB *dequeueTskPRIO(void)
{
    return prio_pop();
}

void schedulerInitPRIO(void)
{
    heap_init();
}

void print_sche()
{
    for (int i = 1; i <= length; i++)
        myPrintk(0x6, "prio_dataid: %d tid:%d pri: %d arr: %d\n", i, prio_data[i]->tid, prio_data[i]->para->priority, prio_data[i]->para->arrTime);
}

void schedulePRIO()
{
    while (1)
    {
        myTCB *nextTsk;
        int idleTid;
        if (prio_empty())
        {
            if (!idleTsk)
                idleTid = createTsk(idleTskBody);

            nextTsk = idleTsk = TCB[idleTid];
        }
        else
            nextTsk = dequeueTskPRIO();
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
        // print_sche();
    }
}